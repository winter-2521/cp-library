---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/static_range_sum.test.cpp
    title: test/static_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/cumulative_sum.test.cpp
    title: test/unittest/cumulative_sum.test.cpp
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
    \ 3 \"data_structure/cumulative_sum.hpp\"\n\n// 1 \u6B21\u5143\u7D2F\u7A4D\u548C\
    \uFF0E\u533A\u9593\u548C\u3092 O(1) \u3067\u6C42\u3081\u308B\ntemplate <class\
    \ T>\nstruct CumulativeSum {\n    // s[i] = a[0] + ... + a[i-1]\n    vector<T>\
    \ s;\n\n    CumulativeSum() : s(1, T(0)) {}\n\n    template <class U>\n    CumulativeSum(const\
    \ vector<U> &a) : s(a.size() + 1) {\n        s[0] = T(0);\n        for (size_t\
    \ i = 0; i < a.size(); i++) s[i + 1] = s[i] + T(a[i]);\n    }\n\n    int size()\
    \ const { return int(s.size()) - 1; }\n\n    // \u672B\u5C3E\u306B x \u3092\u8FFD\
    \u52A0\n    void push_back(const T &x) { s.push_back(s.back() + x); }\n\n    //\
    \ a[0] + ... + a[r-1]\n    T prefix(int r) const { return s[r]; }\n\n    // a[l]\
    \ + ... + a[r-1]\n    T sum(int l, int r) const { return s[r] - s[l]; }\n};\n\n\
    // 2 \u6B21\u5143\u7D2F\u7A4D\u548C\uFF0E\u9577\u65B9\u5F62\u9818\u57DF\u306E\u548C\
    \u3092 O(1) \u3067\u6C42\u3081\u308B\ntemplate <class T>\nstruct CumulativeSum2D\
    \ {\n    int h, w;\n    // s[(i * (w + 1)) + j] = \u5DE6\u4E0A [0, i) x [0, j)\
    \ \u306E\u548C\n    vector<T> s;\n\n    template <class U>\n    CumulativeSum2D(const\
    \ vector<vector<U>> &a) : h(a.size()), w(a.empty() ? 0 : a[0].size()), s((h +\
    \ 1) * (w + 1), T(0)) {\n        for (int i = 0; i < h; i++) {\n            T\
    \ row = T(0);\n            for (int j = 0; j < w; j++) {\n                row\
    \ += T(a[i][j]);\n                s[(i + 1) * (w + 1) + j + 1] = s[i * (w + 1)\
    \ + j + 1] + row;\n            }\n        }\n    }\n\n    // \u884C [x1, x2) x\
    \ \u5217 [y1, y2) \u306E\u548C\n    T sum(int x1, int y1, int x2, int y2) const\
    \ {\n        return s[x2 * (w + 1) + y2] - s[x1 * (w + 1) + y2] - s[x2 * (w +\
    \ 1) + y1] + s[x1 * (w + 1) + y1];\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// 1 \u6B21\u5143\u7D2F\u7A4D\
    \u548C\uFF0E\u533A\u9593\u548C\u3092 O(1) \u3067\u6C42\u3081\u308B\ntemplate <class\
    \ T>\nstruct CumulativeSum {\n    // s[i] = a[0] + ... + a[i-1]\n    vector<T>\
    \ s;\n\n    CumulativeSum() : s(1, T(0)) {}\n\n    template <class U>\n    CumulativeSum(const\
    \ vector<U> &a) : s(a.size() + 1) {\n        s[0] = T(0);\n        for (size_t\
    \ i = 0; i < a.size(); i++) s[i + 1] = s[i] + T(a[i]);\n    }\n\n    int size()\
    \ const { return int(s.size()) - 1; }\n\n    // \u672B\u5C3E\u306B x \u3092\u8FFD\
    \u52A0\n    void push_back(const T &x) { s.push_back(s.back() + x); }\n\n    //\
    \ a[0] + ... + a[r-1]\n    T prefix(int r) const { return s[r]; }\n\n    // a[l]\
    \ + ... + a[r-1]\n    T sum(int l, int r) const { return s[r] - s[l]; }\n};\n\n\
    // 2 \u6B21\u5143\u7D2F\u7A4D\u548C\uFF0E\u9577\u65B9\u5F62\u9818\u57DF\u306E\u548C\
    \u3092 O(1) \u3067\u6C42\u3081\u308B\ntemplate <class T>\nstruct CumulativeSum2D\
    \ {\n    int h, w;\n    // s[(i * (w + 1)) + j] = \u5DE6\u4E0A [0, i) x [0, j)\
    \ \u306E\u548C\n    vector<T> s;\n\n    template <class U>\n    CumulativeSum2D(const\
    \ vector<vector<U>> &a) : h(a.size()), w(a.empty() ? 0 : a[0].size()), s((h +\
    \ 1) * (w + 1), T(0)) {\n        for (int i = 0; i < h; i++) {\n            T\
    \ row = T(0);\n            for (int j = 0; j < w; j++) {\n                row\
    \ += T(a[i][j]);\n                s[(i + 1) * (w + 1) + j + 1] = s[i * (w + 1)\
    \ + j + 1] + row;\n            }\n        }\n    }\n\n    // \u884C [x1, x2) x\
    \ \u5217 [y1, y2) \u306E\u548C\n    T sum(int x1, int y1, int x2, int y2) const\
    \ {\n        return s[x2 * (w + 1) + y2] - s[x1 * (w + 1) + y2] - s[x2 * (w +\
    \ 1) + y1] + s[x1 * (w + 1) + y1];\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/cumulative_sum.hpp
  requiredBy: []
  timestamp: '2026-10-12 10:14:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/static_range_sum.test.cpp
  - test/unittest/cumulative_sum.test.cpp
