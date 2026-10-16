#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../math/modint.hpp"
#include "../../graph/dominator_tree.hpp"
#include "../../graph/minimum_diameter_spanning_tree.hpp"
#include "../../graph/maximum_independent_set.hpp"
#include "../../graph/chromatic.hpp"
#include "../../graph/enumerate_triangles.hpp"
#include "../../graph/enumerate_cliques.hpp"
#include "../../graph/counting_c4.hpp"
#include "../../graph/tree_decomposition_width_2.hpp"
#include "../../graph/star_augmented_min_cut.hpp"

// 支配木・最小直径全域木・最大独立集合・彩色数・彩色多項式・三角形/クリーク列挙・C4 の数え上げ・
// 木幅 2 の木分解・スター付きグラフの最小カットを小さい入力の全探索と照合する

mt19937_64 rng(2026);
long long rnd(long long lo, long long hi) { return lo + (long long)(rng() % (hi - lo + 1)); }

// 単純無向グラフ (辺は各組 1 本)
vector<pair<int, int>> random_simple(int n, int p100) {
    vector<pair<int, int>> es;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (rnd(1, 100) <= p100) es.push_back(rng() & 1 ? make_pair(i, j) : make_pair(j, i));
    shuffle(es.begin(), es.end(), rng);
    return es;
}

void test_dominator() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, 7), m = rnd(0, 12), s = rnd(0, n - 1);
        vector<pair<int, int>> es(m);
        for (auto &[a, b] : es) a = rnd(0, n - 1), b = rnd(0, n - 1);
        auto par = dominator_tree(n, es, s);
        auto reach = [&](int banned) {
            vector<char> vis(n, 0);
            if (banned == s) return vis;
            vector<int> st{s};
            vis[s] = 1;
            while (!st.empty()) {
                int v = st.back();
                st.pop_back();
                for (auto [a, b] : es)
                    if (a == v && b != banned && !vis[b]) vis[b] = 1, st.push_back(b);
            }
            return vis;
        };
        auto r0 = reach(-1);
        // dom[v] = v の支配点 (v 自身を除く)
        vector<vector<int>> dom(n);
        for (int d = 0; d < n; d++) {
            auto r = reach(d);
            for (int v = 0; v < n; v++)
                if (v != d && r0[v] && !r[v]) dom[v].push_back(d);
        }
        for (int v = 0; v < n; v++) {
            if (!r0[v]) {
                assert(par[v] == -1);
                continue;
            }
            if (v == s) {
                assert(par[v] == s);
                continue;
            }
            // idom = 支配点のうち，他の全ての支配点に支配されるもの (支配点の数が最大)
            int best = -1;
            for (int d : dom[v])
                if (best < 0 || dom[d].size() > dom[best].size()) best = d;
            assert(par[v] == best);
        }
    }
}

void test_mdst() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, 6), extra = rnd(0, 3);
        vector<tuple<int, int, long long>> es;
        for (int v = 1; v < n; v++) es.push_back({(int)rnd(0, v - 1), v, rnd(0, 9)});
        for (int i = 0; i < extra && n >= 1; i++) es.push_back({(int)rnd(0, n - 1), (int)rnd(0, n - 1), rnd(0, 9)});
        shuffle(es.begin(), es.end(), rng);
        int m = es.size();
        auto diameter = [&](const vector<int> &ids) -> long long {
            // 木でなければ -1
            vector<vector<pair<int, long long>>> g(n);
            for (int i : ids) {
                auto [a, b, c] = es[i];
                if (a == b) return -1;
                g[a].push_back({b, c}), g[b].push_back({a, c});
            }
            long long best = 0;
            for (int s = 0; s < n; s++) {
                vector<long long> d(n, -1);
                d[s] = 0;
                vector<int> st{s};
                while (!st.empty()) {
                    int v = st.back();
                    st.pop_back();
                    for (auto [to, c] : g[v])
                        if (d[to] < 0) d[to] = d[v] + c, st.push_back(to);
                }
                for (int v = 0; v < n; v++) {
                    if (d[v] < 0) return -1;
                    best = max(best, d[v]);
                }
            }
            return best;
        };
        long long opt = LLONG_MAX;
        for (int mask = 0; mask < (1 << m); mask++) {
            if (__builtin_popcount(mask) != n - 1) continue;
            vector<int> ids;
            for (int i = 0; i < m; i++)
                if (mask >> i & 1) ids.push_back(i);
            long long d = diameter(ids);
            if (d >= 0) opt = min(opt, d);
        }
        auto [x, used] = minimum_diameter_spanning_tree(n, es);
        assert(x == opt);
        assert((int)used.size() == n - 1 && diameter(used) == opt);
    }
}

