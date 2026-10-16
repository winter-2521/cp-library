#define PROBLEM "https://judge.yosupo.jp/problem/min_cost_b_flow"
#include "../io/fastio.hpp"
#include "../graph/min_cost_b_flow.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    MinCostBFlow<long long, long long> g(n);
    for (int v = 0; v < n; v++) g.add_supply(v, fin.read<long long>());
    for (int i = 0; i < m; i++) {
        int s, t;
        long long l, u, c;
        fin >> s >> t >> l >> u >> c;
        g.add_edge(s, t, l, u, c);
    }
    if (!g.solve()) {
        fout << "infeasible\n";
        return 0;
    }
    fout << g.cost() << '\n';
    for (int v = 0; v < n; v++) fout << g.potential(v) << '\n';
    for (int e = 0; e < m; e++) fout << g.flow(e) << '\n';
    return 0;
}
