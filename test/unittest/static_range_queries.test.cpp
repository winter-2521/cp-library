#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/static_range_frequency.hpp"
#include "../../data_structure/static_range_count_distinct.hpp"
#include "../../data_structure/static_range_mode.hpp"
#include "../../data_structure/static_range_inversions.hpp"
#include "../../data_structure/dynamic_range_frequency.hpp"

// 静的な区間クエリ (頻度・種類数・最頻値・転倒数) と DynamicRangeFrequency を愚直と照合する

int main() {
    mt19937_64 rng(13);
    for (int it = 0; it < 200; it++) {
        int n = rng() % 60 + (it < 5 ? 0 : 1);
        int sigma = rng() % 3 == 0 ? 3 : 1000000000;
        vector<long long> a(n);
        for (auto &x : a) x = (long long)(rng() % sigma) - sigma / 2;
        StaticRangeFrequency<long long> fr(a);
        StaticRangeCountDistinct<long long> cd(a);
        StaticRangeMode<long long> md(a);
        StaticRangeInversions<long long> inv(a), inv3(a, 3);
        for (int l = 0; l <= n; l++) {
            for (int r = l; r <= n; r++) {
                map<long long, int> cnt;
                long long iv = 0;
                for (int i = l; i < r; i++) {
                    cnt[a[i]]++;
                    for (int j = i + 1; j < r; j++) iv += a[i] > a[j];
                }
                long long x = rng() % 2 && l < r ? a[l + rng() % (r - l)] : (long long)(rng() % sigma) - sigma / 2;
                assert(fr.count(l, r, x) == (cnt.count(x) ? cnt[x] : 0));
                assert(cd.count(l, r) == (int)cnt.size());
                assert(inv.query(l, r) == iv && inv3.query(l, r) == iv);
                if (l < r) {
                    int mx = 0;
                    for (auto &[k, v] : cnt) mx = max(mx, v);
                    auto [v, c] = md.query(l, r);
                    assert(c == mx && cnt[v] == mx);
                }
            }
        }
        // DynamicRangeFrequency
        vector<int> b(n);
        for (auto &x : b) x = rng() % 4;
        DynamicRangeFrequency<int> df(b);
        for (int step = 0; step < 300 && n > 0; step++) {
            if (rng() % 2) {
                int i = rng() % n, v = rng() % 4;
                b[i] = v, df.set(i, v);
            }
            int l = rng() % (n + 1), r = rng() % (n + 1), x = rng() % 5;
            if (l > r) swap(l, r);
            assert(df.count(l, r, x) == count(b.begin() + l, b.begin() + r, x));
            int i = rng() % n;
            assert(df.get(i) == b[i]);
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
