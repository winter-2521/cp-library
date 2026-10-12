#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../data_structure/dual_segment_tree.hpp"

using mint = ModInt998244353;

int main() {
    int n, q;
    fin >> n >> q;
    vector<mint> a(n);
    fin >> a;
    DualSegmentTree<MonoidAffine<mint>> seg(n);
    while (q--) {
        int t;
        fin >> t;
        if (t == 0) {
            int l, r;
            mint b, c;
            fin >> l >> r >> b >> c;
            seg.apply(l, r, {b, c});
        } else {
            int i;
            fin >> i;
            fout << seg.get(i)(a[i]) << '\n';
        }
    }
    return 0;
}
