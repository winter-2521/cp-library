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
    path: test/three_edge_connected_components.test.cpp
    title: test/three_edge_connected_components.test.cpp
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
    \ size() const { return (int)start.size() - 1; }\n};\n#line 4 \"graph/three_edge_connected_components.hpp\"\
    \n\n// \u4E09\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 (Tsin \u306E\u30D1\
    \u30B9\u5438\u53CE\u6CD5\uFF0C\u975E\u518D\u5E30)\uFF0EO(n + m)\n// \u5404\u9802\
    \u70B9 v \u306B\u3064\u3044\u3066 DFS \u6728\u306E\u4E0B\u306B\u4F38\u3073\u308B\
    \u300Cv \u306E\u30D1\u30B9\u300D(path[v] \u3067\u3064\u306A\u304C\u308B\u9802\u70B9\
    \u306E\u5217) \u3068\uFF0C\n// v \u306E\u6210\u5206\u304B\u3089\u7956\u5148\u3078\
    \u51FA\u3066\u3044\u304F\u8FBA\u306E\u672C\u6570 deg[v] \u3092\u6301\u3064\uFF0E\
    \u5B50\u306E\u6210\u5206\u306E deg \u304C 1 \u4EE5\u4E0B (\u6A4B / 2 \u8FBA\u30AB\
    \u30C3\u30C8) \u306A\u3089\u5207\u308A\u96E2\u3057\uFF0C\n// \u305D\u3046\u3067\
    \u306A\u3051\u308C\u3070\u30D1\u30B9\u3092 v \u306B\u5438\u53CE (\u540C\u3058\u6210\
    \u5206\u3068\u3057\u3066\u4F75\u5408) \u3059\u308B\ninline vector<vector<int>>\
    \ three_edge_connected_components(int n, const vector<pair<int, int>> &edges)\
    \ {\n    int m = edges.size();\n    vector<pair<int, int>> el;\n    el.reserve(2\
    \ * m);\n    for (int i = 0; i < m; i++) {\n        auto [a, b] = edges[i];\n\
    \        if (a == b) continue;\n        el.push_back({a, b}), el.push_back({b,\
    \ a});\n    }\n    CSR<int> g(n, el);\n    const int NONE = n;\n    vector<int>\
    \ in(n, -1), out(n), low(n, NONE), deg(n, 0), path(n, NONE), nxt(n);\n    iota(nxt.begin(),\
    \ nxt.end(), 0);  // \u6210\u5206\u3092\u5DE1\u56DE\u30EA\u30B9\u30C8\u3067\u6301\
    \u3064 (\u4F75\u5408\u306F nxt \u306E\u4EA4\u63DB)\n    auto absorb = [&](int\
    \ v, int w) { swap(nxt[v], nxt[w]), deg[v] += deg[w]; };\n    vector<int> it(n),\
    \ par(n, NONE), call;\n    vector<char> par_used(n, 0);  // \u89AA\u3078\u306E\
    \u8FBA\u3092 1 \u672C\u3060\u3051\u98DB\u3070\u3057\u305F\u304B (\u591A\u91CD\u8FBA\
    \u5BFE\u7B56)\n    int cnt = 0;\n    for (int s = 0; s < n; s++) {\n        if\
    \ (in[s] >= 0) continue;\n        in[s] = cnt++, it[s] = g.start[s], call.push_back(s);\n\
    \        while (!call.empty()) {\n            int v = call.back();\n         \
    \   if (it[v] < g.start[v + 1]) {\n                int w = g.elist[it[v]++];\n\
    \                if (w == par[v] && !par_used[v]) {\n                    par_used[v]\
    \ = 1;\n                    continue;\n                }\n                if (in[w]\
    \ >= 0) {\n                    if (in[w] < in[v]) {  // \u7956\u5148\u3078\u306E\
    \u5F8C\u9000\u8FBA\n                        deg[v]++;\n                      \
    \  low[v] = std::min(low[v], in[w]);\n                    } else {  // \u5B50\u5B6B\
    \u304B\u3089\u306E\u5F8C\u9000\u8FBA: \u305D\u306E\u5B50\u5B6B\u3092\u542B\u3080\
    \u30D1\u30B9\u4E0A\u306E\u9802\u70B9\u3092\u5438\u53CE\n                     \
    \   deg[v]--;\n                        int u = path[v];\n                    \
    \    while (u != NONE && in[u] <= in[w] && in[w] < out[u]) {\n               \
    \             absorb(v, u);\n                            u = path[u];\n      \
    \                  }\n                        path[v] = u;\n                 \
    \   }\n                    continue;\n                }\n                par[w]\
    \ = v, in[w] = cnt++, it[w] = g.start[w];\n                call.push_back(w);\n\
    \                continue;\n            }\n            // v \u306E\u63A2\u7D22\
    \u7D42\u4E86\n            out[v] = cnt;\n            call.pop_back();\n      \
    \      if (call.empty()) break;\n            int p = call.back(), w = v;\n   \
    \         if (path[w] == NONE && deg[w] <= 1) {\n                // w \u306E\u6210\
    \u5206\u306F (p, w) \u3068\u9AD8\u3005 1 \u672C\u306E\u8FBA\u3067\u3057\u304B\u3064\
    \u306A\u304C\u3089\u306A\u3044 \u2192 \u72EC\u7ACB\u3057\u305F\u6210\u5206\n \
    \               deg[p] += deg[w];\n                low[p] = std::min(low[p], low[w]);\n\
    \                continue;\n            } else if (deg[w] == 0) {\n          \
    \      w = path[w];  // w \u81EA\u8EAB\u306F\u5207\u308A\u96E2\u3057\uFF0C\u305D\
    \u306E\u4E0B\u306E\u30D1\u30B9\u3060\u3051\u6B8B\u3059\n            }\n      \
    \      if (low[w] < low[p]) {\n                low[p] = low[w];\n            \
    \    swap(w, path[p]);  // \u3088\u308A\u4E0A\u306B\u5C4A\u304F\u30D1\u30B9\u3092\
    \ p \u306E\u30D1\u30B9\u306B\u3057\uFF0C\u5143\u306E\u30D1\u30B9\u306F\u5438\u53CE\
    \u3059\u308B\n            }\n            while (w != NONE) {\n               \
    \ absorb(p, w);\n                w = path[w];\n            }\n        }\n    }\n\
    \    vector<vector<int>> res;\n    vector<char> vis(n, 0);\n    for (int i = 0;\
    \ i < n; i++) {\n        if (vis[i]) continue;\n        res.emplace_back();\n\
    \        int y = i;\n        do {\n            vis[y] = 1, res.back().push_back(y);\n\
    \            y = nxt[y];\n        } while (y != i);\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"csr.hpp\"\n\n// \u4E09\
    \u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 (Tsin \u306E\u30D1\u30B9\u5438\
    \u53CE\u6CD5\uFF0C\u975E\u518D\u5E30)\uFF0EO(n + m)\n// \u5404\u9802\u70B9 v \u306B\
    \u3064\u3044\u3066 DFS \u6728\u306E\u4E0B\u306B\u4F38\u3073\u308B\u300Cv \u306E\
    \u30D1\u30B9\u300D(path[v] \u3067\u3064\u306A\u304C\u308B\u9802\u70B9\u306E\u5217\
    ) \u3068\uFF0C\n// v \u306E\u6210\u5206\u304B\u3089\u7956\u5148\u3078\u51FA\u3066\
    \u3044\u304F\u8FBA\u306E\u672C\u6570 deg[v] \u3092\u6301\u3064\uFF0E\u5B50\u306E\
    \u6210\u5206\u306E deg \u304C 1 \u4EE5\u4E0B (\u6A4B / 2 \u8FBA\u30AB\u30C3\u30C8\
    ) \u306A\u3089\u5207\u308A\u96E2\u3057\uFF0C\n// \u305D\u3046\u3067\u306A\u3051\
    \u308C\u3070\u30D1\u30B9\u3092 v \u306B\u5438\u53CE (\u540C\u3058\u6210\u5206\u3068\
    \u3057\u3066\u4F75\u5408) \u3059\u308B\ninline vector<vector<int>> three_edge_connected_components(int\
    \ n, const vector<pair<int, int>> &edges) {\n    int m = edges.size();\n    vector<pair<int,\
    \ int>> el;\n    el.reserve(2 * m);\n    for (int i = 0; i < m; i++) {\n     \
    \   auto [a, b] = edges[i];\n        if (a == b) continue;\n        el.push_back({a,\
    \ b}), el.push_back({b, a});\n    }\n    CSR<int> g(n, el);\n    const int NONE\
    \ = n;\n    vector<int> in(n, -1), out(n), low(n, NONE), deg(n, 0), path(n, NONE),\
    \ nxt(n);\n    iota(nxt.begin(), nxt.end(), 0);  // \u6210\u5206\u3092\u5DE1\u56DE\
    \u30EA\u30B9\u30C8\u3067\u6301\u3064 (\u4F75\u5408\u306F nxt \u306E\u4EA4\u63DB\
    )\n    auto absorb = [&](int v, int w) { swap(nxt[v], nxt[w]), deg[v] += deg[w];\
    \ };\n    vector<int> it(n), par(n, NONE), call;\n    vector<char> par_used(n,\
    \ 0);  // \u89AA\u3078\u306E\u8FBA\u3092 1 \u672C\u3060\u3051\u98DB\u3070\u3057\
    \u305F\u304B (\u591A\u91CD\u8FBA\u5BFE\u7B56)\n    int cnt = 0;\n    for (int\
    \ s = 0; s < n; s++) {\n        if (in[s] >= 0) continue;\n        in[s] = cnt++,\
    \ it[s] = g.start[s], call.push_back(s);\n        while (!call.empty()) {\n  \
    \          int v = call.back();\n            if (it[v] < g.start[v + 1]) {\n \
    \               int w = g.elist[it[v]++];\n                if (w == par[v] &&\
    \ !par_used[v]) {\n                    par_used[v] = 1;\n                    continue;\n\
    \                }\n                if (in[w] >= 0) {\n                    if\
    \ (in[w] < in[v]) {  // \u7956\u5148\u3078\u306E\u5F8C\u9000\u8FBA\n         \
    \               deg[v]++;\n                        low[v] = std::min(low[v], in[w]);\n\
    \                    } else {  // \u5B50\u5B6B\u304B\u3089\u306E\u5F8C\u9000\u8FBA\
    : \u305D\u306E\u5B50\u5B6B\u3092\u542B\u3080\u30D1\u30B9\u4E0A\u306E\u9802\u70B9\
    \u3092\u5438\u53CE\n                        deg[v]--;\n                      \
    \  int u = path[v];\n                        while (u != NONE && in[u] <= in[w]\
    \ && in[w] < out[u]) {\n                            absorb(v, u);\n          \
    \                  u = path[u];\n                        }\n                 \
    \       path[v] = u;\n                    }\n                    continue;\n \
    \               }\n                par[w] = v, in[w] = cnt++, it[w] = g.start[w];\n\
    \                call.push_back(w);\n                continue;\n            }\n\
    \            // v \u306E\u63A2\u7D22\u7D42\u4E86\n            out[v] = cnt;\n\
    \            call.pop_back();\n            if (call.empty()) break;\n        \
    \    int p = call.back(), w = v;\n            if (path[w] == NONE && deg[w] <=\
    \ 1) {\n                // w \u306E\u6210\u5206\u306F (p, w) \u3068\u9AD8\u3005\
    \ 1 \u672C\u306E\u8FBA\u3067\u3057\u304B\u3064\u306A\u304C\u3089\u306A\u3044 \u2192\
    \ \u72EC\u7ACB\u3057\u305F\u6210\u5206\n                deg[p] += deg[w];\n  \
    \              low[p] = std::min(low[p], low[w]);\n                continue;\n\
    \            } else if (deg[w] == 0) {\n                w = path[w];  // w \u81EA\
    \u8EAB\u306F\u5207\u308A\u96E2\u3057\uFF0C\u305D\u306E\u4E0B\u306E\u30D1\u30B9\
    \u3060\u3051\u6B8B\u3059\n            }\n            if (low[w] < low[p]) {\n\
    \                low[p] = low[w];\n                swap(w, path[p]);  // \u3088\
    \u308A\u4E0A\u306B\u5C4A\u304F\u30D1\u30B9\u3092 p \u306E\u30D1\u30B9\u306B\u3057\
    \uFF0C\u5143\u306E\u30D1\u30B9\u306F\u5438\u53CE\u3059\u308B\n            }\n\
    \            while (w != NONE) {\n                absorb(p, w);\n            \
    \    w = path[w];\n            }\n        }\n    }\n    vector<vector<int>> res;\n\
    \    vector<char> vis(n, 0);\n    for (int i = 0; i < n; i++) {\n        if (vis[i])\
    \ continue;\n        res.emplace_back();\n        int y = i;\n        do {\n \
    \           vis[y] = 1, res.back().push_back(y);\n            y = nxt[y];\n  \
    \      } while (y != i);\n    }\n    return res;\n}\n"
  dependsOn:
  - template.hpp
  - graph/csr.hpp
  isVerificationFile: false
  path: graph/three_edge_connected_components.hpp
  requiredBy: []
  timestamp: '2026-10-15 00:32:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/three_edge_connected_components.test.cpp
  - test/unittest/graph_components.test.cpp
documentation_of: graph/three_edge_connected_components.hpp
layout: document
title: "\u4E09\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 (Three-Edge-Connected\
  \ Components)"
---

## 概要

無向グラフを三重辺連結成分（どの 2 本の辺を取り除いても互いに連結なままの頂点の極大集合）に分解する。Tsin のパス吸収法を非再帰で実装。$O(n + m)$。

DFS をしながら、各頂点 $v$ について

- $\mathrm{deg}[v]$：$v$ の（今の）成分から祖先へ出ていく辺の本数（DFS 木の親への辺を除く）
- $v$ のパス：$v$ から DFS 木を下に伸びる、まだ成分が確定していない頂点の列（`path` でつなぐ）

を持つ。子 $w$ の探索が終わったとき、$w$ のパスが $w$ だけで $\mathrm{deg}[w] \le 1$ なら、$w$ の成分は「親への辺 + 高々 1 本」でしか外とつながらない（橋か 2 辺カット）ので独立した成分として確定する。そうでなければ、low の小さい方のパスを残し、もう一方を $v$ に吸収（同じ成分として併合）する。子孫からの後退辺を見たときは、その子孫を含むパス上の頂点を吸収する。

## 使い方

```cpp
vector<pair<int, int>> edges;
auto groups = three_edge_connected_components(n, edges);   // 成分ごとの頂点
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<vector<int>> three_edge_connected_components(n, edges)` | 成分ごとの頂点 | $O(n + m)$ |

## 参考

- Y. H. Tsin, "A Simple 3-Edge-Connected Component Algorithm", Theory of Computing Systems, 2007.