void test_mis_coloring() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, it < 150 ? 6 : 12);
        auto es = random_simple(n, rnd(0, 100));
        vector<int> nb(n, 0);
        for (auto [a, b] : es) nb[a] |= 1 << b, nb[b] |= 1 << a;
        auto indep = [&](int S) {
            for (int v = 0; v < n; v++)
                if ((S >> v & 1) && (nb[v] & S)) return false;
            return true;
        };
        int best = 0;
        for (int S = 0; S < (1 << n); S++)
            if (indep(S)) best = max(best, __builtin_popcount(S));
        auto mis = maximum_independent_set(n, es);
        int S = 0;
        for (int v : mis) S |= 1 << v;
        assert((int)mis.size() == best && indep(S));
        if (n > 6) continue;
        // P(k): k 色での塗り方 (k <= n + 1)
        vector<long long> P(n + 2, 0);
        for (int k = 0; k <= n + 1; k++) {
            vector<int> col(n, 0);
            while (true) {
                bool ok = k > 0;
                for (auto [a, b] : es)
                    if (col[a] == col[b]) ok = false;
                if (ok) P[k]++;
                if (k == 0) break;
                int i = 0;
                while (i < n && ++col[i] == k) col[i++] = 0;
                if (i == n) break;
            }
        }
        int chi = 0;
        while (P[chi] == 0) chi++;
        assert(chromatic_number(n, es) == chi);
        using mint = ModInt998244353;
        auto poly = chromatic_polynomial<mint>(n, es);
        for (int k = 0; k <= n + 1; k++) {
            mint v = 0, pw = 1;
            for (auto c : poly) v += c * pw, pw *= mint(k);
            assert(v == mint(P[k]));
        }
    }
}

void test_enumerate() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, 8);
        auto es = random_simple(n, rnd(0, 100));
        vector<int> nb(n, 0);
        for (auto [a, b] : es) nb[a] |= 1 << b, nb[b] |= 1 << a;
        set<int> tri, cl;
        enumerate_triangles(n, es, [&](int a, int b, int c) {
            int S = 1 << a | 1 << b | 1 << c;
            assert(__builtin_popcount(S) == 3 && !tri.count(S));
            tri.insert(S);
        });
        enumerate_cliques(n, es, [&](const vector<int> &c) {
            int S = 0;
            for (int v : c) S |= 1 << v;
            assert(__builtin_popcount(S) == (int)c.size() && !cl.count(S));
            cl.insert(S);
        });
        for (int S = 1; S < (1 << n); S++) {
            bool clique = true;
            for (int v = 0; v < n; v++)
                if ((S >> v & 1) && ((nb[v] | 1 << v) & S) != S) clique = false;
            assert(cl.count(S) == (size_t)clique);
            assert(tri.count(S) == (size_t)(clique && __builtin_popcount(S) == 3));
        }
    }
}

void test_c4() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(2, 6), m = rnd(1, 9);
        vector<pair<int, int>> es(m);
        for (auto &[a, b] : es) {
            a = rnd(0, n - 1);
            do b = rnd(0, n - 1);
            while (b == a);
        }
        auto res = counting_c4(n, es);
        for (int i = 0; i < m; i++) {
            long long cnt = 0;
            for (int x = 0; x < m; x++)
                for (int y = x + 1; y < m; y++)
                    for (int z = y + 1; z < m; z++) {
                        if (x == i || y == i || z == i) continue;
                        int ids[4] = {i, x, y, z};
                        map<int, int> deg;
                        for (int e : ids) deg[es[e].first]++, deg[es[e].second]++;
                        if (deg.size() != 4) continue;
                        bool ok = true;
                        for (auto [v, d] : deg) ok &= d == 2;
                        if (!ok) continue;
                        // 4 頂点・全て次数 2 で連結なら C4 (2 つの 2-閉路に分かれるのは多重辺が必要で，頂点 4 つでは
                        // 2 本ずつの多重辺 2 組になる)．連結性を確認
                        vector<int> vs;
                        for (auto [v, d] : deg) vs.push_back(v);
                        int a = es[i].first, b = es[i].second;
                        int pairs = 0;
                        for (int e : ids)
                            if ((es[e].first == a && es[e].second == b) || (es[e].first == b && es[e].second == a)) pairs++;
                        if (pairs == 2) continue;
                        bool multi = false;
                        for (int p = 0; p < 4; p++)
                            for (int q = p + 1; q < 4; q++) {
                                auto [c, d] = es[ids[p]];
                                auto [e2, f] = es[ids[q]];
                                if ((c == e2 && d == f) || (c == f && d == e2)) multi = true;
                            }
                        if (multi) continue;
                        cnt++;
                    }
            assert(res[i] == cnt);
        }
    }
}

