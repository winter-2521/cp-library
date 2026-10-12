#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../data_structure/lazy_segment_tree.hpp"

using mint = ModInt998244353;
using AM = ActedAffineSum<mint>;

int main() {
    int n, q;
    fin >> n >> q;
    vector<AM::S> a(n);
    for (auto &x : a) x = AM::make(fin.read<mint>());
    LazySegmentTree<AM> seg(a);
    while (q--) {
        int t, l, r;
        fin >> t >> l >> r;
        if (t == 0) {
            mint b, c;
            fin >> b >> c;
            seg.apply(l, r, {b, c});
        } else {
            fout << seg.prod(l, r).sum << '\n';
        }
    }
    return 0;
}
