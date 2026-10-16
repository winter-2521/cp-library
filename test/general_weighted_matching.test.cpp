#define PROBLEM "https://judge.yosupo.jp/problem/general_weighted_matching"
#include "../io/fastio.hpp"
#include "../graph/general_weighted_matching.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    GeneralWeightedMatching<long long> wm(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        fin >> u >> v >> w;
        wm.add_edge(u, v, w);
    }
    auto [w, k] = wm.solve();
    auto es = wm.matching_edges();
    fout << es.size() << ' ' << w << '\n';
    for (auto [u, v] : es) fout << u << ' ' << v << '\n';
    return 0;
}
