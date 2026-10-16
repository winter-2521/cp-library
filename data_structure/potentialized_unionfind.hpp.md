---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/unionfind_with_potential.test.cpp
    title: test/unionfind_with_potential.test.cpp
  - icon: ':x:'
    path: test/unionfind_with_potential_non_commutative_group.test.cpp
    title: test/unionfind_with_potential_non_commutative_group.test.cpp
  - icon: ':x:'
    path: test/unittest/modint.test.cpp
    title: test/unittest/modint.test.cpp
  - icon: ':x:'
    path: test/unittest/potentialized_unionfind.test.cpp
    title: test/unittest/potentialized_unionfind.test.cpp
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
    \ 3 \"data_structure/potentialized_unionfind.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union-Find\n// \u5404\u8981\
    \u7D20 u \u306B\u7FA4 G \u306E\u5143 a_u \u3092\u6301\u305F\u305B\uFF0C\u300C\
    a_u = a_v w\u300D\u3068\u3044\u3046\u95A2\u4FC2\u3092\u8FFD\u52A0\u30FB\u77DB\u76FE\
    \u5224\u5B9A\u3057\uFF0Ca_v^{-1} a_u \u3092\u53D6\u5F97\u3059\u308B\n// G \u306F\
    \u975E\u53EF\u63DB\u7FA4\u3067\u3082\u3088\u3044\uFF0E\u52A0\u6CD5\u7FA4\u306A\
    \u3089\u300Ca_u - a_v = w\u300D\u3068\u3044\u3046\u610F\u5473\u306B\u306A\u308B\
    \ (Library Checker \u3068\u540C\u3058\u5411\u304D)\n//\n// G \u306B\u306F\u6B21\
    \u3092\u5B9A\u7FA9\u3059\u308B:\n//   using T = \u7FA4\u306E\u5143\u306E\u578B\
    ;\n//   static T op(const T &a, const T &b);  // \u7FA4\u6F14\u7B97 a * b\n//\
    \   static T inv(const T &a);             // \u9006\u5143\n//   static T e();\
    \                         // \u5358\u4F4D\u5143\n// T \u306F == \u3067\u6BD4\u8F03\
    \u3067\u304D\u308B\u3053\u3068\ntemplate <class G>\nstruct PotentializedUnionFind\
    \ {\n    using T = typename G::T;\n    // \u6839\u306A\u3089 -(\u96C6\u5408\u306E\
    \u30B5\u30A4\u30BA)\uFF0C\u305D\u3046\u3067\u306A\u3051\u308C\u3070\u89AA\n  \
    \  vector<int> par;\n    // pot[x] = a_{par[x]}^{-1} a_x  (\u6839\u306A\u3089\u5358\
    \u4F4D\u5143)\n    vector<T> pot;\n\n    PotentializedUnionFind(int n = 0) : par(n,\
    \ -1), pot(n, G::e()) {}\n\n    // \u6839\u3092\u8FD4\u3059\uFF0E\u7D4C\u8DEF\u5727\
    \u7E2E\u306E\u3064\u3044\u3067\u306B pot[x] \u3092\u6839\u304B\u3089\u306E\u5024\
    \u306B\u66F4\u65B0\u3059\u308B\n    int leader(int x) {\n        if (par[x] <\
    \ 0) return x;\n        int p = par[x];\n        int r = leader(p);\n        //\
    \ pot[p] \u306F a_r^{-1} a_p \u306B\u306A\u3063\u3066\u3044\u308B\n        if\
    \ (p != r) pot[x] = G::op(pot[p], pot[x]);\n        return par[x] = r;\n    }\n\
    \n    bool same(int x, int y) { return leader(x) == leader(y); }\n\n    int size(int\
    \ x) { return -par[leader(x)]; }\n\n    // a_r^{-1} a_x  (r \u306F x \u306E\u5C5E\
    \u3059\u308B\u96C6\u5408\u306E\u6839)\n    T potential(int x) {\n        leader(x);\n\
    \        return pot[x];\n    }\n\n    // a_v^{-1} a_u (\u52A0\u6CD5\u7FA4\u306A\
    \u3089 a_u - a_v)\uFF0E\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\
    \u3053\u3068\n    T diff(int u, int v) {\n        assert(same(u, v));\n      \
    \  return G::op(G::inv(potential(v)), potential(u));\n    }\n\n    // a_u = a_v\
    \ w (\u52A0\u6CD5\u7FA4\u306A\u3089 a_u - a_v = w) \u3068\u3044\u3046\u95A2\u4FC2\
    \u3092\u8FFD\u52A0\u3059\u308B\n    // \u3053\u308C\u307E\u3067\u306E\u95A2\u4FC2\
    \u3068\u77DB\u76FE\u3059\u308B\u306A\u3089\u4F55\u3082\u305B\u305A false\uFF0C\
    \u77DB\u76FE\u3057\u306A\u3051\u308C\u3070 true (\u65E2\u306B\u5206\u304B\u3063\
    \u3066\u3044\u305F\u95A2\u4FC2\u3067\u3082 true)\n    bool merge(int u, int v,\
    \ T w) {\n        // \u4EE5\u4E0B\u3067\u306F x = v, y = u \u3068\u3057\u3066\
    \ a_x^{-1} a_y = w \u3092\u6271\u3046\n        int x = v, y = u;\n        int\
    \ rx = leader(x), ry = leader(y);\n        const T &px = pot[x], &py = pot[y];\n\
    \        if (rx == ry) return G::op(G::inv(px), py) == w;\n        // a_x = a_rx\
    \ px, a_y = a_ry py, a_y = a_x w \u3088\u308A a_rx^{-1} a_ry = px w py^{-1}\n\
    \        T d = G::op(G::op(px, w), G::inv(py));\n        if (par[rx] > par[ry])\
    \ {\n            // rx \u306E\u65B9\u304C\u5C0F\u3055\u3044\u306E\u3067 ry \u306E\
    \u4E0B\u306B\u3064\u3051\u308B\n            par[ry] += par[rx];\n            par[rx]\
    \ = ry;\n            pot[rx] = G::inv(d);\n        } else {\n            par[rx]\
    \ += par[ry];\n            par[ry] = rx;\n            pot[ry] = d;\n        }\n\
    \        return true;\n    }\n\n    // \u96C6\u5408\u3054\u3068\u306B\u8981\u7D20\
    \u3092\u5217\u6319\n    vector<vector<int>> groups() {\n        int n = par.size();\n\
    \        vector<vector<int>> res(n);\n        for (int i = 0; i < n; i++) res[leader(i)].push_back(i);\n\
    \        res.erase(remove_if(res.begin(), res.end(), [](const vector<int> &v)\
    \ { return v.empty(); }), res.end());\n        return res;\n    }\n};\n\n// \u52A0\
    \u6CD5\u7FA4 (a_u - a_v = w)\ntemplate <class X>\nstruct AdditiveGroup {\n   \
    \ using T = X;\n    static T op(const T &a, const T &b) { return a + b; }\n  \
    \  static T inv(const T &a) { return -a; }\n    static T e() { return T(0); }\n\
    };\n\n// xor \u306E\u7FA4 (a_u xor a_v = w)\uFF0E\u5076\u5947\u306E\u5236\u7D04\
    \u306A\u3069\u306B\u4F7F\u3046\ntemplate <class X>\nstruct XorGroup {\n    using\
    \ T = X;\n    static T op(const T &a, const T &b) { return a ^ b; }\n    static\
    \ T inv(const T &a) { return a; }\n    static T e() { return T(0); }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union-Find\n// \u5404\u8981\
    \u7D20 u \u306B\u7FA4 G \u306E\u5143 a_u \u3092\u6301\u305F\u305B\uFF0C\u300C\
    a_u = a_v w\u300D\u3068\u3044\u3046\u95A2\u4FC2\u3092\u8FFD\u52A0\u30FB\u77DB\u76FE\
    \u5224\u5B9A\u3057\uFF0Ca_v^{-1} a_u \u3092\u53D6\u5F97\u3059\u308B\n// G \u306F\
    \u975E\u53EF\u63DB\u7FA4\u3067\u3082\u3088\u3044\uFF0E\u52A0\u6CD5\u7FA4\u306A\
    \u3089\u300Ca_u - a_v = w\u300D\u3068\u3044\u3046\u610F\u5473\u306B\u306A\u308B\
    \ (Library Checker \u3068\u540C\u3058\u5411\u304D)\n//\n// G \u306B\u306F\u6B21\
    \u3092\u5B9A\u7FA9\u3059\u308B:\n//   using T = \u7FA4\u306E\u5143\u306E\u578B\
    ;\n//   static T op(const T &a, const T &b);  // \u7FA4\u6F14\u7B97 a * b\n//\
    \   static T inv(const T &a);             // \u9006\u5143\n//   static T e();\
    \                         // \u5358\u4F4D\u5143\n// T \u306F == \u3067\u6BD4\u8F03\
    \u3067\u304D\u308B\u3053\u3068\ntemplate <class G>\nstruct PotentializedUnionFind\
    \ {\n    using T = typename G::T;\n    // \u6839\u306A\u3089 -(\u96C6\u5408\u306E\
    \u30B5\u30A4\u30BA)\uFF0C\u305D\u3046\u3067\u306A\u3051\u308C\u3070\u89AA\n  \
    \  vector<int> par;\n    // pot[x] = a_{par[x]}^{-1} a_x  (\u6839\u306A\u3089\u5358\
    \u4F4D\u5143)\n    vector<T> pot;\n\n    PotentializedUnionFind(int n = 0) : par(n,\
    \ -1), pot(n, G::e()) {}\n\n    // \u6839\u3092\u8FD4\u3059\uFF0E\u7D4C\u8DEF\u5727\
    \u7E2E\u306E\u3064\u3044\u3067\u306B pot[x] \u3092\u6839\u304B\u3089\u306E\u5024\
    \u306B\u66F4\u65B0\u3059\u308B\n    int leader(int x) {\n        if (par[x] <\
    \ 0) return x;\n        int p = par[x];\n        int r = leader(p);\n        //\
    \ pot[p] \u306F a_r^{-1} a_p \u306B\u306A\u3063\u3066\u3044\u308B\n        if\
    \ (p != r) pot[x] = G::op(pot[p], pot[x]);\n        return par[x] = r;\n    }\n\
    \n    bool same(int x, int y) { return leader(x) == leader(y); }\n\n    int size(int\
    \ x) { return -par[leader(x)]; }\n\n    // a_r^{-1} a_x  (r \u306F x \u306E\u5C5E\
    \u3059\u308B\u96C6\u5408\u306E\u6839)\n    T potential(int x) {\n        leader(x);\n\
    \        return pot[x];\n    }\n\n    // a_v^{-1} a_u (\u52A0\u6CD5\u7FA4\u306A\
    \u3089 a_u - a_v)\uFF0E\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\
    \u3053\u3068\n    T diff(int u, int v) {\n        assert(same(u, v));\n      \
    \  return G::op(G::inv(potential(v)), potential(u));\n    }\n\n    // a_u = a_v\
    \ w (\u52A0\u6CD5\u7FA4\u306A\u3089 a_u - a_v = w) \u3068\u3044\u3046\u95A2\u4FC2\
    \u3092\u8FFD\u52A0\u3059\u308B\n    // \u3053\u308C\u307E\u3067\u306E\u95A2\u4FC2\
    \u3068\u77DB\u76FE\u3059\u308B\u306A\u3089\u4F55\u3082\u305B\u305A false\uFF0C\
    \u77DB\u76FE\u3057\u306A\u3051\u308C\u3070 true (\u65E2\u306B\u5206\u304B\u3063\
    \u3066\u3044\u305F\u95A2\u4FC2\u3067\u3082 true)\n    bool merge(int u, int v,\
    \ T w) {\n        // \u4EE5\u4E0B\u3067\u306F x = v, y = u \u3068\u3057\u3066\
    \ a_x^{-1} a_y = w \u3092\u6271\u3046\n        int x = v, y = u;\n        int\
    \ rx = leader(x), ry = leader(y);\n        const T &px = pot[x], &py = pot[y];\n\
    \        if (rx == ry) return G::op(G::inv(px), py) == w;\n        // a_x = a_rx\
    \ px, a_y = a_ry py, a_y = a_x w \u3088\u308A a_rx^{-1} a_ry = px w py^{-1}\n\
    \        T d = G::op(G::op(px, w), G::inv(py));\n        if (par[rx] > par[ry])\
    \ {\n            // rx \u306E\u65B9\u304C\u5C0F\u3055\u3044\u306E\u3067 ry \u306E\
    \u4E0B\u306B\u3064\u3051\u308B\n            par[ry] += par[rx];\n            par[rx]\
    \ = ry;\n            pot[rx] = G::inv(d);\n        } else {\n            par[rx]\
    \ += par[ry];\n            par[ry] = rx;\n            pot[ry] = d;\n        }\n\
    \        return true;\n    }\n\n    // \u96C6\u5408\u3054\u3068\u306B\u8981\u7D20\
    \u3092\u5217\u6319\n    vector<vector<int>> groups() {\n        int n = par.size();\n\
    \        vector<vector<int>> res(n);\n        for (int i = 0; i < n; i++) res[leader(i)].push_back(i);\n\
    \        res.erase(remove_if(res.begin(), res.end(), [](const vector<int> &v)\
    \ { return v.empty(); }), res.end());\n        return res;\n    }\n};\n\n// \u52A0\
    \u6CD5\u7FA4 (a_u - a_v = w)\ntemplate <class X>\nstruct AdditiveGroup {\n   \
    \ using T = X;\n    static T op(const T &a, const T &b) { return a + b; }\n  \
    \  static T inv(const T &a) { return -a; }\n    static T e() { return T(0); }\n\
    };\n\n// xor \u306E\u7FA4 (a_u xor a_v = w)\uFF0E\u5076\u5947\u306E\u5236\u7D04\
    \u306A\u3069\u306B\u4F7F\u3046\ntemplate <class X>\nstruct XorGroup {\n    using\
    \ T = X;\n    static T op(const T &a, const T &b) { return a ^ b; }\n    static\
    \ T inv(const T &a) { return a; }\n    static T e() { return T(0); }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/potentialized_unionfind.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unionfind_with_potential_non_commutative_group.test.cpp
  - test/unittest/modint.test.cpp
  - test/unittest/potentialized_unionfind.test.cpp
  - test/unionfind_with_potential.test.cpp
