---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/wavelet_matrix.hpp
    title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217 (Wavelet Matrix)"
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/static_range_count_distinct.test.cpp
    title: test/static_range_count_distinct.test.cpp
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
    \ 3 \"data_structure/wavelet_matrix.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217 (\u9759\u7684\u306A\
    \u6570\u5217\u306B\u5BFE\u3059\u308B\u533A\u9593 k \u756A\u76EE\u30FB\u533A\u9593\
    \u306E\u5024\u306E\u500B\u6570\u306A\u3069)\n// \u5024\u306F\u5185\u90E8\u3067\
    \u5EA7\u6A19\u5727\u7E2E\u3059\u308B\uFF0E\u69CB\u7BC9 O(n log n)\uFF0C\u5404\u30AF\
    \u30A8\u30EA O(log \u03C3) (\u03C3 \u306F\u5024\u306E\u7A2E\u985E\u6570)\ntemplate\
    \ <class T>\nstruct WaveletMatrix {\n    // 64 bit \u3054\u3068\u306B\uFF0C\u30D3\
    \u30C3\u30C8\u5217\u3068\u305D\u308C\u3088\u308A\u524D\u306E 1 \u306E\u500B\u6570\
    \u3092\u307E\u3068\u3081\u3066\u6301\u3064\n    struct BitVector {\n        struct\
    \ Block {\n            uint64_t bits;\n            int cnt;\n        };\n    \
    \    vector<Block> b;\n        void init(int n) { b.assign((n >> 6) + 1, {0, 0});\
    \ }\n        void set(int i) { b[i >> 6].bits |= 1ULL << (i & 63); }\n       \
    \ void build() {\n            for (size_t i = 1; i < b.size(); i++) b[i].cnt =\
    \ b[i - 1].cnt + __builtin_popcountll(b[i - 1].bits);\n        }\n        // [0,\
    \ i) \u306E 1 \u306E\u500B\u6570\n        int rank1(int i) const {\n         \
    \   const Block &x = b[i >> 6];\n            return x.cnt + __builtin_popcountll(x.bits\
    \ & ((1ULL << (i & 63)) - 1));\n        }\n        bool get(int i) const { return\
    \ b[i >> 6].bits >> (i & 63) & 1; }\n    };\n\n    int n, lg;\n    vector<T> vals;\
    \  // \u5EA7\u6A19\u5727\u7E2E\u5F8C\u306E\u5024 (\u6607\u9806)\n    vector<BitVector>\
    \ bv;\n    vector<int> zeros;\n\n    WaveletMatrix(const vector<T> &a = {}) :\
    \ n(a.size()) {\n        vals = a;\n        sort(vals.begin(), vals.end());\n\
    \        vals.erase(unique(vals.begin(), vals.end()), vals.end());\n        vector<int>\
    \ cur(n);\n        for (int i = 0; i < n; i++) cur[i] = int(lower_bound(vals.begin(),\
    \ vals.end(), a[i]) - vals.begin());\n        lg = 1;\n        while ((1 << lg)\
    \ < (int)vals.size()) lg++;\n        bv.resize(lg);\n        zeros.resize(lg);\n\
    \        vector<int> nxt(n);\n        for (int h = lg - 1; h >= 0; h--) {\n  \
    \          bv[h].init(n);\n            int z = 0;\n            for (int i = 0;\
    \ i < n; i++) {\n                if (cur[i] >> h & 1) bv[h].set(i);\n        \
    \        else z++;\n            }\n            bv[h].build();\n            zeros[h]\
    \ = z;\n            // 0 \u306E\u3082\u306E\u3092\u524D\u306B\uFF0C1 \u306E\u3082\
    \u306E\u3092\u5F8C\u308D\u306B (\u5B89\u5B9A)\n            int p0 = 0, p1 = z;\n\
    \            for (int i = 0; i < n; i++) nxt[(cur[i] >> h & 1) ? p1++ : p0++]\
    \ = cur[i];\n            swap(cur, nxt);\n        }\n    }\n\n    int size() const\
    \ { return n; }\n\n    // a[i]\n    T access(int i) const {\n        int res =\
    \ 0;\n        for (int h = lg - 1; h >= 0; h--) {\n            int r1 = bv[h].rank1(i);\n\
    \            if (bv[h].get(i)) res |= 1 << h, i = zeros[h] + r1;\n           \
    \ else i -= r1;\n        }\n        return vals[res];\n    }\n    T operator[](int\
    \ i) const { return access(i); }\n\n    // a[l..r) \u306E\u4E2D\u3067\u5C0F\u3055\
    \u3044\u65B9\u304B\u3089 k \u756A\u76EE (0-indexed) \u306E\u5024\uFF0E0 <= k <\
    \ r - l \u3067\u3042\u308B\u3053\u3068\n    T kth_smallest(int l, int r, int k)\
    \ const {\n        int res = 0;\n        for (int h = lg - 1; h >= 0; h--) {\n\
    \            int l1 = bv[h].rank1(l), r1 = bv[h].rank1(r);\n            int z\
    \ = (r - r1) - (l - l1);\n            if (k < z) {\n                l -= l1, r\
    \ -= r1;\n            } else {\n                k -= z;\n                res |=\
    \ 1 << h;\n                l = zeros[h] + l1, r = zeros[h] + r1;\n           \
    \ }\n        }\n        return vals[res];\n    }\n    // a[l..r) \u306E\u4E2D\u3067\
    \u5927\u304D\u3044\u65B9\u304B\u3089 k \u756A\u76EE (0-indexed) \u306E\u5024\n\
    \    T kth_largest(int l, int r, int k) const { return kth_smallest(l, r, r -\
    \ l - 1 - k); }\n\n    // a[l..r) \u306E\u4E2D\u306E x \u672A\u6E80\u306E\u5024\
    \u306E\u500B\u6570\n    int count_lt(int l, int r, const T &x) const { return\
    \ count_lt_id(l, r, id_lower(x)); }\n    // a[l..r) \u306E\u4E2D\u306E x \u4EE5\
    \u4E0B\u306E\u5024\u306E\u500B\u6570\n    int count_le(int l, int r, const T &x)\
    \ const { return count_lt_id(l, r, id_upper(x)); }\n    // a[l..r) \u306E\u4E2D\
    \u306E lo \u4EE5\u4E0A hi \u672A\u6E80\u306E\u5024\u306E\u500B\u6570\n    int\
    \ count_range(int l, int r, const T &lo, const T &hi) const {\n        if (!(lo\
    \ < hi)) return 0;\n        return count_lt(l, r, hi) - count_lt(l, r, lo);\n\
    \    }\n    // a[l..r) \u306E\u4E2D\u306E x \u306E\u500B\u6570\n    int count(int\
    \ l, int r, const T &x) const { return count_le(l, r, x) - count_lt(l, r, x);\
    \ }\n\n    // a[l..r) \u306E\u4E2D\u306E x \u672A\u6E80\u306E\u6700\u5927\u306E\
    \u5024 (\u306A\u3051\u308C\u3070 def)\n    T max_lt(int l, int r, const T &x,\
    \ T def = T(-1)) const {\n        int c = count_lt(l, r, x);\n        return c\
    \ == 0 ? def : kth_smallest(l, r, c - 1);\n    }\n    // a[l..r) \u306E\u4E2D\u306E\
    \ x \u4EE5\u4E0B\u306E\u6700\u5927\u306E\u5024 (\u306A\u3051\u308C\u3070 def)\n\
    \    T max_le(int l, int r, const T &x, T def = T(-1)) const {\n        int c\
    \ = count_le(l, r, x);\n        return c == 0 ? def : kth_smallest(l, r, c - 1);\n\
    \    }\n    // a[l..r) \u306E\u4E2D\u306E x \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\
    \u5024 (\u306A\u3051\u308C\u3070 def)\n    T min_ge(int l, int r, const T &x,\
    \ T def = T(-1)) const {\n        int c = count_lt(l, r, x);\n        return c\
    \ == r - l ? def : kth_smallest(l, r, c);\n    }\n    // a[l..r) \u306E\u4E2D\u306E\
    \ x \u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u5024 (\u306A\u3051\u308C\
    \u3070 def)\n    T min_gt(int l, int r, const T &x, T def = T(-1)) const {\n \
    \       int c = count_le(l, r, x);\n        return c == r - l ? def : kth_smallest(l,\
    \ r, c);\n    }\n\n  private:\n    int id_lower(const T &x) const { return int(lower_bound(vals.begin(),\
    \ vals.end(), x) - vals.begin()); }\n    int id_upper(const T &x) const { return\
    \ int(upper_bound(vals.begin(), vals.end(), x) - vals.begin()); }\n    // a[l..r)\
    \ \u306E\u4E2D\u3067\u5727\u7E2E\u5F8C\u306E\u5024\u304C v \u672A\u6E80\u306E\u3082\
    \u306E\u306E\u500B\u6570\n    int count_lt_id(int l, int r, int v) const {\n \
    \       if (l >= r) return 0;\n        if (v >= (1 << lg)) return r - l;\n   \
    \     int res = 0;\n        for (int h = lg - 1; h >= 0; h--) {\n            int\
    \ l1 = bv[h].rank1(l), r1 = bv[h].rank1(r);\n            if (v >> h & 1) {\n \
    \               res += (r - r1) - (l - l1);\n                l = zeros[h] + l1,\
    \ r = zeros[h] + r1;\n            } else {\n                l -= l1, r -= r1;\n\
    \            }\n        }\n        return res;\n    }\n};\n#line 4 \"data_structure/static_range_count_distinct.hpp\"\
    \n\n// https://github.com/winter-2521/cp-library\n\n// \u9759\u7684\u306A\u6570\
    \u5217\u306E\u533A\u9593\u306B\u542B\u307E\u308C\u308B\u5024\u306E\u7A2E\u985E\
    \u6570 (Static Range Count Distinct)\uFF0E\u30AA\u30F3\u30E9\u30A4\u30F3\n// prev[i]\
    \ = i \u3088\u308A\u524D\u3067 a[i] \u3068\u540C\u3058\u5024\u304C\u6700\u5F8C\
    \u306B\u51FA\u3066\u304F\u308B\u4F4D\u7F6E (\u306A\u3051\u308C\u3070 -1) \u3068\
    \u3059\u308B\u3068\uFF0C\n// [l, r) \u306E\u7A2E\u985E\u6570 = #{i \u2208 [l,\
    \ r) : prev[i] < l}\uFF0E\u3053\u308C\u3092\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\
    \u30C8\u884C\u5217\u3067\u6570\u3048\u308B\n// \u69CB\u7BC9 O(n log n)\uFF0C\u30AF\
    \u30A8\u30EA O(log n)\ntemplate <class T>\nstruct StaticRangeCountDistinct {\n\
    \    int n;\n    WaveletMatrix<int> wm;\n\n    StaticRangeCountDistinct(const\
    \ vector<T> &a) : n(a.size()) {\n        vector<int> ord(n), prev(n, -1);\n  \
    \      iota(ord.begin(), ord.end(), 0);\n        stable_sort(ord.begin(), ord.end(),\
    \ [&](int i, int j) { return a[i] < a[j]; });\n        for (int k = 1; k < n;\
    \ k++)\n            if (!(a[ord[k - 1]] < a[ord[k]])) prev[ord[k]] = ord[k - 1];\n\
    \        wm = WaveletMatrix<int>(prev);\n    }\n\n    // a[l..r) \u306E\u5024\u306E\
    \u7A2E\u985E\u6570\n    int count(int l, int r) const { return l < r ? wm.count_lt(l,\
    \ r, l) : 0; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"wavelet_matrix.hpp\"\
    \n\n// https://github.com/winter-2521/cp-library\n\n// \u9759\u7684\u306A\u6570\
    \u5217\u306E\u533A\u9593\u306B\u542B\u307E\u308C\u308B\u5024\u306E\u7A2E\u985E\
    \u6570 (Static Range Count Distinct)\uFF0E\u30AA\u30F3\u30E9\u30A4\u30F3\n// prev[i]\
    \ = i \u3088\u308A\u524D\u3067 a[i] \u3068\u540C\u3058\u5024\u304C\u6700\u5F8C\
    \u306B\u51FA\u3066\u304F\u308B\u4F4D\u7F6E (\u306A\u3051\u308C\u3070 -1) \u3068\
    \u3059\u308B\u3068\uFF0C\n// [l, r) \u306E\u7A2E\u985E\u6570 = #{i \u2208 [l,\
    \ r) : prev[i] < l}\uFF0E\u3053\u308C\u3092\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\
    \u30C8\u884C\u5217\u3067\u6570\u3048\u308B\n// \u69CB\u7BC9 O(n log n)\uFF0C\u30AF\
    \u30A8\u30EA O(log n)\ntemplate <class T>\nstruct StaticRangeCountDistinct {\n\
    \    int n;\n    WaveletMatrix<int> wm;\n\n    StaticRangeCountDistinct(const\
    \ vector<T> &a) : n(a.size()) {\n        vector<int> ord(n), prev(n, -1);\n  \
    \      iota(ord.begin(), ord.end(), 0);\n        stable_sort(ord.begin(), ord.end(),\
    \ [&](int i, int j) { return a[i] < a[j]; });\n        for (int k = 1; k < n;\
    \ k++)\n            if (!(a[ord[k - 1]] < a[ord[k]])) prev[ord[k]] = ord[k - 1];\n\
    \        wm = WaveletMatrix<int>(prev);\n    }\n\n    // a[l..r) \u306E\u5024\u306E\
    \u7A2E\u985E\u6570\n    int count(int l, int r) const { return l < r ? wm.count_lt(l,\
    \ r, l) : 0; }\n};\n"
  dependsOn:
  - template.hpp
  - data_structure/wavelet_matrix.hpp
  isVerificationFile: false
  path: data_structure/static_range_count_distinct.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/static_range_count_distinct.test.cpp
  - test/unittest/static_range_queries.test.cpp
