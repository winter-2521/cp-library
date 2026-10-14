#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../graph/cycle_detection.hpp"
#include "../../graph/scc.hpp"
#include "../../graph/two_edge_connected_components.hpp"
#include "../../graph/three_edge_connected_components.hpp"
#include "../../graph/biconnected_components.hpp"
#include "../../graph/complement_graph_components.hpp"
#include "../../graph/eulerian_trail.hpp"

// 閉路検出・SCC・二重辺連結・三重辺連結・二重頂点連結・補グラフの連結成分・オイラー路を
// 小さいランダムグラフ (多重辺・自己ループあり) で愚直と照合する

using Edges = vector<pair<int, int>>;

// removed[e] の辺を除いた無向グラフの連結成分番号
vector<int> undirected_cc(int n, const Edges &es, const vector<char> &removed) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto f = [&](auto self, int x) -> int { return p[x] == x ? x : p[x] = self(self, p[x]); };
    for (int i = 0; i < (int)es.size(); i++)
        if (!removed[i]) p[f(f, es[i].first)] = f(f, es[i].second);
    vector<int> c(n);
    for (int i = 0; i < n; i++) c[i] = f(f, i);
    return c;
}

// 頂点の分割を正規化 (各集合をソートして全体をソート)
vector<vector<int>> normalize(vector<vector<int>> g) {
    for (auto &x : g) sort(x.begin(), x.end());
    sort(g.begin(), g.end());
    return g;
}

