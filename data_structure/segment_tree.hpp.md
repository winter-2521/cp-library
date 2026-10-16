---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9 (Monoid)"
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':x:'
    path: data_structure/range_assign_segment_tree.hpp
    title: "\u533A\u9593\u4EE3\u5165\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Range Assign\
      \ Segment Tree)"
  - icon: ':x:'
    path: data_structure/sortable_segment_tree.hpp
    title: "\u533A\u9593\u30BD\u30FC\u30C8\u304C\u3067\u304D\u308B\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728 (Sortable Segment Tree)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/point_set_range_composite.test.cpp
    title: test/point_set_range_composite.test.cpp
  - icon: ':x:'
    path: test/point_set_range_sort_range_composite.test.cpp
    title: test/point_set_range_sort_range_composite.test.cpp
  - icon: ':x:'
    path: test/range_set_range_composite.test.cpp
    title: test/range_set_range_composite.test.cpp
  - icon: ':x:'
    path: test/unittest/range_assign_segment_tree.test.cpp
    title: test/unittest/range_assign_segment_tree.test.cpp
  - icon: ':x:'
    path: test/unittest/segment_tree.test.cpp
    title: test/unittest/segment_tree.test.cpp
  - icon: ':x:'
    path: test/unittest/sortable_segment_tree.test.cpp
    title: test/unittest/sortable_segment_tree.test.cpp
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
    \ 3 \"algebra/monoid.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\n\
    // \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306A\u3069\u306B\u6E21\u3059\u30E2\u30CE\
    \u30A4\u30C9\n// \u5F62\u5F0F: using S = \u5024\u306E\u578B; static S op(const\
    \ S &a, const S &b); static S e();\n// op \u306F\u7D50\u5408\u7684\u3067\uFF0C\
    e \u306F\u5358\u4F4D\u5143\uFF0Eop(a, b) \u306F\u300Ca \u304C\u5DE6 (\u5148)\uFF0C\
    b \u304C\u53F3 (\u5F8C)\u300D\n\n// 1 \u6B21\u95A2\u6570 f(x) = a x + b\ntemplate\
    \ <class T>\nstruct Affine {\n    T a = T(1), b = T(0);\n    Affine() = default;\n\
    \    Affine(T a, T b) : a(a), b(b) {}\n    T operator()(const T &x) const { return\
    \ a * x + b; }\n    T eval(const T &x) const { return a * x + b; }\n    // \u300C\
    \u5148\u306B *this\uFF0C\u6B21\u306B g\u300D\u3092\u8868\u3059\u95A2\u6570 g(f(x))\n\
    \    Affine then(const Affine &g) const { return Affine(a * g.a, b * g.a + g.b);\
    \ }\n    friend bool operator==(const Affine &f, const Affine &g) { return f.a\
    \ == g.a && f.b == g.b; }\n    friend bool operator!=(const Affine &f, const Affine\
    \ &g) { return !(f == g); }\n};\n\n// \u548C\ntemplate <class T>\nstruct MonoidSum\
    \ {\n    using S = T;\n    static S op(const S &a, const S &b) { return a + b;\
    \ }\n    static S e() { return S(0); }\n};\n\n// \u6700\u5C0F\u5024 (\u5358\u4F4D\
    \u5143\u306F numeric_limits<T>::max())\ntemplate <class T>\nstruct MonoidMin {\n\
    \    using S = T;\n    static S op(const S &a, const S &b) { return b < a ? b\
    \ : a; }\n    static S e() { return numeric_limits<T>::max(); }\n};\n\n// \u6700\
    \u5927\u5024 (\u5358\u4F4D\u5143\u306F numeric_limits<T>::lowest())\ntemplate\
    \ <class T>\nstruct MonoidMax {\n    using S = T;\n    static S op(const S &a,\
    \ const S &b) { return a < b ? b : a; }\n    static S e() { return numeric_limits<T>::lowest();\
    \ }\n};\n\n// xor\ntemplate <class T>\nstruct MonoidXor {\n    using S = T;\n\
    \    static S op(const S &a, const S &b) { return a ^ b; }\n    static S e() {\
    \ return S(0); }\n};\n\n// 1 \u6B21\u95A2\u6570\u306E\u5408\u6210\uFF0Eop(f, g)\
    \ = \u300C\u5148\u306B f\uFF0C\u6B21\u306B g\u300D = g(f(x))\n// \u533A\u9593\
    \ [l, r) \u306E\u7A4D\u306F f_{r-1}(...f_l(x)) \u3092\u8868\u3059\ntemplate <class\
    \ T>\nstruct MonoidAffine {\n    using S = Affine<T>;\n    static S op(const S\
    \ &f, const S &g) { return f.then(g); }\n    static S e() { return S(); }\n};\n\
    \n// x^k = op(x, x, ..., x) (k \u500B)\uFF0Ek = 0 \u306A\u3089 e()\uFF0EO(log\
    \ k) \u56DE\u306E op\ntemplate <class M>\ntypename M::S monoid_pow(typename M::S\
    \ x, long long k) {\n    typename M::S r = M::e();\n    while (k) {\n        if\
    \ (k & 1) r = M::op(r, x);\n        k >>= 1;\n        if (k) x = M::op(x, x);\n\
    \    }\n    return r;\n}\n#line 4 \"data_structure/segment_tree.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\
    \u9593\u7A4D)\n// M \u306F\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp \u53C2\u7167\
    )\uFF0E\u975E\u53EF\u63DB\u3067\u3082\u3088\u3044\ntemplate <class M>\nstruct\
    \ SegmentTree {\n    using S = typename M::S;\n    int n, sz, lg;\n    vector<S>\
    \ d;\n\n    SegmentTree(int n = 0) : SegmentTree(vector<S>(n, M::e())) {}\n\n\
    \    SegmentTree(const vector<S> &a) : n(a.size()) {\n        lg = 0;\n      \
    \  while ((1 << lg) < n) lg++;\n        sz = 1 << lg;\n        d.assign(2 * sz,\
    \ M::e());\n        copy(a.begin(), a.end(), d.begin() + sz);\n        for (int\
    \ i = sz - 1; i >= 1; i--) d[i] = M::op(d[2 * i], d[2 * i + 1]);\n    }\n\n  \
    \  int size() const { return n; }\n\n    // a[p] = x\n    void set(int p, const\
    \ S &x) {\n        p += sz;\n        d[p] = x;\n        for (p >>= 1; p; p >>=\
    \ 1) d[p] = M::op(d[2 * p], d[2 * p + 1]);\n    }\n\n    // a[p] = op(a[p], x)\n\
    \    void multiply(int p, const S &x) { set(p, M::op(d[p + sz], x)); }\n\n   \
    \ S get(int p) const { return d[p + sz]; }\n    S operator[](int p) const { return\
    \ d[p + sz]; }\n\n    // op(a[l], ..., a[r-1])\uFF0El == r \u306A\u3089 e()\n\
    \    S prod(int l, int r) const {\n        S sml = M::e(), smr = M::e();\n   \
    \     l += sz, r += sz;\n        while (l < r) {\n            if (l & 1) sml =\
    \ M::op(sml, d[l++]);\n            if (r & 1) smr = M::op(d[--r], smr);\n    \
    \        l >>= 1, r >>= 1;\n        }\n        return M::op(sml, smr);\n    }\n\
    \n    S all_prod() const { return d[1]; }\n\n    // g(op(a[l], ..., a[r-1])) \u304C\
    \ true \u3068\u306A\u308B\u6700\u5927\u306E r \u3092\u8FD4\u3059 (g(e()) \u306F\
    \ true \u3067\u3042\u308B\u3053\u3068)\n    template <class G>\n    int max_right(int\
    \ l, G g) const {\n        if (l == n) return n;\n        l += sz;\n        S\
    \ sm = M::e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n      \
    \      if (!g(M::op(sm, d[l]))) {\n                while (l < sz) {\n        \
    \            l = 2 * l;\n                    if (g(M::op(sm, d[l]))) sm = M::op(sm,\
    \ d[l++]);\n                }\n                return l - sz;\n            }\n\
    \            sm = M::op(sm, d[l++]);\n        } while ((l & -l) != l);\n     \
    \   return n;\n    }\n\n    // g(op(a[l], ..., a[r-1])) \u304C true \u3068\u306A\
    \u308B\u6700\u5C0F\u306E l \u3092\u8FD4\u3059 (g(e()) \u306F true \u3067\u3042\
    \u308B\u3053\u3068)\n    template <class G>\n    int min_left(int r, G g) const\
    \ {\n        if (r == 0) return 0;\n        r += sz;\n        S sm = M::e();\n\
    \        do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n\
    \            if (!g(M::op(d[r], sm))) {\n                while (r < sz) {\n  \
    \                  r = 2 * r + 1;\n                    if (g(M::op(d[r], sm)))\
    \ sm = M::op(d[r--], sm);\n                }\n                return r + 1 - sz;\n\
    \            }\n            sm = M::op(d[r], sm);\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"../algebra/monoid.hpp\"\
    \n\n// https://github.com/winter-2521/cp-library\n\n// \u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728 (\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\u9593\u7A4D)\n// M \u306F\u30E2\
    \u30CE\u30A4\u30C9 (algebra/monoid.hpp \u53C2\u7167)\uFF0E\u975E\u53EF\u63DB\u3067\
    \u3082\u3088\u3044\ntemplate <class M>\nstruct SegmentTree {\n    using S = typename\
    \ M::S;\n    int n, sz, lg;\n    vector<S> d;\n\n    SegmentTree(int n = 0) :\
    \ SegmentTree(vector<S>(n, M::e())) {}\n\n    SegmentTree(const vector<S> &a)\
    \ : n(a.size()) {\n        lg = 0;\n        while ((1 << lg) < n) lg++;\n    \
    \    sz = 1 << lg;\n        d.assign(2 * sz, M::e());\n        copy(a.begin(),\
    \ a.end(), d.begin() + sz);\n        for (int i = sz - 1; i >= 1; i--) d[i] =\
    \ M::op(d[2 * i], d[2 * i + 1]);\n    }\n\n    int size() const { return n; }\n\
    \n    // a[p] = x\n    void set(int p, const S &x) {\n        p += sz;\n     \
    \   d[p] = x;\n        for (p >>= 1; p; p >>= 1) d[p] = M::op(d[2 * p], d[2 *\
    \ p + 1]);\n    }\n\n    // a[p] = op(a[p], x)\n    void multiply(int p, const\
    \ S &x) { set(p, M::op(d[p + sz], x)); }\n\n    S get(int p) const { return d[p\
    \ + sz]; }\n    S operator[](int p) const { return d[p + sz]; }\n\n    // op(a[l],\
    \ ..., a[r-1])\uFF0El == r \u306A\u3089 e()\n    S prod(int l, int r) const {\n\
    \        S sml = M::e(), smr = M::e();\n        l += sz, r += sz;\n        while\
    \ (l < r) {\n            if (l & 1) sml = M::op(sml, d[l++]);\n            if\
    \ (r & 1) smr = M::op(d[--r], smr);\n            l >>= 1, r >>= 1;\n        }\n\
    \        return M::op(sml, smr);\n    }\n\n    S all_prod() const { return d[1];\
    \ }\n\n    // g(op(a[l], ..., a[r-1])) \u304C true \u3068\u306A\u308B\u6700\u5927\
    \u306E r \u3092\u8FD4\u3059 (g(e()) \u306F true \u3067\u3042\u308B\u3053\u3068\
    )\n    template <class G>\n    int max_right(int l, G g) const {\n        if (l\
    \ == n) return n;\n        l += sz;\n        S sm = M::e();\n        do {\n  \
    \          while (l % 2 == 0) l >>= 1;\n            if (!g(M::op(sm, d[l]))) {\n\
    \                while (l < sz) {\n                    l = 2 * l;\n          \
    \          if (g(M::op(sm, d[l]))) sm = M::op(sm, d[l++]);\n                }\n\
    \                return l - sz;\n            }\n            sm = M::op(sm, d[l++]);\n\
    \        } while ((l & -l) != l);\n        return n;\n    }\n\n    // g(op(a[l],\
    \ ..., a[r-1])) \u304C true \u3068\u306A\u308B\u6700\u5C0F\u306E l \u3092\u8FD4\
    \u3059 (g(e()) \u306F true \u3067\u3042\u308B\u3053\u3068)\n    template <class\
    \ G>\n    int min_left(int r, G g) const {\n        if (r == 0) return 0;\n  \
    \      r += sz;\n        S sm = M::e();\n        do {\n            r--;\n    \
    \        while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(M::op(d[r], sm)))\
    \ {\n                while (r < sz) {\n                    r = 2 * r + 1;\n  \
    \                  if (g(M::op(d[r], sm))) sm = M::op(d[r--], sm);\n         \
    \       }\n                return r + 1 - sz;\n            }\n            sm =\
    \ M::op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\
    };\n"
  dependsOn:
  - template.hpp
  - algebra/monoid.hpp
  - template.hpp
  isVerificationFile: false
  path: data_structure/segment_tree.hpp
  requiredBy:
  - data_structure/sortable_segment_tree.hpp
  - data_structure/range_assign_segment_tree.hpp
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unittest/segment_tree.test.cpp
  - test/unittest/range_assign_segment_tree.test.cpp
  - test/unittest/sortable_segment_tree.test.cpp
  - test/point_set_range_sort_range_composite.test.cpp
  - test/point_set_range_composite.test.cpp
  - test/range_set_range_composite.test.cpp
