#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/static_range_lis.hpp"

// StaticRangeLIS を愚直と照合する
// sticky_product・seaweed も愚直 (升ごとのひもの交換) と照合する

int brute_lis(const vector<int> &a, int l, int r) {
    vector<int> d;
    for (int i = l; i < r; i++) {
        auto it = lower_bound(d.begin(), d.end(), a[i]);
        if (it == d.end()) d.push_back(a[i]);
        else *it = a[i];
    }
    return d.size();
}

// 隣接互換 s_p を「まだ交差していなければ交差」で順に適用 (0-Hecke)
vector<int> apply_word(int n, const vector<int> &word) {
    vector<int> at(n);  // at[位置] = そこにいるひもの始点
    iota(at.begin(), at.end(), 0);
    for (int p : word) if (at[p] < at[p + 1]) swap(at[p], at[p + 1]);
    vector<int> res(n);
    for (int x = 0; x < n; x++) res[at[x]] = x;
    return res;
}

int main() {
    mt19937_64 rng(11);
    // sticky_product: ランダムな語 w1, w2 について product(w1, w2) == w1 w2
    for (int it = 0; it < 3000; it++) {
        int n = rng() % (it % 3 ? 9 : 60) + 1;
        vector<int> w1, w2;
        if (n > 1) {
            for (int t = rng() % (n * 4); t--;) w1.push_back(rng() % (n - 1));
            for (int t = rng() % (n * 4); t--;) w2.push_back(rng() % (n - 1));
        }
        vector<int> w12 = w1;
        w12.insert(w12.end(), w2.begin(), w2.end());
        assert(seaweed_internal::sticky_product(apply_word(n, w1), apply_word(n, w2)) == apply_word(n, w12));
    }
    // seaweed: 升ごとに処理する愚直
    for (int it = 0; it < 500; it++) {
        int m = rng() % 10 + 1;
        vector<int> q(m);
        iota(q.begin(), q.end(), 0);
        shuffle(q.begin(), q.end(), rng);
        vector<int> word;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++) if (q[j] != i) word.push_back(m - 1 - i + j);
        assert(seaweed_internal::seaweed(q) == apply_word(2 * m, word));
    }
    // 区間 LIS (重複のある数列も)
    for (int it = 0; it < 300; it++) {
        int n = rng() % 40 + 1;
        vector<int> a(n);
        for (auto &x : a) x = rng() % (it % 2 ? 5 : 100);
        StaticRangeLIS lis(a);
        for (int l = 0; l <= n; l++)
            for (int r = l; r <= n; r++) assert(lis.query(l, r) == brute_lis(a, l, r));
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
