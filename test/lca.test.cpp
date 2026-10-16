#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../io/fastio.hpp"
#include "../tree/hld.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> par(n, -1);
    for (int i = 1; i < n; i++) fin >> par[i];
    HLD hld(par);
    while (q--) {
        int u, v;
        fin >> u >> v;
        fout << hld.lca(u, v) << '\n';
    }
    return 0;
}
