#pragma once
#include "../template.hpp"
#include "count_spanning_trees.hpp"

// https://github.com/winter-2521/cp-library

// 有向グラフのオイラー閉路の個数 (巡回シフトで一致するものは同じとみなす = 辺 0 から始まるものの個数)．BEST 定理
//   ec(G) = t_w(G) × Π_v (outdeg(v) - 1)!
// t_w(G) は頂点 w に向かう有向全域木 (各頂点 v ≠ w が「出ていく辺」を 1 本ずつ選ぶ) の個数で，辺を逆向きにした
// グラフの「w から出る有向全域木」の個数に等しい．辺のない頂点は除いて考える．O(n^3 + m)
// 入次数 ≠ 出次数の頂点があるか，辺のある頂点が全てつながっていなければ 0
template <class mint>
mint count_eulerian_circuits(int n, const vector<pair<int, int>> &edges) {
    int m = edges.size();
    if (m == 0) return mint(1);
    vector<int> indeg(n, 0), outdeg(n, 0);
    for (auto [a, b] : edges) outdeg[a]++, indeg[b]++;
    for (int v = 0; v < n; v++)
        if (indeg[v] != outdeg[v]) return mint(0);
    // 辺のある頂点に詰める
    vector<int> id(n, -1);
    int k = 0;
    for (int v = 0; v < n; v++)
        if (outdeg[v] > 0) id[v] = k++;
    vector<pair<int, int>> rev(m);
    for (int i = 0; i < m; i++) rev[i] = {id[edges[i].second], id[edges[i].first]};
    // 連結性は全域木の個数が 0 かどうかで分かる (入次数 = 出次数なので弱連結 ⇔ 強連結)
    mint res = count_spanning_trees_directed<mint>(k, rev, 0);
    vector<mint> fact(m + 1, mint(1));
    for (int i = 1; i <= m; i++) fact[i] = fact[i - 1] * mint(i);
    for (int v = 0; v < n; v++)
        if (outdeg[v] > 0) res *= fact[outdeg[v] - 1];
    return res;
}
