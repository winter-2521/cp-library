---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dijkstra.test.cpp
    title: test/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://theory-and-me.hatenablog.com/entry/2019/09/08/182442
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
    \ const vector<Edge<T> > &operator[](const int &k) const { return g[k]; }\n};\n\
    #line 3 \"graph/dijkstra.hpp\"\n\ntemplate <typename T>\nstruct Pathutil{\n  \
    \  // \u5404\u9802\u70B9\u3078\u306E\u8DDD\u96E2\u3092\u8868\u3059\u914D\u5217\
    \n    vector<T> dist;\n\n    // \u3069\u3053\u304B\u3089\u304D\u305F\u304B\u3092\
    \u8868\u3059\u914D\u5217\n    vector<int> prev;\n\n    // \u6700\u77ED\u7D4C\u8DEF\
    \u3092\u30D1\u30B9\u3067\u8FD4\u3059\u914D\u5217\n    vector<int> path;\n};\n\n\
    // \u30B0\u30E9\u30D5\u306F\u5168\u3066 0-index \u3067\u6271\u3063\u3066\u3044\
    \u308B\ntemplate <typename T = long long>\nPathutil<T> Dijikstra(const Graph<T>\
    \ &G, int from, int to = 0){\n\n    // \u6BD4\u8F03\u7528\u306B\u6700\u5927\u5024\
    \u3092\u5B9A\u6570\u3067\u5B9A\u7FA9\n    const T INF = numeric_limits<T>::max();\n\
    \    // \u9802\u70B9\u6570\n    int n = G.size();\n\n    // \u8DDD\u96E2\u3092\
    \u683C\u7D0D\u3059\u308Bvector\n    vector<T> distance;\n\n    // \u30D1\u30B9\
    \u306E\u5FA9\u5143\u3092\u884C\u3046\u305F\u3081\u306B\u3069\u3053\u304B\u3089\
    \u9077\u79FB\u3057\u305F\u304B\u3092\u30E1\u30E2\n    vector<int> prev;\n\n  \
    \  using P = pair<T,int>;\n\n    distance.resize(n,INF);\n    prev.resize(n,-1);\n\
    \n    priority_queue<P,vector<P>,greater<P>> pq;\n    distance[from] = 0;\n  \
    \  pq.emplace(distance[from], from);\n\n    while(!pq.empty()) {\n        P p\
    \ = pq.top();\n        pq.pop();\n        int v = p.second;\n\n        // \u4ECA\
    \u898B\u3066\u3044\u308B\u9802\u70B9\u306E\u8DDD\u96E2\u304C\u6700\u65B0\u306E\
    \u5024\u3067\u306A\u3051\u308C\u3070\u98DB\u3070\u3059 (\u9AD8\u901F\u5316\u7528\
    )\n        if(distance[v] < p.first) continue;\n\n        for(auto e : G[v]) {\n\
    \            // \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u306F\u8CA0\u8FBA\u304C\u3042\
    \u308B\u3068\u58CA\u308C\u308B\uFF0E\n            // \u6B63\u78BA\u306B\u306F\u3053\
    \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u306F\u8CA0\u306E\u9589\u8DEF\u304C\
    \u3042\u308B\u3068\u304D\u505C\u6B62\u3057\u306A\u3044\n            // \u53C2\u8003\
    \ -> https://theory-and-me.hatenablog.com/entry/2019/09/08/182442\n          \
    \  assert(e.to >= 0);\n            if(distance[e.to] > distance[v] + e.cost) {\n\
    \                distance[e.to] = distance[v] + e.cost;\n                // v\
    \ \u3092\u901A\u3063\u3066 e.to \u306B\u304D\u305F\n                prev[e.to]\
    \ = v;\n                pq.emplace(distance[e.to], e.to);\n            }\n   \
    \     }\n    }\n\n    // \u5230\u9054\u4E0D\u53EF\u80FD\u306A\u9802\u70B9\u3078\
    \u306E\u8DDD\u96E2\u3092 -1 \u306B\u3059\u308B\uFF0E(\u7AF6\u30D7\u30ED\u3067\u306F\
    \u5230\u9054\u4E0D\u53EF\u80FD\u306A\u3089\u3000-1\u3000\u3092\u51FA\u529B\u3059\
    \u308B\u3053\u3068\u304C\u901A\u4F8B\uFF0E)\n    for (T &costs : distance)if(costs\
    \ == INF) costs = -1;\n\n    vector<int> path;\n    for (int cur = to; cur !=\
    \ -1; cur = prev[cur]) {\n        path.push_back(cur);\n    }\n    reverse(path.begin(),\
    \ path.end()); // \u9006\u9806\u306A\u306E\u3067\u3072\u3063\u304F\u308A\u8FD4\
    \u3059\n\n    return {distance, prev, path};\n\n};\n"
  code: "#pragma once\n#include \"graph-template.hpp\"\n\ntemplate <typename T>\n\
    struct Pathutil{\n    // \u5404\u9802\u70B9\u3078\u306E\u8DDD\u96E2\u3092\u8868\
    \u3059\u914D\u5217\n    vector<T> dist;\n\n    // \u3069\u3053\u304B\u3089\u304D\
    \u305F\u304B\u3092\u8868\u3059\u914D\u5217\n    vector<int> prev;\n\n    // \u6700\
    \u77ED\u7D4C\u8DEF\u3092\u30D1\u30B9\u3067\u8FD4\u3059\u914D\u5217\n    vector<int>\
    \ path;\n};\n\n// \u30B0\u30E9\u30D5\u306F\u5168\u3066 0-index \u3067\u6271\u3063\
    \u3066\u3044\u308B\ntemplate <typename T = long long>\nPathutil<T> Dijikstra(const\
    \ Graph<T> &G, int from, int to = 0){\n\n    // \u6BD4\u8F03\u7528\u306B\u6700\
    \u5927\u5024\u3092\u5B9A\u6570\u3067\u5B9A\u7FA9\n    const T INF = numeric_limits<T>::max();\n\
    \    // \u9802\u70B9\u6570\n    int n = G.size();\n\n    // \u8DDD\u96E2\u3092\
    \u683C\u7D0D\u3059\u308Bvector\n    vector<T> distance;\n\n    // \u30D1\u30B9\
    \u306E\u5FA9\u5143\u3092\u884C\u3046\u305F\u3081\u306B\u3069\u3053\u304B\u3089\
    \u9077\u79FB\u3057\u305F\u304B\u3092\u30E1\u30E2\n    vector<int> prev;\n\n  \
    \  using P = pair<T,int>;\n\n    distance.resize(n,INF);\n    prev.resize(n,-1);\n\
    \n    priority_queue<P,vector<P>,greater<P>> pq;\n    distance[from] = 0;\n  \
    \  pq.emplace(distance[from], from);\n\n    while(!pq.empty()) {\n        P p\
    \ = pq.top();\n        pq.pop();\n        int v = p.second;\n\n        // \u4ECA\
    \u898B\u3066\u3044\u308B\u9802\u70B9\u306E\u8DDD\u96E2\u304C\u6700\u65B0\u306E\
    \u5024\u3067\u306A\u3051\u308C\u3070\u98DB\u3070\u3059 (\u9AD8\u901F\u5316\u7528\
    )\n        if(distance[v] < p.first) continue;\n\n        for(auto e : G[v]) {\n\
    \            // \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u306F\u8CA0\u8FBA\u304C\u3042\
    \u308B\u3068\u58CA\u308C\u308B\uFF0E\n            // \u6B63\u78BA\u306B\u306F\u3053\
    \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u306F\u8CA0\u306E\u9589\u8DEF\u304C\
    \u3042\u308B\u3068\u304D\u505C\u6B62\u3057\u306A\u3044\n            // \u53C2\u8003\
    \ -> https://theory-and-me.hatenablog.com/entry/2019/09/08/182442\n          \
    \  assert(e.to >= 0);\n            if(distance[e.to] > distance[v] + e.cost) {\n\
    \                distance[e.to] = distance[v] + e.cost;\n                // v\
    \ \u3092\u901A\u3063\u3066 e.to \u306B\u304D\u305F\n                prev[e.to]\
    \ = v;\n                pq.emplace(distance[e.to], e.to);\n            }\n   \
    \     }\n    }\n\n    // \u5230\u9054\u4E0D\u53EF\u80FD\u306A\u9802\u70B9\u3078\
    \u306E\u8DDD\u96E2\u3092 -1 \u306B\u3059\u308B\uFF0E(\u7AF6\u30D7\u30ED\u3067\u306F\
    \u5230\u9054\u4E0D\u53EF\u80FD\u306A\u3089\u3000-1\u3000\u3092\u51FA\u529B\u3059\
    \u308B\u3053\u3068\u304C\u901A\u4F8B\uFF0E)\n    for (T &costs : distance)if(costs\
    \ == INF) costs = -1;\n\n    vector<int> path;\n    for (int cur = to; cur !=\
    \ -1; cur = prev[cur]) {\n        path.push_back(cur);\n    }\n    reverse(path.begin(),\
    \ path.end()); // \u9006\u9806\u306A\u306E\u3067\u3072\u3063\u304F\u308A\u8FD4\
    \u3059\n\n    return {distance, prev, path};\n\n};\n"
  dependsOn:
  - graph/graph-template.hpp
  - template.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2024-11-05 15:14:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dijkstra.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
