#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/li_chao_tree.hpp"

// DynamicLiChaoTree / LiChaoTree を愚直と照合する (最小値・最大値，直線・線分)

int main() {
    mt19937_64 rng(7);
    const long long INF = numeric_limits<long long>::max(), NINF = numeric_limits<long long>::lowest();
    for (int it = 0; it < 30; it++) {
        long long lo = -(long long)(rng() % 30), hi = lo + 1 + rng() % 60;
        vector<long long> xs;
        for (long long x = lo; x < hi; x++) if (rng() % 3) xs.push_back(x);
        if (xs.empty()) xs.push_back(lo);
        DynamicLiChaoTree<long long> dmn(lo, hi);
        DynamicLiChaoTree<long long, true> dmx(lo, hi);
        LiChaoTree<long long> smn(xs);
        LiChaoTree<long long, true> smx(xs);
        vector<array<long long, 4>> segs;  // l, r, a, b
        for (int step = 0; step < 300; step++) {
            long long a = (long long)(rng() % 21) - 10, b = (long long)(rng() % 201) - 100;
            if (rng() % 2) {
                dmn.add_line(a, b), dmx.add_line(a, b), smn.add_line(a, b), smx.add_line(a, b);
                segs.push_back({lo - 100, hi + 100, a, b});
            } else {
                long long l = lo - 5 + (long long)(rng() % (hi - lo + 10)), r = lo - 5 + (long long)(rng() % (hi - lo + 10));
                if (l > r) swap(l, r);
                dmn.add_segment(l, r, a, b), dmx.add_segment(l, r, a, b), smn.add_segment(l, r, a, b), smx.add_segment(l, r, a, b);
                segs.push_back({l, r, a, b});
            }
            for (long long x = lo; x < hi; x++) {
                long long mn = INF, mx = NINF;
                for (auto &[l, r, a2, b2] : segs) if (l <= x && x < r) mn = min(mn, a2 * x + b2), mx = max(mx, a2 * x + b2);
                assert(dmn.get(x) == mn && dmx.get(x) == mx);
                if (binary_search(xs.begin(), xs.end(), x)) assert(smn.get(x) == mn && smx.get(x) == mx);
            }
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
