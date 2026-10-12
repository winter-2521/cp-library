#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../io/fastio.hpp"
#include "../data_structure/cumulative_sum.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> a(n);
    fin >> a;
    CumulativeSum<long long> cs(a);
    while (q--) {
        int l, r;
        fin >> l >> r;
        fout << cs.sum(l, r) << '\n';
    }
    return 0;
}
