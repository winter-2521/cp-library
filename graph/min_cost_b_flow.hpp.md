---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/min_cost_b_flow.test.cpp
    title: test/min_cost_b_flow.test.cpp
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
    \ 3 \"graph/min_cost_b_flow.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u6700\u5C0F\u8CBB\u7528 b-flow (\u4F9B\u7D66\u30FB\u9700\u8981\u3068\uFF0C\
    \u8FBA\u306E\u6D41\u91CF\u306E\u4E0B\u9650\u30FB\u4E0A\u9650\u30FB\u8CBB\u7528\
    )\uFF0E\u5BB9\u91CF\u30B9\u30B1\u30FC\u30EA\u30F3\u30B0\u6CD5\n//   \u5404\u9802\
    \u70B9 v: (\u51FA\u3066\u3044\u304F\u6D41\u91CF) - (\u5165\u3063\u3066\u304F\u308B\
    \u6D41\u91CF) = b[v]\uFF0C\u5404\u8FBA e: lower[e] <= f[e] <= upper[e]\uFF0C\u03A3\
    \ cost[e] f[e] \u3092\u6700\u5C0F\u5316\n// \u0394 = 2^k, ..., 1 \u306E\u9806\u306B\
    \uFF0C\u300C\u6B8B\u4F59\u5BB9\u91CF\u304C \u0394 \u4EE5\u4E0A\u306E\u8FBA\u300D\
    \u3060\u3051\u306E\u30B0\u30E9\u30D5\u3067\uFF0C\u8D85\u904E\u304C \u0394 \u4EE5\
    \u4E0A\u306E\u9802\u70B9\u304B\u3089\u4E0D\u8DB3\u304C \u0394 \u4EE5\u4E0A\u306E\
    \u9802\u70B9\u3078\n// \u0394 \u305A\u3064\u6700\u77ED\u8DEF (\u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\u4ED8\u304D Dijkstra) \u3067\u6D41\u3059\uFF0E\u5404\u6BB5\u306E\
    \u59CB\u3081\u306B\uFF0C\u6B8B\u4F59\u5BB9\u91CF \u0394 \u4EE5\u4E0A\u3067\u88AB\
    \u7D04\u8CBB\u7528\u304C\u8CA0\u306E\u8FBA\u306F\u98FD\u548C\u3055\u305B\u308B\
    \uFF0E\n// \u6700\u5F8C\u306B\u6B8B\u4F59\u30B0\u30E9\u30D5\u3067 Bellman-Ford\
    \ \u3092\u3057\u3066\u53CC\u5BFE (\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB) p \u3092\
    \u6C42\u3081\u308B (c[e] + p[s] - p[t] >= 0 \u304C\u6B8B\u4F59\u8FBA\u3067\u6210\
    \u308A\u7ACB\u3064)\n// O(m log U \xB7 (m + n) log n) (U \u306F\u5BB9\u91CF\u30FB\
    \u4F9B\u7D66\u306E\u6700\u5927\u5024)\ntemplate <class Cap = long long, class\
    \ Cost = long long>\nstruct MinCostBFlow {\n    struct Arc {\n        int to,\
    \ rev;\n        Cap cap;\n        Cost cost;\n    };\n    int n;\n    vector<vector<Arc>>\
    \ g;\n    vector<Cap> b;\n    vector<pair<int, int>> pos;  // \u8FBA e \u306E\
    \ (\u9802\u70B9, \u6DFB\u5B57)\n    vector<Cap> lower;\n    vector<Cost> pot;\n\
    \n    MinCostBFlow(int n) : n(n), g(n), b(n, 0), pot(n, 0) {}\n\n    // \u9802\
    \u70B9 v \u306E\u4F9B\u7D66\u3092 x \u5897\u3084\u3059 (\u8CA0\u306A\u3089\u9700\
    \u8981)\n    void add_supply(int v, Cap x) { b[v] += x; }\n    void add_demand(int\
    \ v, Cap x) { b[v] -= x; }\n\n    // \u8FBA u \u2192 v (\u6D41\u91CF [lo, hi]\uFF0C\
    \u8CBB\u7528 c) \u3092\u8FFD\u52A0\u3057\uFF0C\u756A\u53F7\u3092\u8FD4\u3059\n\
    \    int add_edge(int u, int v, Cap lo, Cap hi, Cost c) {\n        assert(lo <=\
    \ hi);\n        int id = pos.size();\n        pos.push_back({u, (int)g[u].size()});\n\
    \        lower.push_back(lo);\n        int ru = g[u].size(), rv = g[v].size()\
    \ + (u == v);\n        g[u].push_back({v, rv, hi - lo, c});\n        g[v].push_back({u,\
    \ ru, 0, -c});\n        // \u4E0B\u9650\u5206\u3092\u5148\u306B\u6D41\u3057\u3066\
    \u304A\u304F\n        b[u] -= lo, b[v] += lo;\n        return id;\n    }\n\n \
    \   // \u89E3\u3051\u305F\u3089 true (\u5B9F\u884C\u53EF\u80FD\u3067\u306A\u3051\
    \u308C\u3070 false)\n    bool solve() {\n        vector<Cap> ex = b;  // \u8D85\
    \u904E (\u6B63\u306A\u3089\u51FA\u3057\u305F\u3044\u91CF)\n        Cap total =\
    \ 0, mx = 1;\n        for (int v = 0; v < n; v++) total += ex[v], mx = std::max({mx,\
    \ ex[v], -ex[v]});\n        if (total != 0) return false;\n        for (int v\
    \ = 0; v < n; v++)\n            for (auto &a : g[v]) mx = std::max(mx, a.cap);\n\
    \        Cap delta = 1;\n        while (delta <= mx / 2) delta *= 2;\n       \
    \ const Cost INF = numeric_limits<Cost>::max();\n        vector<Cost> dist(n);\n\
    \        vector<int> pv(n), pe(n);\n        vector<char> done(n);\n        for\
    \ (; delta >= 1; delta /= 2) {\n            // \u6B8B\u4F59\u5BB9\u91CF delta\
    \ \u4EE5\u4E0A\u3067\u88AB\u7D04\u8CBB\u7528\u304C\u8CA0\u306E\u8FBA\u3092\u98FD\
    \u548C\u3055\u305B\u308B\n            for (int v = 0; v < n; v++) {\n        \
    \        for (auto &a : g[v]) {\n                    if (a.cap >= delta && a.cost\
    \ + pot[v] - pot[a.to] < 0) {\n                        Cap f = a.cap;\n      \
    \                  a.cap -= f, g[a.to][a.rev].cap += f;\n                    \
    \    ex[v] -= f, ex[a.to] += f;\n                    }\n                }\n  \
    \          }\n            while (true) {\n                // \u8D85\u904E >= delta\
    \ \u306E\u9802\u70B9\u304B\u3089\uFF0C\u4E0D\u8DB3 >= delta \u306E\u9802\u70B9\
    \u3078\u306E\u6700\u77ED\u8DEF (\u591A\u59CB\u70B9 Dijkstra)\n               \
    \ priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<>> pq;\n  \
    \              fill(dist.begin(), dist.end(), INF);\n                fill(done.begin(),\
    \ done.end(), 0);\n                for (int v = 0; v < n; v++)\n             \
    \       if (ex[v] >= delta) dist[v] = 0, pv[v] = -1, pq.push({0, v});\n      \
    \          if (pq.empty()) break;\n                int t = -1;\n             \
    \   Cost dt = 0;\n                while (!pq.empty()) {\n                    auto\
    \ [d, v] = pq.top();\n                    pq.pop();\n                    if (done[v])\
    \ continue;\n                    done[v] = 1;\n                    if (ex[v] <=\
    \ -delta) {\n                        t = v, dt = d;\n                        break;\n\
    \                    }\n                    for (int i = 0; i < (int)g[v].size();\
    \ i++) {\n                        auto &a = g[v][i];\n                       \
    \ if (a.cap < delta) continue;\n                        Cost nd = d + a.cost +\
    \ pot[v] - pot[a.to];\n                        if (nd < dist[a.to]) dist[a.to]\
    \ = nd, pv[a.to] = v, pe[a.to] = i, pq.push({nd, a.to});\n                   \
    \ }\n                }\n                if (t < 0) break;\n                //\
    \ \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u66F4\u65B0 (\u88AB\u7D04\u8CBB\u7528\
    \u3092\u975E\u8CA0\u306B\u4FDD\u3064)\n                for (int v = 0; v < n;\
    \ v++) pot[v] += std::min(dist[v], dt);\n                // delta \u6D41\u3059\
    \n                for (int v = t; pv[v] >= 0; v = pv[v]) {\n                 \
    \   auto &a = g[pv[v]][pe[v]];\n                    a.cap -= delta, g[v][a.rev].cap\
    \ += delta;\n                }\n                int s = t;\n                while\
    \ (pv[s] >= 0) s = pv[s];\n                ex[s] -= delta, ex[t] += delta;\n \
    \           }\n        }\n        for (int v = 0; v < n; v++)\n            if\
    \ (ex[v] != 0) return false;\n        // \u53CC\u5BFE: \u6B8B\u4F59\u30B0\u30E9\
    \u30D5\u3067 Bellman-Ford (\u5168\u9802\u70B9\u3092\u59CB\u70B9 0 \u3068\u3057\
    \u3066)\n        fill(pot.begin(), pot.end(), 0);\n        for (int iter = 0;\
    \ iter < n; iter++) {\n            bool upd = false;\n            for (int v =\
    \ 0; v < n; v++)\n                for (auto &a : g[v])\n                    if\
    \ (a.cap > 0 && pot[v] + a.cost < pot[a.to]) pot[a.to] = pot[v] + a.cost, upd\
    \ = true;\n            if (!upd) break;\n        }\n        return true;\n   \
    \ }\n\n    Cap flow(int e) const {\n        auto [v, i] = pos[e];\n        return\
    \ lower[e] + g[g[v][i].to][g[v][i].rev].cap;\n    }\n    Cost potential(int v)\
    \ const { return pot[v]; }\n\n    // \u8CBB\u7528\u306E\u5408\u8A08 (\u5927\u304D\
    \u304F\u306A\u308A\u3046\u308B\u306E\u3067 __int128)\n    __int128 cost() const\
    \ {\n        __int128 res = 0;\n        for (int e = 0; e < (int)pos.size(); e++)\
    \ {\n            auto [v, i] = pos[e];\n            res += (__int128)g[v][i].cost\
    \ * flow(e);\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u6700\u5C0F\u8CBB\u7528 b-flow (\u4F9B\u7D66\u30FB\u9700\u8981\u3068\uFF0C\
    \u8FBA\u306E\u6D41\u91CF\u306E\u4E0B\u9650\u30FB\u4E0A\u9650\u30FB\u8CBB\u7528\
    )\uFF0E\u5BB9\u91CF\u30B9\u30B1\u30FC\u30EA\u30F3\u30B0\u6CD5\n//   \u5404\u9802\
    \u70B9 v: (\u51FA\u3066\u3044\u304F\u6D41\u91CF) - (\u5165\u3063\u3066\u304F\u308B\
    \u6D41\u91CF) = b[v]\uFF0C\u5404\u8FBA e: lower[e] <= f[e] <= upper[e]\uFF0C\u03A3\
    \ cost[e] f[e] \u3092\u6700\u5C0F\u5316\n// \u0394 = 2^k, ..., 1 \u306E\u9806\u306B\
    \uFF0C\u300C\u6B8B\u4F59\u5BB9\u91CF\u304C \u0394 \u4EE5\u4E0A\u306E\u8FBA\u300D\
    \u3060\u3051\u306E\u30B0\u30E9\u30D5\u3067\uFF0C\u8D85\u904E\u304C \u0394 \u4EE5\
    \u4E0A\u306E\u9802\u70B9\u304B\u3089\u4E0D\u8DB3\u304C \u0394 \u4EE5\u4E0A\u306E\
    \u9802\u70B9\u3078\n// \u0394 \u305A\u3064\u6700\u77ED\u8DEF (\u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\u4ED8\u304D Dijkstra) \u3067\u6D41\u3059\uFF0E\u5404\u6BB5\u306E\
    \u59CB\u3081\u306B\uFF0C\u6B8B\u4F59\u5BB9\u91CF \u0394 \u4EE5\u4E0A\u3067\u88AB\
    \u7D04\u8CBB\u7528\u304C\u8CA0\u306E\u8FBA\u306F\u98FD\u548C\u3055\u305B\u308B\
    \uFF0E\n// \u6700\u5F8C\u306B\u6B8B\u4F59\u30B0\u30E9\u30D5\u3067 Bellman-Ford\
    \ \u3092\u3057\u3066\u53CC\u5BFE (\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB) p \u3092\
    \u6C42\u3081\u308B (c[e] + p[s] - p[t] >= 0 \u304C\u6B8B\u4F59\u8FBA\u3067\u6210\
    \u308A\u7ACB\u3064)\n// O(m log U \xB7 (m + n) log n) (U \u306F\u5BB9\u91CF\u30FB\
    \u4F9B\u7D66\u306E\u6700\u5927\u5024)\ntemplate <class Cap = long long, class\
    \ Cost = long long>\nstruct MinCostBFlow {\n    struct Arc {\n        int to,\
    \ rev;\n        Cap cap;\n        Cost cost;\n    };\n    int n;\n    vector<vector<Arc>>\
    \ g;\n    vector<Cap> b;\n    vector<pair<int, int>> pos;  // \u8FBA e \u306E\
    \ (\u9802\u70B9, \u6DFB\u5B57)\n    vector<Cap> lower;\n    vector<Cost> pot;\n\
    \n    MinCostBFlow(int n) : n(n), g(n), b(n, 0), pot(n, 0) {}\n\n    // \u9802\
    \u70B9 v \u306E\u4F9B\u7D66\u3092 x \u5897\u3084\u3059 (\u8CA0\u306A\u3089\u9700\
    \u8981)\n    void add_supply(int v, Cap x) { b[v] += x; }\n    void add_demand(int\
    \ v, Cap x) { b[v] -= x; }\n\n    // \u8FBA u \u2192 v (\u6D41\u91CF [lo, hi]\uFF0C\
    \u8CBB\u7528 c) \u3092\u8FFD\u52A0\u3057\uFF0C\u756A\u53F7\u3092\u8FD4\u3059\n\
    \    int add_edge(int u, int v, Cap lo, Cap hi, Cost c) {\n        assert(lo <=\
    \ hi);\n        int id = pos.size();\n        pos.push_back({u, (int)g[u].size()});\n\
    \        lower.push_back(lo);\n        int ru = g[u].size(), rv = g[v].size()\
    \ + (u == v);\n        g[u].push_back({v, rv, hi - lo, c});\n        g[v].push_back({u,\
    \ ru, 0, -c});\n        // \u4E0B\u9650\u5206\u3092\u5148\u306B\u6D41\u3057\u3066\
    \u304A\u304F\n        b[u] -= lo, b[v] += lo;\n        return id;\n    }\n\n \
    \   // \u89E3\u3051\u305F\u3089 true (\u5B9F\u884C\u53EF\u80FD\u3067\u306A\u3051\
    \u308C\u3070 false)\n    bool solve() {\n        vector<Cap> ex = b;  // \u8D85\
    \u904E (\u6B63\u306A\u3089\u51FA\u3057\u305F\u3044\u91CF)\n        Cap total =\
    \ 0, mx = 1;\n        for (int v = 0; v < n; v++) total += ex[v], mx = std::max({mx,\
    \ ex[v], -ex[v]});\n        if (total != 0) return false;\n        for (int v\
    \ = 0; v < n; v++)\n            for (auto &a : g[v]) mx = std::max(mx, a.cap);\n\
    \        Cap delta = 1;\n        while (delta <= mx / 2) delta *= 2;\n       \
    \ const Cost INF = numeric_limits<Cost>::max();\n        vector<Cost> dist(n);\n\
    \        vector<int> pv(n), pe(n);\n        vector<char> done(n);\n        for\
    \ (; delta >= 1; delta /= 2) {\n            // \u6B8B\u4F59\u5BB9\u91CF delta\
    \ \u4EE5\u4E0A\u3067\u88AB\u7D04\u8CBB\u7528\u304C\u8CA0\u306E\u8FBA\u3092\u98FD\
    \u548C\u3055\u305B\u308B\n            for (int v = 0; v < n; v++) {\n        \
    \        for (auto &a : g[v]) {\n                    if (a.cap >= delta && a.cost\
    \ + pot[v] - pot[a.to] < 0) {\n                        Cap f = a.cap;\n      \
    \                  a.cap -= f, g[a.to][a.rev].cap += f;\n                    \
    \    ex[v] -= f, ex[a.to] += f;\n                    }\n                }\n  \
    \          }\n            while (true) {\n                // \u8D85\u904E >= delta\
    \ \u306E\u9802\u70B9\u304B\u3089\uFF0C\u4E0D\u8DB3 >= delta \u306E\u9802\u70B9\
    \u3078\u306E\u6700\u77ED\u8DEF (\u591A\u59CB\u70B9 Dijkstra)\n               \
    \ priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<>> pq;\n  \
    \              fill(dist.begin(), dist.end(), INF);\n                fill(done.begin(),\
    \ done.end(), 0);\n                for (int v = 0; v < n; v++)\n             \
    \       if (ex[v] >= delta) dist[v] = 0, pv[v] = -1, pq.push({0, v});\n      \
    \          if (pq.empty()) break;\n                int t = -1;\n             \
    \   Cost dt = 0;\n                while (!pq.empty()) {\n                    auto\
    \ [d, v] = pq.top();\n                    pq.pop();\n                    if (done[v])\
    \ continue;\n                    done[v] = 1;\n                    if (ex[v] <=\
    \ -delta) {\n                        t = v, dt = d;\n                        break;\n\
    \                    }\n                    for (int i = 0; i < (int)g[v].size();\
    \ i++) {\n                        auto &a = g[v][i];\n                       \
    \ if (a.cap < delta) continue;\n                        Cost nd = d + a.cost +\
    \ pot[v] - pot[a.to];\n                        if (nd < dist[a.to]) dist[a.to]\
    \ = nd, pv[a.to] = v, pe[a.to] = i, pq.push({nd, a.to});\n                   \
    \ }\n                }\n                if (t < 0) break;\n                //\
    \ \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u66F4\u65B0 (\u88AB\u7D04\u8CBB\u7528\
    \u3092\u975E\u8CA0\u306B\u4FDD\u3064)\n                for (int v = 0; v < n;\
    \ v++) pot[v] += std::min(dist[v], dt);\n                // delta \u6D41\u3059\
    \n                for (int v = t; pv[v] >= 0; v = pv[v]) {\n                 \
    \   auto &a = g[pv[v]][pe[v]];\n                    a.cap -= delta, g[v][a.rev].cap\
    \ += delta;\n                }\n                int s = t;\n                while\
    \ (pv[s] >= 0) s = pv[s];\n                ex[s] -= delta, ex[t] += delta;\n \
    \           }\n        }\n        for (int v = 0; v < n; v++)\n            if\
    \ (ex[v] != 0) return false;\n        // \u53CC\u5BFE: \u6B8B\u4F59\u30B0\u30E9\
    \u30D5\u3067 Bellman-Ford (\u5168\u9802\u70B9\u3092\u59CB\u70B9 0 \u3068\u3057\
    \u3066)\n        fill(pot.begin(), pot.end(), 0);\n        for (int iter = 0;\
    \ iter < n; iter++) {\n            bool upd = false;\n            for (int v =\
    \ 0; v < n; v++)\n                for (auto &a : g[v])\n                    if\
    \ (a.cap > 0 && pot[v] + a.cost < pot[a.to]) pot[a.to] = pot[v] + a.cost, upd\
    \ = true;\n            if (!upd) break;\n        }\n        return true;\n   \
    \ }\n\n    Cap flow(int e) const {\n        auto [v, i] = pos[e];\n        return\
    \ lower[e] + g[g[v][i].to][g[v][i].rev].cap;\n    }\n    Cost potential(int v)\
    \ const { return pot[v]; }\n\n    // \u8CBB\u7528\u306E\u5408\u8A08 (\u5927\u304D\
    \u304F\u306A\u308A\u3046\u308B\u306E\u3067 __int128)\n    __int128 cost() const\
    \ {\n        __int128 res = 0;\n        for (int e = 0; e < (int)pos.size(); e++)\
    \ {\n            auto [v, i] = pos[e];\n            res += (__int128)g[v][i].cost\
    \ * flow(e);\n        }\n        return res;\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/min_cost_b_flow.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/min_cost_b_flow.test.cpp
  - test/unittest/graph_optimization.test.cpp
