#define PROBLEM "https://judge.yosupo.jp/problem/dominatortree"
#include "../io/fastio.hpp"
#include "../graph/dominator_tree.hpp"

int main() {
    int n, m, s;
    fin >> n >> m >> s;
    vector<pair<int, int>> edges(m);
    for (auto &[a, b] : edges) fin >> a >> b;
    fout << dominator_tree(n, edges, s) << '\n';
    return 0;
}
