#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include "../io/fastio.hpp"
#include "../data_structure/segment_tree_beats.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<long long> a(n);
    fin >> a;
    SegmentTreeBeats<long long> seg(a);
    while (q--) {
        int t, l, r;
        fin >> t >> l >> r;
        if (t == 3) {
            fout << seg.sum(l, r) << '\n';
            continue;
        }
        long long b;
        fin >> b;
        if (t == 0) seg.chmin(l, r, b);
        else if (t == 1) seg.chmax(l, r, b);
        else seg.add(l, r, b);
    }
    return 0;
}
