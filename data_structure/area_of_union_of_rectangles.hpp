#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 長方形の和集合の面積 (Area of Union of Rectangles)
// x の小さい順に走査し，y 方向をセグメント木で管理する．各ノードは
//   cnt: このノードの区間「全体」をちょうど覆っている長方形の数 (子には伝えない)
//   cov: このノードの区間のうち，このノード以下の cnt で覆われている長さ
// を持ち，cov = (cnt > 0 ? 区間の長さ : 子の cov の和)．遅延伝播が要らないので速い．O(n log n)
// 長方形 i は [l[i], r[i]] × [d[i], u[i]] (面積は閉区間でも半開区間でも同じ)
template <class T>
T area_of_union_of_rectangles(const vector<T> &l, const vector<T> &d, const vector<T> &r, const vector<T> &u) {
    int n = l.size();
    // y 座標を (値, 2i または 2i+1) でソートして番号を振る (二分探索しない)
    vector<pair<T, int>> yv(2 * n);
    for (int i = 0; i < n; i++) yv[2 * i] = {d[i], 2 * i}, yv[2 * i + 1] = {u[i], 2 * i + 1};
    sort(yv.begin(), yv.end());
    vector<T> ys;
    ys.reserve(2 * n);
    vector<int> yi(2 * n);  // yi[2i] = d[i] の番号，yi[2i+1] = u[i] の番号
    for (auto &[y, id] : yv) {
        if (ys.empty() || ys.back() != y) ys.push_back(y);
        yi[id] = ys.size() - 1;
    }
    int m = (int)ys.size() - 1;
    if (m <= 0) return T(0);
    int sz = 1;
    while (sz < m) sz <<= 1;
    struct Node {
        T cov, len;
        int cnt;
    };
    vector<Node> t(2 * sz, Node{T(0), T(0), 0});
    for (int i = 0; i < m; i++) t[sz + i].len = ys[i + 1] - ys[i];
    for (int k = sz - 1; k >= 1; k--) t[k].len = t[2 * k].len + t[2 * k + 1].len;
    auto fix = [&](int k) { t[k].cov = t[k].cnt ? t[k].len : (k < sz ? t[2 * k].cov + t[2 * k + 1].cov : T(0)); };
    auto update = [&](int a, int b, int c) {  // y の区間 [a, b) の被覆回数に c を足す
        int a0 = a + sz, b0 = b + sz;
        for (int x = a0, y = b0; x < y; x >>= 1, y >>= 1) {
            if (x & 1) t[x].cnt += c, fix(x), x++;
            if (y & 1) --y, t[y].cnt += c, fix(y);
        }
        for (int k = a0 >> 1; k; k >>= 1) fix(k);
        for (int k = (b0 - 1) >> 1; k; k >>= 1) fix(k);
    };
    // イベント: 長方形 i の左端で +1 (番号 i)，右端で -1 (番号 ~i)
    vector<pair<T, int>> ev;
    ev.reserve(2 * n);
    for (int i = 0; i < n; i++) ev.emplace_back(l[i], i), ev.emplace_back(r[i], ~i);
    sort(ev.begin(), ev.end());
    T res(0);
    for (int k = 0; k < (int)ev.size(); k++) {
        if (k > 0) res += t[1].cov * (ev[k].first - ev[k - 1].first);
        int i = ev[k].second;
        if (i >= 0) update(yi[2 * i], yi[2 * i + 1], 1);
        else update(yi[2 * ~i], yi[2 * ~i + 1], -1);
    }
    return res;
}
