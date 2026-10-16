---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/acted_monoid.hpp
    title: "\u4F5C\u7528\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (Acted Monoid)"
  - icon: ':question:'
    path: algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9 (Monoid)"
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/range_affine_range_sum_large_array.test.cpp
    title: test/range_affine_range_sum_large_array.test.cpp
  - icon: ':x:'
    path: test/unittest/lazy_segment_tree.test.cpp
    title: test/unittest/lazy_segment_tree.test.cpp
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
    \    }\n    return r;\n}\n#line 3 \"algebra/acted_monoid.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306A\u3069\u306B\u6E21\u3059\
    \u300C\u4F5C\u7528\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u300D(ACL \u306E lazy_segtree\
    \ \u3068\u540C\u3058\u898F\u7D04)\n// \u5F62\u5F0F:\n//   using S = \u5024\u306E\
    \u578B;   static S op(S, S);  static S e();\n//   using F = \u4F5C\u7528\u306E\
    \u578B; static S mapping(F f, S x);  // f \u3092 x \u306B\u4F5C\u7528\u3055\u305B\
    \u308B\n//                       static F composition(F f, F g);  // \u5148\u306B\
    \ g\uFF0C\u6B21\u306B f (f \u2218 g)\n//                       static F id();\n\
    \n// \u533A\u9593 1 \u6B21\u95A2\u6570\u4F5C\u7528\u30FB\u533A\u9593\u548C\uFF0E\
    S \u306F {\u548C, \u9577\u3055}\n// \u521D\u671F\u5024\u306F ActedAffineSum<T>::make(x)\
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
    \ 4 \"data_structure/dynamic_lazy_segment_tree.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u52D5\u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u6DFB\u5B57\
    \u304C\u5927\u304D\u3044\u5834\u5408\u306E\u533A\u9593\u4F5C\u7528\u30FB\u533A\
    \u9593\u7A4D)\n// \u6DFB\u5B57\u306F [0, n) (n \u306F 2^62 \u7A0B\u5EA6\u307E\u3067\
    )\uFF0E\u306F\u3058\u3081\u5168\u3066\u306E\u8981\u7D20\u304C x0 (\u7701\u7565\
    \u6642 e())\n// \u89E6\u3063\u305F\u90E8\u5206\u3060\u3051\u30CE\u30FC\u30C9\u3092\
    \u4F5C\u308B\uFF0E1 \u56DE\u306E\u64CD\u4F5C\u3067\u4F5C\u308B\u30CE\u30FC\u30C9\
    \u306F O(log n) \u500B\n//\n// \u5927\u304D\u3055\u3092 2 \u51AA\u306B\u5207\u308A\
    \u4E0A\u3052\uFF0C\u307E\u3060\u4F5C\u3063\u3066\u3044\u306A\u3044\u9577\u3055\
    \ 2^k \u306E\u533A\u9593\u306E\u7A4D\u306F x0^(2^k) \u3092\u4E8B\u524D\u8A08\u7B97\
    \u3057\u3066\u304A\u3044\u3066\u4F7F\u3046\ntemplate <class AM>\nstruct DynamicLazySegmentTree\
    \ {\n    using S = typename AM::S;\n    using F = typename AM::F;\n    struct\
    \ Node {\n        S val;\n        F lz;\n        int l, r;\n    };\n    long long\
    \ n;\n    int lg;\n    vector<S> pw;  // pw[k] = x0^(2^k)\n    vector<Node> t;\n\
    \    int root;\n\n    DynamicLazySegmentTree(long long n = 0, S x0 = AM::e())\
    \ : n(n) {\n        lg = 0;\n        while ((1LL << lg) < n) lg++;\n        pw.resize(lg\
    \ + 1);\n        pw[0] = x0;\n        for (int k = 1; k <= lg; k++) pw[k] = AM::op(pw[k\
    \ - 1], pw[k - 1]);\n        root = new_node(lg);\n    }\n\n    void reserve(int\
    \ k) { t.reserve(k); }\n\n    // a[p] = x\n    void set(long long p, const S &x)\
    \ { set(root, lg, 0, p, x); }\n\n    S get(long long p) { return prod(p, p + 1);\
    \ }\n\n    // op(a[l], ..., a[r-1])\uFF0El == r \u306A\u3089 e()\n    S prod(long\
    \ long l, long long r) {\n        if (l >= r) return AM::e();\n        return\
    \ prod(root, lg, 0, l, r, AM::id());\n    }\n\n    S all_prod() const { return\
    \ t[root].val; }\n\n    // i in [l, r) \u306B\u3064\u3044\u3066 a[i] = f(a[i])\n\
    \    void apply(long long l, long long r, const F &f) {\n        if (l >= r) return;\n\
    \        apply(root, lg, 0, l, r, f);\n    }\n\n  private:\n    int new_node(int\
    \ k) {\n        t.push_back({pw[k], AM::id(), -1, -1});\n        return int(t.size())\
    \ - 1;\n    }\n    // \u5B50\u3092 (\u306A\u3051\u308C\u3070\u4F5C\u3063\u3066\
    ) \u4F5C\u7528\u3092\u4E0B\u308D\u3059\n    void push(int v, int k) {\n      \
    \  if (t[v].l == -1) {\n            int a = new_node(k - 1);\n            int\
    \ b = new_node(k - 1);\n            t[v].l = a, t[v].r = b;\n        }\n     \
    \   const F f = t[v].lz;\n        all_apply(t[v].l, f);\n        all_apply(t[v].r,\
    \ f);\n        t[v].lz = AM::id();\n    }\n    void all_apply(int v, const F &f)\
    \ {\n        t[v].val = AM::mapping(f, t[v].val);\n        t[v].lz = AM::composition(f,\
    \ t[v].lz);\n    }\n    void update(int v) { t[v].val = AM::op(t[t[v].l].val,\
    \ t[t[v].r].val); }\n\n    // \u30CE\u30FC\u30C9 v \u306F\u533A\u9593 [lo, lo\
    \ + 2^k)\n    void set(int v, int k, long long lo, long long p, const S &x) {\n\
    \        if (k == 0) {\n            t[v].val = x;\n            return;\n     \
    \   }\n        push(v, k);\n        long long mid = lo + (1LL << (k - 1));\n \
    \       if (p < mid) set(t[v].l, k - 1, lo, p, x);\n        else set(t[v].r, k\
    \ - 1, mid, p, x);\n        update(v);\n    }\n\n    void apply(int v, int k,\
    \ long long lo, long long l, long long r, const F &f) {\n        long long hi\
    \ = lo + (1LL << k);\n        if (r <= lo || hi <= l) return;\n        if (l <=\
    \ lo && hi <= r) {\n            all_apply(v, f);\n            return;\n      \
    \  }\n        push(v, k);\n        long long mid = lo + (1LL << (k - 1));\n  \
    \      apply(t[v].l, k - 1, lo, l, r, f);\n        apply(t[v].r, k - 1, mid, l,\
    \ r, f);\n        update(v);\n    }\n\n    // \u5B50\u3092\u4F5C\u3089\u305A\u306B\
    \u6E08\u3080\u3088\u3046\uFF0C\u4E0A\u304B\u3089\u4F5C\u7528\u3092\u6301\u3061\
    \u8D8A\u3057\u3066\u8A08\u7B97\u3059\u308B (g: \u307E\u3060\u4E0B\u308D\u3057\u3066\
    \u3044\u306A\u3044\u4F5C\u7528)\n    S prod(int v, int k, long long lo, long long\
    \ l, long long r, const F &g) {\n        long long hi = lo + (1LL << k);\n   \
    \     if (r <= lo || hi <= l) return AM::e();\n        if (l <= lo && hi <= r)\
    \ return AM::mapping(g, t[v].val);\n        long long mid = lo + (1LL << (k -\
    \ 1));\n        if (t[v].l == -1) {\n            // \u307E\u3060\u5B50\u304C\u306A\
    \u3044 = \u533A\u9593\u5168\u4F53\u306B x0 \u304C\u4E26\u3093\u3067\u3044\u3066\
    \uFF0C\u4F5C\u7528 lz \u304C\u304B\u304B\u3063\u3066\u3044\u308B\n           \
    \ long long a = std::max(l, lo), b = std::min(r, hi);\n            S s = AM::e();\n\
    \            for (int j = k - 1; j >= 0; j--) if ((b - a) >> j & 1) s = AM::op(s,\
    \ pw[j]);\n            return AM::mapping(AM::composition(g, t[v].lz), s);\n \
    \       }\n        F h = AM::composition(g, t[v].lz);\n        return AM::op(prod(t[v].l,\
    \ k - 1, lo, l, r, h), prod(t[v].r, k - 1, mid, l, r, h));\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"../algebra/acted_monoid.hpp\"\
    \n\n// https://github.com/winter-2521/cp-library\n\n// \u52D5\u7684\u9045\u5EF6\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u6DFB\u5B57\u304C\u5927\u304D\u3044\u5834\
    \u5408\u306E\u533A\u9593\u4F5C\u7528\u30FB\u533A\u9593\u7A4D)\n// \u6DFB\u5B57\
    \u306F [0, n) (n \u306F 2^62 \u7A0B\u5EA6\u307E\u3067)\uFF0E\u306F\u3058\u3081\
    \u5168\u3066\u306E\u8981\u7D20\u304C x0 (\u7701\u7565\u6642 e())\n// \u89E6\u3063\
    \u305F\u90E8\u5206\u3060\u3051\u30CE\u30FC\u30C9\u3092\u4F5C\u308B\uFF0E1 \u56DE\
    \u306E\u64CD\u4F5C\u3067\u4F5C\u308B\u30CE\u30FC\u30C9\u306F O(log n) \u500B\n\
    //\n// \u5927\u304D\u3055\u3092 2 \u51AA\u306B\u5207\u308A\u4E0A\u3052\uFF0C\u307E\
    \u3060\u4F5C\u3063\u3066\u3044\u306A\u3044\u9577\u3055 2^k \u306E\u533A\u9593\u306E\
    \u7A4D\u306F x0^(2^k) \u3092\u4E8B\u524D\u8A08\u7B97\u3057\u3066\u304A\u3044\u3066\
    \u4F7F\u3046\ntemplate <class AM>\nstruct DynamicLazySegmentTree {\n    using\
    \ S = typename AM::S;\n    using F = typename AM::F;\n    struct Node {\n    \
    \    S val;\n        F lz;\n        int l, r;\n    };\n    long long n;\n    int\
    \ lg;\n    vector<S> pw;  // pw[k] = x0^(2^k)\n    vector<Node> t;\n    int root;\n\
    \n    DynamicLazySegmentTree(long long n = 0, S x0 = AM::e()) : n(n) {\n     \
    \   lg = 0;\n        while ((1LL << lg) < n) lg++;\n        pw.resize(lg + 1);\n\
    \        pw[0] = x0;\n        for (int k = 1; k <= lg; k++) pw[k] = AM::op(pw[k\
    \ - 1], pw[k - 1]);\n        root = new_node(lg);\n    }\n\n    void reserve(int\
    \ k) { t.reserve(k); }\n\n    // a[p] = x\n    void set(long long p, const S &x)\
    \ { set(root, lg, 0, p, x); }\n\n    S get(long long p) { return prod(p, p + 1);\
    \ }\n\n    // op(a[l], ..., a[r-1])\uFF0El == r \u306A\u3089 e()\n    S prod(long\
    \ long l, long long r) {\n        if (l >= r) return AM::e();\n        return\
    \ prod(root, lg, 0, l, r, AM::id());\n    }\n\n    S all_prod() const { return\
    \ t[root].val; }\n\n    // i in [l, r) \u306B\u3064\u3044\u3066 a[i] = f(a[i])\n\
    \    void apply(long long l, long long r, const F &f) {\n        if (l >= r) return;\n\
    \        apply(root, lg, 0, l, r, f);\n    }\n\n  private:\n    int new_node(int\
    \ k) {\n        t.push_back({pw[k], AM::id(), -1, -1});\n        return int(t.size())\
    \ - 1;\n    }\n    // \u5B50\u3092 (\u306A\u3051\u308C\u3070\u4F5C\u3063\u3066\
    ) \u4F5C\u7528\u3092\u4E0B\u308D\u3059\n    void push(int v, int k) {\n      \
    \  if (t[v].l == -1) {\n            int a = new_node(k - 1);\n            int\
    \ b = new_node(k - 1);\n            t[v].l = a, t[v].r = b;\n        }\n     \
    \   const F f = t[v].lz;\n        all_apply(t[v].l, f);\n        all_apply(t[v].r,\
    \ f);\n        t[v].lz = AM::id();\n    }\n    void all_apply(int v, const F &f)\
    \ {\n        t[v].val = AM::mapping(f, t[v].val);\n        t[v].lz = AM::composition(f,\
    \ t[v].lz);\n    }\n    void update(int v) { t[v].val = AM::op(t[t[v].l].val,\
    \ t[t[v].r].val); }\n\n    // \u30CE\u30FC\u30C9 v \u306F\u533A\u9593 [lo, lo\
    \ + 2^k)\n    void set(int v, int k, long long lo, long long p, const S &x) {\n\
    \        if (k == 0) {\n            t[v].val = x;\n            return;\n     \
    \   }\n        push(v, k);\n        long long mid = lo + (1LL << (k - 1));\n \
    \       if (p < mid) set(t[v].l, k - 1, lo, p, x);\n        else set(t[v].r, k\
    \ - 1, mid, p, x);\n        update(v);\n    }\n\n    void apply(int v, int k,\
    \ long long lo, long long l, long long r, const F &f) {\n        long long hi\
    \ = lo + (1LL << k);\n        if (r <= lo || hi <= l) return;\n        if (l <=\
    \ lo && hi <= r) {\n            all_apply(v, f);\n            return;\n      \
    \  }\n        push(v, k);\n        long long mid = lo + (1LL << (k - 1));\n  \
    \      apply(t[v].l, k - 1, lo, l, r, f);\n        apply(t[v].r, k - 1, mid, l,\
    \ r, f);\n        update(v);\n    }\n\n    // \u5B50\u3092\u4F5C\u3089\u305A\u306B\
    \u6E08\u3080\u3088\u3046\uFF0C\u4E0A\u304B\u3089\u4F5C\u7528\u3092\u6301\u3061\
    \u8D8A\u3057\u3066\u8A08\u7B97\u3059\u308B (g: \u307E\u3060\u4E0B\u308D\u3057\u3066\
    \u3044\u306A\u3044\u4F5C\u7528)\n    S prod(int v, int k, long long lo, long long\
    \ l, long long r, const F &g) {\n        long long hi = lo + (1LL << k);\n   \
    \     if (r <= lo || hi <= l) return AM::e();\n        if (l <= lo && hi <= r)\
    \ return AM::mapping(g, t[v].val);\n        long long mid = lo + (1LL << (k -\
    \ 1));\n        if (t[v].l == -1) {\n            // \u307E\u3060\u5B50\u304C\u306A\
    \u3044 = \u533A\u9593\u5168\u4F53\u306B x0 \u304C\u4E26\u3093\u3067\u3044\u3066\
    \uFF0C\u4F5C\u7528 lz \u304C\u304B\u304B\u3063\u3066\u3044\u308B\n           \
    \ long long a = std::max(l, lo), b = std::min(r, hi);\n            S s = AM::e();\n\
    \            for (int j = k - 1; j >= 0; j--) if ((b - a) >> j & 1) s = AM::op(s,\
    \ pw[j]);\n            return AM::mapping(AM::composition(g, t[v].lz), s);\n \
    \       }\n        F h = AM::composition(g, t[v].lz);\n        return AM::op(prod(t[v].l,\
    \ k - 1, lo, l, r, h), prod(t[v].r, k - 1, mid, l, r, h));\n    }\n};\n"
  dependsOn:
  - template.hpp
  - algebra/acted_monoid.hpp
  - algebra/monoid.hpp
  - template.hpp
  isVerificationFile: false
  path: data_structure/dynamic_lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unittest/lazy_segment_tree.test.cpp
  - test/range_affine_range_sum_large_array.test.cpp
