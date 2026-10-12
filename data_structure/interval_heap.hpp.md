---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/double_ended_priority_queue.test.cpp
    title: test/double_ended_priority_queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/interval_heap.test.cpp
    title: test/unittest/interval_heap.test.cpp
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
    \ 3 \"data_structure/interval_heap.hpp\"\n\n// Interval Heap (\u4E21\u7AEF\u512A\
    \u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC)\n// \u6700\u5C0F\u5024\u30FB\u6700\
    \u5927\u5024\u306E\u53D6\u5F97\u3092 O(1)\uFF0C\u633F\u5165\u30FB\u6700\u5C0F\u5024\
    \u306E\u524A\u9664\u30FB\u6700\u5927\u5024\u306E\u524A\u9664\u3092 O(log n) \u3067\
    \u51E6\u7406\u3059\u308B\n// \u7BC0\u70B9 k \u304C d[2k] (\u533A\u9593\u306E\u5DE6\
    \u7AEF) \u3068 d[2k+1] (\u533A\u9593\u306E\u53F3\u7AEF) \u3092\u6301\u3061\uFF0C\
    \n// \u5DE6\u7AEF\u3060\u3051\u3092\u898B\u308B\u3068 min-heap\uFF0C\u53F3\u7AEF\
    \u3060\u3051\u3092\u898B\u308B\u3068 max-heap \u306B\u306A\u3063\u3066\u3044\u308B\
    \ntemplate <class T, class Compare = less<T>>\nstruct IntervalHeap {\n    vector<T>\
    \ d;\n    Compare comp;\n\n    IntervalHeap(Compare comp = Compare()) : comp(comp)\
    \ {}\n\n    IntervalHeap(const vector<T> &a, Compare comp = Compare()) : comp(comp)\
    \ {\n        d.reserve(a.size());\n        for (const T &x : a) push(x);\n   \
    \ }\n\n    int size() const { return d.size(); }\n    bool empty() const { return\
    \ d.empty(); }\n    void reserve(int n) { d.reserve(n); }\n    void clear() {\
    \ d.clear(); }\n\n    const T &min() const { return d[0]; }\n    const T &max()\
    \ const { return d.size() == 1 ? d[0] : d[1]; }\n\n    void push(const T &x) {\n\
    \        int i = d.size();\n        d.push_back(x);\n        if (i & 1) {\n  \
    \          // \u7BC0\u70B9 i/2 \u306E\u53F3\u7AEF\u306B\u5165\u3063\u305F\n  \
    \          if (comp(d[i], d[i - 1])) {\n                swap(d[i], d[i - 1]);\n\
    \                up_min(i - 1);\n            } else {\n                up_max(i);\n\
    \            }\n        } else {\n            // \u65B0\u3057\u3044\u7BC0\u70B9\
    \u304C\u3067\u304D\u305F (\u8981\u7D20 1 \u500B\u306A\u306E\u3067\u5DE6\u7AEF\u304B\
    \u3064\u53F3\u7AEF)\n            if (i == 0) return;\n            int p = (((i\
    \ >> 1) - 1) >> 1) << 1;\n            if (comp(d[i], d[p])) up_min(i);\n     \
    \       else if (comp(d[p + 1], d[i])) up_max(i);\n        }\n    }\n\n    T pop_min()\
    \ {\n        T res = std::move(d[0]);\n        T last = std::move(d.back());\n\
    \        d.pop_back();\n        if (!d.empty()) {\n            d[0] = std::move(last);\n\
    \            down_min();\n        }\n        return res;\n    }\n\n    T pop_max()\
    \ {\n        if (d.size() <= 2) {\n            T res = std::move(d.back());\n\
    \            d.pop_back();\n            return res;\n        }\n        T res\
    \ = std::move(d[1]);\n        T last = std::move(d.back());\n        d.pop_back();\n\
    \        d[1] = std::move(last);\n        down_max();\n        return res;\n \
    \   }\n\n  private:\n    // \u4F4D\u7F6E i (\u5DE6\u7AEF) \u306E\u8981\u7D20\u3092\
    \ min-heap \u3068\u3057\u3066\u4E0A\u3052\u308B\n    void up_min(int i) {\n  \
    \      T x = std::move(d[i]);\n        int k = i >> 1;\n        while (k > 0)\
    \ {\n            int p = (k - 1) >> 1;\n            if (!comp(x, d[p << 1])) break;\n\
    \            d[k << 1] = std::move(d[p << 1]);\n            k = p;\n        }\n\
    \        d[k << 1] = std::move(x);\n    }\n\n    // \u4F4D\u7F6E i (\u53F3\u7AEF\
    \uFF0E\u8981\u7D20 1 \u500B\u306E\u7BC0\u70B9\u306A\u3089\u5DE6\u7AEF) \u306E\u8981\
    \u7D20\u3092 max-heap \u3068\u3057\u3066\u4E0A\u3052\u308B\n    void up_max(int\
    \ i) {\n        T x = std::move(d[i]);\n        int k = i >> 1;\n        int pos\
    \ = i;\n        while (k > 0) {\n            int p = (k - 1) >> 1;\n         \
    \   if (!comp(d[p << 1 | 1], x)) break;\n            d[pos] = std::move(d[p <<\
    \ 1 | 1]);\n            pos = p << 1 | 1;\n            k = p;\n        }\n   \
    \     d[pos] = std::move(x);\n    }\n\n    void down_min() {\n        int n =\
    \ d.size();\n        int k = 0;\n        while (true) {\n            int lo =\
    \ k << 1;\n            if (lo + 1 < n && comp(d[lo + 1], d[lo])) swap(d[lo], d[lo\
    \ + 1]);\n            int c = (k << 1) + 1;\n            if ((c << 1) >= n) break;\n\
    \            if (((c + 1) << 1) < n && comp(d[(c + 1) << 1], d[c << 1])) c++;\n\
    \            if (!comp(d[c << 1], d[lo])) break;\n            swap(d[c << 1],\
    \ d[lo]);\n            k = c;\n        }\n        // \u6700\u5F8C\u306B\u79FB\u3063\
    \u305F\u7BC0\u70B9\u306E\u533A\u9593\u306E\u5411\u304D\u3092\u76F4\u3059\n   \
    \     int lo = k << 1;\n        if (lo + 1 < n && comp(d[lo + 1], d[lo])) swap(d[lo],\
    \ d[lo + 1]);\n    }\n\n    void down_max() {\n        int n = d.size();\n   \
    \     int k = 0;\n        while (true) {\n            int hi = k << 1 | 1;\n \
    \           if (hi < n && comp(d[hi], d[hi - 1])) swap(d[hi], d[hi - 1]);\n  \
    \          int c = (k << 1) + 1;\n            if ((c << 1) >= n) break;\n    \
    \        // \u5B50\u306E\u53F3\u7AEF (\u8981\u7D20 1 \u500B\u306E\u7BC0\u70B9\u306A\
    \u3089\u5DE6\u7AEF)\n            int hc = std::min((c << 1) | 1, n - 1);\n   \
    \         if (((c + 1) << 1) < n) {\n                int hc2 = std::min(((c +\
    \ 1) << 1) | 1, n - 1);\n                if (comp(d[hc], d[hc2])) hc = hc2, c++;\n\
    \            }\n            if (!comp(d[hi], d[hc])) break;\n            swap(d[hc],\
    \ d[hi]);\n            k = c;\n        }\n        int hi = k << 1 | 1;\n     \
    \   if (hi < n && comp(d[hi], d[hi - 1])) swap(d[hi], d[hi - 1]);\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// Interval Heap (\u4E21\u7AEF\
    \u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC)\n// \u6700\u5C0F\u5024\u30FB\
    \u6700\u5927\u5024\u306E\u53D6\u5F97\u3092 O(1)\uFF0C\u633F\u5165\u30FB\u6700\u5C0F\
    \u5024\u306E\u524A\u9664\u30FB\u6700\u5927\u5024\u306E\u524A\u9664\u3092 O(log\
    \ n) \u3067\u51E6\u7406\u3059\u308B\n// \u7BC0\u70B9 k \u304C d[2k] (\u533A\u9593\
    \u306E\u5DE6\u7AEF) \u3068 d[2k+1] (\u533A\u9593\u306E\u53F3\u7AEF) \u3092\u6301\
    \u3061\uFF0C\n// \u5DE6\u7AEF\u3060\u3051\u3092\u898B\u308B\u3068 min-heap\uFF0C\
    \u53F3\u7AEF\u3060\u3051\u3092\u898B\u308B\u3068 max-heap \u306B\u306A\u3063\u3066\
    \u3044\u308B\ntemplate <class T, class Compare = less<T>>\nstruct IntervalHeap\
    \ {\n    vector<T> d;\n    Compare comp;\n\n    IntervalHeap(Compare comp = Compare())\
    \ : comp(comp) {}\n\n    IntervalHeap(const vector<T> &a, Compare comp = Compare())\
    \ : comp(comp) {\n        d.reserve(a.size());\n        for (const T &x : a) push(x);\n\
    \    }\n\n    int size() const { return d.size(); }\n    bool empty() const {\
    \ return d.empty(); }\n    void reserve(int n) { d.reserve(n); }\n    void clear()\
    \ { d.clear(); }\n\n    const T &min() const { return d[0]; }\n    const T &max()\
    \ const { return d.size() == 1 ? d[0] : d[1]; }\n\n    void push(const T &x) {\n\
    \        int i = d.size();\n        d.push_back(x);\n        if (i & 1) {\n  \
    \          // \u7BC0\u70B9 i/2 \u306E\u53F3\u7AEF\u306B\u5165\u3063\u305F\n  \
    \          if (comp(d[i], d[i - 1])) {\n                swap(d[i], d[i - 1]);\n\
    \                up_min(i - 1);\n            } else {\n                up_max(i);\n\
    \            }\n        } else {\n            // \u65B0\u3057\u3044\u7BC0\u70B9\
    \u304C\u3067\u304D\u305F (\u8981\u7D20 1 \u500B\u306A\u306E\u3067\u5DE6\u7AEF\u304B\
    \u3064\u53F3\u7AEF)\n            if (i == 0) return;\n            int p = (((i\
    \ >> 1) - 1) >> 1) << 1;\n            if (comp(d[i], d[p])) up_min(i);\n     \
    \       else if (comp(d[p + 1], d[i])) up_max(i);\n        }\n    }\n\n    T pop_min()\
    \ {\n        T res = std::move(d[0]);\n        T last = std::move(d.back());\n\
    \        d.pop_back();\n        if (!d.empty()) {\n            d[0] = std::move(last);\n\
    \            down_min();\n        }\n        return res;\n    }\n\n    T pop_max()\
    \ {\n        if (d.size() <= 2) {\n            T res = std::move(d.back());\n\
    \            d.pop_back();\n            return res;\n        }\n        T res\
    \ = std::move(d[1]);\n        T last = std::move(d.back());\n        d.pop_back();\n\
    \        d[1] = std::move(last);\n        down_max();\n        return res;\n \
    \   }\n\n  private:\n    // \u4F4D\u7F6E i (\u5DE6\u7AEF) \u306E\u8981\u7D20\u3092\
    \ min-heap \u3068\u3057\u3066\u4E0A\u3052\u308B\n    void up_min(int i) {\n  \
    \      T x = std::move(d[i]);\n        int k = i >> 1;\n        while (k > 0)\
    \ {\n            int p = (k - 1) >> 1;\n            if (!comp(x, d[p << 1])) break;\n\
    \            d[k << 1] = std::move(d[p << 1]);\n            k = p;\n        }\n\
    \        d[k << 1] = std::move(x);\n    }\n\n    // \u4F4D\u7F6E i (\u53F3\u7AEF\
    \uFF0E\u8981\u7D20 1 \u500B\u306E\u7BC0\u70B9\u306A\u3089\u5DE6\u7AEF) \u306E\u8981\
    \u7D20\u3092 max-heap \u3068\u3057\u3066\u4E0A\u3052\u308B\n    void up_max(int\
    \ i) {\n        T x = std::move(d[i]);\n        int k = i >> 1;\n        int pos\
    \ = i;\n        while (k > 0) {\n            int p = (k - 1) >> 1;\n         \
    \   if (!comp(d[p << 1 | 1], x)) break;\n            d[pos] = std::move(d[p <<\
    \ 1 | 1]);\n            pos = p << 1 | 1;\n            k = p;\n        }\n   \
    \     d[pos] = std::move(x);\n    }\n\n    void down_min() {\n        int n =\
    \ d.size();\n        int k = 0;\n        while (true) {\n            int lo =\
    \ k << 1;\n            if (lo + 1 < n && comp(d[lo + 1], d[lo])) swap(d[lo], d[lo\
    \ + 1]);\n            int c = (k << 1) + 1;\n            if ((c << 1) >= n) break;\n\
    \            if (((c + 1) << 1) < n && comp(d[(c + 1) << 1], d[c << 1])) c++;\n\
    \            if (!comp(d[c << 1], d[lo])) break;\n            swap(d[c << 1],\
    \ d[lo]);\n            k = c;\n        }\n        // \u6700\u5F8C\u306B\u79FB\u3063\
    \u305F\u7BC0\u70B9\u306E\u533A\u9593\u306E\u5411\u304D\u3092\u76F4\u3059\n   \
    \     int lo = k << 1;\n        if (lo + 1 < n && comp(d[lo + 1], d[lo])) swap(d[lo],\
    \ d[lo + 1]);\n    }\n\n    void down_max() {\n        int n = d.size();\n   \
    \     int k = 0;\n        while (true) {\n            int hi = k << 1 | 1;\n \
    \           if (hi < n && comp(d[hi], d[hi - 1])) swap(d[hi], d[hi - 1]);\n  \
    \          int c = (k << 1) + 1;\n            if ((c << 1) >= n) break;\n    \
    \        // \u5B50\u306E\u53F3\u7AEF (\u8981\u7D20 1 \u500B\u306E\u7BC0\u70B9\u306A\
    \u3089\u5DE6\u7AEF)\n            int hc = std::min((c << 1) | 1, n - 1);\n   \
    \         if (((c + 1) << 1) < n) {\n                int hc2 = std::min(((c +\
    \ 1) << 1) | 1, n - 1);\n                if (comp(d[hc], d[hc2])) hc = hc2, c++;\n\
    \            }\n            if (!comp(d[hi], d[hc])) break;\n            swap(d[hc],\
    \ d[hi]);\n            k = c;\n        }\n        int hi = k << 1 | 1;\n     \
    \   if (hi < n && comp(d[hi], d[hi - 1])) swap(d[hi], d[hi - 1]);\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/interval_heap.hpp
  requiredBy: []
  timestamp: '2026-10-12 11:00:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/double_ended_priority_queue.test.cpp
  - test/unittest/interval_heap.test.cpp
