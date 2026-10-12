#pragma once
#include "../template.hpp"
#include "../algebra/monoid.hpp"

// セグメント木 (一点更新・区間積)
// M はモノイド (algebra/monoid.hpp 参照)．非可換でもよい
template <class M>
struct SegmentTree {
    using S = typename M::S;
    int n, sz, lg;
    vector<S> d;

    SegmentTree(int n = 0) : SegmentTree(vector<S>(n, M::e())) {}

    SegmentTree(const vector<S> &a) : n(a.size()) {
        lg = 0;
        while ((1 << lg) < n) lg++;
        sz = 1 << lg;
        d.assign(2 * sz, M::e());
        copy(a.begin(), a.end(), d.begin() + sz);
        for (int i = sz - 1; i >= 1; i--) d[i] = M::op(d[2 * i], d[2 * i + 1]);
    }

    int size() const { return n; }

    // a[p] = x
    void set(int p, const S &x) {
        p += sz;
        d[p] = x;
        for (p >>= 1; p; p >>= 1) d[p] = M::op(d[2 * p], d[2 * p + 1]);
    }

    // a[p] = op(a[p], x)
    void multiply(int p, const S &x) { set(p, M::op(d[p + sz], x)); }

    S get(int p) const { return d[p + sz]; }
    S operator[](int p) const { return d[p + sz]; }

    // op(a[l], ..., a[r-1])．l == r なら e()
    S prod(int l, int r) const {
        S sml = M::e(), smr = M::e();
        l += sz, r += sz;
        while (l < r) {
            if (l & 1) sml = M::op(sml, d[l++]);
            if (r & 1) smr = M::op(d[--r], smr);
            l >>= 1, r >>= 1;
        }
        return M::op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    // g(op(a[l], ..., a[r-1])) が true となる最大の r を返す (g(e()) は true であること)
    template <class G>
    int max_right(int l, G g) const {
        if (l == n) return n;
        l += sz;
        S sm = M::e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(M::op(sm, d[l]))) {
                while (l < sz) {
                    l = 2 * l;
                    if (g(M::op(sm, d[l]))) sm = M::op(sm, d[l++]);
                }
                return l - sz;
            }
            sm = M::op(sm, d[l++]);
        } while ((l & -l) != l);
        return n;
    }

    // g(op(a[l], ..., a[r-1])) が true となる最小の l を返す (g(e()) は true であること)
    template <class G>
    int min_left(int r, G g) const {
        if (r == 0) return 0;
        r += sz;
        S sm = M::e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(M::op(d[r], sm))) {
                while (r < sz) {
                    r = 2 * r + 1;
                    if (g(M::op(d[r], sm))) sm = M::op(d[r--], sm);
                }
                return r + 1 - sz;
            }
            sm = M::op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};
