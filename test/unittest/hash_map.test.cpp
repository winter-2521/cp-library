#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/hash_map.hpp"

// HashMap を unordered_map と照合する

template <class K>
void check(mt19937_64 &rng, long long range) {
    HashMap<K, long long> mp;
    unordered_map<K, long long> ref;
    for (int it = 0; it < 300000; it++) {
        K k = K((long long)(rng() % range) - range / 3);
        int t = rng() % 6;
        if (t == 0) {
            long long v = rng();
            mp[k] = v, ref[k] = v;
        } else if (t == 1) {
            mp[k] += 1, ref[k] += 1;
        } else if (t == 2) {
            assert(mp.erase(k) == (ref.erase(k) == 1));
        } else if (t == 3) {
            assert(mp.contains(k) == (ref.count(k) == 1));
            auto p = mp.find(k);
            assert((p != nullptr) == (ref.count(k) == 1));
            if (p) assert(*p == ref[k]);
        } else if (t == 4) {
            auto it2 = ref.find(k);
            assert(mp.get(k, -7) == (it2 == ref.end() ? -7 : it2->second));
        } else if (rng() % 20000 == 0) {
            mp.clear(), ref.clear();
        }
        assert(mp.size() == ref.size());
    }
    size_t c = 0;
    mp.for_each([&](K k, long long v) {
        c++;
        assert(ref.count(k) && ref[k] == v);
    });
    assert(c == ref.size());
}

int main() {
    mt19937_64 rng(2);
    check<int>(rng, 50);
    check<int>(rng, 100000);
    check<long long>(rng, 1000000000000000000LL);
    check<unsigned long long>(rng, 300);
    HashMap<int, int> r(1000);
    r.reserve(5000);
    for (int i = 0; i < 5000; i++) r[i * 1024] = i;
    for (int i = 0; i < 5000; i++) assert(r.get(i * 1024) == i);
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
