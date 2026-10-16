---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':x:'
    path: data_structure/range_assign_segment_tree.hpp
    title: "\u533A\u9593\u4EE3\u5165\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Range Assign\
      \ Segment Tree)"
  - icon: ':x:'
    path: data_structure/sortable_segment_tree.hpp
    title: "\u533A\u9593\u30BD\u30FC\u30C8\u304C\u3067\u304D\u308B\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728 (Sortable Segment Tree)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/point_set_range_sort_range_composite.test.cpp
    title: test/point_set_range_sort_range_composite.test.cpp
  - icon: ':x:'
    path: test/predecessor_problem.test.cpp
    title: test/predecessor_problem.test.cpp
  - icon: ':x:'
    path: test/range_set_range_composite.test.cpp
    title: test/range_set_range_composite.test.cpp
  - icon: ':x:'
    path: test/unittest/fast_set.test.cpp
    title: test/unittest/fast_set.test.cpp
  - icon: ':x:'
    path: test/unittest/range_assign_segment_tree.test.cpp
    title: test/unittest/range_assign_segment_tree.test.cpp
  - icon: ':x:'
    path: test/unittest/sortable_segment_tree.test.cpp
    title: test/unittest/sortable_segment_tree.test.cpp
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
    \ 3 \"data_structure/fast_set.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// 64 \u5206\u6728\u306B\u3088\u308B [0, n) \u306E\u6574\u6570\u96C6\u5408\n\
    // \u633F\u5165\u30FB\u524A\u9664\u30FB\u5B58\u5728\u5224\u5B9A\u30FB\u6B21\u306E\
    \u8981\u7D20\u30FB\u524D\u306E\u8981\u7D20\u3092 O(log_64 n) \u3067\u51E6\u7406\
    \u3059\u308B\nstruct FastSet {\n    int n, lg;\n    // seg[0] \u304C\u6700\u4E0B\
    \u6BB5\uFF0Eseg[h+1] \u306E bit i \u306F seg[h] \u306E i \u756A\u76EE\u306E\u30EF\
    \u30FC\u30C9\u304C 0 \u3067\u306A\u3044\u304B\u3092\u8868\u3059\n    vector<vector<uint64_t>>\
    \ seg;\n\n    FastSet(int n = 0) : n(n) {\n        int m = n;\n        do {\n\
    \            seg.push_back(vector<uint64_t>(std::max(1, (m + 63) >> 6)));\n  \
    \          m = (m + 63) >> 6;\n        } while (m > 1);\n        lg = seg.size();\n\
    \    }\n\n    // f(i) \u304C true \u306E i \u3092\u5168\u3066\u5165\u308C\u305F\
    \u72B6\u614B\u3067\u521D\u671F\u5316\u3059\u308B\uFF0EO(n)\n    template <class\
    \ F>\n    FastSet(int n, F f) : FastSet(n) {\n        for (int i = 0; i < n; i++)\
    \ if (f(i)) seg[0][i >> 6] |= 1ULL << (i & 63);\n        build_upper();\n    }\n\
    \n    // \u6700\u4E0B\u6BB5\u304B\u3089\u4E0A\u306E\u6BB5\u3092\u4F5C\u308A\u76F4\
    \u3059\n    void build_upper() {\n        for (int h = 0; h + 1 < lg; h++) {\n\
    \            fill(seg[h + 1].begin(), seg[h + 1].end(), 0);\n            for (size_t\
    \ i = 0; i < seg[h].size(); i++) if (seg[h][i]) seg[h + 1][i >> 6] |= 1ULL <<\
    \ (i & 63);\n        }\n    }\n\n    int size() const { return n; }\n\n    bool\
    \ contains(int i) const { return seg[0][i >> 6] >> (i & 63) & 1; }\n    bool operator[](int\
    \ i) const { return contains(i); }\n\n    void insert(int i) {\n        for (int\
    \ h = 0; h < lg; h++) {\n            uint64_t &w = seg[h][i >> 6];\n         \
    \   bool was_empty = w == 0;\n            w |= 1ULL << (i & 63);\n           \
    \ // \u3059\u3067\u306B\u4E0A\u306E\u6BB5\u306B\u30D5\u30E9\u30B0\u304C\u7ACB\u3063\
    \u3066\u3044\u308B\u306E\u3067\u6253\u3061\u5207\u308B\n            if (!was_empty)\
    \ break;\n            i >>= 6;\n        }\n    }\n\n    void erase(int i) {\n\
    \        for (int h = 0; h < lg; h++) {\n            uint64_t &w = seg[h][i >>\
    \ 6];\n            w &= ~(1ULL << (i & 63));\n            // \u30EF\u30FC\u30C9\
    \u304C\u307E\u3060\u7A7A\u3067\u306A\u3051\u308C\u3070\u4E0A\u306E\u6BB5\u306F\
    \u5909\u308F\u3089\u306A\u3044\n            if (w) break;\n            i >>= 6;\n\
    \        }\n    }\n\n    // i \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20\
    \ (\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 -1)\n    int next(int i) const {\n\
    \        if (i < 0) i = 0;\n        if (i >= n) return -1;\n        for (int h\
    \ = 0; h < lg; h++) {\n            if ((i >> 6) == (int)seg[h].size()) break;\n\
    \            uint64_t d = seg[h][i >> 6] >> (i & 63);\n            if (d == 0)\
    \ {\n                i = (i >> 6) + 1;\n                continue;\n          \
    \  }\n            i += __builtin_ctzll(d);\n            for (int g = h - 1; g\
    \ >= 0; g--) {\n                i <<= 6;\n                i += __builtin_ctzll(seg[g][i\
    \ >> 6]);\n            }\n            return i;\n        }\n        return -1;\n\
    \    }\n\n    // i \u4EE5\u4E0B\u306E\u6700\u5927\u306E\u8981\u7D20 (\u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070 -1)\n    int prev(int i) const {\n        if (i\
    \ >= n) i = n - 1;\n        for (int h = 0; h < lg; h++) {\n            if (i\
    \ < 0) break;\n            uint64_t d = seg[h][i >> 6] << (63 - (i & 63));\n \
    \           if (d == 0) {\n                i = (i >> 6) - 1;\n               \
    \ continue;\n            }\n            i -= __builtin_clzll(d);\n           \
    \ for (int g = h - 1; g >= 0; g--) {\n                i <<= 6;\n             \
    \   i += 63 - __builtin_clzll(seg[g][i >> 6]);\n            }\n            return\
    \ i;\n        }\n        return -1;\n    }\n\n    // \u6700\u5C0F\u306E\u8981\u7D20\
    \ (\u7A7A\u306A\u3089 -1)\n    int min() const { return next(0); }\n    // \u6700\
    \u5927\u306E\u8981\u7D20 (\u7A7A\u306A\u3089 -1)\n    int max() const { return\
    \ prev(n - 1); }\n    bool empty() const { return seg[lg - 1][0] == 0; }\n\n \
    \   // [l, r) \u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u3092\u6607\u9806\u306B\
    \ f \u306B\u6E21\u3059\n    template <class F>\n    void enumerate(int l, int\
    \ r, F f) const {\n        for (int x = next(l); x != -1 && x < r; x = next(x\
    \ + 1)) f(x);\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// 64 \u5206\u6728\u306B\u3088\u308B [0, n) \u306E\u6574\u6570\u96C6\u5408\n\
    // \u633F\u5165\u30FB\u524A\u9664\u30FB\u5B58\u5728\u5224\u5B9A\u30FB\u6B21\u306E\
    \u8981\u7D20\u30FB\u524D\u306E\u8981\u7D20\u3092 O(log_64 n) \u3067\u51E6\u7406\
    \u3059\u308B\nstruct FastSet {\n    int n, lg;\n    // seg[0] \u304C\u6700\u4E0B\
    \u6BB5\uFF0Eseg[h+1] \u306E bit i \u306F seg[h] \u306E i \u756A\u76EE\u306E\u30EF\
    \u30FC\u30C9\u304C 0 \u3067\u306A\u3044\u304B\u3092\u8868\u3059\n    vector<vector<uint64_t>>\
    \ seg;\n\n    FastSet(int n = 0) : n(n) {\n        int m = n;\n        do {\n\
    \            seg.push_back(vector<uint64_t>(std::max(1, (m + 63) >> 6)));\n  \
    \          m = (m + 63) >> 6;\n        } while (m > 1);\n        lg = seg.size();\n\
    \    }\n\n    // f(i) \u304C true \u306E i \u3092\u5168\u3066\u5165\u308C\u305F\
    \u72B6\u614B\u3067\u521D\u671F\u5316\u3059\u308B\uFF0EO(n)\n    template <class\
    \ F>\n    FastSet(int n, F f) : FastSet(n) {\n        for (int i = 0; i < n; i++)\
    \ if (f(i)) seg[0][i >> 6] |= 1ULL << (i & 63);\n        build_upper();\n    }\n\
    \n    // \u6700\u4E0B\u6BB5\u304B\u3089\u4E0A\u306E\u6BB5\u3092\u4F5C\u308A\u76F4\
    \u3059\n    void build_upper() {\n        for (int h = 0; h + 1 < lg; h++) {\n\
    \            fill(seg[h + 1].begin(), seg[h + 1].end(), 0);\n            for (size_t\
    \ i = 0; i < seg[h].size(); i++) if (seg[h][i]) seg[h + 1][i >> 6] |= 1ULL <<\
    \ (i & 63);\n        }\n    }\n\n    int size() const { return n; }\n\n    bool\
    \ contains(int i) const { return seg[0][i >> 6] >> (i & 63) & 1; }\n    bool operator[](int\
    \ i) const { return contains(i); }\n\n    void insert(int i) {\n        for (int\
    \ h = 0; h < lg; h++) {\n            uint64_t &w = seg[h][i >> 6];\n         \
    \   bool was_empty = w == 0;\n            w |= 1ULL << (i & 63);\n           \
    \ // \u3059\u3067\u306B\u4E0A\u306E\u6BB5\u306B\u30D5\u30E9\u30B0\u304C\u7ACB\u3063\
    \u3066\u3044\u308B\u306E\u3067\u6253\u3061\u5207\u308B\n            if (!was_empty)\
    \ break;\n            i >>= 6;\n        }\n    }\n\n    void erase(int i) {\n\
    \        for (int h = 0; h < lg; h++) {\n            uint64_t &w = seg[h][i >>\
    \ 6];\n            w &= ~(1ULL << (i & 63));\n            // \u30EF\u30FC\u30C9\
    \u304C\u307E\u3060\u7A7A\u3067\u306A\u3051\u308C\u3070\u4E0A\u306E\u6BB5\u306F\
    \u5909\u308F\u3089\u306A\u3044\n            if (w) break;\n            i >>= 6;\n\
    \        }\n    }\n\n    // i \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20\
    \ (\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 -1)\n    int next(int i) const {\n\
    \        if (i < 0) i = 0;\n        if (i >= n) return -1;\n        for (int h\
    \ = 0; h < lg; h++) {\n            if ((i >> 6) == (int)seg[h].size()) break;\n\
    \            uint64_t d = seg[h][i >> 6] >> (i & 63);\n            if (d == 0)\
    \ {\n                i = (i >> 6) + 1;\n                continue;\n          \
    \  }\n            i += __builtin_ctzll(d);\n            for (int g = h - 1; g\
    \ >= 0; g--) {\n                i <<= 6;\n                i += __builtin_ctzll(seg[g][i\
    \ >> 6]);\n            }\n            return i;\n        }\n        return -1;\n\
    \    }\n\n    // i \u4EE5\u4E0B\u306E\u6700\u5927\u306E\u8981\u7D20 (\u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070 -1)\n    int prev(int i) const {\n        if (i\
    \ >= n) i = n - 1;\n        for (int h = 0; h < lg; h++) {\n            if (i\
    \ < 0) break;\n            uint64_t d = seg[h][i >> 6] << (63 - (i & 63));\n \
    \           if (d == 0) {\n                i = (i >> 6) - 1;\n               \
    \ continue;\n            }\n            i -= __builtin_clzll(d);\n           \
    \ for (int g = h - 1; g >= 0; g--) {\n                i <<= 6;\n             \
    \   i += 63 - __builtin_clzll(seg[g][i >> 6]);\n            }\n            return\
    \ i;\n        }\n        return -1;\n    }\n\n    // \u6700\u5C0F\u306E\u8981\u7D20\
    \ (\u7A7A\u306A\u3089 -1)\n    int min() const { return next(0); }\n    // \u6700\
    \u5927\u306E\u8981\u7D20 (\u7A7A\u306A\u3089 -1)\n    int max() const { return\
    \ prev(n - 1); }\n    bool empty() const { return seg[lg - 1][0] == 0; }\n\n \
    \   // [l, r) \u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u3092\u6607\u9806\u306B\
    \ f \u306B\u6E21\u3059\n    template <class F>\n    void enumerate(int l, int\
    \ r, F f) const {\n        for (int x = next(l); x != -1 && x < r; x = next(x\
    \ + 1)) f(x);\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/fast_set.hpp
  requiredBy:
  - data_structure/sortable_segment_tree.hpp
  - data_structure/range_assign_segment_tree.hpp
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unittest/fast_set.test.cpp
  - test/unittest/range_assign_segment_tree.test.cpp
  - test/unittest/sortable_segment_tree.test.cpp
  - test/point_set_range_sort_range_composite.test.cpp
  - test/predecessor_problem.test.cpp
  - test/range_set_range_composite.test.cpp
