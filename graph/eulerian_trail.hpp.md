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
    path: test/eulerian_trail_directed.test.cpp
    title: test/eulerian_trail_directed.test.cpp
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
    \ size() const { return (int)start.size() - 1; }\n};\n#line 4 \"graph/eulerian_trail.hpp\"\
    \n\n// \u30AA\u30A4\u30E9\u30FC\u8DEF (\u5168\u3066\u306E\u8FBA\u3092\u3061\u3087\
    \u3046\u3069 1 \u56DE\u305A\u3064\u901A\u308B\u8DEF)\uFF0EHierholzer \u6CD5\uFF0C\
    \u975E\u518D\u5E30\u3067 O(n + m)\n// \u8FD4\u308A\u5024: {\u9802\u70B9\u306E\u5217\
    \ (m+1 \u500B), \u8FBA\u756A\u53F7\u306E\u5217 (m \u500B)}\uFF0E\u5B58\u5728\u3057\
    \u306A\u3051\u308C\u3070\u7A7A\u306E pair\n// \u8FBA\u304C\u306A\u3044\u3068\u304D\
    \u306F {{0}, {}} (\u9802\u70B9 0 \u304B\u3089\u9577\u3055 0 \u306E\u8DEF)\n//\
    \ DIRECTED = true \u306A\u3089\u6709\u5411\u30B0\u30E9\u30D5\uFF0Cfalse \u306A\
    \u3089\u7121\u5411\u30B0\u30E9\u30D5\n\ntemplate <bool DIRECTED>\npair<vector<int>,\
    \ vector<int>> eulerian_trail(int n, const vector<pair<int, int>> &edges) {\n\
    \    int m = edges.size();\n    if (m == 0) return {{0}, {}};\n    vector<int>\
    \ deg(n, 0);  // \u6709\u5411: \u51FA\u6B21\u6570 - \u5165\u6B21\u6570\uFF0C\u7121\
    \u5411: \u6B21\u6570\n    vector<pair<int, int>> el;\n    el.reserve(DIRECTED\
    \ ? m : 2 * m);\n    for (int i = 0; i < m; i++) {\n        auto [a, b] = edges[i];\n\
    \        el.push_back({a, i});\n        if (DIRECTED) deg[a]++, deg[b]--;\n  \
    \      else {\n            el.push_back({b, i});\n            deg[a]++, deg[b]++;\n\
    \        }\n    }\n    // \u59CB\u70B9: \u6709\u5411\u306A\u3089 \u51FA - \u5165\
    \ = 1 \u306E\u9802\u70B9\uFF0C\u7121\u5411\u306A\u3089\u6B21\u6570\u304C\u5947\
    \u6570\u306E\u9802\u70B9\uFF0E\u306A\u3051\u308C\u3070\u8FBA\u3092\u6301\u3064\
    \u9802\u70B9\n    int s = edges[0].first, odd = 0;\n    for (int v = 0; v < n;\
    \ v++) {\n        if (DIRECTED) {\n            if (deg[v] == 1) s = v, odd++;\n\
    \            else if (deg[v] != 0 && deg[v] != -1) return {};\n            else\
    \ if (deg[v] == -1) odd++;\n        } else if (deg[v] & 1) {\n            if (odd\
    \ == 0) s = v;\n            odd++;\n        }\n    }\n    if (odd > 2) return\
    \ {};\n    CSR<int> g(n, el);\n    vector<int> it(g.start.begin(), g.start.end()\
    \ - 1);\n    vector<char> used(m, 0);\n    vector<int> vs, es;\n    vs.reserve(m\
    \ + 1), es.reserve(m);\n    // \u30B9\u30BF\u30C3\u30AF\u306B\u306F (\u9802\u70B9\
    , \u305D\u3053\u3078\u6765\u305F\u8FBA)\n    vector<pair<int, int>> stk{{s, -1}};\n\
    \    while (!stk.empty()) {\n        auto [v, ein] = stk.back();\n        int\
    \ &i = it[v];\n        while (i < g.start[v + 1] && used[g.elist[i]]) i++;\n \
    \       if (i == g.start[v + 1]) {\n            vs.push_back(v);\n           \
    \ if (ein >= 0) es.push_back(ein);\n            stk.pop_back();\n            continue;\n\
    \        }\n        int e = g.elist[i++];\n        used[e] = 1;\n        int to\
    \ = DIRECTED ? edges[e].second : edges[e].first ^ edges[e].second ^ v;\n     \
    \   stk.push_back({to, e});\n    }\n    if ((int)es.size() != m) return {};  //\
    \ \u9023\u7D50\u3067\u306A\u3044\n    reverse(vs.begin(), vs.end()), reverse(es.begin(),\
    \ es.end());\n    return {vs, es};\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"csr.hpp\"\n\n// \u30AA\
    \u30A4\u30E9\u30FC\u8DEF (\u5168\u3066\u306E\u8FBA\u3092\u3061\u3087\u3046\u3069\
    \ 1 \u56DE\u305A\u3064\u901A\u308B\u8DEF)\uFF0EHierholzer \u6CD5\uFF0C\u975E\u518D\
    \u5E30\u3067 O(n + m)\n// \u8FD4\u308A\u5024: {\u9802\u70B9\u306E\u5217 (m+1 \u500B\
    ), \u8FBA\u756A\u53F7\u306E\u5217 (m \u500B)}\uFF0E\u5B58\u5728\u3057\u306A\u3051\
    \u308C\u3070\u7A7A\u306E pair\n// \u8FBA\u304C\u306A\u3044\u3068\u304D\u306F {{0},\
    \ {}} (\u9802\u70B9 0 \u304B\u3089\u9577\u3055 0 \u306E\u8DEF)\n// DIRECTED =\
    \ true \u306A\u3089\u6709\u5411\u30B0\u30E9\u30D5\uFF0Cfalse \u306A\u3089\u7121\
    \u5411\u30B0\u30E9\u30D5\n\ntemplate <bool DIRECTED>\npair<vector<int>, vector<int>>\
    \ eulerian_trail(int n, const vector<pair<int, int>> &edges) {\n    int m = edges.size();\n\
    \    if (m == 0) return {{0}, {}};\n    vector<int> deg(n, 0);  // \u6709\u5411\
    : \u51FA\u6B21\u6570 - \u5165\u6B21\u6570\uFF0C\u7121\u5411: \u6B21\u6570\n  \
    \  vector<pair<int, int>> el;\n    el.reserve(DIRECTED ? m : 2 * m);\n    for\
    \ (int i = 0; i < m; i++) {\n        auto [a, b] = edges[i];\n        el.push_back({a,\
    \ i});\n        if (DIRECTED) deg[a]++, deg[b]--;\n        else {\n          \
    \  el.push_back({b, i});\n            deg[a]++, deg[b]++;\n        }\n    }\n\
    \    // \u59CB\u70B9: \u6709\u5411\u306A\u3089 \u51FA - \u5165 = 1 \u306E\u9802\
    \u70B9\uFF0C\u7121\u5411\u306A\u3089\u6B21\u6570\u304C\u5947\u6570\u306E\u9802\
    \u70B9\uFF0E\u306A\u3051\u308C\u3070\u8FBA\u3092\u6301\u3064\u9802\u70B9\n   \
    \ int s = edges[0].first, odd = 0;\n    for (int v = 0; v < n; v++) {\n      \
    \  if (DIRECTED) {\n            if (deg[v] == 1) s = v, odd++;\n            else\
    \ if (deg[v] != 0 && deg[v] != -1) return {};\n            else if (deg[v] ==\
    \ -1) odd++;\n        } else if (deg[v] & 1) {\n            if (odd == 0) s =\
    \ v;\n            odd++;\n        }\n    }\n    if (odd > 2) return {};\n    CSR<int>\
    \ g(n, el);\n    vector<int> it(g.start.begin(), g.start.end() - 1);\n    vector<char>\
    \ used(m, 0);\n    vector<int> vs, es;\n    vs.reserve(m + 1), es.reserve(m);\n\
    \    // \u30B9\u30BF\u30C3\u30AF\u306B\u306F (\u9802\u70B9, \u305D\u3053\u3078\
    \u6765\u305F\u8FBA)\n    vector<pair<int, int>> stk{{s, -1}};\n    while (!stk.empty())\
    \ {\n        auto [v, ein] = stk.back();\n        int &i = it[v];\n        while\
    \ (i < g.start[v + 1] && used[g.elist[i]]) i++;\n        if (i == g.start[v +\
    \ 1]) {\n            vs.push_back(v);\n            if (ein >= 0) es.push_back(ein);\n\
    \            stk.pop_back();\n            continue;\n        }\n        int e\
    \ = g.elist[i++];\n        used[e] = 1;\n        int to = DIRECTED ? edges[e].second\
    \ : edges[e].first ^ edges[e].second ^ v;\n        stk.push_back({to, e});\n \
    \   }\n    if ((int)es.size() != m) return {};  // \u9023\u7D50\u3067\u306A\u3044\
    \n    reverse(vs.begin(), vs.end()), reverse(es.begin(), es.end());\n    return\
    \ {vs, es};\n}\n"
  dependsOn:
  - template.hpp
  - graph/csr.hpp
  isVerificationFile: false
  path: graph/eulerian_trail.hpp
  requiredBy: []
  timestamp: '2026-10-15 00:32:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/graph_components.test.cpp
  - test/eulerian_trail_directed.test.cpp
