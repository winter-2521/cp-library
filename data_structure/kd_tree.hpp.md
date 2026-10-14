---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid.hpp
    title: "\u4F5C\u7528\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (Acted Monoid)"
  - icon: ':heavy_check_mark:'
    path: algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9 (Monoid)"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_point_set_rectangle_affine_rectangle_sum.test.cpp
    title: test/dynamic_point_set_rectangle_affine_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/kd_tree.test.cpp
    title: test/unittest/kd_tree.test.cpp
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
    \ 3 \"algebra/monoid.hpp\"\n\n// \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306A\u3069\
    \u306B\u6E21\u3059\u30E2\u30CE\u30A4\u30C9\n// \u5F62\u5F0F: using S = \u5024\u306E\
    \u578B; static S op(const S &a, const S &b); static S e();\n// op \u306F\u7D50\
    \u5408\u7684\u3067\uFF0Ce \u306F\u5358\u4F4D\u5143\uFF0Eop(a, b) \u306F\u300C\
    a \u304C\u5DE6 (\u5148)\uFF0Cb \u304C\u53F3 (\u5F8C)\u300D\n\n// 1 \u6B21\u95A2\
    \u6570 f(x) = a x + b\ntemplate <class T>\nstruct Affine {\n    T a = T(1), b\
    \ = T(0);\n    Affine() = default;\n    Affine(T a, T b) : a(a), b(b) {}\n   \
    \ T operator()(const T &x) const { return a * x + b; }\n    T eval(const T &x)\
    \ const { return a * x + b; }\n    // \u300C\u5148\u306B *this\uFF0C\u6B21\u306B\
    \ g\u300D\u3092\u8868\u3059\u95A2\u6570 g(f(x))\n    Affine then(const Affine\
    \ &g) const { return Affine(a * g.a, b * g.a + g.b); }\n    friend bool operator==(const\
    \ Affine &f, const Affine &g) { return f.a == g.a && f.b == g.b; }\n    friend\
    \ bool operator!=(const Affine &f, const Affine &g) { return !(f == g); }\n};\n\
    \n// \u548C\ntemplate <class T>\nstruct MonoidSum {\n    using S = T;\n    static\
    \ S op(const S &a, const S &b) { return a + b; }\n    static S e() { return S(0);\
    \ }\n};\n\n// \u6700\u5C0F\u5024 (\u5358\u4F4D\u5143\u306F numeric_limits<T>::max())\n\
    template <class T>\nstruct MonoidMin {\n    using S = T;\n    static S op(const\
    \ S &a, const S &b) { return b < a ? b : a; }\n    static S e() { return numeric_limits<T>::max();\
    \ }\n};\n\n// \u6700\u5927\u5024 (\u5358\u4F4D\u5143\u306F numeric_limits<T>::lowest())\n\
    template <class T>\nstruct MonoidMax {\n    using S = T;\n    static S op(const\
    \ S &a, const S &b) { return a < b ? b : a; }\n    static S e() { return numeric_limits<T>::lowest();\
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
    \    }\n    return r;\n}\n#line 3 \"algebra/acted_monoid.hpp\"\n\n// \u9045\u5EF6\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306A\u3069\u306B\u6E21\u3059\u300C\u4F5C\
    \u7528\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u300D(ACL \u306E lazy_segtree \u3068\
    \u540C\u3058\u898F\u7D04)\n// \u5F62\u5F0F:\n//   using S = \u5024\u306E\u578B\
    ;   static S op(S, S);  static S e();\n//   using F = \u4F5C\u7528\u306E\u578B\
    ; static S mapping(F f, S x);  // f \u3092 x \u306B\u4F5C\u7528\u3055\u305B\u308B\
    \n//                       static F composition(F f, F g);  // \u5148\u306B g\uFF0C\
    \u6B21\u306B f (f \u2218 g)\n//                       static F id();\n\n// \u533A\
    \u9593 1 \u6B21\u95A2\u6570\u4F5C\u7528\u30FB\u533A\u9593\u548C\uFF0ES \u306F\
    \ {\u548C, \u9577\u3055}\n// \u521D\u671F\u5024\u306F ActedAffineSum<T>::make(x)\
    \ (= {x, 1}) \u3067\u4F5C\u308B\ntemplate <class T>\nstruct ActedAffineSum {\n\
    \    struct S {\n        T sum, len;\n    };\n    using F = Affine<T>;\n    static\
    \ S make(const T &x) { return {x, T(1)}; }\n    static S op(const S &a, const\
    \ S &b) { return {a.sum + b.sum, a.len + b.len}; }\n    static S e() { return\
    \ {T(0), T(0)}; }\n    static S mapping(const F &f, const S &x) { return {f.a\
    \ * x.sum + f.b * x.len, x.len}; }\n    static F composition(const F &f, const\
    \ F &g) { return g.then(f); }\n    static F id() { return F(); }\n};\n\n// \u533A\
    \u9593\u52A0\u7B97\u30FB\u533A\u9593\u548C\uFF0ES \u306F {\u548C, \u9577\u3055\
    }\ntemplate <class T>\nstruct ActedAddSum {\n    struct S {\n        T sum, len;\n\
    \    };\n    using F = T;\n    static S make(const T &x) { return {x, T(1)}; }\n\
    \    static S op(const S &a, const S &b) { return {a.sum + b.sum, a.len + b.len};\
    \ }\n    static S e() { return {T(0), T(0)}; }\n    static S mapping(const F &f,\
    \ const S &x) { return {x.sum + f * x.len, x.len}; }\n    static F composition(const\
    \ F &f, const F &g) { return f + g; }\n    static F id() { return F(0); }\n};\n\
    \n// \u533A\u9593\u52A0\u7B97\u30FB\u533A\u9593\u6700\u5C0F\u5024\ntemplate <class\
    \ T>\nstruct ActedAddMin {\n    using S = T;\n    using F = T;\n    static S op(const\
    \ S &a, const S &b) { return b < a ? b : a; }\n    static S e() { return numeric_limits<T>::max();\
    \ }\n    // \u5358\u4F4D\u5143 (\u7A7A\u533A\u9593) \u306B\u306F\u4F5C\u7528\u3055\
    \u305B\u306A\u3044\n    static S mapping(const F &f, const S &x) { return x ==\
    \ e() ? x : x + f; }\n    static F composition(const F &f, const F &g) { return\
    \ f + g; }\n    static F id() { return F(0); }\n};\n\n// \u533A\u9593\u52A0\u7B97\
    \u30FB\u533A\u9593\u6700\u5927\u5024\ntemplate <class T>\nstruct ActedAddMax {\n\
    \    using S = T;\n    using F = T;\n    static S op(const S &a, const S &b) {\
    \ return a < b ? b : a; }\n    static S e() { return numeric_limits<T>::lowest();\
    \ }\n    static S mapping(const F &f, const S &x) { return x == e() ? x : x +\
    \ f; }\n    static F composition(const F &f, const F &g) { return f + g; }\n \
    \   static F id() { return F(0); }\n};\n\n// \u533A\u9593\u4EE3\u5165\u7528\u306E\
    \u4F5C\u7528 (\u5024\u3092\u6301\u305F\u306A\u3044\u3068\u304D\u306F\u6052\u7B49\
    \u5199\u50CF)\ntemplate <class T>\nstruct AssignAction {\n    T x{};\n    bool\
    \ has = false;\n    AssignAction() = default;\n    AssignAction(const T &x) :\
    \ x(x), has(true) {}\n};\n\n// \u533A\u9593\u4EE3\u5165\u30FB\u533A\u9593\u548C\
    \uFF0ES \u306F {\u548C, \u9577\u3055}\ntemplate <class T>\nstruct ActedAssignSum\
    \ {\n    struct S {\n        T sum, len;\n    };\n    using F = AssignAction<T>;\n\
    \    static S make(const T &x) { return {x, T(1)}; }\n    static S op(const S\
    \ &a, const S &b) { return {a.sum + b.sum, a.len + b.len}; }\n    static S e()\
    \ { return {T(0), T(0)}; }\n    static S mapping(const F &f, const S &x) { return\
    \ f.has ? S{f.x * x.len, x.len} : x; }\n    static F composition(const F &f, const\
    \ F &g) { return f.has ? f : g; }\n    static F id() { return F(); }\n};\n\n//\
    \ \u533A\u9593\u4EE3\u5165\u30FB\u533A\u9593\u6700\u5C0F\u5024\ntemplate <class\
    \ T>\nstruct ActedAssignMin {\n    using S = T;\n    using F = AssignAction<T>;\n\
    \    static S op(const S &a, const S &b) { return b < a ? b : a; }\n    static\
    \ S e() { return numeric_limits<T>::max(); }\n    static S mapping(const F &f,\
    \ const S &x) { return f.has ? f.x : x; }\n    static F composition(const F &f,\
    \ const F &g) { return f.has ? f : g; }\n    static F id() { return F(); }\n};\n\
    \n// \u533A\u9593\u4EE3\u5165\u30FB\u533A\u9593\u6700\u5927\u5024\ntemplate <class\
    \ T>\nstruct ActedAssignMax {\n    using S = T;\n    using F = AssignAction<T>;\n\
    \    static S op(const S &a, const S &b) { return a < b ? b : a; }\n    static\
    \ S e() { return numeric_limits<T>::lowest(); }\n    static S mapping(const F\
    \ &f, const S &x) { return f.has ? f.x : x; }\n    static F composition(const\
    \ F &f, const F &g) { return f.has ? f : g; }\n    static F id() { return F();\
    \ }\n};\n\n// \u4F5C\u7528\u306A\u3057 (\u30E2\u30CE\u30A4\u30C9 M \u3092\u305D\
    \u306E\u307E\u307E\u4F5C\u7528\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u3068\u3057\
    \u3066\u4F7F\u3046)\uFF0E\u5E73\u8861\u4E8C\u5206\u6728\u3067\u53CD\u8EE2\u3060\
    \u3051\u3057\u305F\u3044\u3068\u304D\u306A\u3069\ntemplate <class M>\nstruct ActedNone\
    \ {\n    using S = typename M::S;\n    struct F {};\n    static S op(const S &a,\
    \ const S &b) { return M::op(a, b); }\n    static S e() { return M::e(); }\n \
    \   static S mapping(const F &, const S &x) { return x; }\n    static F composition(const\
    \ F &, const F &) { return F(); }\n    static F id() { return F(); }\n};\n#line\
    \ 4 \"data_structure/kd_tree.hpp\"\n\n// k-d \u6728 (2 \u6B21\u5143\u306E\u70B9\
    \u306B\u5BFE\u3059\u308B\u9577\u65B9\u5F62\u4F5C\u7528\u30FB\u9577\u65B9\u5F62\
    \u7A4D\u30FB\u4E00\u70B9\u66F4\u65B0)\n// AM \u306F\u4F5C\u7528\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9 (algebra/acted_monoid.hpp \u53C2\u7167)\uFF0E\u7A4D\u306F\u53EF\
    \u63DB\u3067\u3042\u308B\u3053\u3068 (\u70B9\u306E\u9806\u756A\u306F\u6C7A\u307E\
    \u3063\u3066\u3044\u306A\u3044\u305F\u3081)\n// \u70B9\u3092\u30D0\u30E9\u30F3\
    \u30B9\u3088\u304F 2 \u5206\u5272\u3057\u305F\u6728\u3067\uFF0C\u5404\u30CE\u30FC\
    \u30C9\u306F\u70B9\u306E\u5916\u63A5\u9577\u65B9\u5F62\u30FB\u7A4D\u30FB\u9045\
    \u5EF6\u4F5C\u7528\u3092\u6301\u3064\n// \u9577\u65B9\u5F62\u30AF\u30A8\u30EA\
    \ O(\u221An)\uFF0C\u4E00\u70B9\u66F4\u65B0 O(log n)\ntemplate <class X, class\
    \ AM>\nstruct KDTree {\n    using S = typename AM::S;\n    using F = typename\
    \ AM::F;\n    struct Node {\n        X x0, x1, y0, y1;  // \u5916\u63A5\u9577\u65B9\
    \u5F62 (\u9589\u533A\u9593)\n        S val;\n        F lz;\n        bool has_lz;\n\
    \    };\n    int n;\n    vector<Node> d;\n    vector<int> leaf;       // leaf[i]:\
    \ \u70B9 i \u306E\u8449\u306E\u30CE\u30FC\u30C9\u756A\u53F7\n    vector<char>\
    \ internal;  // \u5B50\u3092\u6301\u3064\u30CE\u30FC\u30C9\u304B\n\n    KDTree()\
    \ : n(0) {}\n    KDTree(const vector<X> &xs, const vector<X> &ys, const vector<S>\
    \ &vals) : n(xs.size()) {\n        leaf.resize(n);\n        if (n == 0) return;\n\
    \        d.resize(4 * n), internal.assign(4 * n, 0);\n        vector<int> ord(n);\n\
    \        iota(ord.begin(), ord.end(), 0);\n        build(1, ord.begin(), ord.end(),\
    \ xs, ys, vals);\n    }\n\n    int size() const { return n; }\n\n    // l <= x\
    \ < r, d <= y < u \u306E\u70B9\u306E\u7A4D\n    S prod(X l, X dd, X r, X u) {\n\
    \        if (n == 0 || !(l < r) || !(dd < u)) return AM::e();\n        return\
    \ prod_rec(1, l, dd, r - 1, u - 1);\n    }\n\n    // l <= x < r, d <= y < u \u306E\
    \u70B9\u306B f \u3092\u4F5C\u7528\n    void apply(X l, X dd, X r, X u, const F\
    \ &f) {\n        if (n == 0 || !(l < r) || !(dd < u)) return;\n        apply_rec(1,\
    \ l, dd, r - 1, u - 1, f);\n    }\n\n    S all_prod() const { return n ? d[1].val\
    \ : AM::e(); }\n\n    // \u70B9 i (\u69CB\u7BC9\u6642\u306E\u756A\u53F7) \u306E\
    \u5024\n    S get(int i) {\n        push_path(leaf[i]);\n        return d[leaf[i]].val;\n\
    \    }\n\n    // \u70B9 i \u306E\u5024\u3092 x \u306B\u3059\u308B\n    void set(int\
    \ i, const S &x) {\n        int k = leaf[i];\n        push_path(k);\n        d[k].val\
    \ = x;\n        for (k >>= 1; k; k >>= 1) d[k].val = AM::op(d[2 * k].val, d[2\
    \ * k + 1].val);\n    }\n\n    // \u5168\u3066\u306E\u70B9\u306E\u73FE\u5728\u306E\
    \u5024 (\u69CB\u7BC9\u6642\u306E\u756A\u53F7\u9806)\uFF0EO(n)\n    vector<S> values()\
    \ {\n        vector<S> res(n);\n        // \u89AA\u306F\u5B50\u3088\u308A\u756A\
    \u53F7\u304C\u5C0F\u3055\u3044\u306E\u3067\uFF0C\u756A\u53F7\u9806\u306B push\
    \ \u3059\u308C\u3070\u5168\u3066\u306E\u9045\u5EF6\u304C\u8449\u307E\u3067\u964D\
    \u308A\u308B\n        for (int k = 1; k < (int)d.size(); k++) if (internal[k])\
    \ push(k);\n        for (int i = 0; i < n; i++) res[i] = d[leaf[i]].val;\n   \
    \     return res;\n    }\n\n  private:\n    using It = vector<int>::iterator;\n\
    \    void build(int k, It b, It e, const vector<X> &xs, const vector<X> &ys, const\
    \ vector<S> &vals) {\n        Node &nd = d[k];\n        nd.x0 = nd.x1 = xs[*b],\
    \ nd.y0 = nd.y1 = ys[*b];\n        for (It it = b; it != e; ++it) {\n        \
    \    nd.x0 = std::min(nd.x0, xs[*it]), nd.x1 = std::max(nd.x1, xs[*it]);\n   \
    \         nd.y0 = std::min(nd.y0, ys[*it]), nd.y1 = std::max(nd.y1, ys[*it]);\n\
    \        }\n        nd.lz = AM::id(), nd.has_lz = false;\n        if (e - b ==\
    \ 1) {\n            nd.val = vals[*b];\n            leaf[*b] = k;\n          \
    \  return;\n        }\n        // \u6DF1\u3055\u3054\u3068\u306B x, y \u3092\u4EA4\
    \u4E92\u306B\uFF0C\u4E2D\u592E\u5024\u3067\u5206\u3051\u308B\n        // (\u5E83\
    \u304C\u308A\u306E\u5927\u304D\u3044\u8EF8\u3067\u5206\u3051\u308B\u3068\uFF0C\
    y \u304C\u6570\u7A2E\u985E\u3057\u304B\u306A\u3044\u5165\u529B\u3067 y \u306E\u7D30\
    \u3044\u5E2F\u306E\u30AF\u30A8\u30EA\u304C O(n) \u306B\u306A\u308B)\n        internal[k]\
    \ = 1;\n        It m = b + (e - b) / 2;\n        bool by_x = (31 - __builtin_clz(k))\
    \ % 2 == 0;\n        if (by_x) nth_element(b, m, e, [&](int i, int j) { return\
    \ xs[i] < xs[j]; });\n        else nth_element(b, m, e, [&](int i, int j) { return\
    \ ys[i] < ys[j]; });\n        build(2 * k, b, m, xs, ys, vals);\n        build(2\
    \ * k + 1, m, e, xs, ys, vals);\n        d[k].val = AM::op(d[2 * k].val, d[2 *\
    \ k + 1].val);\n    }\n\n    void all_apply(int k, const F &f) {\n        Node\
    \ &nd = d[k];\n        nd.val = AM::mapping(f, nd.val);\n        nd.lz = nd.has_lz\
    \ ? AM::composition(f, nd.lz) : f;\n        nd.has_lz = true;\n    }\n    void\
    \ push(int k) {\n        if (!d[k].has_lz) return;\n        all_apply(2 * k, d[k].lz);\n\
    \        all_apply(2 * k + 1, d[k].lz);\n        d[k].has_lz = false;\n    }\n\
    \    void push_path(int k) {\n        int h = 31 - __builtin_clz(k);\n       \
    \ for (int s = h; s > 0; s--) push(k >> s);\n    }\n\n    // [l, r] \xD7 [dd,\
    \ u] (\u9589\u533A\u9593)\n    S prod_rec(int k, X l, X dd, X r, X u) {\n    \
    \    const Node &nd = d[k];\n        if (nd.x1 < l || r < nd.x0 || nd.y1 < dd\
    \ || u < nd.y0) return AM::e();\n        if (l <= nd.x0 && nd.x1 <= r && dd <=\
    \ nd.y0 && nd.y1 <= u) return nd.val;\n        push(k);\n        return AM::op(prod_rec(2\
    \ * k, l, dd, r, u), prod_rec(2 * k + 1, l, dd, r, u));\n    }\n\n    void apply_rec(int\
    \ k, X l, X dd, X r, X u, const F &f) {\n        Node &nd = d[k];\n        if\
    \ (nd.x1 < l || r < nd.x0 || nd.y1 < dd || u < nd.y0) return;\n        if (l <=\
    \ nd.x0 && nd.x1 <= r && dd <= nd.y0 && nd.y1 <= u) return all_apply(k, f);\n\
    \        push(k);\n        apply_rec(2 * k, l, dd, r, u, f);\n        apply_rec(2\
    \ * k + 1, l, dd, r, u, f);\n        d[k].val = AM::op(d[2 * k].val, d[2 * k +\
    \ 1].val);\n    }\n\n};\n\n// \u70B9\u306E\u8FFD\u52A0\u3082\u3067\u304D\u308B\
    \ k-d \u6728 (\u30AA\u30F3\u30E9\u30A4\u30F3)\n// \u5927\u304D\u3055\u304C 2 \u51AA\
    \u306E KDTree \u3092\u9AD8\u3005 log \u500B\u6301\u3061\uFF0C\u8FFD\u52A0\u306E\
    \u305F\u3073\u306B\u540C\u3058\u5927\u304D\u3055\u306E\u3082\u306E\u3092\u4F75\
    \u5408\u3057\u3066\u4F5C\u308A\u76F4\u3059 (\u4E8C\u9032\u30AB\u30A6\u30F3\u30BF\
    )\n// \u9577\u65B9\u5F62\u30AF\u30A8\u30EA O(\u221An)\uFF0C\u4E00\u70B9\u66F4\u65B0\
    \ O(log n)\uFF0C\u8FFD\u52A0\u306A\u3089\u3057 O(log^2 n)\ntemplate <class X,\
    \ class AM>\nstruct DynamicKDTree {\n    using S = typename AM::S;\n    using\
    \ F = typename AM::F;\n    struct Bucket {\n        vector<int> ids;  // \u542B\
    \u3080\u70B9\u306E\u756A\u53F7 (KDTree \u306E\u4E2D\u306E\u756A\u53F7\u9806)\n\
    \        KDTree<X, AM> kd;\n    };\n    vector<X> px, py;            // \u70B9\
    \u306E\u5EA7\u6A19 (\u8FFD\u52A0\u9806)\n    vector<int> where, local;    // \u70B9\
    \ i \u306F\u30D0\u30B1\u30C3\u30C8 where[i] \u306E local[i] \u756A\u76EE\n   \
    \ vector<Bucket> buckets;\n\n    DynamicKDTree() = default;\n    DynamicKDTree(const\
    \ vector<X> &xs, const vector<X> &ys, const vector<S> &vals) : px(xs), py(ys)\
    \ {\n        int n = xs.size();\n        where.assign(n, 0), local.resize(n);\n\
    \        if (n == 0) return;\n        Bucket b;\n        b.ids.resize(n);\n  \
    \      iota(b.ids.begin(), b.ids.end(), 0);\n        b.kd = KDTree<X, AM>(xs,\
    \ ys, vals);\n        for (int i = 0; i < n; i++) local[i] = i;\n        buckets.push_back(std::move(b));\n\
    \    }\n\n    int size() const { return px.size(); }\n\n    // \u70B9 (x, y) \u3092\
    \u5024 v \u3067\u8FFD\u52A0\u3057\uFF0C\u305D\u306E\u756A\u53F7\u3092\u8FD4\u3059\
    \n    int add_point(X x, X y, const S &v) {\n        int id = px.size();\n   \
    \     px.push_back(x), py.push_back(y), where.push_back(0), local.push_back(0);\n\
    \        vector<int> ids{id};\n        vector<S> vals{v};\n        while (!buckets.empty()\
    \ && buckets.back().ids.size() <= ids.size()) {\n            Bucket &t = buckets.back();\n\
    \            vector<S> tv = t.kd.values();\n            ids.insert(ids.end(),\
    \ t.ids.begin(), t.ids.end());\n            vals.insert(vals.end(), tv.begin(),\
    \ tv.end());\n            buckets.pop_back();\n        }\n        int m = ids.size();\n\
    \        vector<X> xs(m), ys(m);\n        for (int k = 0; k < m; k++) xs[k] =\
    \ px[ids[k]], ys[k] = py[ids[k]];\n        Bucket b;\n        b.kd = KDTree<X,\
    \ AM>(xs, ys, vals);\n        b.ids = std::move(ids);\n        int bi = buckets.size();\n\
    \        for (int k = 0; k < m; k++) where[b.ids[k]] = bi, local[b.ids[k]] = k;\n\
    \        buckets.push_back(std::move(b));\n        return id;\n    }\n\n    S\
    \ get(int i) { return buckets[where[i]].kd.get(local[i]); }\n    void set(int\
    \ i, const S &v) { buckets[where[i]].kd.set(local[i], v); }\n\n    // l <= x <\
    \ r, d <= y < u \u306E\u70B9\u306E\u7A4D\n    S prod(X l, X d, X r, X u) {\n \
    \       S res = AM::e();\n        for (auto &b : buckets) res = AM::op(res, b.kd.prod(l,\
    \ d, r, u));\n        return res;\n    }\n\n    // l <= x < r, d <= y < u \u306E\
    \u70B9\u306B f \u3092\u4F5C\u7528\n    void apply(X l, X d, X r, X u, const F\
    \ &f) {\n        for (auto &b : buckets) b.kd.apply(l, d, r, u, f);\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"../algebra/acted_monoid.hpp\"\
    \n\n// k-d \u6728 (2 \u6B21\u5143\u306E\u70B9\u306B\u5BFE\u3059\u308B\u9577\u65B9\
    \u5F62\u4F5C\u7528\u30FB\u9577\u65B9\u5F62\u7A4D\u30FB\u4E00\u70B9\u66F4\u65B0\
    )\n// AM \u306F\u4F5C\u7528\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (algebra/acted_monoid.hpp\
    \ \u53C2\u7167)\uFF0E\u7A4D\u306F\u53EF\u63DB\u3067\u3042\u308B\u3053\u3068 (\u70B9\
    \u306E\u9806\u756A\u306F\u6C7A\u307E\u3063\u3066\u3044\u306A\u3044\u305F\u3081\
    )\n// \u70B9\u3092\u30D0\u30E9\u30F3\u30B9\u3088\u304F 2 \u5206\u5272\u3057\u305F\
    \u6728\u3067\uFF0C\u5404\u30CE\u30FC\u30C9\u306F\u70B9\u306E\u5916\u63A5\u9577\
    \u65B9\u5F62\u30FB\u7A4D\u30FB\u9045\u5EF6\u4F5C\u7528\u3092\u6301\u3064\n// \u9577\
    \u65B9\u5F62\u30AF\u30A8\u30EA O(\u221An)\uFF0C\u4E00\u70B9\u66F4\u65B0 O(log\
    \ n)\ntemplate <class X, class AM>\nstruct KDTree {\n    using S = typename AM::S;\n\
    \    using F = typename AM::F;\n    struct Node {\n        X x0, x1, y0, y1; \
    \ // \u5916\u63A5\u9577\u65B9\u5F62 (\u9589\u533A\u9593)\n        S val;\n   \
    \     F lz;\n        bool has_lz;\n    };\n    int n;\n    vector<Node> d;\n \
    \   vector<int> leaf;       // leaf[i]: \u70B9 i \u306E\u8449\u306E\u30CE\u30FC\
    \u30C9\u756A\u53F7\n    vector<char> internal;  // \u5B50\u3092\u6301\u3064\u30CE\
    \u30FC\u30C9\u304B\n\n    KDTree() : n(0) {}\n    KDTree(const vector<X> &xs,\
    \ const vector<X> &ys, const vector<S> &vals) : n(xs.size()) {\n        leaf.resize(n);\n\
    \        if (n == 0) return;\n        d.resize(4 * n), internal.assign(4 * n,\
    \ 0);\n        vector<int> ord(n);\n        iota(ord.begin(), ord.end(), 0);\n\
    \        build(1, ord.begin(), ord.end(), xs, ys, vals);\n    }\n\n    int size()\
    \ const { return n; }\n\n    // l <= x < r, d <= y < u \u306E\u70B9\u306E\u7A4D\
    \n    S prod(X l, X dd, X r, X u) {\n        if (n == 0 || !(l < r) || !(dd <\
    \ u)) return AM::e();\n        return prod_rec(1, l, dd, r - 1, u - 1);\n    }\n\
    \n    // l <= x < r, d <= y < u \u306E\u70B9\u306B f \u3092\u4F5C\u7528\n    void\
    \ apply(X l, X dd, X r, X u, const F &f) {\n        if (n == 0 || !(l < r) ||\
    \ !(dd < u)) return;\n        apply_rec(1, l, dd, r - 1, u - 1, f);\n    }\n\n\
    \    S all_prod() const { return n ? d[1].val : AM::e(); }\n\n    // \u70B9 i\
    \ (\u69CB\u7BC9\u6642\u306E\u756A\u53F7) \u306E\u5024\n    S get(int i) {\n  \
    \      push_path(leaf[i]);\n        return d[leaf[i]].val;\n    }\n\n    // \u70B9\
    \ i \u306E\u5024\u3092 x \u306B\u3059\u308B\n    void set(int i, const S &x) {\n\
    \        int k = leaf[i];\n        push_path(k);\n        d[k].val = x;\n    \
    \    for (k >>= 1; k; k >>= 1) d[k].val = AM::op(d[2 * k].val, d[2 * k + 1].val);\n\
    \    }\n\n    // \u5168\u3066\u306E\u70B9\u306E\u73FE\u5728\u306E\u5024 (\u69CB\
    \u7BC9\u6642\u306E\u756A\u53F7\u9806)\uFF0EO(n)\n    vector<S> values() {\n  \
    \      vector<S> res(n);\n        // \u89AA\u306F\u5B50\u3088\u308A\u756A\u53F7\
    \u304C\u5C0F\u3055\u3044\u306E\u3067\uFF0C\u756A\u53F7\u9806\u306B push \u3059\
    \u308C\u3070\u5168\u3066\u306E\u9045\u5EF6\u304C\u8449\u307E\u3067\u964D\u308A\
    \u308B\n        for (int k = 1; k < (int)d.size(); k++) if (internal[k]) push(k);\n\
    \        for (int i = 0; i < n; i++) res[i] = d[leaf[i]].val;\n        return\
    \ res;\n    }\n\n  private:\n    using It = vector<int>::iterator;\n    void build(int\
    \ k, It b, It e, const vector<X> &xs, const vector<X> &ys, const vector<S> &vals)\
    \ {\n        Node &nd = d[k];\n        nd.x0 = nd.x1 = xs[*b], nd.y0 = nd.y1 =\
    \ ys[*b];\n        for (It it = b; it != e; ++it) {\n            nd.x0 = std::min(nd.x0,\
    \ xs[*it]), nd.x1 = std::max(nd.x1, xs[*it]);\n            nd.y0 = std::min(nd.y0,\
    \ ys[*it]), nd.y1 = std::max(nd.y1, ys[*it]);\n        }\n        nd.lz = AM::id(),\
    \ nd.has_lz = false;\n        if (e - b == 1) {\n            nd.val = vals[*b];\n\
    \            leaf[*b] = k;\n            return;\n        }\n        // \u6DF1\u3055\
    \u3054\u3068\u306B x, y \u3092\u4EA4\u4E92\u306B\uFF0C\u4E2D\u592E\u5024\u3067\
    \u5206\u3051\u308B\n        // (\u5E83\u304C\u308A\u306E\u5927\u304D\u3044\u8EF8\
    \u3067\u5206\u3051\u308B\u3068\uFF0Cy \u304C\u6570\u7A2E\u985E\u3057\u304B\u306A\
    \u3044\u5165\u529B\u3067 y \u306E\u7D30\u3044\u5E2F\u306E\u30AF\u30A8\u30EA\u304C\
    \ O(n) \u306B\u306A\u308B)\n        internal[k] = 1;\n        It m = b + (e -\
    \ b) / 2;\n        bool by_x = (31 - __builtin_clz(k)) % 2 == 0;\n        if (by_x)\
    \ nth_element(b, m, e, [&](int i, int j) { return xs[i] < xs[j]; });\n       \
    \ else nth_element(b, m, e, [&](int i, int j) { return ys[i] < ys[j]; });\n  \
    \      build(2 * k, b, m, xs, ys, vals);\n        build(2 * k + 1, m, e, xs, ys,\
    \ vals);\n        d[k].val = AM::op(d[2 * k].val, d[2 * k + 1].val);\n    }\n\n\
    \    void all_apply(int k, const F &f) {\n        Node &nd = d[k];\n        nd.val\
    \ = AM::mapping(f, nd.val);\n        nd.lz = nd.has_lz ? AM::composition(f, nd.lz)\
    \ : f;\n        nd.has_lz = true;\n    }\n    void push(int k) {\n        if (!d[k].has_lz)\
    \ return;\n        all_apply(2 * k, d[k].lz);\n        all_apply(2 * k + 1, d[k].lz);\n\
    \        d[k].has_lz = false;\n    }\n    void push_path(int k) {\n        int\
    \ h = 31 - __builtin_clz(k);\n        for (int s = h; s > 0; s--) push(k >> s);\n\
    \    }\n\n    // [l, r] \xD7 [dd, u] (\u9589\u533A\u9593)\n    S prod_rec(int\
    \ k, X l, X dd, X r, X u) {\n        const Node &nd = d[k];\n        if (nd.x1\
    \ < l || r < nd.x0 || nd.y1 < dd || u < nd.y0) return AM::e();\n        if (l\
    \ <= nd.x0 && nd.x1 <= r && dd <= nd.y0 && nd.y1 <= u) return nd.val;\n      \
    \  push(k);\n        return AM::op(prod_rec(2 * k, l, dd, r, u), prod_rec(2 *\
    \ k + 1, l, dd, r, u));\n    }\n\n    void apply_rec(int k, X l, X dd, X r, X\
    \ u, const F &f) {\n        Node &nd = d[k];\n        if (nd.x1 < l || r < nd.x0\
    \ || nd.y1 < dd || u < nd.y0) return;\n        if (l <= nd.x0 && nd.x1 <= r &&\
    \ dd <= nd.y0 && nd.y1 <= u) return all_apply(k, f);\n        push(k);\n     \
    \   apply_rec(2 * k, l, dd, r, u, f);\n        apply_rec(2 * k + 1, l, dd, r,\
    \ u, f);\n        d[k].val = AM::op(d[2 * k].val, d[2 * k + 1].val);\n    }\n\n\
    };\n\n// \u70B9\u306E\u8FFD\u52A0\u3082\u3067\u304D\u308B k-d \u6728 (\u30AA\u30F3\
    \u30E9\u30A4\u30F3)\n// \u5927\u304D\u3055\u304C 2 \u51AA\u306E KDTree \u3092\u9AD8\
    \u3005 log \u500B\u6301\u3061\uFF0C\u8FFD\u52A0\u306E\u305F\u3073\u306B\u540C\u3058\
    \u5927\u304D\u3055\u306E\u3082\u306E\u3092\u4F75\u5408\u3057\u3066\u4F5C\u308A\
    \u76F4\u3059 (\u4E8C\u9032\u30AB\u30A6\u30F3\u30BF)\n// \u9577\u65B9\u5F62\u30AF\
    \u30A8\u30EA O(\u221An)\uFF0C\u4E00\u70B9\u66F4\u65B0 O(log n)\uFF0C\u8FFD\u52A0\
    \u306A\u3089\u3057 O(log^2 n)\ntemplate <class X, class AM>\nstruct DynamicKDTree\
    \ {\n    using S = typename AM::S;\n    using F = typename AM::F;\n    struct\
    \ Bucket {\n        vector<int> ids;  // \u542B\u3080\u70B9\u306E\u756A\u53F7\
    \ (KDTree \u306E\u4E2D\u306E\u756A\u53F7\u9806)\n        KDTree<X, AM> kd;\n \
    \   };\n    vector<X> px, py;            // \u70B9\u306E\u5EA7\u6A19 (\u8FFD\u52A0\
    \u9806)\n    vector<int> where, local;    // \u70B9 i \u306F\u30D0\u30B1\u30C3\
    \u30C8 where[i] \u306E local[i] \u756A\u76EE\n    vector<Bucket> buckets;\n\n\
    \    DynamicKDTree() = default;\n    DynamicKDTree(const vector<X> &xs, const\
    \ vector<X> &ys, const vector<S> &vals) : px(xs), py(ys) {\n        int n = xs.size();\n\
    \        where.assign(n, 0), local.resize(n);\n        if (n == 0) return;\n \
    \       Bucket b;\n        b.ids.resize(n);\n        iota(b.ids.begin(), b.ids.end(),\
    \ 0);\n        b.kd = KDTree<X, AM>(xs, ys, vals);\n        for (int i = 0; i\
    \ < n; i++) local[i] = i;\n        buckets.push_back(std::move(b));\n    }\n\n\
    \    int size() const { return px.size(); }\n\n    // \u70B9 (x, y) \u3092\u5024\
    \ v \u3067\u8FFD\u52A0\u3057\uFF0C\u305D\u306E\u756A\u53F7\u3092\u8FD4\u3059\n\
    \    int add_point(X x, X y, const S &v) {\n        int id = px.size();\n    \
    \    px.push_back(x), py.push_back(y), where.push_back(0), local.push_back(0);\n\
    \        vector<int> ids{id};\n        vector<S> vals{v};\n        while (!buckets.empty()\
    \ && buckets.back().ids.size() <= ids.size()) {\n            Bucket &t = buckets.back();\n\
    \            vector<S> tv = t.kd.values();\n            ids.insert(ids.end(),\
    \ t.ids.begin(), t.ids.end());\n            vals.insert(vals.end(), tv.begin(),\
    \ tv.end());\n            buckets.pop_back();\n        }\n        int m = ids.size();\n\
    \        vector<X> xs(m), ys(m);\n        for (int k = 0; k < m; k++) xs[k] =\
    \ px[ids[k]], ys[k] = py[ids[k]];\n        Bucket b;\n        b.kd = KDTree<X,\
    \ AM>(xs, ys, vals);\n        b.ids = std::move(ids);\n        int bi = buckets.size();\n\
    \        for (int k = 0; k < m; k++) where[b.ids[k]] = bi, local[b.ids[k]] = k;\n\
    \        buckets.push_back(std::move(b));\n        return id;\n    }\n\n    S\
    \ get(int i) { return buckets[where[i]].kd.get(local[i]); }\n    void set(int\
    \ i, const S &v) { buckets[where[i]].kd.set(local[i], v); }\n\n    // l <= x <\
    \ r, d <= y < u \u306E\u70B9\u306E\u7A4D\n    S prod(X l, X d, X r, X u) {\n \
    \       S res = AM::e();\n        for (auto &b : buckets) res = AM::op(res, b.kd.prod(l,\
    \ d, r, u));\n        return res;\n    }\n\n    // l <= x < r, d <= y < u \u306E\
    \u70B9\u306B f \u3092\u4F5C\u7528\n    void apply(X l, X d, X r, X u, const F\
    \ &f) {\n        for (auto &b : buckets) b.kd.apply(l, d, r, u, f);\n    }\n};\n"
  dependsOn:
  - template.hpp
  - algebra/acted_monoid.hpp
  - algebra/monoid.hpp
  - template.hpp
  isVerificationFile: false
  path: data_structure/kd_tree.hpp
  requiredBy: []
  timestamp: '2026-10-15 00:08:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_point_set_rectangle_affine_rectangle_sum.test.cpp
  - test/unittest/kd_tree.test.cpp
