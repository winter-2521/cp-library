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
  - icon: ':heavy_check_mark:'
    path: test/dynamic_sequence_range_affine_range_sum.test.cpp
    title: test/dynamic_sequence_range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: test/range_reverse_range_sum.test.cpp
    title: test/range_reverse_range_sum.test.cpp
  - icon: ':x:'
    path: test/unittest/dynamic_sequence.test.cpp
    title: test/unittest/dynamic_sequence.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ 4 \"data_structure/dynamic_sequence.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u5217\u306E\u633F\u5165\u30FB\u524A\u9664\u30FB\u533A\u9593\u53CD\u8EE2\u30FB\
    \u533A\u9593\u4F5C\u7528\u30FB\u533A\u9593\u7A4D (Splay \u6728)\n// AM \u306F\u4F5C\
    \u7528\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (algebra/acted_monoid.hpp \u53C2\u7167\
    )\n// COMMUTATIVE = false \u306A\u3089\u975E\u53EF\u63DB\u306A\u30E2\u30CE\u30A4\
    \u30C9\u3067\u3082\u53CD\u8EE2\u3067\u304D\u308B (\u9006\u9806\u306E\u7A4D\u3082\
    \u6301\u3064\uFF0E\u5C11\u3057\u9045\u3044)\n// \u4E21\u7AEF\u306B\u756A\u5175\
    \u3092\u7F6E\u304D\uFF0C\u533A\u9593 [l, r) \u306F\u300Cl-1 \u756A\u76EE\u3092\
    \u6839\u306B\uFF0Cr \u756A\u76EE\u3092\u6839\u306E\u53F3\u306E\u5B50\u306B splay\
    \ \u3057\u305F\u5F8C\u306E\uFF0C\u305D\u306E\u5DE6\u306E\u5B50\u300D\u3068\u3057\
    \u3066\u53D6\u308A\u51FA\u3059\ntemplate <class AM, bool COMMUTATIVE = true>\n\
    struct DynamicSequence {\n    using S = typename AM::S;\n    using F = typename\
    \ AM::F;\n    // \u9006\u9806\u306E\u7A4D rsum \u306F COMMUTATIVE = false \u306E\
    \u3068\u304D\u3060\u3051\u6301\u3064\n    struct NoRSum {};\n    struct WithRSum\
    \ {\n        S rsum;\n    };\n    struct Node : conditional_t<COMMUTATIVE, NoRSum,\
    \ WithRSum> {\n        int ch[2], p, sz;\n        S val, sum;\n        F lz;\n\
    \        bool has_lz, rev;\n    };\n    vector<Node> d;  // d[0] \u306F\u7A7A\u30CE\
    \u30FC\u30C9\n    int root;\n\n    DynamicSequence(const vector<S> &a = {}) {\n\
    \        int n = a.size();\n        d.reserve(n + 3);\n        d.push_back(make_node(AM::e()));\n\
    \        d[0].sz = 0;\n        vector<int> ids(n + 2);\n        ids[0] = new_node(AM::e());\n\
    \        for (int i = 0; i < n; i++) ids[i + 1] = new_node(a[i]);\n        ids[n\
    \ + 1] = new_node(AM::e());\n        root = build(ids, 0, n + 2, 0);\n    }\n\n\
    \    void reserve(int n) { d.reserve(n + 3); }\n    int size() const { return\
    \ d[root].sz - 2; }\n\n    // i \u756A\u76EE\u306E\u76F4\u524D\u306B x \u3092\u633F\
    \u5165 (i = size() \u306A\u3089\u672B\u5C3E)\n    void insert(int i, const S &x)\
    \ {\n        int t = new_node(x);\n        int r = range(i, i);\n        d[r].ch[0]\
    \ = t, d[t].p = r;\n        update(r), update(root);\n    }\n    void push_back(const\
    \ S &x) { insert(size(), x); }\n    void push_front(const S &x) { insert(0, x);\
    \ }\n\n    // i \u756A\u76EE\u3092\u524A\u9664\n    void erase(int i) {\n    \
    \    int r = range(i, i + 1);\n        d[r].ch[0] = 0;\n        update(r), update(root);\n\
    \    }\n\n    S get(int i) {\n        int t = kth(i + 1);\n        splay(t, 0);\n\
    \        return d[t].val;\n    }\n\n    void set(int i, const S &x) {\n      \
    \  int t = kth(i + 1);\n        splay(t, 0);\n        d[t].val = x;\n        update(t);\n\
    \    }\n\n    // op(a[l], ..., a[r-1])\uFF0El == r \u306A\u3089 e()\n    S prod(int\
    \ l, int r) {\n        if (l == r) return AM::e();\n        return d[d[range(l,\
    \ r)].ch[0]].sum;\n    }\n    S all_prod() { return prod(0, size()); }\n\n   \
    \ // i in [l, r) \u306B\u3064\u3044\u3066 a[i] = f(a[i])\n    void apply(int l,\
    \ int r, const F &f) {\n        if (l == r) return;\n        int rr = range(l,\
    \ r);\n        all_apply(d[rr].ch[0], f);\n        update(rr), update(root);\n\
    \    }\n\n    // a[l], ..., a[r-1] \u3092\u53CD\u8EE2\n    void reverse(int l,\
    \ int r) {\n        if (r - l <= 1) return;\n        int rr = range(l, r);\n \
    \       toggle(d[rr].ch[0]);\n        update(rr), update(root);\n    }\n\n   \
    \ // \u5217\u5168\u4F53 (\u30C7\u30D0\u30C3\u30B0\u7528)\uFF0EO(n)\n    vector<S>\
    \ to_vector() {\n        vector<S> res;\n        res.reserve(size());\n      \
    \  dfs(root, res);\n        return vector<S>(res.begin() + 1, res.end() - 1);\n\
    \    }\n\n  private:\n    Node make_node(const S &x) {\n        Node t;\n    \
    \    t.ch[0] = t.ch[1] = t.p = 0, t.sz = 1;\n        t.val = t.sum = x;\n    \
    \    if constexpr (!COMMUTATIVE) t.rsum = x;\n        t.lz = AM::id(), t.has_lz\
    \ = t.rev = false;\n        return t;\n    }\n    int new_node(const S &x) {\n\
    \        d.push_back(make_node(x));\n        return d.size() - 1;\n    }\n\n \
    \   int build(const vector<int> &ids, int l, int r, int p) {\n        if (l ==\
    \ r) return 0;\n        int m = (l + r) >> 1, t = ids[m];\n        d[t].p = p;\n\
    \        d[t].ch[0] = build(ids, l, m, t);\n        d[t].ch[1] = build(ids, m\
    \ + 1, r, t);\n        update(t);\n        return t;\n    }\n\n    void update(int\
    \ t) {\n        Node &x = d[t];\n        const Node &a = d[x.ch[0]], &b = d[x.ch[1]];\n\
    \        x.sz = a.sz + b.sz + 1;\n        x.sum = AM::op(AM::op(a.sum, x.val),\
    \ b.sum);\n        if constexpr (!COMMUTATIVE) x.rsum = AM::op(AM::op(b.rsum,\
    \ x.val), a.rsum);\n    }\n\n    void all_apply(int t, const F &f) {\n       \
    \ Node &x = d[t];\n        x.val = AM::mapping(f, x.val);\n        x.sum = AM::mapping(f,\
    \ x.sum);\n        if constexpr (!COMMUTATIVE) x.rsum = AM::mapping(f, x.rsum);\n\
    \        x.lz = x.has_lz ? AM::composition(f, x.lz) : f;\n        x.has_lz = true;\n\
    \    }\n\n    void toggle(int t) {\n        Node &x = d[t];\n        swap(x.ch[0],\
    \ x.ch[1]);\n        if constexpr (!COMMUTATIVE) swap(x.sum, x.rsum);\n      \
    \  x.rev ^= 1;\n    }\n\n    void push(int t) {\n        Node &x = d[t];\n   \
    \     if (x.rev) {\n            if (x.ch[0]) toggle(x.ch[0]);\n            if\
    \ (x.ch[1]) toggle(x.ch[1]);\n            x.rev = false;\n        }\n        if\
    \ (x.has_lz) {\n            if (x.ch[0]) all_apply(x.ch[0], x.lz);\n         \
    \   if (x.ch[1]) all_apply(x.ch[1], x.lz);\n            x.has_lz = false;\n  \
    \      }\n    }\n\n    // x \u3092\u89AA\u306E\u4F4D\u7F6E\u306B\u56DE\u8EE2 (\u89AA\
    \u306E update \u3060\u3051\u3059\u308B)\n    void rotate(int x) {\n        int\
    \ y = d[x].p, z = d[y].p;\n        int c = d[y].ch[1] == x;\n        int b = d[x].ch[c\
    \ ^ 1];\n        d[y].ch[c] = b;\n        if (b) d[b].p = y;\n        d[x].ch[c\
    \ ^ 1] = y, d[y].p = x;\n        d[x].p = z;\n        if (z) d[z].ch[d[z].ch[1]\
    \ == y] = x;\n        update(y);\n    }\n\n    // x \u3092 goal \u306E\u5B50\u306B\
    \u306A\u308B\u307E\u3067 splay (goal = 0 \u306A\u3089\u6839)\uFF0Ex \u306E\u7956\
    \u5148\u306F push \u6E08\u307F\u3067\u3042\u308B\u3053\u3068\n    void splay(int\
    \ x, int goal) {\n        while (d[x].p != goal) {\n            int y = d[x].p,\
    \ z = d[y].p;\n            if (z != goal) rotate((d[y].ch[1] == x) == (d[z].ch[1]\
    \ == y) ? y : x);\n            rotate(x);\n        }\n        update(x);\n   \
    \     if (!goal) root = x;\n    }\n\n    // \u756A\u5175\u8FBC\u307F\u3067 k \u756A\
    \u76EE\u306E\u30CE\u30FC\u30C9 (\u7D4C\u8DEF\u3092 push \u3059\u308B)\n    int\
    \ kth(int k) {\n        int t = root;\n        while (true) {\n            push(t);\n\
    \            int ls = d[d[t].ch[0]].sz;\n            if (k < ls) t = d[t].ch[0];\n\
    \            else if (k == ls) return t;\n            else k -= ls + 1, t = d[t].ch[1];\n\
    \        }\n    }\n\n    // [l, r) \u304C\u300C\u6839\u306E\u53F3\u306E\u5B50\u306E\
    \u5DE6\u306E\u5B50\u300D\u306E\u90E8\u5206\u6728\u306B\u306A\u308B\u3088\u3046\
    \u306B\u3057\u3066\uFF0C\u6839\u306E\u53F3\u306E\u5B50\u3092\u8FD4\u3059\n   \
    \ int range(int l, int r) {\n        int a = kth(l);\n        splay(a, 0);\n \
    \       int b = kth(r + 1);\n        splay(b, a);\n        return b;\n    }\n\n\
    \    void dfs(int t, vector<S> &res) {\n        if (!t) return;\n        push(t);\n\
    \        dfs(d[t].ch[0], res);\n        res.push_back(d[t].val);\n        dfs(d[t].ch[1],\
    \ res);\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"../algebra/acted_monoid.hpp\"\
    \n\n// https://github.com/winter-2521/cp-library\n\n// \u5217\u306E\u633F\u5165\
    \u30FB\u524A\u9664\u30FB\u533A\u9593\u53CD\u8EE2\u30FB\u533A\u9593\u4F5C\u7528\
    \u30FB\u533A\u9593\u7A4D (Splay \u6728)\n// AM \u306F\u4F5C\u7528\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9 (algebra/acted_monoid.hpp \u53C2\u7167)\n// COMMUTATIVE = false\
    \ \u306A\u3089\u975E\u53EF\u63DB\u306A\u30E2\u30CE\u30A4\u30C9\u3067\u3082\u53CD\
    \u8EE2\u3067\u304D\u308B (\u9006\u9806\u306E\u7A4D\u3082\u6301\u3064\uFF0E\u5C11\
    \u3057\u9045\u3044)\n// \u4E21\u7AEF\u306B\u756A\u5175\u3092\u7F6E\u304D\uFF0C\
    \u533A\u9593 [l, r) \u306F\u300Cl-1 \u756A\u76EE\u3092\u6839\u306B\uFF0Cr \u756A\
    \u76EE\u3092\u6839\u306E\u53F3\u306E\u5B50\u306B splay \u3057\u305F\u5F8C\u306E\
    \uFF0C\u305D\u306E\u5DE6\u306E\u5B50\u300D\u3068\u3057\u3066\u53D6\u308A\u51FA\
    \u3059\ntemplate <class AM, bool COMMUTATIVE = true>\nstruct DynamicSequence {\n\
    \    using S = typename AM::S;\n    using F = typename AM::F;\n    // \u9006\u9806\
    \u306E\u7A4D rsum \u306F COMMUTATIVE = false \u306E\u3068\u304D\u3060\u3051\u6301\
    \u3064\n    struct NoRSum {};\n    struct WithRSum {\n        S rsum;\n    };\n\
    \    struct Node : conditional_t<COMMUTATIVE, NoRSum, WithRSum> {\n        int\
    \ ch[2], p, sz;\n        S val, sum;\n        F lz;\n        bool has_lz, rev;\n\
    \    };\n    vector<Node> d;  // d[0] \u306F\u7A7A\u30CE\u30FC\u30C9\n    int\
    \ root;\n\n    DynamicSequence(const vector<S> &a = {}) {\n        int n = a.size();\n\
    \        d.reserve(n + 3);\n        d.push_back(make_node(AM::e()));\n       \
    \ d[0].sz = 0;\n        vector<int> ids(n + 2);\n        ids[0] = new_node(AM::e());\n\
    \        for (int i = 0; i < n; i++) ids[i + 1] = new_node(a[i]);\n        ids[n\
    \ + 1] = new_node(AM::e());\n        root = build(ids, 0, n + 2, 0);\n    }\n\n\
    \    void reserve(int n) { d.reserve(n + 3); }\n    int size() const { return\
    \ d[root].sz - 2; }\n\n    // i \u756A\u76EE\u306E\u76F4\u524D\u306B x \u3092\u633F\
    \u5165 (i = size() \u306A\u3089\u672B\u5C3E)\n    void insert(int i, const S &x)\
    \ {\n        int t = new_node(x);\n        int r = range(i, i);\n        d[r].ch[0]\
    \ = t, d[t].p = r;\n        update(r), update(root);\n    }\n    void push_back(const\
    \ S &x) { insert(size(), x); }\n    void push_front(const S &x) { insert(0, x);\
    \ }\n\n    // i \u756A\u76EE\u3092\u524A\u9664\n    void erase(int i) {\n    \
    \    int r = range(i, i + 1);\n        d[r].ch[0] = 0;\n        update(r), update(root);\n\
    \    }\n\n    S get(int i) {\n        int t = kth(i + 1);\n        splay(t, 0);\n\
    \        return d[t].val;\n    }\n\n    void set(int i, const S &x) {\n      \
    \  int t = kth(i + 1);\n        splay(t, 0);\n        d[t].val = x;\n        update(t);\n\
    \    }\n\n    // op(a[l], ..., a[r-1])\uFF0El == r \u306A\u3089 e()\n    S prod(int\
    \ l, int r) {\n        if (l == r) return AM::e();\n        return d[d[range(l,\
    \ r)].ch[0]].sum;\n    }\n    S all_prod() { return prod(0, size()); }\n\n   \
    \ // i in [l, r) \u306B\u3064\u3044\u3066 a[i] = f(a[i])\n    void apply(int l,\
    \ int r, const F &f) {\n        if (l == r) return;\n        int rr = range(l,\
    \ r);\n        all_apply(d[rr].ch[0], f);\n        update(rr), update(root);\n\
    \    }\n\n    // a[l], ..., a[r-1] \u3092\u53CD\u8EE2\n    void reverse(int l,\
    \ int r) {\n        if (r - l <= 1) return;\n        int rr = range(l, r);\n \
    \       toggle(d[rr].ch[0]);\n        update(rr), update(root);\n    }\n\n   \
    \ // \u5217\u5168\u4F53 (\u30C7\u30D0\u30C3\u30B0\u7528)\uFF0EO(n)\n    vector<S>\
    \ to_vector() {\n        vector<S> res;\n        res.reserve(size());\n      \
    \  dfs(root, res);\n        return vector<S>(res.begin() + 1, res.end() - 1);\n\
    \    }\n\n  private:\n    Node make_node(const S &x) {\n        Node t;\n    \
    \    t.ch[0] = t.ch[1] = t.p = 0, t.sz = 1;\n        t.val = t.sum = x;\n    \
    \    if constexpr (!COMMUTATIVE) t.rsum = x;\n        t.lz = AM::id(), t.has_lz\
    \ = t.rev = false;\n        return t;\n    }\n    int new_node(const S &x) {\n\
    \        d.push_back(make_node(x));\n        return d.size() - 1;\n    }\n\n \
    \   int build(const vector<int> &ids, int l, int r, int p) {\n        if (l ==\
    \ r) return 0;\n        int m = (l + r) >> 1, t = ids[m];\n        d[t].p = p;\n\
    \        d[t].ch[0] = build(ids, l, m, t);\n        d[t].ch[1] = build(ids, m\
    \ + 1, r, t);\n        update(t);\n        return t;\n    }\n\n    void update(int\
    \ t) {\n        Node &x = d[t];\n        const Node &a = d[x.ch[0]], &b = d[x.ch[1]];\n\
    \        x.sz = a.sz + b.sz + 1;\n        x.sum = AM::op(AM::op(a.sum, x.val),\
    \ b.sum);\n        if constexpr (!COMMUTATIVE) x.rsum = AM::op(AM::op(b.rsum,\
    \ x.val), a.rsum);\n    }\n\n    void all_apply(int t, const F &f) {\n       \
    \ Node &x = d[t];\n        x.val = AM::mapping(f, x.val);\n        x.sum = AM::mapping(f,\
    \ x.sum);\n        if constexpr (!COMMUTATIVE) x.rsum = AM::mapping(f, x.rsum);\n\
    \        x.lz = x.has_lz ? AM::composition(f, x.lz) : f;\n        x.has_lz = true;\n\
    \    }\n\n    void toggle(int t) {\n        Node &x = d[t];\n        swap(x.ch[0],\
    \ x.ch[1]);\n        if constexpr (!COMMUTATIVE) swap(x.sum, x.rsum);\n      \
    \  x.rev ^= 1;\n    }\n\n    void push(int t) {\n        Node &x = d[t];\n   \
    \     if (x.rev) {\n            if (x.ch[0]) toggle(x.ch[0]);\n            if\
    \ (x.ch[1]) toggle(x.ch[1]);\n            x.rev = false;\n        }\n        if\
    \ (x.has_lz) {\n            if (x.ch[0]) all_apply(x.ch[0], x.lz);\n         \
    \   if (x.ch[1]) all_apply(x.ch[1], x.lz);\n            x.has_lz = false;\n  \
    \      }\n    }\n\n    // x \u3092\u89AA\u306E\u4F4D\u7F6E\u306B\u56DE\u8EE2 (\u89AA\
    \u306E update \u3060\u3051\u3059\u308B)\n    void rotate(int x) {\n        int\
    \ y = d[x].p, z = d[y].p;\n        int c = d[y].ch[1] == x;\n        int b = d[x].ch[c\
    \ ^ 1];\n        d[y].ch[c] = b;\n        if (b) d[b].p = y;\n        d[x].ch[c\
    \ ^ 1] = y, d[y].p = x;\n        d[x].p = z;\n        if (z) d[z].ch[d[z].ch[1]\
    \ == y] = x;\n        update(y);\n    }\n\n    // x \u3092 goal \u306E\u5B50\u306B\
    \u306A\u308B\u307E\u3067 splay (goal = 0 \u306A\u3089\u6839)\uFF0Ex \u306E\u7956\
    \u5148\u306F push \u6E08\u307F\u3067\u3042\u308B\u3053\u3068\n    void splay(int\
    \ x, int goal) {\n        while (d[x].p != goal) {\n            int y = d[x].p,\
    \ z = d[y].p;\n            if (z != goal) rotate((d[y].ch[1] == x) == (d[z].ch[1]\
    \ == y) ? y : x);\n            rotate(x);\n        }\n        update(x);\n   \
    \     if (!goal) root = x;\n    }\n\n    // \u756A\u5175\u8FBC\u307F\u3067 k \u756A\
    \u76EE\u306E\u30CE\u30FC\u30C9 (\u7D4C\u8DEF\u3092 push \u3059\u308B)\n    int\
    \ kth(int k) {\n        int t = root;\n        while (true) {\n            push(t);\n\
    \            int ls = d[d[t].ch[0]].sz;\n            if (k < ls) t = d[t].ch[0];\n\
    \            else if (k == ls) return t;\n            else k -= ls + 1, t = d[t].ch[1];\n\
    \        }\n    }\n\n    // [l, r) \u304C\u300C\u6839\u306E\u53F3\u306E\u5B50\u306E\
    \u5DE6\u306E\u5B50\u300D\u306E\u90E8\u5206\u6728\u306B\u306A\u308B\u3088\u3046\
    \u306B\u3057\u3066\uFF0C\u6839\u306E\u53F3\u306E\u5B50\u3092\u8FD4\u3059\n   \
    \ int range(int l, int r) {\n        int a = kth(l);\n        splay(a, 0);\n \
    \       int b = kth(r + 1);\n        splay(b, a);\n        return b;\n    }\n\n\
    \    void dfs(int t, vector<S> &res) {\n        if (!t) return;\n        push(t);\n\
    \        dfs(d[t].ch[0], res);\n        res.push_back(d[t].val);\n        dfs(d[t].ch[1],\
    \ res);\n    }\n};\n"
  dependsOn:
  - template.hpp
  - algebra/acted_monoid.hpp
  - algebra/monoid.hpp
  - template.hpp
  isVerificationFile: false
  path: data_structure/dynamic_sequence.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/range_reverse_range_sum.test.cpp
  - test/unittest/dynamic_sequence.test.cpp
  - test/dynamic_sequence_range_affine_range_sum.test.cpp
