#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../math/modint.hpp"
#include "../../math/determinant.hpp"
#include "../../graph/count_spanning_trees.hpp"
#include "../../graph/count_eulerian_circuits.hpp"
#include "../../graph/chordal_graph.hpp"
#include "../../graph/offline_dynamic_connectivity.hpp"

// 行列式・全域木の数え上げ (無向/有向)・オイラー閉路の数え上げ・弦グラフ判定・オフライン動的連結性を
// 小さい入力の全探索と照合する

using mint = ModInt998244353;
mt19937_64 rng(77);
long long rnd(long long lo, long long hi) { return lo + (long long)(rng() % (hi - lo + 1)); }

void test_determinant() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(0, 5);
        vector<vector<mint>> a(n, vector<mint>(n));
        for (auto &r : a)
            for (auto &x : r) x = rnd(-3, 3);
        // 置換の全探索
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        mint want = 0;
        do {
            int inv = 0;
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++) inv += p[i] > p[j];
            mint t = inv & 1 ? -1 : 1;
            for (int i = 0; i < n; i++) t *= a[i][p[i]];
            want += t;
        } while (next_permutation(p.begin(), p.end()));
        assert(determinant(a) == want);
    }
}

void test_spanning_trees() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, 5), m = rnd(0, 8), r = rnd(0, n - 1);
        vector<pair<int, int>> es(m);
        for (auto &[a, b] : es) a = rnd(0, n - 1), b = rnd(0, n - 1);
        long long und = 0, dir = 0;
        for (int mask = 0; mask < (1 << m); mask++) {
            if (__builtin_popcount(mask) != n - 1) continue;
            // 無向: 閉路なし (Union-Find)
            vector<int> p(n);
            iota(p.begin(), p.end(), 0);
            auto f = [&](auto self, int x) -> int { return p[x] == x ? x : p[x] = self(self, p[x]); };
            bool ok = true;
            for (int i = 0; i < m; i++)
                if (mask >> i & 1) {
                    auto [a, b] = es[i];
                    if (f(f, a) == f(f, b)) ok = false;
                    else p[f(f, a)] = f(f, b);
                }
            und += ok;
            // 有向: r 以外の各頂点に入る辺がちょうど 1 本で，r から全部に行ける
            vector<int> indeg(n, 0);
            for (int i = 0; i < m; i++)
                if (mask >> i & 1) indeg[es[i].second]++;
            bool good = indeg[r] == 0;
            for (int v = 0; v < n; v++)
                if (v != r && indeg[v] != 1) good = false;
            if (good) {
                vector<char> vis(n, 0);
                vis[r] = 1;
                for (int k = 0; k < n; k++)
                    for (int i = 0; i < m; i++)
                        if ((mask >> i & 1) && vis[es[i].first]) vis[es[i].second] = 1;
                for (int v = 0; v < n; v++) good &= vis[v] == 1;
            }
            dir += good;
        }
        assert(count_spanning_trees_undirected<mint>(n, es) == mint(und));
        assert(count_spanning_trees_directed<mint>(n, es, r) == mint(dir));
    }
}

void test_eulerian() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, 4), m = rnd(1, 7);
        vector<pair<int, int>> es(m);
        for (auto &[a, b] : es) a = rnd(0, n - 1), b = rnd(0, n - 1);
        // 辺 0 から始まるオイラー閉路を全探索
        long long cnt = 0;
        vector<char> used(m, 0);
        used[0] = 1;
        auto dfs = [&](auto self, int v, int k) -> void {
            if (k == m) {
                cnt += v == es[0].first;
                return;
            }
            for (int i = 0; i < m; i++)
                if (!used[i] && es[i].first == v) used[i] = 1, self(self, es[i].second, k + 1), used[i] = 0;
        };
        dfs(dfs, es[0].second, 1);
        assert(count_eulerian_circuits<mint>(n, es) == mint(cnt));
    }
}

