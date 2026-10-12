---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9 (Monoid)"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/range_affine_point_get.test.cpp
    title: test/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/segment_tree.test.cpp
    title: test/unittest/segment_tree.test.cpp
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
    \ 2 \"template.hpp\"\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
    #include <atcoder/all>\nusing namespace atcoder;\n#endif\n// QCfium\u6CD5\u3092\
    \u4F7F\u3046\u6642\u306F\u30B3\u30E1\u30F3\u30C8\u30A2\u30A6\u30C8\u3092\u5916\
    \u3059\n/*/\n#pragma GCC optimize(\"Ofast,unroll-loops,no-stack-protector,fast-math\"\
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
    \    }\n    return r;\n}\n#line 4 \"data_structure/dual_segment_tree.hpp\"\n\n\
    // \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u4F5C\u7528\u30FB\
    \u4E00\u70B9\u53D6\u5F97)\n// \u5404\u4F4D\u7F6E i \u306B\u4F5C\u7528 F_i (\u306F\
    \u3058\u3081 e()) \u3092\u6301\u3061\uFF0C\u533A\u9593 [l, r) \u306E\u5404 F_i\
    \ \u3092 op(F_i, f) \u306B\u66F4\u65B0\u3059\u308B\uFF0E\n// M \u306F\u30E2\u30CE\
    \u30A4\u30C9\u3067\uFF0Cop(x, y) \u306F\u300C\u5148\u306B x\uFF0C\u6B21\u306B\
    \ y\u300D\u3068\u3044\u3046\u6642\u7CFB\u5217\u9806\u306E\u5408\u6210 (\u975E\u53EF\
    \u63DB\u3067\u3082\u3088\u3044)\n// \u4F8B: DualSegmentTree<MonoidAffine<mint>>\
    \ \u3067\u533A\u9593 1 \u6B21\u95A2\u6570\u4F5C\u7528\uFF0Cget(i)(a[i]) \u3067\
    \u73FE\u5728\u306E\u5024\ntemplate <class M>\nstruct DualSegmentTree {\n    using\
    \ S = typename M::S;\n    int n, sz, lg;\n    vector<S> lz;\n\n    DualSegmentTree(int\
    \ n = 0) : n(n) {\n        lg = 0;\n        while ((1 << lg) < n) lg++;\n    \
    \    sz = 1 << lg;\n        lz.assign(2 * sz, M::e());\n    }\n\n    int size()\
    \ const { return n; }\n\n    // i in [l, r) \u306B\u3064\u3044\u3066 F_i = op(F_i,\
    \ f)\n    void apply(int l, int r, const S &f) {\n        if (l >= r) return;\n\
    \        l += sz, r += sz;\n        // \u975E\u53EF\u63DB\u306A\u306E\u3067\uFF0C\
    \u5148\u306B\u5883\u754C\u306E\u7956\u5148\u306E\u4F5C\u7528\u3092\u4E0B\u308D\
    \u3057\u3066\u304A\u304F\n        for (int i = lg; i >= 1; i--) {\n          \
    \  if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) !=\
    \ r) push((r - 1) >> i);\n        }\n        while (l < r) {\n            if (l\
    \ & 1) lz[l] = M::op(lz[l], f), l++;\n            if (r & 1) --r, lz[r] = M::op(lz[r],\
    \ f);\n            l >>= 1, r >>= 1;\n        }\n    }\n\n    // F_p = op(F_p,\
    \ f)\n    void apply(int p, const S &f) { apply(p, p + 1, f); }\n\n    // F_p\
    \ (\u4F4D\u7F6E p \u306B\u3053\u308C\u307E\u3067\u306B\u4F5C\u7528\u3057\u305F\
    \u5168\u3066\u3092\u6642\u7CFB\u5217\u9806\u306B\u5408\u6210\u3057\u305F\u3082\
    \u306E)\n    S get(int p) const {\n        p += sz;\n        S res = lz[p];\n\
    \        // \u7956\u5148\u306E\u4F5C\u7528\u306E\u65B9\u304C\u65B0\u3057\u3044\
    \n        for (p >>= 1; p; p >>= 1) res = M::op(res, lz[p]);\n        return res;\n\
    \    }\n    S operator[](int p) const { return get(p); }\n\n    // F_p = f \u306B\
    \u7F6E\u304D\u63DB\u3048\u308B\n    void set(int p, const S &f) {\n        p +=\
    \ sz;\n        for (int i = lg; i >= 1; i--) push(p >> i);\n        lz[p] = f;\n\
    \    }\n\n  private:\n    void push(int k) {\n        lz[2 * k] = M::op(lz[2 *\
    \ k], lz[k]);\n        lz[2 * k + 1] = M::op(lz[2 * k + 1], lz[k]);\n        lz[k]\
    \ = M::e();\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"../algebra/monoid.hpp\"\
    \n\n// \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u4F5C\u7528\
    \u30FB\u4E00\u70B9\u53D6\u5F97)\n// \u5404\u4F4D\u7F6E i \u306B\u4F5C\u7528 F_i\
    \ (\u306F\u3058\u3081 e()) \u3092\u6301\u3061\uFF0C\u533A\u9593 [l, r) \u306E\u5404\
    \ F_i \u3092 op(F_i, f) \u306B\u66F4\u65B0\u3059\u308B\uFF0E\n// M \u306F\u30E2\
    \u30CE\u30A4\u30C9\u3067\uFF0Cop(x, y) \u306F\u300C\u5148\u306B x\uFF0C\u6B21\u306B\
    \ y\u300D\u3068\u3044\u3046\u6642\u7CFB\u5217\u9806\u306E\u5408\u6210 (\u975E\u53EF\
    \u63DB\u3067\u3082\u3088\u3044)\n// \u4F8B: DualSegmentTree<MonoidAffine<mint>>\
    \ \u3067\u533A\u9593 1 \u6B21\u95A2\u6570\u4F5C\u7528\uFF0Cget(i)(a[i]) \u3067\
    \u73FE\u5728\u306E\u5024\ntemplate <class M>\nstruct DualSegmentTree {\n    using\
    \ S = typename M::S;\n    int n, sz, lg;\n    vector<S> lz;\n\n    DualSegmentTree(int\
    \ n = 0) : n(n) {\n        lg = 0;\n        while ((1 << lg) < n) lg++;\n    \
    \    sz = 1 << lg;\n        lz.assign(2 * sz, M::e());\n    }\n\n    int size()\
    \ const { return n; }\n\n    // i in [l, r) \u306B\u3064\u3044\u3066 F_i = op(F_i,\
    \ f)\n    void apply(int l, int r, const S &f) {\n        if (l >= r) return;\n\
    \        l += sz, r += sz;\n        // \u975E\u53EF\u63DB\u306A\u306E\u3067\uFF0C\
    \u5148\u306B\u5883\u754C\u306E\u7956\u5148\u306E\u4F5C\u7528\u3092\u4E0B\u308D\
    \u3057\u3066\u304A\u304F\n        for (int i = lg; i >= 1; i--) {\n          \
    \  if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) !=\
    \ r) push((r - 1) >> i);\n        }\n        while (l < r) {\n            if (l\
    \ & 1) lz[l] = M::op(lz[l], f), l++;\n            if (r & 1) --r, lz[r] = M::op(lz[r],\
    \ f);\n            l >>= 1, r >>= 1;\n        }\n    }\n\n    // F_p = op(F_p,\
    \ f)\n    void apply(int p, const S &f) { apply(p, p + 1, f); }\n\n    // F_p\
    \ (\u4F4D\u7F6E p \u306B\u3053\u308C\u307E\u3067\u306B\u4F5C\u7528\u3057\u305F\
    \u5168\u3066\u3092\u6642\u7CFB\u5217\u9806\u306B\u5408\u6210\u3057\u305F\u3082\
    \u306E)\n    S get(int p) const {\n        p += sz;\n        S res = lz[p];\n\
    \        // \u7956\u5148\u306E\u4F5C\u7528\u306E\u65B9\u304C\u65B0\u3057\u3044\
    \n        for (p >>= 1; p; p >>= 1) res = M::op(res, lz[p]);\n        return res;\n\
    \    }\n    S operator[](int p) const { return get(p); }\n\n    // F_p = f \u306B\
    \u7F6E\u304D\u63DB\u3048\u308B\n    void set(int p, const S &f) {\n        p +=\
    \ sz;\n        for (int i = lg; i >= 1; i--) push(p >> i);\n        lz[p] = f;\n\
    \    }\n\n  private:\n    void push(int k) {\n        lz[2 * k] = M::op(lz[2 *\
    \ k], lz[k]);\n        lz[2 * k + 1] = M::op(lz[2 * k + 1], lz[k]);\n        lz[k]\
    \ = M::e();\n    }\n};\n"
  dependsOn:
  - template.hpp
  - algebra/monoid.hpp
  - template.hpp
  isVerificationFile: false
  path: data_structure/dual_segment_tree.hpp
  requiredBy: []
  timestamp: '2026-10-12 11:35:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/segment_tree.test.cpp
  - test/range_affine_point_get.test.cpp
documentation_of: data_structure/dual_segment_tree.hpp
layout: document
title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dual Segment Tree)"
---

## 概要

区間への作用と一点取得を $O(\log n)$ で処理する。各位置 $i$ に作用 $F_i$（はじめ単位元）を持ち、`apply(l, r, f)` で $[l, r)$ の各 $F_i$ を $\mathrm{op}(F_i, f)$ に更新する。
`op(x, y)` は **時系列順**（先に $x$、次に $y$）の合成。非可換でもよい（範囲作用の前に境界の祖先の作用を下ろしている）。

遅延セグメント木と違って区間積は求められないが、そのぶん速くて軽い。

## 使い方

```cpp
// 区間 1 次関数作用・一点取得 (range_affine_point_get)
DualSegmentTree<MonoidAffine<mint>> seg(n);
seg.apply(l, r, {b, c});    // [l, r) に x -> b x + c を作用
seg.get(i)(a[i]);           // 位置 i の作用の合成を初期値 a[i] に適用 = 現在の値

// 区間加算・一点取得
DualSegmentTree<MonoidSum<long long>> add(n);
add.apply(l, r, x);
a[i] + add.get(i);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `DualSegmentTree<M>(int n)` | 全て `e()` で構築 | $O(n)$ |
| `void apply(int l, int r, S f)` | $i \in [l, r)$ について $F_i = \mathrm{op}(F_i, f)$ | $O(\log n)$ |
| `void apply(int p, S f)` | $F_p = \mathrm{op}(F_p, f)$ | $O(\log n)$ |
| `S get(int p)` / `operator[]` | $F_p$ | $O(\log n)$ |
| `void set(int p, S f)` | $F_p = f$ | $O(\log n)$ |

## 注意

- 値そのものではなく「これまでの作用の合成」を返す。初期値への適用は呼び出し側で行う（`get(i)(a[i])` など）。
