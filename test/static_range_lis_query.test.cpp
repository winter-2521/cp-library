#define PROBLEM "https://judge.yosupo.jp/problem/static_range_lis_query"
#include "../io/fastio.hpp"
#include "../data_structure/static_range_lis.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> p(n);
    fin >> p;
    StaticRangeLIS lis(p);
    while (q--) {
        int l, r;
        fin >> l >> r;
        fout << lis.query(l, r) << '\n';
    }
    return 0;
}
