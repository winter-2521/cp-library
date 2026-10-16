---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/set_xor_min.test.cpp
    title: test/set_xor_min.test.cpp
  - icon: ':x:'
    path: test/unittest/binary_trie.test.cpp
    title: test/unittest/binary_trie.test.cpp
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
    \ 3 \"data_structure/binary_trie.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// 2 \u5206\u30C8\u30E9\u30A4 (\u975E\u8CA0\u6574\u6570\u306E\u591A\u91CD\u96C6\
    \u5408)\n// [0, 2^LOG) \u306E\u6574\u6570\u3092\u4E0A\u4F4D\u30D3\u30C3\u30C8\u304B\
    \u3089\u6301\u3064\uFF0Exor_min / xor_max / k \u756A\u76EE / x \u672A\u6E80\u306E\
    \u500B\u6570\u3092\u300C\u5168\u4F53\u306B xor \u3057\u305F\u3082\u306E\u300D\u306B\
    \u5BFE\u3057\u3066\u6C42\u3081\u3089\u308C\u308B\n// \u30CE\u30FC\u30C9\u306F\u524A\
    \u9664\u3057\u3066\u3082\u6D88\u3055\u306A\u3044 (\u500B\u6570 0 \u306E\u307E\u307E\
    \u6B8B\u3059)\ntemplate <int LOG = 30, class T = unsigned int>\nstruct BinaryTrie\
    \ {\n    struct Node {\n        int ch[2];\n        int cnt;\n    };\n    vector<Node>\
    \ d;\n    static constexpr T MASK = LOG == (int)sizeof(T) * 8 ? ~T(0) : (T(1)\
    \ << LOG) - 1;\n\n    BinaryTrie() { d.push_back({{0, 0}, 0}); }  // 0 \u756A\u304C\
    \u6839\n\n    void reserve(int n) { d.reserve(n); }\n    int size() const { return\
    \ d[0].cnt; }\n    bool empty() const { return d[0].cnt == 0; }\n\n    // x \u3092\
    \ k \u500B\u8FFD\u52A0\n    void insert(T x, int k = 1) {\n        int v = 0;\n\
    \        d[v].cnt += k;\n        for (int b = LOG - 1; b >= 0; b--) {\n      \
    \      int c = (x >> b) & 1;\n            if (!d[v].ch[c]) {\n               \
    \ d[v].ch[c] = d.size();\n                d.push_back({{0, 0}, 0});\n        \
    \    }\n            v = d[v].ch[c];\n            d[v].cnt += k;\n        }\n \
    \   }\n\n    // x \u3092 k \u500B\u524A\u9664 (k \u500B\u4EE5\u4E0A\u5165\u3063\
    \u3066\u3044\u308B\u3053\u3068)\n    void erase(T x, int k = 1) {\n        int\
    \ v = 0;\n        d[v].cnt -= k;\n        for (int b = LOG - 1; b >= 0; b--) {\n\
    \            v = d[v].ch[(x >> b) & 1];\n            d[v].cnt -= k;\n        }\n\
    \    }\n\n    // x \u304C\u5165\u3063\u3066\u3044\u306A\u3051\u308C\u3070\u8FFD\
    \u52A0\u3057\u3066 true\n    bool insert_unique(T x) {\n        if (count(x))\
    \ return false;\n        insert(x);\n        return true;\n    }\n\n    // x \u304C\
    \u5165\u3063\u3066\u3044\u308C\u3070 1 \u500B\u524A\u9664\u3057\u3066 true\n \
    \   bool erase_one(T x) {\n        if (!count(x)) return false;\n        erase(x);\n\
    \        return true;\n    }\n\n    // x \u306E\u500B\u6570\n    int count(T x)\
    \ const {\n        int v = 0;\n        for (int b = LOG - 1; b >= 0; b--) {\n\
    \            v = d[v].ch[(x >> b) & 1];\n            if (!v || !d[v].cnt) return\
    \ 0;\n        }\n        return d[v].cnt;\n    }\n\n    // min_{y \u2208 S} (x\
    \ xor y) (\u7A7A\u3067\u306A\u3044\u3053\u3068)\n    T xor_min(T x) const {\n\
    \        int v = 0;\n        T res = 0;\n        for (int b = LOG - 1; b >= 0;\
    \ b--) {\n            int c = (x >> b) & 1;\n            int to = d[v].ch[c];\n\
    \            if (to && d[to].cnt) v = to;\n            else v = d[v].ch[c ^ 1],\
    \ res |= T(1) << b;\n        }\n        return res;\n    }\n\n    // max_{y \u2208\
    \ S} (x xor y) (\u7A7A\u3067\u306A\u3044\u3053\u3068)\n    T xor_max(T x) const\
    \ { return xor_min(x ^ MASK) ^ MASK; }\n\n    // {y xor x : y \u2208 S} \u306E\
    \u4E2D\u3067\u5C0F\u3055\u3044\u65B9\u304B\u3089 k \u756A\u76EE (0-indexed, k\
    \ < size())\n    T kth(int k, T x = 0) const {\n        int v = 0;\n        T\
    \ res = 0;\n        for (int b = LOG - 1; b >= 0; b--) {\n            int c =\
    \ (x >> b) & 1;\n            int l = d[v].ch[c];\n            int lc = l ? d[l].cnt\
    \ : 0;\n            if (k < lc) v = l;\n            else k -= lc, v = d[v].ch[c\
    \ ^ 1], res |= T(1) << b;\n        }\n        return res;\n    }\n\n    // {y\
    \ xor x : y \u2208 S} \u306E\u6700\u5C0F\u5024 / \u6700\u5927\u5024 (\u7A7A\u3067\
    \u306A\u3044\u3053\u3068)\n    T min(T x = 0) const { return xor_min(x); }\n \
    \   T max(T x = 0) const { return xor_max(x); }\n\n    // #{y \u2208 S : (y xor\
    \ x) < a}\n    int count_less(T a, T x = 0) const {\n        if (a > MASK) return\
    \ size();\n        int v = 0, res = 0;\n        for (int b = LOG - 1; b >= 0;\
    \ b--) {\n            int c = (x >> b) & 1, ab = (a >> b) & 1;\n            if\
    \ (ab) {\n                int l = d[v].ch[c];\n                if (l) res += d[l].cnt;\n\
    \                v = d[v].ch[c ^ 1];\n            } else {\n                v\
    \ = d[v].ch[c];\n            }\n            if (!v) return res;\n        }\n \
    \       return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// 2 \u5206\u30C8\u30E9\u30A4 (\u975E\u8CA0\u6574\u6570\u306E\u591A\u91CD\u96C6\
    \u5408)\n// [0, 2^LOG) \u306E\u6574\u6570\u3092\u4E0A\u4F4D\u30D3\u30C3\u30C8\u304B\
    \u3089\u6301\u3064\uFF0Exor_min / xor_max / k \u756A\u76EE / x \u672A\u6E80\u306E\
    \u500B\u6570\u3092\u300C\u5168\u4F53\u306B xor \u3057\u305F\u3082\u306E\u300D\u306B\
    \u5BFE\u3057\u3066\u6C42\u3081\u3089\u308C\u308B\n// \u30CE\u30FC\u30C9\u306F\u524A\
    \u9664\u3057\u3066\u3082\u6D88\u3055\u306A\u3044 (\u500B\u6570 0 \u306E\u307E\u307E\
    \u6B8B\u3059)\ntemplate <int LOG = 30, class T = unsigned int>\nstruct BinaryTrie\
    \ {\n    struct Node {\n        int ch[2];\n        int cnt;\n    };\n    vector<Node>\
    \ d;\n    static constexpr T MASK = LOG == (int)sizeof(T) * 8 ? ~T(0) : (T(1)\
    \ << LOG) - 1;\n\n    BinaryTrie() { d.push_back({{0, 0}, 0}); }  // 0 \u756A\u304C\
    \u6839\n\n    void reserve(int n) { d.reserve(n); }\n    int size() const { return\
    \ d[0].cnt; }\n    bool empty() const { return d[0].cnt == 0; }\n\n    // x \u3092\
    \ k \u500B\u8FFD\u52A0\n    void insert(T x, int k = 1) {\n        int v = 0;\n\
    \        d[v].cnt += k;\n        for (int b = LOG - 1; b >= 0; b--) {\n      \
    \      int c = (x >> b) & 1;\n            if (!d[v].ch[c]) {\n               \
    \ d[v].ch[c] = d.size();\n                d.push_back({{0, 0}, 0});\n        \
    \    }\n            v = d[v].ch[c];\n            d[v].cnt += k;\n        }\n \
    \   }\n\n    // x \u3092 k \u500B\u524A\u9664 (k \u500B\u4EE5\u4E0A\u5165\u3063\
    \u3066\u3044\u308B\u3053\u3068)\n    void erase(T x, int k = 1) {\n        int\
    \ v = 0;\n        d[v].cnt -= k;\n        for (int b = LOG - 1; b >= 0; b--) {\n\
    \            v = d[v].ch[(x >> b) & 1];\n            d[v].cnt -= k;\n        }\n\
    \    }\n\n    // x \u304C\u5165\u3063\u3066\u3044\u306A\u3051\u308C\u3070\u8FFD\
    \u52A0\u3057\u3066 true\n    bool insert_unique(T x) {\n        if (count(x))\
    \ return false;\n        insert(x);\n        return true;\n    }\n\n    // x \u304C\
    \u5165\u3063\u3066\u3044\u308C\u3070 1 \u500B\u524A\u9664\u3057\u3066 true\n \
    \   bool erase_one(T x) {\n        if (!count(x)) return false;\n        erase(x);\n\
    \        return true;\n    }\n\n    // x \u306E\u500B\u6570\n    int count(T x)\
    \ const {\n        int v = 0;\n        for (int b = LOG - 1; b >= 0; b--) {\n\
    \            v = d[v].ch[(x >> b) & 1];\n            if (!v || !d[v].cnt) return\
    \ 0;\n        }\n        return d[v].cnt;\n    }\n\n    // min_{y \u2208 S} (x\
    \ xor y) (\u7A7A\u3067\u306A\u3044\u3053\u3068)\n    T xor_min(T x) const {\n\
    \        int v = 0;\n        T res = 0;\n        for (int b = LOG - 1; b >= 0;\
    \ b--) {\n            int c = (x >> b) & 1;\n            int to = d[v].ch[c];\n\
    \            if (to && d[to].cnt) v = to;\n            else v = d[v].ch[c ^ 1],\
    \ res |= T(1) << b;\n        }\n        return res;\n    }\n\n    // max_{y \u2208\
    \ S} (x xor y) (\u7A7A\u3067\u306A\u3044\u3053\u3068)\n    T xor_max(T x) const\
    \ { return xor_min(x ^ MASK) ^ MASK; }\n\n    // {y xor x : y \u2208 S} \u306E\
    \u4E2D\u3067\u5C0F\u3055\u3044\u65B9\u304B\u3089 k \u756A\u76EE (0-indexed, k\
    \ < size())\n    T kth(int k, T x = 0) const {\n        int v = 0;\n        T\
    \ res = 0;\n        for (int b = LOG - 1; b >= 0; b--) {\n            int c =\
    \ (x >> b) & 1;\n            int l = d[v].ch[c];\n            int lc = l ? d[l].cnt\
    \ : 0;\n            if (k < lc) v = l;\n            else k -= lc, v = d[v].ch[c\
    \ ^ 1], res |= T(1) << b;\n        }\n        return res;\n    }\n\n    // {y\
    \ xor x : y \u2208 S} \u306E\u6700\u5C0F\u5024 / \u6700\u5927\u5024 (\u7A7A\u3067\
    \u306A\u3044\u3053\u3068)\n    T min(T x = 0) const { return xor_min(x); }\n \
    \   T max(T x = 0) const { return xor_max(x); }\n\n    // #{y \u2208 S : (y xor\
    \ x) < a}\n    int count_less(T a, T x = 0) const {\n        if (a > MASK) return\
    \ size();\n        int v = 0, res = 0;\n        for (int b = LOG - 1; b >= 0;\
    \ b--) {\n            int c = (x >> b) & 1, ab = (a >> b) & 1;\n            if\
    \ (ab) {\n                int l = d[v].ch[c];\n                if (l) res += d[l].cnt;\n\
    \                v = d[v].ch[c ^ 1];\n            } else {\n                v\
    \ = d[v].ch[c];\n            }\n            if (!v) return res;\n        }\n \
    \       return res;\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unittest/binary_trie.test.cpp
  - test/set_xor_min.test.cpp
