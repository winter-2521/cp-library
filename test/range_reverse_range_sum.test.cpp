#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"
#include "../io/fastio.hpp"
#include "../data_structure/dynamic_sequence.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<long long> a(n);
    fin >> a;
    DynamicSequence<ActedNone<MonoidSum<long long>>> seq(a);
    while (q--) {
        int t, l, r;
        fin >> t >> l >> r;
        if (t == 0) seq.reverse(l, r);
        else fout << seq.prod(l, r) << '\n';
    }
    return 0;
}
