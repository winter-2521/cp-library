---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/range_parallel_unionfind.test.cpp
    title: test/range_parallel_unionfind.test.cpp
  - icon: ':x:'
    path: test/range_parallel_unionfind_online.test.cpp
    title: test/range_parallel_unionfind_online.test.cpp
  - icon: ':x:'
    path: test/unittest/range_parallel_unionfind.test.cpp
    title: test/unittest/range_parallel_unionfind.test.cpp
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
    \ 3 \"data_structure/range_parallel_unionfind.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u533A\u9593\u4E26\u5217 Union-Find\n// \u300Ci = 0, ..., k-1 \u306B\u3064\
    \u3044\u3066 a+i \u3068 b+i \u3092\u4F75\u5408\u3059\u308B\u300D\u3092\u9AD8\u901F\
    \u306B\u51E6\u7406\u3059\u308B\n// \u5168\u4F53\u3067 O((n log n + q) \u03B1(n))\n\
    //\n// \u6BB5 j \u306E Union-Find \u306F\u300C\u9577\u3055 2^j \u306E\u533A\u9593\
    \ [i, i + 2^j)\u300D\u3092\u8981\u7D20 i \u3068\u3057\u3066\u6301\u3061\uFF0C\n\
    // \u6BB5 j \u3067\u533A\u9593 [a, a+2^j) \u3068 [b, b+2^j) \u3092\u4F75\u5408\
    \u3057\u305F\u3089\uFF0C\u6BB5 j-1 \u3067\u524D\u534A\u540C\u58EB\u30FB\u5F8C\u534A\
    \u540C\u58EB\u3092\u4F75\u5408\u3059\u308B\uFF0E\n// \u5404\u6BB5\u3067\u5B9F\u969B\
    \u306B\u4F75\u5408\u304C\u8D77\u304D\u308B\u306E\u306F\u9AD8\u3005 n-1 \u56DE\u306A\
    \u306E\u3067\uFF0C\u4E0B\u306E\u6BB5\u306B\u4F1D\u308F\u308B\u56DE\u6570\u3082\
    \u6291\u3048\u3089\u308C\u308B\nstruct RangeParallelUnionFind {\n    int n, lg;\n\
    \    // par[j][i]: \u6BB5 j \u306E Union-Find (\u6839\u306A\u3089 -(\u30B5\u30A4\
    \u30BA))\n    vector<vector<int>> par;\n\n    RangeParallelUnionFind(int n = 0)\
    \ : n(n) {\n        lg = 1;\n        while ((1 << lg) <= n) lg++;\n        par.resize(lg);\n\
    \        for (int j = 0; j < lg; j++) par[j].assign(std::max(0, n - (1 << j) +\
    \ 1), -1);\n    }\n\n    static int find(vector<int> &p, int x) {\n        int\
    \ r = x;\n        while (p[r] >= 0) r = p[r];\n        // \u7D4C\u8DEF\u5727\u7E2E\
    \n        while (p[x] >= 0 && p[x] != r) {\n            int nx = p[x];\n     \
    \       p[x] = r;\n            x = nx;\n        }\n        return r;\n    }\n\n\
    \    // \u4F75\u5408\u3057\u3066 (\u6B8B\u3063\u305F\u6839, \u5438\u53CE\u3055\
    \u308C\u305F\u6839) \u3092\u8FD4\u3059\uFF0E\u65E2\u306B\u540C\u3058\u306A\u3089\
    \ {-1, -1}\n    static pair<int, int> unite(vector<int> &p, int x, int y) {\n\
    \        x = find(p, x), y = find(p, y);\n        if (x == y) return {-1, -1};\n\
    \        if (p[x] > p[y]) swap(x, y);\n        p[x] += p[y];\n        p[y] = x;\n\
    \        return {x, y};\n    }\n\n    int leader(int x) { return find(par[0],\
    \ x); }\n    bool same(int x, int y) { return leader(x) == leader(y); }\n    int\
    \ size(int x) { return -par[0][leader(x)]; }\n\n    // i = 0, ..., k-1 \u306B\u3064\
    \u3044\u3066 a+i \u3068 b+i \u3092\u4F75\u5408\u3059\u308B\n    // \u6BB5 0 \u3067\
    \u5B9F\u969B\u306B\u4F75\u5408\u304C\u8D77\u304D\u308B\u305F\u3073\u306B f(\u6B8B\
    \u3063\u305F\u6839, \u5438\u53CE\u3055\u308C\u305F\u6839) \u3092\u547C\u3076\n\
    \    template <class F>\n    void merge(int a, int b, int k, F f) {\n        if\
    \ (k <= 0 || a == b) return;\n        int j = 31 - __builtin_clz(k);\n       \
    \ // \u9577\u3055 2^j \u306E\u533A\u9593 2 \u3064\u3067 [a, a+k) \u3092\u8986\u3046\
    \n        stk.clear();\n        stk.push_back({j, a, b});\n        stk.push_back({j,\
    \ a + k - (1 << j), b + k - (1 << j)});\n        while (!stk.empty()) {\n    \
    \        auto [lv, x, y] = stk.back();\n            stk.pop_back();\n        \
    \    auto [r, c] = unite(par[lv], x, y);\n            if (r < 0) continue;\n \
    \           if (lv == 0) {\n                f(r, c);\n            } else {\n \
    \               int h = 1 << (lv - 1);\n                stk.push_back({lv - 1,\
    \ x, y});\n                stk.push_back({lv - 1, x + h, y + h});\n          \
    \  }\n        }\n    }\n\n    void merge(int a, int b, int k) {\n        merge(a,\
    \ b, k, [](int, int) {});\n    }\n\n    // \u30AF\u30A8\u30EA\u3092\u5148\u8AAD\
    \u307F\u3067\u304D\u308B\u3068\u304D\u306E\u9AD8\u901F\u7248 (\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u306F\u4F5C\u3089\u305A\u306B\u4F7F\u3046)\n    // qs[t] =\
    \ {a, b, k} \u3092 t = 0, 1, ... \u306E\u9806\u306B\u51E6\u7406\u3057\u305F\u3068\
    \u304D\uFF0C\u6BB5 0 \u3067\u5B9F\u969B\u306B\u4F75\u5408\u304C\u8D77\u304D\u308B\
    \u305F\u3073\u306B\n    // f(t, \u6B8B\u3063\u305F\u6839, \u5438\u53CE\u3055\u308C\
    \u305F\u6839) \u3092 t \u306E\u6607\u9806\u306B\u547C\u3076\uFF0E\u8A08\u7B97\u91CF\
    \u306F merge \u3068\u540C\u3058\n    //\n    // \u6BB5\u3092\u4E0A\u304B\u3089\
    \ 1 \u3064\u305A\u3064\u51E6\u7406\u3057\uFF0C\u5404\u6BB5\u306E\u4F75\u5408\u306F\
    \u6642\u523B\u9806\u306B\u884C\u3046\uFF0E\u6BB5 j \u3067\u6210\u529F\u3057\u305F\
    \u4F75\u5408\u3092\u6BB5 j-1 \u306B\u6642\u523B\u3064\u304D\u3067\u6E21\u3059\uFF0E\
    \n    // \u540C\u6642\u306B\u89E6\u308B Union-Find \u304C 1 \u6BB5\u5206\u3060\
    \u3051\u306B\u306A\u308B\u306E\u3067\uFF0C\u30AA\u30F3\u30E9\u30A4\u30F3\u7248\
    \u3088\u308A\u30AD\u30E3\u30C3\u30B7\u30E5\u306B\u4E57\u308A\u3084\u3059\u3044\
    \n    template <class F>\n    static void merge_offline(int n, const vector<array<int,\
    \ 3>> &qs, F f) {\n        int q = qs.size();\n        int lg = 1;\n        while\
    \ ((1 << lg) <= n) lg++;\n        // \u6BB5\u3054\u3068\u306B\uFF0C\u305D\u306E\
    \u6BB5\u306B\u76F4\u63A5\u5165\u308B\u30AF\u30A8\u30EA (\u9577\u3055 2^j \u306E\
    \u533A\u9593 2 \u3064\u3067\u8986\u3046) \u3092\u6642\u523B\u9806\u306B\u4E26\u3079\
    \u308B\n        vector<int> start(lg + 1, 0);\n        for (auto &[a, b, k] :\
    \ qs) if (k > 0 && a != b) start[31 - __builtin_clz(k)]++;\n        for (int j\
    \ = 0; j < lg; j++) start[j + 1] += start[j];\n        vector<int> direct(start[lg]);\n\
    \        for (int t = q - 1; t >= 0; t--) {\n            auto &[a, b, k] = qs[t];\n\
    \            if (k > 0 && a != b) direct[--start[31 - __builtin_clz(k)]] = t;\n\
    \        }\n        struct Item {\n            int t, x, y;\n        };\n    \
    \    vector<Item> cur, nxt;\n        vector<int> p(n);\n        for (int j = lg\
    \ - 1; j >= 0; j--) {\n            int m = n - (1 << j) + 1;\n            fill(p.begin(),\
    \ p.begin() + m, -1);\n            nxt.clear();\n            int h = j > 0 ? 1\
    \ << (j - 1) : 0;\n            auto process = [&](int t, int x, int y) {\n   \
    \             auto [r, c] = unite(p, x, y);\n                if (r < 0) return;\n\
    \                if (j == 0) {\n                    f(t, r, c);\n            \
    \    } else {\n                    nxt.push_back({t, x, y});\n               \
    \     nxt.push_back({t, x + h, y + h});\n                }\n            };\n \
    \           // \u76F4\u63A5\u306E\u30AF\u30A8\u30EA\u3068\u4E0A\u306E\u6BB5\u304B\
    \u3089\u6765\u305F\u3082\u306E\u3092\u6642\u523B\u9806\u306B\u30DE\u30FC\u30B8\
    \u3057\u306A\u304C\u3089\u51E6\u7406\u3059\u308B\n            size_t ci = 0;\n\
    \            for (int di = start[j]; di < start[j + 1]; di++) {\n            \
    \    int t = direct[di];\n                for (; ci < cur.size() && cur[ci].t\
    \ < t; ci++) process(cur[ci].t, cur[ci].x, cur[ci].y);\n                auto &[a,\
    \ b, k] = qs[t];\n                int w = 1 << j;\n                process(t,\
    \ a, b);\n                process(t, a + k - w, b + k - w);\n            }\n \
    \           for (; ci < cur.size(); ci++) process(cur[ci].t, cur[ci].x, cur[ci].y);\n\
    \            swap(cur, nxt);\n        }\n    }\n\n  private:\n    vector<tuple<int,\
    \ int, int>> stk;\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u533A\u9593\u4E26\u5217 Union-Find\n// \u300Ci = 0, ..., k-1 \u306B\u3064\
    \u3044\u3066 a+i \u3068 b+i \u3092\u4F75\u5408\u3059\u308B\u300D\u3092\u9AD8\u901F\
    \u306B\u51E6\u7406\u3059\u308B\n// \u5168\u4F53\u3067 O((n log n + q) \u03B1(n))\n\
    //\n// \u6BB5 j \u306E Union-Find \u306F\u300C\u9577\u3055 2^j \u306E\u533A\u9593\
    \ [i, i + 2^j)\u300D\u3092\u8981\u7D20 i \u3068\u3057\u3066\u6301\u3061\uFF0C\n\
    // \u6BB5 j \u3067\u533A\u9593 [a, a+2^j) \u3068 [b, b+2^j) \u3092\u4F75\u5408\
    \u3057\u305F\u3089\uFF0C\u6BB5 j-1 \u3067\u524D\u534A\u540C\u58EB\u30FB\u5F8C\u534A\
    \u540C\u58EB\u3092\u4F75\u5408\u3059\u308B\uFF0E\n// \u5404\u6BB5\u3067\u5B9F\u969B\
    \u306B\u4F75\u5408\u304C\u8D77\u304D\u308B\u306E\u306F\u9AD8\u3005 n-1 \u56DE\u306A\
    \u306E\u3067\uFF0C\u4E0B\u306E\u6BB5\u306B\u4F1D\u308F\u308B\u56DE\u6570\u3082\
    \u6291\u3048\u3089\u308C\u308B\nstruct RangeParallelUnionFind {\n    int n, lg;\n\
    \    // par[j][i]: \u6BB5 j \u306E Union-Find (\u6839\u306A\u3089 -(\u30B5\u30A4\
    \u30BA))\n    vector<vector<int>> par;\n\n    RangeParallelUnionFind(int n = 0)\
    \ : n(n) {\n        lg = 1;\n        while ((1 << lg) <= n) lg++;\n        par.resize(lg);\n\
    \        for (int j = 0; j < lg; j++) par[j].assign(std::max(0, n - (1 << j) +\
    \ 1), -1);\n    }\n\n    static int find(vector<int> &p, int x) {\n        int\
    \ r = x;\n        while (p[r] >= 0) r = p[r];\n        // \u7D4C\u8DEF\u5727\u7E2E\
    \n        while (p[x] >= 0 && p[x] != r) {\n            int nx = p[x];\n     \
    \       p[x] = r;\n            x = nx;\n        }\n        return r;\n    }\n\n\
    \    // \u4F75\u5408\u3057\u3066 (\u6B8B\u3063\u305F\u6839, \u5438\u53CE\u3055\
    \u308C\u305F\u6839) \u3092\u8FD4\u3059\uFF0E\u65E2\u306B\u540C\u3058\u306A\u3089\
    \ {-1, -1}\n    static pair<int, int> unite(vector<int> &p, int x, int y) {\n\
    \        x = find(p, x), y = find(p, y);\n        if (x == y) return {-1, -1};\n\
    \        if (p[x] > p[y]) swap(x, y);\n        p[x] += p[y];\n        p[y] = x;\n\
    \        return {x, y};\n    }\n\n    int leader(int x) { return find(par[0],\
    \ x); }\n    bool same(int x, int y) { return leader(x) == leader(y); }\n    int\
    \ size(int x) { return -par[0][leader(x)]; }\n\n    // i = 0, ..., k-1 \u306B\u3064\
    \u3044\u3066 a+i \u3068 b+i \u3092\u4F75\u5408\u3059\u308B\n    // \u6BB5 0 \u3067\
    \u5B9F\u969B\u306B\u4F75\u5408\u304C\u8D77\u304D\u308B\u305F\u3073\u306B f(\u6B8B\
    \u3063\u305F\u6839, \u5438\u53CE\u3055\u308C\u305F\u6839) \u3092\u547C\u3076\n\
    \    template <class F>\n    void merge(int a, int b, int k, F f) {\n        if\
    \ (k <= 0 || a == b) return;\n        int j = 31 - __builtin_clz(k);\n       \
    \ // \u9577\u3055 2^j \u306E\u533A\u9593 2 \u3064\u3067 [a, a+k) \u3092\u8986\u3046\
    \n        stk.clear();\n        stk.push_back({j, a, b});\n        stk.push_back({j,\
    \ a + k - (1 << j), b + k - (1 << j)});\n        while (!stk.empty()) {\n    \
    \        auto [lv, x, y] = stk.back();\n            stk.pop_back();\n        \
    \    auto [r, c] = unite(par[lv], x, y);\n            if (r < 0) continue;\n \
    \           if (lv == 0) {\n                f(r, c);\n            } else {\n \
    \               int h = 1 << (lv - 1);\n                stk.push_back({lv - 1,\
    \ x, y});\n                stk.push_back({lv - 1, x + h, y + h});\n          \
    \  }\n        }\n    }\n\n    void merge(int a, int b, int k) {\n        merge(a,\
    \ b, k, [](int, int) {});\n    }\n\n    // \u30AF\u30A8\u30EA\u3092\u5148\u8AAD\
    \u307F\u3067\u304D\u308B\u3068\u304D\u306E\u9AD8\u901F\u7248 (\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u306F\u4F5C\u3089\u305A\u306B\u4F7F\u3046)\n    // qs[t] =\
    \ {a, b, k} \u3092 t = 0, 1, ... \u306E\u9806\u306B\u51E6\u7406\u3057\u305F\u3068\
    \u304D\uFF0C\u6BB5 0 \u3067\u5B9F\u969B\u306B\u4F75\u5408\u304C\u8D77\u304D\u308B\
    \u305F\u3073\u306B\n    // f(t, \u6B8B\u3063\u305F\u6839, \u5438\u53CE\u3055\u308C\
    \u305F\u6839) \u3092 t \u306E\u6607\u9806\u306B\u547C\u3076\uFF0E\u8A08\u7B97\u91CF\
    \u306F merge \u3068\u540C\u3058\n    //\n    // \u6BB5\u3092\u4E0A\u304B\u3089\
    \ 1 \u3064\u305A\u3064\u51E6\u7406\u3057\uFF0C\u5404\u6BB5\u306E\u4F75\u5408\u306F\
    \u6642\u523B\u9806\u306B\u884C\u3046\uFF0E\u6BB5 j \u3067\u6210\u529F\u3057\u305F\
    \u4F75\u5408\u3092\u6BB5 j-1 \u306B\u6642\u523B\u3064\u304D\u3067\u6E21\u3059\uFF0E\
    \n    // \u540C\u6642\u306B\u89E6\u308B Union-Find \u304C 1 \u6BB5\u5206\u3060\
    \u3051\u306B\u306A\u308B\u306E\u3067\uFF0C\u30AA\u30F3\u30E9\u30A4\u30F3\u7248\
    \u3088\u308A\u30AD\u30E3\u30C3\u30B7\u30E5\u306B\u4E57\u308A\u3084\u3059\u3044\
    \n    template <class F>\n    static void merge_offline(int n, const vector<array<int,\
    \ 3>> &qs, F f) {\n        int q = qs.size();\n        int lg = 1;\n        while\
    \ ((1 << lg) <= n) lg++;\n        // \u6BB5\u3054\u3068\u306B\uFF0C\u305D\u306E\
    \u6BB5\u306B\u76F4\u63A5\u5165\u308B\u30AF\u30A8\u30EA (\u9577\u3055 2^j \u306E\
    \u533A\u9593 2 \u3064\u3067\u8986\u3046) \u3092\u6642\u523B\u9806\u306B\u4E26\u3079\
    \u308B\n        vector<int> start(lg + 1, 0);\n        for (auto &[a, b, k] :\
    \ qs) if (k > 0 && a != b) start[31 - __builtin_clz(k)]++;\n        for (int j\
    \ = 0; j < lg; j++) start[j + 1] += start[j];\n        vector<int> direct(start[lg]);\n\
    \        for (int t = q - 1; t >= 0; t--) {\n            auto &[a, b, k] = qs[t];\n\
    \            if (k > 0 && a != b) direct[--start[31 - __builtin_clz(k)]] = t;\n\
    \        }\n        struct Item {\n            int t, x, y;\n        };\n    \
    \    vector<Item> cur, nxt;\n        vector<int> p(n);\n        for (int j = lg\
    \ - 1; j >= 0; j--) {\n            int m = n - (1 << j) + 1;\n            fill(p.begin(),\
    \ p.begin() + m, -1);\n            nxt.clear();\n            int h = j > 0 ? 1\
    \ << (j - 1) : 0;\n            auto process = [&](int t, int x, int y) {\n   \
    \             auto [r, c] = unite(p, x, y);\n                if (r < 0) return;\n\
    \                if (j == 0) {\n                    f(t, r, c);\n            \
    \    } else {\n                    nxt.push_back({t, x, y});\n               \
    \     nxt.push_back({t, x + h, y + h});\n                }\n            };\n \
    \           // \u76F4\u63A5\u306E\u30AF\u30A8\u30EA\u3068\u4E0A\u306E\u6BB5\u304B\
    \u3089\u6765\u305F\u3082\u306E\u3092\u6642\u523B\u9806\u306B\u30DE\u30FC\u30B8\
    \u3057\u306A\u304C\u3089\u51E6\u7406\u3059\u308B\n            size_t ci = 0;\n\
    \            for (int di = start[j]; di < start[j + 1]; di++) {\n            \
    \    int t = direct[di];\n                for (; ci < cur.size() && cur[ci].t\
    \ < t; ci++) process(cur[ci].t, cur[ci].x, cur[ci].y);\n                auto &[a,\
    \ b, k] = qs[t];\n                int w = 1 << j;\n                process(t,\
    \ a, b);\n                process(t, a + k - w, b + k - w);\n            }\n \
    \           for (; ci < cur.size(); ci++) process(cur[ci].t, cur[ci].x, cur[ci].y);\n\
    \            swap(cur, nxt);\n        }\n    }\n\n  private:\n    vector<tuple<int,\
    \ int, int>> stk;\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/range_parallel_unionfind.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unittest/range_parallel_unionfind.test.cpp
  - test/range_parallel_unionfind_online.test.cpp
  - test/range_parallel_unionfind.test.cpp