documentation_of: data_structure/binary_trie.hpp
layout: document
title: "2 \u5206\u30C8\u30E9\u30A4 (Binary Trie)"
---

## 概要

$[0, 2^{\mathrm{LOG}})$ の非負整数の **多重集合** を、上位ビットから見た 2 分木で持つ。各ノードは部分木の要素数を持つ。
「全要素に $x$ を xor した集合」に対する最小値・最大値・$k$ 番目・$a$ 未満の個数を、どれも根から 1 本降りるだけで $O(\mathrm{LOG})$ で求められる（xor の各ビットが 1 なら左右の子を入れ替えて見ればよい）。

## 使い方

```cpp
BinaryTrie<30> trie;                 // [0, 2^30)．値の型は unsigned int
BinaryTrie<64, unsigned long long> t64;
trie.reserve(q * 30 + 1);            // ノード数の上限 (任意)
trie.insert(x);       trie.insert(x, k);   // k 個追加
trie.erase(x);        trie.erase(x, k);    // k 個削除 (入っていること)
trie.insert_unique(x);   // 入っていなければ追加 (追加したら true)
trie.erase_one(x);       // 入っていれば 1 個削除 (削除したら true)
trie.count(x);
trie.xor_min(x);  trie.xor_max(x);    // min / max (x xor y)
trie.kth(k, x);                       // (y xor x) の k 番目に小さい値 (0-indexed)
trie.count_less(a, x);                // (y xor x) < a となる y の個数
trie.min(); trie.max();               // 最小値 / 最大値
trie.size(); trie.empty();
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `void insert(T x, int k = 1)` / `void erase(T x, int k = 1)` | 追加 / 削除 | $O(\mathrm{LOG})$ |
| `bool insert_unique(T x)` / `bool erase_one(T x)` | 集合として追加 / 削除 | $O(\mathrm{LOG})$ |
| `int count(T x)` | $x$ の個数 | $O(\mathrm{LOG})$ |
| `T xor_min(T x)` / `T xor_max(T x)` | $\min / \max_{y} (x \oplus y)$ | $O(\mathrm{LOG})$ |
| `T kth(int k, T x = 0)` | $\{y \oplus x\}$ の $k$ 番目（0-indexed） | $O(\mathrm{LOG})$ |
| `int count_less(T a, T x = 0)` | $\#\{y : (y \oplus x) < a\}$ | $O(\mathrm{LOG})$ |
| `T min(T x = 0)` / `T max(T x = 0)` | $\{y \oplus x\}$ の最小 / 最大 | $O(\mathrm{LOG})$ |

## 注意

- `xor_min` / `xor_max` / `kth` / `min` / `max` は空でないときに呼ぶこと。
- 削除してもノードは消さない（個数 0 のまま残る）。ノード数は追加した値の種類数 × LOG で抑えられる。
