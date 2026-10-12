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
    path: test/point_set_range_composite_large_array.test.cpp
    title: test/point_set_range_composite_large_array.test.cpp
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
    \    }\n    return r;\n}\n#line 4 \"data_structure/dynamic_segment_tree.hpp\"\n\
    \n// \u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u6DFB\u5B57\u304C\u5927\
    \u304D\u3044\u5834\u5408\u306E\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\u9593\u7A4D\
    )\n// \u6DFB\u5B57\u306F [0, n) (n \u306F 2^62 \u7A0B\u5EA6\u307E\u3067)\uFF0E\
    \u306F\u3058\u3081\u5168\u3066 e()\n//\n// \u5404\u30CE\u30FC\u30C9\u306F\u300C\
    \u533A\u9593 [lo, hi) \u306E\u4E2D\u306E 1 \u8981\u7D20 (\u4F4D\u7F6E idx, \u5024\
    \ val)\u300D\u3068\u90E8\u5206\u6728\u5168\u4F53\u306E\u7A4D\u3092\u6301\u3064\
    \uFF0E\n// \u5DE6\u306E\u5B50\u306E\u90E8\u5206\u6728\u306E\u4F4D\u7F6E < idx\
    \ < \u53F3\u306E\u5B50\u306E\u90E8\u5206\u6728\u306E\u4F4D\u7F6E \u3068\u3044\u3046\
    \u9806\u5E8F\u3092\u4FDD\u3064\u306E\u3067\uFF0C\n// \u30CE\u30FC\u30C9\u6570\u306F\
    \u5024\u3092\u8A2D\u5B9A\u3057\u305F\u4F4D\u7F6E\u306E\u500B\u6570\u3068\u7B49\
    \u3057\u304F\uFF0C\u30E1\u30E2\u30EA\u306F O(\u66F4\u65B0\u56DE\u6570)\uFF0E\u5404\
    \u64CD\u4F5C O(log n)\ntemplate <class M>\nstruct DynamicSegmentTree {\n    using\
    \ S = typename M::S;\n    struct Node {\n        long long idx;\n        S val,\
    \ prod;\n        int l, r;\n    };\n    long long n;\n    vector<Node> t;\n  \
    \  int root = -1;\n\n    DynamicSegmentTree(long long n = 0) : n(n) {}\n\n   \
    \ // \u66F4\u65B0\u56DE\u6570\u306E\u898B\u8FBC\u307F\u3092\u6E21\u3059\u3068\u518D\
    \u78BA\u4FDD\u3092\u907F\u3051\u3089\u308C\u308B\n    void reserve(int k) { t.reserve(k);\
    \ }\n\n    // a[p] = x\n    void set(long long p, S x) { root = set(root, 0, n,\
    \ p, x); }\n\n    // a[p] (\u8A2D\u5B9A\u3055\u308C\u3066\u3044\u306A\u3051\u308C\
    \u3070 e())\n    S get(long long p) const {\n        int v = root;\n        long\
    \ long lo = 0, hi = n;\n        while (v != -1) {\n            if (t[v].idx ==\
    \ p) return t[v].val;\n            long long mid = (lo + hi) >> 1;\n         \
    \   if (p < mid) v = t[v].l, hi = mid;\n            else v = t[v].r, lo = mid;\n\
    \        }\n        return M::e();\n    }\n    S operator[](long long p) const\
    \ { return get(p); }\n\n    // op(a[l], ..., a[r-1])\uFF0El == r \u306A\u3089\
    \ e()\n    S prod(long long l, long long r) const {\n        if (l >= r) return\
    \ M::e();\n        return prod(root, 0, n, l, r);\n    }\n\n    S all_prod() const\
    \ { return root == -1 ? M::e() : t[root].prod; }\n\n  private:\n    S prod_of(int\
    \ v) const { return v == -1 ? M::e() : t[v].prod; }\n    void update(int v) {\
    \ t[v].prod = M::op(M::op(prod_of(t[v].l), t[v].val), prod_of(t[v].r)); }\n\n\
    \    int set(int v, long long lo, long long hi, long long p, S x) {\n        if\
    \ (v == -1) {\n            t.push_back({p, x, x, -1, -1});\n            return\
    \ int(t.size()) - 1;\n        }\n        if (t[v].idx == p) {\n            t[v].val\
    \ = x;\n            update(v);\n            return v;\n        }\n        long\
    \ long mid = (lo + hi) >> 1;\n        if (p < mid) {\n            // \u30CE\u30FC\
    \u30C9\u306E\u8981\u7D20\u306E\u65B9\u304C\u5DE6\u306B\u3042\u308C\u3070\u5165\
    \u308C\u66FF\u3048\u3066\uFF0C\u9806\u5E8F\u3092\u4FDD\u3064\n            if (t[v].idx\
    \ < p) swap(t[v].idx, p), swap(t[v].val, x);\n            int c = set(t[v].l,\
    \ lo, mid, p, x);\n            t[v].l = c;\n        } else {\n            if (p\
    \ < t[v].idx) swap(t[v].idx, p), swap(t[v].val, x);\n            int c = set(t[v].r,\
    \ mid, hi, p, x);\n            t[v].r = c;\n        }\n        update(v);\n  \
    \      return v;\n    }\n\n    S prod(int v, long long lo, long long hi, long\
    \ long l, long long r) const {\n        if (v == -1 || hi <= l || r <= lo) return\
    \ M::e();\n        if (l <= lo && hi <= r) return t[v].prod;\n        long long\
    \ mid = (lo + hi) >> 1;\n        S res = prod(t[v].l, lo, mid, l, r);\n      \
    \  if (l <= t[v].idx && t[v].idx < r) res = M::op(res, t[v].val);\n        return\
    \ M::op(res, prod(t[v].r, mid, hi, l, r));\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"../algebra/monoid.hpp\"\
    \n\n// \u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u6DFB\u5B57\u304C\u5927\
    \u304D\u3044\u5834\u5408\u306E\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\u9593\u7A4D\
    )\n// \u6DFB\u5B57\u306F [0, n) (n \u306F 2^62 \u7A0B\u5EA6\u307E\u3067)\uFF0E\
    \u306F\u3058\u3081\u5168\u3066 e()\n//\n// \u5404\u30CE\u30FC\u30C9\u306F\u300C\
    \u533A\u9593 [lo, hi) \u306E\u4E2D\u306E 1 \u8981\u7D20 (\u4F4D\u7F6E idx, \u5024\
    \ val)\u300D\u3068\u90E8\u5206\u6728\u5168\u4F53\u306E\u7A4D\u3092\u6301\u3064\
    \uFF0E\n// \u5DE6\u306E\u5B50\u306E\u90E8\u5206\u6728\u306E\u4F4D\u7F6E < idx\
    \ < \u53F3\u306E\u5B50\u306E\u90E8\u5206\u6728\u306E\u4F4D\u7F6E \u3068\u3044\u3046\
    \u9806\u5E8F\u3092\u4FDD\u3064\u306E\u3067\uFF0C\n// \u30CE\u30FC\u30C9\u6570\u306F\
    \u5024\u3092\u8A2D\u5B9A\u3057\u305F\u4F4D\u7F6E\u306E\u500B\u6570\u3068\u7B49\
    \u3057\u304F\uFF0C\u30E1\u30E2\u30EA\u306F O(\u66F4\u65B0\u56DE\u6570)\uFF0E\u5404\
    \u64CD\u4F5C O(log n)\ntemplate <class M>\nstruct DynamicSegmentTree {\n    using\
    \ S = typename M::S;\n    struct Node {\n        long long idx;\n        S val,\
    \ prod;\n        int l, r;\n    };\n    long long n;\n    vector<Node> t;\n  \
    \  int root = -1;\n\n    DynamicSegmentTree(long long n = 0) : n(n) {}\n\n   \
    \ // \u66F4\u65B0\u56DE\u6570\u306E\u898B\u8FBC\u307F\u3092\u6E21\u3059\u3068\u518D\
    \u78BA\u4FDD\u3092\u907F\u3051\u3089\u308C\u308B\n    void reserve(int k) { t.reserve(k);\
    \ }\n\n    // a[p] = x\n    void set(long long p, S x) { root = set(root, 0, n,\
    \ p, x); }\n\n    // a[p] (\u8A2D\u5B9A\u3055\u308C\u3066\u3044\u306A\u3051\u308C\
    \u3070 e())\n    S get(long long p) const {\n        int v = root;\n        long\
    \ long lo = 0, hi = n;\n        while (v != -1) {\n            if (t[v].idx ==\
    \ p) return t[v].val;\n            long long mid = (lo + hi) >> 1;\n         \
    \   if (p < mid) v = t[v].l, hi = mid;\n            else v = t[v].r, lo = mid;\n\
    \        }\n        return M::e();\n    }\n    S operator[](long long p) const\
    \ { return get(p); }\n\n    // op(a[l], ..., a[r-1])\uFF0El == r \u306A\u3089\
    \ e()\n    S prod(long long l, long long r) const {\n        if (l >= r) return\
    \ M::e();\n        return prod(root, 0, n, l, r);\n    }\n\n    S all_prod() const\
    \ { return root == -1 ? M::e() : t[root].prod; }\n\n  private:\n    S prod_of(int\
    \ v) const { return v == -1 ? M::e() : t[v].prod; }\n    void update(int v) {\
    \ t[v].prod = M::op(M::op(prod_of(t[v].l), t[v].val), prod_of(t[v].r)); }\n\n\
    \    int set(int v, long long lo, long long hi, long long p, S x) {\n        if\
    \ (v == -1) {\n            t.push_back({p, x, x, -1, -1});\n            return\
    \ int(t.size()) - 1;\n        }\n        if (t[v].idx == p) {\n            t[v].val\
    \ = x;\n            update(v);\n            return v;\n        }\n        long\
    \ long mid = (lo + hi) >> 1;\n        if (p < mid) {\n            // \u30CE\u30FC\
    \u30C9\u306E\u8981\u7D20\u306E\u65B9\u304C\u5DE6\u306B\u3042\u308C\u3070\u5165\
    \u308C\u66FF\u3048\u3066\uFF0C\u9806\u5E8F\u3092\u4FDD\u3064\n            if (t[v].idx\
    \ < p) swap(t[v].idx, p), swap(t[v].val, x);\n            int c = set(t[v].l,\
    \ lo, mid, p, x);\n            t[v].l = c;\n        } else {\n            if (p\
    \ < t[v].idx) swap(t[v].idx, p), swap(t[v].val, x);\n            int c = set(t[v].r,\
    \ mid, hi, p, x);\n            t[v].r = c;\n        }\n        update(v);\n  \
    \      return v;\n    }\n\n    S prod(int v, long long lo, long long hi, long\
    \ long l, long long r) const {\n        if (v == -1 || hi <= l || r <= lo) return\
    \ M::e();\n        if (l <= lo && hi <= r) return t[v].prod;\n        long long\
    \ mid = (lo + hi) >> 1;\n        S res = prod(t[v].l, lo, mid, l, r);\n      \
    \  if (l <= t[v].idx && t[v].idx < r) res = M::op(res, t[v].val);\n        return\
    \ M::op(res, prod(t[v].r, mid, hi, l, r));\n    }\n};\n"
  dependsOn:
  - template.hpp
  - algebra/monoid.hpp
  - template.hpp
  isVerificationFile: false
  path: data_structure/dynamic_segment_tree.hpp
  requiredBy: []
  timestamp: '2026-10-12 11:35:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/point_set_range_composite_large_array.test.cpp
  - test/unittest/segment_tree.test.cpp
documentation_of: data_structure/dynamic_segment_tree.hpp
layout: document
title: "\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dynamic Segment Tree)"
---

## 概要

添字の範囲が大きい（$n \le 10^{18}$ 程度）場合の一点更新・区間積。はじめ全て `e()`。**オンライン** で動く（座標圧縮のための先読みが不要）。

各ノードが「担当区間の中の 1 要素（位置と値）」と部分木の積を持ち、左の子の部分木の位置 $<$ ノードの位置 $<$ 右の子の部分木の位置 という順序を保つ。
こうするとノード数は値を設定した位置の個数と同じになり、メモリは $O(\text{更新回数})$ で済む（素朴な動的セグメント木は 1 回の更新で $\log n$ 個のノードを作る）。

## 使い方

```cpp
DynamicSegmentTree<MonoidAffine<mint>> seg(1000000000);
seg.reserve(q);          // 任意．更新回数の見込み
seg.set(p, {c, d});      // a[p] = x
seg.prod(l, r)(x);       // op(a[l], ..., a[r-1])
seg.get(p); seg.all_prod();
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `DynamicSegmentTree<M>(long long n)` | 長さ `n`、全て `e()` | $O(1)$ |
| `void set(long long p, S x)` | $a_p = x$ | $O(\log n)$ |
| `S get(long long p)` | $a_p$ | $O(\log n)$ |
| `S prod(long long l, long long r)` | $a_l \cdots a_{r-1}$ | $O(\log n)$ |
| `S all_prod()` | 全体の積 | $O(1)$ |

## 注意

- 非可換なモノイドでもよい。
- 区間作用が必要なら [DynamicLazySegmentTree](dynamic_lazy_segment_tree.hpp) を使う。
