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
    path: test/cycle_detection.test.cpp
    title: test/cycle_detection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cycle_detection_undirected.test.cpp
    title: test/cycle_detection_undirected.test.cpp
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
    graph/cycle_detection.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\n\
    // \u9589\u8DEF\u691C\u51FA\n// find_cycle_directed(n, edges)   : \u6709\u5411\
    \u30B0\u30E9\u30D5\u306E\u9589\u8DEF\u3092 1 \u3064\uFF0E\u8FBA\u756A\u53F7\u306E\
    \u5217 (\u306A\u3051\u308C\u3070\u7A7A)\n// find_cycle_undirected(n, edges) :\
    \ \u7121\u5411\u30B0\u30E9\u30D5\u306E\u9589\u8DEF\u3092 1 \u3064\uFF0E{\u9802\
    \u70B9\u306E\u5217, \u8FBA\u756A\u53F7\u306E\u5217} (\u306A\u3051\u308C\u3070\u7A7A\
    )\n// \u3069\u3061\u3089\u3082\u975E\u518D\u5E30\u306E DFS \u3067 O(n + m)\n\n\
    inline vector<int> find_cycle_directed(int n, const vector<pair<int, int>> &edges)\
    \ {\n    int m = edges.size();\n    vector<pair<int, int>> el(m);\n    for (int\
    \ i = 0; i < m; i++) el[i] = {edges[i].first, i};\n    CSR<int> g(n, el);\n  \
    \  // state: 0 = \u672A\u8A2A\u554F\uFF0C1 = \u63A2\u7D22\u4E2D (\u30B9\u30BF\u30C3\
    \u30AF\u306B\u3042\u308B)\uFF0C2 = \u7D42\u4E86\n    vector<char> state(n, 0);\n\
    \    vector<int> it(n), par_edge(n, -1), stk;\n    for (int s = 0; s < n; s++)\
    \ {\n        if (state[s]) continue;\n        stk.push_back(s), state[s] = 1,\
    \ it[s] = g.start[s];\n        while (!stk.empty()) {\n            int v = stk.back();\n\
    \            if (it[v] == g.start[v + 1]) {\n                state[v] = 2, stk.pop_back();\n\
    \                continue;\n            }\n            int e = g.elist[it[v]++],\
    \ to = edges[e].second;\n            if (state[to] == 0) {\n                par_edge[to]\
    \ = e, state[to] = 1, it[to] = g.start[to];\n                stk.push_back(to);\n\
    \            } else if (state[to] == 1) {\n                // to \u2192 ... \u2192\
    \ v \u2192 to \u304C\u9589\u8DEF\n                vector<int> cyc{e};\n      \
    \          for (int x = v; x != to; x = edges[par_edge[x]].first) cyc.push_back(par_edge[x]);\n\
    \                reverse(cyc.begin(), cyc.end());\n                return cyc;\n\
    \            }\n        }\n    }\n    return {};\n}\n\ninline pair<vector<int>,\
    \ vector<int>> find_cycle_undirected(int n, const vector<pair<int, int>> &edges)\
    \ {\n    int m = edges.size();\n    vector<pair<int, int>> el;\n    el.reserve(2\
    \ * m);\n    for (int i = 0; i < m; i++) {\n        auto [u, v] = edges[i];\n\
    \        if (u == v) return {{u}, {i}};  // \u81EA\u5DF1\u30EB\u30FC\u30D7\n \
    \       el.push_back({u, i}), el.push_back({v, i});\n    }\n    CSR<int> g(n,\
    \ el);\n    vector<int> depth(n, -1), it(n), par_edge(n, -1), stk;\n    for (int\
    \ s = 0; s < n; s++) {\n        if (depth[s] >= 0) continue;\n        depth[s]\
    \ = 0, it[s] = g.start[s], stk.push_back(s);\n        while (!stk.empty()) {\n\
    \            int v = stk.back();\n            if (it[v] == g.start[v + 1]) {\n\
    \                stk.pop_back();\n                continue;\n            }\n \
    \           int e = g.elist[it[v]++];\n            if (e == par_edge[v]) continue;\n\
    \            int to = edges[e].first ^ edges[e].second ^ v;\n            if (depth[to]\
    \ < 0) {\n                depth[to] = depth[v] + 1, par_edge[to] = e, it[to] =\
    \ g.start[to];\n                stk.push_back(to);\n            } else if (depth[to]\
    \ < depth[v]) {\n                // to \u2192 ... \u2192 v \u2192 to (\u5F8C\u9000\
    \u8FBA e)\n                vector<int> vs, es;\n                for (int x = v;\
    \ x != to;) {\n                    vs.push_back(x), es.push_back(par_edge[x]);\n\
    \                    int pe = par_edge[x];\n                    x = edges[pe].first\
    \ ^ edges[pe].second ^ x;\n                }\n                vs.push_back(to);\n\
    \                reverse(vs.begin(), vs.end()), reverse(es.begin(), es.end());\n\
    \                es.push_back(e);\n                return {vs, es};\n        \
    \    }\n        }\n    }\n    return {};\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"csr.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u9589\u8DEF\u691C\u51FA\n// find_cycle_directed(n, edges)   : \u6709\u5411\
    \u30B0\u30E9\u30D5\u306E\u9589\u8DEF\u3092 1 \u3064\uFF0E\u8FBA\u756A\u53F7\u306E\
    \u5217 (\u306A\u3051\u308C\u3070\u7A7A)\n// find_cycle_undirected(n, edges) :\
    \ \u7121\u5411\u30B0\u30E9\u30D5\u306E\u9589\u8DEF\u3092 1 \u3064\uFF0E{\u9802\
    \u70B9\u306E\u5217, \u8FBA\u756A\u53F7\u306E\u5217} (\u306A\u3051\u308C\u3070\u7A7A\
    )\n// \u3069\u3061\u3089\u3082\u975E\u518D\u5E30\u306E DFS \u3067 O(n + m)\n\n\
    inline vector<int> find_cycle_directed(int n, const vector<pair<int, int>> &edges)\
    \ {\n    int m = edges.size();\n    vector<pair<int, int>> el(m);\n    for (int\
    \ i = 0; i < m; i++) el[i] = {edges[i].first, i};\n    CSR<int> g(n, el);\n  \
    \  // state: 0 = \u672A\u8A2A\u554F\uFF0C1 = \u63A2\u7D22\u4E2D (\u30B9\u30BF\u30C3\
    \u30AF\u306B\u3042\u308B)\uFF0C2 = \u7D42\u4E86\n    vector<char> state(n, 0);\n\
    \    vector<int> it(n), par_edge(n, -1), stk;\n    for (int s = 0; s < n; s++)\
    \ {\n        if (state[s]) continue;\n        stk.push_back(s), state[s] = 1,\
    \ it[s] = g.start[s];\n        while (!stk.empty()) {\n            int v = stk.back();\n\
    \            if (it[v] == g.start[v + 1]) {\n                state[v] = 2, stk.pop_back();\n\
    \                continue;\n            }\n            int e = g.elist[it[v]++],\
    \ to = edges[e].second;\n            if (state[to] == 0) {\n                par_edge[to]\
    \ = e, state[to] = 1, it[to] = g.start[to];\n                stk.push_back(to);\n\
    \            } else if (state[to] == 1) {\n                // to \u2192 ... \u2192\
    \ v \u2192 to \u304C\u9589\u8DEF\n                vector<int> cyc{e};\n      \
    \          for (int x = v; x != to; x = edges[par_edge[x]].first) cyc.push_back(par_edge[x]);\n\
    \                reverse(cyc.begin(), cyc.end());\n                return cyc;\n\
    \            }\n        }\n    }\n    return {};\n}\n\ninline pair<vector<int>,\
    \ vector<int>> find_cycle_undirected(int n, const vector<pair<int, int>> &edges)\
    \ {\n    int m = edges.size();\n    vector<pair<int, int>> el;\n    el.reserve(2\
    \ * m);\n    for (int i = 0; i < m; i++) {\n        auto [u, v] = edges[i];\n\
    \        if (u == v) return {{u}, {i}};  // \u81EA\u5DF1\u30EB\u30FC\u30D7\n \
    \       el.push_back({u, i}), el.push_back({v, i});\n    }\n    CSR<int> g(n,\
    \ el);\n    vector<int> depth(n, -1), it(n), par_edge(n, -1), stk;\n    for (int\
    \ s = 0; s < n; s++) {\n        if (depth[s] >= 0) continue;\n        depth[s]\
    \ = 0, it[s] = g.start[s], stk.push_back(s);\n        while (!stk.empty()) {\n\
    \            int v = stk.back();\n            if (it[v] == g.start[v + 1]) {\n\
    \                stk.pop_back();\n                continue;\n            }\n \
    \           int e = g.elist[it[v]++];\n            if (e == par_edge[v]) continue;\n\
    \            int to = edges[e].first ^ edges[e].second ^ v;\n            if (depth[to]\
    \ < 0) {\n                depth[to] = depth[v] + 1, par_edge[to] = e, it[to] =\
    \ g.start[to];\n                stk.push_back(to);\n            } else if (depth[to]\
    \ < depth[v]) {\n                // to \u2192 ... \u2192 v \u2192 to (\u5F8C\u9000\
    \u8FBA e)\n                vector<int> vs, es;\n                for (int x = v;\
    \ x != to;) {\n                    vs.push_back(x), es.push_back(par_edge[x]);\n\
    \                    int pe = par_edge[x];\n                    x = edges[pe].first\
    \ ^ edges[pe].second ^ x;\n                }\n                vs.push_back(to);\n\
    \                reverse(vs.begin(), vs.end()), reverse(es.begin(), es.end());\n\
    \                es.push_back(e);\n                return {vs, es};\n        \
    \    }\n        }\n    }\n    return {};\n}\n"
  dependsOn:
  - template.hpp
  - graph/csr.hpp
  isVerificationFile: false
  path: graph/cycle_detection.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/cycle_detection_undirected.test.cpp
  - test/unittest/graph_components.test.cpp
  - test/cycle_detection.test.cpp
documentation_of: graph/cycle_detection.hpp
layout: document
title: "\u9589\u8DEF\u691C\u51FA (Cycle Detection)"
---

## 概要

グラフの閉路を 1 つ見つける。非再帰の DFS で $O(n + m)$。

- 有向：DFS 中に「探索中（スタックにある）頂点」への辺を見つけたら、それが閉路を作る。
- 無向：DFS 木の親への辺（**辺番号** で区別するので多重辺も正しく扱う）以外で、訪問済みの祖先への辺（後退辺）を見つけたら閉路。自己ループも閉路。

## 使い方

```cpp
vector<pair<int, int>> edges;                       // 辺 i = (u, v)
vector<int> cyc = find_cycle_directed(n, edges);    // 辺番号の列 (この順にたどると閉路)．なければ空
auto [vs, es] = find_cycle_undirected(n, edges);    // 頂点の列と辺番号の列 (es[i] は vs[i] と vs[i+1] を結ぶ)．なければ空
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<int> find_cycle_directed(int n, edges)` | 有向グラフの閉路 | $O(n + m)$ |
| `pair<vector<int>, vector<int>> find_cycle_undirected(int n, edges)` | 無向グラフの閉路（頂点も辺も重複しない） | $O(n + m)$ |
