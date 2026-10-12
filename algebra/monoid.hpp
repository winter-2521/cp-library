#pragma once
#include "../template.hpp"

// セグメント木などに渡すモノイド
// 形式: using S = 値の型; static S op(const S &a, const S &b); static S e();
// op は結合的で，e は単位元．op(a, b) は「a が左 (先)，b が右 (後)」

// 1 次関数 f(x) = a x + b
template <class T>
struct Affine {
    T a = T(1), b = T(0);
    Affine() = default;
    Affine(T a, T b) : a(a), b(b) {}
    T operator()(const T &x) const { return a * x + b; }
    T eval(const T &x) const { return a * x + b; }
    // 「先に *this，次に g」を表す関数 g(f(x))
    Affine then(const Affine &g) const { return Affine(a * g.a, b * g.a + g.b); }
    friend bool operator==(const Affine &f, const Affine &g) { return f.a == g.a && f.b == g.b; }
    friend bool operator!=(const Affine &f, const Affine &g) { return !(f == g); }
};

// 和
template <class T>
struct MonoidSum {
    using S = T;
    static S op(const S &a, const S &b) { return a + b; }
    static S e() { return S(0); }
};

// 最小値 (単位元は numeric_limits<T>::max())
template <class T>
struct MonoidMin {
    using S = T;
    static S op(const S &a, const S &b) { return b < a ? b : a; }
    static S e() { return numeric_limits<T>::max(); }
};

// 最大値 (単位元は numeric_limits<T>::lowest())
template <class T>
struct MonoidMax {
    using S = T;
    static S op(const S &a, const S &b) { return a < b ? b : a; }
    static S e() { return numeric_limits<T>::lowest(); }
};

// xor
template <class T>
struct MonoidXor {
    using S = T;
    static S op(const S &a, const S &b) { return a ^ b; }
    static S e() { return S(0); }
};

// 1 次関数の合成．op(f, g) = 「先に f，次に g」 = g(f(x))
// 区間 [l, r) の積は f_{r-1}(...f_l(x)) を表す
template <class T>
struct MonoidAffine {
    using S = Affine<T>;
    static S op(const S &f, const S &g) { return f.then(g); }
    static S e() { return S(); }
};

// x^k = op(x, x, ..., x) (k 個)．k = 0 なら e()．O(log k) 回の op
template <class M>
typename M::S monoid_pow(typename M::S x, long long k) {
    typename M::S r = M::e();
    while (k) {
        if (k & 1) r = M::op(r, x);
        k >>= 1;
        if (k) x = M::op(x, x);
    }
    return r;
}
