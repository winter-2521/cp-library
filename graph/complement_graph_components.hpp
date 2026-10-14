#pragma once
#include "../template.hpp"
#include "csr.hpp"

// 補グラフの連結成分分解．O(n + m)
// まだどの成分にも入っていない頂点を連結リストで持ち，BFS で頂点 v から「v と元のグラフで隣接していない未訪問頂点」を全部取る．
// 未訪問リストを 1 周するとき，取らなかった頂点は v の隣接頂点なので，1 周のコストは deg(v) + (取った数) で抑えられる
inline vector<vector<int>> complement_graph_components(int n, const vector<pair<int, int>> &edges) {
    vector<pair<int, int>> el;
    el.reserve(2 * edges.size());
    for (auto [a, b] : edges) el.push_back({a, b}), el.push_back({b, a});
    CSR<int> g(n, el);
    // 未訪問頂点の双方向リスト (番兵 n)
    vector<int> nx(n + 1), pv(n + 1);
    for (int i = 0; i <= n; i++) nx[i] = (i + 1) % (n + 1), pv[i] = (i + n) % (n + 1);
    auto erase = [&](int v) { nx[pv[v]] = nx[v], pv[nx[v]] = pv[v]; };
    vector<int> stamp(n, -1), que;
    que.reserve(n);
    vector<vector<int>> res;
    while (nx[n] != n) {
        int s = nx[n];
        erase(s);
        que.clear(), que.push_back(s);
        for (size_t h = 0; h < que.size(); h++) {
            int v = que[h];
            for (int i = g.start[v]; i < g.start[v + 1]; i++) stamp[g.elist[i]] = v;
            for (int u = nx[n]; u != n;) {
                int nu = nx[u];
                if (stamp[u] != v) erase(u), que.push_back(u);
                u = nu;
            }
        }
        res.push_back(que);
    }
    return res;
}
