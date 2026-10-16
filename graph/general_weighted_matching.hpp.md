---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/general_weighted_matching.test.cpp
    title: test/general_weighted_matching.test.cpp
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
    \ 3 \"graph/general_weighted_matching.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u91CD\u307F\u30DE\u30C3\u30C1\
    \u30F3\u30B0 (Edmonds \u306E\u4E3B\u53CC\u5BFE\u6CD5\u30FB\u82B1\u306E\u7E2E\u7D04\
    )\uFF0EO(n^3)\n// \u9802\u70B9\u30E9\u30D9\u30EB (\u53CC\u5BFE\u5909\u6570) lab\
    \ \u3068\uFF0C\u82B1 (\u5947\u9589\u8DEF\u3092\u7E2E\u7D04\u3057\u305F\u9802\u70B9\
    ) \u3054\u3068\u306E\u30E9\u30D9\u30EB\u3092\u6301\u3061\uFF0C\n// \u300C\u30E9\
    \u30D9\u30EB\u306E\u548C = \u8FBA\u306E\u91CD\u307F \xD7 2\u300D\u3068\u306A\u308B\
    \u8FBA (\u30BF\u30A4\u30C8\u306A\u8FBA) \u3060\u3051\u3067\u4EA4\u4E92\u6728\u3092\
    \u4F38\u3070\u3059\uFF0E\u4F38\u3070\u305B\u306A\u304F\u306A\u3063\u305F\u3089\
    \u53CC\u5BFE\u3092 d \u3060\u3051\u52D5\u304B\u3059\uFF0E\n// \u9802\u70B9\u306F\
    \u5185\u90E8\u3067 1-indexed\uFF0C\u82B1\u306F n+1 .. 2n\ntemplate <class W =\
    \ long long>\nstruct GeneralWeightedMatching {\n    struct Edge {\n        int\
    \ u, v;\n        W w;\n    };\n    int n, nx;\n    vector<vector<Edge>> g;\n \
    \   vector<W> lab;\n    vector<int> mate, slack, st, pa, S, vis;\n    vector<vector<int>>\
    \ flo_from;\n    vector<vector<int>> flo;\n    vector<int> que;\n    size_t qh\
    \ = 0;\n    int vis_t = 0;\n\n    GeneralWeightedMatching(int n_)\n        : n(n_),\
    \ nx(n_), g(2 * n_ + 1, vector<Edge>(2 * n_ + 1)), lab(2 * n_ + 1), mate(2 * n_\
    \ + 1), slack(2 * n_ + 1), st(2 * n_ + 1),\n          pa(2 * n_ + 1), S(2 * n_\
    \ + 1), vis(2 * n_ + 1), flo_from(2 * n_ + 1, vector<int>(n_ + 1)), flo(2 * n_\
    \ + 1) {\n        for (int u = 1; u <= n; u++)\n            for (int v = 1; v\
    \ <= n; v++) g[u][v] = {u, v, 0};\n    }\n\n    // \u8FBA (u, v) \u91CD\u307F\
    \ w (0-indexed\uFF0Cw > 0\uFF0E\u540C\u3058\u7D44\u306F\u91CD\u3044\u65B9)\n \
    \   void add_edge(int u, int v, W w) {\n        u++, v++;\n        if (w > g[u][v].w)\
    \ g[u][v].w = g[v][u].w = w;\n    }\n\n    // {\u91CD\u307F\u306E\u548C, \u30DE\
    \u30C3\u30C1\u30F3\u30B0\u306E\u8FBA\u306E\u6570}\n    pair<W, int> solve() {\n\
    \        fill(mate.begin(), mate.end(), 0);\n        nx = n;\n        for (int\
    \ u = 0; u <= n; u++) st[u] = u, flo[u].clear();\n        W wmax = 0;\n      \
    \  for (int u = 1; u <= n; u++)\n            for (int v = 1; v <= n; v++) {\n\
    \                flo_from[u][v] = (u == v ? u : 0);\n                wmax = std::max(wmax,\
    \ g[u][v].w);\n            }\n        for (int u = 1; u <= n; u++) lab[u] = wmax;\n\
    \        int cnt = 0;\n        while (matching()) cnt++;\n        W tot = 0;\n\
    \        for (int u = 1; u <= n; u++)\n            if (mate[u] && mate[u] < u)\
    \ tot += g[u][mate[u]].w;\n        return {tot, cnt};\n    }\n\n    // \u30DE\u30C3\
    \u30C1\u30F3\u30B0\u306E\u8FBA (0-indexed, u < v)\n    vector<pair<int, int>>\
    \ matching_edges() const {\n        vector<pair<int, int>> res;\n        for (int\
    \ u = 1; u <= n; u++)\n            if (mate[u] && u < mate[u]) res.push_back({u\
    \ - 1, mate[u] - 1});\n        return res;\n    }\n\n  private:\n    W e_delta(const\
    \ Edge &e) const { return lab[e.u] + lab[e.v] - g[e.u][e.v].w * 2; }\n    void\
    \ update_slack(int u, int x) {\n        if (!slack[x] || e_delta(g[u][x]) < e_delta(g[slack[x]][x]))\
    \ slack[x] = u;\n    }\n    void set_slack(int x) {\n        slack[x] = 0;\n \
    \       for (int u = 1; u <= n; u++)\n            if (g[u][x].w > 0 && st[u] !=\
    \ x && S[st[u]] == 0) update_slack(u, x);\n    }\n    void q_push(int x) {\n \
    \       if (x <= n) que.push_back(x);\n        else\n            for (int y :\
    \ flo[x]) q_push(y);\n    }\n    void set_st(int x, int b) {\n        st[x] =\
    \ b;\n        if (x > n)\n            for (int y : flo[x]) set_st(y, b);\n   \
    \ }\n    int get_pr(int b, int xr) {\n        int pr = find(flo[b].begin(), flo[b].end(),\
    \ xr) - flo[b].begin();\n        if (pr % 2 == 1) {\n            reverse(flo[b].begin()\
    \ + 1, flo[b].end());\n            return (int)flo[b].size() - pr;\n        }\n\
    \        return pr;\n    }\n    void set_match(int u, int v) {\n        mate[u]\
    \ = g[u][v].v;\n        if (u <= n) return;\n        Edge e = g[u][v];\n     \
    \   int xr = flo_from[u][e.u], pr = get_pr(u, xr);\n        for (int i = 0; i\
    \ < pr; i++) set_match(flo[u][i], flo[u][i ^ 1]);\n        set_match(xr, v);\n\
    \        rotate(flo[u].begin(), flo[u].begin() + pr, flo[u].end());\n    }\n \
    \   void augment(int u, int v) {\n        while (true) {\n            int xnv\
    \ = st[mate[u]];\n            set_match(u, v);\n            if (!xnv) return;\n\
    \            set_match(xnv, st[pa[xnv]]);\n            u = st[pa[xnv]], v = xnv;\n\
    \        }\n    }\n    int get_lca(int u, int v) {\n        for (++vis_t; u ||\
    \ v; swap(u, v)) {\n            if (u == 0) continue;\n            if (vis[u]\
    \ == vis_t) return u;\n            vis[u] = vis_t;\n            u = st[mate[u]];\n\
    \            if (u) u = st[pa[u]];\n        }\n        return 0;\n    }\n    void\
    \ add_blossom(int u, int lca, int v) {\n        int b = n + 1;\n        while\
    \ (b <= nx && st[b]) b++;\n        if (b > nx) nx++;\n        lab[b] = 0, S[b]\
    \ = 0;\n        mate[b] = mate[lca];\n        flo[b].clear();\n        flo[b].push_back(lca);\n\
    \        for (int x = u, y; x != lca; x = st[pa[y]]) flo[b].push_back(x), flo[b].push_back(y\
    \ = st[mate[x]]), q_push(y);\n        reverse(flo[b].begin() + 1, flo[b].end());\n\
    \        for (int x = v, y; x != lca; x = st[pa[y]]) flo[b].push_back(x), flo[b].push_back(y\
    \ = st[mate[x]]), q_push(y);\n        set_st(b, b);\n        for (int x = 1; x\
    \ <= nx; x++) g[b][x].w = g[x][b].w = 0;\n        for (int x = 1; x <= n; x++)\
    \ flo_from[b][x] = 0;\n        for (int xs : flo[b]) {\n            for (int x\
    \ = 1; x <= nx; x++)\n                if (g[b][x].w == 0 || e_delta(g[xs][x])\
    \ < e_delta(g[b][x])) g[b][x] = g[xs][x], g[x][b] = g[x][xs];\n            for\
    \ (int x = 1; x <= n; x++)\n                if (flo_from[xs][x]) flo_from[b][x]\
    \ = xs;\n        }\n        set_slack(b);\n    }\n    void expand_blossom(int\
    \ b) {\n        for (int x : flo[b]) set_st(x, x);\n        int xr = flo_from[b][g[b][pa[b]].u],\
    \ pr = get_pr(b, xr);\n        for (int i = 0; i < pr; i += 2) {\n           \
    \ int xs = flo[b][i], xns = flo[b][i + 1];\n            pa[xs] = g[xns][xs].u;\n\
    \            S[xs] = 1, S[xns] = 0;\n            slack[xs] = 0, set_slack(xns);\n\
    \            q_push(xns);\n        }\n        S[xr] = 1, pa[xr] = pa[b];\n   \
    \     for (size_t i = pr + 1; i < flo[b].size(); i++) {\n            int xs =\
    \ flo[b][i];\n            S[xs] = -1, set_slack(xs);\n        }\n        st[b]\
    \ = 0;\n    }\n    bool on_found_edge(const Edge &e) {\n        int u = st[e.u],\
    \ v = st[e.v];\n        if (S[v] == -1) {\n            pa[v] = e.u, S[v] = 1;\n\
    \            int nu = st[mate[v]];\n            slack[v] = slack[nu] = 0;\n  \
    \          S[nu] = 0, q_push(nu);\n        } else if (S[v] == 0) {\n         \
    \   int lca = get_lca(u, v);\n            if (!lca) {\n                augment(u,\
    \ v), augment(v, u);\n                return true;\n            }\n          \
    \  add_blossom(u, lca, v);\n        }\n        return false;\n    }\n    bool\
    \ matching() {\n        for (int x = 1; x <= nx; x++) S[x] = -1, slack[x] = 0;\n\
    \        que.clear(), qh = 0;\n        for (int x = 1; x <= nx; x++)\n       \
    \     if (st[x] == x && !mate[x]) pa[x] = 0, S[x] = 0, q_push(x);\n        if\
    \ (que.empty()) return false;\n        while (true) {\n            while (qh <\
    \ que.size()) {\n                int u = que[qh++];\n                if (S[st[u]]\
    \ == 1) continue;\n                for (int v = 1; v <= n; v++) {\n          \
    \          if (g[u][v].w > 0 && st[u] != st[v]) {\n                        if\
    \ (e_delta(g[u][v]) == 0) {\n                            if (on_found_edge(g[u][v]))\
    \ return true;\n                        } else {\n                           \
    \ update_slack(u, st[v]);\n                        }\n                    }\n\
    \                }\n            }\n            W d = numeric_limits<W>::max();\n\
    \            for (int b = n + 1; b <= nx; b++)\n                if (st[b] == b\
    \ && S[b] == 1) d = std::min(d, lab[b] / 2);\n            for (int x = 1; x <=\
    \ nx; x++) {\n                if (st[x] == x && slack[x]) {\n                \
    \    if (S[x] == -1) d = std::min(d, e_delta(g[slack[x]][x]));\n             \
    \       else if (S[x] == 0) d = std::min(d, e_delta(g[slack[x]][x]) / 2);\n  \
    \              }\n            }\n            // \u5916\u5074\u306E\u9802\u70B9\
    \u306E\u30E9\u30D9\u30EB\u304C 0 \u306B\u306A\u308B\u306A\u3089\uFF0C\u3053\u308C\
    \u4EE5\u4E0A\u91CD\u307F\u3092\u5897\u3084\u305B\u306A\u3044 (\u5148\u306B\u5224\
    \u5B9A\u3057\u3066\u304B\u3089\u52D5\u304B\u3059)\n            for (int u = 1;\
    \ u <= n; u++)\n                if (S[st[u]] == 0 && lab[u] <= d) return false;\n\
    \            for (int u = 1; u <= n; u++) {\n                if (S[st[u]] == 0)\
    \ lab[u] -= d;\n                else if (S[st[u]] == 1) lab[u] += d;\n       \
    \     }\n            for (int b = n + 1; b <= nx; b++) {\n                if (st[b]\
    \ == b) {\n                    if (S[st[b]] == 0) lab[b] += d * 2;\n         \
    \           else if (S[st[b]] == 1) lab[b] -= d * 2;\n                }\n    \
    \        }\n            que.clear(), qh = 0;\n            for (int x = 1; x <=\
    \ nx; x++)\n                if (st[x] == x && slack[x] && st[slack[x]] != x &&\
    \ e_delta(g[slack[x]][x]) == 0)\n                    if (on_found_edge(g[slack[x]][x]))\
    \ return true;\n            for (int b = n + 1; b <= nx; b++)\n              \
    \  if (st[b] == b && S[b] == 1 && lab[b] == 0) expand_blossom(b);\n        }\n\
    \        return false;\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u91CD\u307F\u30DE\u30C3\u30C1\
    \u30F3\u30B0 (Edmonds \u306E\u4E3B\u53CC\u5BFE\u6CD5\u30FB\u82B1\u306E\u7E2E\u7D04\
    )\uFF0EO(n^3)\n// \u9802\u70B9\u30E9\u30D9\u30EB (\u53CC\u5BFE\u5909\u6570) lab\
    \ \u3068\uFF0C\u82B1 (\u5947\u9589\u8DEF\u3092\u7E2E\u7D04\u3057\u305F\u9802\u70B9\
    ) \u3054\u3068\u306E\u30E9\u30D9\u30EB\u3092\u6301\u3061\uFF0C\n// \u300C\u30E9\
    \u30D9\u30EB\u306E\u548C = \u8FBA\u306E\u91CD\u307F \xD7 2\u300D\u3068\u306A\u308B\
    \u8FBA (\u30BF\u30A4\u30C8\u306A\u8FBA) \u3060\u3051\u3067\u4EA4\u4E92\u6728\u3092\
    \u4F38\u3070\u3059\uFF0E\u4F38\u3070\u305B\u306A\u304F\u306A\u3063\u305F\u3089\
    \u53CC\u5BFE\u3092 d \u3060\u3051\u52D5\u304B\u3059\uFF0E\n// \u9802\u70B9\u306F\
    \u5185\u90E8\u3067 1-indexed\uFF0C\u82B1\u306F n+1 .. 2n\ntemplate <class W =\
    \ long long>\nstruct GeneralWeightedMatching {\n    struct Edge {\n        int\
    \ u, v;\n        W w;\n    };\n    int n, nx;\n    vector<vector<Edge>> g;\n \
    \   vector<W> lab;\n    vector<int> mate, slack, st, pa, S, vis;\n    vector<vector<int>>\
    \ flo_from;\n    vector<vector<int>> flo;\n    vector<int> que;\n    size_t qh\
    \ = 0;\n    int vis_t = 0;\n\n    GeneralWeightedMatching(int n_)\n        : n(n_),\
    \ nx(n_), g(2 * n_ + 1, vector<Edge>(2 * n_ + 1)), lab(2 * n_ + 1), mate(2 * n_\
    \ + 1), slack(2 * n_ + 1), st(2 * n_ + 1),\n          pa(2 * n_ + 1), S(2 * n_\
    \ + 1), vis(2 * n_ + 1), flo_from(2 * n_ + 1, vector<int>(n_ + 1)), flo(2 * n_\
    \ + 1) {\n        for (int u = 1; u <= n; u++)\n            for (int v = 1; v\
    \ <= n; v++) g[u][v] = {u, v, 0};\n    }\n\n    // \u8FBA (u, v) \u91CD\u307F\
    \ w (0-indexed\uFF0Cw > 0\uFF0E\u540C\u3058\u7D44\u306F\u91CD\u3044\u65B9)\n \
    \   void add_edge(int u, int v, W w) {\n        u++, v++;\n        if (w > g[u][v].w)\
    \ g[u][v].w = g[v][u].w = w;\n    }\n\n    // {\u91CD\u307F\u306E\u548C, \u30DE\
    \u30C3\u30C1\u30F3\u30B0\u306E\u8FBA\u306E\u6570}\n    pair<W, int> solve() {\n\
    \        fill(mate.begin(), mate.end(), 0);\n        nx = n;\n        for (int\
    \ u = 0; u <= n; u++) st[u] = u, flo[u].clear();\n        W wmax = 0;\n      \
    \  for (int u = 1; u <= n; u++)\n            for (int v = 1; v <= n; v++) {\n\
    \                flo_from[u][v] = (u == v ? u : 0);\n                wmax = std::max(wmax,\
    \ g[u][v].w);\n            }\n        for (int u = 1; u <= n; u++) lab[u] = wmax;\n\
    \        int cnt = 0;\n        while (matching()) cnt++;\n        W tot = 0;\n\
    \        for (int u = 1; u <= n; u++)\n            if (mate[u] && mate[u] < u)\
    \ tot += g[u][mate[u]].w;\n        return {tot, cnt};\n    }\n\n    // \u30DE\u30C3\
    \u30C1\u30F3\u30B0\u306E\u8FBA (0-indexed, u < v)\n    vector<pair<int, int>>\
    \ matching_edges() const {\n        vector<pair<int, int>> res;\n        for (int\
    \ u = 1; u <= n; u++)\n            if (mate[u] && u < mate[u]) res.push_back({u\
    \ - 1, mate[u] - 1});\n        return res;\n    }\n\n  private:\n    W e_delta(const\
    \ Edge &e) const { return lab[e.u] + lab[e.v] - g[e.u][e.v].w * 2; }\n    void\
    \ update_slack(int u, int x) {\n        if (!slack[x] || e_delta(g[u][x]) < e_delta(g[slack[x]][x]))\
    \ slack[x] = u;\n    }\n    void set_slack(int x) {\n        slack[x] = 0;\n \
    \       for (int u = 1; u <= n; u++)\n            if (g[u][x].w > 0 && st[u] !=\
    \ x && S[st[u]] == 0) update_slack(u, x);\n    }\n    void q_push(int x) {\n \
    \       if (x <= n) que.push_back(x);\n        else\n            for (int y :\
    \ flo[x]) q_push(y);\n    }\n    void set_st(int x, int b) {\n        st[x] =\
    \ b;\n        if (x > n)\n            for (int y : flo[x]) set_st(y, b);\n   \
    \ }\n    int get_pr(int b, int xr) {\n        int pr = find(flo[b].begin(), flo[b].end(),\
    \ xr) - flo[b].begin();\n        if (pr % 2 == 1) {\n            reverse(flo[b].begin()\
    \ + 1, flo[b].end());\n            return (int)flo[b].size() - pr;\n        }\n\
    \        return pr;\n    }\n    void set_match(int u, int v) {\n        mate[u]\
    \ = g[u][v].v;\n        if (u <= n) return;\n        Edge e = g[u][v];\n     \
    \   int xr = flo_from[u][e.u], pr = get_pr(u, xr);\n        for (int i = 0; i\
    \ < pr; i++) set_match(flo[u][i], flo[u][i ^ 1]);\n        set_match(xr, v);\n\
    \        rotate(flo[u].begin(), flo[u].begin() + pr, flo[u].end());\n    }\n \
    \   void augment(int u, int v) {\n        while (true) {\n            int xnv\
    \ = st[mate[u]];\n            set_match(u, v);\n            if (!xnv) return;\n\
    \            set_match(xnv, st[pa[xnv]]);\n            u = st[pa[xnv]], v = xnv;\n\
    \        }\n    }\n    int get_lca(int u, int v) {\n        for (++vis_t; u ||\
    \ v; swap(u, v)) {\n            if (u == 0) continue;\n            if (vis[u]\
    \ == vis_t) return u;\n            vis[u] = vis_t;\n            u = st[mate[u]];\n\
    \            if (u) u = st[pa[u]];\n        }\n        return 0;\n    }\n    void\
    \ add_blossom(int u, int lca, int v) {\n        int b = n + 1;\n        while\
    \ (b <= nx && st[b]) b++;\n        if (b > nx) nx++;\n        lab[b] = 0, S[b]\
    \ = 0;\n        mate[b] = mate[lca];\n        flo[b].clear();\n        flo[b].push_back(lca);\n\
    \        for (int x = u, y; x != lca; x = st[pa[y]]) flo[b].push_back(x), flo[b].push_back(y\
    \ = st[mate[x]]), q_push(y);\n        reverse(flo[b].begin() + 1, flo[b].end());\n\
    \        for (int x = v, y; x != lca; x = st[pa[y]]) flo[b].push_back(x), flo[b].push_back(y\
    \ = st[mate[x]]), q_push(y);\n        set_st(b, b);\n        for (int x = 1; x\
    \ <= nx; x++) g[b][x].w = g[x][b].w = 0;\n        for (int x = 1; x <= n; x++)\
    \ flo_from[b][x] = 0;\n        for (int xs : flo[b]) {\n            for (int x\
    \ = 1; x <= nx; x++)\n                if (g[b][x].w == 0 || e_delta(g[xs][x])\
    \ < e_delta(g[b][x])) g[b][x] = g[xs][x], g[x][b] = g[x][xs];\n            for\
    \ (int x = 1; x <= n; x++)\n                if (flo_from[xs][x]) flo_from[b][x]\
    \ = xs;\n        }\n        set_slack(b);\n    }\n    void expand_blossom(int\
    \ b) {\n        for (int x : flo[b]) set_st(x, x);\n        int xr = flo_from[b][g[b][pa[b]].u],\
    \ pr = get_pr(b, xr);\n        for (int i = 0; i < pr; i += 2) {\n           \
    \ int xs = flo[b][i], xns = flo[b][i + 1];\n            pa[xs] = g[xns][xs].u;\n\
    \            S[xs] = 1, S[xns] = 0;\n            slack[xs] = 0, set_slack(xns);\n\
    \            q_push(xns);\n        }\n        S[xr] = 1, pa[xr] = pa[b];\n   \
    \     for (size_t i = pr + 1; i < flo[b].size(); i++) {\n            int xs =\
    \ flo[b][i];\n            S[xs] = -1, set_slack(xs);\n        }\n        st[b]\
    \ = 0;\n    }\n    bool on_found_edge(const Edge &e) {\n        int u = st[e.u],\
    \ v = st[e.v];\n        if (S[v] == -1) {\n            pa[v] = e.u, S[v] = 1;\n\
    \            int nu = st[mate[v]];\n            slack[v] = slack[nu] = 0;\n  \
    \          S[nu] = 0, q_push(nu);\n        } else if (S[v] == 0) {\n         \
    \   int lca = get_lca(u, v);\n            if (!lca) {\n                augment(u,\
    \ v), augment(v, u);\n                return true;\n            }\n          \
    \  add_blossom(u, lca, v);\n        }\n        return false;\n    }\n    bool\
    \ matching() {\n        for (int x = 1; x <= nx; x++) S[x] = -1, slack[x] = 0;\n\
    \        que.clear(), qh = 0;\n        for (int x = 1; x <= nx; x++)\n       \
    \     if (st[x] == x && !mate[x]) pa[x] = 0, S[x] = 0, q_push(x);\n        if\
    \ (que.empty()) return false;\n        while (true) {\n            while (qh <\
    \ que.size()) {\n                int u = que[qh++];\n                if (S[st[u]]\
    \ == 1) continue;\n                for (int v = 1; v <= n; v++) {\n          \
    \          if (g[u][v].w > 0 && st[u] != st[v]) {\n                        if\
    \ (e_delta(g[u][v]) == 0) {\n                            if (on_found_edge(g[u][v]))\
    \ return true;\n                        } else {\n                           \
    \ update_slack(u, st[v]);\n                        }\n                    }\n\
    \                }\n            }\n            W d = numeric_limits<W>::max();\n\
    \            for (int b = n + 1; b <= nx; b++)\n                if (st[b] == b\
    \ && S[b] == 1) d = std::min(d, lab[b] / 2);\n            for (int x = 1; x <=\
    \ nx; x++) {\n                if (st[x] == x && slack[x]) {\n                \
    \    if (S[x] == -1) d = std::min(d, e_delta(g[slack[x]][x]));\n             \
    \       else if (S[x] == 0) d = std::min(d, e_delta(g[slack[x]][x]) / 2);\n  \
    \              }\n            }\n            // \u5916\u5074\u306E\u9802\u70B9\
    \u306E\u30E9\u30D9\u30EB\u304C 0 \u306B\u306A\u308B\u306A\u3089\uFF0C\u3053\u308C\
    \u4EE5\u4E0A\u91CD\u307F\u3092\u5897\u3084\u305B\u306A\u3044 (\u5148\u306B\u5224\
    \u5B9A\u3057\u3066\u304B\u3089\u52D5\u304B\u3059)\n            for (int u = 1;\
    \ u <= n; u++)\n                if (S[st[u]] == 0 && lab[u] <= d) return false;\n\
    \            for (int u = 1; u <= n; u++) {\n                if (S[st[u]] == 0)\
    \ lab[u] -= d;\n                else if (S[st[u]] == 1) lab[u] += d;\n       \
    \     }\n            for (int b = n + 1; b <= nx; b++) {\n                if (st[b]\
    \ == b) {\n                    if (S[st[b]] == 0) lab[b] += d * 2;\n         \
    \           else if (S[st[b]] == 1) lab[b] -= d * 2;\n                }\n    \
    \        }\n            que.clear(), qh = 0;\n            for (int x = 1; x <=\
    \ nx; x++)\n                if (st[x] == x && slack[x] && st[slack[x]] != x &&\
    \ e_delta(g[slack[x]][x]) == 0)\n                    if (on_found_edge(g[slack[x]][x]))\
    \ return true;\n            for (int b = n + 1; b <= nx; b++)\n              \
    \  if (st[b] == b && S[b] == 1 && lab[b] == 0) expand_blossom(b);\n        }\n\
    \        return false;\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/general_weighted_matching.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unittest/graph_optimization.test.cpp
  - test/general_weighted_matching.test.cpp
