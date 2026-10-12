#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_sort_range_composite"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../data_structure/sortable_segment_tree.hpp"

using mint = ModInt998244353;

int main() {
    int n, q;
    fin >> n >> q;
    vector<long long> p(n);
    vector<Affine<mint>> f(n);
    for (int i = 0; i < n; i++) fin >> p[i] >> f[i].a >> f[i].b;
    SortableSegmentTree<MonoidAffine<mint>> seg(p, f);
    while (q--) {
        int t;
        fin >> t;
        if (t == 0) {
            int i;
            long long key;
            mint a, b;
            fin >> i >> key >> a >> b;
            seg.set(i, key, {a, b});
        } else if (t == 1) {
            int l, r;
            mint x;
            fin >> l >> r >> x;
            fout << seg.prod(l, r)(x) << '\n';
        } else {
            int l, r;
            fin >> l >> r;
            if (t == 2) seg.sort_asc(l, r);
            else seg.sort_desc(l, r);
        }
    }
    return 0;
}
