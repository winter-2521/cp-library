#define PROBLEM "https://judge.yosupo.jp/problem/global_minimum_cut_of_dynamic_star_augmented_graph"
#include "../io/fastio.hpp"
#include "../graph/star_augmented_min_cut.hpp"

int main() {
    int n, m, q;
    fin >> n >> m >> q;
    vector<long long> a(n);
    fin >> a;
    vector<tuple<int, int, long long>> edges(m);
    for (auto &[u, v, w] : edges) fin >> u >> v >> w;
    StarAugmentedMinCut mc(n, edges, a);
    while (q--) {
        int x;
        long long y;
        fin >> x >> y;
        mc.set(x, y);
        fout << mc.min_cut() << '\n';
    }
    return 0;
}