documentation_of: data_structure/range_parallel_unionfind.hpp
layout: document
title: "\u533A\u9593\u4E26\u5217 Union-Find (Range Parallel Union-Find)"
---

## 概要

「$i = 0, \ldots, k-1$ について $a+i$ と $b+i$ を併合する」という操作を高速に処理する Union-Find。

段 $j$ の Union-Find は長さ $2^j$ の区間 $[i, i+2^j)$ を要素 $i$ として持つ。長さ $k$ の併合は、$2^j \le k$ となる最大の $j$ について長さ $2^j$ の区間 2 つ（先頭と末尾）の併合に分解する。段 $j$ で実際に併合が起きたら段 $j-1$ で前半同士・後半同士を併合する。各段で実際に併合が起きるのは高々 $n-1$ 回なので、全体で $O((n \log n + q)\,\alpha(n))$。

段 0 で実際に併合が起きるたびにコールバック `f(残った根, 吸収された根)` が呼ばれるので、成分ごとの値（和など）を管理できる。

クエリをまとめて先読みできるなら、`merge_offline` の方が速い（段を 1 つずつ処理するのでキャッシュに乗りやすい。$n = q = 5 \times 10^5$ で手元 0.47 秒 → 0.27 秒）。

## 使い方

```cpp
RangeParallelUnionFind uf(n);
uf.merge(a, b, k);                     // i = 0..k-1 について a+i と b+i を併合
uf.merge(a, b, k, [&](int r, int c) {  // 段 0 で併合が起きるたびに呼ばれる
    val[r] += val[c];                  // r が残った根, c が吸収された根
});
uf.leader(x); uf.same(x, y); uf.size(x);

// オフライン版：qs[t] = {a, b, k}．f(t, r, c) が t の昇順に呼ばれる
vector<array<int, 3>> qs = ...;
RangeParallelUnionFind::merge_offline(n, qs, [&](int t, int r, int c) { ... });
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `RangeParallelUnionFind(int n)` | 要素数 `n` で初期化 | $O(n \log n)$ |
| `void merge(int a, int b, int k, F f)` | $a+i$ と $b+i$ ($0 \le i < k$) を併合。段 0 の併合ごとに `f(r, c)` | 全体でならし $O((n \log n + q)\,\alpha(n))$ |
| `int leader(int x)` | 代表元 | ならし $O(\alpha(n))$ |
| `bool same(int x, int y)` | 同じ集合か | ならし $O(\alpha(n))$ |
| `int size(int x)` | `x` を含む集合のサイズ | ならし $O(\alpha(n))$ |
| `static void merge_offline(int n, const vector<array<int, 3>> &qs, F f)` | クエリ列 `qs[t] = {a, b, k}` を順に処理し、段 0 の併合ごとに `f(t, r, c)` を $t$ の昇順に呼ぶ | $O((n \log n + q)\,\alpha(n))$ |

## 注意

- $0 \le a, b$ かつ $a + k, b + k \le n$ であること。$k = 0$ や $a = b$ のときは何もしない。
- **`merge_offline` はクエリを全て先読みできるときのみ使える**。各クエリの直後に連結性を問い合わせて次のクエリを決める（オンラインで答える必要がある）問題では `merge` を使うこと。
- メモリは $O(n \log n)$（`merge_offline` は $O(n + q)$）。
- `merge_offline` の後の連結性は、コールバックで受け取った `(r, c)` を通常の Union-Find で併合すれば再現できる（`r`, `c` は段 0 の Union-Find の根）。
- コールバックの中で `uf` 自体を操作してはいけない（`leader` などの参照は可）。