void test_chordal() {
    for (int it = 0; it < 500; it++) {
        int n = rnd(1, 7);
        vector<pair<int, int>> es;
        int p100 = rnd(0, 100);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (rnd(1, 100) <= p100) es.push_back({i, j});
        vector<int> nb(n, 0);
        for (auto [a, b] : es) nb[a] |= 1 << b, nb[b] |= 1 << a;
        // 全探索: 単体的頂点 (隣がクリーク) を消し続けられるか
        auto clique = [&](int S) {
            for (int v = 0; v < n; v++)
                if ((S >> v & 1) && (S & ~nb[v] & ~(1 << v))) return false;
            return true;
        };
        int alive = (1 << n) - 1;
        bool progress = true;
        while (alive && progress) {
            progress = false;
            for (int v = 0; v < n; v++)
                if ((alive >> v & 1) && clique(nb[v] & alive)) {
                    alive &= ~(1 << v), progress = true;
                    break;
                }
        }
        bool chordal = alive == 0;
        auto res = chordal_graph(n, es);
        assert(res.chordal == chordal);
        if (chordal) {
            vector<int> pos(n);
            for (int i = 0; i < n; i++) pos[res.peo[i]] = i;
            for (int v = 0; v < n; v++) {
                int later = 0;
                for (int u = 0; u < n; u++)
                    if ((nb[v] >> u & 1) && pos[u] > pos[v]) later |= 1 << u;
                assert(clique(later));
            }
        } else {
            auto &c = res.cycle;
            int k = c.size();
            assert(k >= 4);
            set<int> s(c.begin(), c.end());
            assert((int)s.size() == k);
            for (int i = 0; i < k; i++)
                for (int j = i + 1; j < k; j++) {
                    bool adj = nb[c[i]] >> c[j] & 1, cyc = (j == i + 1) || (i == 0 && j == k - 1);
                    assert(adj == cyc);
                }
        }
    }
}

void test_dynamic_connectivity() {
    for (int it = 0; it < 200; it++) {
        int n = rnd(1, 6), q = rnd(1, 40);
        vector<long long> a(n);
        for (auto &x : a) x = rnd(0, 9);
        OfflineDynamicConnectivity dc(n, a);
        set<pair<int, int>> E;
        vector<long long> want;
        for (int t = 0; t < q; t++) {
            int type = rnd(0, 3);
            if (type == 0 && n >= 2) {
                int u = rnd(0, n - 1), v = rnd(0, n - 1);
                if (u == v || E.count(minmax(u, v))) continue;
                E.insert(minmax(u, v)), dc.link(u, v);
            } else if (type == 1 && !E.empty()) {
                auto it2 = E.begin();
                advance(it2, rnd(0, E.size() - 1));
                auto [u, v] = *it2;
                E.erase(it2);
                rng() & 1 ? dc.cut(u, v) : dc.cut(v, u);
            } else if (type == 2) {
                int v = rnd(0, n - 1);
                long long x = rnd(0, 9);
                a[v] += x, dc.add(v, x);
            } else {
                int v = rnd(0, n - 1);
                vector<char> vis(n, 0);
                vector<int> st{v};
                vis[v] = 1;
                long long s = 0;
                while (!st.empty()) {
                    int x = st.back();
                    st.pop_back();
                    s += a[x];
                    for (auto [p, r] : E) {
                        int y = p == x ? r : r == x ? p : -1;
                        if (y >= 0 && !vis[y]) vis[y] = 1, st.push_back(y);
                    }
                }
                want.push_back(s), dc.query(v);
            }
        }
        assert(dc.solve() == want);
    }
}

int main() {
    test_determinant();
    test_spanning_trees();
    test_eulerian();
    test_chordal();
    test_dynamic_connectivity();
    long long a, b;
    fin >> a >> b;
    fout << a + b << '\n';
    return 0;
}
