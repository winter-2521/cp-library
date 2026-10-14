#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"
#include "../io/fastio.hpp"
#include "../data_structure/static_range_frequency.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> a(n);
    fin >> a;
    StaticRangeFrequency<int> f(a);
    while (q--) {
        int l, r, x;
        fin >> l >> r >> x;
        fout << f.count(l, r, x) << '\n';
    }
    return 0;
}
