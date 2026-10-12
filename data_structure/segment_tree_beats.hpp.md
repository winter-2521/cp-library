---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/range_chmin_chmax_add_range_sum.test.cpp
    title: test/range_chmin_chmax_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/segment_tree_beats.test.cpp
    title: test/unittest/segment_tree_beats.test.cpp
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
    \ 3 \"data_structure/segment_tree_beats.hpp\"\n\n// Segment Tree Beats\n// \u533A\
    \u9593 chmin\u30FB\u533A\u9593 chmax\u30FB\u533A\u9593\u52A0\u7B97\u30FB\u533A\
    \u9593\u4EE3\u5165\u3068\uFF0C\u533A\u9593\u548C\u30FB\u533A\u9593\u6700\u5C0F\
    \u5024\u30FB\u533A\u9593\u6700\u5927\u5024\u3092\u51E6\u7406\u3059\u308B\n// \u8A08\
    \u7B97\u91CF\u306F\u306A\u3089\u3057 O((n + q) log^2 n) (\u52A0\u7B97\u304C\u306A\
    \u3051\u308C\u3070 O((n + q) log n))\ntemplate <class T = long long>\nstruct SegmentTreeBeats\
    \ {\n    static constexpr T INF = numeric_limits<T>::max();\n    static constexpr\
    \ T NINF = numeric_limits<T>::lowest();\n    int n, sz;\n    // mx1 / mx2: \u6700\
    \u5927\u5024\u3068 2 \u756A\u76EE\u306E\u6700\u5927\u5024 (\u306A\u3051\u308C\u3070\
    \ NINF)\uFF0Cmxc: \u6700\u5927\u5024\u306E\u500B\u6570\uFF0Emin \u3082\u540C\u69D8\
    \n    vector<T> mx1, mx2, mn1, mn2, sm, lz;\n    vector<int> mxc, mnc, len;\n\n\
    \    SegmentTreeBeats(int n = 0) : SegmentTreeBeats(vector<T>(n, T(0))) {}\n\n\
    \    SegmentTreeBeats(const vector<T> &a) : n(a.size()) {\n        sz = 1;\n \
    \       while (sz < n) sz <<= 1;\n        mx1.assign(2 * sz, NINF), mx2.assign(2\
    \ * sz, NINF), mn1.assign(2 * sz, INF), mn2.assign(2 * sz, INF);\n        sm.assign(2\
    \ * sz, T(0)), lz.assign(2 * sz, T(0));\n        mxc.assign(2 * sz, 0), mnc.assign(2\
    \ * sz, 0), len.assign(2 * sz, 0);\n        for (int i = 0; i < n; i++) {\n  \
    \          int k = sz + i;\n            mx1[k] = mn1[k] = sm[k] = a[i];\n    \
    \        mxc[k] = mnc[k] = len[k] = 1;\n        }\n        for (int k = sz - 1;\
    \ k >= 1; k--) {\n            len[k] = len[2 * k] + len[2 * k + 1];\n        \
    \    update(k);\n        }\n    }\n\n    int size() const { return n; }\n\n  \
    \  // i in [l, r) \u306B\u3064\u3044\u3066 a[i] = min(a[i], x)\n    void chmin(int\
    \ l, int r, T x) { chmin(l, r, x, 1, 0, sz); }\n    // i in [l, r) \u306B\u3064\
    \u3044\u3066 a[i] = max(a[i], x)\n    void chmax(int l, int r, T x) { chmax(l,\
    \ r, x, 1, 0, sz); }\n    // i in [l, r) \u306B\u3064\u3044\u3066 a[i] += x\n\
    \    void add(int l, int r, T x) { add(l, r, x, 1, 0, sz); }\n    // i in [l,\
    \ r) \u306B\u3064\u3044\u3066 a[i] = x\n    void assign(int l, int r, T x) {\n\
    \        chmin(l, r, x);\n        chmax(l, r, x);\n    }\n\n    // a[l] + ...\
    \ + a[r-1]\n    T sum(int l, int r) { return sum(l, r, 1, 0, sz); }\n    // min(a[l],\
    \ ..., a[r-1])\uFF0El == r \u306A\u3089 INF\n    T min(int l, int r) { return\
    \ get_min(l, r, 1, 0, sz); }\n    // max(a[l], ..., a[r-1])\uFF0El == r \u306A\
    \u3089 NINF\n    T max(int l, int r) { return get_max(l, r, 1, 0, sz); }\n   \
    \ T get(int i) { return sum(i, i + 1); }\n\n  private:\n    void update(int k)\
    \ {\n        int a = 2 * k, b = 2 * k + 1;\n        sm[k] = sm[a] + sm[b];\n \
    \       if (mx1[a] > mx1[b]) mx1[k] = mx1[a], mxc[k] = mxc[a], mx2[k] = std::max(mx2[a],\
    \ mx1[b]);\n        else if (mx1[a] < mx1[b]) mx1[k] = mx1[b], mxc[k] = mxc[b],\
    \ mx2[k] = std::max(mx1[a], mx2[b]);\n        else mx1[k] = mx1[a], mxc[k] = mxc[a]\
    \ + mxc[b], mx2[k] = std::max(mx2[a], mx2[b]);\n        if (mn1[a] < mn1[b]) mn1[k]\
    \ = mn1[a], mnc[k] = mnc[a], mn2[k] = std::min(mn2[a], mn1[b]);\n        else\
    \ if (mn1[a] > mn1[b]) mn1[k] = mn1[b], mnc[k] = mnc[b], mn2[k] = std::min(mn1[a],\
    \ mn2[b]);\n        else mn1[k] = mn1[a], mnc[k] = mnc[a] + mnc[b], mn2[k] = std::min(mn2[a],\
    \ mn2[b]);\n    }\n    // \u6700\u5927\u5024\u3092 x \u306B\u3059\u308B (mx2 <\
    \ x < mx1)\n    void node_chmin(int k, T x) {\n        sm[k] += (x - mx1[k]) *\
    \ mxc[k];\n        if (mx1[k] == mn1[k]) mx1[k] = mn1[k] = x;\n        else if\
    \ (mx1[k] == mn2[k]) mx1[k] = mn2[k] = x;\n        else mx1[k] = x;\n    }\n \
    \   // \u6700\u5C0F\u5024\u3092 x \u306B\u3059\u308B (mn1 < x < mn2)\n    void\
    \ node_chmax(int k, T x) {\n        sm[k] += (x - mn1[k]) * mnc[k];\n        if\
    \ (mx1[k] == mn1[k]) mx1[k] = mn1[k] = x;\n        else if (mx2[k] == mn1[k])\
    \ mn1[k] = mx2[k] = x;\n        else mn1[k] = x;\n    }\n    void node_add(int\
    \ k, T x) {\n        if (len[k] == 0) return;\n        mx1[k] += x, mn1[k] +=\
    \ x;\n        if (mx2[k] != NINF) mx2[k] += x;\n        if (mn2[k] != INF) mn2[k]\
    \ += x;\n        sm[k] += x * len[k];\n        lz[k] += x;\n    }\n    void push(int\
    \ k) {\n        int a = 2 * k, b = 2 * k + 1;\n        if (lz[k] != 0) {\n   \
    \         node_add(a, lz[k]), node_add(b, lz[k]);\n            lz[k] = 0;\n  \
    \      }\n        if (mx1[a] > mx1[k]) node_chmin(a, mx1[k]);\n        if (mx1[b]\
    \ > mx1[k]) node_chmin(b, mx1[k]);\n        if (mn1[a] < mn1[k]) node_chmax(a,\
    \ mn1[k]);\n        if (mn1[b] < mn1[k]) node_chmax(b, mn1[k]);\n    }\n\n   \
    \ void chmin(int l, int r, T x, int k, int lo, int hi) {\n        if (r <= lo\
    \ || hi <= l || mx1[k] <= x) return;\n        if (l <= lo && hi <= r && mx2[k]\
    \ < x) {\n            node_chmin(k, x);\n            return;\n        }\n    \
    \    push(k);\n        int mid = (lo + hi) >> 1;\n        chmin(l, r, x, 2 * k,\
    \ lo, mid);\n        chmin(l, r, x, 2 * k + 1, mid, hi);\n        update(k);\n\
    \    }\n    void chmax(int l, int r, T x, int k, int lo, int hi) {\n        if\
    \ (r <= lo || hi <= l || mn1[k] >= x) return;\n        if (l <= lo && hi <= r\
    \ && mn2[k] > x) {\n            node_chmax(k, x);\n            return;\n     \
    \   }\n        push(k);\n        int mid = (lo + hi) >> 1;\n        chmax(l, r,\
    \ x, 2 * k, lo, mid);\n        chmax(l, r, x, 2 * k + 1, mid, hi);\n        update(k);\n\
    \    }\n    void add(int l, int r, T x, int k, int lo, int hi) {\n        if (r\
    \ <= lo || hi <= l) return;\n        if (l <= lo && hi <= r) {\n            node_add(k,\
    \ x);\n            return;\n        }\n        push(k);\n        int mid = (lo\
    \ + hi) >> 1;\n        add(l, r, x, 2 * k, lo, mid);\n        add(l, r, x, 2 *\
    \ k + 1, mid, hi);\n        update(k);\n    }\n    T sum(int l, int r, int k,\
    \ int lo, int hi) {\n        if (r <= lo || hi <= l) return T(0);\n        if\
    \ (l <= lo && hi <= r) return sm[k];\n        push(k);\n        int mid = (lo\
    \ + hi) >> 1;\n        return sum(l, r, 2 * k, lo, mid) + sum(l, r, 2 * k + 1,\
    \ mid, hi);\n    }\n    T get_min(int l, int r, int k, int lo, int hi) {\n   \
    \     if (r <= lo || hi <= l) return INF;\n        if (l <= lo && hi <= r) return\
    \ mn1[k];\n        push(k);\n        int mid = (lo + hi) >> 1;\n        return\
    \ std::min(get_min(l, r, 2 * k, lo, mid), get_min(l, r, 2 * k + 1, mid, hi));\n\
    \    }\n    T get_max(int l, int r, int k, int lo, int hi) {\n        if (r <=\
    \ lo || hi <= l) return NINF;\n        if (l <= lo && hi <= r) return mx1[k];\n\
    \        push(k);\n        int mid = (lo + hi) >> 1;\n        return std::max(get_max(l,\
    \ r, 2 * k, lo, mid), get_max(l, r, 2 * k + 1, mid, hi));\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// Segment Tree Beats\n// \u533A\
    \u9593 chmin\u30FB\u533A\u9593 chmax\u30FB\u533A\u9593\u52A0\u7B97\u30FB\u533A\
    \u9593\u4EE3\u5165\u3068\uFF0C\u533A\u9593\u548C\u30FB\u533A\u9593\u6700\u5C0F\
    \u5024\u30FB\u533A\u9593\u6700\u5927\u5024\u3092\u51E6\u7406\u3059\u308B\n// \u8A08\
    \u7B97\u91CF\u306F\u306A\u3089\u3057 O((n + q) log^2 n) (\u52A0\u7B97\u304C\u306A\
    \u3051\u308C\u3070 O((n + q) log n))\ntemplate <class T = long long>\nstruct SegmentTreeBeats\
    \ {\n    static constexpr T INF = numeric_limits<T>::max();\n    static constexpr\
    \ T NINF = numeric_limits<T>::lowest();\n    int n, sz;\n    // mx1 / mx2: \u6700\
    \u5927\u5024\u3068 2 \u756A\u76EE\u306E\u6700\u5927\u5024 (\u306A\u3051\u308C\u3070\
    \ NINF)\uFF0Cmxc: \u6700\u5927\u5024\u306E\u500B\u6570\uFF0Emin \u3082\u540C\u69D8\
    \n    vector<T> mx1, mx2, mn1, mn2, sm, lz;\n    vector<int> mxc, mnc, len;\n\n\
    \    SegmentTreeBeats(int n = 0) : SegmentTreeBeats(vector<T>(n, T(0))) {}\n\n\
    \    SegmentTreeBeats(const vector<T> &a) : n(a.size()) {\n        sz = 1;\n \
    \       while (sz < n) sz <<= 1;\n        mx1.assign(2 * sz, NINF), mx2.assign(2\
    \ * sz, NINF), mn1.assign(2 * sz, INF), mn2.assign(2 * sz, INF);\n        sm.assign(2\
    \ * sz, T(0)), lz.assign(2 * sz, T(0));\n        mxc.assign(2 * sz, 0), mnc.assign(2\
    \ * sz, 0), len.assign(2 * sz, 0);\n        for (int i = 0; i < n; i++) {\n  \
    \          int k = sz + i;\n            mx1[k] = mn1[k] = sm[k] = a[i];\n    \
    \        mxc[k] = mnc[k] = len[k] = 1;\n        }\n        for (int k = sz - 1;\
    \ k >= 1; k--) {\n            len[k] = len[2 * k] + len[2 * k + 1];\n        \
    \    update(k);\n        }\n    }\n\n    int size() const { return n; }\n\n  \
    \  // i in [l, r) \u306B\u3064\u3044\u3066 a[i] = min(a[i], x)\n    void chmin(int\
    \ l, int r, T x) { chmin(l, r, x, 1, 0, sz); }\n    // i in [l, r) \u306B\u3064\
    \u3044\u3066 a[i] = max(a[i], x)\n    void chmax(int l, int r, T x) { chmax(l,\
    \ r, x, 1, 0, sz); }\n    // i in [l, r) \u306B\u3064\u3044\u3066 a[i] += x\n\
    \    void add(int l, int r, T x) { add(l, r, x, 1, 0, sz); }\n    // i in [l,\
    \ r) \u306B\u3064\u3044\u3066 a[i] = x\n    void assign(int l, int r, T x) {\n\
    \        chmin(l, r, x);\n        chmax(l, r, x);\n    }\n\n    // a[l] + ...\
    \ + a[r-1]\n    T sum(int l, int r) { return sum(l, r, 1, 0, sz); }\n    // min(a[l],\
    \ ..., a[r-1])\uFF0El == r \u306A\u3089 INF\n    T min(int l, int r) { return\
    \ get_min(l, r, 1, 0, sz); }\n    // max(a[l], ..., a[r-1])\uFF0El == r \u306A\
    \u3089 NINF\n    T max(int l, int r) { return get_max(l, r, 1, 0, sz); }\n   \
    \ T get(int i) { return sum(i, i + 1); }\n\n  private:\n    void update(int k)\
    \ {\n        int a = 2 * k, b = 2 * k + 1;\n        sm[k] = sm[a] + sm[b];\n \
    \       if (mx1[a] > mx1[b]) mx1[k] = mx1[a], mxc[k] = mxc[a], mx2[k] = std::max(mx2[a],\
    \ mx1[b]);\n        else if (mx1[a] < mx1[b]) mx1[k] = mx1[b], mxc[k] = mxc[b],\
    \ mx2[k] = std::max(mx1[a], mx2[b]);\n        else mx1[k] = mx1[a], mxc[k] = mxc[a]\
    \ + mxc[b], mx2[k] = std::max(mx2[a], mx2[b]);\n        if (mn1[a] < mn1[b]) mn1[k]\
    \ = mn1[a], mnc[k] = mnc[a], mn2[k] = std::min(mn2[a], mn1[b]);\n        else\
    \ if (mn1[a] > mn1[b]) mn1[k] = mn1[b], mnc[k] = mnc[b], mn2[k] = std::min(mn1[a],\
    \ mn2[b]);\n        else mn1[k] = mn1[a], mnc[k] = mnc[a] + mnc[b], mn2[k] = std::min(mn2[a],\
    \ mn2[b]);\n    }\n    // \u6700\u5927\u5024\u3092 x \u306B\u3059\u308B (mx2 <\
    \ x < mx1)\n    void node_chmin(int k, T x) {\n        sm[k] += (x - mx1[k]) *\
    \ mxc[k];\n        if (mx1[k] == mn1[k]) mx1[k] = mn1[k] = x;\n        else if\
    \ (mx1[k] == mn2[k]) mx1[k] = mn2[k] = x;\n        else mx1[k] = x;\n    }\n \
    \   // \u6700\u5C0F\u5024\u3092 x \u306B\u3059\u308B (mn1 < x < mn2)\n    void\
    \ node_chmax(int k, T x) {\n        sm[k] += (x - mn1[k]) * mnc[k];\n        if\
    \ (mx1[k] == mn1[k]) mx1[k] = mn1[k] = x;\n        else if (mx2[k] == mn1[k])\
    \ mn1[k] = mx2[k] = x;\n        else mn1[k] = x;\n    }\n    void node_add(int\
    \ k, T x) {\n        if (len[k] == 0) return;\n        mx1[k] += x, mn1[k] +=\
    \ x;\n        if (mx2[k] != NINF) mx2[k] += x;\n        if (mn2[k] != INF) mn2[k]\
    \ += x;\n        sm[k] += x * len[k];\n        lz[k] += x;\n    }\n    void push(int\
    \ k) {\n        int a = 2 * k, b = 2 * k + 1;\n        if (lz[k] != 0) {\n   \
    \         node_add(a, lz[k]), node_add(b, lz[k]);\n            lz[k] = 0;\n  \
    \      }\n        if (mx1[a] > mx1[k]) node_chmin(a, mx1[k]);\n        if (mx1[b]\
    \ > mx1[k]) node_chmin(b, mx1[k]);\n        if (mn1[a] < mn1[k]) node_chmax(a,\
    \ mn1[k]);\n        if (mn1[b] < mn1[k]) node_chmax(b, mn1[k]);\n    }\n\n   \
    \ void chmin(int l, int r, T x, int k, int lo, int hi) {\n        if (r <= lo\
    \ || hi <= l || mx1[k] <= x) return;\n        if (l <= lo && hi <= r && mx2[k]\
    \ < x) {\n            node_chmin(k, x);\n            return;\n        }\n    \
    \    push(k);\n        int mid = (lo + hi) >> 1;\n        chmin(l, r, x, 2 * k,\
    \ lo, mid);\n        chmin(l, r, x, 2 * k + 1, mid, hi);\n        update(k);\n\
    \    }\n    void chmax(int l, int r, T x, int k, int lo, int hi) {\n        if\
    \ (r <= lo || hi <= l || mn1[k] >= x) return;\n        if (l <= lo && hi <= r\
    \ && mn2[k] > x) {\n            node_chmax(k, x);\n            return;\n     \
    \   }\n        push(k);\n        int mid = (lo + hi) >> 1;\n        chmax(l, r,\
    \ x, 2 * k, lo, mid);\n        chmax(l, r, x, 2 * k + 1, mid, hi);\n        update(k);\n\
    \    }\n    void add(int l, int r, T x, int k, int lo, int hi) {\n        if (r\
    \ <= lo || hi <= l) return;\n        if (l <= lo && hi <= r) {\n            node_add(k,\
    \ x);\n            return;\n        }\n        push(k);\n        int mid = (lo\
    \ + hi) >> 1;\n        add(l, r, x, 2 * k, lo, mid);\n        add(l, r, x, 2 *\
    \ k + 1, mid, hi);\n        update(k);\n    }\n    T sum(int l, int r, int k,\
    \ int lo, int hi) {\n        if (r <= lo || hi <= l) return T(0);\n        if\
    \ (l <= lo && hi <= r) return sm[k];\n        push(k);\n        int mid = (lo\
    \ + hi) >> 1;\n        return sum(l, r, 2 * k, lo, mid) + sum(l, r, 2 * k + 1,\
    \ mid, hi);\n    }\n    T get_min(int l, int r, int k, int lo, int hi) {\n   \
    \     if (r <= lo || hi <= l) return INF;\n        if (l <= lo && hi <= r) return\
    \ mn1[k];\n        push(k);\n        int mid = (lo + hi) >> 1;\n        return\
    \ std::min(get_min(l, r, 2 * k, lo, mid), get_min(l, r, 2 * k + 1, mid, hi));\n\
    \    }\n    T get_max(int l, int r, int k, int lo, int hi) {\n        if (r <=\
    \ lo || hi <= l) return NINF;\n        if (l <= lo && hi <= r) return mx1[k];\n\
    \        push(k);\n        int mid = (lo + hi) >> 1;\n        return std::max(get_max(l,\
    \ r, 2 * k, lo, mid), get_max(l, r, 2 * k + 1, mid, hi));\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/segment_tree_beats.hpp
  requiredBy: []
  timestamp: '2026-10-12 11:35:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/segment_tree_beats.test.cpp
  - test/range_chmin_chmax_add_range_sum.test.cpp
