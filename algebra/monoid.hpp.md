---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid.hpp
    title: "\u4F5C\u7528\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (Acted Monoid)"
  - icon: ':heavy_check_mark:'
    path: data_structure/dual_segment_tree.hpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dual Segment Tree)"
  - icon: ':heavy_check_mark:'
    path: data_structure/dynamic_lazy_segment_tree.hpp
    title: "\u52D5\u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dynamic\
      \ Lazy Segment Tree)"
  - icon: ':heavy_check_mark:'
    path: data_structure/dynamic_segment_tree.hpp
    title: "\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dynamic Segment Tree)"
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segment_tree.hpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Lazy Segment Tree)"
  - icon: ':heavy_check_mark:'
    path: data_structure/persistent_lazy_segment_tree.hpp
    title: "\u6C38\u7D9A\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Persistent\
      \ Lazy Segment Tree)"
  - icon: ':heavy_check_mark:'
    path: data_structure/range_assign_segment_tree.hpp
    title: "\u533A\u9593\u4EE3\u5165\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Range Assign\
      \ Segment Tree)"
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)"
  - icon: ':heavy_check_mark:'
    path: data_structure/sortable_segment_tree.hpp
    title: "\u533A\u9593\u30BD\u30FC\u30C8\u304C\u3067\u304D\u308B\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728 (Sortable Segment Tree)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/persistent_range_affine_range_sum.test.cpp
    title: test/persistent_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/point_set_range_composite.test.cpp
    title: test/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/point_set_range_composite_large_array.test.cpp
    title: test/point_set_range_composite_large_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/point_set_range_sort_range_composite.test.cpp
    title: test/point_set_range_sort_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/range_affine_point_get.test.cpp
    title: test/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/range_affine_range_sum.test.cpp
    title: test/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/range_affine_range_sum_large_array.test.cpp
    title: test/range_affine_range_sum_large_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/range_set_range_composite.test.cpp
    title: test/range_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/lazy_segment_tree.test.cpp
    title: test/unittest/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/range_assign_segment_tree.test.cpp
    title: test/unittest/range_assign_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/segment_tree.test.cpp
    title: test/unittest/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/sortable_segment_tree.test.cpp
    title: test/unittest/sortable_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#if __has_include(<atcoder/all>)\n#include <atcoder/all>\nusing namespace\
    \ atcoder;\n#endif\n// QCfium\u6CD5\u3092\u4F7F\u3046\u6642\u306F\u30B3\u30E1\u30F3\
    \u30C8\u30A2\u30A6\u30C8\u3092\u5916\u3059\n/*/\n#pragma GCC optimize(\"Ofast,unroll-loops,no-stack-protector,fast-math\"\
    )\n#pragma GCC target(\"avx2,bmi,bmi2,lzcnt,popcnt\")\n#pragma GCC target(\"avx,avx2,fma\"\
    )\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma\"\
    )\n//*/\n#define rep(i,n) for(int i=0;i<n;i++)\n#define Rep(i,a,b) for(int i=a;i<b;i++)\n\
    #define ALL(x) (x).begin(),(x).end()\n#define dbgv(x); for(auto now : x) cout\
    \ << now << \" \"; cout << endl;\n//using P = pair<int,int>;\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\ntypedef pair<int, int> pii;\ntypedef\
    \ pair<ll, ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line\
    \ 3 \"algebra/monoid.hpp\"\n\n// \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306A\u3069\
    \u306B\u6E21\u3059\u30E2\u30CE\u30A4\u30C9\n// \u5F62\u5F0F: using S = \u5024\u306E\
    \u578B; static S op(const S &a, const S &b); static S e();\n// op \u306F\u7D50\
    \u5408\u7684\u3067\uFF0Ce \u306F\u5358\u4F4D\u5143\uFF0Eop(a, b) \u306F\u300C\
    a \u304C\u5DE6 (\u5148)\uFF0Cb \u304C\u53F3 (\u5F8C)\u300D\n\n// 1 \u6B21\u95A2\
    \u6570 f(x) = a x + b\ntemplate <class T>\nstruct Affine {\n    T a = T(1), b\
    \ = T(0);\n    Affine() = default;\n    Affine(T a, T b) : a(a), b(b) {}\n   \
    \ T operator()(const T &x) const { return a * x + b; }\n    T eval(const T &x)\
    \ const { return a * x + b; }\n    // \u300C\u5148\u306B *this\uFF0C\u6B21\u306B\
    \ g\u300D\u3092\u8868\u3059\u95A2\u6570 g(f(x))\n    Affine then(const Affine\
    \ &g) const { return Affine(a * g.a, b * g.a + g.b); }\n    friend bool operator==(const\
    \ Affine &f, const Affine &g) { return f.a == g.a && f.b == g.b; }\n    friend\
    \ bool operator!=(const Affine &f, const Affine &g) { return !(f == g); }\n};\n\
    \n// \u548C\ntemplate <class T>\nstruct MonoidSum {\n    using S = T;\n    static\
    \ S op(const S &a, const S &b) { return a + b; }\n    static S e() { return S(0);\
    \ }\n};\n\n// \u6700\u5C0F\u5024 (\u5358\u4F4D\u5143\u306F numeric_limits<T>::max())\n\
    template <class T>\nstruct MonoidMin {\n    using S = T;\n    static S op(const\
    \ S &a, const S &b) { return b < a ? b : a; }\n    static S e() { return numeric_limits<T>::max();\
    \ }\n};\n\n// \u6700\u5927\u5024 (\u5358\u4F4D\u5143\u306F numeric_limits<T>::lowest())\n\
    template <class T>\nstruct MonoidMax {\n    using S = T;\n    static S op(const\
    \ S &a, const S &b) { return a < b ? b : a; }\n    static S e() { return numeric_limits<T>::lowest();\
    \ }\n};\n\n// xor\ntemplate <class T>\nstruct MonoidXor {\n    using S = T;\n\
    \    static S op(const S &a, const S &b) { return a ^ b; }\n    static S e() {\
    \ return S(0); }\n};\n\n// 1 \u6B21\u95A2\u6570\u306E\u5408\u6210\uFF0Eop(f, g)\
    \ = \u300C\u5148\u306B f\uFF0C\u6B21\u306B g\u300D = g(f(x))\n// \u533A\u9593\
    \ [l, r) \u306E\u7A4D\u306F f_{r-1}(...f_l(x)) \u3092\u8868\u3059\ntemplate <class\
    \ T>\nstruct MonoidAffine {\n    using S = Affine<T>;\n    static S op(const S\
    \ &f, const S &g) { return f.then(g); }\n    static S e() { return S(); }\n};\n\
    \n// x^k = op(x, x, ..., x) (k \u500B)\uFF0Ek = 0 \u306A\u3089 e()\uFF0EO(log\
    \ k) \u56DE\u306E op\ntemplate <class M>\ntypename M::S monoid_pow(typename M::S\
    \ x, long long k) {\n    typename M::S r = M::e();\n    while (k) {\n        if\
    \ (k & 1) r = M::op(r, x);\n        k >>= 1;\n        if (k) x = M::op(x, x);\n\
    \    }\n    return r;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// \u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\u306A\u3069\u306B\u6E21\u3059\u30E2\u30CE\u30A4\u30C9\n// \u5F62\u5F0F\
    : using S = \u5024\u306E\u578B; static S op(const S &a, const S &b); static S\
    \ e();\n// op \u306F\u7D50\u5408\u7684\u3067\uFF0Ce \u306F\u5358\u4F4D\u5143\uFF0E\
    op(a, b) \u306F\u300Ca \u304C\u5DE6 (\u5148)\uFF0Cb \u304C\u53F3 (\u5F8C)\u300D\
    \n\n// 1 \u6B21\u95A2\u6570 f(x) = a x + b\ntemplate <class T>\nstruct Affine\
    \ {\n    T a = T(1), b = T(0);\n    Affine() = default;\n    Affine(T a, T b)\
    \ : a(a), b(b) {}\n    T operator()(const T &x) const { return a * x + b; }\n\
    \    T eval(const T &x) const { return a * x + b; }\n    // \u300C\u5148\u306B\
    \ *this\uFF0C\u6B21\u306B g\u300D\u3092\u8868\u3059\u95A2\u6570 g(f(x))\n    Affine\
    \ then(const Affine &g) const { return Affine(a * g.a, b * g.a + g.b); }\n   \
    \ friend bool operator==(const Affine &f, const Affine &g) { return f.a == g.a\
    \ && f.b == g.b; }\n    friend bool operator!=(const Affine &f, const Affine &g)\
    \ { return !(f == g); }\n};\n\n// \u548C\ntemplate <class T>\nstruct MonoidSum\
    \ {\n    using S = T;\n    static S op(const S &a, const S &b) { return a + b;\
    \ }\n    static S e() { return S(0); }\n};\n\n// \u6700\u5C0F\u5024 (\u5358\u4F4D\
    \u5143\u306F numeric_limits<T>::max())\ntemplate <class T>\nstruct MonoidMin {\n\
    \    using S = T;\n    static S op(const S &a, const S &b) { return b < a ? b\
    \ : a; }\n    static S e() { return numeric_limits<T>::max(); }\n};\n\n// \u6700\
    \u5927\u5024 (\u5358\u4F4D\u5143\u306F numeric_limits<T>::lowest())\ntemplate\
    \ <class T>\nstruct MonoidMax {\n    using S = T;\n    static S op(const S &a,\
    \ const S &b) { return a < b ? b : a; }\n    static S e() { return numeric_limits<T>::lowest();\
    \ }\n};\n\n// xor\ntemplate <class T>\nstruct MonoidXor {\n    using S = T;\n\
    \    static S op(const S &a, const S &b) { return a ^ b; }\n    static S e() {\
    \ return S(0); }\n};\n\n// 1 \u6B21\u95A2\u6570\u306E\u5408\u6210\uFF0Eop(f, g)\
    \ = \u300C\u5148\u306B f\uFF0C\u6B21\u306B g\u300D = g(f(x))\n// \u533A\u9593\
    \ [l, r) \u306E\u7A4D\u306F f_{r-1}(...f_l(x)) \u3092\u8868\u3059\ntemplate <class\
    \ T>\nstruct MonoidAffine {\n    using S = Affine<T>;\n    static S op(const S\
    \ &f, const S &g) { return f.then(g); }\n    static S e() { return S(); }\n};\n\
    \n// x^k = op(x, x, ..., x) (k \u500B)\uFF0Ek = 0 \u306A\u3089 e()\uFF0EO(log\
    \ k) \u56DE\u306E op\ntemplate <class M>\ntypename M::S monoid_pow(typename M::S\
    \ x, long long k) {\n    typename M::S r = M::e();\n    while (k) {\n        if\
    \ (k & 1) r = M::op(r, x);\n        k >>= 1;\n        if (k) x = M::op(x, x);\n\
    \    }\n    return r;\n}\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: algebra/monoid.hpp
  requiredBy:
  - data_structure/dual_segment_tree.hpp
  - data_structure/lazy_segment_tree.hpp
  - data_structure/sortable_segment_tree.hpp
  - data_structure/persistent_lazy_segment_tree.hpp
  - data_structure/dynamic_segment_tree.hpp
  - data_structure/dynamic_lazy_segment_tree.hpp
  - data_structure/segment_tree.hpp
  - data_structure/range_assign_segment_tree.hpp
  - algebra/acted_monoid.hpp
  timestamp: '2026-10-12 11:35:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/point_set_range_composite_large_array.test.cpp
  - test/persistent_range_affine_range_sum.test.cpp
  - test/unittest/lazy_segment_tree.test.cpp
  - test/unittest/segment_tree.test.cpp
  - test/unittest/range_assign_segment_tree.test.cpp
  - test/unittest/sortable_segment_tree.test.cpp
  - test/point_set_range_sort_range_composite.test.cpp
  - test/range_affine_point_get.test.cpp
  - test/point_set_range_composite.test.cpp
  - test/range_set_range_composite.test.cpp
  - test/range_affine_range_sum.test.cpp
  - test/range_affine_range_sum_large_array.test.cpp
