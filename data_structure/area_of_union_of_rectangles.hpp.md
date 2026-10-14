---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/area_of_union_of_rectangles.test.cpp
    title: test/area_of_union_of_rectangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/rectangle_add.test.cpp
    title: test/unittest/rectangle_add.test.cpp
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
    \ 3 \"data_structure/area_of_union_of_rectangles.hpp\"\n\n// \u9577\u65B9\u5F62\
    \u306E\u548C\u96C6\u5408\u306E\u9762\u7A4D (Area of Union of Rectangles)\n// x\
    \ \u306E\u5C0F\u3055\u3044\u9806\u306B\u8D70\u67FB\u3057\uFF0Cy \u65B9\u5411\u3092\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3067\u7BA1\u7406\u3059\u308B\uFF0E\u5404\
    \u30CE\u30FC\u30C9\u306F\n//   cnt: \u3053\u306E\u30CE\u30FC\u30C9\u306E\u533A\
    \u9593\u300C\u5168\u4F53\u300D\u3092\u3061\u3087\u3046\u3069\u8986\u3063\u3066\
    \u3044\u308B\u9577\u65B9\u5F62\u306E\u6570 (\u5B50\u306B\u306F\u4F1D\u3048\u306A\
    \u3044)\n//   cov: \u3053\u306E\u30CE\u30FC\u30C9\u306E\u533A\u9593\u306E\u3046\
    \u3061\uFF0C\u3053\u306E\u30CE\u30FC\u30C9\u4EE5\u4E0B\u306E cnt \u3067\u8986\u308F\
    \u308C\u3066\u3044\u308B\u9577\u3055\n// \u3092\u6301\u3061\uFF0Ccov = (cnt >\
    \ 0 ? \u533A\u9593\u306E\u9577\u3055 : \u5B50\u306E cov \u306E\u548C)\uFF0E\u9045\
    \u5EF6\u4F1D\u64AD\u304C\u8981\u3089\u306A\u3044\u306E\u3067\u901F\u3044\uFF0E\
    O(n log n)\n// \u9577\u65B9\u5F62 i \u306F [l[i], r[i]] \xD7 [d[i], u[i]] (\u9762\
    \u7A4D\u306F\u9589\u533A\u9593\u3067\u3082\u534A\u958B\u533A\u9593\u3067\u3082\
    \u540C\u3058)\ntemplate <class T>\nT area_of_union_of_rectangles(const vector<T>\
    \ &l, const vector<T> &d, const vector<T> &r, const vector<T> &u) {\n    int n\
    \ = l.size();\n    // y \u5EA7\u6A19\u3092 (\u5024, 2i \u307E\u305F\u306F 2i+1)\
    \ \u3067\u30BD\u30FC\u30C8\u3057\u3066\u756A\u53F7\u3092\u632F\u308B (\u4E8C\u5206\
    \u63A2\u7D22\u3057\u306A\u3044)\n    vector<pair<T, int>> yv(2 * n);\n    for\
    \ (int i = 0; i < n; i++) yv[2 * i] = {d[i], 2 * i}, yv[2 * i + 1] = {u[i], 2\
    \ * i + 1};\n    sort(yv.begin(), yv.end());\n    vector<T> ys;\n    ys.reserve(2\
    \ * n);\n    vector<int> yi(2 * n);  // yi[2i] = d[i] \u306E\u756A\u53F7\uFF0C\
    yi[2i+1] = u[i] \u306E\u756A\u53F7\n    for (auto &[y, id] : yv) {\n        if\
    \ (ys.empty() || ys.back() != y) ys.push_back(y);\n        yi[id] = ys.size()\
    \ - 1;\n    }\n    int m = (int)ys.size() - 1;\n    if (m <= 0) return T(0);\n\
    \    int sz = 1;\n    while (sz < m) sz <<= 1;\n    struct Node {\n        T cov,\
    \ len;\n        int cnt;\n    };\n    vector<Node> t(2 * sz, Node{T(0), T(0),\
    \ 0});\n    for (int i = 0; i < m; i++) t[sz + i].len = ys[i + 1] - ys[i];\n \
    \   for (int k = sz - 1; k >= 1; k--) t[k].len = t[2 * k].len + t[2 * k + 1].len;\n\
    \    auto fix = [&](int k) { t[k].cov = t[k].cnt ? t[k].len : (k < sz ? t[2 *\
    \ k].cov + t[2 * k + 1].cov : T(0)); };\n    auto update = [&](int a, int b, int\
    \ c) {  // y \u306E\u533A\u9593 [a, b) \u306E\u88AB\u8986\u56DE\u6570\u306B c\
    \ \u3092\u8DB3\u3059\n        int a0 = a + sz, b0 = b + sz;\n        for (int\
    \ x = a0, y = b0; x < y; x >>= 1, y >>= 1) {\n            if (x & 1) t[x].cnt\
    \ += c, fix(x), x++;\n            if (y & 1) --y, t[y].cnt += c, fix(y);\n   \
    \     }\n        for (int k = a0 >> 1; k; k >>= 1) fix(k);\n        for (int k\
    \ = (b0 - 1) >> 1; k; k >>= 1) fix(k);\n    };\n    // \u30A4\u30D9\u30F3\u30C8\
    : \u9577\u65B9\u5F62 i \u306E\u5DE6\u7AEF\u3067 +1 (\u756A\u53F7 i)\uFF0C\u53F3\
    \u7AEF\u3067 -1 (\u756A\u53F7 ~i)\n    vector<pair<T, int>> ev;\n    ev.reserve(2\
    \ * n);\n    for (int i = 0; i < n; i++) ev.emplace_back(l[i], i), ev.emplace_back(r[i],\
    \ ~i);\n    sort(ev.begin(), ev.end());\n    T res(0);\n    for (int k = 0; k\
    \ < (int)ev.size(); k++) {\n        if (k > 0) res += t[1].cov * (ev[k].first\
    \ - ev[k - 1].first);\n        int i = ev[k].second;\n        if (i >= 0) update(yi[2\
    \ * i], yi[2 * i + 1], 1);\n        else update(yi[2 * ~i], yi[2 * ~i + 1], -1);\n\
    \    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// \u9577\u65B9\u5F62\u306E\
    \u548C\u96C6\u5408\u306E\u9762\u7A4D (Area of Union of Rectangles)\n// x \u306E\
    \u5C0F\u3055\u3044\u9806\u306B\u8D70\u67FB\u3057\uFF0Cy \u65B9\u5411\u3092\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\u3067\u7BA1\u7406\u3059\u308B\uFF0E\u5404\u30CE\
    \u30FC\u30C9\u306F\n//   cnt: \u3053\u306E\u30CE\u30FC\u30C9\u306E\u533A\u9593\
    \u300C\u5168\u4F53\u300D\u3092\u3061\u3087\u3046\u3069\u8986\u3063\u3066\u3044\
    \u308B\u9577\u65B9\u5F62\u306E\u6570 (\u5B50\u306B\u306F\u4F1D\u3048\u306A\u3044\
    )\n//   cov: \u3053\u306E\u30CE\u30FC\u30C9\u306E\u533A\u9593\u306E\u3046\u3061\
    \uFF0C\u3053\u306E\u30CE\u30FC\u30C9\u4EE5\u4E0B\u306E cnt \u3067\u8986\u308F\u308C\
    \u3066\u3044\u308B\u9577\u3055\n// \u3092\u6301\u3061\uFF0Ccov = (cnt > 0 ? \u533A\
    \u9593\u306E\u9577\u3055 : \u5B50\u306E cov \u306E\u548C)\uFF0E\u9045\u5EF6\u4F1D\
    \u64AD\u304C\u8981\u3089\u306A\u3044\u306E\u3067\u901F\u3044\uFF0EO(n log n)\n\
    // \u9577\u65B9\u5F62 i \u306F [l[i], r[i]] \xD7 [d[i], u[i]] (\u9762\u7A4D\u306F\
    \u9589\u533A\u9593\u3067\u3082\u534A\u958B\u533A\u9593\u3067\u3082\u540C\u3058\
    )\ntemplate <class T>\nT area_of_union_of_rectangles(const vector<T> &l, const\
    \ vector<T> &d, const vector<T> &r, const vector<T> &u) {\n    int n = l.size();\n\
    \    // y \u5EA7\u6A19\u3092 (\u5024, 2i \u307E\u305F\u306F 2i+1) \u3067\u30BD\
    \u30FC\u30C8\u3057\u3066\u756A\u53F7\u3092\u632F\u308B (\u4E8C\u5206\u63A2\u7D22\
    \u3057\u306A\u3044)\n    vector<pair<T, int>> yv(2 * n);\n    for (int i = 0;\
    \ i < n; i++) yv[2 * i] = {d[i], 2 * i}, yv[2 * i + 1] = {u[i], 2 * i + 1};\n\
    \    sort(yv.begin(), yv.end());\n    vector<T> ys;\n    ys.reserve(2 * n);\n\
    \    vector<int> yi(2 * n);  // yi[2i] = d[i] \u306E\u756A\u53F7\uFF0Cyi[2i+1]\
    \ = u[i] \u306E\u756A\u53F7\n    for (auto &[y, id] : yv) {\n        if (ys.empty()\
    \ || ys.back() != y) ys.push_back(y);\n        yi[id] = ys.size() - 1;\n    }\n\
    \    int m = (int)ys.size() - 1;\n    if (m <= 0) return T(0);\n    int sz = 1;\n\
    \    while (sz < m) sz <<= 1;\n    struct Node {\n        T cov, len;\n      \
    \  int cnt;\n    };\n    vector<Node> t(2 * sz, Node{T(0), T(0), 0});\n    for\
    \ (int i = 0; i < m; i++) t[sz + i].len = ys[i + 1] - ys[i];\n    for (int k =\
    \ sz - 1; k >= 1; k--) t[k].len = t[2 * k].len + t[2 * k + 1].len;\n    auto fix\
    \ = [&](int k) { t[k].cov = t[k].cnt ? t[k].len : (k < sz ? t[2 * k].cov + t[2\
    \ * k + 1].cov : T(0)); };\n    auto update = [&](int a, int b, int c) {  // y\
    \ \u306E\u533A\u9593 [a, b) \u306E\u88AB\u8986\u56DE\u6570\u306B c \u3092\u8DB3\
    \u3059\n        int a0 = a + sz, b0 = b + sz;\n        for (int x = a0, y = b0;\
    \ x < y; x >>= 1, y >>= 1) {\n            if (x & 1) t[x].cnt += c, fix(x), x++;\n\
    \            if (y & 1) --y, t[y].cnt += c, fix(y);\n        }\n        for (int\
    \ k = a0 >> 1; k; k >>= 1) fix(k);\n        for (int k = (b0 - 1) >> 1; k; k >>=\
    \ 1) fix(k);\n    };\n    // \u30A4\u30D9\u30F3\u30C8: \u9577\u65B9\u5F62 i \u306E\
    \u5DE6\u7AEF\u3067 +1 (\u756A\u53F7 i)\uFF0C\u53F3\u7AEF\u3067 -1 (\u756A\u53F7\
    \ ~i)\n    vector<pair<T, int>> ev;\n    ev.reserve(2 * n);\n    for (int i =\
    \ 0; i < n; i++) ev.emplace_back(l[i], i), ev.emplace_back(r[i], ~i);\n    sort(ev.begin(),\
    \ ev.end());\n    T res(0);\n    for (int k = 0; k < (int)ev.size(); k++) {\n\
    \        if (k > 0) res += t[1].cov * (ev[k].first - ev[k - 1].first);\n     \
    \   int i = ev[k].second;\n        if (i >= 0) update(yi[2 * i], yi[2 * i + 1],\
    \ 1);\n        else update(yi[2 * ~i], yi[2 * ~i + 1], -1);\n    }\n    return\
    \ res;\n}\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/area_of_union_of_rectangles.hpp
  requiredBy: []
  timestamp: '2026-10-15 00:08:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/rectangle_add.test.cpp
  - test/area_of_union_of_rectangles.test.cpp
