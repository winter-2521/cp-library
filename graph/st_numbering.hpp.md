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
    path: test/st_numbering.test.cpp
    title: test/st_numbering.test.cpp
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
    graph/st_numbering.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\n//\
    \ st \u756A\u53F7\u4ED8\u3051\uFF0Es \u304C\u6700\u5C0F\uFF0Ct \u304C\u6700\u5927\
    \u3067\uFF0C\u4ED6\u306E\u5168\u3066\u306E\u9802\u70B9\u304C\u300C\u756A\u53F7\
    \u304C\u5C0F\u3055\u3044\u96A3\u63A5\u9802\u70B9\u300D\u3068\u300C\u5927\u304D\
    \u3044\u96A3\u63A5\u9802\u70B9\u300D\u3092\u4E21\u65B9\u6301\u3064\u3088\u3046\
    \u306A\u756A\u53F7\u4ED8\u3051\uFF0E\n// \u5B58\u5728\u3059\u308B \u21D4 G \u306B\
    \u8FBA (s, t) \u3092\u8DB3\u3057\u305F\u30B0\u30E9\u30D5\u304C\u4E8C\u91CD\u9802\
    \u70B9\u9023\u7D50 (n >= 3 \u306E\u3068\u304D)\n// s \u3092\u6839\uFF0Ct \u3092\
    \u6700\u521D\u306E\u5B50\u3068\u3059\u308B DFS \u3067 lowlink \u3092\u6C42\u3081\
    \uFF0C\u5148\u884C\u9806\u306B\u5404\u9802\u70B9\u3092\u300C\u89AA\u306E\u76F4\
    \u524D\u304B\u76F4\u5F8C\u300D\u306B\u9023\u7D50\u30EA\u30B9\u30C8\u3078\u633F\
    \u5165\u3059\u308B (Tarjan)\uFF0EO(n + m)\n// \u8FD4\u308A\u5024: \u5404\u9802\
    \u70B9\u306E\u756A\u53F7 (0 .. n-1)\uFF0E\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\
    \u7A7A\ninline vector<int> st_numbering(int n, const vector<pair<int, int>> &edges,\
    \ int s, int t) {\n    if (n == 1) return {0};\n    if (n == 2) {\n        //\
    \ \u8FBA (s, t) \u3092\u8DB3\u3057\u3066\u8003\u3048\u308B\u306E\u306F n >= 3\
    \ \u306E\u3068\u304D\u3060\u3051\u6B63\u3057\u3044\uFF0En = 2 \u3067\u306F\u5B9F\
    \u969B\u306B\u8FBA s - t \u304C\u5FC5\u8981\n        for (auto [a, b] : edges)\n\
    \            if ((a == s && b == t) || (a == t && b == s)) {\n               \
    \ vector<int> num(2);\n                num[s] = 0, num[t] = 1;\n             \
    \   return num;\n            }\n        return {};\n    }\n    vector<pair<int,\
    \ int>> el;\n    el.reserve(2 * edges.size() + 2);\n    el.push_back({s, t}),\
    \ el.push_back({t, s});  // \u8FBA (s, t) \u3092\u8DB3\u3059 (s \u304B\u3089\u6700\
    \u521D\u306B t \u3078\u964D\u308A\u308B)\n    for (auto [a, b] : edges) el.push_back({a,\
    \ b}), el.push_back({b, a});\n    CSR<int> g(n, el);\n    vector<int> pre(n, -1),\
    \ low(n), par(n, -1), order, it(n), call;\n    order.reserve(n);\n    int cnt\
    \ = 0;\n    pre[s] = low[s] = cnt++, order.push_back(s), it[s] = g.start[s], call.push_back(s);\n\
    \    vector<char> skipped(n, 0);  // \u89AA\u3078\u306E\u8FBA\u3092 1 \u672C\u3060\
    \u3051\u98DB\u3070\u3057\u305F\u304B\n    while (!call.empty()) {\n        int\
    \ v = call.back();\n        if (it[v] < g.start[v + 1]) {\n            int w =\
    \ g.elist[it[v]++];\n            if (w == par[v] && !skipped[v]) {\n         \
    \       skipped[v] = 1;\n                continue;\n            }\n          \
    \  if (pre[w] < 0) {\n                par[w] = v, pre[w] = low[w] = cnt++, order.push_back(w),\
    \ it[w] = g.start[w];\n                call.push_back(w);\n            } else\
    \ {\n                low[v] = std::min(low[v], pre[w]);\n            }\n     \
    \       continue;\n        }\n        call.pop_back();\n        if (!call.empty())\
    \ low[call.back()] = std::min(low[call.back()], low[v]);\n    }\n    if (cnt !=\
    \ n) return {};  // \u975E\u9023\u7D50\n    // \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\
    \u304B: \u6839 s \u306E\u5B50\u306F t \u3060\u3051\uFF0C\u4ED6\u306E\u6728\u306E\
    \u8FBA (p, c) \u306F low[c] < pre[p]\n    for (int v = 0; v < n; v++) {\n    \
    \    if (v == s) continue;\n        int p = par[v];\n        if (p == s) {\n \
    \           if (v != t) return {};\n        } else if (low[v] >= pre[p]) {\n \
    \           return {};\n        }\n    }\n    // low \u3092\u9802\u70B9\u3067\u6301\
    \u3061\u76F4\u3059 (pre \u306E\u5024 \u2192 \u9802\u70B9)\n    // sign[v] = -1\
    \ \u306A\u3089 v \u306F\u300C\u89AA\u3088\u308A\u524D\u300D\u5074\u306B\u3044\u308B\
    \u5370\n    vector<int> who(n);\n    for (int v = 0; v < n; v++) who[pre[v]] =\
    \ v;\n    vector<int> nx(n, -1), pv(n, -1);\n    vector<char> minus(n, 0);\n \
    \   // \u30EA\u30B9\u30C8: s \u2192 t\n    nx[s] = t, pv[t] = s, minus[s] = 1;\n\
    \    for (int v : order) {\n        if (v == s || v == t) continue;\n        int\
    \ p = par[v], lw = who[low[v]];\n        if (minus[lw]) {\n            // p \u306E\
    \u76F4\u524D\u306B\u633F\u5165\n            int q = pv[p];\n            nx[q]\
    \ = v, pv[v] = q, nx[v] = p, pv[p] = v;\n            minus[p] = 0;\n        }\
    \ else {\n            // p \u306E\u76F4\u5F8C\u306B\u633F\u5165\n            int\
    \ q = nx[p];\n            nx[p] = v, pv[v] = p, nx[v] = q;\n            if (q\
    \ >= 0) pv[q] = v;\n            minus[p] = 1;\n        }\n    }\n    vector<int>\
    \ num(n);\n    int k = 0;\n    for (int v = s; v >= 0; v = nx[v]) num[v] = k++;\n\
    \    return num;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"csr.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// st \u756A\u53F7\u4ED8\u3051\uFF0Es \u304C\u6700\u5C0F\uFF0Ct \u304C\u6700\
    \u5927\u3067\uFF0C\u4ED6\u306E\u5168\u3066\u306E\u9802\u70B9\u304C\u300C\u756A\
    \u53F7\u304C\u5C0F\u3055\u3044\u96A3\u63A5\u9802\u70B9\u300D\u3068\u300C\u5927\
    \u304D\u3044\u96A3\u63A5\u9802\u70B9\u300D\u3092\u4E21\u65B9\u6301\u3064\u3088\
    \u3046\u306A\u756A\u53F7\u4ED8\u3051\uFF0E\n// \u5B58\u5728\u3059\u308B \u21D4\
    \ G \u306B\u8FBA (s, t) \u3092\u8DB3\u3057\u305F\u30B0\u30E9\u30D5\u304C\u4E8C\
    \u91CD\u9802\u70B9\u9023\u7D50 (n >= 3 \u306E\u3068\u304D)\n// s \u3092\u6839\uFF0C\
    t \u3092\u6700\u521D\u306E\u5B50\u3068\u3059\u308B DFS \u3067 lowlink \u3092\u6C42\
    \u3081\uFF0C\u5148\u884C\u9806\u306B\u5404\u9802\u70B9\u3092\u300C\u89AA\u306E\
    \u76F4\u524D\u304B\u76F4\u5F8C\u300D\u306B\u9023\u7D50\u30EA\u30B9\u30C8\u3078\
    \u633F\u5165\u3059\u308B (Tarjan)\uFF0EO(n + m)\n// \u8FD4\u308A\u5024: \u5404\
    \u9802\u70B9\u306E\u756A\u53F7 (0 .. n-1)\uFF0E\u5B58\u5728\u3057\u306A\u3051\u308C\
    \u3070\u7A7A\ninline vector<int> st_numbering(int n, const vector<pair<int, int>>\
    \ &edges, int s, int t) {\n    if (n == 1) return {0};\n    if (n == 2) {\n  \
    \      // \u8FBA (s, t) \u3092\u8DB3\u3057\u3066\u8003\u3048\u308B\u306E\u306F\
    \ n >= 3 \u306E\u3068\u304D\u3060\u3051\u6B63\u3057\u3044\uFF0En = 2 \u3067\u306F\
    \u5B9F\u969B\u306B\u8FBA s - t \u304C\u5FC5\u8981\n        for (auto [a, b] :\
    \ edges)\n            if ((a == s && b == t) || (a == t && b == s)) {\n      \
    \          vector<int> num(2);\n                num[s] = 0, num[t] = 1;\n    \
    \            return num;\n            }\n        return {};\n    }\n    vector<pair<int,\
    \ int>> el;\n    el.reserve(2 * edges.size() + 2);\n    el.push_back({s, t}),\
    \ el.push_back({t, s});  // \u8FBA (s, t) \u3092\u8DB3\u3059 (s \u304B\u3089\u6700\
    \u521D\u306B t \u3078\u964D\u308A\u308B)\n    for (auto [a, b] : edges) el.push_back({a,\
    \ b}), el.push_back({b, a});\n    CSR<int> g(n, el);\n    vector<int> pre(n, -1),\
    \ low(n), par(n, -1), order, it(n), call;\n    order.reserve(n);\n    int cnt\
    \ = 0;\n    pre[s] = low[s] = cnt++, order.push_back(s), it[s] = g.start[s], call.push_back(s);\n\
    \    vector<char> skipped(n, 0);  // \u89AA\u3078\u306E\u8FBA\u3092 1 \u672C\u3060\
    \u3051\u98DB\u3070\u3057\u305F\u304B\n    while (!call.empty()) {\n        int\
    \ v = call.back();\n        if (it[v] < g.start[v + 1]) {\n            int w =\
    \ g.elist[it[v]++];\n            if (w == par[v] && !skipped[v]) {\n         \
    \       skipped[v] = 1;\n                continue;\n            }\n          \
    \  if (pre[w] < 0) {\n                par[w] = v, pre[w] = low[w] = cnt++, order.push_back(w),\
    \ it[w] = g.start[w];\n                call.push_back(w);\n            } else\
    \ {\n                low[v] = std::min(low[v], pre[w]);\n            }\n     \
    \       continue;\n        }\n        call.pop_back();\n        if (!call.empty())\
    \ low[call.back()] = std::min(low[call.back()], low[v]);\n    }\n    if (cnt !=\
    \ n) return {};  // \u975E\u9023\u7D50\n    // \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\
    \u304B: \u6839 s \u306E\u5B50\u306F t \u3060\u3051\uFF0C\u4ED6\u306E\u6728\u306E\
    \u8FBA (p, c) \u306F low[c] < pre[p]\n    for (int v = 0; v < n; v++) {\n    \
    \    if (v == s) continue;\n        int p = par[v];\n        if (p == s) {\n \
    \           if (v != t) return {};\n        } else if (low[v] >= pre[p]) {\n \
    \           return {};\n        }\n    }\n    // low \u3092\u9802\u70B9\u3067\u6301\
    \u3061\u76F4\u3059 (pre \u306E\u5024 \u2192 \u9802\u70B9)\n    // sign[v] = -1\
    \ \u306A\u3089 v \u306F\u300C\u89AA\u3088\u308A\u524D\u300D\u5074\u306B\u3044\u308B\
    \u5370\n    vector<int> who(n);\n    for (int v = 0; v < n; v++) who[pre[v]] =\
    \ v;\n    vector<int> nx(n, -1), pv(n, -1);\n    vector<char> minus(n, 0);\n \
    \   // \u30EA\u30B9\u30C8: s \u2192 t\n    nx[s] = t, pv[t] = s, minus[s] = 1;\n\
    \    for (int v : order) {\n        if (v == s || v == t) continue;\n        int\
    \ p = par[v], lw = who[low[v]];\n        if (minus[lw]) {\n            // p \u306E\
    \u76F4\u524D\u306B\u633F\u5165\n            int q = pv[p];\n            nx[q]\
    \ = v, pv[v] = q, nx[v] = p, pv[p] = v;\n            minus[p] = 0;\n        }\
    \ else {\n            // p \u306E\u76F4\u5F8C\u306B\u633F\u5165\n            int\
    \ q = nx[p];\n            nx[p] = v, pv[v] = p, nx[v] = q;\n            if (q\
    \ >= 0) pv[q] = v;\n            minus[p] = 1;\n        }\n    }\n    vector<int>\
    \ num(n);\n    int k = 0;\n    for (int v = s; v >= 0; v = nx[v]) num[v] = k++;\n\
    \    return num;\n}\n"
  dependsOn:
  - template.hpp
  - graph/csr.hpp
  isVerificationFile: false
  path: graph/st_numbering.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/st_numbering.test.cpp
  - test/unittest/graph_optimization.test.cpp