documentation_of: data_structure/potentialized_unionfind.hpp
layout: document
title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union-Find (\u975E\u53EF\u63DB\
  \u7FA4\u5BFE\u5FDC)"
---

## 概要

各要素 $u$ に群 $G$ の元 $a_u$ を持たせ、「$a_u = a_v w$」という関係の追加・矛盾判定と、同じ集合に属する 2 要素の $a_v^{-1} a_u$ の取得を行う。
$G$ は **非可換群でもよい**。加法群なら「$a_u - a_v = w$」、xor なら「$a_u \oplus a_v = w$」という意味になる。向きは Library Checker と同じ。

union by size と経路圧縮を併用している。頂点は 0-indexed。
[`weighted_dsu.hpp`](weighted_dsu.hpp) と違い、矛盾判定を `merge` の戻り値で返し、群を自由に差し替えられる。

## 使い方

```cpp
PotentializedUnionFind<AdditiveGroup<long long>> uf(n);
uf.merge(u, v, w);   // a_u = a_v w (加法なら a_u - a_v = w) を追加．矛盾したら false (状態は変わらない)
uf.same(u, v);
uf.diff(u, v);       // a_v^{-1} a_u (加法なら a_u - a_v)．同じ集合のときのみ
uf.potential(x);     // a_r^{-1} a_x (r は x の集合の根)
uf.size(x); uf.leader(x); uf.groups();

// 群を自作する場合 (例: 2x2 行列の積)
struct G {
    using T = array<mint, 4>;
    static T op(const T &a, const T &b);  // a * b
    static T inv(const T &a);             // 逆元
    static T e();                         // 単位元
};
PotentializedUnionFind<G> uf2(n);
```

