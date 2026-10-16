#pragma once
#include "../template.hpp"
#include "csr.hpp"

// https://github.com/winter-2521/cp-library

// 強連結成分分解 (Tarjan, 非再帰)
// build() 後: groups はトポロジカル順 (辺 u → v なら u の成分が先)，comp[v] はその番号．O(n + m)
struct StronglyConnectedComponents {
    int n;
    vector<pair<int, int>> edges;
    vector<int> comp;
    vector<vector<int>> groups;

    StronglyConnectedComponents(int n = 0) : n(n) {}
    void reserve(int m) { edges.reserve(m); }
    void add_edge(int u, int v) { edges.push_back({u, v}); }

    // 成分の個数を返す
    int build() {
        CSR<int> g(n, edges);
        vector<int> ord(n, -1), low(n), it(n), stk, call;
        comp.assign(n, -1);
        stk.reserve(n), call.reserve(n);
        int now = 0, k = 0;
        for (int s = 0; s < n; s++) {
            if (ord[s] >= 0) continue;
            call.push_back(s), ord[s] = low[s] = now++, it[s] = g.start[s], stk.push_back(s);
            while (!call.empty()) {
                int v = call.back();
                if (it[v] < g.start[v + 1]) {
                    int to = g.elist[it[v]++];
                    if (ord[to] < 0) {
                        ord[to] = low[to] = now++, it[to] = g.start[to];
                        stk.push_back(to), call.push_back(to);
                    } else if (comp[to] < 0) {
                        low[v] = std::min(low[v], ord[to]);
                    }
                    continue;
                }
                call.pop_back();
                if (!call.empty()) low[call.back()] = std::min(low[call.back()], low[v]);
                if (low[v] == ord[v]) {
                    while (true) {
                        int u = stk.back();
                        stk.pop_back();
                        comp[u] = k;
                        if (u == v) break;
                    }
                    k++;
                }
            }
        }
        // Tarjan は逆トポロジカル順に番号を振るので反転する
        for (auto &c : comp) c = k - 1 - c;
        groups.assign(k, {});
        vector<int> cnt(k, 0);
        for (int v = 0; v < n; v++) cnt[comp[v]]++;
        for (int i = 0; i < k; i++) groups[i].reserve(cnt[i]);
        for (int v = 0; v < n; v++) groups[comp[v]].push_back(v);
        return k;
    }
};