documentation_of: graph/min_cost_b_flow.hpp
layout: document
title: "\u6700\u5C0F\u8CBB\u7528 b-flow (Min Cost b-Flow)"
---

## 概要

各頂点 $v$ の供給 $b_v$（負なら需要）、各辺 $e$ の流量の下限 $l_e$・上限 $u_e$・費用 $c_e$ が与えられたとき、

- 流量保存：$(\text{$v$ から出る流量}) - (\text{$v$ に入る流量}) = b_v$
- 容量制約：$l_e \le f_e \le u_e$

を満たす流し方 $f$ のうち $\sum c_e f_e$ が最小のものを求める。双対（ポテンシャル）も返す。**容量スケーリング法**で $O(m \log U \cdot (n + m) \log n)$（$U$ は容量・供給の最大値）、最後の双対の計算（Bellman-Ford）に $O(nm)$。

1. 下限 $l_e$ 分を先に流したことにして、供給を調整する。
2. $\Delta = 2^k, \dots, 1$ の順に、残余容量が $\Delta$ 以上の辺だけを見る。その段の始めに被約費用が負の辺は飽和させ、超過が $\Delta$ 以上の頂点から不足が $\Delta$ 以上の頂点へ、ポテンシャル付き Dijkstra の最短路で $\Delta$ ずつ流す。
3. 最後に残余グラフで Bellman-Ford をしてポテンシャル $p$（全ての残余辺で $c_e + p_{\mathrm{from}} - p_{\mathrm{to}} \ge 0$）を求める。

