#pragma once
#include "../template.hpp"
#include "csr.hpp"

// https://github.com/winter-2521/cp-library

// 二重頂点連結成分分解 (関節点で切った成分)．lowlink + 辺のスタック，非再帰 DFS で O(n + m)
// 返り値: 成分ごとの頂点の列 (関節点は複数の成分に入る．孤立点は 1 頂点の成分)
// edge_groups を渡すと成分ごとの辺番号の列も入る
inline vector<vector<int>> biconnected_components(int n, const vector<pair<int, int>> &edges, vector<vector<int>> *edge_groups = nullptr) {
    int m = edges.size();
    vector<pair<int, int>> el;
    el.reserve(2 * m);
    for (int i = 0; i < m; i++) {
        if (edges[i].first == edges[i].second) continue;
        el.push_back({edges[i].first, i}), el.push_back({edges[i].second, i});
    }
    CSR<int> g(n, el);
    vector<int> ord(n, -1), low(n), it(n), par_edge(n, -1), call, estk;
    vector<vector<int>> res;
    if (edge_groups) edge_groups->clear();
    vector<int> mark(n, -1);  // 成分に入れた頂点の印 (成分番号)
    int now = 0;
    for (int s = 0; s < n; s++) {
        if (ord[s] >= 0) continue;
        ord[s] = low[s] = now++, it[s] = g.start[s], call.push_back(s);
        if (g.start[s] == g.start[s + 1]) {  // 孤立点 (自己ループだけの頂点も)
            res.push_back({s});
            if (edge_groups) edge_groups->emplace_back();
        }
        while (!call.empty()) {
            int v = call.back();
            if (it[v] < g.start[v + 1]) {
                int e = g.elist[it[v]++];
                if (e == par_edge[v]) continue;
                int to = edges[e].first ^ edges[e].second ^ v;
                if (ord[to] < 0) {
                    estk.push_back(e);
                    ord[to] = low[to] = now++, it[to] = g.start[to], par_edge[to] = e;
                    call.push_back(to);
                } else if (ord[to] < ord[v]) {
                    estk.push_back(e);  // 後退辺 (子孫から見た 1 回だけ積む)
                    low[v] = std::min(low[v], ord[to]);
                }
                continue;
            }
            call.pop_back();
            if (call.empty()) break;
            int p = call.back();
            low[p] = std::min(low[p], low[v]);
            if (low[v] >= ord[p]) {
                // p は関節点 (または根)．辺 (p, v) までをスタックから取り出したものが 1 つの成分
                int k = res.size();
                res.emplace_back();
                if (edge_groups) edge_groups->emplace_back();
                while (true) {
                    int e = estk.back();
                    estk.pop_back();
                    if (edge_groups) (*edge_groups)[k].push_back(e);
                    for (int x : {edges[e].first, edges[e].second})
                        if (mark[x] != k) mark[x] = k, res[k].push_back(x);
                    if (e == par_edge[v]) break;
                }
            }
        }
    }
    return res;
}
