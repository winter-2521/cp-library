#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../io/fastio.hpp"
#include "../graph/scc.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    StronglyConnectedComponents scc(n);
    scc.reserve(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        scc.add_edge(a, b);
    }
    int k = scc.build();
    fout << k << '\n';
    for (auto &g : scc.groups) fout << g.size() << ' ' << g << '\n';
    return 0;
}
