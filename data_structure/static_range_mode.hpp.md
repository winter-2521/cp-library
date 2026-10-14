---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/static_range_mode_query.test.cpp
    title: test/static_range_mode_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/static_range_queries.test.cpp
    title: test/unittest/static_range_queries.test.cpp
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
    \ 3 \"data_structure/static_range_mode.hpp\"\n\n// \u9759\u7684\u306A\u6570\u5217\
    \u306E\u533A\u9593\u6700\u983B\u5024 (Static Range Mode Query)\uFF0E\u30AA\u30F3\
    \u30E9\u30A4\u30F3\uFF0C\u5E73\u65B9\u5206\u5272\n// \u30D6\u30ED\u30C3\u30AF\u306E\
    \u533A\u9593 [bi, bj] \u3054\u3068\u306B\u6700\u983B\u5024\u3068\u500B\u6570\u3092\
    \u524D\u8A08\u7B97\u3057\u3066\u304A\u304D\uFF0C\u7AEF\u306E\u8981\u7D20\u306F\
    \n// \u300C\u5024\u3054\u3068\u306E\u51FA\u73FE\u4F4D\u7F6E\u306E\u5217\u300D\u3067\
    \u500B\u6570\u3092 1 \u305A\u3064\u4F38\u3070\u305B\u308B\u304B\u78BA\u304B\u3081\
    \u308B\uFF0E\u69CB\u7BC9 O(n \u221An)\uFF0C\u30AF\u30A8\u30EA O(\u221An)\ntemplate\
    \ <class T>\nstruct StaticRangeMode {\n    int n, B, nb;\n    vector<T> vals;\
    \              // \u5EA7\u6A19\u5727\u7E2E\u5F8C\u306E\u5024 \u2192 \u5143\u306E\
    \u5024\n    vector<int> c;               // \u5727\u7E2E\u5F8C\u306E\u5024\n \
    \   vector<int> rank_in;         // i \u304C pos[c[i]] \u306E\u4F55\u756A\u76EE\
    \u304B\n    vector<vector<int>> pos;     // \u5024\u3054\u3068\u306E\u51FA\u73FE\
    \u4F4D\u7F6E\n    vector<int> mode_val, mode_cnt;  // \u30D6\u30ED\u30C3\u30AF\
    \u533A\u9593 [bi, bj] \u306E\u6700\u983B\u5024\u30FB\u500B\u6570 (bi * nb + bj)\n\
    \n    StaticRangeMode(const vector<T> &a) : n(a.size()) {\n        vals = a;\n\
    \        sort(vals.begin(), vals.end());\n        vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\n        int m = vals.size();\n        c.resize(n),\
    \ rank_in.resize(n), pos.assign(m, {});\n        for (int i = 0; i < n; i++) {\n\
    \            c[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();\n\
    \            rank_in[i] = pos[c[i]].size();\n            pos[c[i]].push_back(i);\n\
    \        }\n        B = std::max(1, (int)sqrt(n));\n        nb = (n + B - 1) /\
    \ B;\n        mode_val.assign(nb * nb, -1), mode_cnt.assign(nb * nb, 0);\n   \
    \     vector<int> cnt(m, 0);\n        for (int bi = 0; bi < nb; bi++) {\n    \
    \        int best = -1, bc = 0;\n            for (int bj = bi; bj < nb; bj++)\
    \ {\n                for (int i = bj * B; i < std::min(n, (bj + 1) * B); i++)\
    \ {\n                    if (++cnt[c[i]] > bc) bc = cnt[c[i]], best = c[i];\n\
    \                }\n                mode_val[bi * nb + bj] = best, mode_cnt[bi\
    \ * nb + bj] = bc;\n            }\n            for (int i = bi * B; i < n; i++)\
    \ cnt[c[i]]--;\n        }\n    }\n\n    // a[l..r) \u306E\u6700\u983B\u5024\u3068\
    \u305D\u306E\u500B\u6570 (l < r)\uFF0E\u6700\u983B\u5024\u304C\u8907\u6570\u3042\
    \u308C\u3070\u3069\u308C\u304B 1 \u3064\n    pair<T, int> query(int l, int r)\
    \ const {\n        int lb = l / B, rb = (r - 1) / B;\n        int best = -1, bc\
    \ = 0;\n        auto extend_right = [&](int i) {  // i \u304B\u3089\u53F3\u306B\
    \u6570\u3048\u3066 bc + 1 \u500B\u76EE\u304C r \u672A\u6E80\u306B\u3042\u308B\u304B\
    \n            int v = c[i], k = rank_in[i];\n            const auto &p = pos[v];\n\
    \            while (k + bc < (int)p.size() && p[k + bc] < r) bc++, best = v;\n\
    \        };\n        if (rb - lb <= 1) {\n            for (int i = l; i < r; i++)\
    \ extend_right(i);\n            return {vals[best], bc};\n        }\n        best\
    \ = mode_val[(lb + 1) * nb + rb - 1], bc = mode_cnt[(lb + 1) * nb + rb - 1];\n\
    \        for (int i = l; i < (lb + 1) * B; i++) extend_right(i);\n        for\
    \ (int i = rb * B; i < r; i++) {  // \u5DE6\u306B\u6570\u3048\u3066 bc + 1 \u500B\
    \u76EE\u304C l \u4EE5\u4E0A\u306B\u3042\u308B\u304B\n            int v = c[i],\
    \ k = rank_in[i];\n            const auto &p = pos[v];\n            while (k -\
    \ bc >= 0 && p[k - bc] >= l) bc++, best = v;\n        }\n        return {vals[best],\
    \ bc};\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// \u9759\u7684\u306A\u6570\
    \u5217\u306E\u533A\u9593\u6700\u983B\u5024 (Static Range Mode Query)\uFF0E\u30AA\
    \u30F3\u30E9\u30A4\u30F3\uFF0C\u5E73\u65B9\u5206\u5272\n// \u30D6\u30ED\u30C3\u30AF\
    \u306E\u533A\u9593 [bi, bj] \u3054\u3068\u306B\u6700\u983B\u5024\u3068\u500B\u6570\
    \u3092\u524D\u8A08\u7B97\u3057\u3066\u304A\u304D\uFF0C\u7AEF\u306E\u8981\u7D20\
    \u306F\n// \u300C\u5024\u3054\u3068\u306E\u51FA\u73FE\u4F4D\u7F6E\u306E\u5217\u300D\
    \u3067\u500B\u6570\u3092 1 \u305A\u3064\u4F38\u3070\u305B\u308B\u304B\u78BA\u304B\
    \u3081\u308B\uFF0E\u69CB\u7BC9 O(n \u221An)\uFF0C\u30AF\u30A8\u30EA O(\u221An)\n\
    template <class T>\nstruct StaticRangeMode {\n    int n, B, nb;\n    vector<T>\
    \ vals;              // \u5EA7\u6A19\u5727\u7E2E\u5F8C\u306E\u5024 \u2192 \u5143\
    \u306E\u5024\n    vector<int> c;               // \u5727\u7E2E\u5F8C\u306E\u5024\
    \n    vector<int> rank_in;         // i \u304C pos[c[i]] \u306E\u4F55\u756A\u76EE\
    \u304B\n    vector<vector<int>> pos;     // \u5024\u3054\u3068\u306E\u51FA\u73FE\
    \u4F4D\u7F6E\n    vector<int> mode_val, mode_cnt;  // \u30D6\u30ED\u30C3\u30AF\
    \u533A\u9593 [bi, bj] \u306E\u6700\u983B\u5024\u30FB\u500B\u6570 (bi * nb + bj)\n\
    \n    StaticRangeMode(const vector<T> &a) : n(a.size()) {\n        vals = a;\n\
    \        sort(vals.begin(), vals.end());\n        vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\n        int m = vals.size();\n        c.resize(n),\
    \ rank_in.resize(n), pos.assign(m, {});\n        for (int i = 0; i < n; i++) {\n\
    \            c[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();\n\
    \            rank_in[i] = pos[c[i]].size();\n            pos[c[i]].push_back(i);\n\
    \        }\n        B = std::max(1, (int)sqrt(n));\n        nb = (n + B - 1) /\
    \ B;\n        mode_val.assign(nb * nb, -1), mode_cnt.assign(nb * nb, 0);\n   \
    \     vector<int> cnt(m, 0);\n        for (int bi = 0; bi < nb; bi++) {\n    \
    \        int best = -1, bc = 0;\n            for (int bj = bi; bj < nb; bj++)\
    \ {\n                for (int i = bj * B; i < std::min(n, (bj + 1) * B); i++)\
    \ {\n                    if (++cnt[c[i]] > bc) bc = cnt[c[i]], best = c[i];\n\
    \                }\n                mode_val[bi * nb + bj] = best, mode_cnt[bi\
    \ * nb + bj] = bc;\n            }\n            for (int i = bi * B; i < n; i++)\
    \ cnt[c[i]]--;\n        }\n    }\n\n    // a[l..r) \u306E\u6700\u983B\u5024\u3068\
    \u305D\u306E\u500B\u6570 (l < r)\uFF0E\u6700\u983B\u5024\u304C\u8907\u6570\u3042\
    \u308C\u3070\u3069\u308C\u304B 1 \u3064\n    pair<T, int> query(int l, int r)\
    \ const {\n        int lb = l / B, rb = (r - 1) / B;\n        int best = -1, bc\
    \ = 0;\n        auto extend_right = [&](int i) {  // i \u304B\u3089\u53F3\u306B\
    \u6570\u3048\u3066 bc + 1 \u500B\u76EE\u304C r \u672A\u6E80\u306B\u3042\u308B\u304B\
    \n            int v = c[i], k = rank_in[i];\n            const auto &p = pos[v];\n\
    \            while (k + bc < (int)p.size() && p[k + bc] < r) bc++, best = v;\n\
    \        };\n        if (rb - lb <= 1) {\n            for (int i = l; i < r; i++)\
    \ extend_right(i);\n            return {vals[best], bc};\n        }\n        best\
    \ = mode_val[(lb + 1) * nb + rb - 1], bc = mode_cnt[(lb + 1) * nb + rb - 1];\n\
    \        for (int i = l; i < (lb + 1) * B; i++) extend_right(i);\n        for\
    \ (int i = rb * B; i < r; i++) {  // \u5DE6\u306B\u6570\u3048\u3066 bc + 1 \u500B\
    \u76EE\u304C l \u4EE5\u4E0A\u306B\u3042\u308B\u304B\n            int v = c[i],\
    \ k = rank_in[i];\n            const auto &p = pos[v];\n            while (k -\
    \ bc >= 0 && p[k - bc] >= l) bc++, best = v;\n        }\n        return {vals[best],\
    \ bc};\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/static_range_mode.hpp
  requiredBy: []
  timestamp: '2026-10-14 23:42:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/static_range_queries.test.cpp
  - test/static_range_mode_query.test.cpp
