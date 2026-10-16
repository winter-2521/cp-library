---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/range_linear_add_range_min.test.cpp
    title: test/range_linear_add_range_min.test.cpp
  - icon: ':x:'
    path: test/unittest/linear_add_min_segment_tree.test.cpp
    title: test/unittest/linear_add_min_segment_tree.test.cpp
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
    \ 3 \"data_structure/linear_add_min_segment_tree.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u533A\u9593\u306B 1 \u6B21\u95A2\u6570 (b i + c) \u3092\u8DB3\u3059\u30FB\
    \u533A\u9593\u6700\u5C0F\u5024 (Range Linear Add Range Min)\n// \u70B9 (i, a_i)\
    \ \u306E\u4E0B\u5074\u51F8\u5305\u3092\uFF0C\u5404\u30CE\u30FC\u30C9\u306B\u300C\
    \u5DE6\u306E\u5B50\u306E\u51F8\u5305\u3068\u53F3\u306E\u5B50\u306E\u51F8\u5305\
    \u3092\u3064\u306A\u3050\u6A4B (bridge)\u300D\u3060\u3051\u6301\u3064\u5F62\u3067\
    \u8868\u3059\uFF0E\n// 1 \u6B21\u95A2\u6570\u3092\u8DB3\u3057\u3066\u3082\u51F8\
    \u5305\u306E\u5F62 (\u3069\u306E\u70B9\u304C\u9802\u70B9\u304B\u30FB\u6A4B) \u306F\
    \u5909\u308F\u3089\u306A\u3044\u306E\u3067\uFF0C\u9045\u5EF6\u3067\u8DB3\u305B\
    \u308B\uFF0E\n// \u6700\u5C0F\u5024\u306F\u6A4B\u306E\u50BE\u304D\u306E\u7B26\u53F7\
    \u3092\u898B\u3066\u6839\u304B\u3089\u964D\u308A\u308C\u3070\u6C42\u307E\u308B\
    \uFF0E\u6A4B\u306E\u518D\u8A08\u7B97\u306F\u5DE6\u53F3\u306E\u5B50\u3092\u540C\
    \u6642\u306B\u964D\u308A\u3066 O(log n)\n// MAX = true \u306A\u3089\u533A\u9593\
    \u6700\u5927\u5024\uFF0ET \u306F\u7B26\u53F7\u4ED8\u304D\u6574\u6570\ntemplate\
    \ <class T = long long, bool MAX = false>\nstruct LinearAddMinSegmentTree {\n\
    \    using W = __int128;\n    struct Node {\n        int lx, rx;    // \u6A4B\u306E\
    \u7AEF\u70B9\u306E\u6DFB\u5B57 (\u8449\u306A\u3089 lx = rx = \u305D\u306E\u4F4D\
    \u7F6E)\n        T ly, ry;      // \u6A4B\u306E\u7AEF\u70B9\u306E\u5024 (\u3053\
    \u306E\u30CE\u30FC\u30C9\u306E\u9045\u5EF6\u307E\u3067\u53CD\u6620\u6E08\u307F\
    )\n        T lb, lc;      // \u5B50\u306B\u4F1D\u3048\u3066\u3044\u306A\u3044\u9045\
    \u5EF6 (b i + c \u3092\u8DB3\u3059)\n    };\n    int n;\n    vector<Node> d;\n\
    \n    LinearAddMinSegmentTree(const vector<T> &a) : n(a.size()), d(4 * std::max<int>(1,\
    \ a.size())) {\n        if (n) build(1, 0, n, a);\n    }\n\n    int size() const\
    \ { return n; }\n\n    // i in [l, r) \u306B\u3064\u3044\u3066 a[i] += b * i +\
    \ c\n    void add(int l, int r, T b, T c) {\n        if (MAX) b = -b, c = -c;\n\
    \        if (l < r) add(1, 0, n, l, r, b, c);\n    }\n\n    // min(a[l], ...,\
    \ a[r-1]) (MAX \u306A\u3089 max)\uFF0El < r \u3067\u3042\u308B\u3053\u3068\n \
    \   T min(int l, int r) {\n        T res = query(1, 0, n, l, r);\n        return\
    \ MAX ? -res : res;\n    }\n    T max(int l, int r) { return min(l, r); }\n  \
    \  T all_min() { return MAX ? -node_min(1, 0, n) : node_min(1, 0, n); }\n\n  \
    \  T get(int i) {\n        int k = 1, l = 0, r = n;\n        while (r - l > 1)\
    \ {\n            push(k);\n            int m = (l + r) >> 1;\n            if (i\
    \ < m) k = 2 * k, r = m;\n            else k = 2 * k + 1, l = m;\n        }\n\
    \        return MAX ? -d[k].ly : d[k].ly;\n    }\n\n    void set(int i, T x) {\
    \ set(1, 0, n, i, MAX ? -x : x); }\n\n  private:\n    struct P {\n        int\
    \ x;\n        T y;\n    };\n\n    void build(int k, int l, int r, const vector<T>\
    \ &a) {\n        d[k].lb = d[k].lc = 0;\n        if (r - l == 1) {\n         \
    \   T v = MAX ? -a[l] : a[l];\n            d[k].lx = d[k].rx = l, d[k].ly = d[k].ry\
    \ = v;\n            return;\n        }\n        int m = (l + r) >> 1;\n      \
    \  build(2 * k, l, m, a), build(2 * k + 1, m, r, a);\n        pull(k, l, m, r);\n\
    \    }\n\n    void apply(int k, T b, T c) {\n        Node &x = d[k];\n       \
    \ x.ly += b * x.lx + c;\n        x.ry += b * x.rx + c;\n        x.lb += b, x.lc\
    \ += c;\n    }\n\n    void push(int k) {\n        if (d[k].lb == 0 && d[k].lc\
    \ == 0) return;\n        apply(2 * k, d[k].lb, d[k].lc);\n        apply(2 * k\
    \ + 1, d[k].lb, d[k].lc);\n        d[k].lb = d[k].lc = 0;\n    }\n\n    // q \u306E\
    \u53F3\u306B\u3042\u308B\u30CE\u30FC\u30C9 k ([l, r)) \u306E\u70B9\u306E\u3046\
    \u3061\uFF0Cq \u304B\u3089\u306E\u50BE\u304D\u304C\u6700\u5C0F\u306E\u70B9 (\u4E0B\
    \u5074\u306E\u63A5\u70B9)\n    // b, c: k \u3088\u308A\u4E0A\u3067 k \u306B\u4F1D\
    \u308F\u3063\u3066\u3044\u306A\u3044\u9045\u5EF6\u306E\u548C\n    P tangent(P\
    \ q, int k, int l, int r, T b, T c) const {\n        while (r - l > 1) {\n   \
    \         const Node &x = d[k];\n            T ly = x.ly + b * x.lx + c, ry =\
    \ x.ry + b * x.rx + c;\n            b += x.lb, c += x.lc;\n            int m =\
    \ (l + r) >> 1;\n            // slope(q, \u53F3\u7AEF\u70B9) < slope(q, \u5DE6\
    \u7AEF\u70B9) \u306A\u3089\u53F3\u306E\u5B50\n            if ((W)(ry - q.y) *\
    \ (x.lx - q.x) < (W)(ly - q.y) * (x.rx - q.x)) k = 2 * k + 1, l = m;\n       \
    \     else k = 2 * k, r = m;\n        }\n        return {d[k].lx, d[k].ly + b\
    \ * d[k].lx + c};\n    }\n\n    // q \u306E\u5DE6\u306B\u3042\u308B\u30CE\u30FC\
    \u30C9 k \u306E\u70B9\u306E\u3046\u3061\uFF0Cq \u3078\u306E\u50BE\u304D\u304C\u6700\
    \u5927\u306E\u70B9 (\u4E0B\u5074\u306E\u63A5\u70B9)\n    P tangent_left(P q, int\
    \ k, int l, int r, T b, T c) const {\n        while (r - l > 1) {\n          \
    \  const Node &x = d[k];\n            T ly = x.ly + b * x.lx + c, ry = x.ry +\
    \ b * x.rx + c;\n            b += x.lb, c += x.lc;\n            int m = (l + r)\
    \ >> 1;\n            // slope(\u53F3\u7AEF\u70B9, q) >= slope(\u5DE6\u7AEF\u70B9\
    , q) \u306A\u3089\u53F3\u306E\u5B50\n            if ((W)(q.y - ry) * (q.x - x.lx)\
    \ >= (W)(q.y - ly) * (q.x - x.rx)) k = 2 * k + 1, l = m;\n            else k =\
    \ 2 * k, r = m;\n        }\n        return {d[k].lx, d[k].ly + b * d[k].lx + c};\n\
    \    }\n\n    // \u5B50\u306E\u51F8\u5305\u304B\u3089 k \u306E\u6A4B\u3092\u8A08\
    \u7B97\u3059\u308B (k \u306E\u9045\u5EF6\u306F 0 \u3067\u3042\u308B\u3053\u3068\
    )\n    // \u5DE6\u53F3\u306E\u5B50\u3092\u540C\u6642\u306B\u964D\u308A\u308B (Overmars-van\
    \ Leeuwen)\uFF0E\u5DE6\u306E\u51F8\u5305\u306E\u8FBA (a1, a2) \u3068\u53F3\u306E\
    \u51F8\u5305\u306E\u8FBA (b1, b2) \u3092\u898B\u3066\uFF0C\n    // 2 \u76F4\u7DDA\
    \u306E\u5927\u5C0F\u3092\u5DE6\u53F3\u306E\u5883\u754C x = m - 1/2 \u3067\u6BD4\
    \u3079\u308B\u3068\uFF0C\u3069\u3061\u3089\u304B\u306E\u534A\u5206\u304C\u6368\
    \u3066\u3089\u308C\u308B\uFF0EO(log n)\n    void pull(int k, int l, int m, int\
    \ r) {\n        int u = 2 * k, ul = l, ur = m, w = 2 * k + 1, wl = m, wr = r;\n\
    \        T ub = 0, uc = 0, wb = 0, wc = 0;\n        while (ur - ul > 1 && wr -\
    \ wl > 1) {\n            const Node &x = d[u], &y = d[w];\n            T a1y =\
    \ x.ly + ub * x.lx + uc, a2y = x.ry + ub * x.rx + uc;\n            T b1y = y.ly\
    \ + wb * y.lx + wc, b2y = y.ry + wb * y.rx + wc;\n            W dxa = x.rx - x.lx,\
    \ dya = a2y - a1y, dxb = y.rx - y.lx, dyb = b2y - b1y;\n            W cmp = dya\
    \ * dxb - dyb * dxa;  // \u50BE\u304D\u306E\u5DEE (a) - (b) \u306E\u7B26\u53F7\
    \n            // 2 * dxa * dxb * (La(m') - Lb(m')), m' = m - 1/2\n           \
    \ W dlt = dxb * (2 * (W)a1y * dxa + dya * (2 * m - 1 - 2 * x.lx)) - dxa * (2 *\
    \ (W)b1y * dxb + dyb * (2 * m - 1 - 2 * y.lx));\n            bool go_u, right;\n\
    \            if (cmp > 0) go_u = dlt >= 0, right = !go_u;   // u \u306F\u5DE6\u3078\
    \ / w \u306F\u53F3\u3078\n            else go_u = dlt <= 0, right = go_u;    \
    \        // u \u306F\u53F3\u3078 / w \u306F\u5DE6\u3078\n            if (go_u)\
    \ {\n                ub += x.lb, uc += x.lc;\n                int um = (ul + ur)\
    \ >> 1;\n                if (right) u = 2 * u + 1, ul = um;\n                else\
    \ u = 2 * u, ur = um;\n            } else {\n                wb += y.lb, wc +=\
    \ y.lc;\n                int wm = (wl + wr) >> 1;\n                if (right)\
    \ w = 2 * w + 1, wl = wm;\n                else w = 2 * w, wr = wm;\n        \
    \    }\n        }\n        P s, t;\n        if (ur - ul == 1) {\n            s\
    \ = {d[u].lx, d[u].ly + ub * d[u].lx + uc};\n            t = tangent(s, w, wl,\
    \ wr, wb, wc);\n        } else {\n            t = {d[w].lx, d[w].ly + wb * d[w].lx\
    \ + wc};\n            s = tangent_left(t, u, ul, ur, ub, uc);\n        }\n   \
    \     d[k].lx = s.x, d[k].ly = s.y, d[k].rx = t.x, d[k].ry = t.y;\n    }\n\n \
    \   // \u30CE\u30FC\u30C9 k \u306E\u6700\u5C0F\u5024 (k \u306E\u9045\u5EF6\u307E\
    \u3067\u53CD\u6620\u3057\u305F\u5024)\n    T node_min(int k, int l, int r) const\
    \ {\n        T b = 0, c = 0;\n        while (r - l > 1) {\n            const Node\
    \ &x = d[k];\n            T ly = x.ly + b * x.lx + c, ry = x.ry + b * x.rx + c;\n\
    \            b += x.lb, c += x.lc;\n            int m = (l + r) >> 1;\n      \
    \      if (ry < ly) k = 2 * k + 1, l = m;\n            else k = 2 * k, r = m;\n\
    \        }\n        return d[k].ly + b * d[k].lx + c;\n    }\n\n    void add(int\
    \ k, int l, int r, int ql, int qr, T b, T c) {\n        if (ql <= l && r <= qr)\
    \ return apply(k, b, c);\n        push(k);\n        int m = (l + r) >> 1;\n  \
    \      if (ql < m) add(2 * k, l, m, ql, qr, b, c);\n        if (m < qr) add(2\
    \ * k + 1, m, r, ql, qr, b, c);\n        pull(k, l, m, r);\n    }\n\n    T query(int\
    \ k, int l, int r, int ql, int qr) {\n        if (ql <= l && r <= qr) return node_min(k,\
    \ l, r);\n        push(k);\n        int m = (l + r) >> 1;\n        if (qr <= m)\
    \ return query(2 * k, l, m, ql, qr);\n        if (m <= ql) return query(2 * k\
    \ + 1, m, r, ql, qr);\n        return std::min(query(2 * k, l, m, ql, qr), query(2\
    \ * k + 1, m, r, ql, qr));\n    }\n\n    void set(int k, int l, int r, int i,\
    \ T x) {\n        if (r - l == 1) {\n            d[k].ly = d[k].ry = x;\n    \
    \        return;\n        }\n        push(k);\n        int m = (l + r) >> 1;\n\
    \        if (i < m) set(2 * k, l, m, i, x);\n        else set(2 * k + 1, m, r,\
    \ i, x);\n        pull(k, l, m, r);\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u533A\u9593\u306B 1 \u6B21\u95A2\u6570 (b i + c) \u3092\u8DB3\u3059\u30FB\
    \u533A\u9593\u6700\u5C0F\u5024 (Range Linear Add Range Min)\n// \u70B9 (i, a_i)\
    \ \u306E\u4E0B\u5074\u51F8\u5305\u3092\uFF0C\u5404\u30CE\u30FC\u30C9\u306B\u300C\
    \u5DE6\u306E\u5B50\u306E\u51F8\u5305\u3068\u53F3\u306E\u5B50\u306E\u51F8\u5305\
    \u3092\u3064\u306A\u3050\u6A4B (bridge)\u300D\u3060\u3051\u6301\u3064\u5F62\u3067\
    \u8868\u3059\uFF0E\n// 1 \u6B21\u95A2\u6570\u3092\u8DB3\u3057\u3066\u3082\u51F8\
    \u5305\u306E\u5F62 (\u3069\u306E\u70B9\u304C\u9802\u70B9\u304B\u30FB\u6A4B) \u306F\
    \u5909\u308F\u3089\u306A\u3044\u306E\u3067\uFF0C\u9045\u5EF6\u3067\u8DB3\u305B\
    \u308B\uFF0E\n// \u6700\u5C0F\u5024\u306F\u6A4B\u306E\u50BE\u304D\u306E\u7B26\u53F7\
    \u3092\u898B\u3066\u6839\u304B\u3089\u964D\u308A\u308C\u3070\u6C42\u307E\u308B\
    \uFF0E\u6A4B\u306E\u518D\u8A08\u7B97\u306F\u5DE6\u53F3\u306E\u5B50\u3092\u540C\
    \u6642\u306B\u964D\u308A\u3066 O(log n)\n// MAX = true \u306A\u3089\u533A\u9593\
    \u6700\u5927\u5024\uFF0ET \u306F\u7B26\u53F7\u4ED8\u304D\u6574\u6570\ntemplate\
    \ <class T = long long, bool MAX = false>\nstruct LinearAddMinSegmentTree {\n\
    \    using W = __int128;\n    struct Node {\n        int lx, rx;    // \u6A4B\u306E\
    \u7AEF\u70B9\u306E\u6DFB\u5B57 (\u8449\u306A\u3089 lx = rx = \u305D\u306E\u4F4D\
    \u7F6E)\n        T ly, ry;      // \u6A4B\u306E\u7AEF\u70B9\u306E\u5024 (\u3053\
    \u306E\u30CE\u30FC\u30C9\u306E\u9045\u5EF6\u307E\u3067\u53CD\u6620\u6E08\u307F\
    )\n        T lb, lc;      // \u5B50\u306B\u4F1D\u3048\u3066\u3044\u306A\u3044\u9045\
    \u5EF6 (b i + c \u3092\u8DB3\u3059)\n    };\n    int n;\n    vector<Node> d;\n\
    \n    LinearAddMinSegmentTree(const vector<T> &a) : n(a.size()), d(4 * std::max<int>(1,\
    \ a.size())) {\n        if (n) build(1, 0, n, a);\n    }\n\n    int size() const\
    \ { return n; }\n\n    // i in [l, r) \u306B\u3064\u3044\u3066 a[i] += b * i +\
    \ c\n    void add(int l, int r, T b, T c) {\n        if (MAX) b = -b, c = -c;\n\
    \        if (l < r) add(1, 0, n, l, r, b, c);\n    }\n\n    // min(a[l], ...,\
    \ a[r-1]) (MAX \u306A\u3089 max)\uFF0El < r \u3067\u3042\u308B\u3053\u3068\n \
    \   T min(int l, int r) {\n        T res = query(1, 0, n, l, r);\n        return\
    \ MAX ? -res : res;\n    }\n    T max(int l, int r) { return min(l, r); }\n  \
    \  T all_min() { return MAX ? -node_min(1, 0, n) : node_min(1, 0, n); }\n\n  \
    \  T get(int i) {\n        int k = 1, l = 0, r = n;\n        while (r - l > 1)\
    \ {\n            push(k);\n            int m = (l + r) >> 1;\n            if (i\
    \ < m) k = 2 * k, r = m;\n            else k = 2 * k + 1, l = m;\n        }\n\
    \        return MAX ? -d[k].ly : d[k].ly;\n    }\n\n    void set(int i, T x) {\
    \ set(1, 0, n, i, MAX ? -x : x); }\n\n  private:\n    struct P {\n        int\
    \ x;\n        T y;\n    };\n\n    void build(int k, int l, int r, const vector<T>\
    \ &a) {\n        d[k].lb = d[k].lc = 0;\n        if (r - l == 1) {\n         \
    \   T v = MAX ? -a[l] : a[l];\n            d[k].lx = d[k].rx = l, d[k].ly = d[k].ry\
    \ = v;\n            return;\n        }\n        int m = (l + r) >> 1;\n      \
    \  build(2 * k, l, m, a), build(2 * k + 1, m, r, a);\n        pull(k, l, m, r);\n\
    \    }\n\n    void apply(int k, T b, T c) {\n        Node &x = d[k];\n       \
    \ x.ly += b * x.lx + c;\n        x.ry += b * x.rx + c;\n        x.lb += b, x.lc\
    \ += c;\n    }\n\n    void push(int k) {\n        if (d[k].lb == 0 && d[k].lc\
    \ == 0) return;\n        apply(2 * k, d[k].lb, d[k].lc);\n        apply(2 * k\
    \ + 1, d[k].lb, d[k].lc);\n        d[k].lb = d[k].lc = 0;\n    }\n\n    // q \u306E\
    \u53F3\u306B\u3042\u308B\u30CE\u30FC\u30C9 k ([l, r)) \u306E\u70B9\u306E\u3046\
    \u3061\uFF0Cq \u304B\u3089\u306E\u50BE\u304D\u304C\u6700\u5C0F\u306E\u70B9 (\u4E0B\
    \u5074\u306E\u63A5\u70B9)\n    // b, c: k \u3088\u308A\u4E0A\u3067 k \u306B\u4F1D\
    \u308F\u3063\u3066\u3044\u306A\u3044\u9045\u5EF6\u306E\u548C\n    P tangent(P\
    \ q, int k, int l, int r, T b, T c) const {\n        while (r - l > 1) {\n   \
    \         const Node &x = d[k];\n            T ly = x.ly + b * x.lx + c, ry =\
    \ x.ry + b * x.rx + c;\n            b += x.lb, c += x.lc;\n            int m =\
    \ (l + r) >> 1;\n            // slope(q, \u53F3\u7AEF\u70B9) < slope(q, \u5DE6\
    \u7AEF\u70B9) \u306A\u3089\u53F3\u306E\u5B50\n            if ((W)(ry - q.y) *\
    \ (x.lx - q.x) < (W)(ly - q.y) * (x.rx - q.x)) k = 2 * k + 1, l = m;\n       \
    \     else k = 2 * k, r = m;\n        }\n        return {d[k].lx, d[k].ly + b\
    \ * d[k].lx + c};\n    }\n\n    // q \u306E\u5DE6\u306B\u3042\u308B\u30CE\u30FC\
    \u30C9 k \u306E\u70B9\u306E\u3046\u3061\uFF0Cq \u3078\u306E\u50BE\u304D\u304C\u6700\
    \u5927\u306E\u70B9 (\u4E0B\u5074\u306E\u63A5\u70B9)\n    P tangent_left(P q, int\
    \ k, int l, int r, T b, T c) const {\n        while (r - l > 1) {\n          \
    \  const Node &x = d[k];\n            T ly = x.ly + b * x.lx + c, ry = x.ry +\
    \ b * x.rx + c;\n            b += x.lb, c += x.lc;\n            int m = (l + r)\
    \ >> 1;\n            // slope(\u53F3\u7AEF\u70B9, q) >= slope(\u5DE6\u7AEF\u70B9\
    , q) \u306A\u3089\u53F3\u306E\u5B50\n            if ((W)(q.y - ry) * (q.x - x.lx)\
    \ >= (W)(q.y - ly) * (q.x - x.rx)) k = 2 * k + 1, l = m;\n            else k =\
    \ 2 * k, r = m;\n        }\n        return {d[k].lx, d[k].ly + b * d[k].lx + c};\n\
    \    }\n\n    // \u5B50\u306E\u51F8\u5305\u304B\u3089 k \u306E\u6A4B\u3092\u8A08\
    \u7B97\u3059\u308B (k \u306E\u9045\u5EF6\u306F 0 \u3067\u3042\u308B\u3053\u3068\
    )\n    // \u5DE6\u53F3\u306E\u5B50\u3092\u540C\u6642\u306B\u964D\u308A\u308B (Overmars-van\
    \ Leeuwen)\uFF0E\u5DE6\u306E\u51F8\u5305\u306E\u8FBA (a1, a2) \u3068\u53F3\u306E\
    \u51F8\u5305\u306E\u8FBA (b1, b2) \u3092\u898B\u3066\uFF0C\n    // 2 \u76F4\u7DDA\
    \u306E\u5927\u5C0F\u3092\u5DE6\u53F3\u306E\u5883\u754C x = m - 1/2 \u3067\u6BD4\
    \u3079\u308B\u3068\uFF0C\u3069\u3061\u3089\u304B\u306E\u534A\u5206\u304C\u6368\
    \u3066\u3089\u308C\u308B\uFF0EO(log n)\n    void pull(int k, int l, int m, int\
    \ r) {\n        int u = 2 * k, ul = l, ur = m, w = 2 * k + 1, wl = m, wr = r;\n\
    \        T ub = 0, uc = 0, wb = 0, wc = 0;\n        while (ur - ul > 1 && wr -\
    \ wl > 1) {\n            const Node &x = d[u], &y = d[w];\n            T a1y =\
    \ x.ly + ub * x.lx + uc, a2y = x.ry + ub * x.rx + uc;\n            T b1y = y.ly\
    \ + wb * y.lx + wc, b2y = y.ry + wb * y.rx + wc;\n            W dxa = x.rx - x.lx,\
    \ dya = a2y - a1y, dxb = y.rx - y.lx, dyb = b2y - b1y;\n            W cmp = dya\
    \ * dxb - dyb * dxa;  // \u50BE\u304D\u306E\u5DEE (a) - (b) \u306E\u7B26\u53F7\
    \n            // 2 * dxa * dxb * (La(m') - Lb(m')), m' = m - 1/2\n           \
    \ W dlt = dxb * (2 * (W)a1y * dxa + dya * (2 * m - 1 - 2 * x.lx)) - dxa * (2 *\
    \ (W)b1y * dxb + dyb * (2 * m - 1 - 2 * y.lx));\n            bool go_u, right;\n\
    \            if (cmp > 0) go_u = dlt >= 0, right = !go_u;   // u \u306F\u5DE6\u3078\
    \ / w \u306F\u53F3\u3078\n            else go_u = dlt <= 0, right = go_u;    \
    \        // u \u306F\u53F3\u3078 / w \u306F\u5DE6\u3078\n            if (go_u)\
    \ {\n                ub += x.lb, uc += x.lc;\n                int um = (ul + ur)\
    \ >> 1;\n                if (right) u = 2 * u + 1, ul = um;\n                else\
    \ u = 2 * u, ur = um;\n            } else {\n                wb += y.lb, wc +=\
    \ y.lc;\n                int wm = (wl + wr) >> 1;\n                if (right)\
    \ w = 2 * w + 1, wl = wm;\n                else w = 2 * w, wr = wm;\n        \
    \    }\n        }\n        P s, t;\n        if (ur - ul == 1) {\n            s\
    \ = {d[u].lx, d[u].ly + ub * d[u].lx + uc};\n            t = tangent(s, w, wl,\
    \ wr, wb, wc);\n        } else {\n            t = {d[w].lx, d[w].ly + wb * d[w].lx\
    \ + wc};\n            s = tangent_left(t, u, ul, ur, ub, uc);\n        }\n   \
    \     d[k].lx = s.x, d[k].ly = s.y, d[k].rx = t.x, d[k].ry = t.y;\n    }\n\n \
    \   // \u30CE\u30FC\u30C9 k \u306E\u6700\u5C0F\u5024 (k \u306E\u9045\u5EF6\u307E\
    \u3067\u53CD\u6620\u3057\u305F\u5024)\n    T node_min(int k, int l, int r) const\
    \ {\n        T b = 0, c = 0;\n        while (r - l > 1) {\n            const Node\
    \ &x = d[k];\n            T ly = x.ly + b * x.lx + c, ry = x.ry + b * x.rx + c;\n\
    \            b += x.lb, c += x.lc;\n            int m = (l + r) >> 1;\n      \
    \      if (ry < ly) k = 2 * k + 1, l = m;\n            else k = 2 * k, r = m;\n\
    \        }\n        return d[k].ly + b * d[k].lx + c;\n    }\n\n    void add(int\
    \ k, int l, int r, int ql, int qr, T b, T c) {\n        if (ql <= l && r <= qr)\
    \ return apply(k, b, c);\n        push(k);\n        int m = (l + r) >> 1;\n  \
    \      if (ql < m) add(2 * k, l, m, ql, qr, b, c);\n        if (m < qr) add(2\
    \ * k + 1, m, r, ql, qr, b, c);\n        pull(k, l, m, r);\n    }\n\n    T query(int\
    \ k, int l, int r, int ql, int qr) {\n        if (ql <= l && r <= qr) return node_min(k,\
    \ l, r);\n        push(k);\n        int m = (l + r) >> 1;\n        if (qr <= m)\
    \ return query(2 * k, l, m, ql, qr);\n        if (m <= ql) return query(2 * k\
    \ + 1, m, r, ql, qr);\n        return std::min(query(2 * k, l, m, ql, qr), query(2\
    \ * k + 1, m, r, ql, qr));\n    }\n\n    void set(int k, int l, int r, int i,\
    \ T x) {\n        if (r - l == 1) {\n            d[k].ly = d[k].ry = x;\n    \
    \        return;\n        }\n        push(k);\n        int m = (l + r) >> 1;\n\
    \        if (i < m) set(2 * k, l, m, i, x);\n        else set(2 * k + 1, m, r,\
    \ i, x);\n        pull(k, l, m, r);\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/linear_add_min_segment_tree.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unittest/linear_add_min_segment_tree.test.cpp
  - test/range_linear_add_range_min.test.cpp
