#define PROBLEM "https://judge.yosupo.jp/problem/incremental_scc"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../graph/incremental_scc.hpp"
#include "../graph/dsu.hpp"

using mint = ModInt998244353;

int main() {
    int n, m;
    fin >> n >> m;
    vector<mint> x(n);
    fin >> x;
    vector<pair<int, int>> edges(m);
    for (auto &[a, b] : edges) fin >> a >> b;
    auto t = incremental_scc(n, edges);
    // 時刻ごとに併合する辺
    vector<vector<int>> at(m + 2);
    for (int i = 0; i < m; i++) at[t[i]].push_back(i);
    vector<int> par(n);
    iota(par.begin(), par.end(), 0);
    vector<mint> sum = x;
    auto find = [&](int v) {
        while (par[v] != v) v = par[v] = par[par[v]];
        return v;
    };
    mint ans = 0;
    for (int k = 1; k <= m; k++) {
        for (int i : at[k]) {
            int a = find(edges[i].first), b = find(edges[i].second);
            if (a == b) continue;
            ans += sum[a] * sum[b];
            par[b] = a, sum[a] += sum[b];
        }
        fout << ans << '\n';
    }
    return 0;
}
