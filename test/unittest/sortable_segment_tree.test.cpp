#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../math/modint.hpp"
#include "../../data_structure/sortable_segment_tree.hpp"

// SortableSegmentTree を愚直と照合する (キーは相異なる)

using mint = ModInt998244353;
using F = Affine<mint>;

int main() {
    mt19937_64 rng(71);
    for (int n : {1, 2, 3, 5, 8, 33, 100}) {
        for (int lg_key : {7, 30}) {
            // 使われていないキーを配る
            set<long long> used;
            auto fresh_key = [&]() {
                while (true) {
                    long long k = rng() % (1LL << lg_key);
                    if (!used.count(k)) {
                        used.insert(k);
                        return k;
                    }
                }
            };
            vector<long long> key(n);
            vector<F> val(n);
            for (int i = 0; i < n; i++) key[i] = fresh_key(), val[i] = F(rng() % 3 + 1, rng() % 3);
            SortableSegmentTree<MonoidAffine<mint>> seg(key, val);
            for (int it = 0; it < 2000; it++) {
                int t = rng() % 5;
                int l = rng() % (n + 1), r = rng() % (n + 1);
                if (l > r) swap(l, r);
                if (t == 0) {
                    int i = rng() % n;
                    used.erase(key[i]);
                    key[i] = fresh_key(), val[i] = F(rng() % 3 + 1, rng() % 3);
                    seg.set(i, key[i], val[i]);
                } else if (t == 1) {
                    F res;
                    for (int i = l; i < r; i++) res = res.then(val[i]);
                    assert(seg.prod(l, r) == res);
                } else if (t == 2 || t == 3) {
                    vector<pair<long long, F>> v;
                    for (int i = l; i < r; i++) v.push_back({key[i], val[i]});
                    sort(v.begin(), v.end(), [](auto &x, auto &y) { return x.first < y.first; });
                    if (t == 3) reverse(v.begin(), v.end());
                    for (int i = l; i < r; i++) key[i] = v[i - l].first, val[i] = v[i - l].second;
                    if (t == 2) seg.sort_asc(l, r);
                    else seg.sort_desc(l, r);
                } else {
                    int i = rng() % n;
                    auto [k, f] = seg.get(i);
                    assert(k == key[i] && f == val[i]);
                    F all;
                    for (auto &f2 : val) all = all.then(f2);
                    assert(seg.all_prod() == all);
                }
            }
        }
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
