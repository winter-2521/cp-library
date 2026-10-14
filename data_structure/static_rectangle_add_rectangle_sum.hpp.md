---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/static_rectangle_sum.hpp
    title: "\u9577\u65B9\u5F62\u306E\u4E2D\u306E\u70B9\u306E\u91CD\u307F\u306E\u548C\
      \ (Rectangle Sum)"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/static_rectangle_add_rectangle_sum.test.cpp
    title: test/static_rectangle_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/rectangle_add.test.cpp
    title: test/unittest/rectangle_add.test.cpp
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
    \ 3 \"data_structure/static_rectangle_sum.hpp\"\n\n// \u9759\u7684\u306A\u91CD\
    \u307F\u4ED8\u304D\u70B9\u306E\u9577\u65B9\u5F62\u548C (Rectangle Sum)\uFF0E\u30AA\
    \u30F3\u30E9\u30A4\u30F3\n// \u70B9\u3092 x \u3067\u30BD\u30FC\u30C8\u3057\uFF0C\
    y (\u5EA7\u6A19\u5727\u7E2E) \u306E\u5217\u3092\u91CD\u307F\u4ED8\u304D\u30A6\u30A7\
    \u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217\u3067\u6301\u3064\uFF0E\u69CB\u7BC9\
    \ O(n log n)\uFF0C\u30AF\u30A8\u30EA O(log n)\n// X: \u5EA7\u6A19\u306E\u578B\uFF0C\
    W: \u91CD\u307F\u306E\u578B\ntemplate <class X, class W>\nstruct StaticRectangleSum\
    \ {\n    // 64 bit \u3054\u3068\u306B\uFF0C\u30D3\u30C3\u30C8\u5217\u3068\u305D\
    \u308C\u3088\u308A\u524D\u306E 1 \u306E\u500B\u6570\u3092\u307E\u3068\u3081\u3066\
    \u6301\u3064\n    struct BitVector {\n        struct Block {\n            uint64_t\
    \ bits;\n            int cnt;\n        };\n        vector<Block> b;\n        void\
    \ init(int n) { b.assign((n >> 6) + 1, {0, 0}); }\n        void set(int i) { b[i\
    \ >> 6].bits |= 1ULL << (i & 63); }\n        void build() {\n            for (size_t\
    \ i = 1; i < b.size(); i++) b[i].cnt = b[i - 1].cnt + __builtin_popcountll(b[i\
    \ - 1].bits);\n        }\n        int rank1(int i) const {\n            const\
    \ Block &x = b[i >> 6];\n            return x.cnt + __builtin_popcountll(x.bits\
    \ & ((1ULL << (i & 63)) - 1));\n        }\n    };\n\n    int n, lg;\n    vector<X>\
    \ xs, ys;           // xs: \u70B9\u306E x (\u6607\u9806)\uFF0Cys: y \u306E\u7A2E\
    \u985E (\u6607\u9806)\n    vector<BitVector> bv;\n    vector<int> zeros;\n   \
    \ vector<vector<W>> sum;      // sum[h][i]: \u6BB5 h \u3067\u632F\u308A\u5206\u3051\
    \u305F\u5F8C\u306E\u5217\u306E\u5148\u982D i \u500B\u306E\u91CD\u307F\u306E\u548C\
    \n\n    StaticRectangleSum() : n(0), lg(0) {}\n    StaticRectangleSum(const vector<X>\
    \ &x, const vector<X> &y, const vector<W> &w) : n(x.size()) {\n        vector<int>\
    \ ord(n);\n        iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(),\
    \ ord.end(), [&](int i, int j) { return x[i] < x[j]; });\n        xs.resize(n);\n\
    \        for (int k = 0; k < n; k++) xs[k] = x[ord[k]];\n        ys = y;\n   \
    \     sort(ys.begin(), ys.end());\n        ys.erase(unique(ys.begin(), ys.end()),\
    \ ys.end());\n        vector<int> cur(n), nxt(n);\n        vector<W> cw(n), nw(n);\n\
    \        for (int k = 0; k < n; k++) {\n            cur[k] = lower_bound(ys.begin(),\
    \ ys.end(), y[ord[k]]) - ys.begin();\n            cw[k] = w[ord[k]];\n       \
    \ }\n        lg = 1;\n        while ((1 << lg) < (int)ys.size()) lg++;\n     \
    \   bv.resize(lg), zeros.resize(lg), sum.assign(lg, vector<W>(n + 1, W(0)));\n\
    \        for (int h = lg - 1; h >= 0; h--) {\n            bv[h].init(n);\n   \
    \         int z = 0;\n            for (int i = 0; i < n; i++) {\n            \
    \    if (cur[i] >> h & 1) bv[h].set(i);\n                else z++;\n         \
    \   }\n            bv[h].build();\n            zeros[h] = z;\n            int\
    \ p0 = 0, p1 = z;\n            for (int i = 0; i < n; i++) {\n               \
    \ int p = (cur[i] >> h & 1) ? p1++ : p0++;\n                nxt[p] = cur[i], nw[p]\
    \ = cw[i];\n            }\n            swap(cur, nxt), swap(cw, nw);\n       \
    \     for (int i = 0; i < n; i++) sum[h][i + 1] = sum[h][i] + cw[i];\n       \
    \ }\n    }\n\n    int size() const { return n; }\n\n    // l <= x < r, d <= y\
    \ < u \u306E\u70B9\u306E\u91CD\u307F\u306E\u548C\n    W sum_rect(X l, X d, X r,\
    \ X u) const {\n        int il = lower_idx(xs, l), ir = lower_idx(xs, r);\n  \
    \      int yd = lower_idx(ys, d), yu = lower_idx(ys, u);\n        if (il >= ir\
    \ || yd >= yu) return W(0);\n        if (yu >= (1 << lg)) return total(il, ir)\
    \ - prefix(il, ir, yd);\n        // \u4E0A\u306E\u6BB5\u3067 yd \u3068 yu \u306E\
    \u30D3\u30C3\u30C8\u304C\u540C\u3058\u9593\u306F 2 \u3064\u306E\u548C\u306E\u5DEE\
    \u306B\u52B9\u304B\u306A\u3044\u306E\u3067\uFF0C\u5171\u901A\u306B\u964D\u308A\
    \u308B\n        int h = lg - 1;\n        for (; h >= 0 && ((yd ^ yu) >> h & 1)\
    \ == 0; h--) {\n            int l1 = bv[h].rank1(il), r1 = bv[h].rank1(ir);\n\
    \            if (yu >> h & 1) il = zeros[h] + l1, ir = zeros[h] + r1;\n      \
    \      else il -= l1, ir -= r1;\n        }\n        // \u30D3\u30C3\u30C8 h \u3067\
    \ yd \u306F 0\uFF0Cyu \u306F 1\n        int l1 = bv[h].rank1(il), r1 = bv[h].rank1(ir);\n\
    \        int l0 = il - l1, r0 = ir - r1;\n        return (sum[h][r0] - sum[h][l0])\
    \ + prefix_from(zeros[h] + l1, zeros[h] + r1, yu, h - 1) - prefix_from(l0, r0,\
    \ yd, h - 1);\n    }\n    W operator()(X l, X d, X r, X u) const { return sum_rect(l,\
    \ d, r, u); }\n\n  private:\n    // \u5206\u5C90\u306E\u5C11\u306A\u3044 lower_bound\
    \ (\u6DFB\u5B57\u3092\u8FD4\u3059)\n    static int lower_idx(const vector<X> &v,\
    \ const X &x) {\n        int n = v.size();\n        if (n == 0) return 0;\n  \
    \      const X *base = v.data();\n        while (n > 1) {\n            int half\
    \ = n >> 1;\n            base = base[half - 1] < x ? base + half : base;\n   \
    \         n -= half;\n        }\n        return int(base - v.data()) + (*base\
    \ < x);\n    }\n\n    // x \u306E\u9806\u3067 [l, r) \u756A\u76EE\u306E\u70B9\u306E\
    \u3046\u3061 y \u306E\u756A\u53F7\u304C v \u672A\u6E80\u306E\u3082\u306E\u306E\
    \u91CD\u307F\u306E\u548C\n    W prefix(int l, int r, int v) const {\n        if\
    \ (v >= (1 << lg)) return total(l, r);\n        return prefix_from(l, r, v, lg\
    \ - 1);\n    }\n    // \u6BB5 h \u304B\u3089\u4E0B\u3060\u3051\u3092\u898B\u308B\
    \u7248 (\u6BB5 h \u3067\u306E\u533A\u9593\u304C [l, r))\n    W prefix_from(int\
    \ l, int r, int v, int h0) const {\n        W res(0);\n        for (int h = h0;\
    \ h >= 0; h--) {\n            int l1 = bv[h].rank1(l), r1 = bv[h].rank1(r);\n\
    \            int l0 = l - l1, r0 = r - r1;\n            if (v >> h & 1) {\n  \
    \              res += sum[h][r0] - sum[h][l0];\n                l = zeros[h] +\
    \ l1, r = zeros[h] + r1;\n            } else {\n                l = l0, r = r0;\n\
    \            }\n        }\n        return res;\n    }\n    W total(int l, int\
    \ r) const {\n        // \u6700\u4E0A\u6BB5\u3067\u632F\u308A\u5206\u3051\u308B\
    \u524D\u306E [l, r) \u306E\u548C = 0 \u5074\u3068 1 \u5074\u306E\u548C\n     \
    \   int h = lg - 1;\n        int l1 = bv[h].rank1(l), r1 = bv[h].rank1(r);\n \
    \       return (sum[h][r - r1] - sum[h][l - l1]) + (sum[h][zeros[h] + r1] - sum[h][zeros[h]\
    \ + l1]);\n    }\n};\n\n// \u70B9\u306E\u8FFD\u52A0\u304C\u3067\u304D\u308B\u9577\
    \u65B9\u5F62\u548C (Point Add Rectangle Sum)\uFF0E\u30AA\u30F3\u30E9\u30A4\u30F3\
    \n// \u5927\u304D\u3055\u304C 2 \u51AA\u306E StaticRectangleSum \u3092\u9AD8\u3005\
    \ log \u500B\u6301\u3061\uFF0C\u8FFD\u52A0\u306E\u305F\u3073\u306B\u540C\u3058\
    \u5927\u304D\u3055\u306E\u3082\u306E\u3092\u4F75\u5408\u3057\u3066\u4F5C\u308A\
    \u76F4\u3059 (\u4E8C\u9032\u30AB\u30A6\u30F3\u30BF)\n// \u8FFD\u52A0\u306A\u3089\
    \u3057 O(log^2 n)\uFF0C\u30AF\u30A8\u30EA O(log^2 n)\ntemplate <class X, class\
    \ W>\nstruct DynamicRectangleSum {\n    struct Bucket {\n        vector<X> x,\
    \ y;\n        vector<W> w;\n        StaticRectangleSum<X, W> rs;\n    };\n   \
    \ vector<Bucket> buckets;\n\n    DynamicRectangleSum() = default;\n    // \u521D\
    \u671F\u306E\u70B9\u3092\u307E\u3068\u3081\u3066\u5165\u308C\u308B\n    DynamicRectangleSum(const\
    \ vector<X> &x, const vector<X> &y, const vector<W> &w) {\n        if (!x.empty())\
    \ buckets.push_back({x, y, w, StaticRectangleSum<X, W>(x, y, w)});\n    }\n\n\
    \    // \u70B9 (x, y) \u306B\u91CD\u307F w \u306E\u70B9\u3092\u8FFD\u52A0\n  \
    \  void add(X x, X y, W w) {\n        Bucket b{{x}, {y}, {w}, {}};\n        while\
    \ (!buckets.empty() && buckets.back().x.size() <= b.x.size()) {\n            Bucket\
    \ &t = buckets.back();\n            b.x.insert(b.x.end(), t.x.begin(), t.x.end());\n\
    \            b.y.insert(b.y.end(), t.y.begin(), t.y.end());\n            b.w.insert(b.w.end(),\
    \ t.w.begin(), t.w.end());\n            buckets.pop_back();\n        }\n     \
    \   b.rs = StaticRectangleSum<X, W>(b.x, b.y, b.w);\n        buckets.push_back(std::move(b));\n\
    \    }\n\n    // l <= x < r, d <= y < u \u306E\u70B9\u306E\u91CD\u307F\u306E\u548C\
    \n    W sum_rect(X l, X d, X r, X u) const {\n        W res(0);\n        for (auto\
    \ &b : buckets) res += b.rs.sum_rect(l, d, r, u);\n        return res;\n    }\n\
    \    W operator()(X l, X d, X r, X u) const { return sum_rect(l, d, r, u); }\n\
    };\n#line 4 \"data_structure/static_rectangle_add_rectangle_sum.hpp\"\n\n// \u9577\
    \u65B9\u5F62\u52A0\u7B97\u3092\u3059\u3079\u3066\u884C\u3063\u305F\u5F8C\u306E\
    \u9577\u65B9\u5F62\u548C (Static Rectangle Add Rectangle Sum)\uFF0E\u52A0\u7B97\
    \u306E\u5F8C\u306E\u30AF\u30A8\u30EA\u306F\u30AA\u30F3\u30E9\u30A4\u30F3\n// \u9577\
    \u65B9\u5F62 [l, r) \xD7 [d, u) \u3078\u306E w \u306E\u52A0\u7B97\u3092 4 \u9685\
    \u306E\u70B9 (p, q, \xB1w) \u306B\u3059\u308B\u3068\uFF0C\n//   S(X, Y) = \u03A3\
    _{x<X, y<Y} A[x][y] = \u03A3_{p<X, q<Y} c (X - p)(Y - q)\n//           = XY \u03A3\
    c - X \u03A3cq - Y \u03A3cp + \u03A3cpq\n// \u306A\u306E\u3067\uFF0C\u91CD\u307F\
    \ (c, cp, cq, cpq) \u306E\u9577\u65B9\u5F62\u548C (StaticRectangleSum) 1 \u56DE\
    \u3067 S(X, Y) \u304C\u6C42\u307E\u308B\n// \u69CB\u7BC9 O(n log n)\uFF0C\u30AF\
    \u30A8\u30EA O(log n)\uFF0ET \u306F\u5024\u306E\u578B (modint \u306A\u3069\uFF0E\
    \u5EA7\u6A19\u306E\u7A4D\u3092 T \u3067\u8A08\u7B97\u3059\u308B)\ntemplate <class\
    \ X, class T>\nstruct StaticRectangleAddRectangleSum {\n    struct Quad {\n  \
    \      T c, cp, cq, cpq;\n        Quad(int z = 0) : c(z), cp(z), cq(z), cpq(z)\
    \ {}\n        Quad(T c, T cp, T cq, T cpq) : c(c), cp(cp), cq(cq), cpq(cpq) {}\n\
    \        Quad &operator+=(const Quad &o) { return c += o.c, cp += o.cp, cq +=\
    \ o.cq, cpq += o.cpq, *this; }\n        Quad operator+(const Quad &o) const {\
    \ return Quad(*this) += o; }\n        Quad operator-(const Quad &o) const { return\
    \ Quad(c - o.c, cp - o.cp, cq - o.cq, cpq - o.cpq); }\n    };\n    vector<X> xs,\
    \ ys;\n    vector<Quad> ws;\n    StaticRectangleSum<X, Quad> rs;\n    bool built\
    \ = false;\n\n    StaticRectangleAddRectangleSum() = default;\n\n    // l <= x\
    \ < r, d <= y < u \u306B w \u3092\u8DB3\u3059 (build \u524D\u306B\u547C\u3076\u3053\
    \u3068)\n    void add(X l, X d, X r, X u, T w) {\n        assert(!built);\n  \
    \      add_corner(l, d, w), add_corner(l, u, -w), add_corner(r, d, -w), add_corner(r,\
    \ u, w);\n    }\n\n    void build() {\n        rs = StaticRectangleSum<X, Quad>(xs,\
    \ ys, ws);\n        built = true;\n    }\n\n    // l <= x < r, d <= y < u \u306E\
    \u548C (\u521D\u56DE\u306B build \u3057\u3066\u3044\u306A\u3051\u308C\u3070 build\
    \ \u3059\u308B)\n    T sum(X l, X d, X r, X u) {\n        if (!built) build();\n\
    \        return prefix(r, u) - prefix(l, u) - prefix(r, d) + prefix(l, d);\n \
    \   }\n\n    // x < X, y < Y \u306E\u548C\n    T prefix(X x, X y) const {\n  \
    \      X lo = numeric_limits<X>::lowest();\n        Quad q = rs.sum_rect(lo, lo,\
    \ x, y);\n        T tx(x), ty(y);\n        return tx * ty * q.c - tx * q.cq -\
    \ ty * q.cp + q.cpq;\n    }\n\n  private:\n    void add_corner(X p, X q, T c)\
    \ {\n        xs.push_back(p), ys.push_back(q);\n        T tp(p), tq(q);\n    \
    \    ws.emplace_back(c, c * tp, c * tq, c * tp * tq);\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"static_rectangle_sum.hpp\"\
    \n\n// \u9577\u65B9\u5F62\u52A0\u7B97\u3092\u3059\u3079\u3066\u884C\u3063\u305F\
    \u5F8C\u306E\u9577\u65B9\u5F62\u548C (Static Rectangle Add Rectangle Sum)\uFF0E\
    \u52A0\u7B97\u306E\u5F8C\u306E\u30AF\u30A8\u30EA\u306F\u30AA\u30F3\u30E9\u30A4\
    \u30F3\n// \u9577\u65B9\u5F62 [l, r) \xD7 [d, u) \u3078\u306E w \u306E\u52A0\u7B97\
    \u3092 4 \u9685\u306E\u70B9 (p, q, \xB1w) \u306B\u3059\u308B\u3068\uFF0C\n// \
    \  S(X, Y) = \u03A3_{x<X, y<Y} A[x][y] = \u03A3_{p<X, q<Y} c (X - p)(Y - q)\n\
    //           = XY \u03A3c - X \u03A3cq - Y \u03A3cp + \u03A3cpq\n// \u306A\u306E\
    \u3067\uFF0C\u91CD\u307F (c, cp, cq, cpq) \u306E\u9577\u65B9\u5F62\u548C (StaticRectangleSum)\
    \ 1 \u56DE\u3067 S(X, Y) \u304C\u6C42\u307E\u308B\n// \u69CB\u7BC9 O(n log n)\uFF0C\
    \u30AF\u30A8\u30EA O(log n)\uFF0ET \u306F\u5024\u306E\u578B (modint \u306A\u3069\
    \uFF0E\u5EA7\u6A19\u306E\u7A4D\u3092 T \u3067\u8A08\u7B97\u3059\u308B)\ntemplate\
    \ <class X, class T>\nstruct StaticRectangleAddRectangleSum {\n    struct Quad\
    \ {\n        T c, cp, cq, cpq;\n        Quad(int z = 0) : c(z), cp(z), cq(z),\
    \ cpq(z) {}\n        Quad(T c, T cp, T cq, T cpq) : c(c), cp(cp), cq(cq), cpq(cpq)\
    \ {}\n        Quad &operator+=(const Quad &o) { return c += o.c, cp += o.cp, cq\
    \ += o.cq, cpq += o.cpq, *this; }\n        Quad operator+(const Quad &o) const\
    \ { return Quad(*this) += o; }\n        Quad operator-(const Quad &o) const {\
    \ return Quad(c - o.c, cp - o.cp, cq - o.cq, cpq - o.cpq); }\n    };\n    vector<X>\
    \ xs, ys;\n    vector<Quad> ws;\n    StaticRectangleSum<X, Quad> rs;\n    bool\
    \ built = false;\n\n    StaticRectangleAddRectangleSum() = default;\n\n    //\
    \ l <= x < r, d <= y < u \u306B w \u3092\u8DB3\u3059 (build \u524D\u306B\u547C\
    \u3076\u3053\u3068)\n    void add(X l, X d, X r, X u, T w) {\n        assert(!built);\n\
    \        add_corner(l, d, w), add_corner(l, u, -w), add_corner(r, d, -w), add_corner(r,\
    \ u, w);\n    }\n\n    void build() {\n        rs = StaticRectangleSum<X, Quad>(xs,\
    \ ys, ws);\n        built = true;\n    }\n\n    // l <= x < r, d <= y < u \u306E\
    \u548C (\u521D\u56DE\u306B build \u3057\u3066\u3044\u306A\u3051\u308C\u3070 build\
    \ \u3059\u308B)\n    T sum(X l, X d, X r, X u) {\n        if (!built) build();\n\
    \        return prefix(r, u) - prefix(l, u) - prefix(r, d) + prefix(l, d);\n \
    \   }\n\n    // x < X, y < Y \u306E\u548C\n    T prefix(X x, X y) const {\n  \
    \      X lo = numeric_limits<X>::lowest();\n        Quad q = rs.sum_rect(lo, lo,\
    \ x, y);\n        T tx(x), ty(y);\n        return tx * ty * q.c - tx * q.cq -\
    \ ty * q.cp + q.cpq;\n    }\n\n  private:\n    void add_corner(X p, X q, T c)\
    \ {\n        xs.push_back(p), ys.push_back(q);\n        T tp(p), tq(q);\n    \
    \    ws.emplace_back(c, c * tp, c * tq, c * tp * tq);\n    }\n};\n"
  dependsOn:
  - template.hpp
  - data_structure/static_rectangle_sum.hpp
  isVerificationFile: false
  path: data_structure/static_rectangle_add_rectangle_sum.hpp
  requiredBy: []
  timestamp: '2026-10-15 00:08:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/rectangle_add.test.cpp
  - test/static_rectangle_add_rectangle_sum.test.cpp
