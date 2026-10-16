---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/weighteddsu.test.cpp
    title: test/weighteddsu.test.cpp
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
    \ 3 \"data_structure/weighted_dsu.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \ntemplate<typename T = int>\nstruct WeightedUnionFind {\n\n    // \u89AA\u30FB\
    rank\u30FB\u91CD\u307F\u3092\u4FDD\u5B58\u3059\u308B\u914D\u5217\u3092\u5B9A\u7FA9\
    \n    vector<int> par;\n    vector<int> rank;\n    vector<T> diff_weight;\n\n\
    \    WeightedUnionFind(int n = 1, T SUM_UNITY = 0) {\n        par.resize(n); rank.resize(n);\
    \ diff_weight.resize(n);\n        for (int i = 0; i < n; ++i) par[i] = i, rank[i]\
    \ = 0, diff_weight[i] = SUM_UNITY;\n    }\n\n    // \u96C6\u5408\u306E\u4EE3\u8868\
    \u5143\u3092\u8FD4\u3059\n    int find(int x) {\n        if (par[x] == x) {\n\
    \            return x;\n        }\n        else {\n            int r = find(par[x]);\n\
    \            diff_weight[x] += diff_weight[par[x]];\n            return par[x]\
    \ = r;\n        }\n    }\n    \n    // \u5358\u4F4D\u5143 SUM_UNITY \u3092\u57FA\
    \u6E96\u3068\u3057\u305F\u9802\u70B9 x \u306E\u91CD\u307F\u3092\u8FD4\u3059\n\
    \    T weight(int x) {\n        find(x);\n        return diff_weight[x];\n   \
    \ }\n\n    // x \u3068 y \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u306A\
    \u3089true , \u305D\u308C\u4EE5\u5916\u3067false\u3092\u8FD4\u3059\uFF0E\n   \
    \ bool same(int x, int y) {\n        return find(x) == find(y);\n    }\n\n   \
    \ // weight(y) - weight(x) = w \u3068\u306A\u308B\u3088\u3046\u306B\u96C6\u5408\
    \u3092\u30DE\u30FC\u30B8\uFF0C\u3059\u3067\u306B\u30DE\u30FC\u30B8\u6E08\u307F\
    \u306A\u3089false\u304C\u8FD4\u308B\uFF0E\n    bool unite(int x, int y, T w) {\n\
    \        w += weight(x); w -= weight(y);\n        x = find(x); y = find(y);\n\
    \        if (x == y) return false;\n        if (rank[x] < rank[y]) swap(x, y),\
    \ w = -w;\n        if (rank[x] == rank[y]) ++rank[x];\n        par[y] = x;\n \
    \       diff_weight[y] = w;\n        return true;\n    }\n\n    // weight(y) -\
    \ weight(x) \u3092\u8FD4\u3059\n    T diff(int x, int y) {\n        return weight(y)\
    \ - weight(x);\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \ntemplate<typename T = int>\nstruct WeightedUnionFind {\n\n    // \u89AA\u30FB\
    rank\u30FB\u91CD\u307F\u3092\u4FDD\u5B58\u3059\u308B\u914D\u5217\u3092\u5B9A\u7FA9\
    \n    vector<int> par;\n    vector<int> rank;\n    vector<T> diff_weight;\n\n\
    \    WeightedUnionFind(int n = 1, T SUM_UNITY = 0) {\n        par.resize(n); rank.resize(n);\
    \ diff_weight.resize(n);\n        for (int i = 0; i < n; ++i) par[i] = i, rank[i]\
    \ = 0, diff_weight[i] = SUM_UNITY;\n    }\n\n    // \u96C6\u5408\u306E\u4EE3\u8868\
    \u5143\u3092\u8FD4\u3059\n    int find(int x) {\n        if (par[x] == x) {\n\
    \            return x;\n        }\n        else {\n            int r = find(par[x]);\n\
    \            diff_weight[x] += diff_weight[par[x]];\n            return par[x]\
    \ = r;\n        }\n    }\n    \n    // \u5358\u4F4D\u5143 SUM_UNITY \u3092\u57FA\
    \u6E96\u3068\u3057\u305F\u9802\u70B9 x \u306E\u91CD\u307F\u3092\u8FD4\u3059\n\
    \    T weight(int x) {\n        find(x);\n        return diff_weight[x];\n   \
    \ }\n\n    // x \u3068 y \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u306A\
    \u3089true , \u305D\u308C\u4EE5\u5916\u3067false\u3092\u8FD4\u3059\uFF0E\n   \
    \ bool same(int x, int y) {\n        return find(x) == find(y);\n    }\n\n   \
    \ // weight(y) - weight(x) = w \u3068\u306A\u308B\u3088\u3046\u306B\u96C6\u5408\
    \u3092\u30DE\u30FC\u30B8\uFF0C\u3059\u3067\u306B\u30DE\u30FC\u30B8\u6E08\u307F\
    \u306A\u3089false\u304C\u8FD4\u308B\uFF0E\n    bool unite(int x, int y, T w) {\n\
    \        w += weight(x); w -= weight(y);\n        x = find(x); y = find(y);\n\
    \        if (x == y) return false;\n        if (rank[x] < rank[y]) swap(x, y),\
    \ w = -w;\n        if (rank[x] == rank[y]) ++rank[x];\n        par[y] = x;\n \
    \       diff_weight[y] = w;\n        return true;\n    }\n\n    // weight(y) -\
    \ weight(x) \u3092\u8FD4\u3059\n    T diff(int x, int y) {\n        return weight(y)\
    \ - weight(x);\n    }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/weighted_dsu.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/weighteddsu.test.cpp
