#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/wavelet_matrix.hpp"

// WaveletMatrix を愚直と照合する

int main() {
    mt19937_64 rng(61);
    const long long NG = LLONG_MIN;
    for (int n : {1, 2, 3, 63, 64, 65, 200}) {
        for (long long range : {1LL, 5LL, 1000000000000LL}) {
            vector<long long> a(n);
            for (auto &x : a) x = (long long)(rng() % (2 * range + 1)) - range;
            WaveletMatrix<long long> wm(a);
            for (int i = 0; i < n; i++) assert(wm.access(i) == a[i] && wm[i] == a[i]);
            for (int it = 0; it < 2000; it++) {
                int l = rng() % n, r = rng() % n;
                if (l > r) swap(l, r);
                r++;
                vector<long long> b(a.begin() + l, a.begin() + r);
                sort(b.begin(), b.end());
                int k = rng() % (r - l);
                assert(wm.kth_smallest(l, r, k) == b[k]);
                assert(wm.kth_largest(l, r, k) == b[r - l - 1 - k]);
                long long x = (long long)(rng() % (2 * range + 3)) - range - 1;
                long long y = (long long)(rng() % (2 * range + 3)) - range - 1;
                int lt = lower_bound(b.begin(), b.end(), x) - b.begin();
                int le = upper_bound(b.begin(), b.end(), x) - b.begin();
                assert(wm.count_lt(l, r, x) == lt && wm.count_le(l, r, x) == le && wm.count(l, r, x) == le - lt);
                int cr = x < y ? int(lower_bound(b.begin(), b.end(), y) - b.begin()) - lt : 0;
                assert(wm.count_range(l, r, x, y) == cr);
                assert(wm.max_lt(l, r, x, NG) == (lt == 0 ? NG : b[lt - 1]));
                assert(wm.max_le(l, r, x, NG) == (le == 0 ? NG : b[le - 1]));
                assert(wm.min_ge(l, r, x, NG) == (lt == r - l ? NG : b[lt]));
                assert(wm.min_gt(l, r, x, NG) == (le == r - l ? NG : b[le]));
            }
            assert(wm.count_lt(3 % n, 3 % n, 0) == 0);
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
