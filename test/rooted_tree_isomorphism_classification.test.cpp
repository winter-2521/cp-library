#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"
#include "../io/fastio.hpp"
#include "../tree/rooted_tree_isomorphism.hpp"

int main() {
    int n;
    fin >> n;
    vector<int> par(n, -1);
    for (int i = 1; i < n; i++) fin >> par[i];
    auto [k, id] = rooted_tree_isomorphism(par);
    fout << k << '\n' << id << '\n';
    return 0;
}
