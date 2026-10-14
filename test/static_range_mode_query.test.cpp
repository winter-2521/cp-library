#define PROBLEM "https://judge.yosupo.jp/problem/static_range_mode_query"
#include "../io/fastio.hpp"
#include "../data_structure/static_range_mode.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> a(n);
    fin >> a;
    StaticRangeMode<int> md(a);
    while (q--) {
        int l, r;
        fin >> l >> r;
        auto [x, c] = md.query(l, r);
        fout << x << ' ' << c << '\n';
    }
    return 0;
}