documentation_of: data_structure/static_range_mode.hpp
layout: document
title: "\u9759\u7684\u306A\u533A\u9593\u6700\u983B\u5024 (Static Range Mode Query)"
---

## 概要

静的な数列 $a$ について、区間 $[l, r)$ の最頻値とその個数を $O(\sqrt n)$ で答える（**オンライン**、平方分割）。

- 長さ $B \approx \sqrt n$ のブロックに分け、ブロックの区間 $[b_i, b_j]$ ごとに最頻値と個数を前計算する（$O(n \sqrt n)$）。
- クエリでは、間の完全なブロックの最頻値から始め、両端の端数の要素それぞれについて「その値が個数 + 1 回出てくるか」を、値ごとの出現位置の列で $O(1)$ ずつ確かめて伸ばしていく。個数が増えるのは端数の要素数回まで。

## 使い方

```cpp
StaticRangeMode<int> md(a);       // vector<int> a
auto [x, c] = md.query(l, r);    // a[l..r) の最頻値 x とその個数 c (l < r)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `StaticRangeMode<T>(const vector<T> &a)` | 構築 | $O(n \sqrt n)$ |
| `pair<T, int> query(int l, int r)` | 最頻値と個数 | $O(\sqrt n)$ |

## 注意

- 最頻値が複数あるときはどれか 1 つを返す。
- $l < r$ で呼ぶこと。
- メモリはブロック数の 2 乗（$n = 10^5$ で約 $10^5$ 個の int）+ $O(n)$。
