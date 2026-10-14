#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
#include "../io/fastio.hpp"
#include "../data_structure/static_range_inversions.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> a(n);
    fin >> a;
    StaticRangeInversions<int> inv(a);
    while (q--) {
        int l, r;
        fin >> l >> r;
        fout << inv.query(l, r) << '\n';
    }
    return 0;
}
