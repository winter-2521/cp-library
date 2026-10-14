#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../math/modint.hpp"
#include "../../data_structure/kd_tree.hpp"

// KDTree / DynamicKDTree を愚直と照合する (同じ座標の点・負の座標も)

using mint = ModInt998244353;
using AM = ActedAffineSum<mint>;

int main() {
    mt19937_64 rng(19);
    for (int it = 0; it < 60; it++) {
        int n = rng() % 40;
        int C = rng() % 2 ? 4 : 100;
        vector<int> x(n), y(n);
        vector<mint> w(n);
        vector<AM::S> s(n);
        for (int i = 0; i < n; i++) x[i] = (int)(rng() % C) - C / 2, y[i] = (int)(rng() % C) - C / 2, w[i] = rng() % 10, s[i] = AM::make(w[i]);
        KDTree<int, AM> kd(x, y, s);
        DynamicKDTree<int, AM> dk(x, y, s);
        vector<int> dx = x, dy = y;
        vector<mint> dw = w, sw = w;
        for (int step = 0; step < 400; step++) {
            int t = rng() % 5;
            int l = (int)(rng() % (C + 2)) - C / 2 - 1, r = (int)(rng() % (C + 2)) - C / 2 - 1;
            int d = (int)(rng() % (C + 2)) - C / 2 - 1, u = (int)(rng() % (C + 2)) - C / 2 - 1;
            if (t == 0) {
                int px = (int)(rng() % C) - C / 2, py = (int)(rng() % C) - C / 2;
                mint pw = rng() % 10;
                int id = dk.add_point(px, py, AM::make(pw));
                assert(id == (int)dx.size());
                dx.push_back(px), dy.push_back(py), dw.push_back(pw);
            } else if (t == 1) {
                Affine<mint> f(rng() % 5, rng() % 5);
                kd.apply(l, d, r, u, f), dk.apply(l, d, r, u, f);
                for (int i = 0; i < n; i++) if (l <= x[i] && x[i] < r && d <= y[i] && y[i] < u) sw[i] = f(sw[i]);
                for (int i = 0; i < (int)dx.size(); i++) if (l <= dx[i] && dx[i] < r && d <= dy[i] && dy[i] < u) dw[i] = f(dw[i]);
            } else if (t == 2) {
                mint s0 = 0, s1 = 0;
                int c0 = 0;
                for (int i = 0; i < n; i++) if (l <= x[i] && x[i] < r && d <= y[i] && y[i] < u) s0 += sw[i], c0++;
                for (int i = 0; i < (int)dx.size(); i++) if (l <= dx[i] && dx[i] < r && d <= dy[i] && dy[i] < u) s1 += dw[i];
                auto p = kd.prod(l, d, r, u);
                assert(p.sum == s0 && p.len == mint(c0));
                assert(dk.prod(l, d, r, u).sum == s1);
            } else if (t == 3) {
                if (n) {
                    int i = rng() % n;
                    assert(kd.get(i).sum == sw[i]);
                    mint v = rng() % 10;
                    kd.set(i, AM::make(v)), sw[i] = v;
                }
                if (!dx.empty()) {
                    int i = rng() % dx.size();
                    assert(dk.get(i).sum == dw[i]);
                    mint v = rng() % 10;
                    dk.set(i, AM::make(v)), dw[i] = v;
                }
            } else {
                auto vs = kd.values();
                for (int i = 0; i < n; i++) assert(vs[i].sum == sw[i]);
                mint all = 0;
                for (auto v : sw) all += v;
                assert(kd.all_prod().sum == all);
            }
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
