#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_add_point_get"
#include "../io/fastio.hpp"
#include "../data_structure/rectangle_add_point_get.hpp"

int main() {
    int n, q;
    fin >> n >> q;
    vector<int> l(n), d(n), r(n), u(n);
    vector<long long> w(n);
    for (int i = 0; i < n; i++) fin >> l[i] >> d[i] >> r[i] >> u[i] >> w[i];
    RectangleAddPointGet<int, long long> rp(l, d, r, u, w);
    while (q--) {
        int t;
        fin >> t;
        if (t == 0) {
            int a, b, c, e;
            long long x;
            fin >> a >> b >> c >> e >> x;
            rp.add(a, b, c, e, x);
        } else {
            int x, y;
            fin >> x >> y;
            fout << rp.get(x, y) << '\n';
        }
    }
    return 0;
}
