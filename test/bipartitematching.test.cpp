#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "../io/fastio.hpp"
#include "../graph/bipartite_matching.hpp"

int main() {
    int l, r, m;
    fin >> l >> r >> m;
    BipartiteMatching bm(l, r);
    bm.reserve(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        bm.add_edge(a, b);
    }
    fout << bm.solve() << '\n';
    for (auto [a, b] : bm.matching()) fout << a << ' ' << b << '\n';
    return 0;
}
