#pragma once
#include "monoid.hpp"

// 遅延セグメント木などに渡す「作用付きモノイド」(ACL の lazy_segtree と同じ規約)
// 形式:
//   using S = 値の型;   static S op(S, S);  static S e();
//   using F = 作用の型; static S mapping(F f, S x);  // f を x に作用させる
//                       static F composition(F f, F g);  // 先に g，次に f (f ∘ g)
//                       static F id();

// 区間 1 次関数作用・区間和．S は {和, 長さ}
// 初期値は ActedAffineSum<T>::make(x) (= {x, 1}) で作る
template <class T>
struct ActedAffineSum {
    struct S {
        T sum, len;
    };
    using F = Affine<T>;
    static S make(const T &x) { return {x, T(1)}; }
    static S op(const S &a, const S &b) { return {a.sum + b.sum, a.len + b.len}; }
    static S e() { return {T(0), T(0)}; }
    static S mapping(const F &f, const S &x) { return {f.a * x.sum + f.b * x.len, x.len}; }
    static F composition(const F &f, const F &g) { return g.then(f); }
    static F id() { return F(); }
};

// 区間加算・区間和．S は {和, 長さ}
template <class T>
struct ActedAddSum {
    struct S {
        T sum, len;
    };
    using F = T;
    static S make(const T &x) { return {x, T(1)}; }
    static S op(const S &a, const S &b) { return {a.sum + b.sum, a.len + b.len}; }
    static S e() { return {T(0), T(0)}; }
    static S mapping(const F &f, const S &x) { return {x.sum + f * x.len, x.len}; }
    static F composition(const F &f, const F &g) { return f + g; }
    static F id() { return F(0); }
};

// 区間加算・区間最小値
template <class T>
struct ActedAddMin {
    using S = T;
    using F = T;
    static S op(const S &a, const S &b) { return b < a ? b : a; }
    static S e() { return numeric_limits<T>::max(); }
    // 単位元 (空区間) には作用させない
    static S mapping(const F &f, const S &x) { return x == e() ? x : x + f; }
    static F composition(const F &f, const F &g) { return f + g; }
    static F id() { return F(0); }
};

// 区間加算・区間最大値
template <class T>
struct ActedAddMax {
    using S = T;
    using F = T;
    static S op(const S &a, const S &b) { return a < b ? b : a; }
    static S e() { return numeric_limits<T>::lowest(); }
    static S mapping(const F &f, const S &x) { return x == e() ? x : x + f; }
    static F composition(const F &f, const F &g) { return f + g; }
    static F id() { return F(0); }
};

// 区間代入用の作用 (値を持たないときは恒等写像)
template <class T>
struct AssignAction {
    T x{};
    bool has = false;
    AssignAction() = default;
    AssignAction(const T &x) : x(x), has(true) {}
};

// 区間代入・区間和．S は {和, 長さ}
template <class T>
struct ActedAssignSum {
    struct S {
        T sum, len;
    };
    using F = AssignAction<T>;
    static S make(const T &x) { return {x, T(1)}; }
    static S op(const S &a, const S &b) { return {a.sum + b.sum, a.len + b.len}; }
    static S e() { return {T(0), T(0)}; }
    static S mapping(const F &f, const S &x) { return f.has ? S{f.x * x.len, x.len} : x; }
    static F composition(const F &f, const F &g) { return f.has ? f : g; }
    static F id() { return F(); }
};

// 区間代入・区間最小値
template <class T>
struct ActedAssignMin {
    using S = T;
    using F = AssignAction<T>;
    static S op(const S &a, const S &b) { return b < a ? b : a; }
    static S e() { return numeric_limits<T>::max(); }
    static S mapping(const F &f, const S &x) { return f.has ? f.x : x; }
    static F composition(const F &f, const F &g) { return f.has ? f : g; }
    static F id() { return F(); }
};

// 区間代入・区間最大値
template <class T>
struct ActedAssignMax {
    using S = T;
    using F = AssignAction<T>;
    static S op(const S &a, const S &b) { return a < b ? b : a; }
    static S e() { return numeric_limits<T>::lowest(); }
    static S mapping(const F &f, const S &x) { return f.has ? f.x : x; }
    static F composition(const F &f, const F &g) { return f.has ? f : g; }
    static F id() { return F(); }
};
