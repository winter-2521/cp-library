#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../data_structure/segment_tree.hpp"

using mint = ModInt998244353;

int main() {
    int n, q;
    fin >> n >> q;
    vector<Affine<mint>> f(n);
    for (auto &x : f) fin >> x.a >> x.b;
    SegmentTree<MonoidAffine<mint>> seg(f);
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