documentation_of: data_structure/kd_tree.hpp
layout: document
title: "k-d \u6728 (\u9577\u65B9\u5F62\u4F5C\u7528\u30FB\u9577\u65B9\u5F62\u7A4D)"
---

## 概要

2 次元平面上の値付きの点に対して、**長方形の中の点への作用**・**長方形の中の点の積**・一点更新を $O(\sqrt n)$ で処理する。値と作用は遅延セグメント木と同じ作用付きモノイド（[acted_monoid.hpp](../../algebra/acted_monoid.hpp)）。

- `KDTree<X, AM>`：点が固定。点を「x の中央値で 2 分割 → 各半分を y の中央値で 2 分割 → …」と **軸を交互に** 分けた木で、各ノードが点の外接長方形・積・遅延作用を持つ。クエリでは、外接長方形がクエリの長方形に含まれるノードはそのまま使い、交わらないノードは無視し、それ以外は子に降りる。
- `DynamicKDTree<X, AM>`：点の **追加** もできる（オンライン）。大きさが 2 冪の `KDTree` を高々 $\log n$ 個持ち、追加のたびに同じ大きさのものを併合して作り直す（二進カウンタ）。

## 使い方

```cpp
using AM = ActedAffineSum<mint>;
vector<int> x(n), y(n);
vector<AM::S> w(n);                       // w[i] = AM::make(重み)
KDTree<int, AM> kd(x, y, w);
kd.prod(l, d, r, u).sum;                  // l <= x < r, d <= y < u の点の積
kd.apply(l, d, r, u, {a, b});             // 同じ範囲の点に作用
kd.get(i); kd.set(i, AM::make(v));        // 点 i (構築時の番号)
kd.all_prod(); kd.values();

DynamicKDTree<int, AM> dk(x, y, w);       // 空でもよい: DynamicKDTree<int, AM> dk;
int id = dk.add_point(px, py, AM::make(v));  // 追加した点の番号 (0, 1, 2, ... の順)
dk.prod(l, d, r, u); dk.apply(l, d, r, u, f); dk.get(id); dk.set(id, s);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `KDTree<X, AM>(xs, ys, vals)` | 構築 | $O(n \log n)$ |
| `S prod(X l, X d, X r, X u)` | 長方形 $[l, r) \times [d, u)$ の点の積 | $O(\sqrt n)$ |
| `void apply(X l, X d, X r, X u, F f)` | 長方形の点に作用 | $O(\sqrt n)$ |
| `S get(int i)` / `void set(int i, S x)` | 一点取得 / 更新 | $O(\log n)$ |
| `vector<S> values()` | 全点の値 | $O(n)$ |
| `int add_point(X x, X y, S v)`（動的版） | 点の追加 | ならし $O(\log^2 n)$ |
| `prod` / `apply`（動的版） | | $O(\sqrt n)$ |

## 注意

- 積は **可換** であること（点の並び順は決まっていない）。
- 分割の軸は深さで交互にする。「広がりの大きい軸で分ける」と、$y$ が数種類しかない入力で $y$ の細い帯のクエリが $O(n)$ になる（Library Checker の hack ケースで 100 秒以上かかった）。