void test_treewidth() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, 7);
        auto es = random_simple(n, rnd(0, 100));
        // 全ての消去順序を試し，消すときの次数が全て 2 以下のものがあるか
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        bool ok = false;
        do {
            vector<int> nb(n, 0);
            for (auto [a, b] : es) nb[a] |= 1 << b, nb[b] |= 1 << a;
            int alive = (1 << n) - 1;
            bool good = true;
            for (int v : perm) {
                int N = nb[v] & alive;
                if (__builtin_popcount(N) > 2) {
                    good = false;
                    break;
                }
                for (int x = 0; x < n; x++)
                    if (N >> x & 1) nb[x] |= N & ~(1 << x);
                alive &= ~(1 << v);
            }
            if (good) ok = true;
        } while (!ok && next_permutation(perm.begin(), perm.end()));
        auto td = tree_decomposition_width_2(n, es);
        assert(td.has_value() == ok);
        if (!td) continue;
        int K = td->bags.size();
        assert((int)td->edges.size() == K - 1);
        // 木か (連結)
        vector<int> p(K);
        iota(p.begin(), p.end(), 0);
        auto f = [&](auto self, int x) -> int { return p[x] == x ? x : p[x] = self(self, p[x]); };
        for (auto [a, b] : td->edges) {
            assert(f(f, a) != f(f, b));
            p[f(f, a)] = f(f, b);
        }
        auto has = [&](int i, int v) {
            for (int j = 0; j < td->bag_size[i]; j++)
                if (td->bags[i][j] == v) return true;
            return false;
        };
        for (auto [a, b] : es) {
            bool found = false;
            for (int i = 0; i < K; i++) found |= has(i, a) && has(i, b);
            assert(found);
        }
        for (int v = 0; v < n; v++) {
            // v を含むバッグが連結
            vector<int> q(K);
            iota(q.begin(), q.end(), 0);
            auto g = [&](auto self, int x) -> int { return q[x] == x ? x : q[x] = self(self, q[x]); };
            int cntb = 0, comps = 0;
            for (int i = 0; i < K; i++) cntb += has(i, v);
            for (auto [a, b] : td->edges)
                if (has(a, v) && has(b, v) && g(g, a) != g(g, b)) q[g(g, a)] = g(g, b), comps++;
            assert(cntb >= 1 && comps == cntb - 1);
        }
    }
}

void test_star_cut() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, 7);
        auto se = random_simple(n, rnd(0, 100));
        vector<tuple<int, int, long long>> es;
        for (auto [a, b] : se) es.push_back({a, b, rnd(0, 9)});
        vector<long long> a(n);
        for (auto &x : a) x = rnd(0, 9);
        StarAugmentedMinCut mc(n, es, a);
        for (int q = 0; q < 10; q++) {
            int x = rnd(0, n - 1);
            a[x] = rnd(0, 9);
            mc.set(x, a[x]);
            long long best = LLONG_MAX;
            for (int S = 1; S < (1 << n); S++) {
                long long c = 0;
                for (int v = 0; v < n; v++)
                    if (S >> v & 1) c += a[v];
                for (auto [u, v, w] : es)
                    if ((S >> u & 1) != (S >> v & 1)) c += w;
                best = min(best, c);
            }
            assert(mc.min_cut() == best);
        }
    }
}

int main() {
    test_dominator();
    test_mdst();
    test_mis_coloring();
    test_enumerate();
    test_c4();
    test_treewidth();
    test_star_cut();
    long long a, b;
    fin >> a >> b;
    fout << a + b << '\n';
    return 0;
}
