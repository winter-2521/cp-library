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
    path: test/persistent_range_affine_range_sum.test.cpp
    title: test/persistent_range_affine_range_sum.test.cpp
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
    \ 4 \"data_structure/persistent_lazy_segment_tree.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u6C38\u7D9A\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n// \u5404\u30D0\
    \u30FC\u30B8\u30E7\u30F3\u3092\u6839\u306E\u30CE\u30FC\u30C9\u756A\u53F7 (int)\
    \ \u3067\u8868\u3059\uFF0E\u66F4\u65B0\u306F\u65B0\u3057\u3044\u30D0\u30FC\u30B8\
    \u30E7\u30F3\u306E\u6839\u3092\u8FD4\u3057\uFF0C\u53E4\u3044\u30D0\u30FC\u30B8\
    \u30E7\u30F3\u306F\u5909\u308F\u3089\u306A\u3044\n// 1 \u56DE\u306E\u66F4\u65B0\
    \u3067\u4F5C\u308B\u30CE\u30FC\u30C9\u306F O(log n) \u500B\uFF0E\u533A\u9593\u7A4D\
    \u306F\u30CE\u30FC\u30C9\u3092\u4F5C\u3089\u306A\u3044\ntemplate <class AM>\n\
    struct PersistentLazySegmentTree {\n    using S = typename AM::S;\n    using F\
    \ = typename AM::F;\n    struct Node {\n        S val;\n        F lz;\n      \
    \  int l, r;\n        bool has_lz;  // lz \u304C\u6052\u7B49\u5199\u50CF\u3067\
    \u306A\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u304B\n    };\n    int n;\n\n\
    \    // \u30CE\u30FC\u30C9\u306F 2^16 \u500B\u305A\u3064\u306E\u30D6\u30ED\u30C3\
    \u30AF\u306B\u78BA\u4FDD\u3059\u308B (vector \u306E\u518D\u78BA\u4FDD\u306B\u3088\
    \u308B\u30B3\u30D4\u30FC\u3068\u30E1\u30E2\u30EA\u306E\u4E00\u6642\u7684\u306A\
    \u500D\u5897\u3092\u907F\u3051\u308B)\n    static constexpr int BLK = 16;\n  \
    \  vector<unique_ptr<Node[]>> blocks;\n    int cnt = 0;\n\n    PersistentLazySegmentTree(int\
    \ n = 0) : n(n) {}\n\n    // \u4F5C\u3063\u305F\u30CE\u30FC\u30C9\u306E\u500B\u6570\
    \n    int node_count() const { return cnt; }\n\n    // \u914D\u5217 a (\u9577\u3055\
    \ n) \u306E\u30D0\u30FC\u30B8\u30E7\u30F3\u3092\u4F5C\u3063\u3066\u6839\u3092\u8FD4\
    \u3059\n    int build(const vector<S> &a) {\n        assert((int)a.size() == n);\n\
    \        return build(a, 0, n);\n    }\n    // \u5168\u3066 x \u306E\u30D0\u30FC\
    \u30B8\u30E7\u30F3\n    int build(const S &x = AM::e()) { return build(vector<S>(n,\
    \ x)); }\n\n    // \u30D0\u30FC\u30B8\u30E7\u30F3 root \u306E a[p] \u3092 x \u306B\
    \u3057\u305F\u30D0\u30FC\u30B8\u30E7\u30F3\n    int set(int root, int p, const\
    \ S &x) {\n        int v = clone(root);\n        set(v, 0, n, p, x);\n       \
    \ return v;\n    }\n\n    S get(int root, int p) const { return prod(root, p,\
    \ p + 1); }\n\n    // \u30D0\u30FC\u30B8\u30E7\u30F3 root \u306E op(a[l], ...,\
    \ a[r-1])\n    S prod(int root, int l, int r) const {\n        if (l >= r) return\
    \ AM::e();\n        return prod(root, 0, n, l, r, AM::id());\n    }\n    S all_prod(int\
    \ root) const { return nd_(root).val; }\n\n    // \u30D0\u30FC\u30B8\u30E7\u30F3\
    \ root \u3067 i in [l, r) \u306B\u3064\u3044\u3066 a[i] = f(a[i]) \u3068\u3057\
    \u305F\u30D0\u30FC\u30B8\u30E7\u30F3\n    int apply(int root, int l, int r, const\
    \ F &f) {\n        if (l >= r) return root;\n        int v = clone(root);\n  \
    \      apply(v, 0, n, l, r, f);\n        return v;\n    }\n\n    // \u30D0\u30FC\
    \u30B8\u30E7\u30F3 dst \u306E [l, r) \u3092\u30D0\u30FC\u30B8\u30E7\u30F3 src\
    \ \u306E [l, r) \u3067\u7F6E\u304D\u63DB\u3048\u305F\u30D0\u30FC\u30B8\u30E7\u30F3\
    \n    int copy_range(int dst, int src, int l, int r) {\n        if (l >= r) return\
    \ dst;\n        return copy_range(dst, src, 0, n, l, r, AM::id());\n    }\n\n\
    \    // \u30D0\u30FC\u30B8\u30E7\u30F3 root \u306E\u914D\u5217\u5168\u4F53\n \
    \   vector<S> to_vector(int root) const {\n        vector<S> res;\n        res.reserve(n);\n\
    \        auto dfs = [&](auto self, int v, int lo, int hi, const F &g) -> void\
    \ {\n            if (hi - lo == 1) {\n                res.push_back(AM::mapping(g,\
    \ nd_(v).val));\n                return;\n            }\n            int mid =\
    \ (lo + hi) >> 1;\n            F h = AM::composition(g, nd_(v).lz);\n        \
    \    self(self, nd_(v).l, lo, mid, h);\n            self(self, nd_(v).r, mid,\
    \ hi, h);\n        };\n        if (n) dfs(dfs, root, 0, n, AM::id());\n      \
    \  return res;\n    }\n\n  private:\n    Node &nd_(int i) { return blocks[i >>\
    \ BLK][i & ((1 << BLK) - 1)]; }\n    const Node &nd_(int i) const { return blocks[i\
    \ >> BLK][i & ((1 << BLK) - 1)]; }\n    int new_node(const Node &x) {\n      \
    \  if ((cnt >> BLK) == (int)blocks.size()) blocks.emplace_back(new Node[1 << BLK]);\n\
    \        nd_(cnt) = x;\n        return cnt++;\n    }\n    int clone(int v) { return\
    \ new_node(Node(nd_(v))); }\n    int build(const vector<S> &a, int lo, int hi)\
    \ {\n        if (hi - lo == 1) {\n            return new_node({a[lo], AM::id(),\
    \ -1, -1, false});\n        }\n        int mid = (lo + hi) >> 1;\n        int\
    \ l = build(a, lo, mid), r = build(a, mid, hi);\n        return new_node({AM::op(nd_(l).val,\
    \ nd_(r).val), AM::id(), l, r, false});\n    }\n    void all_apply(int v, const\
    \ F &f) {\n        nd_(v).val = AM::mapping(f, nd_(v).val);\n        nd_(v).lz\
    \ = AM::composition(f, nd_(v).lz);\n        nd_(v).has_lz = true;\n    }\n   \
    \ // v \u306F\u4ECA\u56DE\u4F5C\u3063\u305F\u30CE\u30FC\u30C9\uFF0E\u4F5C\u7528\
    \u304C\u6B8B\u3063\u3066\u3044\u308C\u3070\u5B50\u3092\u4E21\u65B9\u8907\u88FD\
    \u3057\u3066\u4E0B\u308D\u3059 (\u5B50\u3082\u4ECA\u56DE\u4F5C\u3063\u305F\u30CE\
    \u30FC\u30C9\u306B\u306A\u308B)\n    // \u4F5C\u7528\u304C\u306A\u3051\u308C\u3070\
    \u4F55\u3082\u3057\u306A\u3044 (\u89E6\u308B\u5B50\u3060\u3051\u3092 own_left\
    \ / own_right \u3067\u8907\u88FD\u3059\u308B)\n    void push(int v) {\n      \
    \  if (!nd_(v).has_lz) return;\n        int a = clone(nd_(v).l);\n        int\
    \ b = clone(nd_(v).r);\n        nd_(v).l = a, nd_(v).r = b;\n        const F f\
    \ = nd_(v).lz;\n        all_apply(a, f), all_apply(b, f);\n        nd_(v).lz =\
    \ AM::id();\n        nd_(v).has_lz = false;\n        fresh_l = fresh_r = true;\n\
    \    }\n    // push \u306E\u76F4\u5F8C\u306B\u547C\u3076\uFF0E\u5B50\u304C\u4ECA\
    \u56DE\u4F5C\u3063\u305F\u30CE\u30FC\u30C9\u3067\u306A\u3051\u308C\u3070\u8907\
    \u88FD\u3059\u308B\n    int own_left(int v) {\n        if (!fresh_l) {\n     \
    \       int c = clone(nd_(v).l);\n            nd_(v).l = c;\n        }\n     \
    \   return nd_(v).l;\n    }\n    int own_right(int v) {\n        if (!fresh_r)\
    \ {\n            int c = clone(nd_(v).r);\n            nd_(v).r = c;\n       \
    \ }\n        return nd_(v).r;\n    }\n    bool fresh_l = false, fresh_r = false;\n\
    \    void begin_push(int v) {\n        fresh_l = fresh_r = false;\n        push(v);\n\
    \    }\n    void update(int v) { nd_(v).val = AM::op(nd_(nd_(v).l).val, nd_(nd_(v).r).val);\
    \ }\n\n    void set(int v, int lo, int hi, int p, const S &x) {\n        if (hi\
    \ - lo == 1) {\n            nd_(v).val = x;\n            return;\n        }\n\
    \        begin_push(v);\n        int mid = (lo + hi) >> 1;\n        if (p < mid)\
    \ set(own_left(v), lo, mid, p, x);\n        else set(own_right(v), mid, hi, p,\
    \ x);\n        update(v);\n    }\n\n    void apply(int v, int lo, int hi, int\
    \ l, int r, const F &f) {\n        if (l <= lo && hi <= r) {\n            all_apply(v,\
    \ f);\n            return;\n        }\n        begin_push(v);\n        int mid\
    \ = (lo + hi) >> 1;\n        // own_* \u306F push \u76F4\u5F8C\u306E\u72B6\u614B\
    \ (fresh_*) \u3092\u4F7F\u3046\u306E\u3067\uFF0C\u518D\u5E30\u306E\u524D\u306B\
    \u4E21\u65B9\u78BA\u5B9A\u3055\u305B\u308B\n        int a = l < mid ? own_left(v)\
    \ : -1;\n        int b = mid < r ? own_right(v) : -1;\n        if (a != -1) apply(a,\
    \ lo, mid, l, r, f);\n        if (b != -1) apply(b, mid, hi, l, r, f);\n     \
    \   update(v);\n    }\n\n    // g: \u307E\u3060\u4E0B\u308D\u3057\u3066\u3044\u306A\
    \u3044\u4E0A\u304B\u3089\u306E\u4F5C\u7528\n    S prod(int v, int lo, int hi,\
    \ int l, int r, const F &g) const {\n        if (l <= lo && hi <= r) return AM::mapping(g,\
    \ nd_(v).val);\n        int mid = (lo + hi) >> 1;\n        F h = AM::composition(g,\
    \ nd_(v).lz);\n        if (r <= mid) return prod(nd_(v).l, lo, mid, l, r, h);\n\
    \        if (mid <= l) return prod(nd_(v).r, mid, hi, l, r, h);\n        return\
    \ AM::op(prod(nd_(v).l, lo, mid, l, r, h), prod(nd_(v).r, mid, hi, l, r, h));\n\
    \    }\n\n    // g: src \u5074\u3067\u307E\u3060\u4E0B\u308D\u3057\u3066\u3044\
    \u306A\u3044\u4E0A\u304B\u3089\u306E\u4F5C\u7528\n    int copy_range(int d, int\
    \ s, int lo, int hi, int l, int r, const F &g) {\n        if (r <= lo || hi <=\
    \ l) return d;\n        if (l <= lo && hi <= r) {\n            int v = clone(s);\n\
    \            all_apply(v, g);\n            return v;\n        }\n        int v\
    \ = clone(d);\n        begin_push(v);\n        int mid = (lo + hi) >> 1;\n   \
    \     F h = AM::composition(g, nd_(s).lz);\n        int a = copy_range(nd_(v).l,\
    \ nd_(s).l, lo, mid, l, r, h);\n        int b = copy_range(nd_(v).r, nd_(s).r,\
    \ mid, hi, l, r, h);\n        nd_(v).l = a, nd_(v).r = b;\n        update(v);\n\
    \        return v;\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"../algebra/acted_monoid.hpp\"\
    \n\n// https://github.com/winter-2521/cp-library\n\n// \u6C38\u7D9A\u9045\u5EF6\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n// \u5404\u30D0\u30FC\u30B8\u30E7\u30F3\u3092\
    \u6839\u306E\u30CE\u30FC\u30C9\u756A\u53F7 (int) \u3067\u8868\u3059\uFF0E\u66F4\
    \u65B0\u306F\u65B0\u3057\u3044\u30D0\u30FC\u30B8\u30E7\u30F3\u306E\u6839\u3092\
    \u8FD4\u3057\uFF0C\u53E4\u3044\u30D0\u30FC\u30B8\u30E7\u30F3\u306F\u5909\u308F\
    \u3089\u306A\u3044\n// 1 \u56DE\u306E\u66F4\u65B0\u3067\u4F5C\u308B\u30CE\u30FC\
    \u30C9\u306F O(log n) \u500B\uFF0E\u533A\u9593\u7A4D\u306F\u30CE\u30FC\u30C9\u3092\
    \u4F5C\u3089\u306A\u3044\ntemplate <class AM>\nstruct PersistentLazySegmentTree\
    \ {\n    using S = typename AM::S;\n    using F = typename AM::F;\n    struct\
    \ Node {\n        S val;\n        F lz;\n        int l, r;\n        bool has_lz;\
    \  // lz \u304C\u6052\u7B49\u5199\u50CF\u3067\u306A\u3044\u53EF\u80FD\u6027\u304C\
    \u3042\u308B\u304B\n    };\n    int n;\n\n    // \u30CE\u30FC\u30C9\u306F 2^16\
    \ \u500B\u305A\u3064\u306E\u30D6\u30ED\u30C3\u30AF\u306B\u78BA\u4FDD\u3059\u308B\
    \ (vector \u306E\u518D\u78BA\u4FDD\u306B\u3088\u308B\u30B3\u30D4\u30FC\u3068\u30E1\
    \u30E2\u30EA\u306E\u4E00\u6642\u7684\u306A\u500D\u5897\u3092\u907F\u3051\u308B\
    )\n    static constexpr int BLK = 16;\n    vector<unique_ptr<Node[]>> blocks;\n\
    \    int cnt = 0;\n\n    PersistentLazySegmentTree(int n = 0) : n(n) {}\n\n  \
    \  // \u4F5C\u3063\u305F\u30CE\u30FC\u30C9\u306E\u500B\u6570\n    int node_count()\
    \ const { return cnt; }\n\n    // \u914D\u5217 a (\u9577\u3055 n) \u306E\u30D0\
    \u30FC\u30B8\u30E7\u30F3\u3092\u4F5C\u3063\u3066\u6839\u3092\u8FD4\u3059\n   \
    \ int build(const vector<S> &a) {\n        assert((int)a.size() == n);\n     \
    \   return build(a, 0, n);\n    }\n    // \u5168\u3066 x \u306E\u30D0\u30FC\u30B8\
    \u30E7\u30F3\n    int build(const S &x = AM::e()) { return build(vector<S>(n,\
    \ x)); }\n\n    // \u30D0\u30FC\u30B8\u30E7\u30F3 root \u306E a[p] \u3092 x \u306B\
    \u3057\u305F\u30D0\u30FC\u30B8\u30E7\u30F3\n    int set(int root, int p, const\
    \ S &x) {\n        int v = clone(root);\n        set(v, 0, n, p, x);\n       \
    \ return v;\n    }\n\n    S get(int root, int p) const { return prod(root, p,\
    \ p + 1); }\n\n    // \u30D0\u30FC\u30B8\u30E7\u30F3 root \u306E op(a[l], ...,\
    \ a[r-1])\n    S prod(int root, int l, int r) const {\n        if (l >= r) return\
    \ AM::e();\n        return prod(root, 0, n, l, r, AM::id());\n    }\n    S all_prod(int\
    \ root) const { return nd_(root).val; }\n\n    // \u30D0\u30FC\u30B8\u30E7\u30F3\
    \ root \u3067 i in [l, r) \u306B\u3064\u3044\u3066 a[i] = f(a[i]) \u3068\u3057\
    \u305F\u30D0\u30FC\u30B8\u30E7\u30F3\n    int apply(int root, int l, int r, const\
    \ F &f) {\n        if (l >= r) return root;\n        int v = clone(root);\n  \
    \      apply(v, 0, n, l, r, f);\n        return v;\n    }\n\n    // \u30D0\u30FC\
    \u30B8\u30E7\u30F3 dst \u306E [l, r) \u3092\u30D0\u30FC\u30B8\u30E7\u30F3 src\
    \ \u306E [l, r) \u3067\u7F6E\u304D\u63DB\u3048\u305F\u30D0\u30FC\u30B8\u30E7\u30F3\
    \n    int copy_range(int dst, int src, int l, int r) {\n        if (l >= r) return\
    \ dst;\n        return copy_range(dst, src, 0, n, l, r, AM::id());\n    }\n\n\
    \    // \u30D0\u30FC\u30B8\u30E7\u30F3 root \u306E\u914D\u5217\u5168\u4F53\n \
    \   vector<S> to_vector(int root) const {\n        vector<S> res;\n        res.reserve(n);\n\
    \        auto dfs = [&](auto self, int v, int lo, int hi, const F &g) -> void\
    \ {\n            if (hi - lo == 1) {\n                res.push_back(AM::mapping(g,\
    \ nd_(v).val));\n                return;\n            }\n            int mid =\
    \ (lo + hi) >> 1;\n            F h = AM::composition(g, nd_(v).lz);\n        \
    \    self(self, nd_(v).l, lo, mid, h);\n            self(self, nd_(v).r, mid,\
    \ hi, h);\n        };\n        if (n) dfs(dfs, root, 0, n, AM::id());\n      \
    \  return res;\n    }\n\n  private:\n    Node &nd_(int i) { return blocks[i >>\
    \ BLK][i & ((1 << BLK) - 1)]; }\n    const Node &nd_(int i) const { return blocks[i\
    \ >> BLK][i & ((1 << BLK) - 1)]; }\n    int new_node(const Node &x) {\n      \
    \  if ((cnt >> BLK) == (int)blocks.size()) blocks.emplace_back(new Node[1 << BLK]);\n\
    \        nd_(cnt) = x;\n        return cnt++;\n    }\n    int clone(int v) { return\
    \ new_node(Node(nd_(v))); }\n    int build(const vector<S> &a, int lo, int hi)\
    \ {\n        if (hi - lo == 1) {\n            return new_node({a[lo], AM::id(),\
    \ -1, -1, false});\n        }\n        int mid = (lo + hi) >> 1;\n        int\
    \ l = build(a, lo, mid), r = build(a, mid, hi);\n        return new_node({AM::op(nd_(l).val,\
    \ nd_(r).val), AM::id(), l, r, false});\n    }\n    void all_apply(int v, const\
    \ F &f) {\n        nd_(v).val = AM::mapping(f, nd_(v).val);\n        nd_(v).lz\
    \ = AM::composition(f, nd_(v).lz);\n        nd_(v).has_lz = true;\n    }\n   \
    \ // v \u306F\u4ECA\u56DE\u4F5C\u3063\u305F\u30CE\u30FC\u30C9\uFF0E\u4F5C\u7528\
    \u304C\u6B8B\u3063\u3066\u3044\u308C\u3070\u5B50\u3092\u4E21\u65B9\u8907\u88FD\
    \u3057\u3066\u4E0B\u308D\u3059 (\u5B50\u3082\u4ECA\u56DE\u4F5C\u3063\u305F\u30CE\
    \u30FC\u30C9\u306B\u306A\u308B)\n    // \u4F5C\u7528\u304C\u306A\u3051\u308C\u3070\
    \u4F55\u3082\u3057\u306A\u3044 (\u89E6\u308B\u5B50\u3060\u3051\u3092 own_left\
    \ / own_right \u3067\u8907\u88FD\u3059\u308B)\n    void push(int v) {\n      \
    \  if (!nd_(v).has_lz) return;\n        int a = clone(nd_(v).l);\n        int\
    \ b = clone(nd_(v).r);\n        nd_(v).l = a, nd_(v).r = b;\n        const F f\
    \ = nd_(v).lz;\n        all_apply(a, f), all_apply(b, f);\n        nd_(v).lz =\
    \ AM::id();\n        nd_(v).has_lz = false;\n        fresh_l = fresh_r = true;\n\
    \    }\n    // push \u306E\u76F4\u5F8C\u306B\u547C\u3076\uFF0E\u5B50\u304C\u4ECA\
    \u56DE\u4F5C\u3063\u305F\u30CE\u30FC\u30C9\u3067\u306A\u3051\u308C\u3070\u8907\
    \u88FD\u3059\u308B\n    int own_left(int v) {\n        if (!fresh_l) {\n     \
    \       int c = clone(nd_(v).l);\n            nd_(v).l = c;\n        }\n     \
    \   return nd_(v).l;\n    }\n    int own_right(int v) {\n        if (!fresh_r)\
    \ {\n            int c = clone(nd_(v).r);\n            nd_(v).r = c;\n       \
    \ }\n        return nd_(v).r;\n    }\n    bool fresh_l = false, fresh_r = false;\n\
    \    void begin_push(int v) {\n        fresh_l = fresh_r = false;\n        push(v);\n\
    \    }\n    void update(int v) { nd_(v).val = AM::op(nd_(nd_(v).l).val, nd_(nd_(v).r).val);\
    \ }\n\n    void set(int v, int lo, int hi, int p, const S &x) {\n        if (hi\
    \ - lo == 1) {\n            nd_(v).val = x;\n            return;\n        }\n\
    \        begin_push(v);\n        int mid = (lo + hi) >> 1;\n        if (p < mid)\
    \ set(own_left(v), lo, mid, p, x);\n        else set(own_right(v), mid, hi, p,\
    \ x);\n        update(v);\n    }\n\n    void apply(int v, int lo, int hi, int\
    \ l, int r, const F &f) {\n        if (l <= lo && hi <= r) {\n            all_apply(v,\
    \ f);\n            return;\n        }\n        begin_push(v);\n        int mid\
    \ = (lo + hi) >> 1;\n        // own_* \u306F push \u76F4\u5F8C\u306E\u72B6\u614B\
    \ (fresh_*) \u3092\u4F7F\u3046\u306E\u3067\uFF0C\u518D\u5E30\u306E\u524D\u306B\
    \u4E21\u65B9\u78BA\u5B9A\u3055\u305B\u308B\n        int a = l < mid ? own_left(v)\
    \ : -1;\n        int b = mid < r ? own_right(v) : -1;\n        if (a != -1) apply(a,\
    \ lo, mid, l, r, f);\n        if (b != -1) apply(b, mid, hi, l, r, f);\n     \
    \   update(v);\n    }\n\n    // g: \u307E\u3060\u4E0B\u308D\u3057\u3066\u3044\u306A\
    \u3044\u4E0A\u304B\u3089\u306E\u4F5C\u7528\n    S prod(int v, int lo, int hi,\
    \ int l, int r, const F &g) const {\n        if (l <= lo && hi <= r) return AM::mapping(g,\
    \ nd_(v).val);\n        int mid = (lo + hi) >> 1;\n        F h = AM::composition(g,\
    \ nd_(v).lz);\n        if (r <= mid) return prod(nd_(v).l, lo, mid, l, r, h);\n\
    \        if (mid <= l) return prod(nd_(v).r, mid, hi, l, r, h);\n        return\
    \ AM::op(prod(nd_(v).l, lo, mid, l, r, h), prod(nd_(v).r, mid, hi, l, r, h));\n\
    \    }\n\n    // g: src \u5074\u3067\u307E\u3060\u4E0B\u308D\u3057\u3066\u3044\
    \u306A\u3044\u4E0A\u304B\u3089\u306E\u4F5C\u7528\n    int copy_range(int d, int\
    \ s, int lo, int hi, int l, int r, const F &g) {\n        if (r <= lo || hi <=\
    \ l) return d;\n        if (l <= lo && hi <= r) {\n            int v = clone(s);\n\
    \            all_apply(v, g);\n            return v;\n        }\n        int v\
    \ = clone(d);\n        begin_push(v);\n        int mid = (lo + hi) >> 1;\n   \
    \     F h = AM::composition(g, nd_(s).lz);\n        int a = copy_range(nd_(v).l,\
    \ nd_(s).l, lo, mid, l, r, h);\n        int b = copy_range(nd_(v).r, nd_(s).r,\
    \ mid, hi, l, r, h);\n        nd_(v).l = a, nd_(v).r = b;\n        update(v);\n\
    \        return v;\n    }\n};\n"
  dependsOn:
  - template.hpp
  - algebra/acted_monoid.hpp
  - algebra/monoid.hpp
  - template.hpp
  isVerificationFile: false
  path: data_structure/persistent_lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/persistent_range_affine_range_sum.test.cpp
  - test/unittest/lazy_segment_tree.test.cpp