documentation_of: data_structure/weighted_dsu.hpp
layout: document
title: "\u91CD\u307F\u4ED8\u304D Union-Find (Weighted Union-Find)"
---

## 概要

各要素にポテンシャル（重み）$p(x)$ を持たせた Union-Find。
「$p(y) - p(x) = w$」という差分制約を追加していき、同じ集合に属する 2 要素の差分を求められる。
union by rank と経路圧縮を併用している。頂点は 0-indexed。

## 使い方

```cpp
WeightedUnionFind<long long> uf(n);   // 型 T は重みの型 (デフォルト int)
uf.unite(x, y, w);    // p(y) - p(x) = w という関係を追加
uf.same(x, y);        // 同じ集合なら true
uf.diff(x, y);        // p(y) - p(x) を返す (same(x, y) のときのみ意味がある)
uf.weight(x);         // 代表元を基準とした p(x)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `WeightedUnionFind(int n, T SUM_UNITY = 0)` | 要素数 `n` で初期化。`SUM_UNITY` は重みの単位元 | $O(n)$ |
| `int find(int x)` | 代表元を返す | ならし $O(\alpha(n))$ |
| `T weight(int x)` | 代表元の重みを `SUM_UNITY` としたときの $p(x)$ | ならし $O(\alpha(n))$ |
| `bool same(int x, int y)` | 同じ集合か判定 | ならし $O(\alpha(n))$ |
| `bool unite(int x, int y, T w)` | $p(y) - p(x) = w$ となるよう併合。既に同じ集合なら何もせず `false` | ならし $O(\alpha(n))$ |
| `T diff(int x, int y)` | $p(y) - p(x)$ | ならし $O(\alpha(n))$ |

## 注意

- **向きに注意**：`unite(x, y, w)` は $p(y) - p(x) = w$ を意味する。`diff(x, y)` も同じ向きで $p(y) - p(x)$ を返す。
- 既に同じ集合に属する `x, y` に対して `unite` を呼んでも、制約の矛盾チェックはしない。矛盾判定が必要なら、先に `same(x, y)` を確認して `diff(x, y) == w` かを比較すること。
- 重みは加法群（`+=`, `-=`, 単項 `-` が使える型）であればよい。