documentation_of: graph/st_numbering.hpp
layout: document
title: "st \u756A\u53F7\u4ED8\u3051 (st-Numbering)"
---

## 概要

無向グラフの頂点 $s, t$ について、$s$ が最小・$t$ が最大で、それ以外の全ての頂点が「自分より番号が小さい隣接頂点」と「大きい隣接頂点」を両方持つような番号付け（st 番号付け）を求める。$O(n + m)$。

- 存在条件（$n \ge 3$）：辺 $(s, t)$ を足したグラフが二重頂点連結であること。

$s$ を根、$t$ を最初の子とする DFS で lowlink を求め、先行順に各頂点 $v$ を連結リスト中の「親の直前」か「親の直後」に挿入する（$\mathrm{low}[v]$ の頂点が親より前にあるか後ろにあるかで決める。Tarjan の方法）。最後にリストの順に番号を振る。DFS は非再帰。

## 使い方

```cpp
vector<pair<int, int>> edges;
vector<int> num = st_numbering(n, edges, s, t);   // num[v] ∈ [0, n)
if (num.empty()) { /* 存在しない */ }
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<int> st_numbering(int n, edges, int s, int t)` | 各頂点の番号．なければ空 | $O(n + m)$ |

## 注意

- $n \ge 2$ では $s \ne t$ を仮定する（$n = 1$ なら `{0}`）。$n = 2$ では辺 $s$-$t$ があるときだけ存在する。
- 多重辺・自己ループがあってもよい。
