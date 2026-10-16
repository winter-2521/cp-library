---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/directedmst.test.cpp
    title: test/directedmst.test.cpp
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
    \ 3 \"graph/directed_mst.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u6700\u5C0F\u6709\u5411\u5168\u57DF\u6728 (\u6839 r \u304B\u3089\u5168\u9802\
    \u70B9\u306B\u5230\u9054\u3067\u304D\u308B\uFF0C\u8FBA\u306E\u91CD\u307F\u306E\
    \u548C\u304C\u6700\u5C0F\u306E\u6709\u5411\u6728)\uFF0EChu-Liu/Edmonds \u6CD5\u3092\
    \n// \u4F75\u5408\u3067\u304D\u308B\u30D2\u30FC\u30D7 (skew heap\uFF0C\u9045\u5EF6\
    \u52A0\u7B97) \u3068 Union-Find \u3067 O(m log n) \u306B\u3057\u305F\u3082\u306E\
    \ (Tarjan / Gabow \u3089)\n// \u8FD4\u308A\u5024: {\u91CD\u307F\u306E\u548C, par\
    \ (par[v] = v \u306E\u89AA\uFF0Epar[r] = r)}\uFF0E\u5230\u9054\u3067\u304D\u306A\
    \u3044\u9802\u70B9\u304C\u3042\u308C\u3070 {-1 \u76F8\u5F53, \u7A7A}\ntemplate\
    \ <class T>\npair<T, vector<int>> directed_mst(int n, const vector<tuple<int,\
    \ int, T>> &edges, int r) {\n    int m = edges.size();\n    // skew heap: \u5404\
    \u9802\u70B9\u306B\u5165\u3063\u3066\u304F\u308B\u8FBA (\u30AD\u30FC\u306F\u91CD\
    \u307F) \u3092\u5165\u308C\u308B\uFF0Elz \u306F\u90E8\u5206\u6728\u5168\u4F53\u306B\
    \u8DB3\u3059\u5024\n    vector<int> hl(m, -1), hr(m, -1);\n    vector<T> key(m),\
    \ lz(m, 0);\n    for (int i = 0; i < m; i++) key[i] = get<2>(edges[i]);\n    auto\
    \ push = [&](int x) {\n        if (lz[x] != 0) {\n            if (hl[x] >= 0)\
    \ key[hl[x]] += lz[x], lz[hl[x]] += lz[x];\n            if (hr[x] >= 0) key[hr[x]]\
    \ += lz[x], lz[hr[x]] += lz[x];\n            lz[x] = 0;\n        }\n    };\n \
    \   auto meld = [&](auto self, int a, int b) -> int {\n        if (a < 0) return\
    \ b;\n        if (b < 0) return a;\n        if (key[b] < key[a]) swap(a, b);\n\
    \        push(a);\n        hr[a] = self(self, hr[a], b);\n        swap(hl[a],\
    \ hr[a]);\n        return a;\n    };\n    auto pop = [&](int a) {\n        push(a);\n\
    \        return meld(meld, hl[a], hr[a]);\n    };\n    vector<int> heap(n, -1);\n\
    \    for (int i = 0; i < m; i++) {\n        int b = get<1>(edges[i]);\n      \
    \  if (b == r) continue;\n        hl[i] = hr[i] = -1;\n        heap[b] = meld(meld,\
    \ heap[b], i);\n    }\n    // \u7E2E\u7D04\u3092 Union-Find \u3067\u8868\u3059\
    \ (\u9802\u70B9 \u2192 \u7E2E\u7D04\u5F8C\u306E\u4EE3\u8868)\n    vector<int>\
    \ uf(2 * n, -1);\n    auto find = [&](int x) {\n        while (uf[x] >= 0) {\n\
    \            if (uf[uf[x]] >= 0) uf[x] = uf[uf[x]];\n            x = uf[x];\n\
    \        }\n        return x;\n    };\n    // \u7E2E\u7D04\u306E\u305F\u3073\u306B\
    \u65B0\u3057\u3044\u9802\u70B9 (\u756A\u53F7 n, n+1, ...) \u3092\u4F5C\u308B\uFF0E\
    par_c[x]: \u7E2E\u7D04\u9802\u70B9 x \u3092\u542B\u3080\uFF0C\u3088\u308A\u5927\
    \u304D\u3044\u7E2E\u7D04\u9802\u70B9\n    vector<int> seen(2 * n, -1), in_edge(2\
    \ * n, -1), par_c(2 * n, -1), heap2(2 * n, -1);\n    for (int v = 0; v < n; v++)\
    \ heap2[v] = heap[v];\n    int cnt = n;\n    T total = 0;\n    seen[r] = r;\n\
    \    vector<int> path;\n    for (int s = 0; s < n; s++) {\n        int v = find(s);\n\
    \        path.clear();\n        while (seen[v] < 0) {\n            seen[v] = s;\n\
    \            path.push_back(v);\n            // v \u306B\u5165\u3063\u3066\u304F\
    \u308B\u6700\u5C0F\u306E\u8FBA (\u7E2E\u7D04\u306E\u5185\u5074\u306E\u8FBA\u306F\
    \u6368\u3066\u308B)\n            while (true) {\n                if (heap2[v]\
    \ < 0) return {T(-1), {}};  // \u5230\u9054\u3067\u304D\u306A\u3044\n        \
    \        int e = heap2[v];\n                if (find(get<0>(edges[e])) == v) {\n\
    \                    heap2[v] = pop(e);\n                    continue;\n     \
    \           }\n                break;\n            }\n            int e = heap2[v];\n\
    \            in_edge[v] = e;\n            total += key[e];\n            // v \u306B\
    \u5165\u308B\u4ED6\u306E\u8FBA\u306F\uFF0C\u3053\u306E\u8FBA\u3092\u4F7F\u3063\
    \u305F\u524D\u63D0\u3067\u91CD\u307F\u3092\u5DEE\u3057\u5F15\u3044\u3066\u304A\
    \u304F (\u7E2E\u7D04\u3057\u305F\u3068\u304D\u7528)\n            T w = key[e];\n\
    \            heap2[v] = pop(e);\n            if (heap2[v] >= 0) key[heap2[v]]\
    \ -= w, lz[heap2[v]] -= w;\n            int u = find(get<0>(edges[e]));\n    \
    \        if (seen[u] == s) {\n                // \u9589\u8DEF: path \u306E u \u304B\
    \u3089 v \u307E\u3067\u3092\u65B0\u3057\u3044\u9802\u70B9 c \u306B\u7E2E\u7D04\
    \u3059\u308B\n                int c = cnt++;\n                int h = -1;\n  \
    \              while (true) {\n                    int x = path.back();\n    \
    \                path.pop_back();\n                    uf[x] = c, par_c[x] = c;\n\
    \                    if (heap2[x] >= 0) h = meld(meld, h, heap2[x]);\n       \
    \             if (x == u) break;\n                }\n                heap2[c]\
    \ = h;\n                v = c;  // seen[c] = -1 \u306A\u306E\u3067\uFF0C\u30EB\
    \u30FC\u30D7\u306E\u5148\u982D\u3067 c \u306B\u5165\u308B\u8FBA\u3092\u63A2\u3059\
    \n                continue;\n            }\n            v = u;\n        }\n  \
    \  }\n    // \u5FA9\u5143: \u7E2E\u7D04\u9802\u70B9\u3092\u65B0\u3057\u3044\u9806\
    \u306B\u898B\u308B\uFF0Ex \u306B\u5165\u308B\u8FBA e \u3092\u4F7F\u3046\u306A\u3089\
    \uFF0Ce \u306E\u884C\u304D\u5148\u306E\u5143\u306E\u9802\u70B9 b \u304B\u3089\
    \ x \u307E\u3067\u306E\u9593\u306E\u9802\u70B9\u306B\u5165\u308B\u8FBA\u306F\u4F7F\
    \u308F\u306A\u3044\n    // (\u7E2E\u7D04\u3057\u305F\u9589\u8DEF\u306E\u3046\u3061\
    \uFF0Cb \u306E\u3068\u3053\u308D\u3060\u3051\u9589\u8DEF\u306E\u8FBA\u306E\u4EE3\
    \u308F\u308A\u306B e \u304C\u5165\u308B)\n    vector<int> par(n, -1);\n    vector<char>\
    \ unused(cnt, 0);\n    par[r] = r;\n    for (int x = cnt - 1; x >= 0; x--) {\n\
    \        if (x == r || unused[x]) continue;\n        int e = in_edge[x], b = get<1>(edges[e]);\n\
    \        par[b] = get<0>(edges[e]);\n        for (int y = b; y != x; y = par_c[y])\
    \ unused[y] = 1;\n    }\n    return {total, par};\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u6700\u5C0F\u6709\u5411\u5168\u57DF\u6728 (\u6839 r \u304B\u3089\u5168\u9802\
    \u70B9\u306B\u5230\u9054\u3067\u304D\u308B\uFF0C\u8FBA\u306E\u91CD\u307F\u306E\
    \u548C\u304C\u6700\u5C0F\u306E\u6709\u5411\u6728)\uFF0EChu-Liu/Edmonds \u6CD5\u3092\
    \n// \u4F75\u5408\u3067\u304D\u308B\u30D2\u30FC\u30D7 (skew heap\uFF0C\u9045\u5EF6\
    \u52A0\u7B97) \u3068 Union-Find \u3067 O(m log n) \u306B\u3057\u305F\u3082\u306E\
    \ (Tarjan / Gabow \u3089)\n// \u8FD4\u308A\u5024: {\u91CD\u307F\u306E\u548C, par\
    \ (par[v] = v \u306E\u89AA\uFF0Epar[r] = r)}\uFF0E\u5230\u9054\u3067\u304D\u306A\
    \u3044\u9802\u70B9\u304C\u3042\u308C\u3070 {-1 \u76F8\u5F53, \u7A7A}\ntemplate\
    \ <class T>\npair<T, vector<int>> directed_mst(int n, const vector<tuple<int,\
    \ int, T>> &edges, int r) {\n    int m = edges.size();\n    // skew heap: \u5404\
    \u9802\u70B9\u306B\u5165\u3063\u3066\u304F\u308B\u8FBA (\u30AD\u30FC\u306F\u91CD\
    \u307F) \u3092\u5165\u308C\u308B\uFF0Elz \u306F\u90E8\u5206\u6728\u5168\u4F53\u306B\
    \u8DB3\u3059\u5024\n    vector<int> hl(m, -1), hr(m, -1);\n    vector<T> key(m),\
    \ lz(m, 0);\n    for (int i = 0; i < m; i++) key[i] = get<2>(edges[i]);\n    auto\
    \ push = [&](int x) {\n        if (lz[x] != 0) {\n            if (hl[x] >= 0)\
    \ key[hl[x]] += lz[x], lz[hl[x]] += lz[x];\n            if (hr[x] >= 0) key[hr[x]]\
    \ += lz[x], lz[hr[x]] += lz[x];\n            lz[x] = 0;\n        }\n    };\n \
    \   auto meld = [&](auto self, int a, int b) -> int {\n        if (a < 0) return\
    \ b;\n        if (b < 0) return a;\n        if (key[b] < key[a]) swap(a, b);\n\
    \        push(a);\n        hr[a] = self(self, hr[a], b);\n        swap(hl[a],\
    \ hr[a]);\n        return a;\n    };\n    auto pop = [&](int a) {\n        push(a);\n\
    \        return meld(meld, hl[a], hr[a]);\n    };\n    vector<int> heap(n, -1);\n\
    \    for (int i = 0; i < m; i++) {\n        int b = get<1>(edges[i]);\n      \
    \  if (b == r) continue;\n        hl[i] = hr[i] = -1;\n        heap[b] = meld(meld,\
    \ heap[b], i);\n    }\n    // \u7E2E\u7D04\u3092 Union-Find \u3067\u8868\u3059\
    \ (\u9802\u70B9 \u2192 \u7E2E\u7D04\u5F8C\u306E\u4EE3\u8868)\n    vector<int>\
    \ uf(2 * n, -1);\n    auto find = [&](int x) {\n        while (uf[x] >= 0) {\n\
    \            if (uf[uf[x]] >= 0) uf[x] = uf[uf[x]];\n            x = uf[x];\n\
    \        }\n        return x;\n    };\n    // \u7E2E\u7D04\u306E\u305F\u3073\u306B\
    \u65B0\u3057\u3044\u9802\u70B9 (\u756A\u53F7 n, n+1, ...) \u3092\u4F5C\u308B\uFF0E\
    par_c[x]: \u7E2E\u7D04\u9802\u70B9 x \u3092\u542B\u3080\uFF0C\u3088\u308A\u5927\
    \u304D\u3044\u7E2E\u7D04\u9802\u70B9\n    vector<int> seen(2 * n, -1), in_edge(2\
    \ * n, -1), par_c(2 * n, -1), heap2(2 * n, -1);\n    for (int v = 0; v < n; v++)\
    \ heap2[v] = heap[v];\n    int cnt = n;\n    T total = 0;\n    seen[r] = r;\n\
    \    vector<int> path;\n    for (int s = 0; s < n; s++) {\n        int v = find(s);\n\
    \        path.clear();\n        while (seen[v] < 0) {\n            seen[v] = s;\n\
    \            path.push_back(v);\n            // v \u306B\u5165\u3063\u3066\u304F\
    \u308B\u6700\u5C0F\u306E\u8FBA (\u7E2E\u7D04\u306E\u5185\u5074\u306E\u8FBA\u306F\
    \u6368\u3066\u308B)\n            while (true) {\n                if (heap2[v]\
    \ < 0) return {T(-1), {}};  // \u5230\u9054\u3067\u304D\u306A\u3044\n        \
    \        int e = heap2[v];\n                if (find(get<0>(edges[e])) == v) {\n\
    \                    heap2[v] = pop(e);\n                    continue;\n     \
    \           }\n                break;\n            }\n            int e = heap2[v];\n\
    \            in_edge[v] = e;\n            total += key[e];\n            // v \u306B\
    \u5165\u308B\u4ED6\u306E\u8FBA\u306F\uFF0C\u3053\u306E\u8FBA\u3092\u4F7F\u3063\
    \u305F\u524D\u63D0\u3067\u91CD\u307F\u3092\u5DEE\u3057\u5F15\u3044\u3066\u304A\
    \u304F (\u7E2E\u7D04\u3057\u305F\u3068\u304D\u7528)\n            T w = key[e];\n\
    \            heap2[v] = pop(e);\n            if (heap2[v] >= 0) key[heap2[v]]\
    \ -= w, lz[heap2[v]] -= w;\n            int u = find(get<0>(edges[e]));\n    \
    \        if (seen[u] == s) {\n                // \u9589\u8DEF: path \u306E u \u304B\
    \u3089 v \u307E\u3067\u3092\u65B0\u3057\u3044\u9802\u70B9 c \u306B\u7E2E\u7D04\
    \u3059\u308B\n                int c = cnt++;\n                int h = -1;\n  \
    \              while (true) {\n                    int x = path.back();\n    \
    \                path.pop_back();\n                    uf[x] = c, par_c[x] = c;\n\
    \                    if (heap2[x] >= 0) h = meld(meld, h, heap2[x]);\n       \
    \             if (x == u) break;\n                }\n                heap2[c]\
    \ = h;\n                v = c;  // seen[c] = -1 \u306A\u306E\u3067\uFF0C\u30EB\
    \u30FC\u30D7\u306E\u5148\u982D\u3067 c \u306B\u5165\u308B\u8FBA\u3092\u63A2\u3059\
    \n                continue;\n            }\n            v = u;\n        }\n  \
    \  }\n    // \u5FA9\u5143: \u7E2E\u7D04\u9802\u70B9\u3092\u65B0\u3057\u3044\u9806\
    \u306B\u898B\u308B\uFF0Ex \u306B\u5165\u308B\u8FBA e \u3092\u4F7F\u3046\u306A\u3089\
    \uFF0Ce \u306E\u884C\u304D\u5148\u306E\u5143\u306E\u9802\u70B9 b \u304B\u3089\
    \ x \u307E\u3067\u306E\u9593\u306E\u9802\u70B9\u306B\u5165\u308B\u8FBA\u306F\u4F7F\
    \u308F\u306A\u3044\n    // (\u7E2E\u7D04\u3057\u305F\u9589\u8DEF\u306E\u3046\u3061\
    \uFF0Cb \u306E\u3068\u3053\u308D\u3060\u3051\u9589\u8DEF\u306E\u8FBA\u306E\u4EE3\
    \u308F\u308A\u306B e \u304C\u5165\u308B)\n    vector<int> par(n, -1);\n    vector<char>\
    \ unused(cnt, 0);\n    par[r] = r;\n    for (int x = cnt - 1; x >= 0; x--) {\n\
    \        if (x == r || unused[x]) continue;\n        int e = in_edge[x], b = get<1>(edges[e]);\n\
    \        par[b] = get<0>(edges[e]);\n        for (int y = b; y != x; y = par_c[y])\
    \ unused[y] = 1;\n    }\n    return {total, par};\n}\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/directed_mst.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/unittest/graph_optimization.test.cpp
  - test/directedmst.test.cpp
