#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 区間並列 Union-Find
// 「i = 0, ..., k-1 について a+i と b+i を併合する」を高速に処理する
// 全体で O((n log n + q) α(n))
//
// 段 j の Union-Find は「長さ 2^j の区間 [i, i + 2^j)」を要素 i として持ち，
// 段 j で区間 [a, a+2^j) と [b, b+2^j) を併合したら，段 j-1 で前半同士・後半同士を併合する．
// 各段で実際に併合が起きるのは高々 n-1 回なので，下の段に伝わる回数も抑えられる
struct RangeParallelUnionFind {
    int n, lg;
    // par[j][i]: 段 j の Union-Find (根なら -(サイズ))
    vector<vector<int>> par;

    RangeParallelUnionFind(int n = 0) : n(n) {
        lg = 1;
        while ((1 << lg) <= n) lg++;
        par.resize(lg);
        for (int j = 0; j < lg; j++) par[j].assign(std::max(0, n - (1 << j) + 1), -1);
    }

    static int find(vector<int> &p, int x) {
        int r = x;
        while (p[r] >= 0) r = p[r];
        // 経路圧縮
        while (p[x] >= 0 && p[x] != r) {
            int nx = p[x];
            p[x] = r;
            x = nx;
        }
        return r;
    }

    // 併合して (残った根, 吸収された根) を返す．既に同じなら {-1, -1}
    static pair<int, int> unite(vector<int> &p, int x, int y) {
        x = find(p, x), y = find(p, y);
        if (x == y) return {-1, -1};
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return {x, y};
    }

    int leader(int x) { return find(par[0], x); }
    bool same(int x, int y) { return leader(x) == leader(y); }
    int size(int x) { return -par[0][leader(x)]; }

    // i = 0, ..., k-1 について a+i と b+i を併合する
    // 段 0 で実際に併合が起きるたびに f(残った根, 吸収された根) を呼ぶ
    template <class F>
    void merge(int a, int b, int k, F f) {
        if (k <= 0 || a == b) return;
        int j = 31 - __builtin_clz(k);
        // 長さ 2^j の区間 2 つで [a, a+k) を覆う
        stk.clear();
        stk.push_back({j, a, b});
        stk.push_back({j, a + k - (1 << j), b + k - (1 << j)});
        while (!stk.empty()) {
            auto [lv, x, y] = stk.back();
            stk.pop_back();
            auto [r, c] = unite(par[lv], x, y);
            if (r < 0) continue;
            if (lv == 0) {
                f(r, c);
            } else {
                int h = 1 << (lv - 1);
                stk.push_back({lv - 1, x, y});
                stk.push_back({lv - 1, x + h, y + h});
            }
        }
    }

    void merge(int a, int b, int k) {
        merge(a, b, k, [](int, int) {});
    }

    // クエリを先読みできるときの高速版 (オブジェクトは作らずに使う)
    // qs[t] = {a, b, k} を t = 0, 1, ... の順に処理したとき，段 0 で実際に併合が起きるたびに
    // f(t, 残った根, 吸収された根) を t の昇順に呼ぶ．計算量は merge と同じ
    //
    // 段を上から 1 つずつ処理し，各段の併合は時刻順に行う．段 j で成功した併合を段 j-1 に時刻つきで渡す．
    // 同時に触る Union-Find が 1 段分だけになるので，オンライン版よりキャッシュに乗りやすい
    template <class F>
    static void merge_offline(int n, const vector<array<int, 3>> &qs, F f) {
        int q = qs.size();
        int lg = 1;
        while ((1 << lg) <= n) lg++;
        // 段ごとに，その段に直接入るクエリ (長さ 2^j の区間 2 つで覆う) を時刻順に並べる
        vector<int> start(lg + 1, 0);
        for (auto &[a, b, k] : qs) if (k > 0 && a != b) start[31 - __builtin_clz(k)]++;
        for (int j = 0; j < lg; j++) start[j + 1] += start[j];
        vector<int> direct(start[lg]);
        for (int t = q - 1; t >= 0; t--) {
            auto &[a, b, k] = qs[t];
            if (k > 0 && a != b) direct[--start[31 - __builtin_clz(k)]] = t;
        }
        struct Item {
            int t, x, y;
        };
        vector<Item> cur, nxt;
        vector<int> p(n);
        for (int j = lg - 1; j >= 0; j--) {
            int m = n - (1 << j) + 1;
            fill(p.begin(), p.begin() + m, -1);
            nxt.clear();
            int h = j > 0 ? 1 << (j - 1) : 0;
            auto process = [&](int t, int x, int y) {
                auto [r, c] = unite(p, x, y);
                if (r < 0) return;
                if (j == 0) {
                    f(t, r, c);
                } else {
                    nxt.push_back({t, x, y});
                    nxt.push_back({t, x + h, y + h});
                }
            };
            // 直接のクエリと上の段から来たものを時刻順にマージしながら処理する
            size_t ci = 0;
            for (int di = start[j]; di < start[j + 1]; di++) {
                int t = direct[di];
                for (; ci < cur.size() && cur[ci].t < t; ci++) process(cur[ci].t, cur[ci].x, cur[ci].y);
                auto &[a, b, k] = qs[t];
                int w = 1 << j;
                process(t, a, b);
                process(t, a + k - w, b + k - w);
            }
            for (; ci < cur.size(); ci++) process(cur[ci].t, cur[ci].x, cur[ci].y);
            swap(cur, nxt);
        }
    }

  private:
    vector<tuple<int, int, int>> stk;
};
