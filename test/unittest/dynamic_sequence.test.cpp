#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../math/modint.hpp"
#include "../../data_structure/dynamic_sequence.hpp"

// DynamicSequence を愚直と照合する
// 非可換: 値は 1 次関数，作用なし (ActedNone) で反転と積を確認
// 可換: ActedAffineSum で挿入・削除・反転・区間作用・区間和を確認

using mint = ModInt998244353;
using F = Affine<mint>;
using AM = ActedAffineSum<mint>;

int main() {
    mt19937_64 rng(9);
    for (int it = 0; it < 30; it++) {
        int n = rng() % 20;
        vector<F> a(n);
        for (auto &f : a) f = F(rng() % 5 + 1, rng() % 5);
        DynamicSequence<ActedNone<MonoidAffine<mint>>, false> seq(a);
        vector<mint> b(n);
        vector<AM::S> bs(n);
        for (int i = 0; i < n; i++) b[i] = rng() % 10, bs[i] = AM::make(b[i]);
        DynamicSequence<AM> sb(bs);
        for (int step = 0; step < 2000; step++) {
            int t = rng() % 7;
            int m = a.size();
            if (t == 0 || m == 0) {
                int i = rng() % (m + 1);
                F f(rng() % 5 + 1, rng() % 5);
                a.insert(a.begin() + i, f), seq.insert(i, f);
                mint x = rng() % 10;
                b.insert(b.begin() + i, x), sb.insert(i, AM::make(x));
            } else if (t == 1) {
                int i = rng() % m;
                a.erase(a.begin() + i), seq.erase(i);
                b.erase(b.begin() + i), sb.erase(i);
            } else {
                int l = rng() % (m + 1), r = rng() % (m + 1);
                if (l > r) swap(l, r);
                if (t == 2) {
                    reverse(a.begin() + l, a.begin() + r), seq.reverse(l, r);
                    reverse(b.begin() + l, b.begin() + r), sb.reverse(l, r);
                } else if (t == 3) {
                    F f(rng() % 5, rng() % 5);
                    for (int i = l; i < r; i++) b[i] = f(b[i]);
                    sb.apply(l, r, f);
                } else if (t == 4) {
                    F res;
                    for (int i = l; i < r; i++) res = res.then(a[i]);
                    assert(seq.prod(l, r) == res);
                    mint s = 0;
                    for (int i = l; i < r; i++) s += b[i];
                    assert(sb.prod(l, r).sum == s && sb.prod(l, r).len == mint(r - l));
                } else if (t == 5 && m > 0) {
                    int i = rng() % m;
                    assert(seq.get(i) == a[i] && sb.get(i).sum == b[i]);
                    F f(rng() % 5 + 1, rng() % 5);
                    a[i] = f, seq.set(i, f);
                } else {
                    if (rng() % 2) {
                        F f(rng() % 5 + 1, rng() % 5);
                        a.push_back(f), seq.push_back(f);
                        b.push_back(0), sb.push_back(AM::make(0));
                    } else {
                        F f(rng() % 5 + 1, rng() % 5);
                        a.insert(a.begin(), f), seq.push_front(f);
                        b.insert(b.begin(), 0), sb.push_front(AM::make(0));
                    }
                }
            }
            assert(seq.size() == (int)a.size() && sb.size() == (int)b.size());
        }
        assert(seq.to_vector() == a);
        F all;
        for (auto &f : a) all = all.then(f);
        assert(seq.all_prod() == all);
    }
    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
