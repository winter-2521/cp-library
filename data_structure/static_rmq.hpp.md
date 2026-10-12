---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/staticrmq.test.cpp
    title: test/staticrmq.test.cpp
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
    \ 3 \"data_structure/static_rmq.hpp\"\n\n// \u9759\u7684\u306A\u533A\u9593\u6700\
    \u5C0F\u5024 (Range Minimum Query)\n// \u69CB\u7BC9 O(n)\uFF0C\u30AF\u30A8\u30EA\
    \ O(1)\uFF0E\u533A\u9593\u306E\u6700\u5C0F\u5024\u3068\u305D\u306E\u4F4D\u7F6E\
    \ (\u6700\u5C0F\u5024\u304C\u8907\u6570\u3042\u308C\u3070\u4E00\u756A\u5DE6) \u3092\
    \u8FD4\u3059\n//\n// 64 \u8981\u7D20\u305A\u3064\u306E\u30D6\u30ED\u30C3\u30AF\
    \u306B\u5206\u3051\uFF0C\n// - \u30D6\u30ED\u30C3\u30AF\u5185: \u5404 i \u306B\
    \u3064\u3044\u3066\u300C\u30D6\u30ED\u30C3\u30AF\u306E\u5148\u982D\u304B\u3089\
    \ i \u307E\u3067\u306E\u5358\u8ABF\u30B9\u30BF\u30C3\u30AF\u300D\u3092\u30D3\u30C3\
    \u30C8\u30DE\u30B9\u30AF\u3067\u6301\u3064\n// - \u30D6\u30ED\u30C3\u30AF\u9593\
    : \u30D6\u30ED\u30C3\u30AF\u3054\u3068\u306E\u6700\u5C0F\u5024\u306B\u5BFE\u3059\
    \u308B Sparse Table\n// \u3092\u4F7F\u3046\uFF0ESparse Table \u3092\u76F4\u63A5\
    \u4F5C\u308B\u3088\u308A\u4F7F\u3046\u30E1\u30E2\u30EA\u304C\u5C11\u306A\u304F\
    \uFF0C\u30AD\u30E3\u30C3\u30B7\u30E5\u306B\u4E57\u308A\u3084\u3059\u3044\ntemplate\
    \ <class T, class Compare = less<T>>\nstruct StaticRMQ {\n    static constexpr\
    \ int B = 64;\n    int n, nb;\n    vector<T> a;\n    Compare comp;\n    // mask[i]\
    \ \u306E bit j: \u30D6\u30ED\u30C3\u30AF\u5148\u982D + j \u304C a[\u30D6\u30ED\
    \u30C3\u30AF\u5148\u982D + j .. i] \u306E\u6700\u5C0F\u5024\u306E\u4F4D\u7F6E\
    \ (\u5358\u8ABF\u30B9\u30BF\u30C3\u30AF\u306B\u6B8B\u3063\u3066\u3044\u308B)\n\
    \    vector<uint64_t> mask;\n    // \u30D6\u30ED\u30C3\u30AF\u9593 Sparse Table\
    \ (\u5024\u3067\u306F\u306A\u304F\u4F4D\u7F6E\u3092\u6301\u3064)\n    vector<int>\
    \ table;\n    int lg;\n\n    StaticRMQ(const vector<T> &v, Compare comp = Compare())\
    \ : n(v.size()), a(v), comp(comp), mask(v.size()) {\n        nb = (n + B - 1)\
    \ / B;\n        // \u30D6\u30ED\u30C3\u30AF\u5185\u306E\u5358\u8ABF\u30B9\u30BF\
    \u30C3\u30AF\n        for (int s = 0; s < n; s += B) {\n            int e = std::min(n,\
    \ s + B);\n            uint64_t st = 0;\n            for (int i = s; i < e; i++)\
    \ {\n                // a[i] \u3088\u308A\u771F\u306B\u5927\u304D\u3044\u8981\u7D20\
    \u3092\u30B9\u30BF\u30C3\u30AF\u304B\u3089\u53D6\u308A\u9664\u304F (\u7B49\u3057\
    \u3044\u8981\u7D20\u306F\u5DE6\u3092\u6B8B\u3059)\n                while (st)\
    \ {\n                    int top = s + 63 - __builtin_clzll(st);\n           \
    \         if (comp(a[i], a[top])) st ^= 1ULL << (top - s);\n                 \
    \   else break;\n                }\n                st |= 1ULL << (i - s);\n \
    \               mask[i] = st;\n            }\n        }\n        // \u30D6\u30ED\
    \u30C3\u30AF\u9593 Sparse Table\n        lg = 1;\n        while ((1 << lg) <=\
    \ nb) lg++;\n        table.resize((size_t)lg * std::max(nb, 1));\n        for\
    \ (int b = 0; b < nb; b++) table[b] = b * B + __builtin_ctzll(mask[std::min(n,\
    \ (b + 1) * B) - 1]);\n        for (int k = 1; k < lg; k++) {\n            const\
    \ int *src = table.data() + (size_t)(k - 1) * nb;\n            int *dst = table.data()\
    \ + (size_t)k * nb;\n            int half = 1 << (k - 1);\n            for (int\
    \ i = 0; i + (1 << k) <= nb; i++) dst[i] = better(src[i], src[i + half]);\n  \
    \      }\n    }\n\n    // \u4F4D\u7F6E i, j \u306E\u3046\u3061\u5024\u304C\u5C0F\
    \u3055\u3044\u65B9 (\u540C\u3058\u306A\u3089\u5DE6)\n    int better(int i, int\
    \ j) const { return comp(a[j], a[i]) ? j : i; }\n\n    // \u540C\u3058\u30D6\u30ED\
    \u30C3\u30AF\u5185\u306E [l, r] (\u9589\u533A\u9593) \u306E\u6700\u5C0F\u5024\u306E\
    \u4F4D\u7F6E\n    int in_block(int l, int r) const {\n        return l + __builtin_ctzll(mask[r]\
    \ >> (l & (B - 1)));\n    }\n\n    // [l, r) \u306E\u6700\u5C0F\u5024\u306E\u4F4D\
    \u7F6E (\u6700\u5C0F\u5024\u304C\u8907\u6570\u3042\u308C\u3070\u4E00\u756A\u5DE6\
    )\uFF0El < r \u3067\u3042\u308B\u3053\u3068\n    int argmin(int l, int r) const\
    \ {\n        r--;\n        int bl = l / B, br = r / B;\n        if (bl == br)\
    \ return in_block(l, r);\n        int res = in_block(l, bl * B + B - 1);\n   \
    \     if (bl + 1 < br) {\n            int k = 31 - __builtin_clz(br - bl - 1);\n\
    \            int x = better(table[(size_t)k * nb + bl + 1], table[(size_t)k *\
    \ nb + br - (1 << k)]);\n            res = better(res, x);\n        }\n      \
    \  return better(res, in_block(br * B, r));\n    }\n\n    // [l, r) \u306E\u6700\
    \u5C0F\u5024\uFF0El < r \u3067\u3042\u308B\u3053\u3068\n    T prod(int l, int\
    \ r) const { return a[argmin(l, r)]; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// \u9759\u7684\u306A\u533A\
    \u9593\u6700\u5C0F\u5024 (Range Minimum Query)\n// \u69CB\u7BC9 O(n)\uFF0C\u30AF\
    \u30A8\u30EA O(1)\uFF0E\u533A\u9593\u306E\u6700\u5C0F\u5024\u3068\u305D\u306E\u4F4D\
    \u7F6E (\u6700\u5C0F\u5024\u304C\u8907\u6570\u3042\u308C\u3070\u4E00\u756A\u5DE6\
    ) \u3092\u8FD4\u3059\n//\n// 64 \u8981\u7D20\u305A\u3064\u306E\u30D6\u30ED\u30C3\
    \u30AF\u306B\u5206\u3051\uFF0C\n// - \u30D6\u30ED\u30C3\u30AF\u5185: \u5404 i\
    \ \u306B\u3064\u3044\u3066\u300C\u30D6\u30ED\u30C3\u30AF\u306E\u5148\u982D\u304B\
    \u3089 i \u307E\u3067\u306E\u5358\u8ABF\u30B9\u30BF\u30C3\u30AF\u300D\u3092\u30D3\
    \u30C3\u30C8\u30DE\u30B9\u30AF\u3067\u6301\u3064\n// - \u30D6\u30ED\u30C3\u30AF\
    \u9593: \u30D6\u30ED\u30C3\u30AF\u3054\u3068\u306E\u6700\u5C0F\u5024\u306B\u5BFE\
    \u3059\u308B Sparse Table\n// \u3092\u4F7F\u3046\uFF0ESparse Table \u3092\u76F4\
    \u63A5\u4F5C\u308B\u3088\u308A\u4F7F\u3046\u30E1\u30E2\u30EA\u304C\u5C11\u306A\
    \u304F\uFF0C\u30AD\u30E3\u30C3\u30B7\u30E5\u306B\u4E57\u308A\u3084\u3059\u3044\
    \ntemplate <class T, class Compare = less<T>>\nstruct StaticRMQ {\n    static\
    \ constexpr int B = 64;\n    int n, nb;\n    vector<T> a;\n    Compare comp;\n\
    \    // mask[i] \u306E bit j: \u30D6\u30ED\u30C3\u30AF\u5148\u982D + j \u304C\
    \ a[\u30D6\u30ED\u30C3\u30AF\u5148\u982D + j .. i] \u306E\u6700\u5C0F\u5024\u306E\
    \u4F4D\u7F6E (\u5358\u8ABF\u30B9\u30BF\u30C3\u30AF\u306B\u6B8B\u3063\u3066\u3044\
    \u308B)\n    vector<uint64_t> mask;\n    // \u30D6\u30ED\u30C3\u30AF\u9593 Sparse\
    \ Table (\u5024\u3067\u306F\u306A\u304F\u4F4D\u7F6E\u3092\u6301\u3064)\n    vector<int>\
    \ table;\n    int lg;\n\n    StaticRMQ(const vector<T> &v, Compare comp = Compare())\
    \ : n(v.size()), a(v), comp(comp), mask(v.size()) {\n        nb = (n + B - 1)\
    \ / B;\n        // \u30D6\u30ED\u30C3\u30AF\u5185\u306E\u5358\u8ABF\u30B9\u30BF\
    \u30C3\u30AF\n        for (int s = 0; s < n; s += B) {\n            int e = std::min(n,\
    \ s + B);\n            uint64_t st = 0;\n            for (int i = s; i < e; i++)\
    \ {\n                // a[i] \u3088\u308A\u771F\u306B\u5927\u304D\u3044\u8981\u7D20\
    \u3092\u30B9\u30BF\u30C3\u30AF\u304B\u3089\u53D6\u308A\u9664\u304F (\u7B49\u3057\
    \u3044\u8981\u7D20\u306F\u5DE6\u3092\u6B8B\u3059)\n                while (st)\
    \ {\n                    int top = s + 63 - __builtin_clzll(st);\n           \
    \         if (comp(a[i], a[top])) st ^= 1ULL << (top - s);\n                 \
    \   else break;\n                }\n                st |= 1ULL << (i - s);\n \
    \               mask[i] = st;\n            }\n        }\n        // \u30D6\u30ED\
    \u30C3\u30AF\u9593 Sparse Table\n        lg = 1;\n        while ((1 << lg) <=\
    \ nb) lg++;\n        table.resize((size_t)lg * std::max(nb, 1));\n        for\
    \ (int b = 0; b < nb; b++) table[b] = b * B + __builtin_ctzll(mask[std::min(n,\
    \ (b + 1) * B) - 1]);\n        for (int k = 1; k < lg; k++) {\n            const\
    \ int *src = table.data() + (size_t)(k - 1) * nb;\n            int *dst = table.data()\
    \ + (size_t)k * nb;\n            int half = 1 << (k - 1);\n            for (int\
    \ i = 0; i + (1 << k) <= nb; i++) dst[i] = better(src[i], src[i + half]);\n  \
    \      }\n    }\n\n    // \u4F4D\u7F6E i, j \u306E\u3046\u3061\u5024\u304C\u5C0F\
    \u3055\u3044\u65B9 (\u540C\u3058\u306A\u3089\u5DE6)\n    int better(int i, int\
    \ j) const { return comp(a[j], a[i]) ? j : i; }\n\n    // \u540C\u3058\u30D6\u30ED\
    \u30C3\u30AF\u5185\u306E [l, r] (\u9589\u533A\u9593) \u306E\u6700\u5C0F\u5024\u306E\
    \u4F4D\u7F6E\n    int in_block(int l, int r) const {\n        return l + __builtin_ctzll(mask[r]\
    \ >> (l & (B - 1)));\n    }\n\n    // [l, r) \u306E\u6700\u5C0F\u5024\u306E\u4F4D\
    \u7F6E (\u6700\u5C0F\u5024\u304C\u8907\u6570\u3042\u308C\u3070\u4E00\u756A\u5DE6\
    )\uFF0El < r \u3067\u3042\u308B\u3053\u3068\n    int argmin(int l, int r) const\
    \ {\n        r--;\n        int bl = l / B, br = r / B;\n        if (bl == br)\
    \ return in_block(l, r);\n        int res = in_block(l, bl * B + B - 1);\n   \
    \     if (bl + 1 < br) {\n            int k = 31 - __builtin_clz(br - bl - 1);\n\
    \            int x = better(table[(size_t)k * nb + bl + 1], table[(size_t)k *\
    \ nb + br - (1 << k)]);\n            res = better(res, x);\n        }\n      \
    \  return better(res, in_block(br * B, r));\n    }\n\n    // [l, r) \u306E\u6700\
    \u5C0F\u5024\uFF0El < r \u3067\u3042\u308B\u3053\u3068\n    T prod(int l, int\
    \ r) const { return a[argmin(l, r)]; }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/static_rmq.hpp
  requiredBy: []
  timestamp: '2026-10-12 10:14:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/staticrmq.test.cpp
  - test/unittest/static_rmq.test.cpp
