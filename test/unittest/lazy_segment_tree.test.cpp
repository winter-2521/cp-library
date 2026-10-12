#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../io/fastio.hpp"
#include "../../math/modint.hpp"
#include "../../data_structure/lazy_segment_tree.hpp"
#include "../../data_structure/dynamic_lazy_segment_tree.hpp"
#include "../../data_structure/persistent_lazy_segment_tree.hpp"

// LazySegmentTree / DynamicLazySegmentTree / PersistentLazySegmentTree と，
// algebra/acted_monoid.hpp の各作用付きモノイドを愚直と照合する

using mint = ModInt998244353;
using ll = long long;

// 作用付きモノイド AM について，愚直の配列 (long long) と照合する
// to_s: 値 -> S，from_s: S -> 比較用の値，gen_f: 乱数で作用を作る，act: 作用を値に適用
template <class AM, class ToS, class Val, class GenF, class Act>
void check_lazy(mt19937_64 &rng, ToS to_s, Val val, GenF gen_f, Act act) {
    for (int n : {1, 2, 3, 5, 8, 13, 64, 100}) {
        vector<ll> a(n);
        for (auto &x : a) x = rng() % 10;
        vector<typename AM::S> init(n);
        for (int i = 0; i < n; i++) init[i] = to_s(a[i]);
        LazySegmentTree<AM> seg(init);
        for (int it = 0; it < 1500; it++) {
            int t = rng() % 4;
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) swap(l, r);
            if (t == 0) {
                auto f = gen_f();
                seg.apply(l, r, f);
                for (int i = l; i < r; i++) a[i] = act(f, a[i]);
            } else if (t == 1) {
                int p = rng() % n;
                if (rng() % 2) {
                    a[p] = rng() % 10;
                    seg.set(p, to_s(a[p]));
                } else {
                    auto f = gen_f();
                    seg.apply(p, f);
                    a[p] = act(f, a[p]);
                }
                assert(val(seg.get(p)) == val(to_s(a[p])));
            } else if (t == 2) {
                auto s = AM::e();
                for (int i = l; i < r; i++) s = AM::op(s, to_s(a[i]));
                assert(val(seg.prod(l, r)) == val(s));
                auto all = AM::e();
                for (int i = 0; i < n; i++) all = AM::op(all, to_s(a[i]));
                assert(val(seg.all_prod()) == val(all));
            } else {
                int p = rng() % n;
                assert(val(seg.get(p)) == val(to_s(a[p])));
            }
        }
    }
}

