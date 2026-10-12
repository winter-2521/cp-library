#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../math/modint.hpp"
#include "../../data_structure/segment_tree.hpp"
#include "../../data_structure/dual_segment_tree.hpp"
#include "../../data_structure/dynamic_segment_tree.hpp"

// SegmentTree / DualSegmentTree / DynamicSegmentTree を愚直と照合する (非可換な 1 次関数の合成で確認)

using mint = ModInt998244353;
using F = Affine<mint>;
using MA = MonoidAffine<mint>;

F rand_f(mt19937_64 &rng) { return F(rng() % 5 + 1, rng() % 5); }
F brute(const vector<F> &a, int l, int r) {
    F res;
    for (int i = l; i < r; i++) res = res.then(a[i]);
    return res;
}

int main() {
    mt19937_64 rng(21);
    // SegmentTree
    for (int n : {0, 1, 2, 3, 5, 8, 13, 64, 100}) {
        vector<F> a(n);
        for (auto &x : a) x = rand_f(rng);
        SegmentTree<MA> seg(a);
        SegmentTree<MonoidSum<long long>> sum_seg(n);
        vector<long long> b(n, 0);
        for (int it = 0; it < 2000; it++) {
            int t = rng() % 4;
            if (t == 0 && n > 0) {
                int p = rng() % n;
                a[p] = rand_f(rng);
                seg.set(p, a[p]);
                long long v = rng() % 10;
                b[p] = v, sum_seg.set(p, v);
            } else if (t == 1 && n > 0) {
                int p = rng() % n;
                F f = rand_f(rng);
                a[p] = a[p].then(f);
                seg.multiply(p, f);
                assert(seg.get(p) == a[p] && seg[p] == a[p]);
            } else if (t == 2) {
                int l = rng() % (n + 1), r = rng() % (n + 1);
                if (l > r) swap(l, r);
                assert(seg.prod(l, r) == brute(a, l, r));
                assert(seg.all_prod() == brute(a, 0, n));
            } else {
                // max_right / min_left: 和が lim 以下となる最大 / 最小
                long long lim = rng() % 30;
                int l = rng() % (n + 1);
                int r = l;
                long long s = 0;
                while (r < n && s + b[r] <= lim) s += b[r++];
                assert(sum_seg.max_right(l, [&](long long x) { return x <= lim; }) == r);
                int r2 = rng() % (n + 1), l2 = r2;
                s = 0;
                while (l2 > 0 && s + b[l2 - 1] <= lim) s += b[--l2];
                assert(sum_seg.min_left(r2, [&](long long x) { return x <= lim; }) == l2);
            }
        }
    }
    // DualSegmentTree: 各位置に作用した関数を時系列順に合成したもの
    for (int n : {1, 2, 3, 5, 8, 13, 64, 100}) {
        vector<F> a(n);
        DualSegmentTree<MA> seg(n);
        for (int it = 0; it < 2000; it++) {
            int t = rng() % 3;
            if (t == 0) {
                int l = rng() % (n + 1), r = rng() % (n + 1);
                if (l > r) swap(l, r);
                F f = rand_f(rng);
                seg.apply(l, r, f);
                for (int i = l; i < r; i++) a[i] = a[i].then(f);
            } else if (t == 1) {
                int p = rng() % n;
                F f = rand_f(rng);
                if (rng() % 2) seg.apply(p, f), a[p] = a[p].then(f);
                else seg.set(p, f), a[p] = f;
            } else {
                int p = rng() % n;
                assert(seg.get(p) == a[p] && seg[p] == a[p]);
            }
        }
    }
    // DynamicSegmentTree: 添字が大きいとき
    for (long long n : {1LL, 7LL, 1000LL, 1000000000000LL}) {
        map<long long, F> a;
        DynamicSegmentTree<MA> seg(n);
        vector<long long> pos;
        for (int it = 0; it < 3000; it++) {
            int t = rng() % 3;
            if (t == 0) {
                long long p = (pos.empty() || rng() % 2) ? (long long)(rng() % n) : pos[rng() % pos.size()];
                F f = rand_f(rng);
                seg.set(p, f), a[p] = f, pos.push_back(p);
            } else if (t == 1) {
                long long l = rng() % (n + 1), r = rng() % (n + 1);
                if (l > r) swap(l, r);
                F res;
                for (auto it2 = a.lower_bound(l); it2 != a.end() && it2->first < r; ++it2) res = res.then(it2->second);
                assert(seg.prod(l, r) == res);
            } else {
                long long p = (pos.empty() || rng() % 2) ? (long long)(rng() % n) : pos[rng() % pos.size()];
                F exp = a.count(p) ? a[p] : F();
                assert(seg.get(p) == exp);
                F all;
                for (auto &[k, v] : a) all = all.then(v);
                assert(seg.all_prod() == all);
            }
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
