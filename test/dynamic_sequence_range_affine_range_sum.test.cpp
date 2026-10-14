#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include "../io/fastio.hpp"
#include "../math/modint.hpp"
#include "../data_structure/dynamic_sequence.hpp"

using mint = ModInt998244353;
using AM = ActedAffineSum<mint>;

int main() {
    int n, q;
    fin >> n >> q;
    vector<AM::S> a(n);
    for (auto &x : a) x = AM::make(fin.read<mint>());
    DynamicSequence<AM> seq(a);
    seq.reserve(n + q);
    while (q--) {
        int t;
        fin >> t;
        if (t == 0) {
            int i;
            mint x;
            fin >> i >> x;
            seq.insert(i, AM::make(x));
        } else if (t == 1) {
            int i;
            fin >> i;
            seq.erase(i);
        } else if (t == 2) {
            int l, r;
            fin >> l >> r;
            seq.reverse(l, r);
        } else if (t == 3) {
            int l, r;
            mint b, c;
            fin >> l >> r >> b >> c;
            seq.apply(l, r, {b, c});
        } else {
            int l, r;
            fin >> l >> r;
            fout << seq.prod(l, r).sum << '\n';
        }
    }
    return 0;
}