documentation_of: data_structure/fast_set.hpp
layout: document
title: "64 \u5206\u6728\u306B\u3088\u308B\u6574\u6570\u96C6\u5408 (Fast Set)"
---

## 概要

$[0, n)$ の整数の集合を 64 分木（各段がビット列）で持ち、挿入・削除・存在判定・「$i$ 以上の最小の要素」・「$i$ 以下の最大の要素」を $O(\log_{64} n)$ で処理する。
$n = 10^6$ でも 4 段なので、`std::set` よりはるかに速く、メモリも約 $n/8$ バイトしか使わない。

## 使い方

```cpp
FastSet fs(n);                                   // 空集合
FastSet fs2(n, [&](int i) { return s[i] == '1'; });  // f(i) が true の i を入れて O(n) で構築
fs.insert(i); fs.erase(i);
fs.contains(i);   // fs[i] でも可
fs.next(i);       // i 以上の最小の要素 (なければ -1)
fs.prev(i);       // i 以下の最大の要素 (なければ -1)
fs.min(); fs.max(); fs.empty();
fs.enumerate(l, r, [&](int x) { ... });  // [l, r) の要素を昇順に列挙
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `FastSet(int n)` | 空集合で初期化 | $O(n / 64)$ |
| `FastSet(int n, F f)` | `f(i)` が `true` の `i` を入れて初期化 | $O(n)$ |
| `void insert(int i)` | `i` を追加（既にあれば何もしない） | $O(\log_{64} n)$ |
| `void erase(int i)` | `i` を削除（なければ何もしない） | $O(\log_{64} n)$ |
| `bool contains(int i)` | `i` が含まれるか | $O(1)$ |
| `int next(int i)` | `i` 以上の最小の要素。なければ `-1`（`i < 0` なら 0 とみなす） | $O(\log_{64} n)$ |
| `int prev(int i)` | `i` 以下の最大の要素。なければ `-1`（`i >= n` なら `n - 1` とみなす） | $O(\log_{64} n)$ |
| `int min()` / `int max()` | 最小 / 最大の要素（空なら `-1`） | $O(\log_{64} n)$ |
| `bool empty()` | 空か | $O(1)$ |
| `void enumerate(int l, int r, F f)` | $[l, r)$ の要素を昇順に `f(x)` | $O((\text{個数} + 1) \log_{64} n)$ |

## 注意

- 要素数を数える機能はない（順位や $k$ 番目が必要なら [OrderedSet](ordered_set.hpp) を使う）。
- 値の範囲が大きい場合は座標圧縮してから使う。
