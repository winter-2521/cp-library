#define PROBLEM "https://judge.yosupo.jp/problem/static_range_count_distinct"
#include "../io/fastio.hpp"
#include "../data_structure/static_range_count_distinct.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> a(n);
    fin >> a;
    StaticRangeCountDistinct<int> cd(a);
    while (q--) {
        int l, r;
        fin >> l >> r;
        fout << cd.count(l, r) << '\n';
    }
    return 0;
}
