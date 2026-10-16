#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"
#include "../io/fastio.hpp"
#include "../tree/frequency_table_of_tree_distance.hpp"

int main() {
    int n;
    fin >> n;
    vector<pair<int, int>> edges(n - 1);
    for (auto &[a, b] : edges) fin >> a >> b;
    auto res = frequency_table_of_tree_distance(n, edges);
    res.erase(res.begin());
    fout << res << '\n';
    return 0;
}
