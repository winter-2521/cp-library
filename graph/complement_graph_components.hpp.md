---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/csr.hpp
    title: "CSR (\u96A3\u63A5\u30EA\u30B9\u30C8\u3092 1 \u672C\u306E\u914D\u5217\u3067\
      \u6301\u3064)"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/connected_components_of_complement_graph.test.cpp
    title: test/connected_components_of_complement_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/graph_components.test.cpp
    title: test/unittest/graph_components.test.cpp
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
    \ 3 \"graph/csr.hpp\"\n\n// \u96A3\u63A5\u30EA\u30B9\u30C8\u3092 1 \u672C\u306E\
    \u914D\u5217\u3067\u6301\u3064 (Compressed Sparse Row)\n// \u9802\u70B9 v \u306E\
    \u96A3\u63A5\u306F elist[start[v] .. start[v+1])\uFF0Evector<vector<int>> \u3088\
    \u308A\u901F\u304F\u30E1\u30E2\u30EA\u3082\u5C11\u306A\u3044\ntemplate <class\
    \ E>\nstruct CSR {\n    vector<int> start;\n    vector<E> elist;\n    CSR() =\
    \ default;\n    // edges[i] = (from, \u4E2D\u8EAB)\n    CSR(int n, const vector<pair<int,\
    \ E>> &edges) : start(n + 1, 0), elist(edges.size()) {\n        for (auto &e :\
    \ edges) start[e.first + 1]++;\n        for (int i = 1; i <= n; i++) start[i]\
    \ += start[i - 1];\n        vector<int> pos(start.begin(), start.end() - 1);\n\
    \        for (auto &e : edges) elist[pos[e.first]++] = e.second;\n    }\n    int\
    \ size() const { return (int)start.size() - 1; }\n};\n#line 4 \"graph/complement_graph_components.hpp\"\
    \n\n// \u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3\uFF0E\
    O(n + m)\n// \u307E\u3060\u3069\u306E\u6210\u5206\u306B\u3082\u5165\u3063\u3066\
    \u3044\u306A\u3044\u9802\u70B9\u3092\u9023\u7D50\u30EA\u30B9\u30C8\u3067\u6301\
    \u3061\uFF0CBFS \u3067\u9802\u70B9 v \u304B\u3089\u300Cv \u3068\u5143\u306E\u30B0\
    \u30E9\u30D5\u3067\u96A3\u63A5\u3057\u3066\u3044\u306A\u3044\u672A\u8A2A\u554F\
    \u9802\u70B9\u300D\u3092\u5168\u90E8\u53D6\u308B\uFF0E\n// \u672A\u8A2A\u554F\u30EA\
    \u30B9\u30C8\u3092 1 \u5468\u3059\u308B\u3068\u304D\uFF0C\u53D6\u3089\u306A\u304B\
    \u3063\u305F\u9802\u70B9\u306F v \u306E\u96A3\u63A5\u9802\u70B9\u306A\u306E\u3067\
    \uFF0C1 \u5468\u306E\u30B3\u30B9\u30C8\u306F deg(v) + (\u53D6\u3063\u305F\u6570\
    ) \u3067\u6291\u3048\u3089\u308C\u308B\ninline vector<vector<int>> complement_graph_components(int\
    \ n, const vector<pair<int, int>> &edges) {\n    vector<pair<int, int>> el;\n\
    \    el.reserve(2 * edges.size());\n    for (auto [a, b] : edges) el.push_back({a,\
    \ b}), el.push_back({b, a});\n    CSR<int> g(n, el);\n    // \u672A\u8A2A\u554F\
    \u9802\u70B9\u306E\u53CC\u65B9\u5411\u30EA\u30B9\u30C8 (\u756A\u5175 n)\n    vector<int>\
    \ nx(n + 1), pv(n + 1);\n    for (int i = 0; i <= n; i++) nx[i] = (i + 1) % (n\
    \ + 1), pv[i] = (i + n) % (n + 1);\n    auto erase = [&](int v) { nx[pv[v]] =\
    \ nx[v], pv[nx[v]] = pv[v]; };\n    vector<int> stamp(n, -1), que;\n    que.reserve(n);\n\
    \    vector<vector<int>> res;\n    while (nx[n] != n) {\n        int s = nx[n];\n\
    \        erase(s);\n        que.clear(), que.push_back(s);\n        for (size_t\
    \ h = 0; h < que.size(); h++) {\n            int v = que[h];\n            for\
    \ (int i = g.start[v]; i < g.start[v + 1]; i++) stamp[g.elist[i]] = v;\n     \
    \       for (int u = nx[n]; u != n;) {\n                int nu = nx[u];\n    \
    \            if (stamp[u] != v) erase(u), que.push_back(u);\n                u\
    \ = nu;\n            }\n        }\n        res.push_back(que);\n    }\n    return\
    \ res;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"csr.hpp\"\n\n// \u88DC\
    \u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3\uFF0EO(n + m)\n//\
    \ \u307E\u3060\u3069\u306E\u6210\u5206\u306B\u3082\u5165\u3063\u3066\u3044\u306A\
    \u3044\u9802\u70B9\u3092\u9023\u7D50\u30EA\u30B9\u30C8\u3067\u6301\u3061\uFF0C\
    BFS \u3067\u9802\u70B9 v \u304B\u3089\u300Cv \u3068\u5143\u306E\u30B0\u30E9\u30D5\
    \u3067\u96A3\u63A5\u3057\u3066\u3044\u306A\u3044\u672A\u8A2A\u554F\u9802\u70B9\
    \u300D\u3092\u5168\u90E8\u53D6\u308B\uFF0E\n// \u672A\u8A2A\u554F\u30EA\u30B9\u30C8\
    \u3092 1 \u5468\u3059\u308B\u3068\u304D\uFF0C\u53D6\u3089\u306A\u304B\u3063\u305F\
    \u9802\u70B9\u306F v \u306E\u96A3\u63A5\u9802\u70B9\u306A\u306E\u3067\uFF0C1 \u5468\
    \u306E\u30B3\u30B9\u30C8\u306F deg(v) + (\u53D6\u3063\u305F\u6570) \u3067\u6291\
    \u3048\u3089\u308C\u308B\ninline vector<vector<int>> complement_graph_components(int\
    \ n, const vector<pair<int, int>> &edges) {\n    vector<pair<int, int>> el;\n\
    \    el.reserve(2 * edges.size());\n    for (auto [a, b] : edges) el.push_back({a,\
    \ b}), el.push_back({b, a});\n    CSR<int> g(n, el);\n    // \u672A\u8A2A\u554F\
    \u9802\u70B9\u306E\u53CC\u65B9\u5411\u30EA\u30B9\u30C8 (\u756A\u5175 n)\n    vector<int>\
    \ nx(n + 1), pv(n + 1);\n    for (int i = 0; i <= n; i++) nx[i] = (i + 1) % (n\
    \ + 1), pv[i] = (i + n) % (n + 1);\n    auto erase = [&](int v) { nx[pv[v]] =\
    \ nx[v], pv[nx[v]] = pv[v]; };\n    vector<int> stamp(n, -1), que;\n    que.reserve(n);\n\
    \    vector<vector<int>> res;\n    while (nx[n] != n) {\n        int s = nx[n];\n\
    \        erase(s);\n        que.clear(), que.push_back(s);\n        for (size_t\
    \ h = 0; h < que.size(); h++) {\n            int v = que[h];\n            for\
    \ (int i = g.start[v]; i < g.start[v + 1]; i++) stamp[g.elist[i]] = v;\n     \
    \       for (int u = nx[n]; u != n;) {\n                int nu = nx[u];\n    \
    \            if (stamp[u] != v) erase(u), que.push_back(u);\n                u\
    \ = nu;\n            }\n        }\n        res.push_back(que);\n    }\n    return\
    \ res;\n}\n"
  dependsOn:
  - template.hpp
  - graph/csr.hpp
  isVerificationFile: false
  path: graph/complement_graph_components.hpp
  requiredBy: []
  timestamp: '2026-10-15 00:32:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/graph_components.test.cpp
  - test/connected_components_of_complement_graph.test.cpp
documentation_of: graph/complement_graph_components.hpp
layout: document
title: "\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
---

## 概要

単純無向グラフの **補グラフ**（辺がないところに辺を張ったグラフ）の連結成分を、補グラフを作らずに $O(n + m)$ で求める。

まだどの成分にも入っていない頂点を連結リストで持ち、BFS で頂点 $v$ を取り出したら、$v$ の隣接頂点に印を付けてから未訪問リストを 1 周し、印のない頂点（補グラフで $v$ と隣接）を全部取り出してキューに入れる。1 周で取り出さなかった頂点は $v$ の隣接頂点なので、1 周のコストは $\deg(v) + (\text{取り出した数})$ で抑えられ、全体 $O(n + m)$。

## 使い方

```cpp
vector<pair<int, int>> edges;   // 元のグラフ (単純)
auto groups = complement_graph_components(n, edges);   // 補グラフの連結成分ごとの頂点
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<vector<int>> complement_graph_components(n, edges)` | 補グラフの連結成分 | $O(n + m)$ |
