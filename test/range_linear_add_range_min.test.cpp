#define PROBLEM "https://judge.yosupo.jp/problem/range_linear_add_range_min"
#include "../io/fastio.hpp"
#include "../data_structure/linear_add_min_segment_tree.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<long long> a(n);
    fin >> a;
    LinearAddMinSegmentTree<long long> seg(a);
    while (q--) {
        int t, l, r;
        fin >> t >> l >> r;
        if (t == 0) {
            long long b, c;
            fin >> b >> c;
            seg.add(l, r, b, c);
        } else {
            fout << seg.min(l, r) << '\n';
        }
    }
    return 0;
}
