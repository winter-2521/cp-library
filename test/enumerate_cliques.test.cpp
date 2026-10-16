#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_cliques"
#include "../io/fastio.hpp"
#include "../graph/enumerate_cliques.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    vector<unsigned long long> x(n);
    for (auto &v : x) fin >> v;
    vector<pair<int, int>> edges(m);
    for (auto &[a, b] : edges) fin >> a >> b;
    const unsigned long long MOD = 998244353;
    unsigned long long ans = 0;
    enumerate_cliques(n, edges, [&](const vector<int> &c) {
        unsigned long long p = 1;
        for (int v : c) p = p * x[v] % MOD;
        ans += p;
        if (ans >= MOD) ans -= MOD;
    });
    fout << ans << '\n';
    return 0;
}
