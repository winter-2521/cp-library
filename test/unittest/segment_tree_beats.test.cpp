#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/segment_tree_beats.hpp"

// SegmentTreeBeats を愚直と照合する

int main() {
    mt19937_64 rng(51);
    for (int n : {1, 2, 3, 5, 8, 13, 64, 100}) {
        for (long long range : {3LL, 1000000000000LL}) {
            vector<long long> a(n);
            for (auto &x : a) x = (long long)(rng() % (2 * range + 1)) - range;
            SegmentTreeBeats<long long> seg(a);
            for (int it = 0; it < 3000; it++) {
                int t = rng() % 7;
                int l = rng() % (n + 1), r = rng() % (n + 1);
                if (l > r) swap(l, r);
                long long x = (long long)(rng() % (2 * range + 1)) - range;
                if (t == 0) {
                    seg.chmin(l, r, x);
                    for (int i = l; i < r; i++) a[i] = min(a[i], x);
                } else if (t == 1) {
                    seg.chmax(l, r, x);
                    for (int i = l; i < r; i++) a[i] = max(a[i], x);
                } else if (t == 2) {
                    x = (long long)(rng() % 7) - 3;
                    seg.add(l, r, x);
                    for (int i = l; i < r; i++) a[i] += x;
                } else if (t == 3) {
                    seg.assign(l, r, x);
                    for (int i = l; i < r; i++) a[i] = x;
                } else {
                    long long s = 0, mn = LLONG_MAX, mx = LLONG_MIN;
                    for (int i = l; i < r; i++) s += a[i], mn = min(mn, a[i]), mx = max(mx, a[i]);
                    assert(seg.sum(l, r) == s && seg.min(l, r) == mn && seg.max(l, r) == mx);
                    int p = rng() % n;
                    assert(seg.get(p) == a[p]);
                }
            }
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