documentation_of: data_structure/dynamic_lazy_segment_tree.hpp
layout: document
title: "\u52D5\u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dynamic Lazy\
  \ Segment Tree)"
---

## 概要

添字の範囲が大きい（$n \le 10^{18}$ 程度）場合の区間作用・区間積。**オンライン** で動く。はじめ全ての要素が `x0`。
触った部分だけノードを作り、1 回の操作で作るノードは $O(\log n)$ 個。

大きさを 2 冪 $2^K$ に切り上げ、まだノードを作っていない長さ $2^k$ の区間の積として $x_0^{2^k}$ を事前に計算して使う。区間積はノードを作らない（上から作用を持ち越して計算する）。

## 使い方

```cpp
using AM = ActedAffineSum<mint>;
DynamicLazySegmentTree<AM> seg(1000000000, AM::make(0));   // 全て 0
seg.apply(l, r, {b, c});
seg.prod(l, r).sum;
seg.set(p, AM::make(x)); seg.get(p); seg.all_prod();
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `DynamicLazySegmentTree<AM>(long long n, S x0 = e())` | 長さ `n`、全て `x0` | $O(\log n)$ |
| `void apply(long long l, long long r, F f)` | $i \in [l, r)$ について $a_i = f(a_i)$ | $O(\log n)$ |
| `S prod(long long l, long long r)` | 区間積 | $O(\log n)$ |
| `void set(long long p, S x)` / `S get(long long p)` | 一点代入・取得 | $O(\log n)$ |
| `S all_prod()` | 全体の積 | $O(1)$ |

## 注意

- メモリは 1 回の操作あたり最大 $4 \log_2 n$ ノード程度（$n = 10^9$、$q = 10^5$ で手元 100 MB）。
- `x0` は「和を持つ」型なら `make(x)`（長さ 1）で渡すこと。
