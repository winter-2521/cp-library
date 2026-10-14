#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection_undirected"
#include "../io/fastio.hpp"
#include "../graph/cycle_detection.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto &[u, v] : edges) fin >> u >> v;
    auto [vs, es] = find_cycle_undirected(n, edges);
    if (es.empty()) {
        fout << -1 << '\n';
        return 0;
    }
    fout << vs.size() << '\n' << vs << '\n' << es << '\n';
    return 0;
}
