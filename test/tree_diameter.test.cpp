#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "../io/fastio.hpp"
#include "../tree/tree_diameter.hpp"

int main() {
    int n;
    fin >> n;
    vector<tuple<int, int, long long>> edges(n - 1);
    for (auto &[a, b, c] : edges) fin >> a >> b >> c;
    auto [d, path] = tree_diameter(n, edges);
    fout << d << ' ' << path.size() << '\n' << path << '\n';
    return 0;
}
