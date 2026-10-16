---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9 (Monoid)"
  - icon: ':x:'
    path: data_structure/fast_set.hpp
    title: "64 \u5206\u6728\u306B\u3088\u308B\u6574\u6570\u96C6\u5408 (Fast Set)"
  - icon: ':x:'
    path: data_structure/segment_tree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)"
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/point_set_range_sort_range_composite.test.cpp
    title: test/point_set_range_sort_range_composite.test.cpp
  - icon: ':x:'
    path: test/unittest/sortable_segment_tree.test.cpp
    title: test/unittest/sortable_segment_tree.test.cpp
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
    \    }\n    return r;\n}\n#line 2 \"template.hpp\"\nusing namespace std;\n#if\
    \ __has_include(<atcoder/all>)\n#include <atcoder/all>\nusing namespace atcoder;\n\
    #endif\n// QCfium\u6CD5\u3092\u4F7F\u3046\u6642\u306F\u30B3\u30E1\u30F3\u30C8\u30A2\
    \u30A6\u30C8\u3092\u5916\u3059\n/*/\n#pragma GCC optimize(\"Ofast,unroll-loops,no-stack-protector,fast-math\"\
    )\n#pragma GCC target(\"avx2,bmi,bmi2,lzcnt,popcnt\")\n#pragma GCC target(\"avx,avx2,fma\"\
    )\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma\"\
    )\n//*/\n#define rep(i,n) for(int i=0;i<n;i++)\n#define Rep(i,a,b) for(int i=a;i<b;i++)\n\
    #define ALL(x) (x).begin(),(x).end()\n#define dbgv(x); for(auto now : x) cout\
    \ << now << \" \"; cout << endl;\n//using P = pair<int,int>;\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\ntypedef pair<int, int> pii;\ntypedef\
    \ pair<ll, ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line\
    \ 3 \"data_structure/fast_set.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// 64 \u5206\u6728\u306B\u3088\u308B [0, n) \u306E\u6574\u6570\u96C6\u5408\n\
    // \u633F\u5165\u30FB\u524A\u9664\u30FB\u5B58\u5728\u5224\u5B9A\u30FB\u6B21\u306E\
    \u8981\u7D20\u30FB\u524D\u306E\u8981\u7D20\u3092 O(log_64 n) \u3067\u51E6\u7406\
    \u3059\u308B\nstruct FastSet {\n    int n, lg;\n    // seg[0] \u304C\u6700\u4E0B\
    \u6BB5\uFF0Eseg[h+1] \u306E bit i \u306F seg[h] \u306E i \u756A\u76EE\u306E\u30EF\
    \u30FC\u30C9\u304C 0 \u3067\u306A\u3044\u304B\u3092\u8868\u3059\n    vector<vector<uint64_t>>\
    \ seg;\n\n    FastSet(int n = 0) : n(n) {\n        int m = n;\n        do {\n\
    \            seg.push_back(vector<uint64_t>(std::max(1, (m + 63) >> 6)));\n  \
    \          m = (m + 63) >> 6;\n        } while (m > 1);\n        lg = seg.size();\n\
    \    }\n\n    // f(i) \u304C true \u306E i \u3092\u5168\u3066\u5165\u308C\u305F\
    \u72B6\u614B\u3067\u521D\u671F\u5316\u3059\u308B\uFF0EO(n)\n    template <class\
    \ F>\n    FastSet(int n, F f) : FastSet(n) {\n        for (int i = 0; i < n; i++)\
    \ if (f(i)) seg[0][i >> 6] |= 1ULL << (i & 63);\n        build_upper();\n    }\n\
    \n    // \u6700\u4E0B\u6BB5\u304B\u3089\u4E0A\u306E\u6BB5\u3092\u4F5C\u308A\u76F4\
    \u3059\n    void build_upper() {\n        for (int h = 0; h + 1 < lg; h++) {\n\
    \            fill(seg[h + 1].begin(), seg[h + 1].end(), 0);\n            for (size_t\
    \ i = 0; i < seg[h].size(); i++) if (seg[h][i]) seg[h + 1][i >> 6] |= 1ULL <<\
    \ (i & 63);\n        }\n    }\n\n    int size() const { return n; }\n\n    bool\
    \ contains(int i) const { return seg[0][i >> 6] >> (i & 63) & 1; }\n    bool operator[](int\
    \ i) const { return contains(i); }\n\n    void insert(int i) {\n        for (int\
    \ h = 0; h < lg; h++) {\n            uint64_t &w = seg[h][i >> 6];\n         \
    \   bool was_empty = w == 0;\n            w |= 1ULL << (i & 63);\n           \
    \ // \u3059\u3067\u306B\u4E0A\u306E\u6BB5\u306B\u30D5\u30E9\u30B0\u304C\u7ACB\u3063\
    \u3066\u3044\u308B\u306E\u3067\u6253\u3061\u5207\u308B\n            if (!was_empty)\
    \ break;\n            i >>= 6;\n        }\n    }\n\n    void erase(int i) {\n\
    \        for (int h = 0; h < lg; h++) {\n            uint64_t &w = seg[h][i >>\
    \ 6];\n            w &= ~(1ULL << (i & 63));\n            // \u30EF\u30FC\u30C9\
    \u304C\u307E\u3060\u7A7A\u3067\u306A\u3051\u308C\u3070\u4E0A\u306E\u6BB5\u306F\
    \u5909\u308F\u3089\u306A\u3044\n            if (w) break;\n            i >>= 6;\n\
    \        }\n    }\n\n    // i \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20\
    \ (\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 -1)\n    int next(int i) const {\n\
    \        if (i < 0) i = 0;\n        if (i >= n) return -1;\n        for (int h\
    \ = 0; h < lg; h++) {\n            if ((i >> 6) == (int)seg[h].size()) break;\n\
    \            uint64_t d = seg[h][i >> 6] >> (i & 63);\n            if (d == 0)\
    \ {\n                i = (i >> 6) + 1;\n                continue;\n          \
    \  }\n            i += __builtin_ctzll(d);\n            for (int g = h - 1; g\
    \ >= 0; g--) {\n                i <<= 6;\n                i += __builtin_ctzll(seg[g][i\
    \ >> 6]);\n            }\n            return i;\n        }\n        return -1;\n\
    \    }\n\n    // i \u4EE5\u4E0B\u306E\u6700\u5927\u306E\u8981\u7D20 (\u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070 -1)\n    int prev(int i) const {\n        if (i\
    \ >= n) i = n - 1;\n        for (int h = 0; h < lg; h++) {\n            if (i\
    \ < 0) break;\n            uint64_t d = seg[h][i >> 6] << (63 - (i & 63));\n \
    \           if (d == 0) {\n                i = (i >> 6) - 1;\n               \
    \ continue;\n            }\n            i -= __builtin_clzll(d);\n           \
    \ for (int g = h - 1; g >= 0; g--) {\n                i <<= 6;\n             \
    \   i += 63 - __builtin_clzll(seg[g][i >> 6]);\n            }\n            return\
    \ i;\n        }\n        return -1;\n    }\n\n    // \u6700\u5C0F\u306E\u8981\u7D20\
    \ (\u7A7A\u306A\u3089 -1)\n    int min() const { return next(0); }\n    // \u6700\
    \u5927\u306E\u8981\u7D20 (\u7A7A\u306A\u3089 -1)\n    int max() const { return\
    \ prev(n - 1); }\n    bool empty() const { return seg[lg - 1][0] == 0; }\n\n \
    \   // [l, r) \u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u3092\u6607\u9806\u306B\
    \ f \u306B\u6E21\u3059\n    template <class F>\n    void enumerate(int l, int\
    \ r, F f) const {\n        for (int x = next(l); x != -1 && x < r; x = next(x\
    \ + 1)) f(x);\n    }\n};\n#line 2 \"template.hpp\"\nusing namespace std;\n#if\
    \ __has_include(<atcoder/all>)\n#include <atcoder/all>\nusing namespace atcoder;\n\
    #endif\n// QCfium\u6CD5\u3092\u4F7F\u3046\u6642\u306F\u30B3\u30E1\u30F3\u30C8\u30A2\
    \u30A6\u30C8\u3092\u5916\u3059\n/*/\n#pragma GCC optimize(\"Ofast,unroll-loops,no-stack-protector,fast-math\"\
    )\n#pragma GCC target(\"avx2,bmi,bmi2,lzcnt,popcnt\")\n#pragma GCC target(\"avx,avx2,fma\"\
    )\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma\"\
    )\n//*/\n#define rep(i,n) for(int i=0;i<n;i++)\n#define Rep(i,a,b) for(int i=a;i<b;i++)\n\
    #define ALL(x) (x).begin(),(x).end()\n#define dbgv(x); for(auto now : x) cout\
    \ << now << \" \"; cout << endl;\n//using P = pair<int,int>;\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\ntypedef pair<int, int> pii;\ntypedef\
    \ pair<ll, ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line\
    \ 4 \"data_structure/segment_tree.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\
    \u9593\u7A4D)\n// M \u306F\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp \u53C2\u7167\
    )\uFF0E\u975E\u53EF\u63DB\u3067\u3082\u3088\u3044\ntemplate <class M>\nstruct\
    \ SegmentTree {\n    using S = typename M::S;\n    int n, sz, lg;\n    vector<S>\
    \ d;\n\n    SegmentTree(int n = 0) : SegmentTree(vector<S>(n, M::e())) {}\n\n\
    \    SegmentTree(const vector<S> &a) : n(a.size()) {\n        lg = 0;\n      \
    \  while ((1 << lg) < n) lg++;\n        sz = 1 << lg;\n        d.assign(2 * sz,\
    \ M::e());\n        copy(a.begin(), a.end(), d.begin() + sz);\n        for (int\
    \ i = sz - 1; i >= 1; i--) d[i] = M::op(d[2 * i], d[2 * i + 1]);\n    }\n\n  \
    \  int size() const { return n; }\n\n    // a[p] = x\n    void set(int p, const\
    \ S &x) {\n        p += sz;\n        d[p] = x;\n        for (p >>= 1; p; p >>=\
    \ 1) d[p] = M::op(d[2 * p], d[2 * p + 1]);\n    }\n\n    // a[p] = op(a[p], x)\n\
    \    void multiply(int p, const S &x) { set(p, M::op(d[p + sz], x)); }\n\n   \
    \ S get(int p) const { return d[p + sz]; }\n    S operator[](int p) const { return\
    \ d[p + sz]; }\n\n    // op(a[l], ..., a[r-1])\uFF0El == r \u306A\u3089 e()\n\
    \    S prod(int l, int r) const {\n        S sml = M::e(), smr = M::e();\n   \
    \     l += sz, r += sz;\n        while (l < r) {\n            if (l & 1) sml =\
    \ M::op(sml, d[l++]);\n            if (r & 1) smr = M::op(d[--r], smr);\n    \
    \        l >>= 1, r >>= 1;\n        }\n        return M::op(sml, smr);\n    }\n\
    \n    S all_prod() const { return d[1]; }\n\n    // g(op(a[l], ..., a[r-1])) \u304C\
    \ true \u3068\u306A\u308B\u6700\u5927\u306E r \u3092\u8FD4\u3059 (g(e()) \u306F\
    \ true \u3067\u3042\u308B\u3053\u3068)\n    template <class G>\n    int max_right(int\
    \ l, G g) const {\n        if (l == n) return n;\n        l += sz;\n        S\
    \ sm = M::e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n      \
    \      if (!g(M::op(sm, d[l]))) {\n                while (l < sz) {\n        \
    \            l = 2 * l;\n                    if (g(M::op(sm, d[l]))) sm = M::op(sm,\
    \ d[l++]);\n                }\n                return l - sz;\n            }\n\
    \            sm = M::op(sm, d[l++]);\n        } while ((l & -l) != l);\n     \
    \   return n;\n    }\n\n    // g(op(a[l], ..., a[r-1])) \u304C true \u3068\u306A\
    \u308B\u6700\u5C0F\u306E l \u3092\u8FD4\u3059 (g(e()) \u306F true \u3067\u3042\
    \u308B\u3053\u3068)\n    template <class G>\n    int min_left(int r, G g) const\
    \ {\n        if (r == 0) return 0;\n        r += sz;\n        S sm = M::e();\n\
    \        do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n\
    \            if (!g(M::op(d[r], sm))) {\n                while (r < sz) {\n  \
    \                  r = 2 * r + 1;\n                    if (g(M::op(d[r], sm)))\
    \ sm = M::op(d[r--], sm);\n                }\n                return r + 1 - sz;\n\
    \            }\n            sm = M::op(d[r], sm);\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n};\n#line 6 \"data_structure/sortable_segment_tree.hpp\"\
    \n\n// https://github.com/winter-2521/cp-library\n\n// \u533A\u9593\u30BD\u30FC\
    \u30C8\u304C\u3067\u304D\u308B\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n// \u5404\u4F4D\
    \u7F6E i \u306B (\u30AD\u30FC k_i, \u5024 a_i) \u3092\u6301\u3061\uFF0C\u4E00\u70B9\
    \u66F4\u65B0\u30FB\u533A\u9593\u7A4D\u30FB\u533A\u9593\u3092\u30AD\u30FC\u306E\
    \u6607\u9806 / \u964D\u9806\u306B\u30BD\u30FC\u30C8\u3092\u51E6\u7406\u3059\u308B\
    \n// M \u306F\u30E2\u30CE\u30A4\u30C9 (\u975E\u53EF\u63DB\u3067\u3082\u3088\u3044\
    )\uFF0E\u30AD\u30FC\u306F [0, 2^LOG) \u306E\u6574\u6570\u3067\uFF0C\u5168\u3066\
    \u76F8\u7570\u306A\u308B\u3053\u3068\n//\n// \u30BD\u30FC\u30C8\u6E08\u307F\u306E\
    \u9023\u7D9A\u90E8\u5206 (\u30E9\u30F3) \u3054\u3068\u306B\uFF0C\u30AD\u30FC\u306E\
    \ 2 \u5206\u30C8\u30E9\u30A4 (\u8981\u7D20\u6570\u30FB\u6607\u9806\u306E\u7A4D\
    \u30FB\u964D\u9806\u306E\u7A4D\u3092\u6301\u3064) \u3067\u7BA1\u7406\u3059\u308B\
    \uFF0E\n// \u30BD\u30FC\u30C8\u306F\u30C8\u30E9\u30A4\u306E\u30DE\u30FC\u30B8\uFF0C\
    \u30E9\u30F3\u306E\u9014\u4E2D\u3067\u5207\u308B\u306E\u306F\u30C8\u30E9\u30A4\
    \u306E\u8981\u7D20\u6570\u3067\u306E\u5206\u5272\uFF0E\n// \u30E9\u30F3\u306E\u5148\
    \u982D\u4F4D\u7F6E\u306B\u300C\u305D\u306E\u30E9\u30F3\u306E\u7A4D\u300D\u3092\
    \u7F6E\u3044\u305F\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3067\u533A\u9593\u7A4D\
    \u3092\u8A08\u7B97\u3059\u308B\uFF0E\n// \u8A08\u7B97\u91CF: \u5168\u4F53\u3067\
    \u306A\u3089\u3057 O((n + q) LOG) \u56DE\u306E\u30C8\u30E9\u30A4\u64CD\u4F5C +\
    \ \u5404\u64CD\u4F5C O(log n)\ntemplate <class M, int LOG = 30>\nstruct SortableSegmentTree\
    \ {\n    using S = typename M::S;\n    struct TNode {\n        int ch[2];\n  \
    \      int cnt;\n        S fwd, bwd;  // \u30AD\u30FC\u306E\u6607\u9806 / \u964D\
    \u9806\u306B\u4E26\u3079\u305F\u3068\u304D\u306E\u7A4D\n    };\n    int n;\n \
    \   vector<TNode> tr;\n    vector<int> free_nodes;\n    FastSet starts;      \
    \ // \u30E9\u30F3\u306E\u5148\u982D\u4F4D\u7F6E\n    vector<int> root;     //\
    \ root[s]: s \u304B\u3089\u59CB\u307E\u308B\u30E9\u30F3\u306E\u30C8\u30E9\u30A4\
    \n    vector<char> desc;    // desc[s]: \u30E9\u30F3\u304C\u964D\u9806\u304B\n\
    \    SegmentTree<M> seg;   // seg[s] = \u30E9\u30F3\u306E\u7A4D (\u30E9\u30F3\u306E\
    \u5148\u982D\u4EE5\u5916\u306F e())\n\n    // keys[i] \u3068 vals[i] \u3067\u521D\
    \u671F\u5316 (\u5404\u8981\u7D20\u304C\u9577\u3055 1 \u306E\u30E9\u30F3)\n   \
    \ SortableSegmentTree(const vector<long long> &keys, const vector<S> &vals)\n\
    \        : n(keys.size()), starts(n, [](int) { return true; }), root(n), desc(n,\
    \ 0), seg(vals) {\n        assert(keys.size() == vals.size());\n        tr.reserve((size_t)n\
    \ * (LOG + 1) + 1);\n        tr.push_back({{0, 0}, 0, M::e(), M::e()});  // 0\
    \ \u756A\u306F\u7A7A\n        for (int i = 0; i < n; i++) root[i] = make_single(keys[i],\
    \ vals[i]);\n    }\n\n    int size() const { return n; }\n\n    // \u4F4D\u7F6E\
    \ i \u3092 (key, x) \u306B\u3059\u308B\n    void set(int i, long long key, const\
    \ S &x) {\n        split(i), split(i + 1);\n        free_trie(root[i]);\n    \
    \    root[i] = make_single(key, x);\n        desc[i] = 0;\n        seg.set(i,\
    \ x);\n    }\n\n    // \u4F4D\u7F6E i \u306E (\u30AD\u30FC, \u5024)\n    pair<long\
    \ long, S> get(int i) const {\n        int s = starts.prev(i);\n        int v\
    \ = root[s], k = i - s;\n        if (desc[s]) k = tr[v].cnt - 1 - k;\n       \
    \ long long key = 0;\n        for (int d = LOG; d > 0; d--) {\n            int\
    \ c0 = tr[v].ch[0];\n            if (k < tr[c0].cnt) {\n                v = c0;\n\
    \            } else {\n                k -= tr[c0].cnt;\n                v = tr[v].ch[1];\n\
    \                key |= 1LL << (d - 1);\n            }\n        }\n        return\
    \ {key, tr[v].fwd};\n    }\n\n    // op(a[l], ..., a[r-1])\uFF0El == r \u306A\u3089\
    \ e()\n    S prod(int l, int r) {\n        if (l >= r) return M::e();\n      \
    \  split(l), split(r);\n        return seg.prod(l, r);\n    }\n    S all_prod()\
    \ const { return seg.all_prod(); }\n\n    // [l, r) \u3092\u30AD\u30FC\u306E\u6607\
    \u9806\u306B\u30BD\u30FC\u30C8\u3059\u308B\n    void sort_asc(int l, int r) {\
    \ sort_range(l, r, false); }\n    // [l, r) \u3092\u30AD\u30FC\u306E\u964D\u9806\
    \u306B\u30BD\u30FC\u30C8\u3059\u308B\n    void sort_desc(int l, int r) { sort_range(l,\
    \ r, true); }\n\n  private:\n    int new_node() {\n        if (!free_nodes.empty())\
    \ {\n            int v = free_nodes.back();\n            free_nodes.pop_back();\n\
    \            return v;\n        }\n        tr.push_back({});\n        return int(tr.size())\
    \ - 1;\n    }\n    void free_trie(int v) {\n        if (!v) return;\n        free_trie(tr[v].ch[0]),\
    \ free_trie(tr[v].ch[1]);\n        free_nodes.push_back(v);\n    }\n    void pull(int\
    \ v) {\n        int a = tr[v].ch[0], b = tr[v].ch[1];\n        // \u4E0A\u306E\
    \u65B9\u306E\u6BB5\u306F\u5B50\u304C\u7247\u65B9\u3060\u3051\u306E\u3053\u3068\
    \u304C\u591A\u3044\u306E\u3067\uFF0Cop \u3092\u7701\u304F\n        if (!a || !b)\
    \ {\n            const TNode &c = tr[a | b];\n            tr[v].cnt = c.cnt, tr[v].fwd\
    \ = c.fwd, tr[v].bwd = c.bwd;\n            return;\n        }\n        tr[v].cnt\
    \ = tr[a].cnt + tr[b].cnt;\n        tr[v].fwd = M::op(tr[a].fwd, tr[b].fwd);\n\
    \        tr[v].bwd = M::op(tr[b].bwd, tr[a].bwd);\n    }\n    int make_single(long\
    \ long key, const S &x) {\n        assert(0 <= key && key < (1LL << LOG));\n \
    \       int v = new_node();\n        tr[v] = {{0, 0}, 1, x, x};\n        for (int\
    \ d = 1; d <= LOG; d++) {\n            int p = new_node();\n            int b\
    \ = key >> (d - 1) & 1;\n            tr[p] = {{0, 0}, 1, x, x};\n            tr[p].ch[b]\
    \ = v;\n            v = p;\n        }\n        return v;\n    }\n    // 2 \u3064\
    \u306E\u30C8\u30E9\u30A4\u3092\u30DE\u30FC\u30B8 (\u30AD\u30FC\u306F\u76F8\u7570\
    \u306A\u308B\u3053\u3068)\n    int merge(int a, int b) {\n        if (!a || !b)\
    \ return a | b;\n        int x0 = merge(tr[a].ch[0], tr[b].ch[0]);\n        int\
    \ x1 = merge(tr[a].ch[1], tr[b].ch[1]);\n        tr[a].ch[0] = x0, tr[a].ch[1]\
    \ = x1;\n        free_nodes.push_back(b);\n        pull(a);\n        return a;\n\
    \    }\n    // \u30AD\u30FC\u306E\u5C0F\u3055\u3044\u65B9\u304B\u3089 k \u500B\
    \u3068\u6B8B\u308A\u306B\u5206\u3051\u308B (0 < k < cnt(v))\n    pair<int, int>\
    \ split_trie(int v, int k) {\n        if (k == 0) return {0, v};\n        if (k\
    \ >= tr[v].cnt) return {v, 0};\n        int w = new_node();\n        tr[w] = {{0,\
    \ 0}, 0, M::e(), M::e()};\n        int c0 = tr[v].ch[0];\n        if (k <= tr[c0].cnt)\
    \ {\n            auto [x, y] = split_trie(c0, k);\n            tr[w].ch[0] = y,\
    \ tr[w].ch[1] = tr[v].ch[1];\n            tr[v].ch[0] = x, tr[v].ch[1] = 0;\n\
    \        } else {\n            auto [x, y] = split_trie(tr[v].ch[1], k - tr[c0].cnt);\n\
    \            tr[w].ch[1] = y;\n            tr[v].ch[1] = x;\n        }\n     \
    \   pull(v), pull(w);\n        return {v, w};\n    }\n    S run_prod(int s) const\
    \ { return desc[s] ? tr[root[s]].bwd : tr[root[s]].fwd; }\n    // p \u3092\u30E9\
    \u30F3\u306E\u5148\u982D\u306B\u3059\u308B\n    void split(int p) {\n        if\
    \ (p <= 0 || p >= n || starts.contains(p)) return;\n        int s = starts.prev(p);\n\
    \        int k = p - s, len = tr[root[s]].cnt;\n        if (!desc[s]) {\n    \
    \        auto [a, b] = split_trie(root[s], k);\n            root[s] = a, root[p]\
    \ = b;\n        } else {\n            // \u964D\u9806\u306A\u306E\u3067\uFF0C\u5148\
    \u982D k \u500B\u306F\u30AD\u30FC\u306E\u5927\u304D\u3044\u65B9\n            auto\
    \ [a, b] = split_trie(root[s], len - k);\n            root[s] = b, root[p] = a;\n\
    \        }\n        desc[p] = desc[s];\n        starts.insert(p);\n        seg.set(s,\
    \ run_prod(s));\n        seg.set(p, run_prod(p));\n    }\n    void sort_range(int\
    \ l, int r, bool d) {\n        if (l >= r) return;\n        split(l), split(r);\n\
    \        for (int s = starts.next(l + 1); s != -1 && s < r; s = starts.next(s\
    \ + 1)) {\n            root[l] = merge(root[l], root[s]);\n            root[s]\
    \ = 0;\n            starts.erase(s);\n            seg.set(s, M::e());\n      \
    \  }\n        desc[l] = d;\n        seg.set(l, run_prod(l));\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"../algebra/monoid.hpp\"\
    \n#include \"fast_set.hpp\"\n#include \"segment_tree.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u533A\u9593\u30BD\u30FC\u30C8\u304C\u3067\u304D\u308B\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\n// \u5404\u4F4D\u7F6E i \u306B (\u30AD\u30FC k_i, \u5024 a_i) \u3092\
    \u6301\u3061\uFF0C\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\u9593\u7A4D\u30FB\u533A\
    \u9593\u3092\u30AD\u30FC\u306E\u6607\u9806 / \u964D\u9806\u306B\u30BD\u30FC\u30C8\
    \u3092\u51E6\u7406\u3059\u308B\n// M \u306F\u30E2\u30CE\u30A4\u30C9 (\u975E\u53EF\
    \u63DB\u3067\u3082\u3088\u3044)\uFF0E\u30AD\u30FC\u306F [0, 2^LOG) \u306E\u6574\
    \u6570\u3067\uFF0C\u5168\u3066\u76F8\u7570\u306A\u308B\u3053\u3068\n//\n// \u30BD\
    \u30FC\u30C8\u6E08\u307F\u306E\u9023\u7D9A\u90E8\u5206 (\u30E9\u30F3) \u3054\u3068\
    \u306B\uFF0C\u30AD\u30FC\u306E 2 \u5206\u30C8\u30E9\u30A4 (\u8981\u7D20\u6570\u30FB\
    \u6607\u9806\u306E\u7A4D\u30FB\u964D\u9806\u306E\u7A4D\u3092\u6301\u3064) \u3067\
    \u7BA1\u7406\u3059\u308B\uFF0E\n// \u30BD\u30FC\u30C8\u306F\u30C8\u30E9\u30A4\u306E\
    \u30DE\u30FC\u30B8\uFF0C\u30E9\u30F3\u306E\u9014\u4E2D\u3067\u5207\u308B\u306E\
    \u306F\u30C8\u30E9\u30A4\u306E\u8981\u7D20\u6570\u3067\u306E\u5206\u5272\uFF0E\
    \n// \u30E9\u30F3\u306E\u5148\u982D\u4F4D\u7F6E\u306B\u300C\u305D\u306E\u30E9\u30F3\
    \u306E\u7A4D\u300D\u3092\u7F6E\u3044\u305F\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u3067\u533A\u9593\u7A4D\u3092\u8A08\u7B97\u3059\u308B\uFF0E\n// \u8A08\u7B97\u91CF\
    : \u5168\u4F53\u3067\u306A\u3089\u3057 O((n + q) LOG) \u56DE\u306E\u30C8\u30E9\
    \u30A4\u64CD\u4F5C + \u5404\u64CD\u4F5C O(log n)\ntemplate <class M, int LOG =\
    \ 30>\nstruct SortableSegmentTree {\n    using S = typename M::S;\n    struct\
    \ TNode {\n        int ch[2];\n        int cnt;\n        S fwd, bwd;  // \u30AD\
    \u30FC\u306E\u6607\u9806 / \u964D\u9806\u306B\u4E26\u3079\u305F\u3068\u304D\u306E\
    \u7A4D\n    };\n    int n;\n    vector<TNode> tr;\n    vector<int> free_nodes;\n\
    \    FastSet starts;       // \u30E9\u30F3\u306E\u5148\u982D\u4F4D\u7F6E\n   \
    \ vector<int> root;     // root[s]: s \u304B\u3089\u59CB\u307E\u308B\u30E9\u30F3\
    \u306E\u30C8\u30E9\u30A4\n    vector<char> desc;    // desc[s]: \u30E9\u30F3\u304C\
    \u964D\u9806\u304B\n    SegmentTree<M> seg;   // seg[s] = \u30E9\u30F3\u306E\u7A4D\
    \ (\u30E9\u30F3\u306E\u5148\u982D\u4EE5\u5916\u306F e())\n\n    // keys[i] \u3068\
    \ vals[i] \u3067\u521D\u671F\u5316 (\u5404\u8981\u7D20\u304C\u9577\u3055 1 \u306E\
    \u30E9\u30F3)\n    SortableSegmentTree(const vector<long long> &keys, const vector<S>\
    \ &vals)\n        : n(keys.size()), starts(n, [](int) { return true; }), root(n),\
    \ desc(n, 0), seg(vals) {\n        assert(keys.size() == vals.size());\n     \
    \   tr.reserve((size_t)n * (LOG + 1) + 1);\n        tr.push_back({{0, 0}, 0, M::e(),\
    \ M::e()});  // 0 \u756A\u306F\u7A7A\n        for (int i = 0; i < n; i++) root[i]\
    \ = make_single(keys[i], vals[i]);\n    }\n\n    int size() const { return n;\
    \ }\n\n    // \u4F4D\u7F6E i \u3092 (key, x) \u306B\u3059\u308B\n    void set(int\
    \ i, long long key, const S &x) {\n        split(i), split(i + 1);\n        free_trie(root[i]);\n\
    \        root[i] = make_single(key, x);\n        desc[i] = 0;\n        seg.set(i,\
    \ x);\n    }\n\n    // \u4F4D\u7F6E i \u306E (\u30AD\u30FC, \u5024)\n    pair<long\
    \ long, S> get(int i) const {\n        int s = starts.prev(i);\n        int v\
    \ = root[s], k = i - s;\n        if (desc[s]) k = tr[v].cnt - 1 - k;\n       \
    \ long long key = 0;\n        for (int d = LOG; d > 0; d--) {\n            int\
    \ c0 = tr[v].ch[0];\n            if (k < tr[c0].cnt) {\n                v = c0;\n\
    \            } else {\n                k -= tr[c0].cnt;\n                v = tr[v].ch[1];\n\
    \                key |= 1LL << (d - 1);\n            }\n        }\n        return\
    \ {key, tr[v].fwd};\n    }\n\n    // op(a[l], ..., a[r-1])\uFF0El == r \u306A\u3089\
    \ e()\n    S prod(int l, int r) {\n        if (l >= r) return M::e();\n      \
    \  split(l), split(r);\n        return seg.prod(l, r);\n    }\n    S all_prod()\
    \ const { return seg.all_prod(); }\n\n    // [l, r) \u3092\u30AD\u30FC\u306E\u6607\
    \u9806\u306B\u30BD\u30FC\u30C8\u3059\u308B\n    void sort_asc(int l, int r) {\
    \ sort_range(l, r, false); }\n    // [l, r) \u3092\u30AD\u30FC\u306E\u964D\u9806\
    \u306B\u30BD\u30FC\u30C8\u3059\u308B\n    void sort_desc(int l, int r) { sort_range(l,\
    \ r, true); }\n\n  private:\n    int new_node() {\n        if (!free_nodes.empty())\
    \ {\n            int v = free_nodes.back();\n            free_nodes.pop_back();\n\
    \            return v;\n        }\n        tr.push_back({});\n        return int(tr.size())\
    \ - 1;\n    }\n    void free_trie(int v) {\n        if (!v) return;\n        free_trie(tr[v].ch[0]),\
    \ free_trie(tr[v].ch[1]);\n        free_nodes.push_back(v);\n    }\n    void pull(int\
    \ v) {\n        int a = tr[v].ch[0], b = tr[v].ch[1];\n        // \u4E0A\u306E\
    \u65B9\u306E\u6BB5\u306F\u5B50\u304C\u7247\u65B9\u3060\u3051\u306E\u3053\u3068\
    \u304C\u591A\u3044\u306E\u3067\uFF0Cop \u3092\u7701\u304F\n        if (!a || !b)\
    \ {\n            const TNode &c = tr[a | b];\n            tr[v].cnt = c.cnt, tr[v].fwd\
    \ = c.fwd, tr[v].bwd = c.bwd;\n            return;\n        }\n        tr[v].cnt\
    \ = tr[a].cnt + tr[b].cnt;\n        tr[v].fwd = M::op(tr[a].fwd, tr[b].fwd);\n\
    \        tr[v].bwd = M::op(tr[b].bwd, tr[a].bwd);\n    }\n    int make_single(long\
    \ long key, const S &x) {\n        assert(0 <= key && key < (1LL << LOG));\n \
    \       int v = new_node();\n        tr[v] = {{0, 0}, 1, x, x};\n        for (int\
    \ d = 1; d <= LOG; d++) {\n            int p = new_node();\n            int b\
    \ = key >> (d - 1) & 1;\n            tr[p] = {{0, 0}, 1, x, x};\n            tr[p].ch[b]\
    \ = v;\n            v = p;\n        }\n        return v;\n    }\n    // 2 \u3064\
    \u306E\u30C8\u30E9\u30A4\u3092\u30DE\u30FC\u30B8 (\u30AD\u30FC\u306F\u76F8\u7570\
    \u306A\u308B\u3053\u3068)\n    int merge(int a, int b) {\n        if (!a || !b)\
    \ return a | b;\n        int x0 = merge(tr[a].ch[0], tr[b].ch[0]);\n        int\
    \ x1 = merge(tr[a].ch[1], tr[b].ch[1]);\n        tr[a].ch[0] = x0, tr[a].ch[1]\
    \ = x1;\n        free_nodes.push_back(b);\n        pull(a);\n        return a;\n\
    \    }\n    // \u30AD\u30FC\u306E\u5C0F\u3055\u3044\u65B9\u304B\u3089 k \u500B\
    \u3068\u6B8B\u308A\u306B\u5206\u3051\u308B (0 < k < cnt(v))\n    pair<int, int>\
    \ split_trie(int v, int k) {\n        if (k == 0) return {0, v};\n        if (k\
    \ >= tr[v].cnt) return {v, 0};\n        int w = new_node();\n        tr[w] = {{0,\
    \ 0}, 0, M::e(), M::e()};\n        int c0 = tr[v].ch[0];\n        if (k <= tr[c0].cnt)\
    \ {\n            auto [x, y] = split_trie(c0, k);\n            tr[w].ch[0] = y,\
    \ tr[w].ch[1] = tr[v].ch[1];\n            tr[v].ch[0] = x, tr[v].ch[1] = 0;\n\
    \        } else {\n            auto [x, y] = split_trie(tr[v].ch[1], k - tr[c0].cnt);\n\
    \            tr[w].ch[1] = y;\n            tr[v].ch[1] = x;\n        }\n     \
    \   pull(v), pull(w);\n        return {v, w};\n    }\n    S run_prod(int s) const\
    \ { return desc[s] ? tr[root[s]].bwd : tr[root[s]].fwd; }\n    // p \u3092\u30E9\
    \u30F3\u306E\u5148\u982D\u306B\u3059\u308B\n    void split(int p) {\n        if\
    \ (p <= 0 || p >= n || starts.contains(p)) return;\n        int s = starts.prev(p);\n\
    \        int k = p - s, len = tr[root[s]].cnt;\n        if (!desc[s]) {\n    \
    \        auto [a, b] = split_trie(root[s], k);\n            root[s] = a, root[p]\
    \ = b;\n        } else {\n            // \u964D\u9806\u306A\u306E\u3067\uFF0C\u5148\
    \u982D k \u500B\u306F\u30AD\u30FC\u306E\u5927\u304D\u3044\u65B9\n            auto\
    \ [a, b] = split_trie(root[s], len - k);\n            root[s] = b, root[p] = a;\n\
    \        }\n        desc[p] = desc[s];\n        starts.insert(p);\n        seg.set(s,\
    \ run_prod(s));\n        seg.set(p, run_prod(p));\n    }\n    void sort_range(int\
    \ l, int r, bool d) {\n        if (l >= r) return;\n        split(l), split(r);\n\
    \        for (int s = starts.next(l + 1); s != -1 && s < r; s = starts.next(s\
    \ + 1)) {\n            root[l] = merge(root[l], root[s]);\n            root[s]\
    \ = 0;\n            starts.erase(s);\n            seg.set(s, M::e());\n      \
    \  }\n        desc[l] = d;\n        seg.set(l, run_prod(l));\n    }\n};\n"
  dependsOn:
  - template.hpp
  - algebra/monoid.hpp
  - template.hpp
  - data_structure/fast_set.hpp
  - data_structure/segment_tree.hpp
  isVerificationFile: false
  path: data_structure/sortable_segment_tree.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unittest/sortable_segment_tree.test.cpp
  - test/point_set_range_sort_range_composite.test.cpp