documentation_of: data_structure/cumulative_sum.hpp
layout: document
title: "\u7D2F\u7A4D\u548C (Cumulative Sum)"
---

## 概要

静的な配列の区間和を $O(1)$ で求める。1 次元版 `CumulativeSum` と 2 次元版 `CumulativeSum2D` がある。
2 次元版は 1 本の配列にまとめて持つ（`vector<vector<T>>` より速い）。

## 使い方

```cpp
vector<int> a = {3, 1, 4, 1, 5};
CumulativeSum<long long> cs(a);  // 和の型 T を指定する (要素の型 U は T に変換できればよい)
cs.sum(1, 4);                    // a[1] + a[2] + a[3] = 6
cs.prefix(3);                    // a[0] + a[1] + a[2] = 8
cs.push_back(9);                 // 末尾に追加

vector<vector<int>> g(h, vector<int>(w));
CumulativeSum2D<long long> cs2(g);
cs2.sum(x1, y1, x2, y2);         // 行 [x1, x2) × 列 [y1, y2) の和
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `CumulativeSum<T>(const vector<U> &a)` | 配列 `a` から構築 | $O(n)$ |
| `T sum(int l, int r)` | $a_l + \cdots + a_{r-1}$ | $O(1)$ |
| `T prefix(int r)` | $a_0 + \cdots + a_{r-1}$ | $O(1)$ |
| `void push_back(T x)` | 末尾に `x` を追加 | ならし $O(1)$ |
| `int size()` | 要素数 | $O(1)$ |
| `CumulativeSum2D<T>(const vector<vector<U>> &a)` | $h \times w$ の配列から構築 | $O(hw)$ |
| `T sum(int x1, int y1, int x2, int y2)` | $[x_1, x_2) \times [y_1, y_2)$ の和 | $O(1)$ |

## 注意

- 区間は半開区間。`l == r` なら 0 を返す。
- `T` は `+`, `-` が使える型（加法群）であればよい。modint でも使える。
- 和がオーバーフローしないよう `T` は十分大きな型にすること（`int` の配列でも和は `long long` にするなど）。
