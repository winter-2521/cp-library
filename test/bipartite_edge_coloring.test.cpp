#define PROBLEM "https://judge.yosupo.jp/problem/bipartite_edge_coloring"
#include "../io/fastio.hpp"
#include "../graph/bipartite_edge_coloring.hpp"

int main() {
    int l, r, m;
    fin >> l >> r >> m;
    vector<pair<int, int>> edges(m);
    for (auto &[a, b] : edges) fin >> a >> b;
    auto [k, c] = bipartite_edge_coloring(l, r, edges);
    fout << k << '\n';
    for (int x : c) fout << x << '\n';
    return 0;
}