documentation_of: data_structure/static_rmq.hpp
layout: document
title: "\u9759\u7684 RMQ (Static Range Minimum Query)"
---

## 概要

静的な配列の区間最小値（とその位置）を、構築 $O(n)$・クエリ $O(1)$ で求める。

64 要素ずつのブロックに分け、

- ブロック内：各位置 $i$ について「ブロック先頭から $i$ までの単調スタック」を 64 bit のビットマスクで持つ。区間 $[l, i]$ の最小値の位置は、マスクを $l$ でシフトした最下位ビット。
- ブロック間：ブロックごとの最小値の位置に対する Sparse Table（$O(\frac{n}{64} \log n)$ 要素）。

とする。Sparse Table を直接作るよりメモリが少なくキャッシュに乗りやすいので速い。

## 使い方

```cpp
StaticRMQ<int> mn(a);                     // 最小値
StaticRMQ<int, greater<int>> mx(a);       // 比較関数を変えると最大値
mn.prod(l, r);     // min(a[l], ..., a[r-1])
mn.argmin(l, r);   // その位置 (最小値が複数あれば一番左)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `StaticRMQ<T, Compare = less<T>>(const vector<T> &a, Compare comp = Compare())` | 構築 | $O(n)$ |
| `T prod(int l, int r)` | $[l, r)$ の最小値 | $O(1)$ |
| `int argmin(int l, int r)` | $[l, r)$ の最小値の位置（複数あれば一番左） | $O(1)$ |

## 注意

- `l < r` であること（空区間には対応していない）。
- `Compare` は狭義弱順序（`less` / `greater` など）。`greater<T>` にすると最大値と、最大値のうち一番左の位置を返す。
- 配列のコピーを内部に持つ。
