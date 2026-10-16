---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/static_range_inversions_query.test.cpp
    title: test/static_range_inversions_query.test.cpp
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
    \ 3 \"data_structure/static_range_inversions.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u9759\u7684\u306A\u6570\u5217\u306E\u533A\u9593\u8EE2\u5012\u6570 (Static\
    \ Range Inversions Query)\uFF0E\u30AA\u30F3\u30E9\u30A4\u30F3\uFF0C\u5E73\u65B9\
    \u5206\u5272\n// \u30D6\u30ED\u30C3\u30AF\u306E\u5927\u304D\u3055\u3092 B\uFF0C\
    \u500B\u6570\u3092 nb \u3068\u3059\u308B\uFF0E\u524D\u8A08\u7B97:\n//   lt[R][i]\
    \ = #{j : block(i) < block(j) < R, a[j] < a[i]}   (i \u3088\u308A\u53F3\uFF0C\u30D6\
    \u30ED\u30C3\u30AF R \u306E\u624B\u524D\u307E\u3067\u3067 a[i] \u3088\u308A\u5C0F\
    \u3055\u3044\u3082\u306E)\n//   gt[L][j] = #{i : L <= block(i) < block(j), a[i]\
    \ > a[j]}  (\u30D6\u30ED\u30C3\u30AF L \u304B\u3089 j \u306E\u624B\u524D\u306E\
    \u30D6\u30ED\u30C3\u30AF\u307E\u3067\u3067 a[j] \u3088\u308A\u5927\u304D\u3044\
    \u3082\u306E)\n//   big[L][R] = \u30D6\u30ED\u30C3\u30AF L..R-1 \u306E\u4E2D\u306E\
    \u8EE2\u5012\u6570\n//   pre[i], suf[i] = i \u306E\u30D6\u30ED\u30C3\u30AF\u5185\
    \u3067 [\u30D6\u30ED\u30C3\u30AF\u5148\u982D, i] / [i, \u30D6\u30ED\u30C3\u30AF\
    \u672B\u5C3E) \u306E\u8EE2\u5012\u6570\n//   \u5404\u30D6\u30ED\u30C3\u30AF\u306E\
    \ (\u5024, \u4F4D\u7F6E) \u306E\u6607\u9806\u30EA\u30B9\u30C8\n// \u30AF\u30A8\
    \u30EA\u306F\u300C\u5DE6\u306E\u7AEF\u30FB\u53F3\u306E\u7AEF\u30FB\u9593\u306E\
    \u5B8C\u5168\u306A\u30D6\u30ED\u30C3\u30AF\u300D\u306B\u5206\u3051\u3066\u6570\
    \u3048\u308B\uFF0Elt / gt \u306F\u4F4D\u7F6E\u306E\u9806\u306B\u4E26\u3079\u3066\
    \u3042\u308B\u306E\u3067\uFF0C\u7AEF\u306E\u8981\u7D20\u3092\u9806\u306B\u898B\
    \u308B\u3068\u304D\u9023\u7D9A\u30A2\u30AF\u30BB\u30B9\u306B\u306A\u308B\n// \u69CB\
    \u7BC9 O(n \u221An)\uFF0C\u30AF\u30A8\u30EA O(\u221An)\uFF0C\u30E1\u30E2\u30EA\
    \ O(n \u221An)\ntemplate <class T>\nstruct StaticRangeInversions {\n    int n,\
    \ B, nb;\n    vector<int> c;                    // \u5727\u7E2E\u5F8C\u306E\u5024\
    \n    vector<int> lt, gt;               // lt[R * n + i], gt[L * n + j]\n    vector<long\
    \ long> big;            // big[L * (nb + 1) + R]\n    vector<long long> pre, suf;\n\
    \    vector<pair<int, int>> sorted_;   // \u30D6\u30ED\u30C3\u30AF\u3054\u3068\
    \u306B (\u5024, \u4F4D\u7F6E) \u3092\u6607\u9806\u306B\u4E26\u3079\u305F\u3082\
    \u306E\n\n    StaticRangeInversions(const vector<T> &a, int block = -1) : n(a.size())\
    \ {\n        vector<T> vals = a;\n        sort(vals.begin(), vals.end());\n  \
    \      vals.erase(unique(vals.begin(), vals.end()), vals.end());\n        c.resize(n);\n\
    \        for (int i = 0; i < n; i++) c[i] = lower_bound(vals.begin(), vals.end(),\
    \ a[i]) - vals.begin();\n        B = block > 0 ? block : std::max(16, (int)(1.25\
    \ * sqrt(n)));\n        nb = std::max(1, (n + B - 1) / B);\n        sorted_.resize(n);\n\
    \        for (int i = 0; i < n; i++) sorted_[i] = {c[i], i};\n        for (int\
    \ b = 0; b < nb; b++) sort(sorted_.begin() + std::min(n, b * B), sorted_.begin()\
    \ + std::min(n, (b + 1) * B));\n        vector<pair<int, int>> all = sorted_;\
    \  // \u5168\u4F53\u3092 (\u5024, \u4F4D\u7F6E) \u306E\u6607\u9806\u306B\n   \
    \     sort(all.begin(), all.end());\n        // lt[R][i] = lt[R-1][i] + #{j \u2208\
    \ \u30D6\u30ED\u30C3\u30AF R-1 : c[j] < c[i]} (block(i) < R-1 \u306E\u3068\u304D\
    )\n        lt.assign((size_t)(nb + 1) * n, 0);\n        for (int R = 2; R <= nb;\
    \ R++) {\n            int *cur = &lt[(size_t)R * n], *prv = &lt[(size_t)(R - 1)\
    \ * n];\n            int bs = (R - 1) * B, be = std::min(n, R * B), p = bs;\n\
    \            for (auto [v, i] : all) {\n                while (p < be && sorted_[p].first\
    \ < v) p++;\n                if (i < bs) cur[i] = prv[i] + (p - bs);\n       \
    \     }\n        }\n        // gt[L][j] = gt[L+1][j] + #{i \u2208 \u30D6\u30ED\
    \u30C3\u30AF L : c[i] > c[j]} (block(j) > L \u306E\u3068\u304D)\n        gt.assign((size_t)(nb\
    \ + 1) * n, 0);\n        for (int L = nb - 2; L >= 0; L--) {\n            int\
    \ *cur = &gt[(size_t)L * n], *nxt = &gt[(size_t)(L + 1) * n];\n            int\
    \ bs = L * B, be = std::min(n, (L + 1) * B), p = bs;\n            for (auto [v,\
    \ j] : all) {\n                while (p < be && sorted_[p].first <= v) p++;\n\
    \                if (j >= be) cur[j] = nxt[j] + (be - p);\n            }\n   \
    \     }\n        // \u30D6\u30ED\u30C3\u30AF\u5185\u306E\u8EE2\u5012\u6570\n \
    \       pre.assign(n, 0), suf.assign(n, 0);\n        for (int b = 0; b < nb; b++)\
    \ {\n            int s = b * B, e = std::min(n, (b + 1) * B);\n            for\
    \ (int i = s; i < e; i++) {\n                long long x = i > s ? pre[i - 1]\
    \ : 0;\n                for (int j = s; j < i; j++) x += c[j] > c[i];\n      \
    \          pre[i] = x;\n            }\n            for (int i = e - 1; i >= s;\
    \ i--) {\n                long long x = i + 1 < e ? suf[i + 1] : 0;\n        \
    \        for (int j = i + 1; j < e; j++) x += c[i] > c[j];\n                suf[i]\
    \ = x;\n            }\n        }\n        // big[L][R] = big[L][R-1] + big[L+1][R]\
    \ - big[L+1][R-1] + (\u30D6\u30ED\u30C3\u30AF L \u306E\u8981\u7D20 > \u30D6\u30ED\
    \u30C3\u30AF R-1 \u306E\u8981\u7D20 \u306E\u7D44)\n        big.assign((size_t)(nb\
    \ + 1) * (nb + 1), 0);\n        auto BIG = [&](int L, int R) -> long long & {\
    \ return big[(size_t)L * (nb + 1) + R]; };\n        for (int L = nb - 1; L >=\
    \ 0; L--) {\n            if (L * B < n) BIG(L, L + 1) = suf[L * B];\n        \
    \    for (int R = L + 2; R <= nb; R++) {\n                long long cross = 0;\n\
    \                const int *hi = &lt[(size_t)R * n], *lo = &lt[(size_t)(R - 1)\
    \ * n];\n                for (int i = L * B; i < (L + 1) * B; i++) cross += hi[i]\
    \ - lo[i];\n                BIG(L, R) = BIG(L, R - 1) + BIG(L + 1, R) - BIG(L\
    \ + 1, R - 1) + cross;\n            }\n        }\n    }\n\n    // a[l..r) \u306E\
    \u8EE2\u5012\u6570\n    long long query(int l, int r) const {\n        if (r -\
    \ l <= 1) return 0;\n        int lb = l / B, rb = (r - 1) / B;\n        if (lb\
    \ == rb) {\n            int s = lb * B, e = std::min(n, s + B);\n            long\
    \ long res = pre[r - 1] - (l > s ? pre[l - 1] : 0);\n            // [s, l) \u306E\
    \u8981\u7D20 > [l, r) \u306E\u8981\u7D20 \u306E\u7D44\u3092\u5F15\u304F (\u5024\
    \u306E\u6607\u9806\u306B\u898B\u308B\uFF0E\u540C\u3058\u5024\u306F\u4F4D\u7F6E\
    \u306E\u6607\u9806\u306A\u306E\u3067\u6570\u3048\u306A\u3044)\n            int\
    \ seen = 0;\n            for (int k = s; k < e; k++) {\n                int i\
    \ = sorted_[k].second;\n                if (i < l) res -= seen;\n            \
    \    else if (i < r) seen++;\n            }\n            return res;\n       \
    \ }\n        long long res = suf[l] + pre[r - 1] + big[(size_t)(lb + 1) * (nb\
    \ + 1) + rb];\n        const int *ltr = &lt[(size_t)rb * n], *gtl = &gt[(size_t)(lb\
    \ + 1) * n];\n        for (int i = l; i < (lb + 1) * B; i++) res += ltr[i];\n\
    \        for (int j = rb * B; j < r; j++) res += gtl[j];\n        // \u5DE6\u306E\
    \u7AEF\u306E\u8981\u7D20 > \u53F3\u306E\u7AEF\u306E\u8981\u7D20 \u306E\u7D44 (\u3069\
    \u3061\u3089\u3082\u5024\u306E\u6607\u9806\u306B\u898B\u308B)\n        int ls\
    \ = lb * B, le = (lb + 1) * B, rs = rb * B, re = std::min(n, rs + B);\n      \
    \  int p = rs, smaller = 0;\n        for (int k = ls; k < le; k++) {\n       \
    \     if (sorted_[k].second < l) continue;\n            int v = sorted_[k].first;\n\
    \            while (p < re && sorted_[p].first < v) {\n                if (sorted_[p].second\
    \ < r) smaller++;\n                p++;\n            }\n            res += smaller;\n\
    \        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u9759\u7684\u306A\u6570\u5217\u306E\u533A\u9593\u8EE2\u5012\u6570 (Static\
    \ Range Inversions Query)\uFF0E\u30AA\u30F3\u30E9\u30A4\u30F3\uFF0C\u5E73\u65B9\
    \u5206\u5272\n// \u30D6\u30ED\u30C3\u30AF\u306E\u5927\u304D\u3055\u3092 B\uFF0C\
    \u500B\u6570\u3092 nb \u3068\u3059\u308B\uFF0E\u524D\u8A08\u7B97:\n//   lt[R][i]\
    \ = #{j : block(i) < block(j) < R, a[j] < a[i]}   (i \u3088\u308A\u53F3\uFF0C\u30D6\
    \u30ED\u30C3\u30AF R \u306E\u624B\u524D\u307E\u3067\u3067 a[i] \u3088\u308A\u5C0F\
    \u3055\u3044\u3082\u306E)\n//   gt[L][j] = #{i : L <= block(i) < block(j), a[i]\
    \ > a[j]}  (\u30D6\u30ED\u30C3\u30AF L \u304B\u3089 j \u306E\u624B\u524D\u306E\
    \u30D6\u30ED\u30C3\u30AF\u307E\u3067\u3067 a[j] \u3088\u308A\u5927\u304D\u3044\
    \u3082\u306E)\n//   big[L][R] = \u30D6\u30ED\u30C3\u30AF L..R-1 \u306E\u4E2D\u306E\
    \u8EE2\u5012\u6570\n//   pre[i], suf[i] = i \u306E\u30D6\u30ED\u30C3\u30AF\u5185\
    \u3067 [\u30D6\u30ED\u30C3\u30AF\u5148\u982D, i] / [i, \u30D6\u30ED\u30C3\u30AF\
    \u672B\u5C3E) \u306E\u8EE2\u5012\u6570\n//   \u5404\u30D6\u30ED\u30C3\u30AF\u306E\
    \ (\u5024, \u4F4D\u7F6E) \u306E\u6607\u9806\u30EA\u30B9\u30C8\n// \u30AF\u30A8\
    \u30EA\u306F\u300C\u5DE6\u306E\u7AEF\u30FB\u53F3\u306E\u7AEF\u30FB\u9593\u306E\
    \u5B8C\u5168\u306A\u30D6\u30ED\u30C3\u30AF\u300D\u306B\u5206\u3051\u3066\u6570\
    \u3048\u308B\uFF0Elt / gt \u306F\u4F4D\u7F6E\u306E\u9806\u306B\u4E26\u3079\u3066\
    \u3042\u308B\u306E\u3067\uFF0C\u7AEF\u306E\u8981\u7D20\u3092\u9806\u306B\u898B\
    \u308B\u3068\u304D\u9023\u7D9A\u30A2\u30AF\u30BB\u30B9\u306B\u306A\u308B\n// \u69CB\
    \u7BC9 O(n \u221An)\uFF0C\u30AF\u30A8\u30EA O(\u221An)\uFF0C\u30E1\u30E2\u30EA\
    \ O(n \u221An)\ntemplate <class T>\nstruct StaticRangeInversions {\n    int n,\
    \ B, nb;\n    vector<int> c;                    // \u5727\u7E2E\u5F8C\u306E\u5024\
    \n    vector<int> lt, gt;               // lt[R * n + i], gt[L * n + j]\n    vector<long\
    \ long> big;            // big[L * (nb + 1) + R]\n    vector<long long> pre, suf;\n\
    \    vector<pair<int, int>> sorted_;   // \u30D6\u30ED\u30C3\u30AF\u3054\u3068\
    \u306B (\u5024, \u4F4D\u7F6E) \u3092\u6607\u9806\u306B\u4E26\u3079\u305F\u3082\
    \u306E\n\n    StaticRangeInversions(const vector<T> &a, int block = -1) : n(a.size())\
    \ {\n        vector<T> vals = a;\n        sort(vals.begin(), vals.end());\n  \
    \      vals.erase(unique(vals.begin(), vals.end()), vals.end());\n        c.resize(n);\n\
    \        for (int i = 0; i < n; i++) c[i] = lower_bound(vals.begin(), vals.end(),\
    \ a[i]) - vals.begin();\n        B = block > 0 ? block : std::max(16, (int)(1.25\
    \ * sqrt(n)));\n        nb = std::max(1, (n + B - 1) / B);\n        sorted_.resize(n);\n\
    \        for (int i = 0; i < n; i++) sorted_[i] = {c[i], i};\n        for (int\
    \ b = 0; b < nb; b++) sort(sorted_.begin() + std::min(n, b * B), sorted_.begin()\
    \ + std::min(n, (b + 1) * B));\n        vector<pair<int, int>> all = sorted_;\
    \  // \u5168\u4F53\u3092 (\u5024, \u4F4D\u7F6E) \u306E\u6607\u9806\u306B\n   \
    \     sort(all.begin(), all.end());\n        // lt[R][i] = lt[R-1][i] + #{j \u2208\
    \ \u30D6\u30ED\u30C3\u30AF R-1 : c[j] < c[i]} (block(i) < R-1 \u306E\u3068\u304D\
    )\n        lt.assign((size_t)(nb + 1) * n, 0);\n        for (int R = 2; R <= nb;\
    \ R++) {\n            int *cur = &lt[(size_t)R * n], *prv = &lt[(size_t)(R - 1)\
    \ * n];\n            int bs = (R - 1) * B, be = std::min(n, R * B), p = bs;\n\
    \            for (auto [v, i] : all) {\n                while (p < be && sorted_[p].first\
    \ < v) p++;\n                if (i < bs) cur[i] = prv[i] + (p - bs);\n       \
    \     }\n        }\n        // gt[L][j] = gt[L+1][j] + #{i \u2208 \u30D6\u30ED\
    \u30C3\u30AF L : c[i] > c[j]} (block(j) > L \u306E\u3068\u304D)\n        gt.assign((size_t)(nb\
    \ + 1) * n, 0);\n        for (int L = nb - 2; L >= 0; L--) {\n            int\
    \ *cur = &gt[(size_t)L * n], *nxt = &gt[(size_t)(L + 1) * n];\n            int\
    \ bs = L * B, be = std::min(n, (L + 1) * B), p = bs;\n            for (auto [v,\
    \ j] : all) {\n                while (p < be && sorted_[p].first <= v) p++;\n\
    \                if (j >= be) cur[j] = nxt[j] + (be - p);\n            }\n   \
    \     }\n        // \u30D6\u30ED\u30C3\u30AF\u5185\u306E\u8EE2\u5012\u6570\n \
    \       pre.assign(n, 0), suf.assign(n, 0);\n        for (int b = 0; b < nb; b++)\
    \ {\n            int s = b * B, e = std::min(n, (b + 1) * B);\n            for\
    \ (int i = s; i < e; i++) {\n                long long x = i > s ? pre[i - 1]\
    \ : 0;\n                for (int j = s; j < i; j++) x += c[j] > c[i];\n      \
    \          pre[i] = x;\n            }\n            for (int i = e - 1; i >= s;\
    \ i--) {\n                long long x = i + 1 < e ? suf[i + 1] : 0;\n        \
    \        for (int j = i + 1; j < e; j++) x += c[i] > c[j];\n                suf[i]\
    \ = x;\n            }\n        }\n        // big[L][R] = big[L][R-1] + big[L+1][R]\
    \ - big[L+1][R-1] + (\u30D6\u30ED\u30C3\u30AF L \u306E\u8981\u7D20 > \u30D6\u30ED\
    \u30C3\u30AF R-1 \u306E\u8981\u7D20 \u306E\u7D44)\n        big.assign((size_t)(nb\
    \ + 1) * (nb + 1), 0);\n        auto BIG = [&](int L, int R) -> long long & {\
    \ return big[(size_t)L * (nb + 1) + R]; };\n        for (int L = nb - 1; L >=\
    \ 0; L--) {\n            if (L * B < n) BIG(L, L + 1) = suf[L * B];\n        \
    \    for (int R = L + 2; R <= nb; R++) {\n                long long cross = 0;\n\
    \                const int *hi = &lt[(size_t)R * n], *lo = &lt[(size_t)(R - 1)\
    \ * n];\n                for (int i = L * B; i < (L + 1) * B; i++) cross += hi[i]\
    \ - lo[i];\n                BIG(L, R) = BIG(L, R - 1) + BIG(L + 1, R) - BIG(L\
    \ + 1, R - 1) + cross;\n            }\n        }\n    }\n\n    // a[l..r) \u306E\
    \u8EE2\u5012\u6570\n    long long query(int l, int r) const {\n        if (r -\
    \ l <= 1) return 0;\n        int lb = l / B, rb = (r - 1) / B;\n        if (lb\
    \ == rb) {\n            int s = lb * B, e = std::min(n, s + B);\n            long\
    \ long res = pre[r - 1] - (l > s ? pre[l - 1] : 0);\n            // [s, l) \u306E\
    \u8981\u7D20 > [l, r) \u306E\u8981\u7D20 \u306E\u7D44\u3092\u5F15\u304F (\u5024\
    \u306E\u6607\u9806\u306B\u898B\u308B\uFF0E\u540C\u3058\u5024\u306F\u4F4D\u7F6E\
    \u306E\u6607\u9806\u306A\u306E\u3067\u6570\u3048\u306A\u3044)\n            int\
    \ seen = 0;\n            for (int k = s; k < e; k++) {\n                int i\
    \ = sorted_[k].second;\n                if (i < l) res -= seen;\n            \
    \    else if (i < r) seen++;\n            }\n            return res;\n       \
    \ }\n        long long res = suf[l] + pre[r - 1] + big[(size_t)(lb + 1) * (nb\
    \ + 1) + rb];\n        const int *ltr = &lt[(size_t)rb * n], *gtl = &gt[(size_t)(lb\
    \ + 1) * n];\n        for (int i = l; i < (lb + 1) * B; i++) res += ltr[i];\n\
    \        for (int j = rb * B; j < r; j++) res += gtl[j];\n        // \u5DE6\u306E\
    \u7AEF\u306E\u8981\u7D20 > \u53F3\u306E\u7AEF\u306E\u8981\u7D20 \u306E\u7D44 (\u3069\
    \u3061\u3089\u3082\u5024\u306E\u6607\u9806\u306B\u898B\u308B)\n        int ls\
    \ = lb * B, le = (lb + 1) * B, rs = rb * B, re = std::min(n, rs + B);\n      \
    \  int p = rs, smaller = 0;\n        for (int k = ls; k < le; k++) {\n       \
    \     if (sorted_[k].second < l) continue;\n            int v = sorted_[k].first;\n\
    \            while (p < re && sorted_[p].first < v) {\n                if (sorted_[p].second\
    \ < r) smaller++;\n                p++;\n            }\n            res += smaller;\n\
    \        }\n        return res;\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/static_range_inversions.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/static_range_inversions_query.test.cpp
  - test/unittest/static_range_queries.test.cpp
