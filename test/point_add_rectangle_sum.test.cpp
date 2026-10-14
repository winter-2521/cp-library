#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
#include "../io/fastio.hpp"
#include "../data_structure/static_rectangle_sum.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> x(n), y(n);
    vector<long long> w(n);
    for (int i = 0; i < n; i++) fin >> x[i] >> y[i] >> w[i];
    DynamicRectangleSum<int, long long> rs(x, y, w);
    while (q--) {
        int t;
        fin >> t;
        if (t == 0) {
            int a, b;
            long long c;
            fin >> a >> b >> c;
            rs.add(a, b, c);
        } else {
            int l, d, r, u;
            fin >> l >> d >> r >> u;
            fout << rs.sum_rect(l, d, r, u) << '\n';
        }
    }
    return 0;
}