documentation_of: graph/general_weighted_matching.hpp
layout: document
title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u91CD\u307F\u30DE\u30C3\u30C1\
  \u30F3\u30B0"
---

## 概要

無向グラフで、端点を共有しない辺の集合のうち重みの和が最大のものを求める（Edmonds の主双対法）。$O(n^3)$。

各頂点と花（奇閉路を縮約した頂点）に双対変数（ラベル）を持ち、「両端のラベルの和 = 重み × 2」になる**タイトな辺**だけで交互木を伸ばす。増加路が見つかれば増加し、伸ばせなくなったら双対変数を一斉に $d$ だけ動かして新しいタイトな辺を作る。奇閉路は花として縮約し、花のラベルが 0 になったら展開する。

## 使い方

```cpp
GeneralWeightedMatching<long long> wm(n);
wm.add_edge(u, v, w);                       // 0-indexed, w > 0
auto [sum, cnt] = wm.solve();               // 重みの和, マッチングの辺数
for (auto [u, v] : wm.matching_edges()) { ... }   // u < v
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `GeneralWeightedMatching<W>(int n)` | 空のグラフ | $O(n^2)$ |
| `void add_edge(int u, int v, W w)` | 辺を追加（同じ頂点対は重い方が残る） | $O(1)$ |
| `pair<W,int> solve()` | 最大重みと辺数 | $O(n^3)$ |
| `vector<pair<int,int>> matching_edges()` | マッチングの辺 | $O(n)$ |

## 注意

- 隣接行列で持つのでメモリは $O(n^2)$（$n = 500$ で数十 MB 程度）。
- 求めるのは「重み最大」であって「辺数最大の中で重み最大」ではない。後者が欲しいときは全ての重みに十分大きい定数を足す。
- 重み 0 以下の辺は使われない（足しても意味がない）。