documentation_of: data_structure/area_of_union_of_rectangles.hpp
layout: document
title: "\u9577\u65B9\u5F62\u306E\u548C\u96C6\u5408\u306E\u9762\u7A4D (Area of Union\
  \ of Rectangles)"
---

## 概要

$n$ 個の長方形の和集合の面積を $O(n \log n)$ で求める。

$x$ の小さい順に長方形の左端（追加）・右端（削除）を処理し、$y$ 方向を「覆っている長方形の数」で管理するセグメント木で、隣り合うイベントの間の幅 × 覆われている $y$ の長さ を足していく。

セグメント木の各ノードは

- `cnt`：ノードの区間 **全体** をちょうど覆っている長方形の数（子には伝えない）
- `cov`：ノードの区間のうち覆われている長さ ＝ `cnt > 0` ならノードの区間の長さ、そうでなければ子の `cov` の和

を持つ。追加と削除は必ず対になって同じノードの集合に来るので、遅延伝播がいらない。

## 使い方

```cpp
vector<long long> l(n), d(n), r(n), u(n);   // 長方形 i は [l[i], r[i]] × [d[i], u[i]]
long long area = area_of_union_of_rectangles(l, d, r, u);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `T area_of_union_of_rectangles(l, d, r, u)` | 和集合の面積 | $O(n \log n)$ |

## 注意

- 面積が `T` に収まること（座標 $10^9$ なら面積は $10^{18}$ 以下で `long long` に収まる）。
