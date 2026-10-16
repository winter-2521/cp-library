---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/bipartite_matching.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0 (Bipartite Matching)"
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bipartite_edge_coloring.test.cpp
    title: test/bipartite_edge_coloring.test.cpp
  - icon: ':x:'
    path: test/unittest/graph_optimization.test.cpp
    title: test/unittest/graph_optimization.test.cpp
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
    \ 3 \"graph/bipartite_matching.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\
    \uFF0EO(m \u221An)\n// 1. \u521D\u671F\u30DE\u30C3\u30C1\u30F3\u30B0\u306F Karp-Sipser\
    \ \u306E\u8CAA\u6B32 (\u6B21\u6570 1 \u306E\u9802\u70B9\u304B\u3089\u7D44\u3080\
    ) \u3067\u4F5C\u308B\n// 2. \u5DE6\u306E\u672A\u30DE\u30C3\u30C1\u9802\u70B9\u5168\
    \u90E8\u304B\u3089\u540C\u6642\u306B BFS \u3057\uFF0C\u5404\u9802\u70B9\u306B\u300C\
    \u3069\u306E\u59CB\u70B9\u304B\u3089\u6765\u305F\u304B (root)\u300D\u3092\u4ED8\
    \u3051\u308B\uFF0E\n//    \u672A\u30DE\u30C3\u30C1\u306E\u53F3\u9802\u70B9\u306B\
    \u7740\u3044\u305F\u3089\u305D\u306E\u5834\u3067\u5897\u52A0\u3057\uFF0C\u540C\
    \u3058 root \u306E\u63A2\u7D22\u306F\u6253\u3061\u5207\u308B\uFF0E1 \u56DE O(m)\
    \ \u3067\u591A\u6570\u306E\u5897\u52A0\u8DEF\u304C\u53D6\u308C\uFF0C\u5B9F\u7528\
    \u4E0A\u3068\u3066\u3082\u901F\u3044\n// 3. 2 \u3092 \u221An \u56DE\u3084\u3063\
    \u3066\u3082\u7D42\u308F\u3089\u306A\u3051\u308C\u3070 Hopcroft-Karp (\u5C64\u306B\
    \u6CBF\u3063\u305F DFS \u3067\u6700\u77ED\u5897\u52A0\u8DEF\u3092\u307E\u3068\u3081\
    \u3066\u53D6\u308B) \u306B\u5207\u308A\u66FF\u3048\u3066 O(m \u221An) \u3092\u4FDD\
    \u8A3C\u3059\u308B\nstruct BipartiteMatching {\n    int L, R;\n    vector<pair<int,\
    \ int>> edges;\n    vector<int> match_l, match_r;  // \u76F8\u624B (\u3044\u306A\
    \u3051\u308C\u3070 -1)\n\n    BipartiteMatching(int L, int R) : L(L), R(R) {}\n\
    \    void reserve(int m) { edges.reserve(m); }\n    // \u5DE6 a \u3068\u53F3 b\
    \ \u306E\u9593\u306B\u8FBA\n    void add_edge(int a, int b) { edges.push_back({a,\
    \ b}); }\n\n    // \u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\u306E\u5927\u304D\
    \u3055\u3092\u8FD4\u3059\n    int solve() {\n        vector<int> start(L + 1,\
    \ 0), adj(edges.size());\n        for (auto &[a, b] : edges) start[a + 1]++;\n\
    \        for (int i = 0; i < L; i++) start[i + 1] += start[i];\n        {\n  \
    \          vector<int> pos(start.begin(), start.end() - 1);\n            for (auto\
    \ &[a, b] : edges) adj[pos[a]++] = b;\n        }\n        match_l.assign(L, -1),\
    \ match_r.assign(R, -1);\n        // \u521D\u671F\u30DE\u30C3\u30C1\u30F3\u30B0\
    \ (Karp-Sipser): \u6B8B\u308A\u306E\u6B21\u6570\u304C 1 \u306E\u9802\u70B9\u306F\
    \uFF0C\u305D\u306E\u552F\u4E00\u306E\u76F8\u624B\u3068\u7D44\u307E\u305B\u3066\
    \u3082\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\u3092\u640D\u306A\u308F\u306A\
    \u3044\uFF0E\n        // \u305D\u3046\u3044\u3046\u9802\u70B9\u304C\u3042\u308C\
    \u3070\u5148\u306B\u7D44\u307F\uFF0C\u306A\u3051\u308C\u3070\u9069\u5F53\u306A\
    \u9802\u70B9\u3092\u7D44\u3080\uFF0E\u5F8C\u306E\u5897\u52A0\u8DEF\u306E\u63A2\
    \u7D22\u304C\u305A\u3063\u3068\u6E1B\u308B\n        int res = 0;\n        {\n\
    \            vector<int> rstart(R + 1, 0), radj(edges.size());\n            for\
    \ (auto &[a, b] : edges) rstart[b + 1]++;\n            for (int i = 0; i < R;\
    \ i++) rstart[i + 1] += rstart[i];\n            {\n                vector<int>\
    \ pos(rstart.begin(), rstart.end() - 1);\n                for (auto &[a, b] :\
    \ edges) radj[pos[b]++] = a;\n            }\n            // \u9802\u70B9\u756A\
    \u53F7: \u5DE6 0..L-1\uFF0C\u53F3 L..L+R-1\n            vector<int> deg(L + R);\n\
    \            for (int a = 0; a < L; a++) deg[a] = start[a + 1] - start[a];\n \
    \           for (int b = 0; b < R; b++) deg[L + b] = rstart[b + 1] - rstart[b];\n\
    \            vector<char> dead(L + R, 0);\n            vector<int> ones;\n   \
    \         for (int x = 0; x < L + R; x++)\n                if (deg[x] == 1) ones.push_back(x);\n\
    \            auto remove = [&](int x) {  // x \u3092\u53D6\u308A\u9664\u304D\uFF0C\
    \u96A3\u306E\u6B21\u6570\u3092\u4E0B\u3052\u308B\n                dead[x] = 1;\n\
    \                if (x < L) {\n                    for (int i = start[x]; i <\
    \ start[x + 1]; i++) {\n                        int y = L + adj[i];\n        \
    \                if (!dead[y] && --deg[y] == 1) ones.push_back(y);\n         \
    \           }\n                } else {\n                    int b = x - L;\n\
    \                    for (int i = rstart[b]; i < rstart[b + 1]; i++) {\n     \
    \                   int y = radj[i];\n                        if (!dead[y] &&\
    \ --deg[y] == 1) ones.push_back(y);\n                    }\n                }\n\
    \            };\n            auto partner = [&](int x) {  // \u751F\u304D\u3066\
    \u3044\u308B\u96A3\u3092 1 \u3064\n                if (x < L) {\n            \
    \        for (int i = start[x]; i < start[x + 1]; i++)\n                     \
    \   if (!dead[L + adj[i]]) return L + adj[i];\n                } else {\n    \
    \                int b = x - L;\n                    for (int i = rstart[b]; i\
    \ < rstart[b + 1]; i++)\n                        if (!dead[radj[i]]) return radj[i];\n\
    \                }\n                return -1;\n            };\n            auto\
    \ pair_up = [&](int x, int y) {\n                int a = x < L ? x : y, b = (x\
    \ < L ? y : x) - L;\n                match_l[a] = b, match_r[b] = a, res++;\n\
    \                remove(x), remove(y);\n            };\n            int scan =\
    \ 0;\n            while (true) {\n                if (!ones.empty()) {\n     \
    \               int x = ones.back();\n                    ones.pop_back();\n \
    \                   if (dead[x] || deg[x] != 1) continue;\n                  \
    \  int y = partner(x);\n                    if (y >= 0) pair_up(x, y);\n     \
    \               continue;\n                }\n                while (scan < L\
    \ && (dead[scan] || deg[scan] == 0)) scan++;\n                if (scan == L) break;\n\
    \                int y = partner(scan);\n                if (y < 0) {\n      \
    \              dead[scan] = 1;\n                    continue;\n              \
    \  }\n                pair_up(scan, y);\n            }\n        }\n        vector<int>\
    \ que(L);\n        {\n            vector<int> root(L, -1), prev(L);\n        \
    \    int rounds = 0, lim_rounds = (int)sqrt((double)(L + R)) + 1;\n          \
    \  while (rounds++ < lim_rounds) {\n                int qt = 0;\n            \
    \    for (int a = 0; a < L; a++)\n                    if (match_l[a] < 0) root[a]\
    \ = a, prev[a] = -1, que[qt++] = a;\n                bool updated = false;\n \
    \               for (int qh = 0; qh < qt; qh++) {\n                    int a =\
    \ que[qh];\n                    if (match_l[root[a]] >= 0) continue;  // \u3053\
    \u306E\u59CB\u70B9\u306F\u3082\u3046\u5897\u52A0\u3057\u305F\n               \
    \     for (int i = start[a]; i < start[a + 1]; i++) {\n                      \
    \  int b = adj[i], c = match_r[b];\n                        if (c < 0) {\n   \
    \                         // prev \u3092\u9061\u308A\u306A\u304C\u3089\u53CD\u8EE2\
    : a-b \u3092\u7D44\u307F\uFF0Ca \u306E\u5143\u306E\u76F8\u624B\u3092 prev[a] \u306B\
    \u6E21\u3059\n                            while (b >= 0) {\n                 \
    \               int t = match_l[a];\n                                match_l[a]\
    \ = b, match_r[b] = a;\n                                b = t, a = prev[a];\n\
    \                            }\n                            res++, updated = true;\n\
    \                            break;\n                        }\n             \
    \           if (root[c] < 0) root[c] = root[a], prev[c] = a, que[qt++] = c;\n\
    \                    }\n                }\n                for (int k = 0; k <\
    \ qt; k++) root[que[k]] = -1;\n                if (!updated) return res;\n   \
    \         }\n        }\n        vector<int> dist(L), it(L), stk;\n        while\
    \ (true) {\n            // BFS: \u5DE6\u306E\u672A\u30DE\u30C3\u30C1\u9802\u70B9\
    \u3092\u8DDD\u96E2 0 \u3068\u3057\u3066\u5C64\u3092\u4F5C\u308B\n            int\
    \ qh = 0, qt = 0;\n            for (int a = 0; a < L; a++) {\n               \
    \ if (match_l[a] < 0) dist[a] = 0, que[qt++] = a;\n                else dist[a]\
    \ = -1;\n            }\n            // \u672A\u30DE\u30C3\u30C1\u306E\u53F3\u9802\
    \u70B9\u306B\u6700\u521D\u306B\u5C4A\u3044\u305F\u5C64 lim \u3088\u308A\u6DF1\u304F\
    \u306F\u5E83\u3052\u306A\u3044 (\u6700\u77ED\u306E\u5897\u52A0\u8DEF\u3060\u3051\
    \u3092\u4F7F\u3046)\n            int lim = -1;\n            while (qh < qt) {\n\
    \                int a = que[qh++];\n                if (lim >= 0 && dist[a] >=\
    \ lim) break;\n                for (int i = start[a]; i < start[a + 1]; i++) {\n\
    \                    int c = match_r[adj[i]];\n                    if (c < 0)\
    \ {\n                        if (lim < 0) lim = dist[a];\n                   \
    \ } else if (dist[c] < 0) {\n                        dist[c] = dist[a] + 1, que[qt++]\
    \ = c;\n                    }\n                }\n            }\n            if\
    \ (lim < 0) break;\n            // DFS (\u975E\u518D\u5E30): \u5C64\u3092 1 \u3064\
    \u305A\u3064\u4E0B\u308A\u308B\u5897\u52A0\u8DEF\n            for (int a = 0;\
    \ a < L; a++) it[a] = start[a];\n            for (int s = 0; s < L; s++) {\n \
    \               if (match_l[s] >= 0) continue;\n                stk.clear(), stk.push_back(s);\n\
    \                while (!stk.empty()) {\n                    int a = stk.back();\n\
    \                    bool advanced = false;\n                    while (it[a]\
    \ < start[a + 1]) {\n                        int b = adj[it[a]], c = match_r[b];\n\
    \                        if (c < 0 && dist[a] == lim) {\n                    \
    \        // \u5897\u52A0\u8DEF\u304C\u898B\u3064\u304B\u3063\u305F: \u30B9\u30BF\
    \u30C3\u30AF\u306B\u6CBF\u3063\u3066\u53CD\u8EE2\n                           \
    \ for (int k = (int)stk.size() - 1; k >= 0; k--) {\n                         \
    \       int x = stk[k], y = adj[it[x]];\n                                match_l[x]\
    \ = y, match_r[y] = x;\n                            }\n                      \
    \      res++;\n                            stk.clear();\n                    \
    \        advanced = true;\n                            break;\n              \
    \          }\n                        if (c >= 0 && dist[c] == dist[a] + 1 &&\
    \ dist[a] < lim) {\n                            stk.push_back(c);\n          \
    \                  advanced = true;\n                            break;\n    \
    \                    }\n                        it[a]++;\n                   \
    \ }\n                    if (!advanced) {\n                        dist[a] = -1;\
    \  // \u884C\u304D\u6B62\u307E\u308A\n                        stk.pop_back();\n\
    \                        if (!stk.empty()) it[stk.back()]++;\n               \
    \     }\n                }\n            }\n        }\n        return res;\n  \
    \  }\n\n    // \u30DE\u30C3\u30C1\u30F3\u30B0\u306E\u8FBA (\u5DE6, \u53F3) \u306E\
    \u5217\n    vector<pair<int, int>> matching() const {\n        vector<pair<int,\
    \ int>> res;\n        for (int a = 0; a < L; a++)\n            if (match_l[a]\
    \ >= 0) res.push_back({a, match_l[a]});\n        return res;\n    }\n};\n#line\
    \ 4 \"graph/bipartite_edge_coloring.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u8FBA\u5F69\u8272 (\u6700\u5927\u6B21\
    \u6570 \u0394 \u8272\u3067\uFF0C\u540C\u3058\u9802\u70B9\u306B\u63A5\u3059\u308B\
    \u8FBA\u306E\u8272\u304C\u5168\u3066\u7570\u306A\u308B\u3088\u3046\u306B\u5857\
    \u308B\uFF0EK\u0151nig \u306E\u5B9A\u7406\u3088\u308A \u0394 \u8272\u3067\u8DB3\
    \u308A\u308B)\n// 1. \u9802\u70B9\u3092\u307E\u3068\u3081\u3066 (\u6B21\u6570\u306E\
    \u548C\u304C \u0394 \u4EE5\u4E0B\u306B\u306A\u308B\u3088\u3046\u306B) \u4E21\u5074\
    \ k \u9802\u70B9\u305A\u3064\u306B\u3057\uFF0C\u30C0\u30DF\u30FC\u8FBA\u3092\u8DB3\
    \u3057\u3066 \u0394-\u6B63\u5247\u306A\u4E8C\u90E8\u591A\u91CD\u30B0\u30E9\u30D5\
    \u306B\u3059\u308B\n// 2. \u0394 \u304C\u5947\u6570\u306A\u3089\u5B8C\u5168\u30DE\
    \u30C3\u30C1\u30F3\u30B0 (\u6B63\u5247\u4E8C\u90E8\u30B0\u30E9\u30D5\u306B\u306F\
    \u5FC5\u305A\u3042\u308B) \u3092 1 \u8272\u3067\u5857\u3063\u3066\u53D6\u308A\u9664\
    \u304F\n//    \u0394 \u304C\u5076\u6570\u306A\u3089\u30AA\u30A4\u30E9\u30FC\u9589\
    \u8DEF\u306B\u6CBF\u3063\u3066\u8FBA\u3092\u4EA4\u4E92\u306B 2 \u3064\u306B\u5206\
    \u3051 (\u5404\u9802\u70B9\u3067\u534A\u5206\u305A\u3064\u306B\u306A\u308B)\uFF0C\
    \u305D\u308C\u305E\u308C\u3092\u518D\u5E30\u7684\u306B\u5857\u308B\n// O(m \u221A\
    n log \u0394)\n// \u8FD4\u308A\u5024: {\u8272\u6570 \u0394, \u5404\u8FBA\u306E\
    \u8272 (0 .. \u0394-1)}\ninline pair<int, vector<int>> bipartite_edge_coloring(int\
    \ L, int R, const vector<pair<int, int>> &edges) {\n    int m = edges.size();\n\
    \    if (m == 0) return {0, {}};\n    vector<int> degl(L, 0), degr(R, 0);\n  \
    \  for (auto [a, b] : edges) degl[a]++, degr[b]++;\n    int D = std::max(*max_element(degl.begin(),\
    \ degl.end()), *max_element(degr.begin(), degr.end()));\n    // 1. \u9802\u70B9\
    \u3092\u307E\u3068\u3081\u308B (\u9806\u306B\u8A70\u3081\u308B)\n    auto pack\
    \ = [&](const vector<int> &deg, vector<int> &grp) {\n        int k = 0, cur =\
    \ 0;\n        grp.assign(deg.size(), 0);\n        for (size_t v = 0; v < deg.size();\
    \ v++) {\n            if (cur + deg[v] > D) k++, cur = 0;\n            grp[v]\
    \ = k, cur += deg[v];\n        }\n        return k + 1;\n    };\n    vector<int>\
    \ gl, gr;\n    int kl = pack(degl, gl), kr = pack(degr, gr), k = std::max(kl,\
    \ kr);\n    vector<int> el(k, 0), er(k, 0);  // \u307E\u3068\u3081\u305F\u9802\
    \u70B9\u306E\u6B21\u6570\n    vector<pair<int, int>> E;        // \u307E\u3068\
    \u3081\u305F\u30B0\u30E9\u30D5\u306E\u8FBA (\u5DE6 0..k-1\uFF0C\u53F3 0..k-1)\n\
    \    E.reserve((size_t)k * D);\n    for (auto [a, b] : edges) E.push_back({gl[a],\
    \ gr[b]}), el[gl[a]]++, er[gr[b]]++;\n    // \u30C0\u30DF\u30FC\u8FBA\u3067 \u0394\
    -\u6B63\u5247\u306B\u3059\u308B (\u4E0D\u8DB3\u3057\u3066\u3044\u308B\u5DE6\u3068\
    \u53F3\u3092\u9806\u306B\u7D50\u3076)\n    for (int x = 0, y = 0; x < k; x++)\
    \ {\n        while (el[x] < D) {\n            while (er[y] == D) y++;\n      \
    \      int f = std::min(D - el[x], D - er[y]);\n            for (int t = 0; t\
    \ < f; t++) E.push_back({x, y});\n            el[x] += f, er[y] += f;\n      \
    \  }\n    }\n    int M = E.size();\n    vector<int> color(M, -1);\n    // 2. \u518D\
    \u5E30 (\u660E\u793A\u7684\u306A\u30B9\u30BF\u30C3\u30AF\u3067): (\u8FBA\u306E\
    \u96C6\u5408, \u6B21\u6570, \u4F7F\u3046\u8272\u306E\u5148\u982D)\n    struct\
    \ Task {\n        vector<int> es;\n        int deg, base;\n    };\n    vector<Task>\
    \ stk;\n    {\n        vector<int> all(M);\n        iota(all.begin(), all.end(),\
    \ 0);\n        stk.push_back({all, D, 0});\n    }\n    vector<int> head(2 * k),\
    \ nxt, used_mark;\n    while (!stk.empty()) {\n        Task t = std::move(stk.back());\n\
    \        stk.pop_back();\n        if (t.deg == 0) continue;\n        if (t.deg\
    \ == 1) {\n            for (int e : t.es) color[e] = t.base;\n            continue;\n\
    \        }\n        if (t.deg & 1) {\n            // \u5B8C\u5168\u30DE\u30C3\u30C1\
    \u30F3\u30B0\u3092 1 \u8272\u3067\u5857\u308B\n            BipartiteMatching bm(k,\
    \ k);\n            bm.reserve(t.es.size());\n            for (int e : t.es) bm.add_edge(E[e].first,\
    \ E[e].second);\n            int got = bm.solve();\n            assert(got ==\
    \ k);\n            // \u30DE\u30C3\u30C1\u3057\u305F\u7D44 (\u5DE6, \u53F3) \u3054\
    \u3068\u306B\u8FBA\u3092 1 \u672C\u9078\u3076\n            vector<char> taken(k,\
    \ 0);\n            vector<int> rest;\n            rest.reserve(t.es.size() - k);\n\
    \            for (int e : t.es) {\n                int a = E[e].first;\n     \
    \           if (!taken[a] && bm.match_l[a] == E[e].second) taken[a] = 1, color[e]\
    \ = t.base + t.deg - 1;\n                else rest.push_back(e);\n           \
    \ }\n            stk.push_back({std::move(rest), t.deg - 1, t.base});\n      \
    \      continue;\n        }\n        // \u30AA\u30A4\u30E9\u30FC\u5206\u5272:\
    \ \u9802\u70B9 (\u5DE6 x \u2192 x\uFF0C\u53F3 y \u2192 k + y) \u3054\u3068\u306B\
    \u8FBA\u306E\u30EA\u30B9\u30C8\n        int sz = t.es.size();\n        fill(head.begin(),\
    \ head.end(), -1);\n        nxt.assign(2 * sz, -1);\n        used_mark.assign(sz,\
    \ 0);\n        // \u534A\u8FBA 2i \u306F\u5DE6\u304B\u3089\uFF0C2i+1 \u306F\u53F3\
    \u304B\u3089\n        for (int i = 0; i < sz; i++) {\n            auto [a, b]\
    \ = E[t.es[i]];\n            nxt[2 * i] = head[a], head[a] = 2 * i;\n        \
    \    nxt[2 * i + 1] = head[k + b], head[k + b] = 2 * i + 1;\n        }\n     \
    \   vector<int> A, B;\n        A.reserve(sz / 2), B.reserve(sz / 2);\n       \
    \ // \u5404\u9023\u7D50\u6210\u5206\u3067\u30AA\u30A4\u30E9\u30FC\u9589\u8DEF\u3092\
    \u4F5C\u308A\uFF0C\u9589\u8DEF\u306E\u9806\u306B\u4EA4\u4E92\u306B\u5206\u3051\
    \u308B (Hierholzer\uFF0C\u975E\u518D\u5E30)\n        vector<pair<int, int>> st;\
    \  // (\u9802\u70B9, \u6765\u305F\u8FBA)\n        vector<int> circuit;\n     \
    \   for (int s = 0; s < 2 * k; s++) {\n            if (head[s] < 0) continue;\n\
    \            circuit.clear();\n            st.clear(), st.push_back({s, -1});\n\
    \            while (!st.empty()) {\n                int v = st.back().first;\n\
    \                while (head[v] >= 0 && used_mark[head[v] >> 1]) head[v] = nxt[head[v]];\n\
    \                if (head[v] < 0) {\n                    if (st.back().second\
    \ >= 0) circuit.push_back(st.back().second);\n                    st.pop_back();\n\
    \                    continue;\n                }\n                int h = head[v],\
    \ i = h >> 1;\n                used_mark[i] = 1;\n                head[v] = nxt[h];\n\
    \                auto [a, b] = E[t.es[i]];\n                int to = (h & 1) ?\
    \ a : k + b;\n                st.push_back({to, i});\n            }\n        \
    \    for (size_t j = 0; j < circuit.size(); j++) (j & 1 ? B : A).push_back(t.es[circuit[j]]);\n\
    \        }\n        stk.push_back({std::move(A), t.deg / 2, t.base});\n      \
    \  stk.push_back({std::move(B), t.deg / 2, t.base + t.deg / 2});\n    }\n    vector<int>\
    \ res(color.begin(), color.begin() + m);\n    return {D, res};\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"bipartite_matching.hpp\"\
    \n\n// https://github.com/winter-2521/cp-library\n\n// \u4E8C\u90E8\u30B0\u30E9\
    \u30D5\u306E\u8FBA\u5F69\u8272 (\u6700\u5927\u6B21\u6570 \u0394 \u8272\u3067\uFF0C\
    \u540C\u3058\u9802\u70B9\u306B\u63A5\u3059\u308B\u8FBA\u306E\u8272\u304C\u5168\
    \u3066\u7570\u306A\u308B\u3088\u3046\u306B\u5857\u308B\uFF0EK\u0151nig \u306E\u5B9A\
    \u7406\u3088\u308A \u0394 \u8272\u3067\u8DB3\u308A\u308B)\n// 1. \u9802\u70B9\u3092\
    \u307E\u3068\u3081\u3066 (\u6B21\u6570\u306E\u548C\u304C \u0394 \u4EE5\u4E0B\u306B\
    \u306A\u308B\u3088\u3046\u306B) \u4E21\u5074 k \u9802\u70B9\u305A\u3064\u306B\u3057\
    \uFF0C\u30C0\u30DF\u30FC\u8FBA\u3092\u8DB3\u3057\u3066 \u0394-\u6B63\u5247\u306A\
    \u4E8C\u90E8\u591A\u91CD\u30B0\u30E9\u30D5\u306B\u3059\u308B\n// 2. \u0394 \u304C\
    \u5947\u6570\u306A\u3089\u5B8C\u5168\u30DE\u30C3\u30C1\u30F3\u30B0 (\u6B63\u5247\
    \u4E8C\u90E8\u30B0\u30E9\u30D5\u306B\u306F\u5FC5\u305A\u3042\u308B) \u3092 1 \u8272\
    \u3067\u5857\u3063\u3066\u53D6\u308A\u9664\u304F\n//    \u0394 \u304C\u5076\u6570\
    \u306A\u3089\u30AA\u30A4\u30E9\u30FC\u9589\u8DEF\u306B\u6CBF\u3063\u3066\u8FBA\
    \u3092\u4EA4\u4E92\u306B 2 \u3064\u306B\u5206\u3051 (\u5404\u9802\u70B9\u3067\u534A\
    \u5206\u305A\u3064\u306B\u306A\u308B)\uFF0C\u305D\u308C\u305E\u308C\u3092\u518D\
    \u5E30\u7684\u306B\u5857\u308B\n// O(m \u221An log \u0394)\n// \u8FD4\u308A\u5024\
    : {\u8272\u6570 \u0394, \u5404\u8FBA\u306E\u8272 (0 .. \u0394-1)}\ninline pair<int,\
    \ vector<int>> bipartite_edge_coloring(int L, int R, const vector<pair<int, int>>\
    \ &edges) {\n    int m = edges.size();\n    if (m == 0) return {0, {}};\n    vector<int>\
    \ degl(L, 0), degr(R, 0);\n    for (auto [a, b] : edges) degl[a]++, degr[b]++;\n\
    \    int D = std::max(*max_element(degl.begin(), degl.end()), *max_element(degr.begin(),\
    \ degr.end()));\n    // 1. \u9802\u70B9\u3092\u307E\u3068\u3081\u308B (\u9806\u306B\
    \u8A70\u3081\u308B)\n    auto pack = [&](const vector<int> &deg, vector<int> &grp)\
    \ {\n        int k = 0, cur = 0;\n        grp.assign(deg.size(), 0);\n       \
    \ for (size_t v = 0; v < deg.size(); v++) {\n            if (cur + deg[v] > D)\
    \ k++, cur = 0;\n            grp[v] = k, cur += deg[v];\n        }\n        return\
    \ k + 1;\n    };\n    vector<int> gl, gr;\n    int kl = pack(degl, gl), kr = pack(degr,\
    \ gr), k = std::max(kl, kr);\n    vector<int> el(k, 0), er(k, 0);  // \u307E\u3068\
    \u3081\u305F\u9802\u70B9\u306E\u6B21\u6570\n    vector<pair<int, int>> E;    \
    \    // \u307E\u3068\u3081\u305F\u30B0\u30E9\u30D5\u306E\u8FBA (\u5DE6 0..k-1\uFF0C\
    \u53F3 0..k-1)\n    E.reserve((size_t)k * D);\n    for (auto [a, b] : edges) E.push_back({gl[a],\
    \ gr[b]}), el[gl[a]]++, er[gr[b]]++;\n    // \u30C0\u30DF\u30FC\u8FBA\u3067 \u0394\
    -\u6B63\u5247\u306B\u3059\u308B (\u4E0D\u8DB3\u3057\u3066\u3044\u308B\u5DE6\u3068\
    \u53F3\u3092\u9806\u306B\u7D50\u3076)\n    for (int x = 0, y = 0; x < k; x++)\
    \ {\n        while (el[x] < D) {\n            while (er[y] == D) y++;\n      \
    \      int f = std::min(D - el[x], D - er[y]);\n            for (int t = 0; t\
    \ < f; t++) E.push_back({x, y});\n            el[x] += f, er[y] += f;\n      \
    \  }\n    }\n    int M = E.size();\n    vector<int> color(M, -1);\n    // 2. \u518D\
    \u5E30 (\u660E\u793A\u7684\u306A\u30B9\u30BF\u30C3\u30AF\u3067): (\u8FBA\u306E\
    \u96C6\u5408, \u6B21\u6570, \u4F7F\u3046\u8272\u306E\u5148\u982D)\n    struct\
    \ Task {\n        vector<int> es;\n        int deg, base;\n    };\n    vector<Task>\
    \ stk;\n    {\n        vector<int> all(M);\n        iota(all.begin(), all.end(),\
    \ 0);\n        stk.push_back({all, D, 0});\n    }\n    vector<int> head(2 * k),\
    \ nxt, used_mark;\n    while (!stk.empty()) {\n        Task t = std::move(stk.back());\n\
    \        stk.pop_back();\n        if (t.deg == 0) continue;\n        if (t.deg\
    \ == 1) {\n            for (int e : t.es) color[e] = t.base;\n            continue;\n\
    \        }\n        if (t.deg & 1) {\n            // \u5B8C\u5168\u30DE\u30C3\u30C1\
    \u30F3\u30B0\u3092 1 \u8272\u3067\u5857\u308B\n            BipartiteMatching bm(k,\
    \ k);\n            bm.reserve(t.es.size());\n            for (int e : t.es) bm.add_edge(E[e].first,\
    \ E[e].second);\n            int got = bm.solve();\n            assert(got ==\
    \ k);\n            // \u30DE\u30C3\u30C1\u3057\u305F\u7D44 (\u5DE6, \u53F3) \u3054\
    \u3068\u306B\u8FBA\u3092 1 \u672C\u9078\u3076\n            vector<char> taken(k,\
    \ 0);\n            vector<int> rest;\n            rest.reserve(t.es.size() - k);\n\
    \            for (int e : t.es) {\n                int a = E[e].first;\n     \
    \           if (!taken[a] && bm.match_l[a] == E[e].second) taken[a] = 1, color[e]\
    \ = t.base + t.deg - 1;\n                else rest.push_back(e);\n           \
    \ }\n            stk.push_back({std::move(rest), t.deg - 1, t.base});\n      \
    \      continue;\n        }\n        // \u30AA\u30A4\u30E9\u30FC\u5206\u5272:\
    \ \u9802\u70B9 (\u5DE6 x \u2192 x\uFF0C\u53F3 y \u2192 k + y) \u3054\u3068\u306B\
    \u8FBA\u306E\u30EA\u30B9\u30C8\n        int sz = t.es.size();\n        fill(head.begin(),\
    \ head.end(), -1);\n        nxt.assign(2 * sz, -1);\n        used_mark.assign(sz,\
    \ 0);\n        // \u534A\u8FBA 2i \u306F\u5DE6\u304B\u3089\uFF0C2i+1 \u306F\u53F3\
    \u304B\u3089\n        for (int i = 0; i < sz; i++) {\n            auto [a, b]\
    \ = E[t.es[i]];\n            nxt[2 * i] = head[a], head[a] = 2 * i;\n        \
    \    nxt[2 * i + 1] = head[k + b], head[k + b] = 2 * i + 1;\n        }\n     \
    \   vector<int> A, B;\n        A.reserve(sz / 2), B.reserve(sz / 2);\n       \
    \ // \u5404\u9023\u7D50\u6210\u5206\u3067\u30AA\u30A4\u30E9\u30FC\u9589\u8DEF\u3092\
    \u4F5C\u308A\uFF0C\u9589\u8DEF\u306E\u9806\u306B\u4EA4\u4E92\u306B\u5206\u3051\
    \u308B (Hierholzer\uFF0C\u975E\u518D\u5E30)\n        vector<pair<int, int>> st;\
    \  // (\u9802\u70B9, \u6765\u305F\u8FBA)\n        vector<int> circuit;\n     \
    \   for (int s = 0; s < 2 * k; s++) {\n            if (head[s] < 0) continue;\n\
    \            circuit.clear();\n            st.clear(), st.push_back({s, -1});\n\
    \            while (!st.empty()) {\n                int v = st.back().first;\n\
    \                while (head[v] >= 0 && used_mark[head[v] >> 1]) head[v] = nxt[head[v]];\n\
    \                if (head[v] < 0) {\n                    if (st.back().second\
    \ >= 0) circuit.push_back(st.back().second);\n                    st.pop_back();\n\
    \                    continue;\n                }\n                int h = head[v],\
    \ i = h >> 1;\n                used_mark[i] = 1;\n                head[v] = nxt[h];\n\
    \                auto [a, b] = E[t.es[i]];\n                int to = (h & 1) ?\
    \ a : k + b;\n                st.push_back({to, i});\n            }\n        \
    \    for (size_t j = 0; j < circuit.size(); j++) (j & 1 ? B : A).push_back(t.es[circuit[j]]);\n\
    \        }\n        stk.push_back({std::move(A), t.deg / 2, t.base});\n      \
    \  stk.push_back({std::move(B), t.deg / 2, t.base + t.deg / 2});\n    }\n    vector<int>\
    \ res(color.begin(), color.begin() + m);\n    return {D, res};\n}\n"
  dependsOn:
  - template.hpp
  - graph/bipartite_matching.hpp
  isVerificationFile: false
  path: graph/bipartite_edge_coloring.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/unittest/graph_optimization.test.cpp
  - test/bipartite_edge_coloring.test.cpp