documentation_of: data_structure/linear_add_min_segment_tree.hpp
layout: document
title: "\u533A\u9593 1 \u6B21\u95A2\u6570\u52A0\u7B97\u30FB\u533A\u9593\u6700\u5C0F\
  \u5024 (Range Linear Add Range Min)"
---

## 概要

整数列 $a$ に対して、

- 区間 $[l, r)$ の各 $i$ に $b i + c$ を足す（**位置によって足す量が違う**）
- 区間 $[l, r)$ の最小値（最大値）

を処理する。普通の遅延セグメント木では、「区間の最小値」に $b i + c$ を足した結果が分からない（どの位置が最小になるかが変わる）ので扱えない。

点 $(i, a_i)$ を平面上に置くと、区間の最小値を取りうるのは点の **下側凸包** の頂点だけ。しかも 1 次関数 $b i + c$ を全点に足しても凸包の形は変わらない（どの点が頂点かは同じ）。そこで各ノードに「左の子の凸包と右の子の凸包をつなぐ橋（共通接線の 2 端点）」だけを持つ。

- 最小値：ノードの橋の傾きが負なら最小値は右の子側、そうでなければ左の子側にあるので、根から 1 本降りれば $O(\log n)$。
- 1 次関数の加算：橋の端点の値と遅延に足すだけ。
- 橋の再計算：左右の子の凸包を同時に降りる（Overmars–van Leeuwen）。左の凸包の辺と右の凸包の辺を延長した 2 直線を、左右の境界 $x = m - 1/2$ で比べると、どちらかの半分を捨てられるので $O(\log n)$。

