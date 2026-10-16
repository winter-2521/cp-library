#define PROBLEM "https://judge.yosupo.jp/problem/tree_decomposition_width_2"
#include "../io/fastio.hpp"
#include "../graph/tree_decomposition_width_2.hpp"

int main() {
    string p, tw;
    int n, m;
    fin >> p >> tw >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto &[a, b] : edges) fin >> a >> b, a--, b--;
    auto td = tree_decomposition_width_2(n, edges);
    if (!td) {
        fout << -1 << '\n';
        return 0;
    }
    int w = *max_element(td->bag_size.begin(), td->bag_size.end());
    fout << "s td " << n << ' ' << w - 1 << ' ' << n << '\n';
    for (int i = 0; i < n; i++) {
        fout << "b " << i + 1;
        for (int j = 0; j < td->bag_size[i]; j++) fout << ' ' << td->bags[i][j] + 1;
        fout << '\n';
    }
    for (auto [a, b] : td->edges) fout << a + 1 << ' ' << b + 1 << '\n';
    return 0;
}