documentation_of: data_structure/persistent_lazy_segment_tree.hpp
layout: document
title: "\u6C38\u7D9A\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Persistent Lazy\
  \ Segment Tree)"
---

## 概要

遅延セグメント木の全てのバージョンを残す。各バージョンを根のノード番号 (`int`) で表し、更新操作は新しいバージョンの根を返す（元のバージョンは変わらない）。
「あるバージョンの区間を別のバージョンの同じ区間で置き換える」(`copy_range`) もできる。

- 更新は書き換えるノードだけを複製する（経路複製）。作用を下ろすときは子も複製する。
- 作用が残っていないノードでは、降りる側の子だけを複製する（ノード数と時間が約 2 割減る）。
- 区間積はノードを作らない（上から作用を持ち越して計算する）。
- ノードは $2^{16}$ 個ずつのブロックに確保する（`vector` の再確保によるコピーとメモリの一時的な倍増を避ける）。

## 使い方

```cpp
using AM = ActedAffineSum<mint>;
PersistentLazySegmentTree<AM> seg(n);
int v0 = seg.build(a);                    // vector<AM::S> a から最初のバージョン
int v1 = seg.apply(v0, l, r, {b, c});     // v0 に作用させたバージョン
int v2 = seg.copy_range(v1, v0, l, r);    // v1 の [l, r) を v0 の [l, r) にしたバージョン
int v3 = seg.set(v2, p, AM::make(x));
seg.prod(v1, l, r).sum;                   // v1 の区間和 (v0 は変わっていない)
seg.get(v0, p); seg.all_prod(v0); seg.to_vector(v0);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `PersistentLazySegmentTree<AM>(int n)` | 長さ `n` の木の入れ物 | $O(1)$ |
| `int build(const vector<S> &a)` / `int build(S x)` | 最初のバージョンを作る | $O(n)$ |
| `int apply(int v, int l, int r, F f)` | 区間作用したバージョン | $O(\log n)$ |
| `int copy_range(int dst, int src, int l, int r)` | `dst` の $[l, r)$ を `src` のもので置き換えたバージョン | $O(\log n)$ |
| `int set(int v, int p, S x)` | 一点代入したバージョン | $O(\log n)$ |
| `S prod(int v, int l, int r)` / `S get(int v, int p)` | 区間積 / 一点取得 | $O(\log n)$ |
| `S all_prod(int v)` | 全体の積 | $O(1)$ |
| `vector<S> to_vector(int v)` | 配列全体 | $O(n)$ |
| `int node_count()` | これまでに作ったノード数 | $O(1)$ |

## 注意

- ノードは解放しない。メモリは $O(n + q \log n)$（$n = q = 10^5$ の区間 1 次関数・区間和で手元最大 240 MB）。
