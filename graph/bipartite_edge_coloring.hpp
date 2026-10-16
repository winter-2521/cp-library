#pragma once
#include "../template.hpp"
#include "bipartite_matching.hpp"

// https://github.com/winter-2521/cp-library

// 二部グラフの辺彩色 (最大次数 Δ 色で，同じ頂点に接する辺の色が全て異なるように塗る．Kőnig の定理より Δ 色で足りる)
// 1. 頂点をまとめて (次数の和が Δ 以下になるように) 両側 k 頂点ずつにし，ダミー辺を足して Δ-正則な二部多重グラフにする
// 2. Δ が奇数なら完全マッチング (正則二部グラフには必ずある) を 1 色で塗って取り除く
//    Δ が偶数ならオイラー閉路に沿って辺を交互に 2 つに分け (各頂点で半分ずつになる)，それぞれを再帰的に塗る
// O(m √n log Δ)
// 返り値: {色数 Δ, 各辺の色 (0 .. Δ-1)}
inline pair<int, vector<int>> bipartite_edge_coloring(int L, int R, const vector<pair<int, int>> &edges) {
    int m = edges.size();
    if (m == 0) return {0, {}};
    vector<int> degl(L, 0), degr(R, 0);
    for (auto [a, b] : edges) degl[a]++, degr[b]++;
    int D = std::max(*max_element(degl.begin(), degl.end()), *max_element(degr.begin(), degr.end()));
    // 1. 頂点をまとめる (順に詰める)
    auto pack = [&](const vector<int> &deg, vector<int> &grp) {
        int k = 0, cur = 0;
        grp.assign(deg.size(), 0);
        for (size_t v = 0; v < deg.size(); v++) {
            if (cur + deg[v] > D) k++, cur = 0;
            grp[v] = k, cur += deg[v];
        }
        return k + 1;
    };
    vector<int> gl, gr;
    int kl = pack(degl, gl), kr = pack(degr, gr), k = std::max(kl, kr);
    vector<int> el(k, 0), er(k, 0);  // まとめた頂点の次数
    vector<pair<int, int>> E;        // まとめたグラフの辺 (左 0..k-1，右 0..k-1)
    E.reserve((size_t)k * D);
    for (auto [a, b] : edges) E.push_back({gl[a], gr[b]}), el[gl[a]]++, er[gr[b]]++;
    // ダミー辺で Δ-正則にする (不足している左と右を順に結ぶ)
    for (int x = 0, y = 0; x < k; x++) {
        while (el[x] < D) {
            while (er[y] == D) y++;
            int f = std::min(D - el[x], D - er[y]);
            for (int t = 0; t < f; t++) E.push_back({x, y});
            el[x] += f, er[y] += f;
        }
    }
    int M = E.size();
    vector<int> color(M, -1);
    // 2. 再帰 (明示的なスタックで): (辺の集合, 次数, 使う色の先頭)
    struct Task {
        vector<int> es;
        int deg, base;
    };
    vector<Task> stk;
    {
        vector<int> all(M);
        iota(all.begin(), all.end(), 0);
        stk.push_back({all, D, 0});
    }
    vector<int> head(2 * k), nxt, used_mark;
    while (!stk.empty()) {
        Task t = std::move(stk.back());
        stk.pop_back();
        if (t.deg == 0) continue;
        if (t.deg == 1) {
            for (int e : t.es) color[e] = t.base;
            continue;
        }
        if (t.deg & 1) {
            // 完全マッチングを 1 色で塗る
            BipartiteMatching bm(k, k);
            bm.reserve(t.es.size());
            for (int e : t.es) bm.add_edge(E[e].first, E[e].second);
            int got = bm.solve();
            assert(got == k);
            // マッチした組 (左, 右) ごとに辺を 1 本選ぶ
            vector<char> taken(k, 0);
            vector<int> rest;
            rest.reserve(t.es.size() - k);
            for (int e : t.es) {
                int a = E[e].first;
                if (!taken[a] && bm.match_l[a] == E[e].second) taken[a] = 1, color[e] = t.base + t.deg - 1;
                else rest.push_back(e);
            }
            stk.push_back({std::move(rest), t.deg - 1, t.base});
            continue;
        }
        // オイラー分割: 頂点 (左 x → x，右 y → k + y) ごとに辺のリスト
        int sz = t.es.size();
        fill(head.begin(), head.end(), -1);
        nxt.assign(2 * sz, -1);
        used_mark.assign(sz, 0);
        // 半辺 2i は左から，2i+1 は右から
        for (int i = 0; i < sz; i++) {
            auto [a, b] = E[t.es[i]];
            nxt[2 * i] = head[a], head[a] = 2 * i;
            nxt[2 * i + 1] = head[k + b], head[k + b] = 2 * i + 1;
        }
        vector<int> A, B;
        A.reserve(sz / 2), B.reserve(sz / 2);
        // 各連結成分でオイラー閉路を作り，閉路の順に交互に分ける (Hierholzer，非再帰)
        vector<pair<int, int>> st;  // (頂点, 来た辺)
        vector<int> circuit;
        for (int s = 0; s < 2 * k; s++) {
            if (head[s] < 0) continue;
            circuit.clear();
            st.clear(), st.push_back({s, -1});
            while (!st.empty()) {
                int v = st.back().first;
                while (head[v] >= 0 && used_mark[head[v] >> 1]) head[v] = nxt[head[v]];
                if (head[v] < 0) {
                    if (st.back().second >= 0) circuit.push_back(st.back().second);
                    st.pop_back();
                    continue;
                }
                int h = head[v], i = h >> 1;
                used_mark[i] = 1;
                head[v] = nxt[h];
                auto [a, b] = E[t.es[i]];
                int to = (h & 1) ? a : k + b;
                st.push_back({to, i});
            }
            for (size_t j = 0; j < circuit.size(); j++) (j & 1 ? B : A).push_back(t.es[circuit[j]]);
        }
        stk.push_back({std::move(A), t.deg / 2, t.base});
        stk.push_back({std::move(B), t.deg / 2, t.base + t.deg / 2});
    }
    vector<int> res(color.begin(), color.begin() + m);
    return {D, res};
}