documentation_of: graph/bipartite_edge_coloring.hpp
layout: document
title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u8FBA\u5F69\u8272 (Bipartite Edge Coloring)"
---

## 概要

二部グラフの辺を、同じ頂点に接する辺が全て異なる色になるように、最大次数 $\Delta$ 色で塗る（Kőnig の辺彩色定理より $\Delta$ 色で必ず足りる）。$O(m\sqrt{n}\log\Delta)$。

1. 同じ側の頂点を「次数の和が $\Delta$ 以下」になるようにまとめて両側の頂点数をそろえ、ダミー辺を足して $\Delta$-正則な二部多重グラフにする（色の衝突は元のグラフでも起きない）。
2. $\Delta$ が奇数なら完全マッチング（正則二部グラフには必ずある。[二部マッチング](bipartite_matching.hpp)）を 1 色で塗って取り除き、$\Delta - 1$ にする。
3. $\Delta$ が偶数ならオイラー閉路に沿って辺を交互に 2 つに分ける。各頂点で次数がちょうど半分ずつになり、$\Delta/2$-正則グラフ 2 つを再帰的に塗る。

## 使い方

```cpp
vector<pair<int, int>> edges;   // (左, 右)
auto [k, color] = bipartite_edge_coloring(L, R, edges);   // k = Δ, color[i] ∈ [0, k)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `pair<int, vector<int>> bipartite_edge_coloring(int L, int R, edges)` | 色数 $\Delta$ と各辺の色 | $O(m\sqrt{n}\log\Delta)$ |

## 注意

- 多重辺があってもよい（同じ頂点対の辺にも別の色がつく）。
