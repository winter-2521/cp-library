#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../math/modint.hpp"
#include "../../data_structure/rectangle_add_point_get.hpp"
#include "../../data_structure/static_rectangle_add_rectangle_sum.hpp"
#include "../../data_structure/area_of_union_of_rectangles.hpp"

// RectangleAddPointGet / StaticRectangleAddRectangleSum / area_of_union_of_rectangles を
// 小さい格子の愚直と照合する (負の座標も)

using mint = ModInt998244353;

int main() {
    mt19937_64 rng(23);
    const int C = 8, OFF = 4;  // 座標は [-4, 4)
    for (int it = 0; it < 200; it++) {
        int n = rng() % 6;
        auto rect = [&](int &l, int &d, int &r, int &u) {
            l = (int)(rng() % C) - OFF, r = (int)(rng() % C) - OFF, d = (int)(rng() % C) - OFF, u = (int)(rng() % C) - OFF;
            if (l > r) swap(l, r);
            if (d > u) swap(d, u);
            r++, u++;
        };
        vector<int> L(n), D(n), R(n), U(n);
        vector<long long> W(n);
        vector<vector<long long>> g(C + 2, vector<long long>(C + 2, 0));
        StaticRectangleAddRectangleSum<int, mint> sr;
        for (int i = 0; i < n; i++) {
            rect(L[i], D[i], R[i], U[i]);
            W[i] = rng() % 10;
            for (int x = L[i]; x < R[i]; x++)
                for (int y = D[i]; y < U[i]; y++) g[x + OFF][y + OFF] += W[i];
            sr.add(L[i], D[i], R[i], U[i], W[i]);
        }
        // 静的: 加算の後に長方形和
        for (int qi = 0; qi < 30; qi++) {
            int l, d, r, u;
            rect(l, d, r, u);
            long long s = 0;
            for (int x = l; x < r; x++)
                for (int y = d; y < u; y++) s += g[x + OFF][y + OFF];
            assert(sr.sum(l, d, r, u) == mint(s));
        }
        // 和集合の面積
        {
            vector<long long> l(n), d(n), r(n), u(n);
            long long area = 0;
            vector<vector<int>> cov(C + 2, vector<int>(C + 2, 0));
            for (int i = 0; i < n; i++) {
                l[i] = L[i], d[i] = D[i], r[i] = R[i], u[i] = U[i];
                for (int x = L[i]; x < R[i]; x++)
                    for (int y = D[i]; y < U[i]; y++) cov[x + OFF][y + OFF] = 1;
            }
            for (auto &row : cov) for (int c : row) area += c;
            assert(area_of_union_of_rectangles(l, d, r, u) == area);
        }
        // 長方形加算・一点取得
        RectangleAddPointGet<int, long long> rp(L, D, R, U, W);
        RectangleAddPointGet<int, long long> rp_empty;
        vector<vector<long long>> g2(C + 2, vector<long long>(C + 2, 0));
        for (int step = 0; step < 100; step++) {
            if (rng() % 2) {
                int l, d, r, u;
                rect(l, d, r, u);
                long long w = rng() % 10;
                rp.add(l, d, r, u, w), rp_empty.add(l, d, r, u, w);
                for (int x = l; x < r; x++)
                    for (int y = d; y < u; y++) g[x + OFF][y + OFF] += w, g2[x + OFF][y + OFF] += w;
            }
            int x = (int)(rng() % (C + 1)) - OFF, y = (int)(rng() % (C + 1)) - OFF;
            assert(rp.get(x, y) == g[x + OFF][y + OFF]);
            assert(rp_empty.get(x, y) == g2[x + OFF][y + OFF]);
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
