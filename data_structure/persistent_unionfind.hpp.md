---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/persistent_array.hpp
    title: "\u6C38\u7D9A\u914D\u5217 (Persistent Array)"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/persistent_unionfind.test.cpp
    title: test/persistent_unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/persistent.test.cpp
    title: test/unittest/persistent.test.cpp
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
    \ 3 \"data_structure/persistent_array.hpp\"\n\n// \u6C38\u7D9A\u914D\u5217 (Persistent\
    \ Array)\uFF0E\u3069\u306E\u7248\u304B\u3089\u3067\u3082\u4E00\u70B9\u66F4\u65B0\
    \u3067\u304D\uFF0C\u65B0\u3057\u3044\u7248\u306E\u756A\u53F7\u3092\u8FD4\u3059\
    \n// 2^LOG \u5206\u6728\u3067\u6301\u3061\uFF0C\u66F4\u65B0\u306F\u6839\u304B\u3089\
    \u8449\u307E\u3067\u306E\u9053\u306E\u30CE\u30FC\u30C9\u3060\u3051\u3092\u8907\
    \u88FD\u3059\u308B (path copying)\n// \u53D6\u5F97\u30FB\u66F4\u65B0 O(log_{2^LOG}\
    \ n)\uFF0E\u66F4\u65B0\u3054\u3068\u306B O(2^LOG log_{2^LOG} n) \u306E\u30E1\u30E2\
    \u30EA\ntemplate <class T, int LOG = 3>\nstruct PersistentArray {\n    static\
    \ constexpr int K = 1 << LOG;\n    int n, height;\n    vector<array<int, K>> ch;\
    \   // \u5185\u90E8\u30CE\u30FC\u30C9\u306E\u5B50 (ch \u306E\u30CE\u30FC\u30C9\
    \u756A\u53F7\uFF0C\u8449\u306E\u6BB5\u3067\u306F vals \u306E\u756A\u53F7)\n  \
    \  vector<T> vals;              // \u8449\u306E\u5024\n    vector<int> roots;\
    \           // \u7248\u3054\u3068\u306E\u6839\n\n    PersistentArray(const vector<T>\
    \ &a = {}) : n(a.size()) {\n        height = 0;\n        while ((1LL << (LOG *\
    \ height)) < std::max(n, 1)) height++;\n        vals = a;\n        if (vals.empty())\
    \ vals.push_back(T());\n        roots.push_back(build(0, height));\n    }\n\n\
    \    PersistentArray(int n, const T &x) : PersistentArray(vector<T>(n, x)) {}\n\
    \n    void reserve(int updates) {\n        ch.reserve(ch.size() + (size_t)updates\
    \ * height);\n        vals.reserve(vals.size() + updates);\n        roots.reserve(roots.size()\
    \ + updates);\n    }\n\n    int size() const { return n; }\n    int versions()\
    \ const { return roots.size(); }\n\n    // \u7248 v \u306E a[i]\n    T get(int\
    \ v, int i) const {\n        int t = roots[v];\n        for (int h = height -\
    \ 1; h >= 0; h--) t = ch[t][(i >> (LOG * h)) & (K - 1)];\n        return vals[t];\n\
    \    }\n\n    // \u7248 v \u306E a[i] \u3092 x \u306B\u3057\u305F\u7248\u3092\u4F5C\
    \u308A\uFF0C\u305D\u306E\u756A\u53F7\u3092\u8FD4\u3059\n    int set(int v, int\
    \ i, const T &x) {\n        vals.push_back(x);\n        int leaf = vals.size()\
    \ - 1;\n        if (height == 0) {\n            roots.push_back(leaf);\n     \
    \       return roots.size() - 1;\n        }\n        roots.push_back(set_rec(roots[v],\
    \ height - 1, i, leaf));\n        return roots.size() - 1;\n    }\n\n  private:\n\
    \    // \u6BB5 h (h = height \u306A\u3089\u6839) \u304B\u3089\u4E0B\u306E\uFF0C\
    \u5148\u982D lo \u306E\u90E8\u5206\u3092\u4F5C\u308B\uFF0E\u8449\u306E\u6BB5\u306A\
    \u3089 vals \u306E\u756A\u53F7\u3092\u8FD4\u3059\n    int build(int lo, int h)\
    \ {\n        if (h == 0) return std::min(lo, (int)vals.size() - 1);\n        array<int,\
    \ K> c;\n        long long w = 1LL << (LOG * (h - 1));\n        for (int k = 0;\
    \ k < K; k++) c[k] = build(std::min<long long>(lo + w * k, std::max(n - 1, 0)),\
    \ h - 1);\n        ch.push_back(c);\n        return ch.size() - 1;\n    }\n\n\
    \    int set_rec(int t, int h, int i, int leaf) {\n        array<int, K> c = ch[t];\n\
    \        int k = (i >> (LOG * h)) & (K - 1);\n        c[k] = h == 0 ? leaf : set_rec(c[k],\
    \ h - 1, i, leaf);\n        ch.push_back(c);\n        return ch.size() - 1;\n\
    \    }\n};\n#line 4 \"data_structure/persistent_unionfind.hpp\"\n\n// \u6C38\u7D9A\
    \ Union-Find (Persistent Union-Find)\uFF0E\u3069\u306E\u7248\u306B\u3082\u8FBA\
    \u3092\u8DB3\u305B\u3066\uFF0C\u65B0\u3057\u3044\u7248\u306E\u756A\u53F7\u3092\
    \u8FD4\u3059 (\u30AA\u30F3\u30E9\u30A4\u30F3)\n// \u89AA\u306E\u914D\u5217\u3092\
    \u6C38\u7D9A\u914D\u5217\u3067\u6301\u3061\uFF0C\u7D4C\u8DEF\u5727\u7E2E\u306F\
    \u305B\u305A\u306B union by size \u3060\u3051\u884C\u3046 (\u6728\u306E\u9AD8\u3055\
    \ O(log n))\n// par[x] < 0 \u306A\u3089 x \u306F\u6839\u3067 -par[x] \u304C\u305D\
    \u306E\u9023\u7D50\u6210\u5206\u306E\u5927\u304D\u3055\n// find O(log n \xB7 log_8\
    \ n)\uFF0Cunite O(log n \xB7 log_8 n)\nstruct PersistentUnionFind {\n    PersistentArray<int,\
    \ 3> par;\n\n    PersistentUnionFind(int n = 0) : par(n, -1) {}\n\n    void reserve(int\
    \ q) { par.reserve(2 * q); }\n\n    // \u521D\u671F\u72B6\u614B (\u8FBA\u306A\u3057\
    ) \u306E\u7248\u306E\u756A\u53F7\n    static constexpr int initial_version() {\
    \ return 0; }\n\n    // \u7248 v \u3067\u306E x \u306E\u6839\n    int leader(int\
    \ v, int x) const {\n        while (true) {\n            int p = par.get(v, x);\n\
    \            if (p < 0) return x;\n            x = p;\n        }\n    }\n\n  \
    \  bool same(int v, int x, int y) const { return leader(v, x) == leader(v, y);\
    \ }\n\n    // \u7248 v \u306E x \u3092\u542B\u3080\u9023\u7D50\u6210\u5206\u306E\
    \u5927\u304D\u3055\n    int size(int v, int x) const { return -par.get(v, leader(v,\
    \ x)); }\n\n    // \u7248 v \u306B\u8FBA (x, y) \u3092\u8DB3\u3057\u305F\u7248\
    \u3092\u4F5C\u308A\uFF0C\u305D\u306E\u756A\u53F7\u3092\u8FD4\u3059 (\u3059\u3067\
    \u306B\u9023\u7D50\u3067\u3082\u65B0\u3057\u3044\u7248\u3092\u4F5C\u308B)\n  \
    \  int merge(int v, int x, int y) {\n        x = leader(v, x), y = leader(v, y);\n\
    \        if (x == y) return par.set(v, x, par.get(v, x));\n        int sx = -par.get(v,\
    \ x), sy = -par.get(v, y);\n        if (sx < sy) swap(x, y), swap(sx, sy);\n \
    \       int w = par.set(v, x, -(sx + sy));\n        return par.set(w, y, x);\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"persistent_array.hpp\"\
    \n\n// \u6C38\u7D9A Union-Find (Persistent Union-Find)\uFF0E\u3069\u306E\u7248\
    \u306B\u3082\u8FBA\u3092\u8DB3\u305B\u3066\uFF0C\u65B0\u3057\u3044\u7248\u306E\
    \u756A\u53F7\u3092\u8FD4\u3059 (\u30AA\u30F3\u30E9\u30A4\u30F3)\n// \u89AA\u306E\
    \u914D\u5217\u3092\u6C38\u7D9A\u914D\u5217\u3067\u6301\u3061\uFF0C\u7D4C\u8DEF\
    \u5727\u7E2E\u306F\u305B\u305A\u306B union by size \u3060\u3051\u884C\u3046 (\u6728\
    \u306E\u9AD8\u3055 O(log n))\n// par[x] < 0 \u306A\u3089 x \u306F\u6839\u3067\
    \ -par[x] \u304C\u305D\u306E\u9023\u7D50\u6210\u5206\u306E\u5927\u304D\u3055\n\
    // find O(log n \xB7 log_8 n)\uFF0Cunite O(log n \xB7 log_8 n)\nstruct PersistentUnionFind\
    \ {\n    PersistentArray<int, 3> par;\n\n    PersistentUnionFind(int n = 0) :\
    \ par(n, -1) {}\n\n    void reserve(int q) { par.reserve(2 * q); }\n\n    // \u521D\
    \u671F\u72B6\u614B (\u8FBA\u306A\u3057) \u306E\u7248\u306E\u756A\u53F7\n    static\
    \ constexpr int initial_version() { return 0; }\n\n    // \u7248 v \u3067\u306E\
    \ x \u306E\u6839\n    int leader(int v, int x) const {\n        while (true) {\n\
    \            int p = par.get(v, x);\n            if (p < 0) return x;\n      \
    \      x = p;\n        }\n    }\n\n    bool same(int v, int x, int y) const {\
    \ return leader(v, x) == leader(v, y); }\n\n    // \u7248 v \u306E x \u3092\u542B\
    \u3080\u9023\u7D50\u6210\u5206\u306E\u5927\u304D\u3055\n    int size(int v, int\
    \ x) const { return -par.get(v, leader(v, x)); }\n\n    // \u7248 v \u306B\u8FBA\
    \ (x, y) \u3092\u8DB3\u3057\u305F\u7248\u3092\u4F5C\u308A\uFF0C\u305D\u306E\u756A\
    \u53F7\u3092\u8FD4\u3059 (\u3059\u3067\u306B\u9023\u7D50\u3067\u3082\u65B0\u3057\
    \u3044\u7248\u3092\u4F5C\u308B)\n    int merge(int v, int x, int y) {\n      \
    \  x = leader(v, x), y = leader(v, y);\n        if (x == y) return par.set(v,\
    \ x, par.get(v, x));\n        int sx = -par.get(v, x), sy = -par.get(v, y);\n\
    \        if (sx < sy) swap(x, y), swap(sx, sy);\n        int w = par.set(v, x,\
    \ -(sx + sy));\n        return par.set(w, y, x);\n    }\n};\n"
  dependsOn:
  - template.hpp
  - data_structure/persistent_array.hpp
  isVerificationFile: false
  path: data_structure/persistent_unionfind.hpp
  requiredBy: []
  timestamp: '2026-10-15 00:08:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/persistent_unionfind.test.cpp
  - test/unittest/persistent.test.cpp