用意してある群: `AdditiveGroup<X>`（加法、modint も可）、`XorGroup<X>`（xor）。

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `PotentializedUnionFind<G>(int n)` | 要素数 `n` で初期化 | $O(n)$ |
| `bool merge(int u, int v, T w)` | $a_u = a_v w$ を追加。矛盾すれば何もせず `false`、そうでなければ `true`（既知の関係でも `true`） | ならし $O(\alpha(n))$ |
| `T diff(int u, int v)` | $a_v^{-1} a_u$（加法なら $a_u - a_v$）。`same(u, v)` であること | ならし $O(\alpha(n))$ |
| `T potential(int x)` | $a_r^{-1} a_x$（$r$ は根） | ならし $O(\alpha(n))$ |
| `int leader(int x)` | 代表元 | ならし $O(\alpha(n))$ |
| `bool same(int x, int y)` | 同じ集合か | ならし $O(\alpha(n))$ |
| `int size(int x)` | 集合のサイズ | ならし $O(\alpha(n))$ |
| `vector<vector<int>> groups()` | 集合ごとの要素のリスト | $O(n\,\alpha(n))$ |

（計算量は群演算を $O(1)$ としたもの）

## 注意

- **向きに注意**：`merge(u, v, w)` は $a_u = a_v w$（加法なら $a_u - a_v = w$）、`diff(u, v)` は $a_v^{-1} a_u$。[`weighted_dsu.hpp`](weighted_dsu.hpp) とは向きが逆。
- `T` は `==` で比較できること（矛盾判定に使う）。
- `leader` は再帰で実装しているが、union by size なので深さは $O(\log n)$。