documentation_of: data_structure/sortable_segment_tree.hpp
layout: document
title: "\u533A\u9593\u30BD\u30FC\u30C8\u304C\u3067\u304D\u308B\u30BB\u30B0\u30E1\u30F3\
  \u30C8\u6728 (Sortable Segment Tree)"
---

## 概要

各位置 $i$ に（キー $k_i$, 値 $a_i$）を持ち、一点更新・区間積・**区間をキーの昇順 / 降順にソート** を処理する。値はモノイド（非可換でもよい）。**オンライン** で動く（キーの先読み不要）。

ソート済みの連続部分（ラン）ごとに、キーの 2 分トライを持つ。トライの各ノードは要素数と「キーの昇順に並べた積」「降順に並べた積」を持つ。

- 区間ソート：両端でランを切り、内側のランのトライを全てマージする。
- ランを途中で切る：トライを要素数で分割する（作るノードは $O(\mathrm{LOG})$ 個）。
- 区間積：両端でランを切り、ランの先頭位置にランの積を置いたセグメント木で求める。

トライのマージは「重なったノードの個数」だけ時間がかかり、重なったノードは 1 つ消える。ノードを作るのは初期化・一点更新・分割だけなので、マージの総コストは作ったノード数で抑えられ、全体でならし $O((n + q) \mathrm{LOG})$。

