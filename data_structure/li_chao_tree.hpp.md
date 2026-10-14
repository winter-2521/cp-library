---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/line_add_get_min.test.cpp
    title: test/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_add_get_min.test.cpp
    title: test/segment_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_add_get_min_offline.test.cpp
    title: test/segment_add_get_min_offline.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/li_chao_tree.test.cpp
    title: test/unittest/li_chao_tree.test.cpp
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
    \ 3 \"data_structure/li_chao_tree.hpp\"\n\n// Li Chao Tree (\u76F4\u7DDA\u30FB\
    \u7DDA\u5206\u306E\u8FFD\u52A0\uFF0C\u3042\u308B x \u3067\u306E\u6700\u5C0F\u5024\
    )\n// 2 \u7A2E\u985E\u3042\u308B:\n//   DynamicLiChaoTree<T>(xlo, xhi) : x \u2208\
    \ [xlo, xhi) \u306E\u6574\u6570\uFF0E\u30CE\u30FC\u30C9\u3092\u5FC5\u8981\u306A\
    \u5206\u3060\u3051\u4F5C\u308B (\u30AA\u30F3\u30E9\u30A4\u30F3)\n//   LiChaoTree<T>(xs)\
    \             : x \u304C xs \u306E\u3069\u308C\u304B (\u5148\u8AAD\u307F\u3067\
    \u304D\u308B\u3068\u304D\uFF0E\u914D\u5217\u3067\u6301\u3064\u306E\u3067\u901F\
    \u3044)\n// MAX = true \u306A\u3089\u6700\u5927\u5024\uFF0ET \u306F\u5024\u306E\
    \u578B (a x + b \u304C T \u306B\u53CE\u307E\u308B\u3053\u3068)\n\n// \u76F4\u7DDA\
    \ y = a x + b\ntemplate <class T>\nstruct LiChaoLine {\n    T a, b;\n    T operator()(T\
    \ x) const { return a * x + b; }\n};\n\ntemplate <class T, bool MAX = false>\n\
    struct DynamicLiChaoTree {\n    using Line = LiChaoLine<T>;\n    struct Node {\n\
    \        Line f;\n        int ch[2];\n    };\n    static constexpr T INF = MAX\
    \ ? numeric_limits<T>::lowest() : numeric_limits<T>::max();\n    T xlo, xhi;\n\
    \    vector<Node> d;  // d[0] \u306F\u756A\u5175 (\u76F4\u7DDA\u306A\u3057)\n\
    \    int root = 0;\n\n    DynamicLiChaoTree(T xlo, T xhi) : xlo(xlo), xhi(xhi)\
    \ { d.push_back({{0, INF}, {0, 0}}); }\n\n    void reserve(int n) { d.reserve(n);\
    \ }\n\n    // \u76F4\u7DDA y = a x + b \u3092\u8FFD\u52A0\n    void add_line(T\
    \ a, T b) { root = insert(root, xlo, xhi, {a, b}); }\n\n    // \u7DDA\u5206 y\
    \ = a x + b (x \u2208 [l, r)) \u3092\u8FFD\u52A0\n    void add_segment(T l, T\
    \ r, T a, T b) {\n        l = std::max(l, xlo), r = std::min(r, xhi);\n      \
    \  if (l < r) root = insert_seg(root, xlo, xhi, l, r, {a, b});\n    }\n\n    //\
    \ x \u3067\u306E\u6700\u5C0F\u5024 (\u6700\u5927\u5024)\uFF0E\u4F55\u3082\u306A\
    \u3051\u308C\u3070 INF (MAX \u306A\u3089 lowest)\n    T get(T x) const {\n   \
    \     int v = root;\n        T lo = xlo, hi = xhi;\n        T res = INF;\n   \
    \     while (v) {\n            T y = d[v].f(x);\n            if (better(y, res))\
    \ res = y;\n            T m = mid(lo, hi);\n            if (x < m) v = d[v].ch[0],\
    \ hi = m;\n            else v = d[v].ch[1], lo = m;\n        }\n        return\
    \ res;\n    }\n\n  private:\n    static bool better(T a, T b) { return MAX ? a\
    \ > b : a < b; }\n    static T mid(T lo, T hi) { return lo + (hi - lo) / 2; }\n\
    \n    int new_node(const Line &f) {\n        d.push_back({f, {0, 0}});\n     \
    \   return d.size() - 1;\n    }\n\n    // [lo, hi) \u3092\u62C5\u5F53\u3059\u308B\
    \u30CE\u30FC\u30C9 v \u306B\u76F4\u7DDA f \u3092\u5165\u308C\u308B\n    int insert(int\
    \ v, T lo, T hi, Line f) {\n        if (!v) return new_node(f);\n        int res\
    \ = v;\n        while (true) {\n            Line &g = d[v].f;\n            T m\
    \ = mid(lo, hi);\n            bool bl = better(f(lo), g(lo)), bm = better(f(m),\
    \ g(m));\n            if (bm) swap(f, g);\n            if (hi - lo == 1) break;\n\
    \            // \u4E2D\u592E\u3067\u8CA0\u3051\u305F\u65B9 f \u304C\u52DD\u3061\
    \u3046\u308B\u306E\u306F\u7247\u5074\u3060\u3051\n            int c;\n       \
    \     if (bl != bm) c = 0, hi = m;\n            else if (better(f(hi - 1), g(hi\
    \ - 1))) c = 1, lo = m;\n            else break;\n            if (!d[v].ch[c])\
    \ {\n                int u = new_node(f);\n                d[v].ch[c] = u;\n \
    \               break;\n            }\n            v = d[v].ch[c];\n        }\n\
    \        return res;\n    }\n\n    int insert_seg(int v, T lo, T hi, T l, T r,\
    \ const Line &f) {\n        if (r <= lo || hi <= l) return v;\n        if (l <=\
    \ lo && hi <= r) return insert(v, lo, hi, f);\n        if (!v) v = new_node({0,\
    \ INF});\n        T m = mid(lo, hi);\n        int c0 = insert_seg(d[v].ch[0],\
    \ lo, m, l, r, f);\n        d[v].ch[0] = c0;\n        int c1 = insert_seg(d[v].ch[1],\
    \ m, hi, l, r, f);\n        d[v].ch[1] = c1;\n        return v;\n    }\n};\n\n\
    template <class T, bool MAX = false>\nstruct LiChaoTree {\n    using Line = LiChaoLine<T>;\n\
    \    static constexpr T INF = MAX ? numeric_limits<T>::lowest() : numeric_limits<T>::max();\n\
    \    int n, sz;\n    vector<T> xs;     // \u5EA7\u6A19 (\u6607\u9806\u30FB\u91CD\
    \u8907\u306A\u3057)\uFF0E\u8449 i \u304C xs[i] \u3092\u62C5\u5F53 (i >= n \u306F\
    \ xs.back() \u3092\u8A70\u3081\u308B)\n    vector<Line> d;   // d[v]: \u30CE\u30FC\
    \u30C9 v \u306E\u76F4\u7DDA (\u306A\u3051\u308C\u3070 {0, INF})\n\n    LiChaoTree(vector<T>\
    \ xs_) : xs(xs_) {\n        sort(xs.begin(), xs.end());\n        xs.erase(unique(xs.begin(),\
    \ xs.end()), xs.end());\n        n = xs.size();\n        sz = 1;\n        while\
    \ (sz < std::max(n, 1)) sz <<= 1;\n        if (n == 0) xs.push_back(0);\n    \
    \    xs.resize(sz, xs.back());\n        d.assign(2 * sz, {0, INF});\n    }\n\n\
    \    // \u76F4\u7DDA y = a x + b \u3092\u8FFD\u52A0\n    void add_line(T a, T\
    \ b) { insert(1, 0, sz, {a, b}); }\n\n    // \u7DDA\u5206 y = a x + b (x \u2208\
    \ [l, r)) \u3092\u8FFD\u52A0\n    void add_segment(T l, T r, T a, T b) {\n   \
    \     int li = lower_bound(xs.begin(), xs.begin() + n, l) - xs.begin();\n    \
    \    int ri = lower_bound(xs.begin(), xs.begin() + n, r) - xs.begin();\n     \
    \   Line f{a, b};\n        for (int lv = li + sz, rv = ri + sz, w = 1; lv < rv;\
    \ lv >>= 1, rv >>= 1, w <<= 1) {\n            if (lv & 1) insert(lv, (lv - (sz\
    \ / w)) * w, (lv - (sz / w)) * w + w, f), lv++;\n            if (rv & 1) --rv,\
    \ insert(rv, (rv - (sz / w)) * w, (rv - (sz / w)) * w + w, f);\n        }\n  \
    \  }\n\n    // x \u3067\u306E\u6700\u5C0F\u5024 (\u6700\u5927\u5024)\uFF0Ex \u306F\
    \ xs \u306B\u542B\u307E\u308C\u308B\u3053\u3068\uFF0E\u4F55\u3082\u306A\u3051\u308C\
    \u3070 INF\n    T get(T x) const { return get_index(lower_bound(xs.begin(), xs.begin()\
    \ + n, x) - xs.begin()); }\n\n    // xs[i] \u3067\u306E\u6700\u5C0F\u5024\n  \
    \  T get_index(int i) const {\n        T x = xs[i], res = INF;\n        for (int\
    \ v = i + sz; v; v >>= 1) {\n            T y = d[v](x);\n            if (better(y,\
    \ res)) res = y;\n        }\n        return res;\n    }\n\n  private:\n    static\
    \ bool better(T a, T b) { return MAX ? a > b : a < b; }\n\n    // \u30CE\u30FC\
    \u30C9 v (\u8449\u306E\u6DFB\u5B57 [lo, hi)) \u306B\u76F4\u7DDA\u3092\u5165\u308C\
    \u308B\n    void insert(int v, int lo, int hi, Line f) {\n        while (true)\
    \ {\n            Line &g = d[v];\n            int m = (lo + hi) >> 1;\n      \
    \      bool bl = better(f(xs[lo]), g(xs[lo])), bm = better(f(xs[m]), g(xs[m]));\n\
    \            if (bm) swap(f, g);\n            if (hi - lo == 1) return;\n    \
    \        if (bl != bm) v = 2 * v, hi = m;\n            else if (better(f(xs[hi\
    \ - 1]), g(xs[hi - 1]))) v = 2 * v + 1, lo = m;\n            else return;\n  \
    \      }\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// Li Chao Tree (\u76F4\u7DDA\
    \u30FB\u7DDA\u5206\u306E\u8FFD\u52A0\uFF0C\u3042\u308B x \u3067\u306E\u6700\u5C0F\
    \u5024)\n// 2 \u7A2E\u985E\u3042\u308B:\n//   DynamicLiChaoTree<T>(xlo, xhi) :\
    \ x \u2208 [xlo, xhi) \u306E\u6574\u6570\uFF0E\u30CE\u30FC\u30C9\u3092\u5FC5\u8981\
    \u306A\u5206\u3060\u3051\u4F5C\u308B (\u30AA\u30F3\u30E9\u30A4\u30F3)\n//   LiChaoTree<T>(xs)\
    \             : x \u304C xs \u306E\u3069\u308C\u304B (\u5148\u8AAD\u307F\u3067\
    \u304D\u308B\u3068\u304D\uFF0E\u914D\u5217\u3067\u6301\u3064\u306E\u3067\u901F\
    \u3044)\n// MAX = true \u306A\u3089\u6700\u5927\u5024\uFF0ET \u306F\u5024\u306E\
    \u578B (a x + b \u304C T \u306B\u53CE\u307E\u308B\u3053\u3068)\n\n// \u76F4\u7DDA\
    \ y = a x + b\ntemplate <class T>\nstruct LiChaoLine {\n    T a, b;\n    T operator()(T\
    \ x) const { return a * x + b; }\n};\n\ntemplate <class T, bool MAX = false>\n\
    struct DynamicLiChaoTree {\n    using Line = LiChaoLine<T>;\n    struct Node {\n\
    \        Line f;\n        int ch[2];\n    };\n    static constexpr T INF = MAX\
    \ ? numeric_limits<T>::lowest() : numeric_limits<T>::max();\n    T xlo, xhi;\n\
    \    vector<Node> d;  // d[0] \u306F\u756A\u5175 (\u76F4\u7DDA\u306A\u3057)\n\
    \    int root = 0;\n\n    DynamicLiChaoTree(T xlo, T xhi) : xlo(xlo), xhi(xhi)\
    \ { d.push_back({{0, INF}, {0, 0}}); }\n\n    void reserve(int n) { d.reserve(n);\
    \ }\n\n    // \u76F4\u7DDA y = a x + b \u3092\u8FFD\u52A0\n    void add_line(T\
    \ a, T b) { root = insert(root, xlo, xhi, {a, b}); }\n\n    // \u7DDA\u5206 y\
    \ = a x + b (x \u2208 [l, r)) \u3092\u8FFD\u52A0\n    void add_segment(T l, T\
    \ r, T a, T b) {\n        l = std::max(l, xlo), r = std::min(r, xhi);\n      \
    \  if (l < r) root = insert_seg(root, xlo, xhi, l, r, {a, b});\n    }\n\n    //\
    \ x \u3067\u306E\u6700\u5C0F\u5024 (\u6700\u5927\u5024)\uFF0E\u4F55\u3082\u306A\
    \u3051\u308C\u3070 INF (MAX \u306A\u3089 lowest)\n    T get(T x) const {\n   \
    \     int v = root;\n        T lo = xlo, hi = xhi;\n        T res = INF;\n   \
    \     while (v) {\n            T y = d[v].f(x);\n            if (better(y, res))\
    \ res = y;\n            T m = mid(lo, hi);\n            if (x < m) v = d[v].ch[0],\
    \ hi = m;\n            else v = d[v].ch[1], lo = m;\n        }\n        return\
    \ res;\n    }\n\n  private:\n    static bool better(T a, T b) { return MAX ? a\
    \ > b : a < b; }\n    static T mid(T lo, T hi) { return lo + (hi - lo) / 2; }\n\
    \n    int new_node(const Line &f) {\n        d.push_back({f, {0, 0}});\n     \
    \   return d.size() - 1;\n    }\n\n    // [lo, hi) \u3092\u62C5\u5F53\u3059\u308B\
    \u30CE\u30FC\u30C9 v \u306B\u76F4\u7DDA f \u3092\u5165\u308C\u308B\n    int insert(int\
    \ v, T lo, T hi, Line f) {\n        if (!v) return new_node(f);\n        int res\
    \ = v;\n        while (true) {\n            Line &g = d[v].f;\n            T m\
    \ = mid(lo, hi);\n            bool bl = better(f(lo), g(lo)), bm = better(f(m),\
    \ g(m));\n            if (bm) swap(f, g);\n            if (hi - lo == 1) break;\n\
    \            // \u4E2D\u592E\u3067\u8CA0\u3051\u305F\u65B9 f \u304C\u52DD\u3061\
    \u3046\u308B\u306E\u306F\u7247\u5074\u3060\u3051\n            int c;\n       \
    \     if (bl != bm) c = 0, hi = m;\n            else if (better(f(hi - 1), g(hi\
    \ - 1))) c = 1, lo = m;\n            else break;\n            if (!d[v].ch[c])\
    \ {\n                int u = new_node(f);\n                d[v].ch[c] = u;\n \
    \               break;\n            }\n            v = d[v].ch[c];\n        }\n\
    \        return res;\n    }\n\n    int insert_seg(int v, T lo, T hi, T l, T r,\
    \ const Line &f) {\n        if (r <= lo || hi <= l) return v;\n        if (l <=\
    \ lo && hi <= r) return insert(v, lo, hi, f);\n        if (!v) v = new_node({0,\
    \ INF});\n        T m = mid(lo, hi);\n        int c0 = insert_seg(d[v].ch[0],\
    \ lo, m, l, r, f);\n        d[v].ch[0] = c0;\n        int c1 = insert_seg(d[v].ch[1],\
    \ m, hi, l, r, f);\n        d[v].ch[1] = c1;\n        return v;\n    }\n};\n\n\
    template <class T, bool MAX = false>\nstruct LiChaoTree {\n    using Line = LiChaoLine<T>;\n\
    \    static constexpr T INF = MAX ? numeric_limits<T>::lowest() : numeric_limits<T>::max();\n\
    \    int n, sz;\n    vector<T> xs;     // \u5EA7\u6A19 (\u6607\u9806\u30FB\u91CD\
    \u8907\u306A\u3057)\uFF0E\u8449 i \u304C xs[i] \u3092\u62C5\u5F53 (i >= n \u306F\
    \ xs.back() \u3092\u8A70\u3081\u308B)\n    vector<Line> d;   // d[v]: \u30CE\u30FC\
    \u30C9 v \u306E\u76F4\u7DDA (\u306A\u3051\u308C\u3070 {0, INF})\n\n    LiChaoTree(vector<T>\
    \ xs_) : xs(xs_) {\n        sort(xs.begin(), xs.end());\n        xs.erase(unique(xs.begin(),\
    \ xs.end()), xs.end());\n        n = xs.size();\n        sz = 1;\n        while\
    \ (sz < std::max(n, 1)) sz <<= 1;\n        if (n == 0) xs.push_back(0);\n    \
    \    xs.resize(sz, xs.back());\n        d.assign(2 * sz, {0, INF});\n    }\n\n\
    \    // \u76F4\u7DDA y = a x + b \u3092\u8FFD\u52A0\n    void add_line(T a, T\
    \ b) { insert(1, 0, sz, {a, b}); }\n\n    // \u7DDA\u5206 y = a x + b (x \u2208\
    \ [l, r)) \u3092\u8FFD\u52A0\n    void add_segment(T l, T r, T a, T b) {\n   \
    \     int li = lower_bound(xs.begin(), xs.begin() + n, l) - xs.begin();\n    \
    \    int ri = lower_bound(xs.begin(), xs.begin() + n, r) - xs.begin();\n     \
    \   Line f{a, b};\n        for (int lv = li + sz, rv = ri + sz, w = 1; lv < rv;\
    \ lv >>= 1, rv >>= 1, w <<= 1) {\n            if (lv & 1) insert(lv, (lv - (sz\
    \ / w)) * w, (lv - (sz / w)) * w + w, f), lv++;\n            if (rv & 1) --rv,\
    \ insert(rv, (rv - (sz / w)) * w, (rv - (sz / w)) * w + w, f);\n        }\n  \
    \  }\n\n    // x \u3067\u306E\u6700\u5C0F\u5024 (\u6700\u5927\u5024)\uFF0Ex \u306F\
    \ xs \u306B\u542B\u307E\u308C\u308B\u3053\u3068\uFF0E\u4F55\u3082\u306A\u3051\u308C\
    \u3070 INF\n    T get(T x) const { return get_index(lower_bound(xs.begin(), xs.begin()\
    \ + n, x) - xs.begin()); }\n\n    // xs[i] \u3067\u306E\u6700\u5C0F\u5024\n  \
    \  T get_index(int i) const {\n        T x = xs[i], res = INF;\n        for (int\
    \ v = i + sz; v; v >>= 1) {\n            T y = d[v](x);\n            if (better(y,\
    \ res)) res = y;\n        }\n        return res;\n    }\n\n  private:\n    static\
    \ bool better(T a, T b) { return MAX ? a > b : a < b; }\n\n    // \u30CE\u30FC\
    \u30C9 v (\u8449\u306E\u6DFB\u5B57 [lo, hi)) \u306B\u76F4\u7DDA\u3092\u5165\u308C\
    \u308B\n    void insert(int v, int lo, int hi, Line f) {\n        while (true)\
    \ {\n            Line &g = d[v];\n            int m = (lo + hi) >> 1;\n      \
    \      bool bl = better(f(xs[lo]), g(xs[lo])), bm = better(f(xs[m]), g(xs[m]));\n\
    \            if (bm) swap(f, g);\n            if (hi - lo == 1) return;\n    \
    \        if (bl != bm) v = 2 * v, hi = m;\n            else if (better(f(xs[hi\
    \ - 1]), g(xs[hi - 1]))) v = 2 * v + 1, lo = m;\n            else return;\n  \
    \      }\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2026-10-14 23:17:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment_add_get_min.test.cpp
  - test/unittest/li_chao_tree.test.cpp
  - test/line_add_get_min.test.cpp
  - test/segment_add_get_min_offline.test.cpp
