#define PROBLEM "https://judge.yosupo.jp/problem/general_matching"
#include "../io/fastio.hpp"
#include "../graph/general_matching.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    GeneralMatching gm(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        gm.add_edge(u, v);
    }
    fout << gm.solve() << '\n';
    for (auto [u, v] : gm.matching()) fout << u << ' ' << v << '\n';
    return 0;
}