documentation_of: data_structure/persistent_unionfind.hpp
layout: document
title: "\u6C38\u7D9A Union-Find (Persistent Union-Find)"
---

## 概要

Union-Find の **どの過去の版にも** 辺を足して新しい版を作れる（オンライン）。

親の配列を [永続配列](persistent_array.hpp) で持つ。経路圧縮は（過去の版を書き換えてしまうので）使わず、union by size だけで木の高さを $O(\log n)$ に抑える。

## 使い方

```cpp
PersistentUnionFind uf(n);
uf.reserve(q);
int v0 = uf.initial_version();   // 辺なし
int v1 = uf.merge(v0, a, b);     // 版 v0 に辺 (a, b) を足した版
uf.same(v1, a, b);               // true
uf.same(v0, a, b);               // false (古い版はそのまま)
uf.leader(v1, a); uf.size(v1, a);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `int merge(int v, int x, int y)` | 版 $v$ に辺を足した版 | $O(\log n \cdot \log_8 n)$ |
| `bool same(int v, int x, int y)` | 版 $v$ で連結か | $O(\log n \cdot \log_8 n)$ |
| `int leader(int v, int x)` / `int size(int v, int x)` | 根 / 連結成分の大きさ | $O(\log n \cdot \log_8 n)$ |

## 注意

- `merge` は内部で永続配列を 2 回更新するので、版の番号は連番にならない。返り値の番号をそのまま使うこと。
- クエリを先読みできるなら、版の木を DFS しながら undo 付き Union-Find で処理するオフライン解法の方がメモリが少ない。
