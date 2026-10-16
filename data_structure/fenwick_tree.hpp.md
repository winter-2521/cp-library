---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/point_add_range_sum.test.cpp
    title: test/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: test/unittest/fenwick_tree.test.cpp
    title: test/unittest/fenwick_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://github.com/winter-2521/cp-library
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
    \ 3 \"data_structure/fenwick_tree.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// Fenwick Tree (Binary Indexed Tree)\n// \u4E00\u70B9\u52A0\u7B97\u30FB\u533A\
    \u9593\u548C\u3092 O(log n) \u3067\u51E6\u7406\u3059\u308B\uFF0E\u5916\u90E8\u304B\
    \u3089\u306F 0-indexed \u3067\u6271\u3046\ntemplate <class T>\nstruct FenwickTree\
    \ {\n    int n;\n    // d[i] (1-indexed) \u306F\u533A\u9593 (i - lowbit(i), i]\
    \ \u306E\u548C\n    vector<T> d;\n\n    FenwickTree(int n = 0) : n(n), d(n + 1,\
    \ T(0)) {}\n\n    // \u914D\u5217 a \u3067 O(n) \u521D\u671F\u5316\n    FenwickTree(const\
    \ vector<T> &a) : n(a.size()), d(a.size() + 1, T(0)) {\n        for (int i = 0;\
    \ i < n; i++) d[i + 1] = a[i];\n        for (int i = 1; i <= n; i++) {\n     \
    \       int j = i + (i & -i);\n            if (j <= n) d[j] += d[i];\n       \
    \ }\n    }\n\n    int size() const { return n; }\n\n    // a[i] += x\n    void\
    \ add(int i, T x) {\n        for (i++; i <= n; i += i & -i) d[i] += x;\n    }\n\
    \n    // a[0] + ... + a[r-1]\n    T sum(int r) const {\n        T s = T(0);\n\
    \        for (; r > 0; r &= r - 1) s += d[r];\n        return s;\n    }\n\n  \
    \  // a[l] + ... + a[r-1]\n    // sum(r) - sum(l) \u3092\uFF0Cl \u3068 r \u306E\
    \u5171\u901A\u306E\u7956\u5148\u307E\u3067\u964D\u308A\u305F\u3068\u3053\u308D\
    \u3067\u6253\u3061\u5207\u3063\u3066\u8A08\u7B97\u3059\u308B\n    T sum(int l,\
    \ int r) const {\n        T s = T(0);\n        while (l < r) s += d[r], r &= r\
    \ - 1;\n        while (r < l) s -= d[l], l &= l - 1;\n        return s;\n    }\n\
    \n    // a[i]\n    T get(int i) const { return sum(i, i + 1); }\n\n    // a[i]\
    \ = x\n    void set(int i, T x) { add(i, x - get(i)); }\n\n    // a[0] + ... +\
    \ a[i] >= w \u3068\u306A\u308B\u6700\u5C0F\u306E i \u3092\u8FD4\u3059 (\u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070 n)\n    // \u5168\u8981\u7D20\u304C\u975E\u8CA0\
    \u3067\u3042\u308B\u3053\u3068\n    int lower_bound(T w) const {\n        if (w\
    \ <= T(0)) return 0;\n        int x = 0;\n        int k = 1;\n        while (k\
    \ * 2 <= n) k *= 2;\n        for (; k > 0; k >>= 1) {\n            if (x + k <=\
    \ n && d[x + k] < w) {\n                x += k;\n                w -= d[x];\n\
    \            }\n        }\n        return x;\n    }\n\n    // a[0] + ... + a[i]\
    \ > w \u3068\u306A\u308B\u6700\u5C0F\u306E i \u3092\u8FD4\u3059 (\u5B58\u5728\u3057\
    \u306A\u3051\u308C\u3070 n)\n    // \u5168\u8981\u7D20\u304C\u975E\u8CA0\u3067\
    \u3042\u308B\u3053\u3068\n    int upper_bound(T w) const {\n        int x = 0;\n\
    \        int k = 1;\n        while (k * 2 <= n) k *= 2;\n        for (; k > 0;\
    \ k >>= 1) {\n            if (x + k <= n && !(w < d[x + k])) {\n             \
    \   x += k;\n                w -= d[x];\n            }\n        }\n        return\
    \ x;\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// Fenwick Tree (Binary Indexed Tree)\n// \u4E00\u70B9\u52A0\u7B97\u30FB\u533A\
    \u9593\u548C\u3092 O(log n) \u3067\u51E6\u7406\u3059\u308B\uFF0E\u5916\u90E8\u304B\
    \u3089\u306F 0-indexed \u3067\u6271\u3046\ntemplate <class T>\nstruct FenwickTree\
    \ {\n    int n;\n    // d[i] (1-indexed) \u306F\u533A\u9593 (i - lowbit(i), i]\
    \ \u306E\u548C\n    vector<T> d;\n\n    FenwickTree(int n = 0) : n(n), d(n + 1,\
    \ T(0)) {}\n\n    // \u914D\u5217 a \u3067 O(n) \u521D\u671F\u5316\n    FenwickTree(const\
    \ vector<T> &a) : n(a.size()), d(a.size() + 1, T(0)) {\n        for (int i = 0;\
    \ i < n; i++) d[i + 1] = a[i];\n        for (int i = 1; i <= n; i++) {\n     \
    \       int j = i + (i & -i);\n            if (j <= n) d[j] += d[i];\n       \
    \ }\n    }\n\n    int size() const { return n; }\n\n    // a[i] += x\n    void\
    \ add(int i, T x) {\n        for (i++; i <= n; i += i & -i) d[i] += x;\n    }\n\
    \n    // a[0] + ... + a[r-1]\n    T sum(int r) const {\n        T s = T(0);\n\
    \        for (; r > 0; r &= r - 1) s += d[r];\n        return s;\n    }\n\n  \
    \  // a[l] + ... + a[r-1]\n    // sum(r) - sum(l) \u3092\uFF0Cl \u3068 r \u306E\
    \u5171\u901A\u306E\u7956\u5148\u307E\u3067\u964D\u308A\u305F\u3068\u3053\u308D\
    \u3067\u6253\u3061\u5207\u3063\u3066\u8A08\u7B97\u3059\u308B\n    T sum(int l,\
    \ int r) const {\n        T s = T(0);\n        while (l < r) s += d[r], r &= r\
    \ - 1;\n        while (r < l) s -= d[l], l &= l - 1;\n        return s;\n    }\n\
    \n    // a[i]\n    T get(int i) const { return sum(i, i + 1); }\n\n    // a[i]\
    \ = x\n    void set(int i, T x) { add(i, x - get(i)); }\n\n    // a[0] + ... +\
    \ a[i] >= w \u3068\u306A\u308B\u6700\u5C0F\u306E i \u3092\u8FD4\u3059 (\u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070 n)\n    // \u5168\u8981\u7D20\u304C\u975E\u8CA0\
    \u3067\u3042\u308B\u3053\u3068\n    int lower_bound(T w) const {\n        if (w\
    \ <= T(0)) return 0;\n        int x = 0;\n        int k = 1;\n        while (k\
    \ * 2 <= n) k *= 2;\n        for (; k > 0; k >>= 1) {\n            if (x + k <=\
    \ n && d[x + k] < w) {\n                x += k;\n                w -= d[x];\n\
    \            }\n        }\n        return x;\n    }\n\n    // a[0] + ... + a[i]\
    \ > w \u3068\u306A\u308B\u6700\u5C0F\u306E i \u3092\u8FD4\u3059 (\u5B58\u5728\u3057\
    \u306A\u3051\u308C\u3070 n)\n    // \u5168\u8981\u7D20\u304C\u975E\u8CA0\u3067\
    \u3042\u308B\u3053\u3068\n    int upper_bound(T w) const {\n        int x = 0;\n\
    \        int k = 1;\n        while (k * 2 <= n) k *= 2;\n        for (; k > 0;\
    \ k >>= 1) {\n            if (x + k <= n && !(w < d[x + k])) {\n             \
    \   x += k;\n                w -= d[x];\n            }\n        }\n        return\
    \ x;\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unittest/fenwick_tree.test.cpp
  - test/point_add_range_sum.test.cpp
