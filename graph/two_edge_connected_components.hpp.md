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
  - icon: ':x:'
    path: test/two_edge_connected_components.test.cpp
    title: test/two_edge_connected_components.test.cpp
  - icon: ':x:'
    path: test/unittest/graph_components.test.cpp
    title: test/unittest/graph_components.test.cpp
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
    graph/two_edge_connected_components.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 (\u6A4B\u3067\u5207\
    \u3063\u305F\u9023\u7D50\u6210\u5206)\uFF0Elowlink\uFF0C\u975E\u518D\u5E30 DFS\
    \ \u3067 O(n + m)\n// \u8FD4\u308A\u5024: \u6210\u5206\u3054\u3068\u306E\u9802\
    \u70B9\u306E\u5217\uFF0Ecomp \u3092\u6E21\u3059\u3068\u5404\u9802\u70B9\u306E\u6210\
    \u5206\u756A\u53F7\u3082\u5165\u308B\n// is_bridge \u3092\u6E21\u3059\u3068\u5404\
    \u8FBA\u304C\u6A4B\u304B\u3069\u3046\u304B\u3082\u5165\u308B\ninline vector<vector<int>>\
    \ two_edge_connected_components(int n, const vector<pair<int, int>> &edges, vector<int>\
    \ *comp_out = nullptr,\n                                                     \
    \    vector<char> *is_bridge = nullptr) {\n    int m = edges.size();\n    vector<pair<int,\
    \ int>> el;\n    el.reserve(2 * m);\n    for (int i = 0; i < m; i++) {\n     \
    \   if (edges[i].first == edges[i].second) continue;\n        el.push_back({edges[i].first,\
    \ i}), el.push_back({edges[i].second, i});\n    }\n    CSR<int> g(n, el);\n  \
    \  vector<int> ord(n, -1), low(n), it(n), par_edge(n, -1), call, stk, comp(n,\
    \ -1);\n    vector<vector<int>> groups;\n    if (is_bridge) is_bridge->assign(m,\
    \ 0);\n    int now = 0;\n    for (int s = 0; s < n; s++) {\n        if (ord[s]\
    \ >= 0) continue;\n        ord[s] = low[s] = now++, it[s] = g.start[s], call.push_back(s),\
    \ stk.push_back(s);\n        while (!call.empty()) {\n            int v = call.back();\n\
    \            if (it[v] < g.start[v + 1]) {\n                int e = g.elist[it[v]++];\n\
    \                if (e == par_edge[v]) continue;  // \u6765\u305F\u8FBA (\u591A\
    \u91CD\u8FBA\u306F\u5225\u306E\u8FBA\u3068\u3057\u3066\u6271\u3046)\n        \
    \        int to = edges[e].first ^ edges[e].second ^ v;\n                if (ord[to]\
    \ < 0) {\n                    ord[to] = low[to] = now++, it[to] = g.start[to],\
    \ par_edge[to] = e;\n                    call.push_back(to), stk.push_back(to);\n\
    \                } else {\n                    low[v] = std::min(low[v], ord[to]);\n\
    \                }\n                continue;\n            }\n            call.pop_back();\n\
    \            if (!call.empty()) low[call.back()] = std::min(low[call.back()],\
    \ low[v]);\n            if (low[v] == ord[v]) {\n                // v \u304B\u3089\
    \u4E0B\u306E (\u307E\u3060\u53D6\u308A\u51FA\u3057\u3066\u3044\u306A\u3044) \u9802\
    \u70B9\u304C 1 \u3064\u306E\u6210\u5206\uFF0Ev \u306E\u89AA\u3078\u306E\u8FBA\u306F\
    \u6A4B\n                if (is_bridge && par_edge[v] >= 0) (*is_bridge)[par_edge[v]]\
    \ = 1;\n                int k = groups.size();\n                groups.emplace_back();\n\
    \                while (true) {\n                    int u = stk.back();\n   \
    \                 stk.pop_back();\n                    comp[u] = k, groups[k].push_back(u);\n\
    \                    if (u == v) break;\n                }\n            }\n  \
    \      }\n    }\n    if (comp_out) *comp_out = comp;\n    return groups;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"csr.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 (\u6A4B\u3067\u5207\
    \u3063\u305F\u9023\u7D50\u6210\u5206)\uFF0Elowlink\uFF0C\u975E\u518D\u5E30 DFS\
    \ \u3067 O(n + m)\n// \u8FD4\u308A\u5024: \u6210\u5206\u3054\u3068\u306E\u9802\
    \u70B9\u306E\u5217\uFF0Ecomp \u3092\u6E21\u3059\u3068\u5404\u9802\u70B9\u306E\u6210\
    \u5206\u756A\u53F7\u3082\u5165\u308B\n// is_bridge \u3092\u6E21\u3059\u3068\u5404\
    \u8FBA\u304C\u6A4B\u304B\u3069\u3046\u304B\u3082\u5165\u308B\ninline vector<vector<int>>\
    \ two_edge_connected_components(int n, const vector<pair<int, int>> &edges, vector<int>\
    \ *comp_out = nullptr,\n                                                     \
    \    vector<char> *is_bridge = nullptr) {\n    int m = edges.size();\n    vector<pair<int,\
    \ int>> el;\n    el.reserve(2 * m);\n    for (int i = 0; i < m; i++) {\n     \
    \   if (edges[i].first == edges[i].second) continue;\n        el.push_back({edges[i].first,\
    \ i}), el.push_back({edges[i].second, i});\n    }\n    CSR<int> g(n, el);\n  \
    \  vector<int> ord(n, -1), low(n), it(n), par_edge(n, -1), call, stk, comp(n,\
    \ -1);\n    vector<vector<int>> groups;\n    if (is_bridge) is_bridge->assign(m,\
    \ 0);\n    int now = 0;\n    for (int s = 0; s < n; s++) {\n        if (ord[s]\
    \ >= 0) continue;\n        ord[s] = low[s] = now++, it[s] = g.start[s], call.push_back(s),\
    \ stk.push_back(s);\n        while (!call.empty()) {\n            int v = call.back();\n\
    \            if (it[v] < g.start[v + 1]) {\n                int e = g.elist[it[v]++];\n\
    \                if (e == par_edge[v]) continue;  // \u6765\u305F\u8FBA (\u591A\
    \u91CD\u8FBA\u306F\u5225\u306E\u8FBA\u3068\u3057\u3066\u6271\u3046)\n        \
    \        int to = edges[e].first ^ edges[e].second ^ v;\n                if (ord[to]\
    \ < 0) {\n                    ord[to] = low[to] = now++, it[to] = g.start[to],\
    \ par_edge[to] = e;\n                    call.push_back(to), stk.push_back(to);\n\
    \                } else {\n                    low[v] = std::min(low[v], ord[to]);\n\
    \                }\n                continue;\n            }\n            call.pop_back();\n\
    \            if (!call.empty()) low[call.back()] = std::min(low[call.back()],\
    \ low[v]);\n            if (low[v] == ord[v]) {\n                // v \u304B\u3089\
    \u4E0B\u306E (\u307E\u3060\u53D6\u308A\u51FA\u3057\u3066\u3044\u306A\u3044) \u9802\
    \u70B9\u304C 1 \u3064\u306E\u6210\u5206\uFF0Ev \u306E\u89AA\u3078\u306E\u8FBA\u306F\
    \u6A4B\n                if (is_bridge && par_edge[v] >= 0) (*is_bridge)[par_edge[v]]\
    \ = 1;\n                int k = groups.size();\n                groups.emplace_back();\n\
    \                while (true) {\n                    int u = stk.back();\n   \
    \                 stk.pop_back();\n                    comp[u] = k, groups[k].push_back(u);\n\
    \                    if (u == v) break;\n                }\n            }\n  \
    \      }\n    }\n    if (comp_out) *comp_out = comp;\n    return groups;\n}\n"
  dependsOn:
  - template.hpp
  - graph/csr.hpp
  isVerificationFile: false
  path: graph/two_edge_connected_components.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/two_edge_connected_components.test.cpp
  - test/unittest/graph_components.test.cpp
documentation_of: graph/two_edge_connected_components.hpp
layout: document
title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 (Two-Edge-Connected\
  \ Components)"
---

## 概要

無向グラフを、**橋**（取り除くと連結成分が増える辺）で切った連結成分に分解する。lowlink（DFS 木で、子孫から後退辺 1 本で行ける最も浅い頂点の訪問順）を非再帰 DFS で求め、$\mathrm{low}[v] = \mathrm{ord}[v]$ となる頂点 $v$ の部分木（の、まだ取り出していない頂点）を 1 つの成分として取り出す。多重辺は辺番号で区別するので、2 本の平行な辺は橋にならない。$O(n + m)$。

## 使い方

```cpp
vector<pair<int, int>> edges;
vector<int> comp;
vector<char> is_bridge;
auto groups = two_edge_connected_components(n, edges, &comp, &is_bridge);   // comp, is_bridge は省略可
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<vector<int>> two_edge_connected_components(n, edges, comp = nullptr, is_bridge = nullptr)` | 成分ごとの頂点 | $O(n + m)$ |