int main() {
    mt19937_64 rng(31);
    for (int it = 0; it < 3000; it++) {
        int n = rng() % 7 + 1, m = rng() % 9;
        Edges es(m);
        for (auto &[a, b] : es) a = rng() % n, b = rng() % n;
        // 有向: 到達可能性
        vector<vector<char>> reach(n, vector<char>(n, 0));
        for (int i = 0; i < n; i++) reach[i][i] = 1;
        for (auto [a, b] : es) reach[a][b] = 1;
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) reach[i][j] |= reach[i][k] && reach[k][j];
        // 有向閉路
        {
            bool has = false;
            for (auto [a, b] : es) has |= reach[b][a];
            auto cyc = find_cycle_directed(n, es);
            assert(has == !cyc.empty());
            if (!cyc.empty()) {
                set<int> used(cyc.begin(), cyc.end());
                assert(used.size() == cyc.size());
                for (size_t i = 0; i < cyc.size(); i++) assert(es[cyc[i]].second == es[cyc[(i + 1) % cyc.size()]].first);
            }
        }
        // SCC
        {
            StronglyConnectedComponents scc(n);
            for (auto [a, b] : es) scc.add_edge(a, b);
            scc.build();
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) assert((scc.comp[i] == scc.comp[j]) == (reach[i][j] && reach[j][i]));
            for (auto [a, b] : es) assert(scc.comp[a] <= scc.comp[b]);
            for (int k = 0; k < (int)scc.groups.size(); k++)
                for (int v : scc.groups[k]) assert(scc.comp[v] == k);
        }
        // 無向閉路 (森でないか)
        {
            vector<char> none(m, 0);
            auto c = undirected_cc(n, es, none);
            set<int> comps(c.begin(), c.end());
            bool has = m > n - (int)comps.size();
            auto [vs, ecs] = find_cycle_undirected(n, es);
            assert(has == !ecs.empty());
            if (!ecs.empty()) {
                int L = vs.size();
                assert((int)ecs.size() == L && set<int>(vs.begin(), vs.end()).size() == vs.size() && set<int>(ecs.begin(), ecs.end()).size() == ecs.size());
                for (int i = 0; i < L; i++) {
                    auto [a, b] = es[ecs[i]];
                    int x = vs[i], y = vs[(i + 1) % L];
                    assert((a == x && b == y) || (a == y && b == x));
                }
            }
        }
        // 二重辺連結・三重辺連結: k 本未満の辺を除いて非連結にできないか
        for (int k : {2, 3}) {
            vector<vector<char>> same(n, vector<char>(n, 1));
            vector<char> rem(m, 0);
            auto check = [&]() {
                auto c = undirected_cc(n, es, rem);
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        if (c[i] != c[j]) same[i][j] = 0;
            };
            check();
            for (int a = 0; a < m; a++) {
                rem[a] = 1, check();
                if (k == 3)
                    for (int b = a + 1; b < m; b++) rem[b] = 1, check(), rem[b] = 0;
                rem[a] = 0;
            }
            auto groups = k == 2 ? two_edge_connected_components(n, es) : three_edge_connected_components(n, es);
            vector<int> gid(n, -1);
            for (int g = 0; g < (int)groups.size(); g++)
                for (int v : groups[g]) assert(gid[v] < 0), gid[v] = g;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) assert((gid[i] == gid[j]) == (bool)same[i][j]);
        }
        // 二重頂点連結: 単純閉路を全列挙し，同じ閉路に乗る辺を併合
        {
            vector<int> p(m);
            iota(p.begin(), p.end(), 0);
            auto f = [&](auto self, int x) -> int { return p[x] == x ? x : p[x] = self(self, p[x]); };
            vector<char> onv(n, 0);
            vector<int> path;
            // 頂点 s を最小とする単純閉路を辺の列で列挙
            auto dfs = [&](auto self, int s, int v) -> void {
                for (int e = 0; e < m; e++) {
                    auto [a, b] = es[e];
                    if (a == b) continue;
                    if (a != v && b != v) continue;
                    if (!path.empty() && path.back() == e) continue;
                    int to = a ^ b ^ v;
                    if (to == s && !path.empty()) {
                        if (path.size() == 1 && path[0] == e) continue;
                        for (int x : path) p[f(f, x)] = f(f, e);
                        continue;
                    }
                    if (to < s || onv[to]) continue;
                    onv[to] = 1, path.push_back(e);
                    self(self, s, to);
                    onv[to] = 0, path.pop_back();
                }
            };
            for (int s = 0; s < n; s++) onv[s] = 1, dfs(dfs, s, s), onv[s] = 0;
            map<int, set<int>> blocks;
            vector<char> has_edge(n, 0);
            for (int e = 0; e < m; e++) {
                auto [a, b] = es[e];
                if (a == b) continue;
                blocks[f(f, e)].insert(a), blocks[f(f, e)].insert(b);
                has_edge[a] = has_edge[b] = 1;
            }
            vector<vector<int>> exp;
            for (auto &[k2, st] : blocks) exp.push_back(vector<int>(st.begin(), st.end()));
            for (int v = 0; v < n; v++)
                if (!has_edge[v]) exp.push_back({v});
            assert(normalize(biconnected_components(n, es)) == normalize(exp));
        }
        // 補グラフ (単純グラフにしてから)
        {
            set<pair<int, int>> st;
            for (auto [a, b] : es)
                if (a != b) st.insert({min(a, b), max(a, b)});
            Edges simple(st.begin(), st.end());
            vector<vector<char>> adj(n, vector<char>(n, 0));
            for (auto [a, b] : simple) adj[a][b] = adj[b][a] = 1;
            Edges comp_edges;
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    if (!adj[i][j]) comp_edges.push_back({i, j});
            auto c = undirected_cc(n, comp_edges, vector<char>(comp_edges.size(), 0));
            map<int, vector<int>> mp;
            for (int i = 0; i < n; i++) mp[c[i]].push_back(i);
            vector<vector<int>> exp;
            for (auto &[k2, v] : mp) exp.push_back(v);
            assert(normalize(complement_graph_components(n, simple)) == normalize(exp));
        }
        // オイラー路 (有向・無向)．辺の順列を全部試す愚直 (m <= 6)
        if (m <= 6) {
            for (int dir = 0; dir < 2; dir++) {
                vector<int> perm(m);
                iota(perm.begin(), perm.end(), 0);
                bool exists = false;
                do {
                    // 無向は各辺の向きも試す
                    for (int mask = 0; mask < (dir ? 1 : (1 << m)) && !exists; mask++) {
                        bool ok = true;
                        int cur = -1;
                        for (int i = 0; i < m && ok; i++) {
                            auto [a, b] = es[perm[i]];
                            if (mask >> i & 1) swap(a, b);
                            if (cur >= 0 && a != cur) ok = false;
                            cur = b;
                        }
                        exists |= ok;
                    }
                } while (!exists && next_permutation(perm.begin(), perm.end()));
                auto [vs, ecs] = dir ? eulerian_trail<true>(n, es) : eulerian_trail<false>(n, es);
                assert(exists == !vs.empty() || m == 0);
                if (!vs.empty()) {
                    assert((int)vs.size() == m + 1 && (int)ecs.size() == m);
                    assert(set<int>(ecs.begin(), ecs.end()).size() == ecs.size());
                    for (int i = 0; i < m; i++) {
                        auto [a, b] = es[ecs[i]];
                        if (dir) assert(a == vs[i] && b == vs[i + 1]);
                        else assert((a == vs[i] && b == vs[i + 1]) || (b == vs[i] && a == vs[i + 1]));
                    }
                }
            }
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