documentation_of: data_structure/segment_tree_beats.hpp
layout: document
title: Segment Tree Beats
---

## 概要

区間 chmin・区間 chmax・区間加算・区間代入と、区間和・区間最小値・区間最大値を処理する。

各ノードに最大値・2 番目の最大値・最大値の個数（最小値側も同様）と和を持つ。区間 chmin($x$) で、ノードの「2 番目の最大値 $< x <$ 最大値」なら最大値の要素だけが変わるので、そのノードで止められる。そうでなければ子に降りる。
降りる回数はポテンシャル（各ノードの部分木内の値の種類数の和）で評価でき、ならし $O((n + q) \log^2 n)$（加算がなければ $O((n + q) \log n)$）。

## 使い方

```cpp
SegmentTreeBeats<long long> seg(a);   // vector<long long> a
seg.chmin(l, r, x);   // a[i] = min(a[i], x)
seg.chmax(l, r, x);   // a[i] = max(a[i], x)
seg.add(l, r, x);     // a[i] += x
seg.assign(l, r, x);  // a[i] = x
seg.sum(l, r); seg.min(l, r); seg.max(l, r); seg.get(i);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `SegmentTreeBeats<T>(const vector<T> &a)` / `(int n)` | 構築 | $O(n)$ |
| `void chmin(int l, int r, T x)` / `void chmax(int l, int r, T x)` | 区間 chmin / chmax | ならし $O(\log^2 n)$ |
| `void add(int l, int r, T x)` | 区間加算 | $O(\log n)$（ならし評価に影響） |
| `void assign(int l, int r, T x)` | 区間代入（chmin と chmax の組み合わせ） | ならし $O(\log^2 n)$ |
| `T sum(int l, int r)` / `T min(int l, int r)` / `T max(int l, int r)` | 区間和 / 最小 / 最大 | $O(\log n)$ |
| `T get(int i)` | $a_i$ | $O(\log n)$ |

## 注意

- 和がオーバーフローしないよう `T` を選ぶこと（$|a_i| \le 10^{12}$、$n = 2 \times 10^5$ なら `long long` で足りる）。
