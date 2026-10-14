#pragma once
#include "../template.hpp"
#include "csr.hpp"

// 三重辺連結成分分解 (Tsin のパス吸収法，非再帰)．O(n + m)
// 各頂点 v について DFS 木の下に伸びる「v のパス」(path[v] でつながる頂点の列) と，
// v の成分から祖先へ出ていく辺の本数 deg[v] を持つ．子の成分の deg が 1 以下 (橋 / 2 辺カット) なら切り離し，
// そうでなければパスを v に吸収 (同じ成分として併合) する
inline vector<vector<int>> three_edge_connected_components(int n, const vector<pair<int, int>> &edges) {
    int m = edges.size();
    vector<pair<int, int>> el;
    el.reserve(2 * m);
    for (int i = 0; i < m; i++) {
        auto [a, b] = edges[i];
        if (a == b) continue;
        el.push_back({a, b}), el.push_back({b, a});
    }
    CSR<int> g(n, el);
    const int NONE = n;
    vector<int> in(n, -1), out(n), low(n, NONE), deg(n, 0), path(n, NONE), nxt(n);
    iota(nxt.begin(), nxt.end(), 0);  // 成分を巡回リストで持つ (併合は nxt の交換)
    auto absorb = [&](int v, int w) { swap(nxt[v], nxt[w]), deg[v] += deg[w]; };
    vector<int> it(n), par(n, NONE), call;
    vector<char> par_used(n, 0);  // 親への辺を 1 本だけ飛ばしたか (多重辺対策)
    int cnt = 0;
    for (int s = 0; s < n; s++) {
        if (in[s] >= 0) continue;
        in[s] = cnt++, it[s] = g.start[s], call.push_back(s);
        while (!call.empty()) {
            int v = call.back();
            if (it[v] < g.start[v + 1]) {
                int w = g.elist[it[v]++];
                if (w == par[v] && !par_used[v]) {
                    par_used[v] = 1;
                    continue;
                }
                if (in[w] >= 0) {
                    if (in[w] < in[v]) {  // 祖先への後退辺
                        deg[v]++;
                        low[v] = std::min(low[v], in[w]);
                    } else {  // 子孫からの後退辺: その子孫を含むパス上の頂点を吸収
                        deg[v]--;
                        int u = path[v];
                        while (u != NONE && in[u] <= in[w] && in[w] < out[u]) {
                            absorb(v, u);
                            u = path[u];
                        }
                        path[v] = u;
                    }
                    continue;
                }
                par[w] = v, in[w] = cnt++, it[w] = g.start[w];
                call.push_back(w);
                continue;
            }
            // v の探索終了
            out[v] = cnt;
            call.pop_back();
            if (call.empty()) break;
            int p = call.back(), w = v;
            if (path[w] == NONE && deg[w] <= 1) {
                // w の成分は (p, w) と高々 1 本の辺でしかつながらない → 独立した成分
                deg[p] += deg[w];
                low[p] = std::min(low[p], low[w]);
                continue;
            } else if (deg[w] == 0) {
                w = path[w];  // w 自身は切り離し，その下のパスだけ残す
            }
            if (low[w] < low[p]) {
                low[p] = low[w];
                swap(w, path[p]);  // より上に届くパスを p のパスにし，元のパスは吸収する
            }
            while (w != NONE) {
                absorb(p, w);
                w = path[w];
            }
        }
    }
    vector<vector<int>> res;
    vector<char> vis(n, 0);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        res.emplace_back();
        int y = i;
        do {
            vis[y] = 1, res.back().push_back(y);
            y = nxt[y];
        } while (y != i);
    }
    return res;
}
