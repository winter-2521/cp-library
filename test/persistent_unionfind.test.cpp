#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include "../io/fastio.hpp"
#include "../data_structure/persistent_unionfind.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    PersistentUnionFind uf(n);
    uf.reserve(q);
    vector<int> ver(q + 1);  // ver[i + 1] = G_i の版
    ver[0] = uf.initial_version();
    for (int i = 0; i < q; i++) {
        int t, k, u, v;
        fin >> t >> k >> u >> v;
        if (t == 0) ver[i + 1] = uf.merge(ver[k + 1], u, v);
        else fout << uf.same(ver[k + 1], u, v) << '\n';
    }
    return 0;
}
