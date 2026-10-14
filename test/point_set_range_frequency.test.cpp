#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_frequency"
#include "../io/fastio.hpp"
#include "../data_structure/dynamic_range_frequency.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> a(n);
    fin >> a;
    DynamicRangeFrequency<int> f(a);
    while (q--) {
        int t;
        fin >> t;
        if (t == 0) {
            int k, v;
            fin >> k >> v;
            f.set(k, v);
        } else {
            int l, r, x;
            fin >> l >> r >> x;
            fout << f.count(l, r, x) << '\n';
        }
    }
    return 0;
}