## 使い方

```cpp
SortableSegmentTree<MonoidAffine<mint>> seg(keys, vals);  // vector<long long> keys, vector<Affine<mint>> vals
seg.set(i, key, x);     // 位置 i を (key, x) に
seg.prod(l, r)(x);      // op(a[l], ..., a[r-1])
seg.sort_asc(l, r);     // [l, r) をキーの昇順にソート
seg.sort_desc(l, r);    // 降順
auto [key, x] = seg.get(i);
seg.all_prod();
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `SortableSegmentTree<M, LOG = 30>(keys, vals)` | 構築 | $O(n \cdot \mathrm{LOG})$ |
| `void set(int i, long long key, S x)` | 位置 $i$ を (key, x) に | $O(\mathrm{LOG} + \log n)$ |
| `S prod(int l, int r)` | 区間積 | $O(\mathrm{LOG} + \log n)$ |
| `void sort_asc(int l, int r)` / `sort_desc` | 区間をソート | ならし $O(\mathrm{LOG} + \log n)$ |
| `pair<long long, S> get(int i)` | 位置 $i$ の (キー, 値) | $O(\mathrm{LOG} + \log_{64} n)$ |
| `S all_prod()` | 全体の積 | $O(1)$ |

## 注意

- キーは $[0, 2^{\mathrm{LOG}})$ の整数で、**常に全て相異なる** こと。
- メモリは $O(n \cdot \mathrm{LOG})$ 個のトライのノード（消えたノードは再利用する）。$n = q = 10^5$ で手元 100 MB。
