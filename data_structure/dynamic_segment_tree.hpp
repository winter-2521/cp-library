#pragma once
#include "../template.hpp"
#include "../algebra/monoid.hpp"

// 動的セグメント木 (添字が大きい場合の一点更新・区間積)
// 添字は [0, n) (n は 2^62 程度まで)．はじめ全て e()
//
// 各ノードは「区間 [lo, hi) の中の 1 要素 (位置 idx, 値 val)」と部分木全体の積を持つ．
// 左の子の部分木の位置 < idx < 右の子の部分木の位置 という順序を保つので，
// ノード数は値を設定した位置の個数と等しく，メモリは O(更新回数)．各操作 O(log n)
template <class M>
struct DynamicSegmentTree {
    using S = typename M::S;
    struct Node {
        long long idx;
        S val, prod;
        int l, r;
    };
    long long n;
    vector<Node> t;
    int root = -1;

    DynamicSegmentTree(long long n = 0) : n(n) {}

    // 更新回数の見込みを渡すと再確保を避けられる
    void reserve(int k) { t.reserve(k); }

    // a[p] = x
    void set(long long p, S x) { root = set(root, 0, n, p, x); }

    // a[p] (設定されていなければ e())
    S get(long long p) const {
        int v = root;
        long long lo = 0, hi = n;
        while (v != -1) {
            if (t[v].idx == p) return t[v].val;
            long long mid = (lo + hi) >> 1;
            if (p < mid) v = t[v].l, hi = mid;
            else v = t[v].r, lo = mid;
        }
        return M::e();
    }
    S operator[](long long p) const { return get(p); }

    // op(a[l], ..., a[r-1])．l == r なら e()
    S prod(long long l, long long r) const {
        if (l >= r) return M::e();
        return prod(root, 0, n, l, r);
    }

    S all_prod() const { return root == -1 ? M::e() : t[root].prod; }

  private:
    S prod_of(int v) const { return v == -1 ? M::e() : t[v].prod; }
    void update(int v) { t[v].prod = M::op(M::op(prod_of(t[v].l), t[v].val), prod_of(t[v].r)); }

    int set(int v, long long lo, long long hi, long long p, S x) {
        if (v == -1) {
            t.push_back({p, x, x, -1, -1});
            return int(t.size()) - 1;
        }
        if (t[v].idx == p) {
            t[v].val = x;
            update(v);
            return v;
        }
        long long mid = (lo + hi) >> 1;
        if (p < mid) {
            // ノードの要素の方が左にあれば入れ替えて，順序を保つ
            if (t[v].idx < p) swap(t[v].idx, p), swap(t[v].val, x);
            int c = set(t[v].l, lo, mid, p, x);
            t[v].l = c;
        } else {
            if (p < t[v].idx) swap(t[v].idx, p), swap(t[v].val, x);
            int c = set(t[v].r, mid, hi, p, x);
            t[v].r = c;
        }
        update(v);
        return v;
    }

    S prod(int v, long long lo, long long hi, long long l, long long r) const {
        if (v == -1 || hi <= l || r <= lo) return M::e();
        if (l <= lo && hi <= r) return t[v].prod;
        long long mid = (lo + hi) >> 1;
        S res = prod(t[v].l, lo, mid, l, r);
        if (l <= t[v].idx && t[v].idx < r) res = M::op(res, t[v].val);
        return M::op(res, prod(t[v].r, mid, hi, l, r));
    }
};
