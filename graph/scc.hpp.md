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
    path: test/scc.test.cpp
    title: test/scc.test.cpp
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
    \ size() const { return (int)start.size() - 1; }\n};\n#line 4 \"graph/scc.hpp\"\
    \n\n// \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 (Tarjan, \u975E\u518D\u5E30\
    )\n// build() \u5F8C: groups \u306F\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\
    \ (\u8FBA u \u2192 v \u306A\u3089 u \u306E\u6210\u5206\u304C\u5148)\uFF0Ccomp[v]\
    \ \u306F\u305D\u306E\u756A\u53F7\uFF0EO(n + m)\nstruct StronglyConnectedComponents\
    \ {\n    int n;\n    vector<pair<int, int>> edges;\n    vector<int> comp;\n  \
    \  vector<vector<int>> groups;\n\n    StronglyConnectedComponents(int n = 0) :\
    \ n(n) {}\n    void reserve(int m) { edges.reserve(m); }\n    void add_edge(int\
    \ u, int v) { edges.push_back({u, v}); }\n\n    // \u6210\u5206\u306E\u500B\u6570\
    \u3092\u8FD4\u3059\n    int build() {\n        CSR<int> g(n, edges);\n       \
    \ vector<int> ord(n, -1), low(n), it(n), stk, call;\n        comp.assign(n, -1);\n\
    \        stk.reserve(n), call.reserve(n);\n        int now = 0, k = 0;\n     \
    \   for (int s = 0; s < n; s++) {\n            if (ord[s] >= 0) continue;\n  \
    \          call.push_back(s), ord[s] = low[s] = now++, it[s] = g.start[s], stk.push_back(s);\n\
    \            while (!call.empty()) {\n                int v = call.back();\n \
    \               if (it[v] < g.start[v + 1]) {\n                    int to = g.elist[it[v]++];\n\
    \                    if (ord[to] < 0) {\n                        ord[to] = low[to]\
    \ = now++, it[to] = g.start[to];\n                        stk.push_back(to), call.push_back(to);\n\
    \                    } else if (comp[to] < 0) {\n                        low[v]\
    \ = std::min(low[v], ord[to]);\n                    }\n                    continue;\n\
    \                }\n                call.pop_back();\n                if (!call.empty())\
    \ low[call.back()] = std::min(low[call.back()], low[v]);\n                if (low[v]\
    \ == ord[v]) {\n                    while (true) {\n                        int\
    \ u = stk.back();\n                        stk.pop_back();\n                 \
    \       comp[u] = k;\n                        if (u == v) break;\n           \
    \         }\n                    k++;\n                }\n            }\n    \
    \    }\n        // Tarjan \u306F\u9006\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\
    \u306B\u756A\u53F7\u3092\u632F\u308B\u306E\u3067\u53CD\u8EE2\u3059\u308B\n   \
    \     for (auto &c : comp) c = k - 1 - c;\n        groups.assign(k, {});\n   \
    \     vector<int> cnt(k, 0);\n        for (int v = 0; v < n; v++) cnt[comp[v]]++;\n\
    \        for (int i = 0; i < k; i++) groups[i].reserve(cnt[i]);\n        for (int\
    \ v = 0; v < n; v++) groups[comp[v]].push_back(v);\n        return k;\n    }\n\
    };\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"csr.hpp\"\n\n// \u5F37\
    \u9023\u7D50\u6210\u5206\u5206\u89E3 (Tarjan, \u975E\u518D\u5E30)\n// build()\
    \ \u5F8C: groups \u306F\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806 (\u8FBA u \u2192\
    \ v \u306A\u3089 u \u306E\u6210\u5206\u304C\u5148)\uFF0Ccomp[v] \u306F\u305D\u306E\
    \u756A\u53F7\uFF0EO(n + m)\nstruct StronglyConnectedComponents {\n    int n;\n\
    \    vector<pair<int, int>> edges;\n    vector<int> comp;\n    vector<vector<int>>\
    \ groups;\n\n    StronglyConnectedComponents(int n = 0) : n(n) {}\n    void reserve(int\
    \ m) { edges.reserve(m); }\n    void add_edge(int u, int v) { edges.push_back({u,\
    \ v}); }\n\n    // \u6210\u5206\u306E\u500B\u6570\u3092\u8FD4\u3059\n    int build()\
    \ {\n        CSR<int> g(n, edges);\n        vector<int> ord(n, -1), low(n), it(n),\
    \ stk, call;\n        comp.assign(n, -1);\n        stk.reserve(n), call.reserve(n);\n\
    \        int now = 0, k = 0;\n        for (int s = 0; s < n; s++) {\n        \
    \    if (ord[s] >= 0) continue;\n            call.push_back(s), ord[s] = low[s]\
    \ = now++, it[s] = g.start[s], stk.push_back(s);\n            while (!call.empty())\
    \ {\n                int v = call.back();\n                if (it[v] < g.start[v\
    \ + 1]) {\n                    int to = g.elist[it[v]++];\n                  \
    \  if (ord[to] < 0) {\n                        ord[to] = low[to] = now++, it[to]\
    \ = g.start[to];\n                        stk.push_back(to), call.push_back(to);\n\
    \                    } else if (comp[to] < 0) {\n                        low[v]\
    \ = std::min(low[v], ord[to]);\n                    }\n                    continue;\n\
    \                }\n                call.pop_back();\n                if (!call.empty())\
    \ low[call.back()] = std::min(low[call.back()], low[v]);\n                if (low[v]\
    \ == ord[v]) {\n                    while (true) {\n                        int\
    \ u = stk.back();\n                        stk.pop_back();\n                 \
    \       comp[u] = k;\n                        if (u == v) break;\n           \
    \         }\n                    k++;\n                }\n            }\n    \
    \    }\n        // Tarjan \u306F\u9006\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\
    \u306B\u756A\u53F7\u3092\u632F\u308B\u306E\u3067\u53CD\u8EE2\u3059\u308B\n   \
    \     for (auto &c : comp) c = k - 1 - c;\n        groups.assign(k, {});\n   \
    \     vector<int> cnt(k, 0);\n        for (int v = 0; v < n; v++) cnt[comp[v]]++;\n\
    \        for (int i = 0; i < k; i++) groups[i].reserve(cnt[i]);\n        for (int\
    \ v = 0; v < n; v++) groups[comp[v]].push_back(v);\n        return k;\n    }\n\
    };\n"
  dependsOn:
  - template.hpp
  - graph/csr.hpp
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2026-10-15 00:32:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/graph_components.test.cpp
  - test/scc.test.cpp
documentation_of: graph/scc.hpp
layout: document
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 (SCC)"
---

## 概要

有向グラフを強連結成分に分解し、成分をトポロジカル順（辺 $u \to v$ があれば $u$ の成分が先）に並べる。Tarjan のアルゴリズムを非再帰で実装し、隣接は [CSR](csr.hpp) で持つ。$O(n + m)$。

## 使い方

```cpp
StronglyConnectedComponents scc(n);
scc.reserve(m);
scc.add_edge(u, v);
int k = scc.build();      // 成分の個数
scc.groups;               // vector<vector<int>>: トポロジカル順の成分
scc.comp[v];              // 頂点 v の成分番号 (groups の添字)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `void add_edge(int u, int v)` | 辺 $u \to v$ を追加 | $O(1)$ |
| `int build()` | 分解して成分数を返す | $O(n + m)$ |