documentation_of: data_structure/static_rectangle_add_rectangle_sum.hpp
layout: document
title: "\u9577\u65B9\u5F62\u52A0\u7B97\u306E\u5F8C\u306E\u9577\u65B9\u5F62\u548C (Static\
  \ Rectangle Add Rectangle Sum)"
---

## 概要

先に長方形加算（$[l, r) \times [d, u)$ の全マスに $w$）をまとめて行い、その後で長方形和を答える。加算の後のクエリはオンライン。

長方形加算を 4 隅の点 $(p, q, c)$（$c = \pm w$）に直すと、左下の累積和は

$$S(X, Y) = \sum_{x < X,\ y < Y} A_{xy} = \sum_{p < X,\ q < Y} c\,(X - p)(Y - q) = XY \sum c - X \sum cq - Y \sum cp + \sum cpq$$

なので、重み $(c, cp, cq, cpq)$ の組についての長方形和（[StaticRectangleSum](static_rectangle_sum.hpp)）1 回で $S(X, Y)$ が求まる。長方形和は $S$ の 4 回の包除。

## 使い方

```cpp
StaticRectangleAddRectangleSum<int, mint> rs;
rs.add(l, d, r, u, w);    // 先に全部の加算
rs.build();               // (省略すると最初の sum で build する)
rs.sum(l, d, r, u);       // [l, r) × [d, u) の和
rs.prefix(x, y);          // x' < x, y' < y の和
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `void add(X l, X d, X r, X u, T w)` | 長方形加算（`build` 前） | $O(1)$ |
| `void build()` | 構築 | $O(n \log n)$ |
| `T sum(X l, X d, X r, X u)` | 長方形和 | $O(\log n)$ |

## 注意

- `T` は座標の積を計算する型（modint など）。座標を `T` に変換して掛けるので、`long long` だと座標 $10^9$ で $XY \sum c$ があふれる。
- メモリは 4 隅の点 $4n$ 個 × $\log$ 段 × 重み 4 つ分（$n = 2 \times 10^5$ で約 300 MB）。
- 加算と和が交互に来るなら、オフラインで分割統治するか、遅延セグ木を使う別の方法が要る。