documentation_of: data_structure/dynamic_sequence.hpp
layout: document
title: "\u5217\u306E\u633F\u5165\u30FB\u524A\u9664\u30FB\u53CD\u8EE2\u30FB\u533A\u9593\
  \u4F5C\u7528 (Dynamic Sequence, Splay \u6728)"
---

## 概要

列に対して、任意位置への挿入・削除・**区間反転**・区間作用・区間積を、ならし $O(\log n)$ で処理する（Splay 木）。値と作用は遅延セグメント木と同じ作用付きモノイド `AM`（[acted_monoid.hpp](../../algebra/acted_monoid.hpp)）。

- 両端に番兵を置き、区間 $[l, r)$ は「$l-1$ 番目を根に splay → $r$ 番目を根の右の子に splay」したときの、その左の子の部分木として取り出す。取り出した部分木の根に、反転フラグや作用を遅延で載せる。
- 反転は部分木の左右の子を入れ替える。非可換なモノイドで反転するときは逆順の積も持つ必要があるので、`COMMUTATIVE = false` を指定する。

## 使い方

```cpp
using AM = ActedAffineSum<mint>;
vector<AM::S> a(n);                   // a[i] = AM::make(x)
DynamicSequence<AM> seq(a);
seq.reserve(n + q);                   // 挿入の回数分の容量 (任意)
seq.insert(i, AM::make(x));           // i 番目の直前に挿入 (i = size() なら末尾)
seq.erase(i);
seq.reverse(l, r);
seq.apply(l, r, {b, c});
seq.prod(l, r).sum;
seq.get(i); seq.set(i, x);
seq.push_back(x); seq.push_front(x);
seq.size(); seq.all_prod(); seq.to_vector();

// 作用なしで反転と区間和だけ
DynamicSequence<ActedNone<MonoidSum<long long>>> s2(v);   // vector<long long> v
// 非可換なモノイドで反転する
DynamicSequence<ActedNone<MonoidAffine<mint>>, false> s3(fs);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `DynamicSequence<AM, COMMUTATIVE = true>(const vector<S> &a)` | 構築 | $O(n)$ |
| `void insert(int i, S x)` / `push_back` / `push_front` | 挿入 | ならし $O(\log n)$ |
| `void erase(int i)` | 削除 | ならし $O(\log n)$ |
| `void reverse(int l, int r)` | $[l, r)$ を反転 | ならし $O(\log n)$ |
| `void apply(int l, int r, F f)` | $[l, r)$ に作用 | ならし $O(\log n)$ |
| `S prod(int l, int r)` | 区間積（空なら `e()`） | ならし $O(\log n)$ |
| `S get(int i)` / `void set(int i, S x)` | 一点取得 / 更新 | ならし $O(\log n)$ |
| `int size()` | 要素数 | $O(1)$ |
| `vector<S> to_vector()` | 列全体（デバッグ用） | $O(n)$ |

## 注意

- 区間を反転するとき、モノイドが非可換なら `COMMUTATIVE = false` にすること（デフォルトの `true` だと逆順の積を持たないので、反転後の積がおかしくなる）。和・最小値などは可換なのでそのままでよい。
- 削除したノードは再利用しない（ノード数は 初期の長さ + 挿入回数）。
- 作用付きモノイドの書き方は [acted_monoid.hpp](../../algebra/acted_monoid.hpp)。作用が要らないときは `ActedNone<M>` でモノイド `M` を包む。
