#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../io/fastio.hpp"
#include "../data_structure/fenwick_tree.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<long long> a(n);
    fin >> a;
    FenwickTree<long long> bit(a);
    while (q--) {
        int t, x, y;
        fin >> t >> x >> y;
        if (t == 0) bit.add(x, y);
        else fout << bit.sum(x, y) << '\n';
    }
    return 0;
}
