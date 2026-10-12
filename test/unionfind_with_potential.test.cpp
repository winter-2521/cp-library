#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../data_structure/potentialized_unionfind.hpp"

using mint = ModInt998244353;

int main() {
    int n, q;
    fin >> n >> q;
    PotentializedUnionFind<AdditiveGroup<mint>> uf(n);
    while (q--) {
        int t, u, v;
        fin >> t >> u >> v;
        if (t == 0) {
            mint x;
            fin >> x;
            // a_u - a_v = x
            fout << uf.merge(v, u, x) << '\n';
        } else {
            if (uf.same(u, v)) fout << uf.diff(v, u) << '\n';
            else fout << -1 << '\n';
        }
    }
    return 0;
}
