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
    path: test/incremental_scc.test.cpp
    title: test/incremental_scc.test.cpp
  - icon: ':x:'
    path: test/unittest/incremental_scc_k_shortest.test.cpp
    title: test/unittest/incremental_scc_k_shortest.test.cpp
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
    graph/incremental_scc.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\n\
    // \u8FBA\u3092\u9806\u306B\u8FFD\u52A0\u3057\u3066\u3044\u304F\u6709\u5411\u30B0\
    \u30E9\u30D5\u306E\u5F37\u9023\u7D50\u6210\u5206 (Incremental SCC)\uFF0E\u30AA\
    \u30D5\u30E9\u30A4\u30F3 (\u8FBA\u3092\u5168\u90E8\u5148\u8AAD\u307F\u3059\u308B\
    )\n// incremental_scc(n, edges) \u306F\u5404\u8FBA i \u306B\u3064\u3044\u3066\u300C\
    \u8FBA 0..t-1 \u3092\u8FFD\u52A0\u3057\u305F\u6642\u70B9\u3067 i \u306E\u4E21\u7AEF\
    \u304C\u540C\u3058\u5F37\u9023\u7D50\u6210\u5206\u306B\u306A\u308B\u6700\u5C0F\
    \u306E t\u300D\u3092\u8FD4\u3059\n// (\u306A\u3089\u306A\u3051\u308C\u3070 m +\
    \ 1)\uFF0Et > i \u3067\u3042\u308B\uFF0E\u8FBA\u3092 t \u306E\u9806\u306B Union-Find\
    \ \u3067\u3064\u306A\u3052\u3070\uFF0C\u5404\u6642\u70B9\u306E\u5F37\u9023\u7D50\
    \u6210\u5206\u304C\u5206\u304B\u308B\n// \u6642\u523B\u306B\u3064\u3044\u3066\u5206\
    \u5272\u7D71\u6CBB\u3057\uFF0C\u5404\u6BB5\u3067\u5F37\u9023\u7D50\u6210\u5206\
    \u5206\u89E3\u3092\u3059\u308B\uFF0EO(m log m)\ninline vector<int> incremental_scc(int\
    \ n, const vector<pair<int, int>> &edges) {\n    int m = edges.size();\n    vector<int>\
    \ ans(m, m + 1);\n    // eu, ev: \u5404\u8FBA\u306E\u7AEF\u70B9 (\u5206\u5272\u7D71\
    \u6CBB\u306E\u4E2D\u3067\u7E2E\u7D04\u5F8C\u306E\u756A\u53F7\u306B\u66F8\u304D\
    \u63DB\u308F\u308B)\n    vector<int> eu(m), ev(m);\n    for (int i = 0; i < m;\
    \ i++) eu[i] = edges[i].first, ev[i] = edges[i].second;\n    vector<int> id(n,\
    \ -1);  // \u9802\u70B9\u756A\u53F7 \u2192 \u5C40\u6240\u756A\u53F7 (\u4F7F\u3044\
    \u7D42\u308F\u3063\u305F\u3089 -1 \u306B\u623B\u3059)\n    vector<int> vs;\n \
    \   // \u5C40\u6240\u30B0\u30E9\u30D5 (\u9802\u70B9 0..k-1\uFF0C\u8FBA el) \u306E\
    \u5F37\u9023\u7D50\u6210\u5206\uFF0Ecomp \u306B\u756A\u53F7\u3092\u5165\u308C\uFF0C\
    \u500B\u6570\u3092\u8FD4\u3059 (Tarjan, \u975E\u518D\u5E30)\n    vector<int> ord,\
    \ low, it, comp, stk, call;\n    auto local_scc = [&](int k, const vector<pair<int,\
    \ int>> &el) {\n        CSR<int> g(k, el);\n        ord.assign(k, -1), low.assign(k,\
    \ 0), it.assign(k, 0), comp.assign(k, -1);\n        int now = 0, nc = 0;\n   \
    \     for (int s = 0; s < k; s++) {\n            if (ord[s] >= 0) continue;\n\
    \            call.push_back(s), ord[s] = low[s] = now++, it[s] = g.start[s], stk.push_back(s);\n\
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
    \       comp[u] = nc;\n                        if (u == v) break;\n          \
    \          }\n                    nc++;\n                }\n            }\n  \
    \      }\n        return nc;\n    };\n    // ids: \u7B54\u3048\u304C (l, r] \u306B\
    \u3042\u308B\u8FBA (\u756A\u53F7\u306E\u6607\u9806)\n    auto rec = [&](auto self,\
    \ int l, int r, vector<int> &ids) -> void {\n        if (ids.empty()) return;\n\
    \        if (r - l == 1) {\n            for (int e : ids) ans[e] = r;\n      \
    \      return;\n        }\n        int mid = (l + r) / 2;\n        // \u756A\u53F7\
    \u304C mid \u672A\u6E80\u306E\u8FBA (= \u6642\u523B mid \u307E\u3067\u306B\u8FFD\
    \u52A0\u3055\u308C\u305F\u8FBA) \u3067\u5C40\u6240\u30B0\u30E9\u30D5\u3092\u4F5C\
    \u308A\uFF0C\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u3059\u308B\n        vs.clear();\n\
    \        for (int e : ids)\n            for (int x : {eu[e], ev[e]})\n       \
    \         if (id[x] < 0) id[x] = vs.size(), vs.push_back(x);\n        int k =\
    \ vs.size(), nc;\n        {\n            vector<pair<int, int>> el;\n        \
    \    for (int e : ids) {\n                if (e >= mid) break;\n             \
    \   el.push_back({id[eu[e]], id[ev[e]]});\n            }\n            nc = local_scc(k,\
    \ el);\n        }\n        // \u5DE6: \u6642\u523B mid \u3067\u4E21\u7AEF\u304C\
    \u540C\u3058\u6210\u5206\u306B\u306A\u3063\u305F\u8FBA (\u7AEF\u70B9\u306F\u305D\
    \u306E\u307E\u307E)\n        // \u53F3: \u305D\u308C\u4EE5\u5916\uFF0E\u7AEF\u70B9\
    \u3092\u6210\u5206\u306E\u4EE3\u8868\u306E\u9802\u70B9\u306B\u7E2E\u7D04\u3059\
    \u308B\n        vector<int> head(nc, -1), left, right;\n        for (int i = 0;\
    \ i < k; i++)\n            if (head[comp[i]] < 0) head[comp[i]] = vs[i];\n   \
    \     for (int e : ids) {\n            int cu = comp[id[eu[e]]], cv = comp[id[ev[e]]];\n\
    \            if (e < mid && cu == cv) left.push_back(e);\n            else right.push_back(e);\n\
    \        }\n        for (int e : right) {\n            int nu = head[comp[id[eu[e]]]],\
    \ nv = head[comp[id[ev[e]]]];\n            eu[e] = nu, ev[e] = nv;\n        }\n\
    \        for (int x : vs) id[x] = -1;\n        vector<int>().swap(ids), vector<int>().swap(head);\n\
    \        self(self, mid, r, right);\n        self(self, l, mid, left);\n    };\n\
    \    vector<int> all(m);\n    iota(all.begin(), all.end(), 0);\n    rec(rec, 0,\
    \ m + 1, all);\n    return ans;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"csr.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u8FBA\u3092\u9806\u306B\u8FFD\u52A0\u3057\u3066\u3044\u304F\u6709\u5411\u30B0\
    \u30E9\u30D5\u306E\u5F37\u9023\u7D50\u6210\u5206 (Incremental SCC)\uFF0E\u30AA\
    \u30D5\u30E9\u30A4\u30F3 (\u8FBA\u3092\u5168\u90E8\u5148\u8AAD\u307F\u3059\u308B\
    )\n// incremental_scc(n, edges) \u306F\u5404\u8FBA i \u306B\u3064\u3044\u3066\u300C\
    \u8FBA 0..t-1 \u3092\u8FFD\u52A0\u3057\u305F\u6642\u70B9\u3067 i \u306E\u4E21\u7AEF\
    \u304C\u540C\u3058\u5F37\u9023\u7D50\u6210\u5206\u306B\u306A\u308B\u6700\u5C0F\
    \u306E t\u300D\u3092\u8FD4\u3059\n// (\u306A\u3089\u306A\u3051\u308C\u3070 m +\
    \ 1)\uFF0Et > i \u3067\u3042\u308B\uFF0E\u8FBA\u3092 t \u306E\u9806\u306B Union-Find\
    \ \u3067\u3064\u306A\u3052\u3070\uFF0C\u5404\u6642\u70B9\u306E\u5F37\u9023\u7D50\
    \u6210\u5206\u304C\u5206\u304B\u308B\n// \u6642\u523B\u306B\u3064\u3044\u3066\u5206\
    \u5272\u7D71\u6CBB\u3057\uFF0C\u5404\u6BB5\u3067\u5F37\u9023\u7D50\u6210\u5206\
    \u5206\u89E3\u3092\u3059\u308B\uFF0EO(m log m)\ninline vector<int> incremental_scc(int\
    \ n, const vector<pair<int, int>> &edges) {\n    int m = edges.size();\n    vector<int>\
    \ ans(m, m + 1);\n    // eu, ev: \u5404\u8FBA\u306E\u7AEF\u70B9 (\u5206\u5272\u7D71\
    \u6CBB\u306E\u4E2D\u3067\u7E2E\u7D04\u5F8C\u306E\u756A\u53F7\u306B\u66F8\u304D\
    \u63DB\u308F\u308B)\n    vector<int> eu(m), ev(m);\n    for (int i = 0; i < m;\
    \ i++) eu[i] = edges[i].first, ev[i] = edges[i].second;\n    vector<int> id(n,\
    \ -1);  // \u9802\u70B9\u756A\u53F7 \u2192 \u5C40\u6240\u756A\u53F7 (\u4F7F\u3044\
    \u7D42\u308F\u3063\u305F\u3089 -1 \u306B\u623B\u3059)\n    vector<int> vs;\n \
    \   // \u5C40\u6240\u30B0\u30E9\u30D5 (\u9802\u70B9 0..k-1\uFF0C\u8FBA el) \u306E\
    \u5F37\u9023\u7D50\u6210\u5206\uFF0Ecomp \u306B\u756A\u53F7\u3092\u5165\u308C\uFF0C\
    \u500B\u6570\u3092\u8FD4\u3059 (Tarjan, \u975E\u518D\u5E30)\n    vector<int> ord,\
    \ low, it, comp, stk, call;\n    auto local_scc = [&](int k, const vector<pair<int,\
    \ int>> &el) {\n        CSR<int> g(k, el);\n        ord.assign(k, -1), low.assign(k,\
    \ 0), it.assign(k, 0), comp.assign(k, -1);\n        int now = 0, nc = 0;\n   \
    \     for (int s = 0; s < k; s++) {\n            if (ord[s] >= 0) continue;\n\
    \            call.push_back(s), ord[s] = low[s] = now++, it[s] = g.start[s], stk.push_back(s);\n\
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
    \       comp[u] = nc;\n                        if (u == v) break;\n          \
    \          }\n                    nc++;\n                }\n            }\n  \
    \      }\n        return nc;\n    };\n    // ids: \u7B54\u3048\u304C (l, r] \u306B\
    \u3042\u308B\u8FBA (\u756A\u53F7\u306E\u6607\u9806)\n    auto rec = [&](auto self,\
    \ int l, int r, vector<int> &ids) -> void {\n        if (ids.empty()) return;\n\
    \        if (r - l == 1) {\n            for (int e : ids) ans[e] = r;\n      \
    \      return;\n        }\n        int mid = (l + r) / 2;\n        // \u756A\u53F7\
    \u304C mid \u672A\u6E80\u306E\u8FBA (= \u6642\u523B mid \u307E\u3067\u306B\u8FFD\
    \u52A0\u3055\u308C\u305F\u8FBA) \u3067\u5C40\u6240\u30B0\u30E9\u30D5\u3092\u4F5C\
    \u308A\uFF0C\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u3059\u308B\n        vs.clear();\n\
    \        for (int e : ids)\n            for (int x : {eu[e], ev[e]})\n       \
    \         if (id[x] < 0) id[x] = vs.size(), vs.push_back(x);\n        int k =\
    \ vs.size(), nc;\n        {\n            vector<pair<int, int>> el;\n        \
    \    for (int e : ids) {\n                if (e >= mid) break;\n             \
    \   el.push_back({id[eu[e]], id[ev[e]]});\n            }\n            nc = local_scc(k,\
    \ el);\n        }\n        // \u5DE6: \u6642\u523B mid \u3067\u4E21\u7AEF\u304C\
    \u540C\u3058\u6210\u5206\u306B\u306A\u3063\u305F\u8FBA (\u7AEF\u70B9\u306F\u305D\
    \u306E\u307E\u307E)\n        // \u53F3: \u305D\u308C\u4EE5\u5916\uFF0E\u7AEF\u70B9\
    \u3092\u6210\u5206\u306E\u4EE3\u8868\u306E\u9802\u70B9\u306B\u7E2E\u7D04\u3059\
    \u308B\n        vector<int> head(nc, -1), left, right;\n        for (int i = 0;\
    \ i < k; i++)\n            if (head[comp[i]] < 0) head[comp[i]] = vs[i];\n   \
    \     for (int e : ids) {\n            int cu = comp[id[eu[e]]], cv = comp[id[ev[e]]];\n\
    \            if (e < mid && cu == cv) left.push_back(e);\n            else right.push_back(e);\n\
    \        }\n        for (int e : right) {\n            int nu = head[comp[id[eu[e]]]],\
    \ nv = head[comp[id[ev[e]]]];\n            eu[e] = nu, ev[e] = nv;\n        }\n\
    \        for (int x : vs) id[x] = -1;\n        vector<int>().swap(ids), vector<int>().swap(head);\n\
    \        self(self, mid, r, right);\n        self(self, l, mid, left);\n    };\n\
    \    vector<int> all(m);\n    iota(all.begin(), all.end(), 0);\n    rec(rec, 0,\
    \ m + 1, all);\n    return ans;\n}\n"
  dependsOn:
  - template.hpp
  - graph/csr.hpp
  isVerificationFile: false
  path: graph/incremental_scc.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unittest/incremental_scc_k_shortest.test.cpp
  - test/incremental_scc.test.cpp
