#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/ordered_set.hpp"

// OrderedSet を std::set と照合する

template <int B>
void check(mt19937_64 &rng) {
    for (long long range : {5LL, 100LL, 100000LL, 1000000000000LL}) {
        for (int rep = 0; rep < 3; rep++) {
            vector<long long> init(rng() % 300);
            for (auto &v : init) v = (long long)(rng() % (2 * range)) - range;
            OrderedSet<long long, B> st(init);
            set<long long> ref(init.begin(), init.end());
            const long long NG = LLONG_MIN;
            for (int it = 0; it < 100000; it++) {
                long long x = (long long)(rng() % (2 * range + 4)) - range - 2;
                int t = rng() % 12;
                if (t <= 2) {
                    assert(st.insert(x) == ref.insert(x).second);
                } else if (t <= 4) {
                    assert(st.erase(x) == (ref.erase(x) == 1));
                } else if (t == 5) {
                    assert(st.contains(x) == (ref.count(x) == 1) && st.count(x) == ref.count(x));
                } else if (t == 6) {
                    int k = (int)(rng() % (ref.size() + 2)) - 1;
                    assert(st.kth(k, NG) == ((0 <= k && k < (int)ref.size()) ? *next(ref.begin(), k) : NG));
                } else if (t == 7) {
                    assert(st.count_le(x) == (int)distance(ref.begin(), ref.upper_bound(x)));
                    assert(st.count_lt(x) == (int)distance(ref.begin(), ref.lower_bound(x)));
                    long long y = (long long)(rng() % (2 * range + 4)) - range - 2;
                    assert(st.count_range(x, y) == (x < y ? (int)distance(ref.lower_bound(x), ref.lower_bound(y)) : 0));
                } else if (t == 8) {
                    auto p = ref.upper_bound(x);
                    assert(st.max_le(x, NG) == (p == ref.begin() ? NG : *prev(p)));
                    p = ref.lower_bound(x);
                    assert(st.max_lt(x, NG) == (p == ref.begin() ? NG : *prev(p)));
                } else if (t == 9) {
                    auto p = ref.lower_bound(x);
                    assert(st.min_ge(x, NG) == (p == ref.end() ? NG : *p));
                    p = ref.upper_bound(x);
                    assert(st.min_gt(x, NG) == (p == ref.end() ? NG : *p));
                } else if (t == 10) {
                    assert(st.min(NG) == (ref.empty() ? NG : *ref.begin()));
                    assert(st.max(NG) == (ref.empty() ? NG : *ref.rbegin()));
                } else if (rng() % 50 == 0) {
                    assert(st.to_vector() == vector<long long>(ref.begin(), ref.end()));
                }
                assert(st.size() == (int)ref.size() && st.empty() == ref.empty());
                // 時々まとめて削除して，空に近い状態やノードの削除も試す
                if (it % 997 == 0) {
                    for (int j = 0; j < 50 && !ref.empty(); j++) {
                        long long y = *next(ref.begin(), rng() % ref.size());
                        assert(st.erase(y));
                        ref.erase(y);
                    }
                }
            }
        }
    }
}

int main() {
    mt19937_64 rng(5);
    check<14>(rng);  // long long のデフォルト
    check<4>(rng);   // ノードが小さいと分割・回転が頻繁に起きる

    // def を省略すると -1
    OrderedSet<int> s;
    assert(s.kth(0) == -1 && s.max_le(5) == -1 && s.min_ge(0) == -1 && s.min() == -1);

    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
