#define PROBLEM "https://judge.yosupo.jp/problem/chordal_graph_recognition"
#include "../io/fastio.hpp"
#include "../graph/chordal_graph.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto &[a, b] : edges) fin >> a >> b;
    auto res = chordal_graph(n, edges);
    if (res.chordal) fout << "YES\n" << res.peo << '\n';
    else fout << "NO\n" << res.cycle.size() << '\n' << res.cycle << '\n';
    return 0;
}
