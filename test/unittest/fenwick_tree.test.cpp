#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/fenwick_tree.hpp"

// FenwickTree を愚直な配列と照合する

int main() {
    mt19937_64 rng(4);
    for (int n : {0, 1, 2, 3, 7, 8, 9, 100, 1000}) {
        vector<long long> a(n);
        for (auto &x : a) x = rng() % 5;
        FenwickTree<long long> bit(a);
        assert(bit.size() == n);
        for (int it = 0; it < 20000; it++) {
            int t = rng() % 5;
            if (n == 0) t = 4;
            if (t == 0) {
                int i = rng() % n;
                long long x = rng() % 4;
                bit.add(i, x), a[i] += x;
            } else if (t == 1) {
                int i = rng() % n;
                long long x = rng() % 4;
                bit.set(i, x), a[i] = x;
            } else if (t == 2) {
                int l = rng() % (n + 1), r = rng() % (n + 1);
                if (l > r) swap(l, r);
                long long s = 0;
                for (int i = l; i < r; i++) s += a[i];
                assert(bit.sum(l, r) == s && bit.sum(r) - bit.sum(l) == s);
                if (l < n) assert(bit.get(l) == a[l]);
            } else {
                long long total = accumulate(a.begin(), a.end(), 0LL);
                long long w = (long long)(rng() % (total + 3)) - 1;
                int lb = n, ub = n;
                long long s = 0;
                for (int i = n - 1; i >= 0; i--) {
                    s = 0;
                    for (int j = 0; j <= i; j++) s += a[j];
                    if (s >= w) lb = i;
                    if (s > w) ub = i;
                }
                assert(bit.lower_bound(w) == lb);
                assert(bit.upper_bound(w) == ub);
            }
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
