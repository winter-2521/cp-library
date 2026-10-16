#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"
#include "../io/fastio.hpp"
#include "../graph/enumerate_triangles.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    vector<unsigned long long> x(n);
    for (auto &v : x) fin >> v;
    vector<pair<int, int>> edges(m);
    for (auto &[a, b] : edges) fin >> a >> b;
    const unsigned long long MOD = 998244353;
    unsigned long long ans = 0;
    enumerate_triangles(n, edges, [&](int a, int b, int c) { ans = (ans + x[a] * x[b] % MOD * x[c]) % MOD; });
    fout << ans << '\n';
    return 0;
}
