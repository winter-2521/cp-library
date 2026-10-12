#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/interval_heap.hpp"

// IntervalHeap を multiset と照合する

template <class C>
void check(mt19937_64 &rng, int range) {
    vector<int> init(rng() % 50);
    for (auto &x : init) x = rng() % range;
    IntervalHeap<int, C> hp(init);
    multiset<int, C> ref(init.begin(), init.end());
    for (int it = 0; it < 200000; it++) {
        int t = rng() % 3;
        if (ref.empty() || t == 0) {
            int x = rng() % range;
            hp.push(x), ref.insert(x);
        } else if (t == 1) {
            assert(hp.min() == *ref.begin());
            assert(hp.pop_min() == *ref.begin());
            ref.erase(ref.begin());
        } else {
            assert(hp.max() == *ref.rbegin());
            assert(hp.pop_max() == *ref.rbegin());
            ref.erase(prev(ref.end()));
        }
        assert(hp.size() == (int)ref.size() && hp.empty() == ref.empty());
        if (!ref.empty()) assert(hp.min() == *ref.begin() && hp.max() == *ref.rbegin());
    }
}

int main() {
    mt19937_64 rng(6);
    check<less<int>>(rng, 5);
    check<less<int>>(rng, 1000000000);
    check<greater<int>>(rng, 7);
    check<greater<int>>(rng, 1000000000);
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
