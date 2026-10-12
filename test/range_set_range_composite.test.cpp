#define PROBLEM "https://judge.yosupo.jp/problem/range_set_range_composite"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../data_structure/range_assign_segment_tree.hpp"

using mint = ModInt998244353;

int main() {
    int n, q;
    fin >> n >> q;
    vector<Affine<mint>> f(n);
    for (auto &x : f) fin >> x.a >> x.b;
    RangeAssignSegmentTree<MonoidAffine<mint>> seg(f);
    while (q--) {
        int t, l, r;
        fin >> t >> l >> r;
        if (t == 0) {
            mint c, d;
            fin >> c >> d;
            seg.assign(l, r, {c, d});
        } else {
            mint x;
            fin >> x;
            fout << seg.prod(l, r)(x) << '\n';
        }
    }
    return 0;
}