## 使い方

```cpp
LinearAddMinSegmentTree<long long> seg(a);         // vector<long long> a
LinearAddMinSegmentTree<long long, true> segmax(a); // 区間最大値
seg.add(l, r, b, c);     // i in [l, r) について a[i] += b * i + c
seg.min(l, r);           // min(a[l], ..., a[r-1])  (最大値版は seg.max(l, r) でも可)
seg.all_min();
seg.get(i); seg.set(i, x);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `LinearAddMinSegmentTree<T = long long, MAX = false>(const vector<T> &a)` | 構築 | $O(n \log n)$ |
| `void add(int l, int r, T b, T c)` | $a_i \mathrel{+}= b i + c$ | $O(\log^2 n)$ |
| `T min(int l, int r)` / `T max(int l, int r)` | 区間最小値（最大値版では最大値） | $O(\log^2 n)$ |
| `T all_min()` | 全体の最小値 | $O(\log n)$ |
| `T get(int i)` / `void set(int i, T x)` | 一点取得 / 更新 | $O(\log n)$ / $O(\log^2 n)$ |

## 注意

- 足す量の $i$ は **0-indexed の位置そのもの**（区間の左端からの距離ではない）。左端からの距離で足したいときは $c$ を $c - b l$ にする。
- `min(l, r)` は $l < r$ で呼ぶこと。
- 値は `T`（符号付き整数）に収まること。橋の比較は `__int128` で行う（値 $\times$ 長さ$^2$ 程度まで使う）。