documentation_of: data_structure/static_range_inversions.hpp
layout: document
title: "\u9759\u7684\u306A\u533A\u9593\u8EE2\u5012\u6570 (Static Range Inversions\
  \ Query)"
---

## 概要

静的な数列 $a$ について、区間 $[l, r)$ の転倒数（$l \le i < j < r$ かつ $a_i > a_j$ の組の数）を $O(\sqrt n)$ で答える（**オンライン**、平方分割）。

大きさ $B$ のブロックに分け、次を前計算する。

| 表 | 意味 |
| --- | --- |
| `lt[R][i]` | $i$ のブロックより右、ブロック $R$ の手前までの要素で $a_i$ より小さいものの個数 |
| `gt[L][j]` | ブロック $L$ から $j$ のブロックの手前までの要素で $a_j$ より大きいものの個数 |
| `big[L][R]` | ブロック $L, \ldots, R-1$ の中の転倒数 |
| `pre[i]`, `suf[i]` | $i$ のブロックの中で、先頭から $i$ まで / $i$ から末尾までの転倒数 |
| ブロックごとの (値, 位置) の昇順リスト | 端どうしの組を数えるのに使う |

クエリは「左の端数・間の完全なブロック・右の端数」に分け、(端数の中) + (ブロックの中) + (端数 × ブロック: `lt`, `gt` を順に足す) + (左の端数 × 右の端数: 昇順リストのマージ) で数える。`lt` / `gt` は位置の順に並べてあるので、端数を順に見るとき連続アクセスになって速い。

## 使い方

```cpp
StaticRangeInversions<int> inv(a);       // vector<int> a
StaticRangeInversions<int> inv2(a, 256); // ブロックの大きさを指定
inv.query(l, r);                         // a[l..r) の転倒数 (long long)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `StaticRangeInversions<T>(const vector<T> &a, int block = -1)` | 構築（`block` 省略で $1.25\sqrt n$） | $O(n \sqrt n)$ |
| `long long query(int l, int r)` | 区間転倒数 | $O(\sqrt n)$ |

## 注意

- メモリは $2 n \cdot n / B$ 個の int（$n = 10^5$ で約 200 MB）。メモリが厳しいときは `block` を大きくする（クエリは遅くなる）。
- クエリを先読みできるなら Mo's algorithm + BIT（$O(n \sqrt q \log n)$）でも解ける。こちらは $\log$ が付かない。
