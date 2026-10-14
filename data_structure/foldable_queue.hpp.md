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
    path: test/queue_operate_all_composite.test.cpp
    title: test/queue_operate_all_composite.test.cpp
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
    \    }\n    return r;\n}\n#line 4 \"data_structure/foldable_queue.hpp\"\n\n//\
    \ \u5168\u4F53\u306E\u7A4D\u304C\u53D6\u308C\u308B\u30AD\u30E5\u30FC (Sliding\
    \ Window Aggregation)\n// M \u306F\u30E2\u30CE\u30A4\u30C9 (\u975E\u53EF\u63DB\
    \u3067\u3082\u3088\u3044)\uFF0E\u7A4D\u306F\u300C\u5148\u982D\u304B\u3089\u672B\
    \u5C3E\u306E\u9806\u300D= op(front, ..., back)\n// 2 \u672C\u306E\u30B9\u30BF\u30C3\
    \u30AF\u3067\u6301\u3064\uFF0Efront \u5074\u306F\u300C\u305D\u306E\u8981\u7D20\
    \u304B\u3089 front \u5074\u306E\u5E95\u307E\u3067\u306E\u7A4D\u300D\u3092\u7A4D\
    \u3093\u3067\u304A\u304F\ntemplate <class M>\nstruct FoldableQueue {\n    using\
    \ S = typename M::S;\n    vector<S> front_val, front_prod;  // front_val.back()\
    \ \u304C\u5148\u982D\uFF0Efront_prod[i] = op(front_val[i], ..., front_val[0])\n\
    \    vector<S> back_val;               // \u672B\u5C3E\u5074 (push \u9806)\n \
    \   S back_prod = M::e();             // back_val \u5168\u4F53\u306E\u7A4D\n\n\
    \    FoldableQueue() = default;\n\n    int size() const { return front_val.size()\
    \ + back_val.size(); }\n    bool empty() const { return front_val.empty() && back_val.empty();\
    \ }\n    void reserve(int n) { front_val.reserve(n), front_prod.reserve(n), back_val.reserve(n);\
    \ }\n    void clear() { front_val.clear(), front_prod.clear(), back_val.clear(),\
    \ back_prod = M::e(); }\n\n    // \u672B\u5C3E\u306B x \u3092\u8FFD\u52A0\n  \
    \  void push(const S &x) {\n        back_val.push_back(x);\n        back_prod\
    \ = M::op(back_prod, x);\n    }\n\n    // \u5148\u982D\u3092\u524A\u9664 (\u7A7A\
    \u3067\u306A\u3044\u3053\u3068)\n    void pop() {\n        if (front_val.empty())\
    \ move_back_to_front();\n        front_val.pop_back();\n        front_prod.pop_back();\n\
    \    }\n\n    // \u5148\u982D (\u7A7A\u3067\u306A\u3044\u3053\u3068)\n    S front()\
    \ {\n        if (front_val.empty()) move_back_to_front();\n        return front_val.back();\n\
    \    }\n\n    // op(\u5148\u982D, ..., \u672B\u5C3E)\uFF0E\u7A7A\u306A\u3089 e()\n\
    \    S all_prod() const {\n        if (front_prod.empty()) return back_prod;\n\
    \        return M::op(front_prod.back(), back_prod);\n    }\n\n  private:\n  \
    \  void move_back_to_front() {\n        S acc = M::e();\n        for (int i =\
    \ (int)back_val.size() - 1; i >= 0; i--) {\n            acc = M::op(back_val[i],\
    \ acc);\n            front_val.push_back(back_val[i]);\n            front_prod.push_back(acc);\n\
    \        }\n        back_val.clear();\n        back_prod = M::e();\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"../algebra/monoid.hpp\"\
    \n\n// \u5168\u4F53\u306E\u7A4D\u304C\u53D6\u308C\u308B\u30AD\u30E5\u30FC (Sliding\
    \ Window Aggregation)\n// M \u306F\u30E2\u30CE\u30A4\u30C9 (\u975E\u53EF\u63DB\
    \u3067\u3082\u3088\u3044)\uFF0E\u7A4D\u306F\u300C\u5148\u982D\u304B\u3089\u672B\
    \u5C3E\u306E\u9806\u300D= op(front, ..., back)\n// 2 \u672C\u306E\u30B9\u30BF\u30C3\
    \u30AF\u3067\u6301\u3064\uFF0Efront \u5074\u306F\u300C\u305D\u306E\u8981\u7D20\
    \u304B\u3089 front \u5074\u306E\u5E95\u307E\u3067\u306E\u7A4D\u300D\u3092\u7A4D\
    \u3093\u3067\u304A\u304F\ntemplate <class M>\nstruct FoldableQueue {\n    using\
    \ S = typename M::S;\n    vector<S> front_val, front_prod;  // front_val.back()\
    \ \u304C\u5148\u982D\uFF0Efront_prod[i] = op(front_val[i], ..., front_val[0])\n\
    \    vector<S> back_val;               // \u672B\u5C3E\u5074 (push \u9806)\n \
    \   S back_prod = M::e();             // back_val \u5168\u4F53\u306E\u7A4D\n\n\
    \    FoldableQueue() = default;\n\n    int size() const { return front_val.size()\
    \ + back_val.size(); }\n    bool empty() const { return front_val.empty() && back_val.empty();\
    \ }\n    void reserve(int n) { front_val.reserve(n), front_prod.reserve(n), back_val.reserve(n);\
    \ }\n    void clear() { front_val.clear(), front_prod.clear(), back_val.clear(),\
    \ back_prod = M::e(); }\n\n    // \u672B\u5C3E\u306B x \u3092\u8FFD\u52A0\n  \
    \  void push(const S &x) {\n        back_val.push_back(x);\n        back_prod\
    \ = M::op(back_prod, x);\n    }\n\n    // \u5148\u982D\u3092\u524A\u9664 (\u7A7A\
    \u3067\u306A\u3044\u3053\u3068)\n    void pop() {\n        if (front_val.empty())\
    \ move_back_to_front();\n        front_val.pop_back();\n        front_prod.pop_back();\n\
    \    }\n\n    // \u5148\u982D (\u7A7A\u3067\u306A\u3044\u3053\u3068)\n    S front()\
    \ {\n        if (front_val.empty()) move_back_to_front();\n        return front_val.back();\n\
    \    }\n\n    // op(\u5148\u982D, ..., \u672B\u5C3E)\uFF0E\u7A7A\u306A\u3089 e()\n\
    \    S all_prod() const {\n        if (front_prod.empty()) return back_prod;\n\
    \        return M::op(front_prod.back(), back_prod);\n    }\n\n  private:\n  \
    \  void move_back_to_front() {\n        S acc = M::e();\n        for (int i =\
    \ (int)back_val.size() - 1; i >= 0; i--) {\n            acc = M::op(back_val[i],\
    \ acc);\n            front_val.push_back(back_val[i]);\n            front_prod.push_back(acc);\n\
    \        }\n        back_val.clear();\n        back_prod = M::e();\n    }\n};\n"
  dependsOn:
  - template.hpp
  - algebra/monoid.hpp
  - template.hpp
  isVerificationFile: false
  path: data_structure/foldable_queue.hpp
  requiredBy: []
  timestamp: '2026-10-14 23:17:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/queue_operate_all_composite.test.cpp
  - test/unittest/foldable_queue.test.cpp
documentation_of: data_structure/foldable_queue.hpp
layout: document
title: "\u5168\u4F53\u306E\u7A4D\u304C\u53D6\u308C\u308B\u30AD\u30E5\u30FC (Foldable\
  \ Queue / SWAG)"
---

## 概要

モノイド `M` の列をキューとして持ち、末尾への追加・先頭の削除・**全体の積** をならし $O(1)$ で処理する（Sliding Window Aggregation）。非可換なモノイドでもよい。積は「先頭から末尾の順」$a_{\text{front}} \cdots a_{\text{back}}$。

スタックを 2 本使う。

- 末尾側のスタックには追加された順に積み、その全体の積を 1 つだけ持つ。
- 先頭側のスタックには「その要素から先頭側スタックの底までの積」を積む。先頭側が空のときに削除が来たら、末尾側を全部移し替えて累積積を作り直す。

各要素は 1 回しか移し替えられないので、ならし $O(1)$。

## 使い方

```cpp
FoldableQueue<MonoidAffine<mint>> que;
que.reserve(q);
que.push(f);          // 末尾に追加
que.pop();            // 先頭を削除
que.front();          // 先頭
que.all_prod()(x);    // f_{back}(...f_{front}(x))
que.size(); que.empty(); que.clear();
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `void push(S x)` | 末尾に追加 | $O(1)$ |
| `void pop()` | 先頭を削除 | ならし $O(1)$ |
| `S front()` | 先頭 | ならし $O(1)$ |
| `S all_prod()` | 先頭から末尾の順の積（空なら `e()`） | $O(1)$ |
| `int size()` / `bool empty()` / `void clear()` / `void reserve(int n)` | | $O(1)$ |

## 注意

- `pop` / `front` は空でないときに呼ぶこと。
- 両端から出し入れしたいときは [FoldableDeque](foldable_deque.hpp)。
