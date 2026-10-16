#pragma once
#include "../template.hpp"
#include "../algebra/acted_monoid.hpp"

// https://github.com/winter-2521/cp-library

// 遅延セグメント木 (区間作用・区間積)
// AM は作用付きモノイド (algebra/acted_monoid.hpp 参照．規約は ACL の lazy_segtree と同じ)
template <class AM>
struct LazySegmentTree {
    using S = typename AM::S;
    using F = typename AM::F;
    int n, sz, lg;
    vector<S> d;
    vector<F> lz;

    LazySegmentTree(int n = 0) : LazySegmentTree(vector<S>(n, AM::e())) {}

    LazySegmentTree(const vector<S> &a) : n(a.size()) {
        lg = 0;
        while ((1 << lg) < n) lg++;
        sz = 1 << lg;
        d.assign(2 * sz, AM::e());
        lz.assign(sz, AM::id());
        copy(a.begin(), a.end(), d.begin() + sz);
        for (int i = sz - 1; i >= 1; i--) update(i);
    }

    int size() const { return n; }

    // a[p] = x
    void set(int p, const S &x) {
        p += sz;
        for (int i = lg; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= lg; i++) update(p >> i);
    }

    S get(int p) {
        p += sz;
        for (int i = lg; i >= 1; i--) push(p >> i);
        return d[p];
    }

    // op(a[l], ..., a[r-1])．l == r なら e()
    S prod(int l, int r) {
        if (l == r) return AM::e();
        l += sz, r += sz;
        for (int i = lg; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        S sml = AM::e(), smr = AM::e();
        while (l < r) {
            if (l & 1) sml = AM::op(sml, d[l++]);
            if (r & 1) smr = AM::op(d[--r], smr);
            l >>= 1, r >>= 1;
        }
        return AM::op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    // a[p] = f(a[p])
    void apply(int p, const F &f) {
        p += sz;
        for (int i = lg; i >= 1; i--) push(p >> i);
        d[p] = AM::mapping(f, d[p]);
        for (int i = 1; i <= lg; i++) update(p >> i);
    }

    // i in [l, r) について a[i] = f(a[i])
    void apply(int l, int r, const F &f) {
        if (l == r) return;
        l += sz, r += sz;
        for (int i = lg; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1, r >>= 1;
            }
            l = l2, r = r2;
        }
        for (int i = 1; i <= lg; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    // g(op(a[l], ..., a[r-1])) が true となる最大の r (g(e()) は true であること)
    template <class G>
    int max_right(int l, G g) {
        if (l == n) return n;
        l += sz;
        for (int i = lg; i >= 1; i--) push(l >> i);
        S sm = AM::e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(AM::op(sm, d[l]))) {
                while (l < sz) {
                    push(l);
                    l = 2 * l;
                    if (g(AM::op(sm, d[l]))) sm = AM::op(sm, d[l++]);
                }
                return l - sz;
            }
            sm = AM::op(sm, d[l++]);
        } while ((l & -l) != l);
        return n;
    }

    // g(op(a[l], ..., a[r-1])) が true となる最小の l (g(e()) は true であること)
    template <class G>
    int min_left(int r, G g) {
        if (r == 0) return 0;
        r += sz;
        for (int i = lg; i >= 1; i--) push((r - 1) >> i);
        S sm = AM::e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(AM::op(d[r], sm))) {
                while (r < sz) {
                    push(r);
                    r = 2 * r + 1;
                    if (g(AM::op(d[r], sm))) sm = AM::op(d[r--], sm);
                }
                return r + 1 - sz;
            }
            sm = AM::op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    void update(int k) { d[k] = AM::op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, const F &f) {
        d[k] = AM::mapping(f, d[k]);
        if (k < sz) lz[k] = AM::composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = AM::id();
    }
};
