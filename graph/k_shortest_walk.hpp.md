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
    path: test/k_shortest_walk.test.cpp
    title: test/k_shortest_walk.test.cpp
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
    \ size() const { return (int)start.size() - 1; }\n};\n#line 4 \"graph/k_shortest_walk.hpp\"\
    \n\n// s \u304B\u3089 t \u3078\u306E\u77ED\u3044\u65B9\u304B\u3089 K \u500B\u306E\
    \u30A6\u30A9\u30FC\u30AF (\u540C\u3058\u9802\u70B9\u30FB\u8FBA\u3092\u4F55\u5EA6\
    \u901A\u3063\u3066\u3082\u3088\u3044\u8DEF) \u306E\u9577\u3055 (Eppstein \u6CD5\
    )\n// \u8FBA\u306E\u91CD\u307F\u306F\u975E\u8CA0\uFF0E\u8FD4\u308A\u5024\u306F\
    \u9577\u3055\u306E\u6607\u9806\u3067\uFF0CK \u500B\u306B\u6E80\u305F\u306A\u3051\
    \u308C\u3070\u305D\u306E\u5206\u3060\u3051\n// 1. t \u3078\u306E\u6700\u77ED\u8DDD\
    \u96E2 dist \u3068\uFF0C\u5404\u9802\u70B9\u304B\u3089 t \u3078\u306E\u6700\u77ED\
    \u8DEF\u6728\u3092\u4F5C\u308B\n// 2. \u6700\u77ED\u8DEF\u6728\u306B\u4F7F\u308F\
    \u306A\u3044\u8FBA e = (u \u2192 w) \u3092\u300C\u5BC4\u308A\u9053\u300D\u3068\
    \u547C\u3073\uFF0C\u305D\u306E\u8FFD\u52A0\u30B3\u30B9\u30C8 \u03B4(e) = c + dist[w]\
    \ - dist[u] >= 0\n// 3. H[v] = v \u304B\u3089\u6700\u77ED\u8DEF\u6728\u3067 t\
    \ \u306B\u5411\u304B\u3046\u9014\u4E2D\u306E\u9802\u70B9\u304B\u3089\u51FA\u308B\
    \u5BC4\u308A\u9053\u5168\u90E8\u3092 \u03B4 \u3067\u307E\u3068\u3081\u305F\u6C38\
    \u7D9A\u30D2\u30FC\u30D7 (H[v] = H[\u89AA] + v \u306E\u5BC4\u308A\u9053)\n// 4.\
    \ \u30A6\u30A9\u30FC\u30AF\u306F\u300C\u5BC4\u308A\u9053\u306E\u5217\u300D\u3068\
    \ 1 \u5BFE 1 \u306B\u5BFE\u5FDC\u3057\uFF0C\u305D\u308C\u3092\u512A\u5148\u5EA6\
    \u4ED8\u304D\u30AD\u30E5\u30FC\u3067\u5C0F\u3055\u3044\u9806\u306B\u53D6\u308A\
    \u51FA\u3059\n// O((n + m) log m + K log K)\ntemplate <class T>\nvector<T> k_shortest_walks(int\
    \ n, const vector<tuple<int, int, T>> &edges, int s, int t, int K) {\n    int\
    \ m = edges.size();\n    const T INF = numeric_limits<T>::max();\n    // \u9006\
    \u5411\u304D\u306E Dijkstra (t \u304B\u3089)\n    vector<pair<int, int>> rel(m);\n\
    \    for (int i = 0; i < m; i++) rel[i] = {get<1>(edges[i]), i};\n    CSR<int>\
    \ rg(n, rel);\n    vector<T> dist(n, INF);\n    vector<int> tree_edge(n, -1),\
    \ order;  // tree_edge[v]: v \u304B\u3089 t \u3078\u306E\u6700\u77ED\u8DEF\u6728\
    \u3067\u4F7F\u3046\u8FBA\n    order.reserve(n);\n    {\n        priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<>> pq;\n        dist[t] = 0, pq.push({0,\
    \ t});\n        while (!pq.empty()) {\n            auto [d, v] = pq.top();\n \
    \           pq.pop();\n            if (d != dist[v]) continue;\n            order.push_back(v);\n\
    \            for (int i = rg.start[v]; i < rg.start[v + 1]; i++) {\n         \
    \       int e = rg.elist[i], u = get<0>(edges[e]);\n                T nd = d +\
    \ get<2>(edges[e]);\n                if (nd < dist[u]) dist[u] = nd, tree_edge[u]\
    \ = e, pq.push({nd, u});\n            }\n        }\n    }\n    vector<T> res;\n\
    \    if (dist[s] == INF) return res;\n    // \u6C38\u7D9A leftist heap (\u30AD\
    \u30FC\u306F \u03B4\uFF0C\u5024\u306F\u5BC4\u308A\u9053\u306E\u884C\u304D\u5148\
    \u306E\u9802\u70B9)\n    struct Node {\n        T key;\n        int to, l, r,\
    \ rk;\n    };\n    vector<Node> hp{{T(0), -1, 0, 0, 0}};  // 0 \u756A\u306F\u7A7A\
    \n    auto merge = [&](auto self, int a, int b) -> int {\n        if (!a || !b)\
    \ return a ^ b;\n        if (hp[b].key < hp[a].key) swap(a, b);\n        Node\
    \ nd = hp[a];\n        int r = self(self, nd.r, b);\n        nd.r = r;\n     \
    \   if (hp[nd.l].rk < hp[nd.r].rk) swap(nd.l, nd.r);\n        nd.rk = hp[nd.r].rk\
    \ + 1;\n        hp.push_back(nd);\n        return hp.size() - 1;\n    };\n   \
    \ vector<pair<int, int>> fel(m);\n    for (int i = 0; i < m; i++) fel[i] = {get<0>(edges[i]),\
    \ i};\n    CSR<int> fg(n, fel);\n    vector<int> H(n, 0);\n    // t \u306B\u8FD1\
    \u3044\u9806 (dist \u306E\u6607\u9806) \u306B H \u3092\u4F5C\u308B\n    for (int\
    \ v : order) {\n        int h = v == t ? 0 : H[get<1>(edges[tree_edge[v]])];\n\
    \        for (int i = fg.start[v]; i < fg.start[v + 1]; i++) {\n            int\
    \ e = fg.elist[i], w = get<1>(edges[e]);\n            if (e == tree_edge[v] ||\
    \ dist[w] == INF) continue;\n            T delta = get<2>(edges[e]) + dist[w]\
    \ - dist[v];\n            hp.push_back({delta, w, 0, 0, 1});\n            h =\
    \ merge(merge, h, (int)hp.size() - 1);\n        }\n        H[v] = h;\n    }\n\
    \    res.push_back(dist[s]);\n    priority_queue<pair<T, int>, vector<pair<T,\
    \ int>>, greater<>> pq;  // (\u9577\u3055, \u30D2\u30FC\u30D7\u306E\u30CE\u30FC\
    \u30C9)\n    if (H[s]) pq.push({dist[s] + hp[H[s]].key, H[s]});\n    while ((int)res.size()\
    \ < K && !pq.empty()) {\n        auto [d, x] = pq.top();\n        pq.pop();\n\
    \        res.push_back(d);\n        // \u540C\u3058\u30D2\u30FC\u30D7\u306E\u4E2D\
    \u3067\u6B21\u306E\u5BC4\u308A\u9053\u306B\u66FF\u3048\u308B\n        for (int\
    \ c : {hp[x].l, hp[x].r})\n            if (c) pq.push({d - hp[x].key + hp[c].key,\
    \ c});\n        // \u3053\u306E\u5BC4\u308A\u9053\u306E\u5F8C\u306B\uFF0C\u884C\
    \u304D\u5148\u304B\u3089\u66F4\u306B\u5BC4\u308A\u9053\u3092\u8DB3\u3059\n   \
    \     int nh = H[hp[x].to];\n        if (nh) pq.push({d + hp[nh].key, nh});\n\
    \    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"csr.hpp\"\n\n// s\
    \ \u304B\u3089 t \u3078\u306E\u77ED\u3044\u65B9\u304B\u3089 K \u500B\u306E\u30A6\
    \u30A9\u30FC\u30AF (\u540C\u3058\u9802\u70B9\u30FB\u8FBA\u3092\u4F55\u5EA6\u901A\
    \u3063\u3066\u3082\u3088\u3044\u8DEF) \u306E\u9577\u3055 (Eppstein \u6CD5)\n//\
    \ \u8FBA\u306E\u91CD\u307F\u306F\u975E\u8CA0\uFF0E\u8FD4\u308A\u5024\u306F\u9577\
    \u3055\u306E\u6607\u9806\u3067\uFF0CK \u500B\u306B\u6E80\u305F\u306A\u3051\u308C\
    \u3070\u305D\u306E\u5206\u3060\u3051\n// 1. t \u3078\u306E\u6700\u77ED\u8DDD\u96E2\
    \ dist \u3068\uFF0C\u5404\u9802\u70B9\u304B\u3089 t \u3078\u306E\u6700\u77ED\u8DEF\
    \u6728\u3092\u4F5C\u308B\n// 2. \u6700\u77ED\u8DEF\u6728\u306B\u4F7F\u308F\u306A\
    \u3044\u8FBA e = (u \u2192 w) \u3092\u300C\u5BC4\u308A\u9053\u300D\u3068\u547C\
    \u3073\uFF0C\u305D\u306E\u8FFD\u52A0\u30B3\u30B9\u30C8 \u03B4(e) = c + dist[w]\
    \ - dist[u] >= 0\n// 3. H[v] = v \u304B\u3089\u6700\u77ED\u8DEF\u6728\u3067 t\
    \ \u306B\u5411\u304B\u3046\u9014\u4E2D\u306E\u9802\u70B9\u304B\u3089\u51FA\u308B\
    \u5BC4\u308A\u9053\u5168\u90E8\u3092 \u03B4 \u3067\u307E\u3068\u3081\u305F\u6C38\
    \u7D9A\u30D2\u30FC\u30D7 (H[v] = H[\u89AA] + v \u306E\u5BC4\u308A\u9053)\n// 4.\
    \ \u30A6\u30A9\u30FC\u30AF\u306F\u300C\u5BC4\u308A\u9053\u306E\u5217\u300D\u3068\
    \ 1 \u5BFE 1 \u306B\u5BFE\u5FDC\u3057\uFF0C\u305D\u308C\u3092\u512A\u5148\u5EA6\
    \u4ED8\u304D\u30AD\u30E5\u30FC\u3067\u5C0F\u3055\u3044\u9806\u306B\u53D6\u308A\
    \u51FA\u3059\n// O((n + m) log m + K log K)\ntemplate <class T>\nvector<T> k_shortest_walks(int\
    \ n, const vector<tuple<int, int, T>> &edges, int s, int t, int K) {\n    int\
    \ m = edges.size();\n    const T INF = numeric_limits<T>::max();\n    // \u9006\
    \u5411\u304D\u306E Dijkstra (t \u304B\u3089)\n    vector<pair<int, int>> rel(m);\n\
    \    for (int i = 0; i < m; i++) rel[i] = {get<1>(edges[i]), i};\n    CSR<int>\
    \ rg(n, rel);\n    vector<T> dist(n, INF);\n    vector<int> tree_edge(n, -1),\
    \ order;  // tree_edge[v]: v \u304B\u3089 t \u3078\u306E\u6700\u77ED\u8DEF\u6728\
    \u3067\u4F7F\u3046\u8FBA\n    order.reserve(n);\n    {\n        priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<>> pq;\n        dist[t] = 0, pq.push({0,\
    \ t});\n        while (!pq.empty()) {\n            auto [d, v] = pq.top();\n \
    \           pq.pop();\n            if (d != dist[v]) continue;\n            order.push_back(v);\n\
    \            for (int i = rg.start[v]; i < rg.start[v + 1]; i++) {\n         \
    \       int e = rg.elist[i], u = get<0>(edges[e]);\n                T nd = d +\
    \ get<2>(edges[e]);\n                if (nd < dist[u]) dist[u] = nd, tree_edge[u]\
    \ = e, pq.push({nd, u});\n            }\n        }\n    }\n    vector<T> res;\n\
    \    if (dist[s] == INF) return res;\n    // \u6C38\u7D9A leftist heap (\u30AD\
    \u30FC\u306F \u03B4\uFF0C\u5024\u306F\u5BC4\u308A\u9053\u306E\u884C\u304D\u5148\
    \u306E\u9802\u70B9)\n    struct Node {\n        T key;\n        int to, l, r,\
    \ rk;\n    };\n    vector<Node> hp{{T(0), -1, 0, 0, 0}};  // 0 \u756A\u306F\u7A7A\
    \n    auto merge = [&](auto self, int a, int b) -> int {\n        if (!a || !b)\
    \ return a ^ b;\n        if (hp[b].key < hp[a].key) swap(a, b);\n        Node\
    \ nd = hp[a];\n        int r = self(self, nd.r, b);\n        nd.r = r;\n     \
    \   if (hp[nd.l].rk < hp[nd.r].rk) swap(nd.l, nd.r);\n        nd.rk = hp[nd.r].rk\
    \ + 1;\n        hp.push_back(nd);\n        return hp.size() - 1;\n    };\n   \
    \ vector<pair<int, int>> fel(m);\n    for (int i = 0; i < m; i++) fel[i] = {get<0>(edges[i]),\
    \ i};\n    CSR<int> fg(n, fel);\n    vector<int> H(n, 0);\n    // t \u306B\u8FD1\
    \u3044\u9806 (dist \u306E\u6607\u9806) \u306B H \u3092\u4F5C\u308B\n    for (int\
    \ v : order) {\n        int h = v == t ? 0 : H[get<1>(edges[tree_edge[v]])];\n\
    \        for (int i = fg.start[v]; i < fg.start[v + 1]; i++) {\n            int\
    \ e = fg.elist[i], w = get<1>(edges[e]);\n            if (e == tree_edge[v] ||\
    \ dist[w] == INF) continue;\n            T delta = get<2>(edges[e]) + dist[w]\
    \ - dist[v];\n            hp.push_back({delta, w, 0, 0, 1});\n            h =\
    \ merge(merge, h, (int)hp.size() - 1);\n        }\n        H[v] = h;\n    }\n\
    \    res.push_back(dist[s]);\n    priority_queue<pair<T, int>, vector<pair<T,\
    \ int>>, greater<>> pq;  // (\u9577\u3055, \u30D2\u30FC\u30D7\u306E\u30CE\u30FC\
    \u30C9)\n    if (H[s]) pq.push({dist[s] + hp[H[s]].key, H[s]});\n    while ((int)res.size()\
    \ < K && !pq.empty()) {\n        auto [d, x] = pq.top();\n        pq.pop();\n\
    \        res.push_back(d);\n        // \u540C\u3058\u30D2\u30FC\u30D7\u306E\u4E2D\
    \u3067\u6B21\u306E\u5BC4\u308A\u9053\u306B\u66FF\u3048\u308B\n        for (int\
    \ c : {hp[x].l, hp[x].r})\n            if (c) pq.push({d - hp[x].key + hp[c].key,\
    \ c});\n        // \u3053\u306E\u5BC4\u308A\u9053\u306E\u5F8C\u306B\uFF0C\u884C\
    \u304D\u5148\u304B\u3089\u66F4\u306B\u5BC4\u308A\u9053\u3092\u8DB3\u3059\n   \
    \     int nh = H[hp[x].to];\n        if (nh) pq.push({d + hp[nh].key, nh});\n\
    \    }\n    return res;\n}\n"
  dependsOn:
  - template.hpp
  - graph/csr.hpp
  isVerificationFile: false
  path: graph/k_shortest_walk.hpp
  requiredBy: []
  timestamp: '2026-10-15 00:32:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/incremental_scc_k_shortest.test.cpp
  - test/k_shortest_walk.test.cpp
documentation_of: graph/k_shortest_walk.hpp
layout: document
title: "K \u6700\u77ED\u8DEF (K-Shortest Walk, Eppstein)"
---

## 概要

辺の重みが非負の有向グラフで、$s$ から $t$ への **ウォーク**（同じ頂点・辺を何度通ってもよい路）を短い順に $K$ 個求める（Eppstein のアルゴリズム）。

1. $t$ への最短距離 $\mathrm{dist}$ と、$t$ への最短路木を Dijkstra で求める。
2. 最短路木に使わない辺 $e = (u \to w, c)$ を「寄り道」とし、その追加コスト $\delta(e) = c + \mathrm{dist}[w] - \mathrm{dist}[u] \ge 0$ とする。どのウォークも「寄り道の列」で一意に表せ、長さは $\mathrm{dist}[s] + \sum \delta$。
3. 各頂点 $v$ について、$v$ から最短路木で $t$ に向かう途中の頂点から出る寄り道全部を、$\delta$ をキーとする **永続 leftist heap** $H[v]$ にまとめる（$H[v] = H[\text{木の親}] + v \text{ の寄り道}$ で、親と共有する）。
4. 「今の最後の寄り道を、ヒープの中の子に替える」「今の寄り道の行き先 $w$ から $H[w]$ の最小の寄り道を足す」の 2 通りで次の候補を作り、優先度付きキューで小さい順に取り出す。

## 使い方

```cpp
vector<tuple<int, int, long long>> edges;           // (from, to, 重み)．重みは非負
vector<long long> len = k_shortest_walks(n, edges, s, t, K);   // 昇順．K 個に満たなければその分だけ
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<T> k_shortest_walks(int n, edges, int s, int t, int K)` | 短い順に $K$ 個のウォークの長さ | $O((n + m) \log m + K \log K)$ |

## 注意

- 長さが同じでも、通る辺の列が違えば別のウォークとして数える。
- 永続ヒープのノードは寄り道 1 本あたり $O(\log m)$ 個できる。
