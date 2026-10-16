#pragma once
#include "../template.hpp"
#include "csr.hpp"

// https://github.com/winter-2521/cp-library

// オイラー路 (全ての辺をちょうど 1 回ずつ通る路)．Hierholzer 法，非再帰で O(n + m)
// 返り値: {頂点の列 (m+1 個), 辺番号の列 (m 個)}．存在しなければ空の pair
// 辺がないときは {{0}, {}} (頂点 0 から長さ 0 の路)
// DIRECTED = true なら有向グラフ，false なら無向グラフ

template <bool DIRECTED>
pair<vector<int>, vector<int>> eulerian_trail(int n, const vector<pair<int, int>> &edges) {
    int m = edges.size();
    if (m == 0) return {{0}, {}};
    vector<int> deg(n, 0);  // 有向: 出次数 - 入次数，無向: 次数
    vector<pair<int, int>> el;
    el.reserve(DIRECTED ? m : 2 * m);
    for (int i = 0; i < m; i++) {
        auto [a, b] = edges[i];
        el.push_back({a, i});
        if (DIRECTED) deg[a]++, deg[b]--;
        else {
            el.push_back({b, i});
            deg[a]++, deg[b]++;
        }
    }
    // 始点: 有向なら 出 - 入 = 1 の頂点，無向なら次数が奇数の頂点．なければ辺を持つ頂点
    int s = edges[0].first, odd = 0;
    for (int v = 0; v < n; v++) {
        if (DIRECTED) {
            if (deg[v] == 1) s = v, odd++;
            else if (deg[v] != 0 && deg[v] != -1) return {};
            else if (deg[v] == -1) odd++;
        } else if (deg[v] & 1) {
            if (odd == 0) s = v;
            odd++;
        }
    }
    if (odd > 2) return {};
    CSR<int> g(n, el);
    vector<int> it(g.start.begin(), g.start.end() - 1);
    vector<char> used(m, 0);
    vector<int> vs, es;
    vs.reserve(m + 1), es.reserve(m);
    // スタックには (頂点, そこへ来た辺)
    vector<pair<int, int>> stk{{s, -1}};
    while (!stk.empty()) {
        auto [v, ein] = stk.back();
        int &i = it[v];
        while (i < g.start[v + 1] && used[g.elist[i]]) i++;
        if (i == g.start[v + 1]) {
            vs.push_back(v);
            if (ein >= 0) es.push_back(ein);
            stk.pop_back();
            continue;
        }
        int e = g.elist[i++];
        used[e] = 1;
        int to = DIRECTED ? edges[e].second : edges[e].first ^ edges[e].second ^ v;
        stk.push_back({to, e});
    }
    if ((int)es.size() != m) return {};  // 連結でない
    reverse(vs.begin(), vs.end()), reverse(es.begin(), es.end());
    return {vs, es};
}