## 使い方

```cpp
MinCostBFlow<long long, long long> g(n);   // <容量の型, 費用の型>
g.add_supply(v, x);                        // 供給 (add_demand で需要)
int e = g.add_edge(s, t, lo, hi, cost);    // 辺番号
if (!g.solve()) { /* 実行不可能 */ }
__int128 c = g.cost();
g.flow(e);                                 // 辺 e の流量
g.potential(v);                            // 双対変数
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `MinCostBFlow(int n)` | 頂点数 $n$ | $O(n)$ |
| `void add_supply(int v, Cap x)` / `add_demand` | 供給・需要を足す | $O(1)$ |
| `int add_edge(int u, int v, Cap lo, Cap hi, Cost c)` | 辺を追加して番号を返す | $O(1)$ |
| `bool solve()` | 解く．実行不可能なら `false` | $O(m \log U (n + m) \log n + nm)$ |
| `__int128 cost()` | 最小費用 | $O(m)$ |
| `Cap flow(int e)` | 辺 $e$ の流量 | $O(1)$ |
| `Cost potential(int v)` | ポテンシャル | $O(1)$ |

## 注意

- 費用が負の辺・負閉路があってもよい（容量が有限なので最小値は存在する）。
- 費用の合計は `long long` を超えうるので `__int128` で返す。
- 普通の「$s$ から $t$ へ $F$ 流す最小費用流」は `add_supply(s, F)`, `add_demand(t, F)` とすればよい。
