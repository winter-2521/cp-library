#define PROBLEM "https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../data_structure/static_rectangle_add_rectangle_sum.hpp"

using mint = ModInt998244353;

int main() {
    int n, q;
    fin >> n >> q;
    StaticRectangleAddRectangleSum<int, mint> rs;
    for (int i = 0; i < n; i++) {
        int l, d, r, u;
        mint w;
        fin >> l >> d >> r >> u >> w;
        rs.add(l, d, r, u, w);
    }
    rs.build();
    while (q--) {
        int l, d, r, u;
        fin >> l >> d >> r >> u;
        fout << rs.sum(l, d, r, u) << '\n';
    }
    return 0;
}
