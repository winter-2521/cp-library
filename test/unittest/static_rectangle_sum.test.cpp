#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/static_rectangle_sum.hpp"

// StaticRectangleSum / DynamicRectangleSum を愚直と照合する (負の座標・重複する点も)

int main() {
    mt19937_64 rng(17);
    for (int it = 0; it < 100; it++) {
        int n = rng() % 50;
        int C = rng() % 2 ? 5 : 1000;
        vector<long long> x(n), y(n), w(n);
        for (int i = 0; i < n; i++) x[i] = (long long)(rng() % C) - C / 2, y[i] = (long long)(rng() % C) - C / 2, w[i] = rng() % 100;
        StaticRectangleSum<long long, long long> rs(x, y, w);
        DynamicRectangleSum<long long, long long> ds(x, y, w);
        DynamicRectangleSum<long long, long long> empty_start;
        vector<long long> ex, ey, ew;
        for (int step = 0; step < 300; step++) {
            if (rng() % 3 == 0) {
                long long px = (long long)(rng() % C) - C / 2, py = (long long)(rng() % C) - C / 2, pw = rng() % 100;
                ds.add(px, py, pw), empty_start.add(px, py, pw);
                x.push_back(px), y.push_back(py), w.push_back(pw);
                ex.push_back(px), ey.push_back(py), ew.push_back(pw);
            }
            long long l = (long long)(rng() % (C + 4)) - C / 2 - 2, r = (long long)(rng() % (C + 4)) - C / 2 - 2;
            long long d = (long long)(rng() % (C + 4)) - C / 2 - 2, u = (long long)(rng() % (C + 4)) - C / 2 - 2;
            long long s0 = 0, s1 = 0, s2 = 0;
            for (int i = 0; i < (int)x.size(); i++) {
                bool in = l <= x[i] && x[i] < r && d <= y[i] && y[i] < u;
                if (in) s1 += w[i];
                if (in && i < n) s0 += w[i];
            }
            for (int i = 0; i < (int)ex.size(); i++) if (l <= ex[i] && ex[i] < r && d <= ey[i] && ey[i] < u) s2 += ew[i];
            assert(rs.sum_rect(l, d, r, u) == s0 && rs(l, d, r, u) == s0);
            assert(ds.sum_rect(l, d, r, u) == s1);
            assert(empty_start(l, d, r, u) == s2);
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
