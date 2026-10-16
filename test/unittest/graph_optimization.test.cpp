#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../graph/minimum_spanning_tree.hpp"
#include "../../graph/directed_mst.hpp"
#include "../../graph/hungarian.hpp"
#include "../../graph/bipartite_matching.hpp"
#include "../../graph/general_matching.hpp"
#include "../../graph/general_weighted_matching.hpp"
#include "../../graph/bipartite_edge_coloring.hpp"
#include "../../graph/st_numbering.hpp"
#include "../../graph/min_cost_b_flow.hpp"

// 最小全域木・最小有向全域木・割当問題・二部マッチング・一般マッチング・重み付き一般マッチング・
// 二部グラフの辺彩色・st 番号付け・最小費用 b-flow を小さい入力の全探索と照合する

int main() {
    mt19937_64 rng(41);
    auto rnd = [&](long long lo, long long hi) { return lo + (long long)(rng() % (hi - lo + 1)); };
    for (int it = 0; it < 1500; it++) {
        int n = rnd(1, 6);
        // 最小全域木 (連結なら n-1 本．辺の部分集合を全探索)
        {
            int m = rnd(0, 8);
            vector<tuple<int, int, long long>> es(m);
            for (auto &[a, b, c] : es) a = rnd(0, n - 1), b = rnd(0, n - 1), c = rnd(0, 9);
            auto [w, used] = minimum_spanning_tree(n, es);
            long long best = LLONG_MAX;
            int best_cnt = -1;
            for (int mask = 0; mask < (1 << m); mask++) {
                vector<int> p(n);
                iota(p.begin(), p.end(), 0);
                auto f = [&](auto self, int x) -> int { return p[x] == x ? x : p[x] = self(self, p[x]); };
                bool ok = true;
                long long s = 0;
                int cnt = 0;
                for (int i = 0; i < m; i++)
                    if (mask >> i & 1) {
                        auto [a, b, c] = es[i];
                        if (f(f, a) == f(f, b)) ok = false;
                        p[f(f, a)] = f(f, b), s += c, cnt++;
                    }
                if (!ok) continue;
                if (cnt > best_cnt || (cnt == best_cnt && s < best)) best_cnt = cnt, best = s;
            }
            assert((int)used.size() == best_cnt && w == best);
        }
        // 最小有向全域木 (各頂点の親を全探索)
        {
            int m = rnd(0, 10), r = rnd(0, n - 1);
            vector<tuple<int, int, long long>> es;
            set<pair<int, int>> seen;
            for (int i = 0; i < m; i++) {
                int a = rnd(0, n - 1), b = rnd(0, n - 1);
                if (a == b || seen.count({a, b})) continue;
                seen.insert({a, b}), es.push_back({a, b, rnd(0, 9)});
            }
            // in[v] = v に入る辺の候補
            vector<vector<int>> in(n);
            for (int i = 0; i < (int)es.size(); i++) in[get<1>(es[i])].push_back(i);
            long long best = LLONG_MAX;
            vector<int> choice(n, -1);
            auto rec = [&](auto self, int v) -> void {
                if (v == n) {
                    // 全頂点が r から到達できるか (親をたどって r に着くか)
                    long long s = 0;
                    for (int u = 0; u < n; u++) {
                        if (u == r) continue;
                        s += get<2>(es[choice[u]]);
                        int x = u, steps = 0;
                        while (x != r && steps <= n) x = get<0>(es[choice[x]]), steps++;
                        if (x != r) return;
                    }
                    best = std::min(best, s);
                    return;
                }
                if (v == r) return self(self, v + 1);
                for (int e : in[v]) choice[v] = e, self(self, v + 1);
            };
            rec(rec, 0);
            auto [w, par] = directed_mst(n, es, r);
            if (best == LLONG_MAX) assert(par.empty());
            else {
                assert(w == best && par[r] == r);
                long long s = 0;
                for (int v = 0; v < n; v++) {
                    if (v == r) continue;
                    long long c = -1;
                    for (auto &[a, b, cc] : es)
                        if (a == par[v] && b == v) c = cc;
                    assert(c >= 0);
                    s += c;
                }
                assert(s == best);
            }
        }
        // 割当問題 (n × m，n <= m)
        {
            int rows = rnd(1, 5), cols = rnd(rows, 6);
            vector<vector<long long>> a(rows, vector<long long>(cols));
            for (auto &row : a)
                for (auto &x : row) x = rnd(-20, 20);
            auto [w, p] = hungarian(a);
            vector<int> perm(cols);
            iota(perm.begin(), perm.end(), 0);
            long long best = LLONG_MAX;
            do {
                long long s = 0;
                for (int i = 0; i < rows; i++) s += a[i][perm[i]];
                best = std::min(best, s);
            } while (next_permutation(perm.begin(), perm.end()));
            long long s = 0;
            set<int> cs(p.begin(), p.end());
            for (int i = 0; i < rows; i++) s += a[i][p[i]];
            assert(w == best && s == best && (int)cs.size() == rows);
        }
        // 二部マッチング・辺彩色
        {
            int L = rnd(1, 5), R = rnd(1, 5), m = rnd(0, 10);
            vector<pair<int, int>> es(m);
            for (auto &[a, b] : es) a = rnd(0, L - 1), b = rnd(0, R - 1);
            BipartiteMatching bm(L, R);
            for (auto [a, b] : es) bm.add_edge(a, b);
            int got = bm.solve();
            int best = 0;
            for (int mask = 0; mask < (1 << m); mask++) {
                vector<char> ul(L, 0), ur(R, 0);
                bool ok = true;
                for (int i = 0; i < m && ok; i++)
                    if (mask >> i & 1) {
                        auto [a, b] = es[i];
                        if (ul[a] || ur[b]) ok = false;
                        ul[a] = ur[b] = 1;
                    }
                if (ok) best = std::max(best, __builtin_popcount(mask));
            }
            assert(got == best);
            auto mt = bm.matching();
            assert((int)mt.size() == best);
            set<pair<int, int>> eset(es.begin(), es.end());
            for (auto e : mt) assert(eset.count(e));
            auto [K, col] = bipartite_edge_coloring(L, R, es);
            int D = 0;
            vector<int> dl(L, 0), dr(R, 0);
            for (auto [a, b] : es) D = std::max({D, ++dl[a], ++dr[b]});
            assert(K == D);
            set<pair<int, int>> usedl, usedr;
            for (int i = 0; i < m; i++) {
                assert(0 <= col[i] && col[i] < K);
                assert(usedl.insert({es[i].first, col[i]}).second);
                assert(usedr.insert({es[i].second, col[i]}).second);
            }
        }
        // 一般マッチング・重み付き一般マッチング (ビット DP)
        {
            int nn = rnd(1, 8), m = rnd(0, 14);
            vector<vector<long long>> w(nn, vector<long long>(nn, 0));
            GeneralMatching gm(nn);
            GeneralWeightedMatching<long long> wm(nn);
            for (int i = 0; i < m; i++) {
                int a = rnd(0, nn - 1), b = rnd(0, nn - 1);
                if (a == b || w[a][b]) continue;
                long long c = rnd(1, 10);
                w[a][b] = w[b][a] = c;
                gm.add_edge(a, b), wm.add_edge(a, b, c);
            }
            vector<int> card(1 << nn, 0);
            vector<long long> wt(1 << nn, 0);
            for (int mask = 1; mask < (1 << nn); mask++) {
                int v = __builtin_ctz(mask), rest = mask & ~(1 << v);
                card[mask] = card[rest], wt[mask] = wt[rest];
                for (int u = 0; u < nn; u++)
                    if ((rest >> u & 1) && w[v][u]) {
                        card[mask] = std::max(card[mask], card[rest & ~(1 << u)] + 1);
                        wt[mask] = std::max(wt[mask], wt[rest & ~(1 << u)] + w[v][u]);
                    }
            }
            int full = (1 << nn) - 1;
            assert(gm.solve() == card[full]);
            for (auto [a, b] : gm.matching()) assert(w[a][b]);
            auto [tw, cnt] = wm.solve();
            assert(tw == wt[full]);
            long long s = 0;
            vector<char> usedv(nn, 0);
            for (auto [a, b] : wm.matching_edges()) {
                assert(w[a][b] && !usedv[a] && !usedv[b]);
                usedv[a] = usedv[b] = 1, s += w[a][b];
            }
            assert(s == tw);
        }
        // st 番号付け (順列を全探索)
        if (n >= 2) {
            int m = rnd(0, 8), s = rnd(0, n - 1), t = rnd(0, n - 2);
            if (t >= s) t++;
            vector<pair<int, int>> es;
            for (int i = 0; i < m; i++) {
                int a = rnd(0, n - 1), b = rnd(0, n - 1);
                if (a != b) es.push_back({a, b});
            }
            auto valid = [&](const vector<int> &p) {
                if (p[s] != 0 || p[t] != n - 1) return false;
                for (int v = 0; v < n; v++) {
                    if (v == s || v == t) continue;
                    bool lo = false, hi = false;
                    for (auto [a, b] : es) {
                        int o = a == v ? b : (b == v ? a : -1);
                        if (o < 0) continue;
                        if (p[o] < p[v]) lo = true;
                        else hi = true;
                    }
                    if (!lo || !hi) return false;
                }
                // s から t に辺があるか (n = 2)
                if (n == 2) {
                    bool e = false;
                    for (auto [a, b] : es) e |= (a == s && b == t) || (a == t && b == s);
                    return e;
                }
                return true;
            };
            vector<int> perm(n);
            iota(perm.begin(), perm.end(), 0);
            bool exists = false;
            do exists |= valid(perm);
            while (!exists && next_permutation(perm.begin(), perm.end()));
            auto p = st_numbering(n, es, s, t);
            assert(exists == !p.empty());
            if (!p.empty()) assert(valid(p));
        }
        // 最小費用 b-flow (流量を全探索．容量は小さく)
        {
            int nn = rnd(1, 3), m = rnd(0, 4);
            MinCostBFlow<long long, long long> mf(nn);
            vector<long long> b(nn);
            for (auto &x : b) x = rnd(-2, 2);
            long long sum = 0;
            for (auto x : b) sum += x;
            b[0] -= sum;  // 和を 0 に
            for (int v = 0; v < nn; v++) mf.add_supply(v, b[v]);
            vector<array<long long, 5>> es(m);
            for (auto &e : es) {
                e[0] = rnd(0, nn - 1), e[1] = rnd(0, nn - 1), e[2] = rnd(0, 1), e[3] = e[2] + rnd(0, 2), e[4] = rnd(-5, 5);
                mf.add_edge(e[0], e[1], e[2], e[3], e[4]);
            }
            // 全探索
            long long best = LLONG_MAX;
            vector<long long> f(m);
            auto rec = [&](auto self, int i) -> void {
                if (i == m) {
                    vector<long long> bal(nn, 0);
                    long long c = 0;
                    for (int j = 0; j < m; j++) bal[es[j][0]] += f[j], bal[es[j][1]] -= f[j], c += es[j][4] * f[j];
                    if (bal == b) best = std::min(best, c);
                    return;
                }
                for (f[i] = es[i][2]; f[i] <= es[i][3]; f[i]++) self(self, i + 1);
            };
            rec(rec, 0);
            bool ok = mf.solve();
            assert(ok == (best != LLONG_MAX));
            if (ok) {
                assert(mf.cost() == (__int128)best);
                vector<long long> bal(nn, 0);
                for (int j = 0; j < m; j++) {
                    long long fl = mf.flow(j);
                    assert(es[j][2] <= fl && fl <= es[j][3]);
                    bal[es[j][0]] += fl, bal[es[j][1]] -= fl;
                    long long rc = es[j][4] + mf.potential(es[j][0]) - mf.potential(es[j][1]);
                    if (fl > es[j][2]) assert(rc <= 0);
                    if (fl < es[j][3]) assert(rc >= 0);
                }
                assert(bal == b);
            }
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
