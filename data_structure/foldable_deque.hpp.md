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
    path: test/deque_operate_all_composite.test.cpp
    title: test/deque_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/foldable_queue.test.cpp
    title: test/unittest/foldable_queue.test.cpp
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
    \    }\n    return r;\n}\n#line 4 \"data_structure/foldable_deque.hpp\"\n\n//\
    \ \u5168\u4F53\u306E\u7A4D\u304C\u53D6\u308C\u308B\u4E21\u7AEF\u30AD\u30E5\u30FC\
    \n// M \u306F\u30E2\u30CE\u30A4\u30C9 (\u975E\u53EF\u63DB\u3067\u3082\u3088\u3044\
    )\uFF0E\u7A4D\u306F\u300C\u5148\u982D\u304B\u3089\u672B\u5C3E\u306E\u9806\u300D\
    = op(front, ..., back)\n// \u5148\u982D\u5074\u30FB\u672B\u5C3E\u5074\u306E 2\
    \ \u672C\u306E\u30B9\u30BF\u30C3\u30AF\u306B\u7D2F\u7A4D\u7A4D\u3092\u7A4D\u3080\
    \uFF0E\u7247\u65B9\u304C\u7A7A\u306E\u3068\u304D\u306B\u53D6\u308A\u51FA\u3059\
    \u3068\uFF0C\u3082\u3046\u7247\u65B9\u3092\u534A\u5206\u306B\u5206\u3051\u3066\
    \u4F5C\u308A\u76F4\u3059 (\u306A\u3089\u3057 O(1))\ntemplate <class M>\nstruct\
    \ FoldableDeque {\n    using S = typename M::S;\n    // fv.back() \u304C\u5148\
    \u982D\uFF0Efp[i] = op(fv[i], fv[i-1], ..., fv[0])\n    // bv.back() \u304C\u672B\
    \u5C3E\uFF0Ebp[i] = op(bv[0], ..., bv[i])\n    vector<S> fv, fp, bv, bp;\n\n \
    \   FoldableDeque() = default;\n\n    int size() const { return fv.size() + bv.size();\
    \ }\n    bool empty() const { return fv.empty() && bv.empty(); }\n    void reserve(int\
    \ n) { fv.reserve(n), fp.reserve(n), bv.reserve(n), bp.reserve(n); }\n    void\
    \ clear() { fv.clear(), fp.clear(), bv.clear(), bp.clear(); }\n\n    void push_front(const\
    \ S &x) {\n        fp.push_back(fv.empty() ? x : M::op(x, fp.back()));\n     \
    \   fv.push_back(x);\n    }\n    void push_back(const S &x) {\n        bp.push_back(bv.empty()\
    \ ? x : M::op(bp.back(), x));\n        bv.push_back(x);\n    }\n\n    // \u5148\
    \u982D\u3092\u524A\u9664 (\u7A7A\u3067\u306A\u3044\u3053\u3068)\n    void pop_front()\
    \ {\n        if (fv.empty()) rebalance(true);\n        fv.pop_back(), fp.pop_back();\n\
    \    }\n    // \u672B\u5C3E\u3092\u524A\u9664 (\u7A7A\u3067\u306A\u3044\u3053\u3068\
    )\n    void pop_back() {\n        if (bv.empty()) rebalance(false);\n        bv.pop_back(),\
    \ bp.pop_back();\n    }\n\n    // \u5148\u982D / \u672B\u5C3E (\u7A7A\u3067\u306A\
    \u3044\u3053\u3068)\n    S front() const { return fv.empty() ? bv.front() : fv.back();\
    \ }\n    S back() const { return bv.empty() ? fv.front() : bv.back(); }\n\n  \
    \  // op(\u5148\u982D, ..., \u672B\u5C3E)\uFF0E\u7A7A\u306A\u3089 e()\n    S all_prod()\
    \ const {\n        if (fv.empty()) return bv.empty() ? M::e() : bp.back();\n \
    \       if (bv.empty()) return fp.back();\n        return M::op(fp.back(), bp.back());\n\
    \    }\n\n  private:\n    // to_front: \u5148\u982D\u5074\u304C\u7A7A\u306B\u306A\
    \u3063\u305F\u306E\u3067\u672B\u5C3E\u5074\u304B\u3089\u5206\u3051\u308B (\u9006\
    \u3082\u540C\u69D8)\n    void rebalance(bool to_front) {\n        // \u5168\u8981\
    \u7D20\u3092\u5148\u982D\u304B\u3089\u672B\u5C3E\u306E\u9806\u306B\u4E26\u3079\
    \u308B\n        vector<S> all;\n        all.reserve(fv.size() + bv.size());\n\
    \        for (int i = (int)fv.size() - 1; i >= 0; i--) all.push_back(fv[i]);\n\
    \        for (auto &x : bv) all.push_back(x);\n        int m = all.size();\n \
    \       // \u53D6\u308A\u51FA\u3059\u5074\u306B\u5C11\u306A\u304F\u3068\u3082\
    \ 1 \u500B\u5165\u308B\u3088\u3046\u306B\u5206\u3051\u308B\n        int k = to_front\
    \ ? (m + 1) / 2 : m / 2;  // \u5148\u982D\u5074\u306B\u5165\u308C\u308B\u500B\u6570\
    \n        clear();\n        for (int i = k - 1; i >= 0; i--) push_front(all[i]);\n\
    \        for (int i = k; i < m; i++) push_back(all[i]);\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"../algebra/monoid.hpp\"\
    \n\n// \u5168\u4F53\u306E\u7A4D\u304C\u53D6\u308C\u308B\u4E21\u7AEF\u30AD\u30E5\
    \u30FC\n// M \u306F\u30E2\u30CE\u30A4\u30C9 (\u975E\u53EF\u63DB\u3067\u3082\u3088\
    \u3044)\uFF0E\u7A4D\u306F\u300C\u5148\u982D\u304B\u3089\u672B\u5C3E\u306E\u9806\
    \u300D= op(front, ..., back)\n// \u5148\u982D\u5074\u30FB\u672B\u5C3E\u5074\u306E\
    \ 2 \u672C\u306E\u30B9\u30BF\u30C3\u30AF\u306B\u7D2F\u7A4D\u7A4D\u3092\u7A4D\u3080\
    \uFF0E\u7247\u65B9\u304C\u7A7A\u306E\u3068\u304D\u306B\u53D6\u308A\u51FA\u3059\
    \u3068\uFF0C\u3082\u3046\u7247\u65B9\u3092\u534A\u5206\u306B\u5206\u3051\u3066\
    \u4F5C\u308A\u76F4\u3059 (\u306A\u3089\u3057 O(1))\ntemplate <class M>\nstruct\
    \ FoldableDeque {\n    using S = typename M::S;\n    // fv.back() \u304C\u5148\
    \u982D\uFF0Efp[i] = op(fv[i], fv[i-1], ..., fv[0])\n    // bv.back() \u304C\u672B\
    \u5C3E\uFF0Ebp[i] = op(bv[0], ..., bv[i])\n    vector<S> fv, fp, bv, bp;\n\n \
    \   FoldableDeque() = default;\n\n    int size() const { return fv.size() + bv.size();\
    \ }\n    bool empty() const { return fv.empty() && bv.empty(); }\n    void reserve(int\
    \ n) { fv.reserve(n), fp.reserve(n), bv.reserve(n), bp.reserve(n); }\n    void\
    \ clear() { fv.clear(), fp.clear(), bv.clear(), bp.clear(); }\n\n    void push_front(const\
    \ S &x) {\n        fp.push_back(fv.empty() ? x : M::op(x, fp.back()));\n     \
    \   fv.push_back(x);\n    }\n    void push_back(const S &x) {\n        bp.push_back(bv.empty()\
    \ ? x : M::op(bp.back(), x));\n        bv.push_back(x);\n    }\n\n    // \u5148\
    \u982D\u3092\u524A\u9664 (\u7A7A\u3067\u306A\u3044\u3053\u3068)\n    void pop_front()\
    \ {\n        if (fv.empty()) rebalance(true);\n        fv.pop_back(), fp.pop_back();\n\
    \    }\n    // \u672B\u5C3E\u3092\u524A\u9664 (\u7A7A\u3067\u306A\u3044\u3053\u3068\
    )\n    void pop_back() {\n        if (bv.empty()) rebalance(false);\n        bv.pop_back(),\
    \ bp.pop_back();\n    }\n\n    // \u5148\u982D / \u672B\u5C3E (\u7A7A\u3067\u306A\
    \u3044\u3053\u3068)\n    S front() const { return fv.empty() ? bv.front() : fv.back();\
    \ }\n    S back() const { return bv.empty() ? fv.front() : bv.back(); }\n\n  \
    \  // op(\u5148\u982D, ..., \u672B\u5C3E)\uFF0E\u7A7A\u306A\u3089 e()\n    S all_prod()\
    \ const {\n        if (fv.empty()) return bv.empty() ? M::e() : bp.back();\n \
    \       if (bv.empty()) return fp.back();\n        return M::op(fp.back(), bp.back());\n\
    \    }\n\n  private:\n    // to_front: \u5148\u982D\u5074\u304C\u7A7A\u306B\u306A\
    \u3063\u305F\u306E\u3067\u672B\u5C3E\u5074\u304B\u3089\u5206\u3051\u308B (\u9006\
    \u3082\u540C\u69D8)\n    void rebalance(bool to_front) {\n        // \u5168\u8981\
    \u7D20\u3092\u5148\u982D\u304B\u3089\u672B\u5C3E\u306E\u9806\u306B\u4E26\u3079\
    \u308B\n        vector<S> all;\n        all.reserve(fv.size() + bv.size());\n\
    \        for (int i = (int)fv.size() - 1; i >= 0; i--) all.push_back(fv[i]);\n\
    \        for (auto &x : bv) all.push_back(x);\n        int m = all.size();\n \
    \       // \u53D6\u308A\u51FA\u3059\u5074\u306B\u5C11\u306A\u304F\u3068\u3082\
    \ 1 \u500B\u5165\u308B\u3088\u3046\u306B\u5206\u3051\u308B\n        int k = to_front\
    \ ? (m + 1) / 2 : m / 2;  // \u5148\u982D\u5074\u306B\u5165\u308C\u308B\u500B\u6570\
    \n        clear();\n        for (int i = k - 1; i >= 0; i--) push_front(all[i]);\n\
    \        for (int i = k; i < m; i++) push_back(all[i]);\n    }\n};\n"
  dependsOn:
  - template.hpp
  - algebra/monoid.hpp
  - template.hpp
  isVerificationFile: false
  path: data_structure/foldable_deque.hpp
  requiredBy: []
  timestamp: '2026-10-14 23:17:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/foldable_queue.test.cpp
  - test/deque_operate_all_composite.test.cpp
documentation_of: data_structure/foldable_deque.hpp
layout: document
title: "\u5168\u4F53\u306E\u7A4D\u304C\u53D6\u308C\u308B\u4E21\u7AEF\u30AD\u30E5\u30FC\
  \ (Foldable Deque)"
---

## 概要

モノイド `M` の列を両端キューとして持ち、両端への追加・両端の削除・**全体の積** をならし $O(1)$ で処理する。非可換なモノイドでもよい。積は「先頭から末尾の順」。

先頭側・末尾側の 2 本のスタックにそれぞれ累積積を積む。片方が空のときにそちら側から削除が来たら、もう片方の要素を **半分ずつ** に分けて両方作り直す。半分に分けるので、作り直しにかかる時間は直前の作り直し以降の操作回数でならせて、ならし $O(1)$ になる（全部移すと、両端から交互に削除されたとき毎回 $O(n)$ かかってしまう）。

## 使い方

```cpp
FoldableDeque<MonoidAffine<mint>> deq;
deq.reserve(q);
deq.push_front(f); deq.push_back(f);
deq.pop_front(); deq.pop_back();
deq.front(); deq.back();
deq.all_prod()(x);    // f_{back}(...f_{front}(x))
deq.size(); deq.empty(); deq.clear();
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `void push_front(S x)` / `void push_back(S x)` | 追加 | $O(1)$ |
| `void pop_front()` / `void pop_back()` | 削除 | ならし $O(1)$ |
| `S front()` / `S back()` | 先頭 / 末尾 | $O(1)$ |
| `S all_prod()` | 先頭から末尾の順の積（空なら `e()`） | $O(1)$ |
| `int size()` / `bool empty()` / `void clear()` / `void reserve(int n)` | | $O(1)$ |

## 注意

- 削除・`front` / `back` は空でないときに呼ぶこと。
- 片側からしか削除しないなら [FoldableQueue](foldable_queue.hpp) の方が少し速い。
