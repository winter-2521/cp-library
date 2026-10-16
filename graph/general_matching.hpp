#pragma once
#include "../template.hpp"
#include "csr.hpp"

// https://github.com/winter-2521/cp-library

// 一般グラフの最大マッチング (Edmonds の花アルゴリズム)．O(n^3)
// 未マッチの頂点から交互路を BFS で探し，奇閉路 (花) を見つけたら 1 頂点 (base) に縮約したものとして扱う．
// 縮約は base[] (各頂点が属する花の代表) で表し，実際にはグラフを作り直さない
struct GeneralMatching {
    int n;
    vector<pair<int, int>> edges;
    vector<int> mate;  // 相手 (いなければ -1)

    GeneralMatching(int n) : n(n), mate(n, -1) {}
    void add_edge(int u, int v) { edges.push_back({u, v}); }

    int solve() {
        vector<pair<int, int>> el;
        el.reserve(2 * edges.size());
        for (auto [u, v] : edges)
            if (u != v) el.push_back({u, v}), el.push_back({v, u});
        CSR<int> g(n, el);
        // 貪欲に初期マッチング
        for (int v = 0; v < n; v++) {
            if (mate[v] >= 0) continue;
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                int w = g.elist[i];
                if (mate[w] < 0) {
                    mate[v] = w, mate[w] = v;
                    break;
                }
            }
        }
        vector<int> par(n), base(n), que(n), mark(n, 0);
        vector<char> used(n), in_blossom(n);
        int stamp = 0;
        // 花の base を求める (交互木の 2 頂点の最近共通祖先)
        auto lca = [&](int a, int b) {
            stamp++;
            while (true) {
                a = base[a];
                mark[a] = stamp;
                if (mate[a] < 0) break;
                a = par[mate[a]];
            }
            while (true) {
                b = base[b];
                if (mark[b] == stamp) return b;
                b = par[mate[b]];
            }
        };
        auto mark_path = [&](int v, int b, int child) {
            while (base[v] != b) {
                in_blossom[base[v]] = in_blossom[base[mate[v]]] = 1;
                par[v] = child;
                child = mate[v];
                v = par[mate[v]];
            }
        };
        // root から増加路を探し，終点 (未マッチ頂点) を返す．なければ -1
        auto find_path = [&](int root) {
            fill(used.begin(), used.end(), 0);
            fill(par.begin(), par.end(), -1);
            iota(base.begin(), base.end(), 0);
            int qh = 0, qt = 0;
            used[root] = 1, que[qt++] = root;
            while (qh < qt) {
                int v = que[qh++];
                for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                    int to = g.elist[i];
                    if (base[v] == base[to] || mate[v] == to) continue;
                    if (to == root || (mate[to] >= 0 && par[mate[to]] >= 0)) {
                        // 奇閉路 (花) を見つけた: base を cur にまとめる
                        int cur = lca(v, to);
                        fill(in_blossom.begin(), in_blossom.end(), 0);
                        mark_path(v, cur, to), mark_path(to, cur, v);
                        for (int x = 0; x < n; x++) {
                            if (!in_blossom[base[x]]) continue;
                            base[x] = cur;
                            if (!used[x]) used[x] = 1, que[qt++] = x;
                        }
                    } else if (par[to] < 0) {
                        par[to] = v;
                        if (mate[to] < 0) return to;
                        int nx = mate[to];
                        used[nx] = 1, que[qt++] = nx;
                    }
                }
            }
            return -1;
        };
        for (int v = 0; v < n; v++) {
            if (mate[v] >= 0) continue;
            int u = find_path(v);
            // 増加路に沿ってマッチングを反転
            while (u >= 0) {
                int pv = par[u], ppv = mate[pv];
                mate[u] = pv, mate[pv] = u;
                u = ppv;
            }
        }
        int res = 0;
        for (int v = 0; v < n; v++)
            if (mate[v] > v) res++;
        return res;
    }

    // マッチングの辺 (u < v)
    vector<pair<int, int>> matching() const {
        vector<pair<int, int>> res;
        for (int v = 0; v < n; v++)
            if (mate[v] > v) res.push_back({v, mate[v]});
        return res;
    }
};