documentation_of: graph/directed_mst.hpp
layout: document
title: "\u6700\u5C0F\u6709\u5411\u5168\u57DF\u6728 (Directed MST)"
---

## 概要

有向グラフと根 $r$ について、$r$ から全頂点へ到達できる有向木（全域アーボレセンス）のうち辺の重みの和が最小のものを求める。$O(m \log n)$。

Chu-Liu/Edmonds 法：各頂点に入る最小の辺を選び、閉路ができたら縮約して「その閉路に入る辺の重みから、閉路内で選んだ辺の重みを引く」。素朴には $O(nm)$ だが、各頂点に入る辺を**遅延加算つき skew heap** に入れ、縮約をヒープの併合と Union-Find で表すと $O(m \log n)$ になる。最後に縮約を新しい順にほどいて親を復元する。

## 使い方

```cpp
vector<tuple<int, int, long long>> edges;   // (from, to, 重み)
auto [w, par] = directed_mst(n, edges, r);  // par[v] = v の親, par[r] = r
if (par.empty()) { /* 到達できない頂点がある */ }
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `pair<T, vector<int>> directed_mst(int n, edges, int r)` | 重みの和と親の配列 | $O(m \log n)$ |

## 注意

- 根から到達できない頂点があると `{-1, {}}` を返す（`par` が空かどうかで判定する）。
- 負の重みがあってもよい。
