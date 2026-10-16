#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// クリークの列挙．単純無向グラフの全ての (空でない) クリーク C について f(C) を呼ぶ (C は頂点の列)．O(2^√(2m) n) 程度
// 辺を (次数, 番号) の小さい方から大きい方へ向けると，各頂点から出る辺は √(2m) 本以下になる．
// クリークの (向きでの) 最小の頂点 v を決めると，残りは v から出る先 (高々 √(2m) 個) の中のクリークなので，
// その中だけの隣接を bit で持って全部たどる (各クリークはちょうど 1 回)
template <class F>
void enumerate_cliques(int n, const vector<pair<int, int>> &edges, F f) {
    vector<int> deg(n, 0);
    for (auto [a, b] : edges) deg[a]++, deg[b]++;
    auto less = [&](int a, int b) { return deg[a] != deg[b] ? deg[a] < deg[b] : a < b; };
    vector<vector<int>> out(n);
    for (auto [a, b] : edges) {
        if (!less(a, b)) swap(a, b);
        out[a].push_back(b);
    }
    vector<int> idx(n, -1), cur;
    for (int v = 0; v < n; v++) {
        const auto &nb = out[v];
        int k = nb.size();
        assert(k <= 63);
        for (int i = 0; i < k; i++) idx[nb[i]] = i;
        vector<unsigned long long> adj(k, 0);
        for (int i = 0; i < k; i++)
            for (int w : out[nb[i]])
                if (idx[w] >= 0) adj[i] |= 1ULL << idx[w], adj[idx[w]] |= 1ULL << i;
        cur.assign(1, v);
        f(cur);
        // cand: まだ足せる頂点 (番号が今の最後より大きいものだけ)
        auto rec = [&](auto self, unsigned long long cand) -> void {
            while (cand) {
                int i = __builtin_ctzll(cand);
                cand &= cand - 1;
                cur.push_back(nb[i]);
                f(cur);
                self(self, cand & adj[i]);
                cur.pop_back();
            }
        };
        rec(rec, k == 64 ? ~0ULL : (1ULL << k) - 1);
        for (int i = 0; i < k; i++) idx[nb[i]] = -1;
    }
}
