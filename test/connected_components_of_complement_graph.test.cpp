#define PROBLEM "https://judge.yosupo.jp/problem/connected_components_of_complement_graph"
#include "../io/fastio.hpp"
#include "../graph/complement_graph_components.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto &[a, b] : edges) fin >> a >> b;
    auto groups = complement_graph_components(n, edges);
    fout << groups.size() << '\n';
    for (auto &g : groups) fout << g.size() << ' ' << g << '\n';
    return 0;
}
