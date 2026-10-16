---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/static_range_frequency.test.cpp
    title: test/static_range_frequency.test.cpp
  - icon: ':x:'
    path: test/unittest/static_range_queries.test.cpp
    title: test/unittest/static_range_queries.test.cpp
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
    \ 3 \"data_structure/static_range_frequency.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u9759\u7684\u306A\u6570\u5217\u306E\u533A\u9593\u306B x \u304C\u4F55\u500B\
    \u3042\u308B\u304B (Static Range Frequency)\n// \u5024\u3054\u3068\u306B\u51FA\
    \u73FE\u4F4D\u7F6E\u3092\u6607\u9806\u306B\u4E26\u3079\u3066\u304A\u304D\uFF0C\
    x \u306E\u4F4D\u7F6E\u306E\u5217\u3067 [l, r) \u306B\u5165\u308B\u3082\u306E\u3092\
    \u4E8C\u5206\u63A2\u7D22\u3067\u6570\u3048\u308B\uFF0E\u69CB\u7BC9 O(n log n)\uFF0C\
    \u30AF\u30A8\u30EA O(log n)\ntemplate <class T>\nstruct StaticRangeFrequency {\n\
    \    int n;\n    vector<T> vals;     // \u5024\u306E\u7A2E\u985E (\u6607\u9806\
    )\n    vector<int> start;  // \u5024 vals[k] \u306E\u51FA\u73FE\u4F4D\u7F6E\u306F\
    \ pos[start[k] .. start[k+1])\n    vector<int> pos;\n\n    StaticRangeFrequency(const\
    \ vector<T> &a) : n(a.size()) {\n        vector<int> ord(n);\n        iota(ord.begin(),\
    \ ord.end(), 0);\n        stable_sort(ord.begin(), ord.end(), [&](int i, int j)\
    \ { return a[i] < a[j]; });\n        pos = ord;\n        for (int k = 0; k < n;\
    \ k++) {\n            if (k == 0 || vals.back() < a[ord[k]]) vals.push_back(a[ord[k]]),\
    \ start.push_back(k);\n        }\n        start.push_back(n);\n    }\n\n    //\
    \ a[l..r) \u306E\u4E2D\u306E x \u306E\u500B\u6570\n    int count(int l, int r,\
    \ const T &x) const {\n        int k = lower_bound(vals.begin(), vals.end(), x)\
    \ - vals.begin();\n        if (k == (int)vals.size() || x < vals[k]) return 0;\n\
    \        auto b = pos.begin() + start[k], e = pos.begin() + start[k + 1];\n  \
    \      return lower_bound(b, e, r) - lower_bound(b, e, l);\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u9759\u7684\u306A\u6570\u5217\u306E\u533A\u9593\u306B x \u304C\u4F55\u500B\
    \u3042\u308B\u304B (Static Range Frequency)\n// \u5024\u3054\u3068\u306B\u51FA\
    \u73FE\u4F4D\u7F6E\u3092\u6607\u9806\u306B\u4E26\u3079\u3066\u304A\u304D\uFF0C\
    x \u306E\u4F4D\u7F6E\u306E\u5217\u3067 [l, r) \u306B\u5165\u308B\u3082\u306E\u3092\
    \u4E8C\u5206\u63A2\u7D22\u3067\u6570\u3048\u308B\uFF0E\u69CB\u7BC9 O(n log n)\uFF0C\
    \u30AF\u30A8\u30EA O(log n)\ntemplate <class T>\nstruct StaticRangeFrequency {\n\
    \    int n;\n    vector<T> vals;     // \u5024\u306E\u7A2E\u985E (\u6607\u9806\
    )\n    vector<int> start;  // \u5024 vals[k] \u306E\u51FA\u73FE\u4F4D\u7F6E\u306F\
    \ pos[start[k] .. start[k+1])\n    vector<int> pos;\n\n    StaticRangeFrequency(const\
    \ vector<T> &a) : n(a.size()) {\n        vector<int> ord(n);\n        iota(ord.begin(),\
    \ ord.end(), 0);\n        stable_sort(ord.begin(), ord.end(), [&](int i, int j)\
    \ { return a[i] < a[j]; });\n        pos = ord;\n        for (int k = 0; k < n;\
    \ k++) {\n            if (k == 0 || vals.back() < a[ord[k]]) vals.push_back(a[ord[k]]),\
    \ start.push_back(k);\n        }\n        start.push_back(n);\n    }\n\n    //\
    \ a[l..r) \u306E\u4E2D\u306E x \u306E\u500B\u6570\n    int count(int l, int r,\
    \ const T &x) const {\n        int k = lower_bound(vals.begin(), vals.end(), x)\
    \ - vals.begin();\n        if (k == (int)vals.size() || x < vals[k]) return 0;\n\
    \        auto b = pos.begin() + start[k], e = pos.begin() + start[k + 1];\n  \
    \      return lower_bound(b, e, r) - lower_bound(b, e, l);\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/static_range_frequency.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unittest/static_range_queries.test.cpp
  - test/static_range_frequency.test.cpp
documentation_of: data_structure/static_range_frequency.hpp
layout: document
title: "\u9759\u7684\u306A\u533A\u9593\u306E\u5024\u306E\u500B\u6570 (Static Range\
  \ Frequency)"
---

## 概要

静的な数列 $a$ について「$a_l, \ldots, a_{r-1}$ の中に $x$ が何個あるか」を $O(\log n)$ で答える（オンライン）。
値ごとに出現位置を昇順に並べた列を作っておき、$x$ の位置の列の中で $[l, r)$ に入るものを二分探索で数える。

## 使い方

```cpp
StaticRangeFrequency<int> f(a);   // vector<int> a (値の型は < で比べられれば何でもよい)
f.count(l, r, x);                 // a[l..r) の中の x の個数
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `StaticRangeFrequency<T>(const vector<T> &a)` | 構築 | $O(n \log n)$ |
| `int count(int l, int r, T x)` | $a_l, \ldots, a_{r-1}$ の中の $x$ の個数 | $O(\log n)$ |

## 注意

- 値が変わるなら [DynamicRangeFrequency](dynamic_range_frequency.hpp)。
