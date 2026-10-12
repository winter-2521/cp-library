#define PROBLEM "https://judge.yosupo.jp/problem/persistent_range_affine_range_sum"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../data_structure/persistent_lazy_segment_tree.hpp"

using mint = ModInt998244353;
using AM = ActedAffineSum<mint>;

int main() {
    int n, q;
    fin >> n >> q;
    vector<AM::S> a(n);
    for (auto &x : a) x = AM::make(fin.read<mint>());
    PersistentLazySegmentTree<AM> seg(n);
    // root[k + 1] がバージョン A_k (root[0] が A_{-1})
    vector<int> root(q + 1, -1);
    root[0] = seg.build(a);
    for (int i = 0; i < q; i++) {
        int t, k;
        fin >> t >> k;
        if (t == 0) {
            int l, r;
            mint b, c;
            fin >> l >> r >> b >> c;
            root[i + 1] = seg.apply(root[k + 1], l, r, {b, c});
        } else if (t == 1) {
            int s, l, r;
            fin >> s >> l >> r;
            root[i + 1] = seg.copy_range(root[k + 1], root[s + 1], l, r);
        } else {
            int l, r;
            fin >> l >> r;
            fout << seg.prod(root[k + 1], l, r).sum << '\n';
        }
    }
    return 0;
}