documentation_of: graph/eulerian_trail.hpp
layout: document
title: "\u30AA\u30A4\u30E9\u30FC\u8DEF (Eulerian Trail)"
---

## 概要

全ての辺をちょうど 1 回ずつ通る路（オイラー路）を求める。Hierholzer の方法を非再帰で実装。$O(n + m)$。

- 存在条件（有向）：全ての頂点で 出次数 = 入次数、または 出 − 入 = 1 の頂点と 入 − 出 = 1 の頂点がちょうど 1 つずつ（始点・終点）で、辺を持つ頂点が全部つながっている。
- 存在条件（無向）：次数が奇数の頂点が 0 個か 2 個で、辺を持つ頂点が全部つながっている。

始点から「まだ使っていない辺があれば進む、なければ路に出力して戻る」を繰り返し、出力を逆順にする。全ての辺を使えなかったら非連結なので存在しない。

## 使い方

```cpp
vector<pair<int, int>> edges;
auto [vs, es] = eulerian_trail<true>(n, edges);    // 有向．vs: 頂点の列 (m+1 個)，es: 辺番号の列 (m 個)
auto [vs2, es2] = eulerian_trail<false>(n, edges); // 無向
if (vs.empty()) { /* 存在しない */ }
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `pair<vector<int>, vector<int>> eulerian_trail<DIRECTED>(int n, edges)` | オイラー路．なければ空 | $O(n + m)$ |

## 注意

- 辺が 1 本もないときは `{{0}, {}}`（頂点 0 だけの長さ 0 の路）を返す。
- 閉路（始点 = 終点）が欲しいときは、全頂点の次数条件が「出 = 入」（無向なら全て偶数）であることを先に確かめる。
