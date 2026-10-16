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
    path: test/general_matching.test.cpp
    title: test/general_matching.test.cpp
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
    graph/general_matching.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\
    \ (Edmonds \u306E\u82B1\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0)\uFF0EO(n^3)\n// \u672A\
    \u30DE\u30C3\u30C1\u306E\u9802\u70B9\u304B\u3089\u4EA4\u4E92\u8DEF\u3092 BFS \u3067\
    \u63A2\u3057\uFF0C\u5947\u9589\u8DEF (\u82B1) \u3092\u898B\u3064\u3051\u305F\u3089\
    \ 1 \u9802\u70B9 (base) \u306B\u7E2E\u7D04\u3057\u305F\u3082\u306E\u3068\u3057\
    \u3066\u6271\u3046\uFF0E\n// \u7E2E\u7D04\u306F base[] (\u5404\u9802\u70B9\u304C\
    \u5C5E\u3059\u308B\u82B1\u306E\u4EE3\u8868) \u3067\u8868\u3057\uFF0C\u5B9F\u969B\
    \u306B\u306F\u30B0\u30E9\u30D5\u3092\u4F5C\u308A\u76F4\u3055\u306A\u3044\nstruct\
    \ GeneralMatching {\n    int n;\n    vector<pair<int, int>> edges;\n    vector<int>\
    \ mate;  // \u76F8\u624B (\u3044\u306A\u3051\u308C\u3070 -1)\n\n    GeneralMatching(int\
    \ n) : n(n), mate(n, -1) {}\n    void add_edge(int u, int v) { edges.push_back({u,\
    \ v}); }\n\n    int solve() {\n        vector<pair<int, int>> el;\n        el.reserve(2\
    \ * edges.size());\n        for (auto [u, v] : edges)\n            if (u != v)\
    \ el.push_back({u, v}), el.push_back({v, u});\n        CSR<int> g(n, el);\n  \
    \      // \u8CAA\u6B32\u306B\u521D\u671F\u30DE\u30C3\u30C1\u30F3\u30B0\n     \
    \   for (int v = 0; v < n; v++) {\n            if (mate[v] >= 0) continue;\n \
    \           for (int i = g.start[v]; i < g.start[v + 1]; i++) {\n            \
    \    int w = g.elist[i];\n                if (mate[w] < 0) {\n               \
    \     mate[v] = w, mate[w] = v;\n                    break;\n                }\n\
    \            }\n        }\n        vector<int> par(n), base(n), que(n), mark(n,\
    \ 0);\n        vector<char> used(n), in_blossom(n);\n        int stamp = 0;\n\
    \        // \u82B1\u306E base \u3092\u6C42\u3081\u308B (\u4EA4\u4E92\u6728\u306E\
    \ 2 \u9802\u70B9\u306E\u6700\u8FD1\u5171\u901A\u7956\u5148)\n        auto lca\
    \ = [&](int a, int b) {\n            stamp++;\n            while (true) {\n  \
    \              a = base[a];\n                mark[a] = stamp;\n              \
    \  if (mate[a] < 0) break;\n                a = par[mate[a]];\n            }\n\
    \            while (true) {\n                b = base[b];\n                if\
    \ (mark[b] == stamp) return b;\n                b = par[mate[b]];\n          \
    \  }\n        };\n        auto mark_path = [&](int v, int b, int child) {\n  \
    \          while (base[v] != b) {\n                in_blossom[base[v]] = in_blossom[base[mate[v]]]\
    \ = 1;\n                par[v] = child;\n                child = mate[v];\n  \
    \              v = par[mate[v]];\n            }\n        };\n        // root \u304B\
    \u3089\u5897\u52A0\u8DEF\u3092\u63A2\u3057\uFF0C\u7D42\u70B9 (\u672A\u30DE\u30C3\
    \u30C1\u9802\u70B9) \u3092\u8FD4\u3059\uFF0E\u306A\u3051\u308C\u3070 -1\n    \
    \    auto find_path = [&](int root) {\n            fill(used.begin(), used.end(),\
    \ 0);\n            fill(par.begin(), par.end(), -1);\n            iota(base.begin(),\
    \ base.end(), 0);\n            int qh = 0, qt = 0;\n            used[root] = 1,\
    \ que[qt++] = root;\n            while (qh < qt) {\n                int v = que[qh++];\n\
    \                for (int i = g.start[v]; i < g.start[v + 1]; i++) {\n       \
    \             int to = g.elist[i];\n                    if (base[v] == base[to]\
    \ || mate[v] == to) continue;\n                    if (to == root || (mate[to]\
    \ >= 0 && par[mate[to]] >= 0)) {\n                        // \u5947\u9589\u8DEF\
    \ (\u82B1) \u3092\u898B\u3064\u3051\u305F: base \u3092 cur \u306B\u307E\u3068\u3081\
    \u308B\n                        int cur = lca(v, to);\n                      \
    \  fill(in_blossom.begin(), in_blossom.end(), 0);\n                        mark_path(v,\
    \ cur, to), mark_path(to, cur, v);\n                        for (int x = 0; x\
    \ < n; x++) {\n                            if (!in_blossom[base[x]]) continue;\n\
    \                            base[x] = cur;\n                            if (!used[x])\
    \ used[x] = 1, que[qt++] = x;\n                        }\n                   \
    \ } else if (par[to] < 0) {\n                        par[to] = v;\n          \
    \              if (mate[to] < 0) return to;\n                        int nx =\
    \ mate[to];\n                        used[nx] = 1, que[qt++] = nx;\n         \
    \           }\n                }\n            }\n            return -1;\n    \
    \    };\n        for (int v = 0; v < n; v++) {\n            if (mate[v] >= 0)\
    \ continue;\n            int u = find_path(v);\n            // \u5897\u52A0\u8DEF\
    \u306B\u6CBF\u3063\u3066\u30DE\u30C3\u30C1\u30F3\u30B0\u3092\u53CD\u8EE2\n   \
    \         while (u >= 0) {\n                int pv = par[u], ppv = mate[pv];\n\
    \                mate[u] = pv, mate[pv] = u;\n                u = ppv;\n     \
    \       }\n        }\n        int res = 0;\n        for (int v = 0; v < n; v++)\n\
    \            if (mate[v] > v) res++;\n        return res;\n    }\n\n    // \u30DE\
    \u30C3\u30C1\u30F3\u30B0\u306E\u8FBA (u < v)\n    vector<pair<int, int>> matching()\
    \ const {\n        vector<pair<int, int>> res;\n        for (int v = 0; v < n;\
    \ v++)\n            if (mate[v] > v) res.push_back({v, mate[v]});\n        return\
    \ res;\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"csr.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\
    \ (Edmonds \u306E\u82B1\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0)\uFF0EO(n^3)\n// \u672A\
    \u30DE\u30C3\u30C1\u306E\u9802\u70B9\u304B\u3089\u4EA4\u4E92\u8DEF\u3092 BFS \u3067\
    \u63A2\u3057\uFF0C\u5947\u9589\u8DEF (\u82B1) \u3092\u898B\u3064\u3051\u305F\u3089\
    \ 1 \u9802\u70B9 (base) \u306B\u7E2E\u7D04\u3057\u305F\u3082\u306E\u3068\u3057\
    \u3066\u6271\u3046\uFF0E\n// \u7E2E\u7D04\u306F base[] (\u5404\u9802\u70B9\u304C\
    \u5C5E\u3059\u308B\u82B1\u306E\u4EE3\u8868) \u3067\u8868\u3057\uFF0C\u5B9F\u969B\
    \u306B\u306F\u30B0\u30E9\u30D5\u3092\u4F5C\u308A\u76F4\u3055\u306A\u3044\nstruct\
    \ GeneralMatching {\n    int n;\n    vector<pair<int, int>> edges;\n    vector<int>\
    \ mate;  // \u76F8\u624B (\u3044\u306A\u3051\u308C\u3070 -1)\n\n    GeneralMatching(int\
    \ n) : n(n), mate(n, -1) {}\n    void add_edge(int u, int v) { edges.push_back({u,\
    \ v}); }\n\n    int solve() {\n        vector<pair<int, int>> el;\n        el.reserve(2\
    \ * edges.size());\n        for (auto [u, v] : edges)\n            if (u != v)\
    \ el.push_back({u, v}), el.push_back({v, u});\n        CSR<int> g(n, el);\n  \
    \      // \u8CAA\u6B32\u306B\u521D\u671F\u30DE\u30C3\u30C1\u30F3\u30B0\n     \
    \   for (int v = 0; v < n; v++) {\n            if (mate[v] >= 0) continue;\n \
    \           for (int i = g.start[v]; i < g.start[v + 1]; i++) {\n            \
    \    int w = g.elist[i];\n                if (mate[w] < 0) {\n               \
    \     mate[v] = w, mate[w] = v;\n                    break;\n                }\n\
    \            }\n        }\n        vector<int> par(n), base(n), que(n), mark(n,\
    \ 0);\n        vector<char> used(n), in_blossom(n);\n        int stamp = 0;\n\
    \        // \u82B1\u306E base \u3092\u6C42\u3081\u308B (\u4EA4\u4E92\u6728\u306E\
    \ 2 \u9802\u70B9\u306E\u6700\u8FD1\u5171\u901A\u7956\u5148)\n        auto lca\
    \ = [&](int a, int b) {\n            stamp++;\n            while (true) {\n  \
    \              a = base[a];\n                mark[a] = stamp;\n              \
    \  if (mate[a] < 0) break;\n                a = par[mate[a]];\n            }\n\
    \            while (true) {\n                b = base[b];\n                if\
    \ (mark[b] == stamp) return b;\n                b = par[mate[b]];\n          \
    \  }\n        };\n        auto mark_path = [&](int v, int b, int child) {\n  \
    \          while (base[v] != b) {\n                in_blossom[base[v]] = in_blossom[base[mate[v]]]\
    \ = 1;\n                par[v] = child;\n                child = mate[v];\n  \
    \              v = par[mate[v]];\n            }\n        };\n        // root \u304B\
    \u3089\u5897\u52A0\u8DEF\u3092\u63A2\u3057\uFF0C\u7D42\u70B9 (\u672A\u30DE\u30C3\
    \u30C1\u9802\u70B9) \u3092\u8FD4\u3059\uFF0E\u306A\u3051\u308C\u3070 -1\n    \
    \    auto find_path = [&](int root) {\n            fill(used.begin(), used.end(),\
    \ 0);\n            fill(par.begin(), par.end(), -1);\n            iota(base.begin(),\
    \ base.end(), 0);\n            int qh = 0, qt = 0;\n            used[root] = 1,\
    \ que[qt++] = root;\n            while (qh < qt) {\n                int v = que[qh++];\n\
    \                for (int i = g.start[v]; i < g.start[v + 1]; i++) {\n       \
    \             int to = g.elist[i];\n                    if (base[v] == base[to]\
    \ || mate[v] == to) continue;\n                    if (to == root || (mate[to]\
    \ >= 0 && par[mate[to]] >= 0)) {\n                        // \u5947\u9589\u8DEF\
    \ (\u82B1) \u3092\u898B\u3064\u3051\u305F: base \u3092 cur \u306B\u307E\u3068\u3081\
    \u308B\n                        int cur = lca(v, to);\n                      \
    \  fill(in_blossom.begin(), in_blossom.end(), 0);\n                        mark_path(v,\
    \ cur, to), mark_path(to, cur, v);\n                        for (int x = 0; x\
    \ < n; x++) {\n                            if (!in_blossom[base[x]]) continue;\n\
    \                            base[x] = cur;\n                            if (!used[x])\
    \ used[x] = 1, que[qt++] = x;\n                        }\n                   \
    \ } else if (par[to] < 0) {\n                        par[to] = v;\n          \
    \              if (mate[to] < 0) return to;\n                        int nx =\
    \ mate[to];\n                        used[nx] = 1, que[qt++] = nx;\n         \
    \           }\n                }\n            }\n            return -1;\n    \
    \    };\n        for (int v = 0; v < n; v++) {\n            if (mate[v] >= 0)\
    \ continue;\n            int u = find_path(v);\n            // \u5897\u52A0\u8DEF\
    \u306B\u6CBF\u3063\u3066\u30DE\u30C3\u30C1\u30F3\u30B0\u3092\u53CD\u8EE2\n   \
    \         while (u >= 0) {\n                int pv = par[u], ppv = mate[pv];\n\
    \                mate[u] = pv, mate[pv] = u;\n                u = ppv;\n     \
    \       }\n        }\n        int res = 0;\n        for (int v = 0; v < n; v++)\n\
    \            if (mate[v] > v) res++;\n        return res;\n    }\n\n    // \u30DE\
    \u30C3\u30C1\u30F3\u30B0\u306E\u8FBA (u < v)\n    vector<pair<int, int>> matching()\
    \ const {\n        vector<pair<int, int>> res;\n        for (int v = 0; v < n;\
    \ v++)\n            if (mate[v] > v) res.push_back({v, mate[v]});\n        return\
    \ res;\n    }\n};\n"
  dependsOn:
  - template.hpp
  - graph/csr.hpp
  isVerificationFile: false
  path: graph/general_matching.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unittest/graph_optimization.test.cpp
  - test/general_matching.test.cpp
documentation_of: graph/general_matching.hpp
layout: document
title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\
  \ (Edmonds \u306E\u82B1\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0)"
---

## 概要

二部とは限らない無向グラフの最大マッチングを求める。$O(n^3)$（実際には辺の数に応じてずっと速い）。

未マッチの頂点から交互路を BFS で探す。二部グラフと違い奇閉路（**花**）があると交互路がうまく延びないので、花を見つけたらその根（base）1 頂点に縮約したものとして扱う。縮約は各頂点の `base` を書き換えるだけで、グラフは作り直さない。

## 使い方

```cpp
GeneralMatching gm(n);
gm.add_edge(u, v);
int k = gm.solve();                         // 最大マッチングの大きさ
for (auto [u, v] : gm.matching()) { ... }   // u < v
gm.mate[v];                                 // 相手 (いなければ -1)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `GeneralMatching(int n)` | 空のグラフ | $O(n)$ |
| `void add_edge(int u, int v)` | 辺を追加 | 償却 $O(1)$ |
| `int solve()` | 最大マッチングの大きさ | $O(n^3)$ |
| `vector<pair<int,int>> matching()` | マッチングの辺 | $O(n)$ |

## 注意

- 自己ループは無視される。多重辺はあってもよい。
- 二部グラフと分かっているなら [`BipartiteMatching`](bipartite_matching.hpp) の方が速い。
