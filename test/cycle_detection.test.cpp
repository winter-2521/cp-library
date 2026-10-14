#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#include "../io/fastio.hpp"
#include "../graph/cycle_detection.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto &[u, v] : edges) fin >> u >> v;
    auto cyc = find_cycle_directed(n, edges);
    if (cyc.empty()) {
        fout << -1 << '\n';
        return 0;
    }
    fout << cyc.size() << '\n';
    for (int e : cyc) fout << e << '\n';
    return 0;
}