documentation_of: algebra/monoid.hpp
layout: document
title: "\u30E2\u30CE\u30A4\u30C9 (Monoid)"
---

## 概要

セグメント木などに渡すモノイドの定義と、よく使うモノイド。1 次関数 `Affine<T>` もここにある。

モノイドは次の形の構造体で表す（ACL の `segtree` のテンプレート引数を 1 つの構造体にまとめた形）。

```cpp
struct M {
    using S = 値の型;
    static S op(const S &a, const S &b);  // 結合的．a が左 (先)，b が右 (後)
    static S e();                         // 単位元
};
```

## 用意しているもの

| 名前 | `S` | `op(a, b)` | `e()` |
| --- | --- | --- | --- |
| `MonoidSum<T>` | `T` | $a + b$ | $0$ |
| `MonoidMin<T>` | `T` | $\min(a, b)$ | `numeric_limits<T>::max()` |
| `MonoidMax<T>` | `T` | $\max(a, b)$ | `numeric_limits<T>::lowest()` |
| `MonoidXor<T>` | `T` | $a \oplus b$ | $0$ |
| `MonoidAffine<T>` | `Affine<T>` | 「先に $a$、次に $b$」 $= b(a(x))$ | $x \mapsto x$ |

```cpp
Affine<mint> f(a, b);   // f(x) = a x + b
f(x); f.eval(x);        // 値
f.then(g);              // 先に f，次に g: g(f(x))
f == g;

monoid_pow<M>(x, k);    // op(x, x, ..., x) (k 個)．O(log k) 回の op
```

`MonoidAffine` を `SegmentTree` に乗せると、`prod(l, r)` は $f_{r-1}(\cdots f_l(x))$ を表す関数になる（Library Checker の Point Set Range Composite と同じ向き）。

## 注意

- `MonoidMin` / `MonoidMax` は `numeric_limits` を使うので算術型のみ。
- 自作するときは `op` が結合的で `e()` が単位元であることを確かめること。
