---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/deque_operate_all_composite.test.cpp
    title: test/deque_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/dynamic_point_set_rectangle_affine_rectangle_sum.test.cpp
    title: test/dynamic_point_set_rectangle_affine_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/dynamic_sequence_range_affine_range_sum.test.cpp
    title: test/dynamic_sequence_range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: test/incremental_scc.test.cpp
    title: test/incremental_scc.test.cpp
  - icon: ':x:'
    path: test/persistent_range_affine_range_sum.test.cpp
    title: test/persistent_range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: test/point_set_range_composite.test.cpp
    title: test/point_set_range_composite.test.cpp
  - icon: ':x:'
    path: test/point_set_range_composite_large_array.test.cpp
    title: test/point_set_range_composite_large_array.test.cpp
  - icon: ':x:'
    path: test/point_set_range_sort_range_composite.test.cpp
    title: test/point_set_range_sort_range_composite.test.cpp
  - icon: ':x:'
    path: test/queue_operate_all_composite.test.cpp
    title: test/queue_operate_all_composite.test.cpp
  - icon: ':x:'
    path: test/range_affine_point_get.test.cpp
    title: test/range_affine_point_get.test.cpp
  - icon: ':x:'
    path: test/range_affine_range_sum.test.cpp
    title: test/range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: test/range_affine_range_sum_large_array.test.cpp
    title: test/range_affine_range_sum_large_array.test.cpp
  - icon: ':x:'
    path: test/range_parallel_unionfind.test.cpp
    title: test/range_parallel_unionfind.test.cpp
  - icon: ':x:'
    path: test/range_parallel_unionfind_online.test.cpp
    title: test/range_parallel_unionfind_online.test.cpp
  - icon: ':x:'
    path: test/range_set_range_composite.test.cpp
    title: test/range_set_range_composite.test.cpp
  - icon: ':x:'
    path: test/static_rectangle_add_rectangle_sum.test.cpp
    title: test/static_rectangle_add_rectangle_sum.test.cpp
  - icon: ':x:'
    path: test/unionfind_with_potential.test.cpp
    title: test/unionfind_with_potential.test.cpp
  - icon: ':x:'
    path: test/unionfind_with_potential_non_commutative_group.test.cpp
    title: test/unionfind_with_potential_non_commutative_group.test.cpp
  - icon: ':x:'
    path: test/unittest/dynamic_sequence.test.cpp
    title: test/unittest/dynamic_sequence.test.cpp
  - icon: ':x:'
    path: test/unittest/foldable_queue.test.cpp
    title: test/unittest/foldable_queue.test.cpp
  - icon: ':x:'
    path: test/unittest/kd_tree.test.cpp
    title: test/unittest/kd_tree.test.cpp
  - icon: ':x:'
    path: test/unittest/lazy_segment_tree.test.cpp
    title: test/unittest/lazy_segment_tree.test.cpp
  - icon: ':x:'
    path: test/unittest/modint.test.cpp
    title: test/unittest/modint.test.cpp
  - icon: ':x:'
    path: test/unittest/range_assign_segment_tree.test.cpp
    title: test/unittest/range_assign_segment_tree.test.cpp
  - icon: ':x:'
    path: test/unittest/rectangle_add.test.cpp
    title: test/unittest/rectangle_add.test.cpp
  - icon: ':x:'
    path: test/unittest/segment_tree.test.cpp
    title: test/unittest/segment_tree.test.cpp
  - icon: ':x:'
    path: test/unittest/sortable_segment_tree.test.cpp
    title: test/unittest/sortable_segment_tree.test.cpp
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
    \ 3 \"math/modint.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\n//\
    \ \u6CD5 MOD \u304C \u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u5B9A\u6570\u306E modint\n\
    // MOD < 2^31 \u3067\u3042\u308B\u3053\u3068 (\u7D20\u6570\u3067\u306A\u304F\u3066\
    \u3082\u3088\u3044\uFF0E\u305F\u3060\u3057 inv() \u306F MOD \u3068\u4E92\u3044\
    \u306B\u7D20\u306A\u5024\u306B\u5BFE\u3057\u3066\u306E\u307F\u6709\u52B9)\n//\
    \ \u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9\u306F ACL (atcoder::static_modint)\
    \ \u3068\u63C3\u3048\u3066\u3042\u308B\uFF0E\n// \u3053\u306E\u30E9\u30A4\u30D6\
    \u30E9\u30EA\u306E\u4ED6\u306E\u30D5\u30A1\u30A4\u30EB (fastio \u306A\u3069) \u306F\
    \ ACL \u306E modint \u3067\u3082\u305D\u306E\u307E\u307E\u52D5\u304F\ntemplate\
    \ <uint32_t MOD>\nstruct ModInt {\n    static_assert(1 <= MOD && MOD < (1u <<\
    \ 31), \"MOD must be in [1, 2^31)\");\n    using mint = ModInt;\n    uint32_t\
    \ v;\n\n    static constexpr int mod() { return MOD; }\n\n    constexpr ModInt()\
    \ : v(0) {}\n\n    template <class T, enable_if_t<is_integral_v<T>, nullptr_t>\
    \ = nullptr>\n    constexpr ModInt(T x) : v(0) {\n        if constexpr (is_signed_v<T>)\
    \ {\n            long long y = (long long)(x % (long long)MOD);\n            if\
    \ (y < 0) y += MOD;\n            v = uint32_t(y);\n        } else {\n        \
    \    v = uint32_t(x % MOD);\n        }\n    }\n\n    // 0 <= x < MOD \u304C\u5206\
    \u304B\u3063\u3066\u3044\u308B\u3068\u304D\u306B\u5270\u4F59\u3092\u53D6\u3089\
    \u305A\u306B\u4F5C\u308B\n    static constexpr mint raw(int x) {\n        mint\
    \ r;\n        r.v = x;\n        return r;\n    }\n\n    // ACL (\u73FE\u884C\u7248\
    ) \u3068\u540C\u3058\u304F int \u3067\u8FD4\u3059\n    constexpr int val() const\
    \ { return int(v); }\n\n    constexpr mint &operator+=(const mint &r) {\n    \
    \    v += r.v;\n        if (v >= MOD) v -= MOD;\n        return *this;\n    }\n\
    \    constexpr mint &operator-=(const mint &r) {\n        v += MOD - r.v;\n  \
    \      if (v >= MOD) v -= MOD;\n        return *this;\n    }\n    constexpr mint\
    \ &operator*=(const mint &r) {\n        // MOD \u304C\u5B9A\u6570\u306A\u306E\u3067\
    \ % \u306F\u4E57\u7B97\u3068\u30B7\u30D5\u30C8\u306B\u6700\u9069\u5316\u3055\u308C\
    \u308B\n        v = uint32_t((uint64_t)v * r.v % MOD);\n        return *this;\n\
    \    }\n    constexpr mint &operator/=(const mint &r) { return *this *= r.inv();\
    \ }\n\n    constexpr mint operator+() const { return *this; }\n    constexpr mint\
    \ operator-() const { return raw(v == 0 ? 0 : MOD - v); }\n\n    constexpr mint\
    \ &operator++() { return *this += raw(1); }\n    constexpr mint &operator--()\
    \ { return *this -= raw(1); }\n    constexpr mint operator++(int) { mint r = *this;\
    \ ++*this; return r; }\n    constexpr mint operator--(int) { mint r = *this; --*this;\
    \ return r; }\n\n    friend constexpr mint operator+(mint l, const mint &r) {\
    \ return l += r; }\n    friend constexpr mint operator-(mint l, const mint &r)\
    \ { return l -= r; }\n    friend constexpr mint operator*(mint l, const mint &r)\
    \ { return l *= r; }\n    friend constexpr mint operator/(mint l, const mint &r)\
    \ { return l /= r; }\n    friend constexpr bool operator==(const mint &l, const\
    \ mint &r) { return l.v == r.v; }\n    friend constexpr bool operator!=(const\
    \ mint &l, const mint &r) { return l.v != r.v; }\n\n    // this^n (n < 0 \u306A\
    \u3089\u9006\u5143\u306E -n \u4E57)\n    constexpr mint pow(long long n) const\
    \ {\n        mint x = n >= 0 ? *this : inv(), r = raw(1 % MOD);\n        unsigned\
    \ long long e = n >= 0 ? (unsigned long long)n : 0ULL - (unsigned long long)n;\n\
    \        while (e) {\n            if (e & 1) r *= x;\n            x *= x;\n  \
    \          e >>= 1;\n        }\n        return r;\n    }\n\n    // \u62E1\u5F35\
    \u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\u306B\u3088\u308B\
    \u9006\u5143 (MOD \u304C\u7D20\u6570\u3067\u306A\u304F\u3066\u3082 gcd(v, MOD)\
    \ = 1 \u306A\u3089\u6B63\u3057\u3044)\n    constexpr mint inv() const {\n    \
    \    long long a = v, b = MOD, x = 1, y = 0;\n        while (b) {\n          \
    \  long long t = a / b;\n            a -= t * b, swap(a, b);\n            x -=\
    \ t * y, swap(x, y);\n        }\n        assert(a == 1);\n        return mint(x);\n\
    \    }\n\n    friend ostream &operator<<(ostream &os, const mint &x) { return\
    \ os << x.v; }\n    friend istream &operator>>(istream &is, mint &x) {\n     \
    \   long long t;\n        is >> t;\n        x = mint(t);\n        return is;\n\
    \    }\n};\n\nusing ModInt998244353 = ModInt<998244353>;\nusing ModInt1000000007\
    \ = ModInt<1000000007>;\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u6CD5 MOD \u304C \u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u5B9A\u6570\u306E\
    \ modint\n// MOD < 2^31 \u3067\u3042\u308B\u3053\u3068 (\u7D20\u6570\u3067\u306A\
    \u304F\u3066\u3082\u3088\u3044\uFF0E\u305F\u3060\u3057 inv() \u306F MOD \u3068\
    \u4E92\u3044\u306B\u7D20\u306A\u5024\u306B\u5BFE\u3057\u3066\u306E\u307F\u6709\
    \u52B9)\n// \u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9\u306F ACL (atcoder::static_modint)\
    \ \u3068\u63C3\u3048\u3066\u3042\u308B\uFF0E\n// \u3053\u306E\u30E9\u30A4\u30D6\
    \u30E9\u30EA\u306E\u4ED6\u306E\u30D5\u30A1\u30A4\u30EB (fastio \u306A\u3069) \u306F\
    \ ACL \u306E modint \u3067\u3082\u305D\u306E\u307E\u307E\u52D5\u304F\ntemplate\
    \ <uint32_t MOD>\nstruct ModInt {\n    static_assert(1 <= MOD && MOD < (1u <<\
    \ 31), \"MOD must be in [1, 2^31)\");\n    using mint = ModInt;\n    uint32_t\
    \ v;\n\n    static constexpr int mod() { return MOD; }\n\n    constexpr ModInt()\
    \ : v(0) {}\n\n    template <class T, enable_if_t<is_integral_v<T>, nullptr_t>\
    \ = nullptr>\n    constexpr ModInt(T x) : v(0) {\n        if constexpr (is_signed_v<T>)\
    \ {\n            long long y = (long long)(x % (long long)MOD);\n            if\
    \ (y < 0) y += MOD;\n            v = uint32_t(y);\n        } else {\n        \
    \    v = uint32_t(x % MOD);\n        }\n    }\n\n    // 0 <= x < MOD \u304C\u5206\
    \u304B\u3063\u3066\u3044\u308B\u3068\u304D\u306B\u5270\u4F59\u3092\u53D6\u3089\
    \u305A\u306B\u4F5C\u308B\n    static constexpr mint raw(int x) {\n        mint\
    \ r;\n        r.v = x;\n        return r;\n    }\n\n    // ACL (\u73FE\u884C\u7248\
    ) \u3068\u540C\u3058\u304F int \u3067\u8FD4\u3059\n    constexpr int val() const\
    \ { return int(v); }\n\n    constexpr mint &operator+=(const mint &r) {\n    \
    \    v += r.v;\n        if (v >= MOD) v -= MOD;\n        return *this;\n    }\n\
    \    constexpr mint &operator-=(const mint &r) {\n        v += MOD - r.v;\n  \
    \      if (v >= MOD) v -= MOD;\n        return *this;\n    }\n    constexpr mint\
    \ &operator*=(const mint &r) {\n        // MOD \u304C\u5B9A\u6570\u306A\u306E\u3067\
    \ % \u306F\u4E57\u7B97\u3068\u30B7\u30D5\u30C8\u306B\u6700\u9069\u5316\u3055\u308C\
    \u308B\n        v = uint32_t((uint64_t)v * r.v % MOD);\n        return *this;\n\
    \    }\n    constexpr mint &operator/=(const mint &r) { return *this *= r.inv();\
    \ }\n\n    constexpr mint operator+() const { return *this; }\n    constexpr mint\
    \ operator-() const { return raw(v == 0 ? 0 : MOD - v); }\n\n    constexpr mint\
    \ &operator++() { return *this += raw(1); }\n    constexpr mint &operator--()\
    \ { return *this -= raw(1); }\n    constexpr mint operator++(int) { mint r = *this;\
    \ ++*this; return r; }\n    constexpr mint operator--(int) { mint r = *this; --*this;\
    \ return r; }\n\n    friend constexpr mint operator+(mint l, const mint &r) {\
    \ return l += r; }\n    friend constexpr mint operator-(mint l, const mint &r)\
    \ { return l -= r; }\n    friend constexpr mint operator*(mint l, const mint &r)\
    \ { return l *= r; }\n    friend constexpr mint operator/(mint l, const mint &r)\
    \ { return l /= r; }\n    friend constexpr bool operator==(const mint &l, const\
    \ mint &r) { return l.v == r.v; }\n    friend constexpr bool operator!=(const\
    \ mint &l, const mint &r) { return l.v != r.v; }\n\n    // this^n (n < 0 \u306A\
    \u3089\u9006\u5143\u306E -n \u4E57)\n    constexpr mint pow(long long n) const\
    \ {\n        mint x = n >= 0 ? *this : inv(), r = raw(1 % MOD);\n        unsigned\
    \ long long e = n >= 0 ? (unsigned long long)n : 0ULL - (unsigned long long)n;\n\
    \        while (e) {\n            if (e & 1) r *= x;\n            x *= x;\n  \
    \          e >>= 1;\n        }\n        return r;\n    }\n\n    // \u62E1\u5F35\
    \u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\u306B\u3088\u308B\
    \u9006\u5143 (MOD \u304C\u7D20\u6570\u3067\u306A\u304F\u3066\u3082 gcd(v, MOD)\
    \ = 1 \u306A\u3089\u6B63\u3057\u3044)\n    constexpr mint inv() const {\n    \
    \    long long a = v, b = MOD, x = 1, y = 0;\n        while (b) {\n          \
    \  long long t = a / b;\n            a -= t * b, swap(a, b);\n            x -=\
    \ t * y, swap(x, y);\n        }\n        assert(a == 1);\n        return mint(x);\n\
    \    }\n\n    friend ostream &operator<<(ostream &os, const mint &x) { return\
    \ os << x.v; }\n    friend istream &operator>>(istream &is, mint &x) {\n     \
    \   long long t;\n        is >> t;\n        x = mint(t);\n        return is;\n\
    \    }\n};\n\nusing ModInt998244353 = ModInt<998244353>;\nusing ModInt1000000007\
    \ = ModInt<1000000007>;\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/unionfind_with_potential_non_commutative_group.test.cpp
  - test/dynamic_point_set_rectangle_affine_rectangle_sum.test.cpp
  - test/point_set_range_composite_large_array.test.cpp
  - test/queue_operate_all_composite.test.cpp
  - test/persistent_range_affine_range_sum.test.cpp
  - test/unittest/modint.test.cpp
  - test/unittest/kd_tree.test.cpp
  - test/unittest/foldable_queue.test.cpp
  - test/unittest/lazy_segment_tree.test.cpp
  - test/unittest/rectangle_add.test.cpp
  - test/unittest/dynamic_sequence.test.cpp
  - test/unittest/segment_tree.test.cpp
  - test/unittest/range_assign_segment_tree.test.cpp
  - test/unittest/sortable_segment_tree.test.cpp
  - test/deque_operate_all_composite.test.cpp
  - test/point_set_range_sort_range_composite.test.cpp
  - test/incremental_scc.test.cpp
  - test/dynamic_sequence_range_affine_range_sum.test.cpp
  - test/range_parallel_unionfind_online.test.cpp
  - test/range_parallel_unionfind.test.cpp
  - test/range_affine_point_get.test.cpp
  - test/point_set_range_composite.test.cpp
  - test/unionfind_with_potential.test.cpp
  - test/static_rectangle_add_rectangle_sum.test.cpp
  - test/range_set_range_composite.test.cpp
  - test/range_affine_range_sum.test.cpp
  - test/range_affine_range_sum_large_array.test.cpp
