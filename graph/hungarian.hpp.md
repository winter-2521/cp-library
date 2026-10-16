---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/assignment.test.cpp
    title: test/assignment.test.cpp
  - icon: ':x:'
    path: test/unittest/graph_optimization.test.cpp
    title: test/unittest/graph_optimization.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ 3 \"graph/hungarian.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\n\
    // \u5272\u5F53\u554F\u984C (Hungarian \u6CD5)\uFF0En \xD7 m (n <= m) \u306E\u884C\
    \u5217 a \u3067\uFF0C\u5404\u884C\u306B\u76F8\u7570\u306A\u308B\u5217\u3092\u5272\
    \u308A\u5F53\u3066\u3066\u548C\u3092\u6700\u5C0F\u306B\u3059\u308B\uFF0EO(n^2\
    \ m)\n// \u884C i \u3092 1 \u3064\u305A\u3064\u8FFD\u52A0\u3057\uFF0C\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB (\u53CC\u5BFE\u5909\u6570) u, v \u3092\u4FDD\u3063\u305F\
    \u307E\u307E\uFF0CDijkstra \u98A8\u306B\u6700\u77ED\u306E\u5897\u52A0\u8DEF\u3092\
    \u898B\u3064\u3051\u308B\n// \u8FD4\u308A\u5024: {\u6700\u5C0F\u5024, p (p[i]\
    \ = \u884C i \u306B\u5272\u308A\u5F53\u3066\u305F\u5217)}\ntemplate <class T>\n\
    pair<T, vector<int>> hungarian(const vector<vector<T>> &a) {\n    int n = a.size();\n\
    \    if (n == 0) return {T(0), {}};\n    int m = a[0].size();\n    assert(n <=\
    \ m);\n    const T INF = numeric_limits<T>::max() / 2;\n    // 1-indexed\uFF0E\
    \u5217 0 \u306F\u300C\u307E\u3060\u5272\u308A\u5F53\u3066\u3066\u3044\u306A\u3044\
    \u884C\u300D\u3092\u7F6E\u304F\u4EEE\u306E\u5217\n    vector<T> u(n + 1, 0), v(m\
    \ + 1, 0), minv(m + 1);\n    vector<int> p(m + 1, 0), way(m + 1, 0);  // p[j]:\
    \ \u5217 j \u306B\u5272\u308A\u5F53\u3066\u305F\u884C\n    vector<char> used(m\
    \ + 1);\n    for (int i = 1; i <= n; i++) {\n        p[0] = i;\n        int j0\
    \ = 0;\n        fill(minv.begin(), minv.end(), INF);\n        fill(used.begin(),\
    \ used.end(), 0);\n        do {\n            used[j0] = 1;\n            int i0\
    \ = p[j0], j1 = 0;\n            T delta = INF;\n            const T *row = a[i0\
    \ - 1].data();\n            for (int j = 1; j <= m; j++) {\n                if\
    \ (used[j]) continue;\n                T cur = row[j - 1] - u[i0] - v[j];\n  \
    \              if (cur < minv[j]) minv[j] = cur, way[j] = j0;\n              \
    \  if (minv[j] < delta) delta = minv[j], j1 = j;\n            }\n            for\
    \ (int j = 0; j <= m; j++) {\n                if (used[j]) u[p[j]] += delta, v[j]\
    \ -= delta;\n                else minv[j] -= delta;\n            }\n         \
    \   j0 = j1;\n        } while (p[j0] != 0);\n        // \u5897\u52A0\u8DEF\u3092\
    \u53CD\u8EE2\n        do {\n            int j1 = way[j0];\n            p[j0] =\
    \ p[j1];\n            j0 = j1;\n        } while (j0);\n    }\n    vector<int>\
    \ ans(n);\n    for (int j = 1; j <= m; j++)\n        if (p[j]) ans[p[j] - 1] =\
    \ j - 1;\n    T total = 0;\n    for (int i = 0; i < n; i++) total += a[i][ans[i]];\n\
    \    return {total, ans};\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u5272\u5F53\u554F\u984C (Hungarian \u6CD5)\uFF0En \xD7 m (n <= m) \u306E\
    \u884C\u5217 a \u3067\uFF0C\u5404\u884C\u306B\u76F8\u7570\u306A\u308B\u5217\u3092\
    \u5272\u308A\u5F53\u3066\u3066\u548C\u3092\u6700\u5C0F\u306B\u3059\u308B\uFF0E\
    O(n^2 m)\n// \u884C i \u3092 1 \u3064\u305A\u3064\u8FFD\u52A0\u3057\uFF0C\u30DD\
    \u30C6\u30F3\u30B7\u30E3\u30EB (\u53CC\u5BFE\u5909\u6570) u, v \u3092\u4FDD\u3063\
    \u305F\u307E\u307E\uFF0CDijkstra \u98A8\u306B\u6700\u77ED\u306E\u5897\u52A0\u8DEF\
    \u3092\u898B\u3064\u3051\u308B\n// \u8FD4\u308A\u5024: {\u6700\u5C0F\u5024, p\
    \ (p[i] = \u884C i \u306B\u5272\u308A\u5F53\u3066\u305F\u5217)}\ntemplate <class\
    \ T>\npair<T, vector<int>> hungarian(const vector<vector<T>> &a) {\n    int n\
    \ = a.size();\n    if (n == 0) return {T(0), {}};\n    int m = a[0].size();\n\
    \    assert(n <= m);\n    const T INF = numeric_limits<T>::max() / 2;\n    //\
    \ 1-indexed\uFF0E\u5217 0 \u306F\u300C\u307E\u3060\u5272\u308A\u5F53\u3066\u3066\
    \u3044\u306A\u3044\u884C\u300D\u3092\u7F6E\u304F\u4EEE\u306E\u5217\n    vector<T>\
    \ u(n + 1, 0), v(m + 1, 0), minv(m + 1);\n    vector<int> p(m + 1, 0), way(m +\
    \ 1, 0);  // p[j]: \u5217 j \u306B\u5272\u308A\u5F53\u3066\u305F\u884C\n    vector<char>\
    \ used(m + 1);\n    for (int i = 1; i <= n; i++) {\n        p[0] = i;\n      \
    \  int j0 = 0;\n        fill(minv.begin(), minv.end(), INF);\n        fill(used.begin(),\
    \ used.end(), 0);\n        do {\n            used[j0] = 1;\n            int i0\
    \ = p[j0], j1 = 0;\n            T delta = INF;\n            const T *row = a[i0\
    \ - 1].data();\n            for (int j = 1; j <= m; j++) {\n                if\
    \ (used[j]) continue;\n                T cur = row[j - 1] - u[i0] - v[j];\n  \
    \              if (cur < minv[j]) minv[j] = cur, way[j] = j0;\n              \
    \  if (minv[j] < delta) delta = minv[j], j1 = j;\n            }\n            for\
    \ (int j = 0; j <= m; j++) {\n                if (used[j]) u[p[j]] += delta, v[j]\
    \ -= delta;\n                else minv[j] -= delta;\n            }\n         \
    \   j0 = j1;\n        } while (p[j0] != 0);\n        // \u5897\u52A0\u8DEF\u3092\
    \u53CD\u8EE2\n        do {\n            int j1 = way[j0];\n            p[j0] =\
    \ p[j1];\n            j0 = j1;\n        } while (j0);\n    }\n    vector<int>\
    \ ans(n);\n    for (int j = 1; j <= m; j++)\n        if (p[j]) ans[p[j] - 1] =\
    \ j - 1;\n    T total = 0;\n    for (int i = 0; i < n; i++) total += a[i][ans[i]];\n\
    \    return {total, ans};\n}\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/hungarian.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/unittest/graph_optimization.test.cpp
  - test/assignment.test.cpp
documentation_of: graph/hungarian.hpp
layout: document
title: "\u5272\u5F53\u554F\u984C (Hungarian \u6CD5)"
---

## 概要

$n \times m$（$n \le m$）の行列 $a$ について、各行に相異なる列を 1 つずつ割り当て、$\sum_i a_{i, p_i}$ を最小にする。$O(n^2 m)$。

行を 1 つずつ追加していく。行・列のポテンシャル（双対変数）$u, v$ を「$a_{ij} - u_i - v_j \ge 0$」が保たれるように持ち、被約費用 $a_{ij} - u_i - v_j$ で Dijkstra 風に最短の増加路を見つけて割当を 1 つ増やす。

## 使い方

```cpp
vector<vector<long long>> a(n, vector<long long>(m));
auto [cost, p] = hungarian(a);   // p[i] = 行 i に割り当てた列
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `pair<T, vector<int>> hungarian(const vector<vector<T>> &a)` | 最小値と割当 | $O(n^2 m)$ |

## 注意

- 最大化したいときは符号を反転して渡す。
- 負の値があってもよい。
- $n > m$ のときは転置してから渡す。
