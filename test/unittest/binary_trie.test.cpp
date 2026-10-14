#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../data_structure/binary_trie.hpp"

// BinaryTrie を愚直 (multiset) と照合する

int main() {
    mt19937_64 rng(5);
    for (int it = 0; it < 10; it++) {
        BinaryTrie<6> trie;
        BinaryTrie<64, unsigned long long> big;
        multiset<unsigned> ref;
        for (int step = 0; step < 5000; step++) {
            int t = rng() % 6;
            unsigned x = rng() % 64;
            if (t == 0) trie.insert(x), big.insert(x), ref.insert(x);
            else if (t == 1) {
                bool ok = trie.erase_one(x);
                big.erase_one(x);
                assert(ok == (ref.count(x) > 0));
                if (ok) ref.erase(ref.find(x));
            } else if (t == 2) {
                bool ok = trie.insert_unique(x);
                big.insert_unique(x);
                assert(ok == (ref.count(x) == 0));
                if (ok) ref.insert(x);
            }
            assert(trie.size() == (int)ref.size() && big.size() == (int)ref.size());
            assert(trie.count(x) == (int)ref.count(x));
            if (ref.empty()) continue;
            unsigned mn = ~0u, mx = 0;
            vector<unsigned> v;
            for (unsigned y : ref) mn = min(mn, x ^ y), mx = max(mx, x ^ y), v.push_back(x ^ y);
            sort(v.begin(), v.end());
            assert(trie.xor_min(x) == mn && trie.xor_max(x) == mx);
            assert(big.xor_min(x) == mn && big.xor_max(x) == mx && big.xor_max(x ^ (1ull << 63)) == (mx | (1ull << 63)));
            int k = rng() % v.size();
            assert(trie.kth(k, x) == v[k]);
            unsigned a = rng() % 70;
            assert(trie.count_less(a, x) == lower_bound(v.begin(), v.end(), a) - v.begin());
            assert(trie.min() == *ref.begin() && trie.max() == *ref.rbegin());
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
