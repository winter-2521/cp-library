---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/csr.hpp
    title: "CSR (\u96A3\u63A5\u30EA\u30B9\u30C8\u3092 1 \u672C\u306E\u914D\u5217\u3067\
      \u6301\u3064)"
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/biconnected_components.test.cpp
    title: test/biconnected_components.test.cpp
  - icon: ':x:'
    path: test/unittest/graph_components.test.cpp
    title: test/unittest/graph_components.test.cpp
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
    \ 3 \"graph/csr.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\n// \u96A3\
    \u63A5\u30EA\u30B9\u30C8\u3092 1 \u672C\u306E\u914D\u5217\u3067\u6301\u3064 (Compressed\
    \ Sparse Row)\n// \u9802\u70B9 v \u306E\u96A3\u63A5\u306F elist[start[v] .. start[v+1])\uFF0E\
    vector<vector<int>> \u3088\u308A\u901F\u304F\u30E1\u30E2\u30EA\u3082\u5C11\u306A\
    \u3044\ntemplate <class E>\nstruct CSR {\n    vector<int> start;\n    vector<E>\
    \ elist;\n    CSR() = default;\n    // edges[i] = (from, \u4E2D\u8EAB)\n    CSR(int\
    \ n, const vector<pair<int, E>> &edges) : start(n + 1, 0), elist(edges.size())\
    \ {\n        for (auto &e : edges) start[e.first + 1]++;\n        for (int i =\
    \ 1; i <= n; i++) start[i] += start[i - 1];\n        vector<int> pos(start.begin(),\
    \ start.end() - 1);\n        for (auto &e : edges) elist[pos[e.first]++] = e.second;\n\
    \    }\n    int size() const { return (int)start.size() - 1; }\n};\n#line 4 \"\
    graph/biconnected_components.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3 (\u95A2\u7BC0\
    \u70B9\u3067\u5207\u3063\u305F\u6210\u5206)\uFF0Elowlink + \u8FBA\u306E\u30B9\u30BF\
    \u30C3\u30AF\uFF0C\u975E\u518D\u5E30 DFS \u3067 O(n + m)\n// \u8FD4\u308A\u5024\
    : \u6210\u5206\u3054\u3068\u306E\u9802\u70B9\u306E\u5217 (\u95A2\u7BC0\u70B9\u306F\
    \u8907\u6570\u306E\u6210\u5206\u306B\u5165\u308B\uFF0E\u5B64\u7ACB\u70B9\u306F\
    \ 1 \u9802\u70B9\u306E\u6210\u5206)\n// edge_groups \u3092\u6E21\u3059\u3068\u6210\
    \u5206\u3054\u3068\u306E\u8FBA\u756A\u53F7\u306E\u5217\u3082\u5165\u308B\ninline\
    \ vector<vector<int>> biconnected_components(int n, const vector<pair<int, int>>\
    \ &edges, vector<vector<int>> *edge_groups = nullptr) {\n    int m = edges.size();\n\
    \    vector<pair<int, int>> el;\n    el.reserve(2 * m);\n    for (int i = 0; i\
    \ < m; i++) {\n        if (edges[i].first == edges[i].second) continue;\n    \
    \    el.push_back({edges[i].first, i}), el.push_back({edges[i].second, i});\n\
    \    }\n    CSR<int> g(n, el);\n    vector<int> ord(n, -1), low(n), it(n), par_edge(n,\
    \ -1), call, estk;\n    vector<vector<int>> res;\n    if (edge_groups) edge_groups->clear();\n\
    \    vector<int> mark(n, -1);  // \u6210\u5206\u306B\u5165\u308C\u305F\u9802\u70B9\
    \u306E\u5370 (\u6210\u5206\u756A\u53F7)\n    int now = 0;\n    for (int s = 0;\
    \ s < n; s++) {\n        if (ord[s] >= 0) continue;\n        ord[s] = low[s] =\
    \ now++, it[s] = g.start[s], call.push_back(s);\n        if (g.start[s] == g.start[s\
    \ + 1]) {  // \u5B64\u7ACB\u70B9 (\u81EA\u5DF1\u30EB\u30FC\u30D7\u3060\u3051\u306E\
    \u9802\u70B9\u3082)\n            res.push_back({s});\n            if (edge_groups)\
    \ edge_groups->emplace_back();\n        }\n        while (!call.empty()) {\n \
    \           int v = call.back();\n            if (it[v] < g.start[v + 1]) {\n\
    \                int e = g.elist[it[v]++];\n                if (e == par_edge[v])\
    \ continue;\n                int to = edges[e].first ^ edges[e].second ^ v;\n\
    \                if (ord[to] < 0) {\n                    estk.push_back(e);\n\
    \                    ord[to] = low[to] = now++, it[to] = g.start[to], par_edge[to]\
    \ = e;\n                    call.push_back(to);\n                } else if (ord[to]\
    \ < ord[v]) {\n                    estk.push_back(e);  // \u5F8C\u9000\u8FBA (\u5B50\
    \u5B6B\u304B\u3089\u898B\u305F 1 \u56DE\u3060\u3051\u7A4D\u3080)\n           \
    \         low[v] = std::min(low[v], ord[to]);\n                }\n           \
    \     continue;\n            }\n            call.pop_back();\n            if (call.empty())\
    \ break;\n            int p = call.back();\n            low[p] = std::min(low[p],\
    \ low[v]);\n            if (low[v] >= ord[p]) {\n                // p \u306F\u95A2\
    \u7BC0\u70B9 (\u307E\u305F\u306F\u6839)\uFF0E\u8FBA (p, v) \u307E\u3067\u3092\u30B9\
    \u30BF\u30C3\u30AF\u304B\u3089\u53D6\u308A\u51FA\u3057\u305F\u3082\u306E\u304C\
    \ 1 \u3064\u306E\u6210\u5206\n                int k = res.size();\n          \
    \      res.emplace_back();\n                if (edge_groups) edge_groups->emplace_back();\n\
    \                while (true) {\n                    int e = estk.back();\n  \
    \                  estk.pop_back();\n                    if (edge_groups) (*edge_groups)[k].push_back(e);\n\
    \                    for (int x : {edges[e].first, edges[e].second})\n       \
    \                 if (mark[x] != k) mark[x] = k, res[k].push_back(x);\n      \
    \              if (e == par_edge[v]) break;\n                }\n            }\n\
    \        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"csr.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3 (\u95A2\u7BC0\
    \u70B9\u3067\u5207\u3063\u305F\u6210\u5206)\uFF0Elowlink + \u8FBA\u306E\u30B9\u30BF\
    \u30C3\u30AF\uFF0C\u975E\u518D\u5E30 DFS \u3067 O(n + m)\n// \u8FD4\u308A\u5024\
    : \u6210\u5206\u3054\u3068\u306E\u9802\u70B9\u306E\u5217 (\u95A2\u7BC0\u70B9\u306F\
    \u8907\u6570\u306E\u6210\u5206\u306B\u5165\u308B\uFF0E\u5B64\u7ACB\u70B9\u306F\
    \ 1 \u9802\u70B9\u306E\u6210\u5206)\n// edge_groups \u3092\u6E21\u3059\u3068\u6210\
    \u5206\u3054\u3068\u306E\u8FBA\u756A\u53F7\u306E\u5217\u3082\u5165\u308B\ninline\
    \ vector<vector<int>> biconnected_components(int n, const vector<pair<int, int>>\
    \ &edges, vector<vector<int>> *edge_groups = nullptr) {\n    int m = edges.size();\n\
    \    vector<pair<int, int>> el;\n    el.reserve(2 * m);\n    for (int i = 0; i\
    \ < m; i++) {\n        if (edges[i].first == edges[i].second) continue;\n    \
    \    el.push_back({edges[i].first, i}), el.push_back({edges[i].second, i});\n\
    \    }\n    CSR<int> g(n, el);\n    vector<int> ord(n, -1), low(n), it(n), par_edge(n,\
    \ -1), call, estk;\n    vector<vector<int>> res;\n    if (edge_groups) edge_groups->clear();\n\
    \    vector<int> mark(n, -1);  // \u6210\u5206\u306B\u5165\u308C\u305F\u9802\u70B9\
    \u306E\u5370 (\u6210\u5206\u756A\u53F7)\n    int now = 0;\n    for (int s = 0;\
    \ s < n; s++) {\n        if (ord[s] >= 0) continue;\n        ord[s] = low[s] =\
    \ now++, it[s] = g.start[s], call.push_back(s);\n        if (g.start[s] == g.start[s\
    \ + 1]) {  // \u5B64\u7ACB\u70B9 (\u81EA\u5DF1\u30EB\u30FC\u30D7\u3060\u3051\u306E\
    \u9802\u70B9\u3082)\n            res.push_back({s});\n            if (edge_groups)\
    \ edge_groups->emplace_back();\n        }\n        while (!call.empty()) {\n \
    \           int v = call.back();\n            if (it[v] < g.start[v + 1]) {\n\
    \                int e = g.elist[it[v]++];\n                if (e == par_edge[v])\
    \ continue;\n                int to = edges[e].first ^ edges[e].second ^ v;\n\
    \                if (ord[to] < 0) {\n                    estk.push_back(e);\n\
    \                    ord[to] = low[to] = now++, it[to] = g.start[to], par_edge[to]\
    \ = e;\n                    call.push_back(to);\n                } else if (ord[to]\
    \ < ord[v]) {\n                    estk.push_back(e);  // \u5F8C\u9000\u8FBA (\u5B50\
    \u5B6B\u304B\u3089\u898B\u305F 1 \u56DE\u3060\u3051\u7A4D\u3080)\n           \
    \         low[v] = std::min(low[v], ord[to]);\n                }\n           \
    \     continue;\n            }\n            call.pop_back();\n            if (call.empty())\
    \ break;\n            int p = call.back();\n            low[p] = std::min(low[p],\
    \ low[v]);\n            if (low[v] >= ord[p]) {\n                // p \u306F\u95A2\
    \u7BC0\u70B9 (\u307E\u305F\u306F\u6839)\uFF0E\u8FBA (p, v) \u307E\u3067\u3092\u30B9\
    \u30BF\u30C3\u30AF\u304B\u3089\u53D6\u308A\u51FA\u3057\u305F\u3082\u306E\u304C\
    \ 1 \u3064\u306E\u6210\u5206\n                int k = res.size();\n          \
    \      res.emplace_back();\n                if (edge_groups) edge_groups->emplace_back();\n\
    \                while (true) {\n                    int e = estk.back();\n  \
    \                  estk.pop_back();\n                    if (edge_groups) (*edge_groups)[k].push_back(e);\n\
    \                    for (int x : {edges[e].first, edges[e].second})\n       \
    \                 if (mark[x] != k) mark[x] = k, res[k].push_back(x);\n      \
    \              if (e == par_edge[v]) break;\n                }\n            }\n\
    \        }\n    }\n    return res;\n}\n"
  dependsOn:
  - template.hpp
  - graph/csr.hpp
  isVerificationFile: false
  path: graph/biconnected_components.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/biconnected_components.test.cpp
  - test/unittest/graph_components.test.cpp
documentation_of: graph/biconnected_components.hpp
layout: document
title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3 (Biconnected\
  \ Components)"
---

## 概要

無向グラフを二重頂点連結成分（関節点で切った「ブロック」）に分解する。DFS で辺をスタックに積み、子 $v$ の探索が終わって $\mathrm{low}[v] \ge \mathrm{ord}[\text{親}]$ なら、親は関節点（または根）なので、辺 (親, $v$) までをスタックから取り出したものが 1 つの成分。非再帰で $O(n + m)$。

関節点は複数の成分に入る。辺のない頂点は 1 頂点だけの成分になる。

## 使い方

```cpp
vector<pair<int, int>> edges;
vector<vector<int>> edge_groups;
auto groups = biconnected_components(n, edges, &edge_groups);   // 成分ごとの頂点 (edge_groups は省略可)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<vector<int>> biconnected_components(n, edges, edge_groups = nullptr)` | 成分ごとの頂点（と辺） | $O(n + m)$ |

## 注意

- 自己ループは無視する。