documentation_of: data_structure/interval_heap.hpp
layout: document
title: "Interval Heap (\u4E21\u7AEF\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC\
  )"
---

## 概要

最小値と最大値の両方を取り出せる優先度付きキュー。1 本の配列で持ち、節点 $k$ が区間 $[d_{2k}, d_{2k+1}]$ を持つ。左端だけ見ると min-heap、右端だけ見ると max-heap になっている。
`std::multiset` よりはるかに速く、`priority_queue` 2 本 + 遅延削除よりもメモリが少なく速い。

## 使い方

```cpp
IntervalHeap<int> hp;               // 比較関数を渡すことも可 (IntervalHeap<T, Compare>)
IntervalHeap<int> hp2(a);           // vector から構築
hp.reserve(n);
hp.push(x);
hp.min(); hp.max();                 // 参照 (空でないこと)
hp.pop_min(); hp.pop_max();         // 取り出して値を返す (空でないこと)
hp.size(); hp.empty(); hp.clear();
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `IntervalHeap<T, Compare = less<T>>()` | 空で初期化 | $O(1)$ |
| `IntervalHeap(const vector<T> &a)` | `a` の要素を入れて初期化 | $O(n \log n)$ |
| `void push(T x)` | `x` を追加 | $O(\log n)$ |
| `const T &min()` / `const T &max()` | 最小値 / 最大値 | $O(1)$ |
| `T pop_min()` / `T pop_max()` | 最小値 / 最大値を取り出す | $O(\log n)$ |
| `int size()` / `bool empty()` | 要素数 / 空か | $O(1)$ |
| `void reserve(int n)` / `void clear()` | 容量確保 / 全削除 | - |

## 注意

- `min` / `max` / `pop_min` / `pop_max` は空でないときに呼ぶこと。
- 要素数 1 のときは最小値と最大値は同じ要素。
