#pragma once
#include "../template.hpp"
#include "../algebra/monoid.hpp"
#include "fast_set.hpp"
#include "segment_tree.hpp"

// https://github.com/winter-2521/cp-library

// 区間代入・区間積のセグメント木 (任意のモノイド，非可換でもよい)
// 値が等しい連続部分 (ラン) ごとにまとめて持つ．
// ランの先頭位置を FastSet で管理し，セグメント木のランの先頭の位置に x^(ランの長さ) を置く．
// 代入で消えるランは高々「作ったランの個数」なので，全体でならし O((n + q) log n) 回の op
// (x^k の計算に O(log k) 回の op を使う)
template <class M>
struct RangeAssignSegmentTree {
    using S = typename M::S;
    int n;
    FastSet starts;     // ランの先頭位置
    vector<S> val;      // val[s]: s から始まるランの値
    SegmentTree<M> seg; // seg[s] = val[s]^(ランの長さ)．ランの先頭以外は e()

    // 長さ n，全て x
    RangeAssignSegmentTree(int n = 0, const S &x = M::e()) : n(n), starts(n), val(n, x), seg(n) {
        if (n > 0) {
            starts.insert(0);
            seg.set(0, monoid_pow<M>(x, n));
        }
    }

    // 配列 a で初期化 (各要素が長さ 1 のラン)
    RangeAssignSegmentTree(const vector<S> &a) : n(a.size()), starts(n, [](int) { return true; }), val(a), seg(a) {}

    int size() const { return n; }

    // i in [l, r) について a[i] = x
    void assign(int l, int r, const S &x) {
        if (l >= r) return;
        split(l), split(r);
        for (int s = starts.next(l + 1); s != -1 && s < r; s = starts.next(s + 1)) {
            starts.erase(s);
            seg.set(s, M::e());
        }
        val[l] = x;
        seg.set(l, monoid_pow<M>(x, r - l));
    }

    // a[i] = x
    void set(int i, const S &x) { assign(i, i + 1, x); }

    S get(int i) const { return val[starts.prev(i)]; }
    S operator[](int i) const { return get(i); }

    // op(a[l], ..., a[r-1])．l == r なら e()
    S prod(int l, int r) const {
        if (l >= r) return M::e();
        int s = starts.prev(l), e = run_end(s);
        if (r <= e) return monoid_pow<M>(val[s], r - l);
        int s2 = starts.prev(r - 1);
        S res = monoid_pow<M>(val[s], e - l);
        res = M::op(res, seg.prod(e, s2));
        return M::op(res, monoid_pow<M>(val[s2], r - s2));
    }

    S all_prod() const { return seg.all_prod(); }

    // ランを列挙する: f(l, r, x) を左から順に呼ぶ ([l, r) が値 x のラン)
    template <class Fn>
    void enumerate_runs(Fn f) const {
        for (int s = starts.next(0); s != -1; s = starts.next(s + 1)) f(s, run_end(s), val[s]);
    }

  private:
    // s から始まるランの終わり (次のランの先頭)
    int run_end(int s) const {
        int e = starts.next(s + 1);
        return e == -1 ? n : e;
    }
    // p をランの先頭にする
    void split(int p) {
        if (p <= 0 || p >= n || starts.contains(p)) return;
        int s = starts.prev(p), e = run_end(s);
        starts.insert(p);
        val[p] = val[s];
        seg.set(s, monoid_pow<M>(val[s], p - s));
        seg.set(p, monoid_pow<M>(val[s], e - p));
    }
};
