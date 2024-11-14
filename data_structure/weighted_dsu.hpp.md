---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/weighteddsu.test.cpp
    title: test/weighteddsu.test.cpp
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
    \ 3 \"data_structure/weighted_dsu.hpp\"\n\ntemplate<typename T = int>\nstruct\
    \ WeightedUnionFind {\n\n    // \u89AA\u30FBrank\u30FB\u91CD\u307F\u3092\u4FDD\
    \u5B58\u3059\u308B\u914D\u5217\u3092\u5B9A\u7FA9\n    vector<int> par;\n    vector<int>\
    \ rank;\n    vector<T> diff_weight;\n\n    WeightedUnionFind(int n = 1, T SUM_UNITY\
    \ = 0) {\n        par.resize(n); rank.resize(n); diff_weight.resize(n);\n    \
    \    for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;\n\
    \    }\n\n    // \u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\n    int\
    \ find(int x) {\n        if (par[x] == x) {\n            return x;\n        }\n\
    \        else {\n            int r = find(par[x]);\n            diff_weight[x]\
    \ += diff_weight[par[x]];\n            return par[x] = r;\n        }\n    }\n\
    \    \n    // \u5358\u4F4D\u5143 SUM_UNITY \u3092\u57FA\u6E96\u3068\u3057\u305F\
    \u9802\u70B9 x \u306E\u91CD\u307F\u3092\u8FD4\u3059\n    T weight(int x) {\n \
    \       find(x);\n        return diff_weight[x];\n    }\n\n    // x \u3068 y \u304C\
    \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u306A\u3089true , \u305D\u308C\u4EE5\
    \u5916\u3067false\u3092\u8FD4\u3059\uFF0E\n    bool same(int x, int y) {\n   \
    \     return find(x) == find(y);\n    }\n\n    // x-y = w \u3068\u306A\u308B\u3088\
    \u3046\u306B\u96C6\u5408\u3092\u30DE\u30FC\u30B8\uFF0C\u3059\u3067\u306B\u30DE\
    \u30FC\u30B8\u6E08\u307F\u306A\u3089false\u304C\u5E30\u308B\uFF0E\n    bool unite(int\
    \ x, int y, T w) {\n        w += weight(x); w -= weight(y);\n        x = find(x);\
    \ y = find(y);\n        if (x == y) return false;\n        if (rank[x] < rank[y])\
    \ swap(x, y), w = -w;\n        if (rank[x] == rank[y]) ++rank[x];\n        par[y]\
    \ = x;\n        diff_weight[y] = w;\n        return true;\n    }\n\n    // x-y\u3092\
    \u51FA\u529B\n    T diff(int x, int y) {\n        return weight(y) - weight(x);\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename T = int>\n\
    struct WeightedUnionFind {\n\n    // \u89AA\u30FBrank\u30FB\u91CD\u307F\u3092\u4FDD\
    \u5B58\u3059\u308B\u914D\u5217\u3092\u5B9A\u7FA9\n    vector<int> par;\n    vector<int>\
    \ rank;\n    vector<T> diff_weight;\n\n    WeightedUnionFind(int n = 1, T SUM_UNITY\
    \ = 0) {\n        par.resize(n); rank.resize(n); diff_weight.resize(n);\n    \
    \    for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;\n\
    \    }\n\n    // \u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\n    int\
    \ find(int x) {\n        if (par[x] == x) {\n            return x;\n        }\n\
    \        else {\n            int r = find(par[x]);\n            diff_weight[x]\
    \ += diff_weight[par[x]];\n            return par[x] = r;\n        }\n    }\n\
    \    \n    // \u5358\u4F4D\u5143 SUM_UNITY \u3092\u57FA\u6E96\u3068\u3057\u305F\
    \u9802\u70B9 x \u306E\u91CD\u307F\u3092\u8FD4\u3059\n    T weight(int x) {\n \
    \       find(x);\n        return diff_weight[x];\n    }\n\n    // x \u3068 y \u304C\
    \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u306A\u3089true , \u305D\u308C\u4EE5\
    \u5916\u3067false\u3092\u8FD4\u3059\uFF0E\n    bool same(int x, int y) {\n   \
    \     return find(x) == find(y);\n    }\n\n    // x-y = w \u3068\u306A\u308B\u3088\
    \u3046\u306B\u96C6\u5408\u3092\u30DE\u30FC\u30B8\uFF0C\u3059\u3067\u306B\u30DE\
    \u30FC\u30B8\u6E08\u307F\u306A\u3089false\u304C\u5E30\u308B\uFF0E\n    bool unite(int\
    \ x, int y, T w) {\n        w += weight(x); w -= weight(y);\n        x = find(x);\
    \ y = find(y);\n        if (x == y) return false;\n        if (rank[x] < rank[y])\
    \ swap(x, y), w = -w;\n        if (rank[x] == rank[y]) ++rank[x];\n        par[y]\
    \ = x;\n        diff_weight[y] = w;\n        return true;\n    }\n\n    // x-y\u3092\
    \u51FA\u529B\n    T diff(int x, int y) {\n        return weight(y) - weight(x);\n\
    \    }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/weighted_dsu.hpp
  requiredBy: []
  timestamp: '2024-11-14 10:49:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/weighteddsu.test.cpp
documentation_of: data_structure/weighted_dsu.hpp
layout: document
redirect_from:
- /library/data_structure/weighted_dsu.hpp
- /library/data_structure/weighted_dsu.hpp.html
title: data_structure/weighted_dsu.hpp
---