documentation_of: data_structure/li_chao_tree.hpp
layout: document
title: Li Chao Tree
---

## 概要

直線 $y = ax + b$・線分 $y = ax + b \ (x \in [l, r))$ の追加と、ある $x$ での最小値（最大値）を求める。

セグメント木の各ノードに直線を高々 1 本置く。ノードに新しい直線が来たら、ノードの中央の $x$ で比べて勝った方をノードに残し、負けた方は「負けた方が勝ちうる側」の子へ降ろす（2 直線は 1 回しか交わらないので、勝ちうるのは片側だけ）。$x$ での値は、根から $x$ の葉まで降りながら各ノードの直線の値の最小値を取る。

2 種類ある。

| | `DynamicLiChaoTree<T>(xlo, xhi)` | `LiChaoTree<T>(xs)` |
| --- | --- | --- |
| 対象の $x$ | $[x_{lo}, x_{hi})$ の全整数 | 先に与えた座標 `xs` のどれか |
| ノード | 必要な分だけ作る | 配列（完全二分木） |
| オンライン | ○ | 問い合わせる $x$ を先読みする必要がある |
| 速さ | 遅め（特に線分はノードが多い） | 速い |

## 使い方

```cpp
DynamicLiChaoTree<long long> lct(-1000000000, 1000000001);   // x ∈ [-1e9, 1e9]
DynamicLiChaoTree<long long, true> lct_max(lo, hi);          // 最大値
lct.add_line(a, b);            // y = a x + b
lct.add_segment(l, r, a, b);   // y = a x + b (x ∈ [l, r))
lct.get(x);                    // 最小値．何もなければ numeric_limits<T>::max() (最大値版は lowest())

LiChaoTree<long long> st(xs);  // 問い合わせる x を全部渡す (ソート・重複はあってよい)
st.add_line(a, b); st.add_segment(l, r, a, b);
st.get(x);                     // x は xs に含まれること
st.get_index(i);               // ソート済み座標の i 番目での値
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `DynamicLiChaoTree<T, MAX = false>(T xlo, T xhi)` | $x \in [x_{lo}, x_{hi})$ で初期化 | $O(1)$ |
| `LiChaoTree<T, MAX = false>(vector<T> xs)` | 座標 `xs` で初期化 | $O(n \log n)$ |
| `void add_line(T a, T b)` | 直線を追加 | $O(\log C)$ / $O(\log n)$ |
| `void add_segment(T l, T r, T a, T b)` | 線分を追加 | $O(\log^2 C)$ / $O(\log^2 n)$ |
| `T get(T x)` | $x$ での最小値（最大値） | $O(\log C)$ / $O(\log n)$ |

$C = x_{hi} - x_{lo}$、$n$ は座標の個数。

## 注意

- $ax + b$ が `T` に収まること（Library Checker の制約 $|a|, |x| \le 10^9, |b| \le 10^{18}$ なら `long long` で収まる）。
- 動的版で直線を追加すると新しいノードは高々 1 個。線分は $O(\log C)$ 個のノードを作るので、線分 $4 \times 10^5$ 本・$C = 2 \times 10^9$ で手元 400 MB 程度使う。座標を先読みできるなら `LiChaoTree` を使うこと（手元で約 6 倍速い）。
