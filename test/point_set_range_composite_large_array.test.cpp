#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite_large_array"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../data_structure/dynamic_segment_tree.hpp"

using mint = ModInt998244353;

int main() {
    int n, q;
    fin >> n >> q;
    DynamicSegmentTree<MonoidAffine<mint>> seg(n);
    seg.reserve(q);
    while (q--) {
        int t;
        fin >> t;
        if (t == 0) {
            int p;
            mint c, d;
            fin >> p >> c >> d;
            seg.set(p, {c, d});
        } else {
            int l, r;
            mint x;
            fin >> l >> r >> x;
            fout << seg.prod(l, r)(x) << '\n';
        }
    }
    return 0;
}
