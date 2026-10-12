---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/staticrmq_sparse_table.test.cpp
    title: test/staticrmq_sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/static_rmq.test.cpp
    title: test/unittest/static_rmq.test.cpp
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
    \ 3 \"data_structure/sparse_table.hpp\"\n\n// Sparse Table\n// \u51AA\u7B49\u306A\
    \u6F14\u7B97 (min, max, gcd, and, or \u306A\u3069) \u306E\u533A\u9593\u30AF\u30A8\
    \u30EA\u3092\uFF0C\u69CB\u7BC9 O(n log n)\u30FB\u30AF\u30A8\u30EA O(1) \u3067\u51E6\
    \u7406\u3059\u308B\n// SparseTable st(a, [](int x, int y) { return min(x, y);\
    \ });\ntemplate <class T, class Op>\nstruct SparseTable {\n    int n, lg;\n  \
    \  Op op;\n    // t[k * n + i] = op(a[i], ..., a[i + 2^k - 1])  (1 \u672C\u306E\
    \u914D\u5217\u306B\u307E\u3068\u3081\u3066\u30AD\u30E3\u30C3\u30B7\u30E5\u52B9\
    \u7387\u3092\u4E0A\u3052\u308B)\n    vector<T> t;\n\n    SparseTable(const vector<T>\
    \ &a, Op op) : n(a.size()), op(op) {\n        lg = 1;\n        while ((1 << lg)\
    \ <= n) lg++;\n        t.resize((size_t)lg * max(n, 1));\n        copy(a.begin(),\
    \ a.end(), t.begin());\n        for (int k = 1; k < lg; k++) {\n            const\
    \ T *src = t.data() + (size_t)(k - 1) * n;\n            T *dst = t.data() + (size_t)k\
    \ * n;\n            int half = 1 << (k - 1);\n            for (int i = 0; i +\
    \ (1 << k) <= n; i++) dst[i] = op(src[i], src[i + half]);\n        }\n    }\n\n\
    \    // op(a[l], ..., a[r-1])\uFF0El < r \u3067\u3042\u308B\u3053\u3068\n    T\
    \ prod(int l, int r) const {\n        int k = 31 - __builtin_clz(r - l);\n   \
    \     return op(t[(size_t)k * n + l], t[(size_t)k * n + r - (1 << k)]);\n    }\n\
    };\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// Sparse Table\n// \u51AA\u7B49\
    \u306A\u6F14\u7B97 (min, max, gcd, and, or \u306A\u3069) \u306E\u533A\u9593\u30AF\
    \u30A8\u30EA\u3092\uFF0C\u69CB\u7BC9 O(n log n)\u30FB\u30AF\u30A8\u30EA O(1) \u3067\
    \u51E6\u7406\u3059\u308B\n// SparseTable st(a, [](int x, int y) { return min(x,\
    \ y); });\ntemplate <class T, class Op>\nstruct SparseTable {\n    int n, lg;\n\
    \    Op op;\n    // t[k * n + i] = op(a[i], ..., a[i + 2^k - 1])  (1 \u672C\u306E\
    \u914D\u5217\u306B\u307E\u3068\u3081\u3066\u30AD\u30E3\u30C3\u30B7\u30E5\u52B9\
    \u7387\u3092\u4E0A\u3052\u308B)\n    vector<T> t;\n\n    SparseTable(const vector<T>\
    \ &a, Op op) : n(a.size()), op(op) {\n        lg = 1;\n        while ((1 << lg)\
    \ <= n) lg++;\n        t.resize((size_t)lg * max(n, 1));\n        copy(a.begin(),\
    \ a.end(), t.begin());\n        for (int k = 1; k < lg; k++) {\n            const\
    \ T *src = t.data() + (size_t)(k - 1) * n;\n            T *dst = t.data() + (size_t)k\
    \ * n;\n            int half = 1 << (k - 1);\n            for (int i = 0; i +\
    \ (1 << k) <= n; i++) dst[i] = op(src[i], src[i + half]);\n        }\n    }\n\n\
    \    // op(a[l], ..., a[r-1])\uFF0El < r \u3067\u3042\u308B\u3053\u3068\n    T\
    \ prod(int l, int r) const {\n        int k = 31 - __builtin_clz(r - l);\n   \
    \     return op(t[(size_t)k * n + l], t[(size_t)k * n + r - (1 << k)]);\n    }\n\
    };\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2026-10-12 10:14:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/static_rmq.test.cpp
  - test/staticrmq_sparse_table.test.cpp
documentation_of: data_structure/sparse_table.hpp
layout: document
title: Sparse Table
---

## 概要

**冪等** な結合的演算（$\min$, $\max$, $\gcd$, bitwise and / or など、$x \cdot x = x$ となるもの）の区間クエリを、構築 $O(n \log n)$・クエリ $O(1)$ で処理する。
テーブルは `vector<vector<T>>` ではなく 1 本の配列にまとめて持っている。

区間最小値・最大値だけなら、メモリが $O(n)$ で済む [`StaticRMQ`](static_rmq.hpp) の方が速い。

## 使い方

```cpp
SparseTable st(a, [](int x, int y) { return min(x, y); });      // 演算をラムダで渡す
SparseTable g(a, [](long long x, long long y) { return gcd(x, y); });
st.prod(l, r);   // op(a[l], ..., a[r-1])
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `SparseTable(const vector<T> &a, Op op)` | 配列 `a` と演算 `op` で構築 | $O(n \log n)$ |
| `T prod(int l, int r)` | $\mathrm{op}(a_l, \ldots, a_{r-1})$ | $O(1)$ |

## 注意

- `l < r` であること（空区間には対応していない）。
- 冪等でない演算（和など）には使えない（重なった 2 区間を合成するため）。
- C++17 のクラステンプレート引数推論で `T`, `Op` を推論する。明示するなら `SparseTable<int, decltype(f)> st(a, f);`。
