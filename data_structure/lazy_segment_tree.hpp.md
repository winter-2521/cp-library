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
    path: test/range_affine_range_sum.test.cpp
    title: test/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/lazy_segment_tree.test.cpp
    title: test/unittest/lazy_segment_tree.test.cpp
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
    \ 4 \"data_structure/lazy_segment_tree.hpp\"\n\n// \u9045\u5EF6\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728 (\u533A\u9593\u4F5C\u7528\u30FB\u533A\u9593\u7A4D)\n// AM \u306F\
    \u4F5C\u7528\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (algebra/acted_monoid.hpp \u53C2\
    \u7167\uFF0E\u898F\u7D04\u306F ACL \u306E lazy_segtree \u3068\u540C\u3058)\ntemplate\
    \ <class AM>\nstruct LazySegmentTree {\n    using S = typename AM::S;\n    using\
    \ F = typename AM::F;\n    int n, sz, lg;\n    vector<S> d;\n    vector<F> lz;\n\
    \n    LazySegmentTree(int n = 0) : LazySegmentTree(vector<S>(n, AM::e())) {}\n\
    \n    LazySegmentTree(const vector<S> &a) : n(a.size()) {\n        lg = 0;\n \
    \       while ((1 << lg) < n) lg++;\n        sz = 1 << lg;\n        d.assign(2\
    \ * sz, AM::e());\n        lz.assign(sz, AM::id());\n        copy(a.begin(), a.end(),\
    \ d.begin() + sz);\n        for (int i = sz - 1; i >= 1; i--) update(i);\n   \
    \ }\n\n    int size() const { return n; }\n\n    // a[p] = x\n    void set(int\
    \ p, const S &x) {\n        p += sz;\n        for (int i = lg; i >= 1; i--) push(p\
    \ >> i);\n        d[p] = x;\n        for (int i = 1; i <= lg; i++) update(p >>\
    \ i);\n    }\n\n    S get(int p) {\n        p += sz;\n        for (int i = lg;\
    \ i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    // op(a[l], ...,\
    \ a[r-1])\uFF0El == r \u306A\u3089 e()\n    S prod(int l, int r) {\n        if\
    \ (l == r) return AM::e();\n        l += sz, r += sz;\n        for (int i = lg;\
    \ i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n      \
    \      if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n        S sml\
    \ = AM::e(), smr = AM::e();\n        while (l < r) {\n            if (l & 1) sml\
    \ = AM::op(sml, d[l++]);\n            if (r & 1) smr = AM::op(d[--r], smr);\n\
    \            l >>= 1, r >>= 1;\n        }\n        return AM::op(sml, smr);\n\
    \    }\n\n    S all_prod() const { return d[1]; }\n\n    // a[p] = f(a[p])\n \
    \   void apply(int p, const F &f) {\n        p += sz;\n        for (int i = lg;\
    \ i >= 1; i--) push(p >> i);\n        d[p] = AM::mapping(f, d[p]);\n        for\
    \ (int i = 1; i <= lg; i++) update(p >> i);\n    }\n\n    // i in [l, r) \u306B\
    \u3064\u3044\u3066 a[i] = f(a[i])\n    void apply(int l, int r, const F &f) {\n\
    \        if (l == r) return;\n        l += sz, r += sz;\n        for (int i =\
    \ lg; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n  \
    \          if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n        {\n\
    \            int l2 = l, r2 = r;\n            while (l < r) {\n              \
    \  if (l & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r, f);\n\
    \                l >>= 1, r >>= 1;\n            }\n            l = l2, r = r2;\n\
    \        }\n        for (int i = 1; i <= lg; i++) {\n            if (((l >> i)\
    \ << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n\n    // g(op(a[l], ..., a[r-1])) \u304C true\
    \ \u3068\u306A\u308B\u6700\u5927\u306E r (g(e()) \u306F true \u3067\u3042\u308B\
    \u3053\u3068)\n    template <class G>\n    int max_right(int l, G g) {\n     \
    \   if (l == n) return n;\n        l += sz;\n        for (int i = lg; i >= 1;\
    \ i--) push(l >> i);\n        S sm = AM::e();\n        do {\n            while\
    \ (l % 2 == 0) l >>= 1;\n            if (!g(AM::op(sm, d[l]))) {\n           \
    \     while (l < sz) {\n                    push(l);\n                    l =\
    \ 2 * l;\n                    if (g(AM::op(sm, d[l]))) sm = AM::op(sm, d[l++]);\n\
    \                }\n                return l - sz;\n            }\n          \
    \  sm = AM::op(sm, d[l++]);\n        } while ((l & -l) != l);\n        return\
    \ n;\n    }\n\n    // g(op(a[l], ..., a[r-1])) \u304C true \u3068\u306A\u308B\u6700\
    \u5C0F\u306E l (g(e()) \u306F true \u3067\u3042\u308B\u3053\u3068)\n    template\
    \ <class G>\n    int min_left(int r, G g) {\n        if (r == 0) return 0;\n \
    \       r += sz;\n        for (int i = lg; i >= 1; i--) push((r - 1) >> i);\n\
    \        S sm = AM::e();\n        do {\n            r--;\n            while (r\
    \ > 1 && (r % 2)) r >>= 1;\n            if (!g(AM::op(d[r], sm))) {\n        \
    \        while (r < sz) {\n                    push(r);\n                    r\
    \ = 2 * r + 1;\n                    if (g(AM::op(d[r], sm))) sm = AM::op(d[r--],\
    \ sm);\n                }\n                return r + 1 - sz;\n            }\n\
    \            sm = AM::op(d[r], sm);\n        } while ((r & -r) != r);\n      \
    \  return 0;\n    }\n\n  private:\n    void update(int k) { d[k] = AM::op(d[2\
    \ * k], d[2 * k + 1]); }\n    void all_apply(int k, const F &f) {\n        d[k]\
    \ = AM::mapping(f, d[k]);\n        if (k < sz) lz[k] = AM::composition(f, lz[k]);\n\
    \    }\n    void push(int k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2\
    \ * k + 1, lz[k]);\n        lz[k] = AM::id();\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"../algebra/acted_monoid.hpp\"\
    \n\n// \u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u4F5C\u7528\
    \u30FB\u533A\u9593\u7A4D)\n// AM \u306F\u4F5C\u7528\u4ED8\u304D\u30E2\u30CE\u30A4\
    \u30C9 (algebra/acted_monoid.hpp \u53C2\u7167\uFF0E\u898F\u7D04\u306F ACL \u306E\
    \ lazy_segtree \u3068\u540C\u3058)\ntemplate <class AM>\nstruct LazySegmentTree\
    \ {\n    using S = typename AM::S;\n    using F = typename AM::F;\n    int n,\
    \ sz, lg;\n    vector<S> d;\n    vector<F> lz;\n\n    LazySegmentTree(int n =\
    \ 0) : LazySegmentTree(vector<S>(n, AM::e())) {}\n\n    LazySegmentTree(const\
    \ vector<S> &a) : n(a.size()) {\n        lg = 0;\n        while ((1 << lg) < n)\
    \ lg++;\n        sz = 1 << lg;\n        d.assign(2 * sz, AM::e());\n        lz.assign(sz,\
    \ AM::id());\n        copy(a.begin(), a.end(), d.begin() + sz);\n        for (int\
    \ i = sz - 1; i >= 1; i--) update(i);\n    }\n\n    int size() const { return\
    \ n; }\n\n    // a[p] = x\n    void set(int p, const S &x) {\n        p += sz;\n\
    \        for (int i = lg; i >= 1; i--) push(p >> i);\n        d[p] = x;\n    \
    \    for (int i = 1; i <= lg; i++) update(p >> i);\n    }\n\n    S get(int p)\
    \ {\n        p += sz;\n        for (int i = lg; i >= 1; i--) push(p >> i);\n \
    \       return d[p];\n    }\n\n    // op(a[l], ..., a[r-1])\uFF0El == r \u306A\
    \u3089 e()\n    S prod(int l, int r) {\n        if (l == r) return AM::e();\n\
    \        l += sz, r += sz;\n        for (int i = lg; i >= 1; i--) {\n        \
    \    if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i)\
    \ != r) push((r - 1) >> i);\n        }\n        S sml = AM::e(), smr = AM::e();\n\
    \        while (l < r) {\n            if (l & 1) sml = AM::op(sml, d[l++]);\n\
    \            if (r & 1) smr = AM::op(d[--r], smr);\n            l >>= 1, r >>=\
    \ 1;\n        }\n        return AM::op(sml, smr);\n    }\n\n    S all_prod() const\
    \ { return d[1]; }\n\n    // a[p] = f(a[p])\n    void apply(int p, const F &f)\
    \ {\n        p += sz;\n        for (int i = lg; i >= 1; i--) push(p >> i);\n \
    \       d[p] = AM::mapping(f, d[p]);\n        for (int i = 1; i <= lg; i++) update(p\
    \ >> i);\n    }\n\n    // i in [l, r) \u306B\u3064\u3044\u3066 a[i] = f(a[i])\n\
    \    void apply(int l, int r, const F &f) {\n        if (l == r) return;\n   \
    \     l += sz, r += sz;\n        for (int i = lg; i >= 1; i--) {\n           \
    \ if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) !=\
    \ r) push((r - 1) >> i);\n        }\n        {\n            int l2 = l, r2 = r;\n\
    \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
    \                if (r & 1) all_apply(--r, f);\n                l >>= 1, r >>=\
    \ 1;\n            }\n            l = l2, r = r2;\n        }\n        for (int\
    \ i = 1; i <= lg; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n\
    \            if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\
    \n    // g(op(a[l], ..., a[r-1])) \u304C true \u3068\u306A\u308B\u6700\u5927\u306E\
    \ r (g(e()) \u306F true \u3067\u3042\u308B\u3053\u3068)\n    template <class G>\n\
    \    int max_right(int l, G g) {\n        if (l == n) return n;\n        l +=\
    \ sz;\n        for (int i = lg; i >= 1; i--) push(l >> i);\n        S sm = AM::e();\n\
    \        do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(AM::op(sm,\
    \ d[l]))) {\n                while (l < sz) {\n                    push(l);\n\
    \                    l = 2 * l;\n                    if (g(AM::op(sm, d[l])))\
    \ sm = AM::op(sm, d[l++]);\n                }\n                return l - sz;\n\
    \            }\n            sm = AM::op(sm, d[l++]);\n        } while ((l & -l)\
    \ != l);\n        return n;\n    }\n\n    // g(op(a[l], ..., a[r-1])) \u304C true\
    \ \u3068\u306A\u308B\u6700\u5C0F\u306E l (g(e()) \u306F true \u3067\u3042\u308B\
    \u3053\u3068)\n    template <class G>\n    int min_left(int r, G g) {\n      \
    \  if (r == 0) return 0;\n        r += sz;\n        for (int i = lg; i >= 1; i--)\
    \ push((r - 1) >> i);\n        S sm = AM::e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(AM::op(d[r],\
    \ sm))) {\n                while (r < sz) {\n                    push(r);\n  \
    \                  r = 2 * r + 1;\n                    if (g(AM::op(d[r], sm)))\
    \ sm = AM::op(d[r--], sm);\n                }\n                return r + 1 -\
    \ sz;\n            }\n            sm = AM::op(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n  private:\n    void update(int k)\
    \ { d[k] = AM::op(d[2 * k], d[2 * k + 1]); }\n    void all_apply(int k, const\
    \ F &f) {\n        d[k] = AM::mapping(f, d[k]);\n        if (k < sz) lz[k] = AM::composition(f,\
    \ lz[k]);\n    }\n    void push(int k) {\n        all_apply(2 * k, lz[k]);\n \
    \       all_apply(2 * k + 1, lz[k]);\n        lz[k] = AM::id();\n    }\n};\n"
  dependsOn:
  - template.hpp
  - algebra/acted_monoid.hpp
  - algebra/monoid.hpp
  - template.hpp
  isVerificationFile: false
  path: data_structure/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2026-10-14 23:17:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/lazy_segment_tree.test.cpp
  - test/range_affine_range_sum.test.cpp
