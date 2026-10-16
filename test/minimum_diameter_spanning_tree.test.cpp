#define PROBLEM "https://judge.yosupo.jp/problem/minimum_diameter_spanning_tree"
#include "../io/fastio.hpp"
#include "../graph/minimum_diameter_spanning_tree.hpp"

int main() {
    int n, m;
    fin >> n >> m;
    vector<tuple<int, int, long long>> edges(m);
    for (auto &[a, b, c] : edges) fin >> a >> b >> c;
    auto [x, es] = minimum_diameter_spanning_tree(n, edges);
    fout << x << '\n' << es << '\n';
    return 0;
}