documentation_of: data_structure/fenwick_tree.hpp
layout: document
title: Fenwick Tree (Binary Indexed Tree)
---

## 概要

一点加算と区間和を $O(\log n)$ で処理する。外部からは 0-indexed で扱う。

- 配列からの構築は $O(n)$。
- `sum(l, r)` は `sum(r) - sum(l)` を 2 回計算するのではなく、$l, r$ から lowbit を消していって一致したところで打ち切るので、短い区間ほど速い。
- 全要素が非負なら、累積和に対する二分探索 (`lower_bound` / `upper_bound`) が $O(\log n)$ でできる。座標圧縮した値の個数を持てば「$k$ 番目に小さい値」が求まる。

## 使い方

```cpp
FenwickTree<long long> bit(n);   // 全て 0 で初期化
FenwickTree<long long> bit2(a);  // vector<long long> a で初期化
bit.add(i, x);                   // a[i] += x
bit.sum(l, r);                   // a[l] + ... + a[r-1]
bit.sum(r);                      // a[0] + ... + a[r-1]
bit.get(i);                      // a[i]
bit.set(i, x);                   // a[i] = x
bit.lower_bound(w);              // a[0] + ... + a[i] >= w となる最小の i
bit.upper_bound(w);              // a[0] + ... + a[i] >  w となる最小の i
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `FenwickTree(int n)` | 長さ `n`、全て 0 で初期化 | $O(n)$ |
| `FenwickTree(const vector<T> &a)` | 配列 `a` で初期化 | $O(n)$ |
| `void add(int i, T x)` | $a_i \mathrel{+}= x$ | $O(\log n)$ |
| `T sum(int r)` | $a_0 + \cdots + a_{r-1}$ | $O(\log n)$ |
| `T sum(int l, int r)` | $a_l + \cdots + a_{r-1}$ | $O(\log n)$ |
| `T get(int i)` | $a_i$ | $O(\log n)$ |
| `void set(int i, T x)` | $a_i = x$ | $O(\log n)$ |
| `int lower_bound(T w)` | $a_0 + \cdots + a_i \ge w$ となる最小の $i$（なければ $n$）。$w \le 0$ なら 0 | $O(\log n)$ |
| `int upper_bound(T w)` | $a_0 + \cdots + a_i > w$ となる最小の $i$（なければ $n$） | $O(\log n)$ |
| `int size()` | 要素数 | $O(1)$ |

## 注意

- `T` は `+=`, `-=` が使える型（可換群）であればよい。modint でも使える。
- `lower_bound` / `upper_bound` は **全要素が非負** のときのみ正しい。
