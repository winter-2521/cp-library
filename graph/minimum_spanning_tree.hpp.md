---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/minimum_spanning_tree.test.cpp
    title: test/minimum_spanning_tree.test.cpp
  - icon: ':x:'
    path: test/unittest/graph_optimization.test.cpp
    title: test/unittest/graph_optimization.test.cpp
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
    \ 3 \"graph/minimum_spanning_tree.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u6700\u5C0F\u5168\u57DF\u6728 (Kruskal)\uFF0E\u8FBA\u3092\u91CD\u307F\u306E\
    \u6607\u9806\u306B\u898B\u3066\uFF0C\u4E21\u7AEF\u304C\u307E\u3060\u3064\u306A\
    \u304C\u3063\u3066\u3044\u306A\u3051\u308C\u3070\u63A1\u7528\u3059\u308B\uFF0E\
    O(m log m)\n// \u8FD4\u308A\u5024: {\u91CD\u307F\u306E\u548C, \u63A1\u7528\u3057\
    \u305F\u8FBA\u306E\u756A\u53F7\u306E\u5217}\uFF0E\u975E\u9023\u7D50\u306A\u3089\
    \u6700\u5C0F\u5168\u57DF\u68EE\ntemplate <class T>\npair<T, vector<int>> minimum_spanning_tree(int\
    \ n, const vector<tuple<int, int, T>> &edges) {\n    int m = edges.size();\n \
    \   vector<pair<T, int>> ord(m);\n    for (int i = 0; i < m; i++) ord[i] = {get<2>(edges[i]),\
    \ i};\n    sort(ord.begin(), ord.end());\n    vector<int> par(n, -1);\n    auto\
    \ find = [&](int x) {\n        while (par[x] >= 0) {\n            if (par[par[x]]\
    \ >= 0) par[x] = par[par[x]];  // \u7D4C\u8DEF\u3092\u534A\u5206\u306B\u3059\u308B\
    \n            x = par[x];\n        }\n        return x;\n    };\n    T total =\
    \ 0;\n    vector<int> used;\n    used.reserve(n ? n - 1 : 0);\n    for (auto &[w,\
    \ i] : ord) {\n        int a = find(get<0>(edges[i])), b = find(get<1>(edges[i]));\n\
    \        if (a == b) continue;\n        if (par[a] > par[b]) swap(a, b);\n   \
    \     par[a] += par[b], par[b] = a;\n        total += w, used.push_back(i);\n\
    \        if ((int)used.size() == n - 1) break;\n    }\n    return {total, used};\n\
    }\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u6700\u5C0F\u5168\u57DF\u6728 (Kruskal)\uFF0E\u8FBA\u3092\u91CD\u307F\u306E\
    \u6607\u9806\u306B\u898B\u3066\uFF0C\u4E21\u7AEF\u304C\u307E\u3060\u3064\u306A\
    \u304C\u3063\u3066\u3044\u306A\u3051\u308C\u3070\u63A1\u7528\u3059\u308B\uFF0E\
    O(m log m)\n// \u8FD4\u308A\u5024: {\u91CD\u307F\u306E\u548C, \u63A1\u7528\u3057\
    \u305F\u8FBA\u306E\u756A\u53F7\u306E\u5217}\uFF0E\u975E\u9023\u7D50\u306A\u3089\
    \u6700\u5C0F\u5168\u57DF\u68EE\ntemplate <class T>\npair<T, vector<int>> minimum_spanning_tree(int\
    \ n, const vector<tuple<int, int, T>> &edges) {\n    int m = edges.size();\n \
    \   vector<pair<T, int>> ord(m);\n    for (int i = 0; i < m; i++) ord[i] = {get<2>(edges[i]),\
    \ i};\n    sort(ord.begin(), ord.end());\n    vector<int> par(n, -1);\n    auto\
    \ find = [&](int x) {\n        while (par[x] >= 0) {\n            if (par[par[x]]\
    \ >= 0) par[x] = par[par[x]];  // \u7D4C\u8DEF\u3092\u534A\u5206\u306B\u3059\u308B\
    \n            x = par[x];\n        }\n        return x;\n    };\n    T total =\
    \ 0;\n    vector<int> used;\n    used.reserve(n ? n - 1 : 0);\n    for (auto &[w,\
    \ i] : ord) {\n        int a = find(get<0>(edges[i])), b = find(get<1>(edges[i]));\n\
    \        if (a == b) continue;\n        if (par[a] > par[b]) swap(a, b);\n   \
    \     par[a] += par[b], par[b] = a;\n        total += w, used.push_back(i);\n\
    \        if ((int)used.size() == n - 1) break;\n    }\n    return {total, used};\n\
    }\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/minimum_spanning_tree.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/minimum_spanning_tree.test.cpp
  - test/unittest/graph_optimization.test.cpp
documentation_of: graph/minimum_spanning_tree.hpp
layout: document
title: "\u6700\u5C0F\u5168\u57DF\u6728 (Kruskal)"
---

## 概要

無向グラフの最小全域木（非連結なら最小全域森）を Kruskal 法で求める。$O(m \log m)$。

辺を重みの昇順に見て、両端がまだつながっていなければ採用する（Union-Find で判定）。

## 使い方

```cpp
vector<tuple<int, int, long long>> edges;   // (u, v, 重み)
auto [w, used] = minimum_spanning_tree(n, edges);   // 重みの和, 採用した辺の番号
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `pair<T, vector<int>> minimum_spanning_tree(int n, edges)` | 重みの和と採用した辺の番号の列 | $O(m \log m)$ |

## 注意

- 非連結なら最小全域森（採用辺は $n - (\text{連結成分数})$ 本）を返す。連結か確かめたいときは `used.size() == n - 1` を見る。
- 重みが同じ辺は番号が小さい方を優先する。
