#define PROBLEM "https://judge.yosupo.jp/problem/counting_spanning_tree_undirected"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../graph/count_spanning_trees.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto &[a, b] : edges) fin >> a >> b;
    fout << count_spanning_trees_undirected<ModInt998244353>(n, edges) << '\n';
    return 0;
}
