#pragma once
#include "../template.hpp"
#include "../algebra/acted_monoid.hpp"

// 動的遅延セグメント木 (添字が大きい場合の区間作用・区間積)
// 添字は [0, n) (n は 2^62 程度まで)．はじめ全ての要素が x0 (省略時 e())
// 触った部分だけノードを作る．1 回の操作で作るノードは O(log n) 個
//
// 大きさを 2 冪に切り上げ，まだ作っていない長さ 2^k の区間の積は x0^(2^k) を事前計算しておいて使う
template <class AM>
struct DynamicLazySegmentTree {
    using S = typename AM::S;
    using F = typename AM::F;
    struct Node {
        S val;
        F lz;
        int l, r;
    };
    long long n;
    int lg;
    vector<S> pw;  // pw[k] = x0^(2^k)
    vector<Node> t;
    int root;

    DynamicLazySegmentTree(long long n = 0, S x0 = AM::e()) : n(n) {
        lg = 0;
        while ((1LL << lg) < n) lg++;
        pw.resize(lg + 1);
        pw[0] = x0;
        for (int k = 1; k <= lg; k++) pw[k] = AM::op(pw[k - 1], pw[k - 1]);
        root = new_node(lg);
    }

    void reserve(int k) { t.reserve(k); }

    // a[p] = x
    void set(long long p, const S &x) { set(root, lg, 0, p, x); }

    S get(long long p) { return prod(p, p + 1); }

    // op(a[l], ..., a[r-1])．l == r なら e()
    S prod(long long l, long long r) {
        if (l >= r) return AM::e();
        return prod(root, lg, 0, l, r, AM::id());
    }

    S all_prod() const { return t[root].val; }

    // i in [l, r) について a[i] = f(a[i])
    void apply(long long l, long long r, const F &f) {
        if (l >= r) return;
        apply(root, lg, 0, l, r, f);
    }

  private:
    int new_node(int k) {
        t.push_back({pw[k], AM::id(), -1, -1});
        return int(t.size()) - 1;
    }
    // 子を (なければ作って) 作用を下ろす
    void push(int v, int k) {
        if (t[v].l == -1) {
            int a = new_node(k - 1);
            int b = new_node(k - 1);
            t[v].l = a, t[v].r = b;
        }
        const F f = t[v].lz;
        all_apply(t[v].l, f);
        all_apply(t[v].r, f);
        t[v].lz = AM::id();
    }
    void all_apply(int v, const F &f) {
        t[v].val = AM::mapping(f, t[v].val);
        t[v].lz = AM::composition(f, t[v].lz);
    }
    void update(int v) { t[v].val = AM::op(t[t[v].l].val, t[t[v].r].val); }

    // ノード v は区間 [lo, lo + 2^k)
    void set(int v, int k, long long lo, long long p, const S &x) {
        if (k == 0) {
            t[v].val = x;
            return;
        }
        push(v, k);
        long long mid = lo + (1LL << (k - 1));
        if (p < mid) set(t[v].l, k - 1, lo, p, x);
        else set(t[v].r, k - 1, mid, p, x);
        update(v);
    }

    void apply(int v, int k, long long lo, long long l, long long r, const F &f) {
        long long hi = lo + (1LL << k);
        if (r <= lo || hi <= l) return;
        if (l <= lo && hi <= r) {
            all_apply(v, f);
            return;
        }
        push(v, k);
        long long mid = lo + (1LL << (k - 1));
        apply(t[v].l, k - 1, lo, l, r, f);
        apply(t[v].r, k - 1, mid, l, r, f);
        update(v);
    }

    // 子を作らずに済むよう，上から作用を持ち越して計算する (g: まだ下ろしていない作用)
    S prod(int v, int k, long long lo, long long l, long long r, const F &g) {
        long long hi = lo + (1LL << k);
        if (r <= lo || hi <= l) return AM::e();
        if (l <= lo && hi <= r) return AM::mapping(g, t[v].val);
        long long mid = lo + (1LL << (k - 1));
        if (t[v].l == -1) {
            // まだ子がない = 区間全体に x0 が並んでいて，作用 lz がかかっている
            long long a = std::max(l, lo), b = std::min(r, hi);
            S s = AM::e();
            for (int j = k - 1; j >= 0; j--) if ((b - a) >> j & 1) s = AM::op(s, pw[j]);
            return AM::mapping(AM::composition(g, t[v].lz), s);
        }
        F h = AM::composition(g, t[v].lz);
        return AM::op(prod(t[v].l, k - 1, lo, l, r, h), prod(t[v].r, k - 1, mid, l, r, h));
    }
};