documentation_of: math/modint.hpp
layout: document
title: "ModInt (\u6CD5\u304C\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u5B9A\u6570\u306E\
  \ modint)"
---

## 概要

法 `MOD` がコンパイル時定数の剰余類。`MOD` が定数なので `%` は乗算とシフトに最適化される。
インターフェースは ACL の `atcoder::static_modint` と揃えてある（`val()`, `mod()`, `raw()`, `pow()`, `inv()`）。名前の衝突を避けるため CamelCase にしている。

このライブラリで mod を使うもの（fastio など）は `val()` と `mod()` だけに依存するので、**自作 `ModInt` と ACL の modint のどちらでも動く**。

## 使い方

```cpp
using mint = ModInt998244353;      // ModInt<998244353>．ModInt1000000007 もある
mint a = 3, b = -1;                // 負の数も正しく変換される
a + b; a - b; a * b; a / b;        // 四則演算 (割り算は逆元をかける)
a += b; -a; ++a;
a.val();                           // 値 (0 <= val < MOD)
a.pow(n);                          // a^n (n < 0 なら逆元の -n 乗)
a.inv();                           // 逆元
mint::mod();                       // 法
mint::raw(x);                      // 0 <= x < MOD が分かっているとき剰余を取らずに作る
fin >> a; fout << a;               // fastio で読み書きできる (cin / cout も可)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `ModInt<MOD>(T x)` | 整数 `x` を剰余類に変換（負の数も可） | $O(1)$ |
| `+`, `-`, `*`, 単項 `-`, `++`, `--`, `==`, `!=` | 演算 | $O(1)$ |
| `/` | `r.inv()` をかける | $O(\log \mathrm{MOD})$ |
| `int val()` | 値 | $O(1)$ |
| `mint pow(long long n)` | $a^n$（$n < 0$ なら $(a^{-1})^{-n}$） | $O(\log \lvert n \rvert)$ |
| `mint inv()` | 逆元（拡張ユークリッドの互除法） | $O(\log \mathrm{MOD})$ |
| `static int mod()` | 法 | $O(1)$ |
| `static mint raw(int x)` | 剰余を取らずに作る | $O(1)$ |

## 注意

- $1 \le \mathrm{MOD} < 2^{31}$。素数でなくてもよいが、`inv()` / `/` は $\gcd(v, \mathrm{MOD}) = 1$ のときのみ正しい（そうでなければ assert で落ちる）。
- 法を実行時に決める modint はまだない。
