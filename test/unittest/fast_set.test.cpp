#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/fast_set.hpp"

// FastSet を std::set と照合する

int main() {
    mt19937_64 rng(3);
    for (int n : {0, 1, 2, 63, 64, 65, 100, 4095, 4096, 4097, 300000}) {
        vector<int> init(n);
        for (auto &x : init) x = rng() % 3 == 0;
        FastSet fs(n, [&](int i) { return init[i] == 1; });
        set<int> ref;
        for (int i = 0; i < n; i++) if (init[i]) ref.insert(i);
        int ops = n == 300000 ? 300000 : 20000;
        for (int it = 0; it < ops; it++) {
            int k = n == 0 ? 0 : (int)(rng() % (n + 4)) - 2;
            int t = rng() % 5;
            bool in = 0 <= k && k < n;
            if (t == 0 && in) fs.insert(k), ref.insert(k);
            else if (t == 1 && in) fs.erase(k), ref.erase(k);
            else if (t == 2 && in) assert(fs.contains(k) == (ref.count(k) == 1) && fs[k] == fs.contains(k));
            else if (t == 3) {
                auto p = ref.lower_bound(k);
                assert(fs.next(k) == (p == ref.end() ? -1 : *p));
            } else {
                auto p = ref.upper_bound(k);
                assert(fs.prev(k) == (p == ref.begin() ? -1 : *prev(p)));
            }
            assert(fs.empty() == ref.empty());
            assert(fs.min() == (ref.empty() ? -1 : *ref.begin()));
            assert(fs.max() == (ref.empty() ? -1 : *ref.rbegin()));
        }
        int l = n ? rng() % n : 0, r = n ? rng() % (n + 1) : 0;
        vector<int> got, exp;
        fs.enumerate(l, r, [&](int x) { got.push_back(x); });
        for (int x : ref) if (l <= x && x < r) exp.push_back(x);
        assert(got == exp);
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
