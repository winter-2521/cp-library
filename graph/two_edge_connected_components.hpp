#pragma once
#include "../template.hpp"
#include "csr.hpp"

// https://github.com/winter-2521/cp-library

// 二重辺連結成分分解 (橋で切った連結成分)．lowlink，非再帰 DFS で O(n + m)
// 返り値: 成分ごとの頂点の列．comp を渡すと各頂点の成分番号も入る
// is_bridge を渡すと各辺が橋かどうかも入る
inline vector<vector<int>> two_edge_connected_components(int n, const vector<pair<int, int>> &edges, vector<int> *comp_out = nullptr,
                                                         vector<char> *is_bridge = nullptr) {
    int m = edges.size();
    vector<pair<int, int>> el;
    el.reserve(2 * m);
    for (int i = 0; i < m; i++) {
        if (edges[i].first == edges[i].second) continue;
        el.push_back({edges[i].first, i}), el.push_back({edges[i].second, i});
    }
    CSR<int> g(n, el);
    vector<int> ord(n, -1), low(n), it(n), par_edge(n, -1), call, stk, comp(n, -1);
    vector<vector<int>> groups;
    if (is_bridge) is_bridge->assign(m, 0);
    int now = 0;
    for (int s = 0; s < n; s++) {
        if (ord[s] >= 0) continue;
        ord[s] = low[s] = now++, it[s] = g.start[s], call.push_back(s), stk.push_back(s);
        while (!call.empty()) {
            int v = call.back();
            if (it[v] < g.start[v + 1]) {
                int e = g.elist[it[v]++];
                if (e == par_edge[v]) continue;  // 来た辺 (多重辺は別の辺として扱う)
                int to = edges[e].first ^ edges[e].second ^ v;
                if (ord[to] < 0) {
                    ord[to] = low[to] = now++, it[to] = g.start[to], par_edge[to] = e;
                    call.push_back(to), stk.push_back(to);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
                continue;
            }
            call.pop_back();
            if (!call.empty()) low[call.back()] = std::min(low[call.back()], low[v]);
            if (low[v] == ord[v]) {
                // v から下の (まだ取り出していない) 頂点が 1 つの成分．v の親への辺は橋
                if (is_bridge && par_edge[v] >= 0) (*is_bridge)[par_edge[v]] = 1;
                int k = groups.size();
                groups.emplace_back();
                while (true) {
                    int u = stk.back();
                    stk.pop_back();
                    comp[u] = k, groups[k].push_back(u);
                    if (u == v) break;
                }
            }
        }
    }
    if (comp_out) *comp_out = comp;
    return groups;
}
