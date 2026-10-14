---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/biconnected_components.hpp
    title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3 (Biconnected\
      \ Components)"
  - icon: ':heavy_check_mark:'
    path: graph/complement_graph_components.hpp
    title: "\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/cycle_detection.hpp
    title: "\u9589\u8DEF\u691C\u51FA (Cycle Detection)"
  - icon: ':heavy_check_mark:'
    path: graph/eulerian_trail.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u8DEF (Eulerian Trail)"
  - icon: ':heavy_check_mark:'
    path: graph/incremental_scc.hpp
    title: "\u8FBA\u306E\u8FFD\u52A0\u3068\u5F37\u9023\u7D50\u6210\u5206 (Incremental\
      \ SCC)"
  - icon: ':heavy_check_mark:'
    path: graph/k_shortest_walk.hpp
    title: "K \u6700\u77ED\u8DEF (K-Shortest Walk, Eppstein)"
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 (SCC)"
  - icon: ':heavy_check_mark:'
    path: graph/three_edge_connected_components.hpp
    title: "\u4E09\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 (Three-Edge-Connected\
      \ Components)"
  - icon: ':heavy_check_mark:'
    path: graph/two_edge_connected_components.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 (Two-Edge-Connected\
      \ Components)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/biconnected_components.test.cpp
    title: test/biconnected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/connected_components_of_complement_graph.test.cpp
    title: test/connected_components_of_complement_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cycle_detection.test.cpp
    title: test/cycle_detection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cycle_detection_undirected.test.cpp
    title: test/cycle_detection_undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/eulerian_trail_directed.test.cpp
    title: test/eulerian_trail_directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/incremental_scc.test.cpp
    title: test/incremental_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/k_shortest_walk.test.cpp
    title: test/k_shortest_walk.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/scc.test.cpp
    title: test/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/three_edge_connected_components.test.cpp
    title: test/three_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/two_edge_connected_components.test.cpp
    title: test/two_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/graph_components.test.cpp
    title: test/unittest/graph_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/incremental_scc_k_shortest.test.cpp
    title: test/unittest/incremental_scc_k_shortest.test.cpp
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
    \ size() const { return (int)start.size() - 1; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// \u96A3\u63A5\u30EA\u30B9\
    \u30C8\u3092 1 \u672C\u306E\u914D\u5217\u3067\u6301\u3064 (Compressed Sparse Row)\n\
    // \u9802\u70B9 v \u306E\u96A3\u63A5\u306F elist[start[v] .. start[v+1])\uFF0E\
    vector<vector<int>> \u3088\u308A\u901F\u304F\u30E1\u30E2\u30EA\u3082\u5C11\u306A\
    \u3044\ntemplate <class E>\nstruct CSR {\n    vector<int> start;\n    vector<E>\
    \ elist;\n    CSR() = default;\n    // edges[i] = (from, \u4E2D\u8EAB)\n    CSR(int\
    \ n, const vector<pair<int, E>> &edges) : start(n + 1, 0), elist(edges.size())\
    \ {\n        for (auto &e : edges) start[e.first + 1]++;\n        for (int i =\
    \ 1; i <= n; i++) start[i] += start[i - 1];\n        vector<int> pos(start.begin(),\
    \ start.end() - 1);\n        for (auto &e : edges) elist[pos[e.first]++] = e.second;\n\
    \    }\n    int size() const { return (int)start.size() - 1; }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/csr.hpp
  requiredBy:
  - graph/cycle_detection.hpp
  - graph/k_shortest_walk.hpp
  - graph/eulerian_trail.hpp
  - graph/scc.hpp
  - graph/incremental_scc.hpp
  - graph/two_edge_connected_components.hpp
  - graph/three_edge_connected_components.hpp
  - graph/biconnected_components.hpp
  - graph/complement_graph_components.hpp
  timestamp: '2026-10-15 00:32:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cycle_detection_undirected.test.cpp
  - test/three_edge_connected_components.test.cpp
  - test/biconnected_components.test.cpp
  - test/two_edge_connected_components.test.cpp
  - test/unittest/incremental_scc_k_shortest.test.cpp
  - test/unittest/graph_components.test.cpp
  - test/incremental_scc.test.cpp
  - test/connected_components_of_complement_graph.test.cpp
  - test/cycle_detection.test.cpp
  - test/scc.test.cpp
  - test/k_shortest_walk.test.cpp
  - test/eulerian_trail_directed.test.cpp
documentation_of: graph/csr.hpp
layout: document
title: "CSR (\u96A3\u63A5\u30EA\u30B9\u30C8\u3092 1 \u672C\u306E\u914D\u5217\u3067\
  \u6301\u3064)"
---

## 概要

グラフの隣接リストを、`vector<vector<int>>` ではなく 1 本の配列で持つ（Compressed Sparse Row）。頂点 $v$ の隣接は `elist[start[v] .. start[v+1])`。メモリの確保が 2 回で済み、隣接を読むときも連続アクセスになるので速い。グラフのライブラリの内部で使っている。

## 使い方

```cpp
vector<pair<int, int>> el;          // (from, 中身) の列．中身は行き先や辺番号など
CSR<int> g(n, el);
for (int i = g.start[v]; i < g.start[v + 1]; i++) { int x = g.elist[i]; ... }
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `CSR<E>(int n, const vector<pair<int, E>> &edges)` | 構築（同じ頂点の中では入力順） | $O(n + m)$ |