documentation_of: data_structure/lazy_segment_tree.hpp
layout: document
title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Lazy Segment Tree)"
---

## 概要

作用付きモノイド `AM` に対して、区間作用と区間積を $O(\log n)$ で処理する。非再帰の実装で、操作と規約は ACL の `lazy_segtree` と同じ。
よく使う作用付きモノイドは [acted_monoid.hpp](../../algebra/acted_monoid.hpp) にある。

## 使い方

```cpp
using AM = ActedAffineSum<mint>;    // 区間 1 次関数・区間和
vector<AM::S> a(n);
for (int i = 0; i < n; i++) a[i] = AM::make(x[i]);
LazySegmentTree<AM> seg(a);
seg.apply(l, r, {b, c});   // [l, r) の各要素を b x + c に
seg.prod(l, r).sum;        // [l, r) の和
seg.apply(p, f); seg.set(p, x); seg.get(p); seg.all_prod();
seg.max_right(l, g); seg.min_left(r, g);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `LazySegmentTree<AM>(int n)` / `(const vector<S> &a)` | 構築 | $O(n)$ |
| `void apply(int l, int r, F f)` | $i \in [l, r)$ について $a_i = f(a_i)$ | $O(\log n)$ |
| `void apply(int p, F f)` | $a_p = f(a_p)$ | $O(\log n)$ |
| `S prod(int l, int r)` | $a_l \cdots a_{r-1}$ | $O(\log n)$ |
| `S all_prod()` | 全体の積 | $O(1)$ |
| `void set(int p, S x)` / `S get(int p)` | 一点代入・取得 | $O(\log n)$ |
| `int max_right(int l, G g)` / `int min_left(int r, G g)` | 二分探索 | $O(\log n)$ |

## 注意

- `prod` / `get` も内部で作用を下ろすので `const` ではない。
- `max_right` / `min_left` の条件は単調で、`g(e())` が真であること。