documentation_of: data_structure/segment_tree.hpp
layout: document
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)"
---

## 概要

モノイド `M` の列に対して、一点更新と区間積を $O(\log n)$ で処理する。非可換なモノイドでもよい。
大きさを 2 冪に切り上げた完全二分木を 1 本の配列で持つ、非再帰の実装。ACL の `segtree` と同じ操作に加えて `multiply` がある。

## 使い方

```cpp
SegmentTree<MonoidSum<long long>> seg(n);   // 全て e()
SegmentTree<MonoidAffine<mint>> seg2(f);   // vector<Affine<mint>> f から構築
seg.set(p, x);        // a[p] = x
seg.multiply(p, x);   // a[p] = op(a[p], x)
seg.get(p);           // a[p] (seg[p] でも可)
seg.prod(l, r);       // op(a[l], ..., a[r-1])
seg.all_prod();
seg.max_right(l, [](S x) { return 条件; });  // 条件を満たす最大の r
seg.min_left(r, [](S x) { return 条件; });   // 条件を満たす最小の l
seg2.prod(l, r)(x);   // f_{r-1}(...f_l(x))
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `SegmentTree<M>(int n)` / `SegmentTree<M>(const vector<S> &a)` | 構築 | $O(n)$ |
| `void set(int p, S x)` | $a_p = x$ | $O(\log n)$ |
| `void multiply(int p, S x)` | $a_p = a_p \cdot x$ | $O(\log n)$ |
| `S get(int p)` / `operator[]` | $a_p$ | $O(1)$ |
| `S prod(int l, int r)` | $a_l \cdots a_{r-1}$（空なら `e()`） | $O(\log n)$ |
| `S all_prod()` | 全体の積 | $O(1)$ |
| `int max_right(int l, G g)` | `g(prod(l, r))` が真となる最大の $r$ | $O(\log n)$ |
| `int min_left(int r, G g)` | `g(prod(l, r))` が真となる最小の $l$ | $O(\log n)$ |

## 注意

- `max_right` / `min_left` の `g` は単調（短い区間で真なら長い区間で偽になりうるが、その逆はない）で、`g(e())` が真であること。
- モノイドの書き方は [monoid.hpp](../../algebra/monoid.hpp) を参照。
