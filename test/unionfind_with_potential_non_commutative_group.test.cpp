#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../data_structure/potentialized_unionfind.hpp"

using mint = ModInt998244353;

// 行列式 1 の 2x2 行列のなす群
struct SL2 {
    using T = array<mint, 4>;  // {a00, a01, a10, a11}
    static T op(const T &a, const T &b) {
        return {a[0] * b[0] + a[1] * b[2], a[0] * b[1] + a[1] * b[3], a[2] * b[0] + a[3] * b[2], a[2] * b[1] + a[3] * b[3]};
    }
    static T inv(const T &a) { return {a[3], -a[1], -a[2], a[0]}; }
    static T e() { return {1, 0, 0, 1}; }
};

int main() {
    int n, q;
    fin >> n >> q;
    PotentializedUnionFind<SL2> uf(n);
    while (q--) {
        int t, u, v;
        fin >> t >> u >> v;
        if (t == 0) {
            SL2::T x;
            for (auto &c : x) fin >> c;
            // a_u = a_v x
            fout << uf.merge(v, u, x) << '\n';
        } else {
            if (uf.same(u, v)) {
                auto m = uf.diff(v, u);
                fout << m[0] << ' ' << m[1] << ' ' << m[2] << ' ' << m[3] << '\n';
            } else {
                fout << -1 << '\n';
            }
        }
    }
    return 0;
}