documentation_of: data_structure/static_range_count_distinct.hpp
layout: document
title: "\u9759\u7684\u306A\u533A\u9593\u306E\u7A2E\u985E\u6570 (Static Range Count\
  \ Distinct)"
---

## 概要

静的な数列 $a$ について「$a_l, \ldots, a_{r-1}$ に何種類の値があるか」を $O(\log n)$ で答える（**オンライン**）。

$\mathrm{prev}_i$ を「$i$ より前で $a_i$ と同じ値が最後に出てくる位置（なければ $-1$）」とすると、区間 $[l, r)$ の中で各値を **一番左の出現** だけ数えればよく、それは $\mathrm{prev}_i < l$ となる $i$。よって答えは $\#\{i \in [l, r) : \mathrm{prev}_i < l\}$ で、これは $\mathrm{prev}$ の列に対する [ウェーブレット行列](wavelet_matrix.hpp) の `count_lt` 1 回で求まる。

## 使い方

```cpp
StaticRangeCountDistinct<int> cd(a);   // vector<int> a
cd.count(l, r);                        // a[l..r) の種類数
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `StaticRangeCountDistinct<T>(const vector<T> &a)` | 構築 | $O(n \log n)$ |
| `int count(int l, int r)` | $a_l, \ldots, a_{r-1}$ の種類数 | $O(\log n)$ |

## 注意

- クエリを先読みできるなら、右端でソートして BIT で数えるオフライン解法もある（定数倍はそちらの方が軽い）。