int main() {
    mt19937_64 rng(33);
    // 区間 1 次関数・区間和
    {
        using AM = ActedAffineSum<mint>;
        check_lazy<AM>(
            rng, [](ll x) { return AM::make(mint(x)); }, [](const AM::S &s) { return pair<int, int>(s.sum.val(), s.len.val()); },
            [&]() { return Affine<mint>(rng() % 5 + 1, rng() % 5); }, [](const Affine<mint> &f, ll x) { return (ll)f(mint(x)).val(); });
    }
    // 区間加算・区間和
    {
        using AM = ActedAddSum<ll>;
        check_lazy<AM>(
            rng, [](ll x) { return AM::make(x); }, [](const AM::S &s) { return pair<ll, ll>(s.sum, s.len); },
            [&]() { return (ll)(rng() % 11) - 5; }, [](ll f, ll x) { return x + f; });
    }
    // 区間加算・区間最小値 / 最大値
    {
        using AM = ActedAddMin<ll>;
        check_lazy<AM>(
            rng, [](ll x) { return x; }, [](ll s) { return s; }, [&]() { return (ll)(rng() % 11) - 5; }, [](ll f, ll x) { return x + f; });
    }
    {
        using AM = ActedAddMax<ll>;
        check_lazy<AM>(
            rng, [](ll x) { return x; }, [](ll s) { return s; }, [&]() { return (ll)(rng() % 11) - 5; }, [](ll f, ll x) { return x + f; });
    }
    // 区間代入・区間和 / 最小値 / 最大値
    {
        using AM = ActedAssignSum<ll>;
        check_lazy<AM>(
            rng, [](ll x) { return AM::make(x); }, [](const AM::S &s) { return pair<ll, ll>(s.sum, s.len); },
            [&]() { return AM::F((ll)(rng() % 10)); }, [](const AM::F &f, ll x) { return f.has ? f.x : x; });
    }
    {
        using AM = ActedAssignMin<ll>;
        check_lazy<AM>(
            rng, [](ll x) { return x; }, [](ll s) { return s; }, [&]() { return AM::F((ll)(rng() % 10)); },
            [](const AM::F &f, ll x) { return f.has ? f.x : x; });
    }
    {
        using AM = ActedAssignMax<ll>;
        check_lazy<AM>(
            rng, [](ll x) { return x; }, [](ll s) { return s; }, [&]() { return AM::F((ll)(rng() % 10)); },
            [](const AM::F &f, ll x) { return f.has ? f.x : x; });
    }

    // LazySegmentTree の max_right / min_left: 区間加算・区間和で「和が lim 以下」
    {
        using AM = ActedAddSum<ll>;
        int n = 50;
        vector<ll> a(n, 0);
        vector<AM::S> init(n, AM::make(0));
        LazySegmentTree<AM> seg(init);
        for (int it = 0; it < 3000; it++) {
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) swap(l, r);
            if (rng() % 2) {
                ll x = rng() % 3;
                seg.apply(l, r, x);
                for (int i = l; i < r; i++) a[i] += x;
            } else {
                ll lim = rng() % 40;
                int rr = l;
                ll s = 0;
                while (rr < n && s + a[rr] <= lim) s += a[rr++];
                assert(seg.max_right(l, [&](const AM::S &x) { return x.sum <= lim; }) == rr);
                int ll2 = r;
                s = 0;
                while (ll2 > 0 && s + a[ll2 - 1] <= lim) s += a[--ll2];
                assert(seg.min_left(r, [&](const AM::S &x) { return x.sum <= lim; }) == ll2);
            }
        }
    }

    // DynamicLazySegmentTree: 初期値 x0 の大きな配列 (小さい n では愚直と照合)
    for (ll n : {1LL, 2LL, 5LL, 37LL, 64LL, 100LL}) {
        using AM = ActedAffineSum<mint>;
        mint x0 = rng() % 10;
        vector<mint> a(n, x0);
        DynamicLazySegmentTree<AM> seg(n, AM::make(x0));
        for (int it = 0; it < 2000; it++) {
            int t = rng() % 3;
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) swap(l, r);
            if (t == 0) {
                Affine<mint> f(rng() % 5 + 1, rng() % 5);
                seg.apply(l, r, f);
                for (int i = l; i < r; i++) a[i] = f(a[i]);
            } else if (t == 1) {
                int p = rng() % n;
                a[p] = rng() % 10;
                seg.set(p, AM::make(a[p]));
                assert(seg.get(p).sum == a[p]);
            } else {
                mint s = 0;
                for (int i = l; i < r; i++) s += a[i];
                assert(seg.prod(l, r).sum == s && seg.prod(l, r).len == mint(r - l));
            }
        }
    }
    // 大きな n でも小さな範囲の操作は正しい
    {
        using AM = ActedAddSum<ll>;
        ll n = 1LL << 40;
        DynamicLazySegmentTree<AM> seg(n, AM::make(1));
        seg.apply(5, 10, 3);
        assert(seg.prod(0, n).sum == n + 15);
        assert(seg.prod(7, 1LL << 35).sum == (1LL << 35) - 7 + 9);
        assert(seg.all_prod().sum == n + 15);
    }

    // PersistentLazySegmentTree: 全バージョンを愚直に持って照合
    for (int n : {1, 2, 3, 7, 16, 33}) {
        using AM = ActedAffineSum<mint>;
        PersistentLazySegmentTree<AM> seg(n);
        vector<vector<mint>> ver;
        vector<int> roots;
        vector<mint> a(n);
        for (auto &x : a) x = rng() % 10;
        vector<AM::S> init(n);
        for (int i = 0; i < n; i++) init[i] = AM::make(a[i]);
        ver.push_back(a), roots.push_back(seg.build(init));
        ver.push_back(vector<mint>(n, 2)), roots.push_back(seg.build(AM::make(2)));
        for (int it = 0; it < 1500; it++) {
            int k = rng() % ver.size(), t = rng() % 4;
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) swap(l, r);
            if (t == 0) {
                Affine<mint> f(rng() % 5 + 1, rng() % 5);
                auto b = ver[k];
                for (int i = l; i < r; i++) b[i] = f(b[i]);
                ver.push_back(b), roots.push_back(seg.apply(roots[k], l, r, f));
            } else if (t == 1) {
                int s = rng() % ver.size();
                auto b = ver[k];
                for (int i = l; i < r; i++) b[i] = ver[s][i];
                ver.push_back(b), roots.push_back(seg.copy_range(roots[k], roots[s], l, r));
            } else if (t == 2) {
                int p = rng() % n;
                mint x = rng() % 10;
                auto b = ver[k];
                b[p] = x;
                ver.push_back(b), roots.push_back(seg.set(roots[k], p, AM::make(x)));
            } else {
                mint s = 0;
                for (int i = l; i < r; i++) s += ver[k][i];
                assert(seg.prod(roots[k], l, r).sum == s);
                int p = rng() % n;
                assert(seg.get(roots[k], p).sum == ver[k][p]);
            }
        }
        // 全バージョンが壊れていない
        for (size_t k = 0; k < ver.size(); k++) {
            auto v = seg.to_vector(roots[k]);
            for (int i = 0; i < n; i++) assert(v[i].sum == ver[k][i]);
            mint s = 0;
            for (auto x : ver[k]) s += x;
            assert(seg.all_prod(roots[k]).sum == s);
        }
        assert(seg.node_count() > 0);
    }

    long long a_, b_;
    fin >> a_ >> b_;
    fout << a_ + b_ << '\n';
    return 0;
}
