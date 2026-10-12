#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../math/modint.hpp"
#include "../../data_structure/range_assign_segment_tree.hpp"

// RangeAssignSegmentTree を愚直と照合する (非可換な 1 次関数の合成)

using mint = ModInt998244353;
using F = Affine<mint>;

int main() {
    mt19937_64 rng(41);
    auto rand_f = [&]() { return F(rng() % 3 + 1, rng() % 3); };
    for (int n : {1, 2, 3, 5, 8, 64, 100}) {
        for (int mode = 0; mode < 2; mode++) {
            vector<F> a(n);
            for (auto &x : a) x = rand_f();
            F x0 = rand_f();
            if (mode == 1) a.assign(n, x0);
            RangeAssignSegmentTree<MonoidAffine<mint>> seg = mode == 0 ? RangeAssignSegmentTree<MonoidAffine<mint>>(a) : RangeAssignSegmentTree<MonoidAffine<mint>>(n, x0);
            for (int it = 0; it < 3000; it++) {
                int t = rng() % 4;
                int l = rng() % (n + 1), r = rng() % (n + 1);
                if (l > r) swap(l, r);
                if (t == 0) {
                    F f = rand_f();
                    seg.assign(l, r, f);
                    for (int i = l; i < r; i++) a[i] = f;
                } else if (t == 1) {
                    int p = rng() % n;
                    a[p] = rand_f();
                    seg.set(p, a[p]);
                } else if (t == 2) {
                    F res;
                    for (int i = l; i < r; i++) res = res.then(a[i]);
                    assert(seg.prod(l, r) == res);
                    int p = rng() % n;
                    assert(seg.get(p) == a[p] && seg[p] == a[p]);
                } else {
                    F all;
                    for (auto &f : a) all = all.then(f);
                    assert(seg.all_prod() == all);
                    // ランは隣り合わず，全体を覆う
                    int last = 0;
                    seg.enumerate_runs([&](int s, int e, const F &f) {
                        assert(s == last && s < e);
                        for (int i = s; i < e; i++) assert(a[i] == f);
                        last = e;
                    });
                    assert(last == n);
                }
            }
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
