#define PROBLEM "https://judge.yosupo.jp/problem/counting_spanning_tree_directed"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../graph/count_spanning_trees.hpp"

int main() {
    int n, m, r;
    fin >> n >> m >> r;
    vector<pair<int, int>> edges(m);
    for (auto &[a, b] : edges) fin >> a >> b;
    fout << count_spanning_trees_directed<ModInt998244353>(n, edges, r) << '\n';
    return 0;
}
