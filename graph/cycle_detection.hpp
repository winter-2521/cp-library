#pragma once
#include "../template.hpp"
#include "csr.hpp"

// 閉路検出
// find_cycle_directed(n, edges)   : 有向グラフの閉路を 1 つ．辺番号の列 (なければ空)
// find_cycle_undirected(n, edges) : 無向グラフの閉路を 1 つ．{頂点の列, 辺番号の列} (なければ空)
// どちらも非再帰の DFS で O(n + m)

inline vector<int> find_cycle_directed(int n, const vector<pair<int, int>> &edges) {
    int m = edges.size();
    vector<pair<int, int>> el(m);
    for (int i = 0; i < m; i++) el[i] = {edges[i].first, i};
    CSR<int> g(n, el);
    // state: 0 = 未訪問，1 = 探索中 (スタックにある)，2 = 終了
    vector<char> state(n, 0);
    vector<int> it(n), par_edge(n, -1), stk;
    for (int s = 0; s < n; s++) {
        if (state[s]) continue;
        stk.push_back(s), state[s] = 1, it[s] = g.start[s];
        while (!stk.empty()) {
            int v = stk.back();
            if (it[v] == g.start[v + 1]) {
                state[v] = 2, stk.pop_back();
                continue;
            }
            int e = g.elist[it[v]++], to = edges[e].second;
            if (state[to] == 0) {
                par_edge[to] = e, state[to] = 1, it[to] = g.start[to];
                stk.push_back(to);
            } else if (state[to] == 1) {
                // to → ... → v → to が閉路
                vector<int> cyc{e};
                for (int x = v; x != to; x = edges[par_edge[x]].first) cyc.push_back(par_edge[x]);
                reverse(cyc.begin(), cyc.end());
                return cyc;
            }
        }
    }
    return {};
}

inline pair<vector<int>, vector<int>> find_cycle_undirected(int n, const vector<pair<int, int>> &edges) {
    int m = edges.size();
    vector<pair<int, int>> el;
    el.reserve(2 * m);
    for (int i = 0; i < m; i++) {
        auto [u, v] = edges[i];
        if (u == v) return {{u}, {i}};  // 自己ループ
        el.push_back({u, i}), el.push_back({v, i});
    }
    CSR<int> g(n, el);
    vector<int> depth(n, -1), it(n), par_edge(n, -1), stk;
    for (int s = 0; s < n; s++) {
        if (depth[s] >= 0) continue;
        depth[s] = 0, it[s] = g.start[s], stk.push_back(s);
        while (!stk.empty()) {
            int v = stk.back();
            if (it[v] == g.start[v + 1]) {
                stk.pop_back();
                continue;
            }
            int e = g.elist[it[v]++];
            if (e == par_edge[v]) continue;
            int to = edges[e].first ^ edges[e].second ^ v;
            if (depth[to] < 0) {
                depth[to] = depth[v] + 1, par_edge[to] = e, it[to] = g.start[to];
                stk.push_back(to);
            } else if (depth[to] < depth[v]) {
                // to → ... → v → to (後退辺 e)
                vector<int> vs, es;
                for (int x = v; x != to;) {
                    vs.push_back(x), es.push_back(par_edge[x]);
                    int pe = par_edge[x];
                    x = edges[pe].first ^ edges[pe].second ^ x;
                }
                vs.push_back(to);
                reverse(vs.begin(), vs.end()), reverse(es.begin(), es.end());
                es.push_back(e);
                return {vs, es};
            }
        }
    }
    return {};
}