documentation_of: graph/incremental_scc.hpp
layout: document
title: "\u8FBA\u306E\u8FFD\u52A0\u3068\u5F37\u9023\u7D50\u6210\u5206 (Incremental\
  \ SCC)"
---

## 概要

有向グラフに辺 $0, 1, \ldots, m-1$ を順に追加していくとき、各辺 $i$ について「辺 $0, \ldots, t-1$ を追加した時点で、辺 $i$ の両端が同じ強連結成分になる最小の $t$」（ならなければ $m + 1$）を求める。辺を $t$ の小さい順に Union-Find でつなげば、各時点の強連結成分が分かる。

時刻について分割統治する。答えが $(l, r]$ にある辺の集合について、時刻 $\mathrm{mid}$ までに追加された辺で強連結成分分解し、

- 両端が同じ成分になった辺は答えが $\mathrm{mid}$ 以下 → $(l, \mathrm{mid}]$ へ
- それ以外の辺は端点を成分に縮約して $(\mathrm{mid}, r]$ へ

と振り分ける。各段で辺は 1 回ずつ見るので $O(m \log m)$。

## 使い方

```cpp
vector<pair<int, int>> edges;              // 追加する順
vector<int> t = incremental_scc(n, edges); // t[i]: 辺 i の両端が強連結になる時刻 (追加した辺の本数)．ならなければ m + 1
// 例: 時刻 k の強連結成分は「t[i] <= k の辺 i の両端を Union-Find でつないだもの」
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<int> incremental_scc(int n, edges)` | 各辺が成分の内側になる時刻 | $O(n + m \log m)$ |

## 注意

- **オフライン**（全ての辺を先読みできるときのみ）。
- $t[i] > i$（辺 $i$ は自分が追加されるまで使えない）。自己ループは $t[i] = i + 1$。
