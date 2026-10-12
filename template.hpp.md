---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/weighted_dsu.hpp
    title: "\u91CD\u307F\u4ED8\u304D Union-Find (Weighted Union-Find)"
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5 (Dijkstra)"
  - icon: ':heavy_check_mark:'
    path: graph/dsu.hpp
    title: Union-Find (Disjoint Set Union)
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: io/fastio.hpp
    title: "\u9AD8\u901F\u5165\u51FA\u529B (Fast I/O)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aplusb.test.cpp
    title: test/aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/dijkstra.test.cpp
    title: test/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/many_aplusb.test.cpp
    title: test/many_aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/many_aplusb_128bit.test.cpp
    title: test/many_aplusb_128bit.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unionfind.test.cpp
    title: test/unionfind.test.cpp
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
    \ pair<ll, ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
    #include <atcoder/all>\nusing namespace atcoder;\n#endif\n// QCfium\u6CD5\u3092\
    \u4F7F\u3046\u6642\u306F\u30B3\u30E1\u30F3\u30C8\u30A2\u30A6\u30C8\u3092\u5916\
    \u3059\n/*/\n#pragma GCC optimize(\"Ofast,unroll-loops,no-stack-protector,fast-math\"\
    )\n#pragma GCC target(\"avx2,bmi,bmi2,lzcnt,popcnt\")\n#pragma GCC target(\"avx,avx2,fma\"\
    )\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma\"\
    )\n//*/\n#define rep(i,n) for(int i=0;i<n;i++)\n#define Rep(i,a,b) for(int i=a;i<b;i++)\n\
    #define ALL(x) (x).begin(),(x).end()\n#define dbgv(x); for(auto now : x) cout\
    \ << now << \" \"; cout << endl;\n//using P = pair<int,int>;\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\ntypedef pair<int, int> pii;\ntypedef\
    \ pair<ll, ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;"
  dependsOn: []
  isVerificationFile: false
  path: template.hpp
  requiredBy:
  - graph/dsu.hpp
  - graph/dijkstra.hpp
  - graph/graph-template.hpp
  - data_structure/weighted_dsu.hpp
  - io/fastio.hpp
  timestamp: '2024-11-05 15:14:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unionfind.test.cpp
  - test/many_aplusb.test.cpp
  - test/aplusb.test.cpp
  - test/weighteddsu.test.cpp
  - test/dijkstra.test.cpp
  - test/many_aplusb_128bit.test.cpp
documentation_of: template.hpp
layout: document
title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---

## 概要

各ライブラリが `#include` する共通ヘッダ。`<bits/stdc++.h>` と `using namespace std;`、よく使うマクロ・型エイリアスを定義する。
AC Library (`<atcoder/all>`) がインクルードパスにあれば自動で読み込む（`__has_include` で判定）。

## 定義されているもの

| 名前 | 内容 |
| --- | --- |
| `rep(i, n)` | `for (int i = 0; i < n; i++)` |
| `Rep(i, a, b)` | `for (int i = a; i < b; i++)` |
| `ALL(x)` | `(x).begin(), (x).end()` |
| `dbgv(x)` | コンテナの中身を空白区切りで出力 |
| `ll`, `ull` | `long long`, `unsigned long long` |
| `pii`, `pll` | `pair<int,int>`, `pair<ll,ll>` |
| `vint`, `vll` | `vector<int>`, `vector<ll>` |

## 注意

- `#pragma GCC optimize("Ofast,...,fast-math")` / `#pragma GCC target("avx2", ...)` はコメントアウトされている（QCfium 法を使うときだけ `/*/` を `//*/` に変えて有効化する）。有効化すると `fast-math` により浮動小数点の厳密な比較・`NaN` 判定が壊れることがあるので注意。
- `#pragma once` が無いが、各ライブラリは `#pragma once` 付きでこのファイルを 1 回だけ読み込む想定。
