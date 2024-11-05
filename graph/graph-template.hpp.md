---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dijkstra.test.cpp
    title: test/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://ei1333.github.io/library/graph/graph-template.hpp
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
    \ 3 \"graph/graph-template.hpp\"\n\n/*\n\u5927\u304D\u3081\u306E\u9053\u5177\u3092\
    \u4F5C\u308A\u305F\u304F\u306A\u3063\u305F\u6642\u7528\u306B\u30B0\u30E9\u30D5\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u3092\u4F5C\u308A\u307E\u3057\u305F\n\u3069\
    \u3093\u306A\u6A5F\u80FD\u304C\u6B32\u3057\u304F\u306A\u308B\u304B\u898B\u901A\
    \u305B\u306A\u3044\u306E\u3067\u4E00\u65E6\u3046\u3057\u3055\u3093\u306E\u30E9\
    \u30A4\u30D6\u30E9\u30EA\u3092\u53C2\u8003\u306B\u6574\u5099\u3057\u3066\u307E\
    \u3059 (\u6B32\u3057\u3044\u6A5F\u80FD\u304C\u5897\u3048\u305F\u3089\u5909\u308F\
    \u308B\u304B\u3082)\nhttps://ei1333.github.io/library/graph/graph-template.hpp\n\
    */\n\ntemplate <typename T = int>\nstruct Edge {\n    // \u8FBA\u306Efrom , to\n\
    \    int from, to;\n\n    // \u91CD\u307F\u4ED8\u304D\u30B0\u30E9\u30D5\u7528\u30B3\
    \u30B9\u30C8\n    T cost;\n\n    // \u6A4B\u306E\u5217\u6319\u7B49\u304C\u5FC5\
    \u8981\u306A\u6642\u7528\u306E\u8FBA\u306E\u756A\u53F7\n    int idx;\n\n    Edge()\
    \ = default;\n\n    Edge(int from, int to, T cost = 1, int idx = -1) : from(from),\
    \ to(to), cost(cost), idx(idx) {}\n};\n\ntemplate <typename T = int>\nstruct Graph\
    \ {\n\n    // \u30B0\u30E9\u30D5\u672C\u4F53\n    vector<vector<Edge<T> > > g;\n\
    \    // \u8FBA\u306E\u756A\u53F7\u3065\u3051\u7528\u5909\u6570\n    int es;\n\n\
    \    Graph() = default;\n\n    explicit Graph(int n) : g(n), es(0) {}\n\n    //\
    \ \u9802\u70B9\u6570\u3092\u8FD4\u3059\n    size_t size() const { return g.size();\
    \ }\n\n    // \u6709\u5411\u8FBA\u3092\u8FFD\u52A0\n    void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n\
    \    }\n\n    // \u7121\u5411\u8FBA\u3092\u8FFD\u52A0\n    void add_edge(int from,\
    \ int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es);\n \
    \       g[to].emplace_back(to, from, cost, es++);\n    }\n\n    // \u9802\u70B9\
    \u756A\u53F7\u3092\u5165\u529B\u3059\u308B\u3068\u305D\u306E\u9802\u70B9\u304B\
    \u3089\u751F\u3048\u3066\u308B\u8FBA\u306E\u96C6\u5408\u3092\u8FD4\u3059\n   \
    \ inline vector<Edge<T> > &operator[](const int &k) { return g[k]; }\n    inline\
    \ const vector<Edge<T> > &operator[](const int &k) const { return g[k]; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n/*\n\u5927\u304D\u3081\u306E\
    \u9053\u5177\u3092\u4F5C\u308A\u305F\u304F\u306A\u3063\u305F\u6642\u7528\u306B\
    \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u3092\u4F5C\u308A\u307E\
    \u3057\u305F\n\u3069\u3093\u306A\u6A5F\u80FD\u304C\u6B32\u3057\u304F\u306A\u308B\
    \u304B\u898B\u901A\u305B\u306A\u3044\u306E\u3067\u4E00\u65E6\u3046\u3057\u3055\
    \u3093\u306E\u30E9\u30A4\u30D6\u30E9\u30EA\u3092\u53C2\u8003\u306B\u6574\u5099\
    \u3057\u3066\u307E\u3059 (\u6B32\u3057\u3044\u6A5F\u80FD\u304C\u5897\u3048\u305F\
    \u3089\u5909\u308F\u308B\u304B\u3082)\nhttps://ei1333.github.io/library/graph/graph-template.hpp\n\
    */\n\ntemplate <typename T = int>\nstruct Edge {\n    // \u8FBA\u306Efrom , to\n\
    \    int from, to;\n\n    // \u91CD\u307F\u4ED8\u304D\u30B0\u30E9\u30D5\u7528\u30B3\
    \u30B9\u30C8\n    T cost;\n\n    // \u6A4B\u306E\u5217\u6319\u7B49\u304C\u5FC5\
    \u8981\u306A\u6642\u7528\u306E\u8FBA\u306E\u756A\u53F7\n    int idx;\n\n    Edge()\
    \ = default;\n\n    Edge(int from, int to, T cost = 1, int idx = -1) : from(from),\
    \ to(to), cost(cost), idx(idx) {}\n};\n\ntemplate <typename T = int>\nstruct Graph\
    \ {\n\n    // \u30B0\u30E9\u30D5\u672C\u4F53\n    vector<vector<Edge<T> > > g;\n\
    \    // \u8FBA\u306E\u756A\u53F7\u3065\u3051\u7528\u5909\u6570\n    int es;\n\n\
    \    Graph() = default;\n\n    explicit Graph(int n) : g(n), es(0) {}\n\n    //\
    \ \u9802\u70B9\u6570\u3092\u8FD4\u3059\n    size_t size() const { return g.size();\
    \ }\n\n    // \u6709\u5411\u8FBA\u3092\u8FFD\u52A0\n    void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n\
    \    }\n\n    // \u7121\u5411\u8FBA\u3092\u8FFD\u52A0\n    void add_edge(int from,\
    \ int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es);\n \
    \       g[to].emplace_back(to, from, cost, es++);\n    }\n\n    // \u9802\u70B9\
    \u756A\u53F7\u3092\u5165\u529B\u3059\u308B\u3068\u305D\u306E\u9802\u70B9\u304B\
    \u3089\u751F\u3048\u3066\u308B\u8FBA\u306E\u96C6\u5408\u3092\u8FD4\u3059\n   \
    \ inline vector<Edge<T> > &operator[](const int &k) { return g[k]; }\n    inline\
    \ const vector<Edge<T> > &operator[](const int &k) const { return g[k]; }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/graph-template.hpp
  requiredBy:
  - graph/dijkstra.hpp
  timestamp: '2024-11-05 15:14:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dijkstra.test.cpp
documentation_of: graph/graph-template.hpp
layout: document
redirect_from:
- /library/graph/graph-template.hpp
- /library/graph/graph-template.hpp.html
title: graph/graph-template.hpp
---
