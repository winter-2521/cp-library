#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../math/modint.hpp"
#include "../../math/convolution.hpp"
#include "../../tree/hld.hpp"
#include "../../tree/tree_diameter.hpp"
#include "../../tree/rooted_tree_isomorphism.hpp"
#include "../../tree/frequency_table_of_tree_distance.hpp"

// 畳み込み・重軽分解 (LCA・距離・祖先・道の k 番目・道の区間・部分木の区間)・木の直径・部分木の同型分類・
// 距離の度数表を小さい入力の全探索と照合する

mt19937_64 rng(99);
long long rnd(long long lo, long long hi) { return lo + (long long)(rng() % (hi - lo + 1)); }

vector<pair<int, int>> random_tree(int n) {
    vector<pair<int, int>> es;
    // 形を偏らせる: 直線・星・ランダム
    int kind = rnd(0, 2);
    for (int v = 1; v < n; v++) {
        int p = kind == 0 ? v - 1 : kind == 1 ? 0 : (int)rnd(0, v - 1);
        es.push_back(rng() & 1 ? make_pair(p, v) : make_pair(v, p));
    }
    shuffle(es.begin(), es.end(), rng);
    return es;
}

void test_convolution() {
    for (int it = 0; it < 100; it++) {
        int n = rnd(1, 200), m = rnd(1, 200);
        vector<long long> a(n), b(m);
        for (auto &x : a) x = rnd(-1000000, 1000000);
        for (auto &x : b) x = rnd(-1000000, 1000000);
        vector<long long> c(n + m - 1, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) c[i + j] += a[i] * b[j];
        assert(convolve_ll(a, b) == c);
        using mint = ModInt998244353;
        vector<mint> x(a.begin(), a.end()), y(b.begin(), b.end());
        auto z = convolve(x, y);
        for (int i = 0; i < n + m - 1; i++) assert(z[i] == mint(c[i]));
        for (auto &v : a) v = rnd(0, 1000000);
        for (auto &v : b) v = rnd(0, 1000000);
        fill(c.begin(), c.end(), 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) c[i + j] += a[i] * b[j];
        assert(convolve_small(a, b) == c);
    }
}

void test_tree() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, 12), root = rnd(0, n - 1);
        auto es = random_tree(n);
        vector<vector<int>> g(n);
        for (auto [a, b] : es) g[a].push_back(b), g[b].push_back(a);
        // 根 root からの親と深さ
        vector<int> par(n, -1), dep(n, 0), order{root};
        for (size_t i = 0; i < order.size(); i++)
            for (int w : g[order[i]])
                if (w != par[order[i]]) par[w] = order[i], dep[w] = dep[order[i]] + 1, order.push_back(w);
        HLD h(n, es, root), h2(par);
        auto path = [&](int u, int v) {
            vector<int> a{u}, b{v};
            while (a.back() != b.back()) {
                if (dep[a.back()] >= dep[b.back()]) a.push_back(par[a.back()]);
                else b.push_back(par[b.back()]);
            }
            b.pop_back();
            a.insert(a.end(), b.rbegin(), b.rend());
            return a;
        };
        for (const HLD *hp : {&h, &h2}) {
            for (int u = 0; u < n; u++) {
                // 部分木の区間
                auto [l, r] = hp->subtree(u);
                set<int> sub;
                for (int v = 0; v < n; v++) {
                    int x = v;
                    while (x >= 0 && x != u) x = par[x];
                    if (x == u) sub.insert(hp->in[v]);
                }
                assert((int)sub.size() == r - l && *sub.begin() == l && *sub.rbegin() == r - 1);
                for (int k = 0; k <= n; k++) {
                    int x = u;
                    for (int t = 0; t < k && x >= 0; t++) x = par[x];
                    assert(hp->la(u, k) == x);
                }
                for (int v = 0; v < n; v++) {
                    auto p = path(u, v);
                    int w = p[0];
                    for (int x : p)
                        if (dep[x] < dep[w]) w = x;
                    assert(hp->lca(u, v) == w && hp->dist(u, v) == (int)p.size() - 1);
                    for (int i = 0; i <= n; i++) assert(hp->jump(u, v, i) == (i < (int)p.size() ? p[i] : -1));
                    // 道の区間の和集合 = 道の頂点
                    multiset<int> got, want;
                    hp->path(u, v, [&](int l2, int r2) {
                        for (int i = l2; i < r2; i++) got.insert(hp->ord[i]);
                    });
                    for (int x : p) want.insert(x);
                    assert(got == want);
                }
            }
        }
        // 直径
        vector<tuple<int, int, long long>> wes;
        for (auto [a, b] : es) wes.push_back({a, b, rnd(1, 9)});
        vector<vector<long long>> d(n, vector<long long>(n, 0));
        for (int s = 0; s < n; s++) {
            vector<int> st{s};
            vector<char> vis(n, 0);
            vis[s] = 1;
            while (!st.empty()) {
                int v = st.back();
                st.pop_back();
                for (auto [a, b, c] : wes) {
                    int w = a == v ? b : b == v ? a : -1;
                    if (w >= 0 && !vis[w]) vis[w] = 1, d[s][w] = d[s][v] + c, st.push_back(w);
                }
            }
        }
        long long best = 0;
        for (auto &r : d)
            for (auto x : r) best = max(best, x);
        auto [len, dp] = tree_diameter(n, wes);
        assert(len == best && d[dp.front()][dp.back()] == best);
        for (size_t i = 0; i + 1 < dp.size(); i++) {
            bool adj = false;
            for (auto [a, b, c] : wes) adj |= (a == dp[i] && b == dp[i + 1]) || (b == dp[i] && a == dp[i + 1]);
            assert(adj);
        }
        // 距離の度数表
        vector<long long> freq(n, 0);
        for (int u = 0; u < n; u++)
            for (int v = u + 1; v < n; v++) freq[path(u, v).size() - 1]++;
        assert(frequency_table_of_tree_distance(n, es) == freq);
        // 同型分類: 子の標準形の文字列で比べる
        vector<string> canon(n);
        for (int i = n - 1; i >= 0; i--) {
            int v = order[i];
            vector<string> cs;
            for (int w : g[v])
                if (w != par[v]) cs.push_back(canon[w]);
            sort(cs.begin(), cs.end());
            canon[v] = "(";
            for (auto &c : cs) canon[v] += c;
            canon[v] += ")";
        }
        auto [K, id] = rooted_tree_isomorphism(par);
        set<string> kinds(canon.begin(), canon.end());
        assert(K == (int)kinds.size());
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++) assert((id[u] == id[v]) == (canon[u] == canon[v]));
    }
}

int main() {
    test_convolution();
    test_tree();
    long long a, b;
    fin >> a >> b;
    fout << a + b << '\n';
    return 0;
}
