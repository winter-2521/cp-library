#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 最小直径全域木．グラフの「絶対 1-中心」(辺の途中も含めて，最も遠い頂点までの距離が最小になる点) を求め，
// そこからの最短路木を作ると直径が最小になる (直径 = 中心の離心率 × 2)
// 1. 全点対最短距離 d を Dijkstra で求める
// 2. 各辺 (u, v, w) の上の点 (u から x) の離心率は max_k min(d[u][k] + x, d[v][k] + w - x)．
//    頂点を d[u][k] の降順に並べ，「先頭側は v 経由，残りは u 経由」の境目ごとに最適な x を求める (Kariv-Hakimi)
// 3. 中心から最短路木を作る (辺の途中の中心は，u と v に重み x, w - x でつながる仮の頂点とする)
// 重みは 2 倍して扱い，中心が辺の中点のような半端な位置でも整数で計算する
// O(n m log n) (n 回の Dijkstra と，頂点ごとのソート n 回 + 辺ごとの O(n) の走査)
// 返り値: {直径, 使う辺の番号の列 (n-1 本)}．グラフは連結であること
template <class T>
pair<T, vector<int>> minimum_diameter_spanning_tree(int n, const vector<tuple<int, int, T>> &edges) {
    int m = edges.size();
    vector<int> start(n + 1, 0);
    vector<pair<int, int>> adj(2 * m);  // (行き先, 辺番号)
    vector<T> adjw(2 * m);
    for (auto &[a, b, c] : edges) start[a + 1]++, start[b + 1]++;
    for (int i = 0; i < n; i++) start[i + 1] += start[i];
    {
        vector<int> pos(start.begin(), start.end() - 1);
        for (int i = 0; i < m; i++) {
            auto &[a, b, c] = edges[i];
            adjw[pos[a]] = c, adj[pos[a]++] = {b, i};
            adjw[pos[b]] = c, adj[pos[b]++] = {a, i};
        }
    }
    const T INF = numeric_limits<T>::max() / 4;
    // ds: 源点ごとの距離 (重みは元のまま)．srcs: (頂点, 初期距離)
    vector<pair<T, int>> pq;  // push_heap / pop_heap で使う (確保し直さない)
    pq.reserve(2 * m + 2);
    auto dijkstra = [&](const vector<pair<int, T>> &srcs, vector<T> &dist, vector<int> *pe) {
        dist.assign(n, INF);
        if (pe) pe->assign(n, -1);
        pq.clear();
        auto push = [&](T d0, int v) {
            pq.push_back({d0, v});
            push_heap(pq.begin(), pq.end(), greater<>());
        };
        for (auto [v, d0] : srcs)
            if (d0 < dist[v]) dist[v] = d0, push(d0, v);
        while (!pq.empty()) {
            pop_heap(pq.begin(), pq.end(), greater<>());
            auto [d, v] = pq.back();
            pq.pop_back();
            if (d != dist[v]) continue;
            for (int i = start[v]; i < start[v + 1]; i++) {
                int to = adj[i].first;
                T nd = d + (pe ? adjw[i] * 2 : adjw[i]);
                if (nd < dist[to]) {
                    dist[to] = nd, push(nd, to);
                    if (pe) (*pe)[to] = adj[i].second;
                }
            }
        }
    };
    vector<vector<T>> d(n);
    for (int v = 0; v < n; v++) dijkstra({{v, T(0)}}, d[v], nullptr);
    // ord[u]: d[u][k] の降順の頂点の列
    vector<vector<int>> ord(n, vector<int>(n));
    {
        // (距離, 頂点) を 1 つの整数に詰めてソートする (間接参照の比較より速い)
        int lg = 1;
        while ((1 << lg) < n) lg++;
        vector<unsigned long long> key(n);
        for (int u = 0; u < n; u++) {
            for (int k = 0; k < n; k++) key[k] = (unsigned long long)d[u][k] << lg | k;
            sort(key.begin(), key.end(), greater<>());
            for (int k = 0; k < n; k++) ord[u][k] = key[k] & ((1ULL << lg) - 1);
        }
    }
    // best: 直径 (= 離心率の 2 倍)．中心は「辺 be の u 側から x2/2 の点」(be < 0 なら頂点 bv)
    T best = INF, bx2 = 0;
    int be = -1, bv = -1;
    for (int v = 0; v < n; v++) {
        T e = d[v][ord[v][0]] * 2;
        if (e < best) best = e, bv = v;
    }
    for (int i = 0; i < m; i++) {
        auto &[u, v, w] = edges[i];
        if (u == v) continue;
        const auto &du = d[u], &dv = d[v];
        const auto &o = ord[u];
        int p = o[0];  // 先頭側 (v 経由) の中で d[v] が最大の頂点
        for (int j = 1; j < n; j++) {
            int k = o[j];
            if (dv[k] <= dv[p]) continue;
            // 先頭側 (d[u] が大きい方) を v 経由，k 以降を u 経由: 2 * 離心率 = du[k] + dv[p] + w
            T cand = du[k] + dv[p] + w, x2 = dv[p] + w - du[k];  // x2 = 2x
            if (0 <= x2 && x2 <= 2 * w && cand < best) best = cand, be = i, bx2 = x2;
            p = k;
        }
    }
    // 中心からの最短路木 (重み 2 倍)
    vector<T> dist;
    vector<int> pe;
    if (be < 0) {
        dijkstra({{bv, T(0)}}, dist, &pe);
    } else {
        auto &[u, v, w] = edges[be];
        dijkstra({{u, bx2}, {v, 2 * w - bx2}}, dist, &pe);
    }
    vector<int> used;
    used.reserve(n - 1);
    for (int v = 0; v < n; v++)
        if (pe[v] >= 0) used.push_back(pe[v]);
    // 仮の頂点に直接つながる頂点が 2 つ (u と v) なら，辺 be で結ぶ
    if (be >= 0 && (int)used.size() == n - 2) used.push_back(be);
    return {best, used};
}
