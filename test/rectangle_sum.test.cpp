#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include "../io/fastio.hpp"
#include "../data_structure/static_rectangle_sum.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> x(n), y(n);
    vector<long long> w(n);
    for (int i = 0; i < n; i++) fin >> x[i] >> y[i] >> w[i];
    StaticRectangleSum<int, long long> rs(x, y, w);
    while (q--) {
        int l, d, r, u;
        fin >> l >> d >> r >> u;
        fout << rs.sum_rect(l, d, r, u) << '\n';
    }
    return 0;
}
