#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_point_set_rectangle_affine_rectangle_sum"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../data_structure/kd_tree.hpp"

using mint = ModInt998244353;
using AM = ActedAffineSum<mint>;

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> x(n), y(n);
    vector<AM::S> w(n);
    for (int i = 0; i < n; i++) x[i] = fin.read<int>(), y[i] = fin.read<int>(), w[i] = AM::make(fin.read<mint>());
    DynamicKDTree<int, AM> kd(x, y, w);
    while (q--) {
        int t;
        fin >> t;
        if (t == 0) {
            int a, b;
            mint c;
            fin >> a >> b >> c;
            kd.add_point(a, b, AM::make(c));
        } else if (t == 1) {
            int i;
            mint c;
            fin >> i >> c;
            kd.set(i, AM::make(c));
        } else if (t == 2) {
            int l, d, r, u;
            fin >> l >> d >> r >> u;
            fout << kd.prod(l, d, r, u).sum << '\n';
        } else {
            int l, d, r, u;
            mint a, b;
            fin >> l >> d >> r >> u >> a >> b;
            kd.apply(l, d, r, u, {a, b});
        }
    }
    return 0;
}
