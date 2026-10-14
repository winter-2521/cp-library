---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.hpp
    title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217 (Wavelet Matrix)"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/static_range_lis_query.test.cpp
    title: test/static_range_lis_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/static_range_lis.test.cpp
    title: test/unittest/static_range_lis.test.cpp
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
    \ 3 \"data_structure/wavelet_matrix.hpp\"\n\n// \u30A6\u30A7\u30FC\u30D6\u30EC\
    \u30C3\u30C8\u884C\u5217 (\u9759\u7684\u306A\u6570\u5217\u306B\u5BFE\u3059\u308B\
    \u533A\u9593 k \u756A\u76EE\u30FB\u533A\u9593\u306E\u5024\u306E\u500B\u6570\u306A\
    \u3069)\n// \u5024\u306F\u5185\u90E8\u3067\u5EA7\u6A19\u5727\u7E2E\u3059\u308B\
    \uFF0E\u69CB\u7BC9 O(n log n)\uFF0C\u5404\u30AF\u30A8\u30EA O(log \u03C3) (\u03C3\
    \ \u306F\u5024\u306E\u7A2E\u985E\u6570)\ntemplate <class T>\nstruct WaveletMatrix\
    \ {\n    // 64 bit \u3054\u3068\u306B\uFF0C\u30D3\u30C3\u30C8\u5217\u3068\u305D\
    \u308C\u3088\u308A\u524D\u306E 1 \u306E\u500B\u6570\u3092\u307E\u3068\u3081\u3066\
    \u6301\u3064\n    struct BitVector {\n        struct Block {\n            uint64_t\
    \ bits;\n            int cnt;\n        };\n        vector<Block> b;\n        void\
    \ init(int n) { b.assign((n >> 6) + 1, {0, 0}); }\n        void set(int i) { b[i\
    \ >> 6].bits |= 1ULL << (i & 63); }\n        void build() {\n            for (size_t\
    \ i = 1; i < b.size(); i++) b[i].cnt = b[i - 1].cnt + __builtin_popcountll(b[i\
    \ - 1].bits);\n        }\n        // [0, i) \u306E 1 \u306E\u500B\u6570\n    \
    \    int rank1(int i) const {\n            const Block &x = b[i >> 6];\n     \
    \       return x.cnt + __builtin_popcountll(x.bits & ((1ULL << (i & 63)) - 1));\n\
    \        }\n        bool get(int i) const { return b[i >> 6].bits >> (i & 63)\
    \ & 1; }\n    };\n\n    int n, lg;\n    vector<T> vals;  // \u5EA7\u6A19\u5727\
    \u7E2E\u5F8C\u306E\u5024 (\u6607\u9806)\n    vector<BitVector> bv;\n    vector<int>\
    \ zeros;\n\n    WaveletMatrix(const vector<T> &a = {}) : n(a.size()) {\n     \
    \   vals = a;\n        sort(vals.begin(), vals.end());\n        vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\n        vector<int> cur(n);\n        for (int i =\
    \ 0; i < n; i++) cur[i] = int(lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin());\n\
    \        lg = 1;\n        while ((1 << lg) < (int)vals.size()) lg++;\n       \
    \ bv.resize(lg);\n        zeros.resize(lg);\n        vector<int> nxt(n);\n   \
    \     for (int h = lg - 1; h >= 0; h--) {\n            bv[h].init(n);\n      \
    \      int z = 0;\n            for (int i = 0; i < n; i++) {\n               \
    \ if (cur[i] >> h & 1) bv[h].set(i);\n                else z++;\n            }\n\
    \            bv[h].build();\n            zeros[h] = z;\n            // 0 \u306E\
    \u3082\u306E\u3092\u524D\u306B\uFF0C1 \u306E\u3082\u306E\u3092\u5F8C\u308D\u306B\
    \ (\u5B89\u5B9A)\n            int p0 = 0, p1 = z;\n            for (int i = 0;\
    \ i < n; i++) nxt[(cur[i] >> h & 1) ? p1++ : p0++] = cur[i];\n            swap(cur,\
    \ nxt);\n        }\n    }\n\n    int size() const { return n; }\n\n    // a[i]\n\
    \    T access(int i) const {\n        int res = 0;\n        for (int h = lg -\
    \ 1; h >= 0; h--) {\n            int r1 = bv[h].rank1(i);\n            if (bv[h].get(i))\
    \ res |= 1 << h, i = zeros[h] + r1;\n            else i -= r1;\n        }\n  \
    \      return vals[res];\n    }\n    T operator[](int i) const { return access(i);\
    \ }\n\n    // a[l..r) \u306E\u4E2D\u3067\u5C0F\u3055\u3044\u65B9\u304B\u3089 k\
    \ \u756A\u76EE (0-indexed) \u306E\u5024\uFF0E0 <= k < r - l \u3067\u3042\u308B\
    \u3053\u3068\n    T kth_smallest(int l, int r, int k) const {\n        int res\
    \ = 0;\n        for (int h = lg - 1; h >= 0; h--) {\n            int l1 = bv[h].rank1(l),\
    \ r1 = bv[h].rank1(r);\n            int z = (r - r1) - (l - l1);\n           \
    \ if (k < z) {\n                l -= l1, r -= r1;\n            } else {\n    \
    \            k -= z;\n                res |= 1 << h;\n                l = zeros[h]\
    \ + l1, r = zeros[h] + r1;\n            }\n        }\n        return vals[res];\n\
    \    }\n    // a[l..r) \u306E\u4E2D\u3067\u5927\u304D\u3044\u65B9\u304B\u3089\
    \ k \u756A\u76EE (0-indexed) \u306E\u5024\n    T kth_largest(int l, int r, int\
    \ k) const { return kth_smallest(l, r, r - l - 1 - k); }\n\n    // a[l..r) \u306E\
    \u4E2D\u306E x \u672A\u6E80\u306E\u5024\u306E\u500B\u6570\n    int count_lt(int\
    \ l, int r, const T &x) const { return count_lt_id(l, r, id_lower(x)); }\n   \
    \ // a[l..r) \u306E\u4E2D\u306E x \u4EE5\u4E0B\u306E\u5024\u306E\u500B\u6570\n\
    \    int count_le(int l, int r, const T &x) const { return count_lt_id(l, r, id_upper(x));\
    \ }\n    // a[l..r) \u306E\u4E2D\u306E lo \u4EE5\u4E0A hi \u672A\u6E80\u306E\u5024\
    \u306E\u500B\u6570\n    int count_range(int l, int r, const T &lo, const T &hi)\
    \ const {\n        if (!(lo < hi)) return 0;\n        return count_lt(l, r, hi)\
    \ - count_lt(l, r, lo);\n    }\n    // a[l..r) \u306E\u4E2D\u306E x \u306E\u500B\
    \u6570\n    int count(int l, int r, const T &x) const { return count_le(l, r,\
    \ x) - count_lt(l, r, x); }\n\n    // a[l..r) \u306E\u4E2D\u306E x \u672A\u6E80\
    \u306E\u6700\u5927\u306E\u5024 (\u306A\u3051\u308C\u3070 def)\n    T max_lt(int\
    \ l, int r, const T &x, T def = T(-1)) const {\n        int c = count_lt(l, r,\
    \ x);\n        return c == 0 ? def : kth_smallest(l, r, c - 1);\n    }\n    //\
    \ a[l..r) \u306E\u4E2D\u306E x \u4EE5\u4E0B\u306E\u6700\u5927\u306E\u5024 (\u306A\
    \u3051\u308C\u3070 def)\n    T max_le(int l, int r, const T &x, T def = T(-1))\
    \ const {\n        int c = count_le(l, r, x);\n        return c == 0 ? def : kth_smallest(l,\
    \ r, c - 1);\n    }\n    // a[l..r) \u306E\u4E2D\u306E x \u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u306E\u5024 (\u306A\u3051\u308C\u3070 def)\n    T min_ge(int l, int r,\
    \ const T &x, T def = T(-1)) const {\n        int c = count_lt(l, r, x);\n   \
    \     return c == r - l ? def : kth_smallest(l, r, c);\n    }\n    // a[l..r)\
    \ \u306E\u4E2D\u306E x \u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u5024\
    \ (\u306A\u3051\u308C\u3070 def)\n    T min_gt(int l, int r, const T &x, T def\
    \ = T(-1)) const {\n        int c = count_le(l, r, x);\n        return c == r\
    \ - l ? def : kth_smallest(l, r, c);\n    }\n\n  private:\n    int id_lower(const\
    \ T &x) const { return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin());\
    \ }\n    int id_upper(const T &x) const { return int(upper_bound(vals.begin(),\
    \ vals.end(), x) - vals.begin()); }\n    // a[l..r) \u306E\u4E2D\u3067\u5727\u7E2E\
    \u5F8C\u306E\u5024\u304C v \u672A\u6E80\u306E\u3082\u306E\u306E\u500B\u6570\n\
    \    int count_lt_id(int l, int r, int v) const {\n        if (l >= r) return\
    \ 0;\n        if (v >= (1 << lg)) return r - l;\n        int res = 0;\n      \
    \  for (int h = lg - 1; h >= 0; h--) {\n            int l1 = bv[h].rank1(l), r1\
    \ = bv[h].rank1(r);\n            if (v >> h & 1) {\n                res += (r\
    \ - r1) - (l - l1);\n                l = zeros[h] + l1, r = zeros[h] + r1;\n \
    \           } else {\n                l -= l1, r -= r1;\n            }\n     \
    \   }\n        return res;\n    }\n};\n#line 4 \"data_structure/static_range_lis.hpp\"\
    \n\n// \u533A\u9593 LIS (Static Range LIS Query)\uFF0ESeaweed \u6CD5 (Tiskin)\n\
    // \u6570\u5217 a \u306E\u5404\u533A\u9593 [l, r) \u306E\u6700\u9577\u72ED\u7FA9\
    \u5897\u52A0\u90E8\u5206\u5217\u306E\u9577\u3055\u3092\uFF0C\u524D\u8A08\u7B97\
    \ O(n log^2 n)\u30FB\u30AF\u30A8\u30EA O(log n) \u3067\u7B54\u3048\u308B (\u30AA\
    \u30F3\u30E9\u30A4\u30F3)\n//\n// \u4F4D\u7F6E\u3092\u5217\uFF0C\u5024\u3092\u884C\
    \u3068\u3059\u308B n \xD7 n \u306E\u683C\u5B50\u3067\u300Ca[j] = \u5024 \u306E\
    \u5347\u3060\u3051\u4E00\u81F4\u300D\u3068\u3057\u305F LCS \u306E seaweed (\u3072\
    \u3082) \u3092\u8003\u3048\u308B\uFF0E\n// \u4E0A\u8FBA\u306E\u5217 j \u304B\u3089\
    \u5165\u3063\u305F\u3072\u3082\u304C\u4E0B\u8FBA\u306E\u5217 end[j] \u306B\u51FA\
    \u308B\u3068\u304D\uFF0CLIS(a[l..r)) = (r - l) - #{j \u2208 [l, r) : end[j] <\
    \ r}\n// \u3072\u3082\u5168\u4F53\u306E\u884C\u304D\u5148 (\u7F6E\u63DB) \u306F\
    \u300C\u5024\u3067\u4E0A\u4E0B\u534A\u5206\u306B\u5206\u3051\u3066\u518D\u5E30\
    \ \u2192 unit-Monge \u7A4D (steady ant) \u3067\u5408\u6210\u300D\u3067\u6C42\u3081\
    \u308B\nnamespace seaweed_internal {\n\n// \u4F5C\u696D\u9818\u57DF (\u518D\u5E30\
    \u306E\u4E2D\u3067 LIFO \u306B\u78BA\u4FDD\u30FB\u89E3\u653E\u3059\u308B)\nstruct\
    \ Arena {\n    vector<int> buf;\n    size_t top = 0;\n    int *alloc(size_t n)\
    \ {\n        assert(top + n <= buf.size());  // \u78BA\u4FDD\u3057\u76F4\u3059\
    \u3068\u30DD\u30A4\u30F3\u30BF\u304C\u7121\u52B9\u306B\u306A\u308B\u306E\u3067\
    \uFF0C\u6700\u521D\u306B\u5341\u5206\u78BA\u4FDD\u3057\u3066\u304A\u304F\n   \
    \     int *p = buf.data() + top;\n        top += n;\n        return p;\n    }\n\
    };\n\n// 0-Hecke (sticky) \u7A4D\uFF0Ea \u3092\u5148\u306B\uFF0Cb \u3092\u5F8C\
    \u306B\u9069\u7528\u3057\u305F\u7F6E\u63DB (\u3069\u3061\u3089\u3082\u59CB\u70B9\
    \ \u2192 \u7D42\u70B9) \u3092 res \u306B\u66F8\u304F\uFF0EO(n log n)\n// a, b,\
    \ res \u306F arena \u306E\u5916 (\u307E\u305F\u306F\u547C\u3073\u51FA\u3057\u5074\
    \u304C\u78BA\u4FDD\u6E08\u307F) \u306E\u9818\u57DF\ninline void sticky_product_rec(const\
    \ int *a, const int *b, int *res, int n, Arena &ar) {\n    if (n == 1) {\n   \
    \     res[0] = 0;\n        return;\n    }\n    if (n <= 32) {\n        // \u5C0F\
    \u3055\u3044\u3068\u304D\u306F\u76F4\u63A5: b \u3092\u30D0\u30D6\u30EB\u30BD\u30FC\
    \u30C8\u3067\u96A3\u63A5\u4E92\u63DB\u306E\u5217\u306B\u5206\u89E3\u3057\uFF0C\
    a \u306E\u914D\u7F6E\u306B\u300C\u307E\u3060\u4EA4\u5DEE\u3057\u3066\u3044\u306A\
    \u3051\u308C\u3070\u4EA4\u5DEE\u300D\u3067\u9069\u7528\u3059\u308B\n        int\
    \ at[32], tb[32], word[32 * 31 / 2], len = 0;\n        for (int i = 0; i < n;\
    \ i++) at[a[i]] = i, tb[b[i]] = i;\n        for (int i = 0; i < n; i++)\n    \
    \        for (int p = 0; p + 1 < n - i; p++)\n                if (tb[p] > tb[p\
    \ + 1]) swap(tb[p], tb[p + 1]), word[len++] = p;\n        for (int t = len - 1;\
    \ t >= 0; t--) {\n            int p = word[t];\n            if (at[p] < at[p +\
    \ 1]) swap(at[p], at[p + 1]);\n        }\n        for (int x = 0; x < n; x++)\
    \ res[at[x]] = x;\n        return;\n    }\n    size_t saved = ar.top;\n    int\
    \ h = n / 2;\n    int *rows_lo = ar.alloc(h), *rows_hi = ar.alloc(n - h), *a_lo\
    \ = ar.alloc(h), *a_hi = ar.alloc(n - h);\n    int nl = 0, nh = 0;\n    for (int\
    \ i = 0; i < n; i++) {\n        if (a[i] < h) rows_lo[nl] = i, a_lo[nl++] = a[i];\n\
    \        else rows_hi[nh] = i, a_hi[nh++] = a[i] - h;\n    }\n    // b \u306E\u884C\
    \ [0, h) / [h, n) \u306E\u7D42\u70B9\u3092\u5727\u7E2E\n    int *cid = ar.alloc(n),\
    \ *cols_lo = ar.alloc(h), *cols_hi = ar.alloc(n - h);\n    for (int c = 0; c <\
    \ n; c++) cid[c] = -1;\n    for (int j = 0; j < h; j++) cid[b[j]] = 0;\n    nl\
    \ = nh = 0;\n    for (int c = 0; c < n; c++) {\n        if (cid[c] == 0) cid[c]\
    \ = nl, cols_lo[nl++] = c;\n        else cid[c] = nh, cols_hi[nh++] = c;\n   \
    \ }\n    int *b_lo = ar.alloc(h), *b_hi = ar.alloc(n - h);\n    for (int j = 0;\
    \ j < h; j++) b_lo[j] = cid[b[j]];\n    for (int j = h; j < n; j++) b_hi[j - h]\
    \ = cid[b[j]];\n    int *r_lo = ar.alloc(h), *r_hi = ar.alloc(n - h);\n    sticky_product_rec(a_lo,\
    \ b_lo, r_lo, h, ar);\n    sticky_product_rec(a_hi, b_hi, r_hi, n - h, ar);\n\n\
    \    // \u8D64 (lo) \u3068\u9752 (hi) \u306E\u70B9\u3092\u5408\u308F\u305B\u308B\
    \uFF0E\u5404\u884C\u30FB\u5404\u5217\u306B\u3061\u3087\u3046\u3069 1 \u70B9\n\
    \    int *rowcol = ar.alloc(n), *colrow = ar.alloc(n), *red = ar.alloc(n), *K\
    \ = ar.alloc(n + 1);\n    for (int x = 0; x < h; x++) {\n        int r = rows_lo[x],\
    \ c = cols_lo[r_lo[x]];\n        rowcol[r] = c, colrow[c] = r, red[r] = 1;\n \
    \   }\n    for (int x = 0; x < n - h; x++) {\n        int r = rows_hi[x], c =\
    \ cols_hi[r_hi[x]];\n        rowcol[r] = c, colrow[c] = r, red[r] = 0;\n    }\n\
    \    // \u03B4(i, k) = #{\u9752: \u884C < i, \u5217 < k} - #{\u8D64: \u884C >=\
    \ i, \u5217 >= k}\n    // \u03B4 < 0 \u306E\u9818\u57DF\u3067\u306F\u8D64\uFF0C\
    \u03B4 >= 0 \u306E\u9818\u57DF\u3067\u306F\u9752\u3092\u63A1\u7528\u3057\uFF0C\
    \u5883\u754C\u306E\u5347\u3060\u3051\u8A08\u7B97\u3057\u76F4\u3059\n    // K[i]\
    \ = \u03B4(i, k) >= 0 \u3068\u306A\u308B\u6700\u5C0F\u306E k (\u87FB\u304C\u5883\
    \u754C\u3092 (n, 0) \u304B\u3089 (0, n) \u307E\u3067\u6B69\u3044\u3066\u6C42\u3081\
    \u308B)\n    auto colstep = [&](int i, int k) {  // \u03B4(i, k+1) - \u03B4(i,\
    \ k)\n        int r = colrow[k];\n        return red[r] ? int(r >= i) : int(r\
    \ < i);\n    };\n    {\n        int i = n, k = 0, d = 0;\n        K[n] = 0;\n\
    \        while (i > 0) {\n            int r = i - 1, c = rowcol[r];\n        \
    \    int t = red[r] ? int(c >= k) : int(c < k);  // \u03B4(i, k) - \u03B4(i-1,\
    \ k)\n            if (d - t >= 0) d -= t, K[--i] = k;\n            else d += colstep(i,\
    \ k), k++;\n        }\n    }\n    int *dr = ar.alloc(n + 2), *dr1 = ar.alloc(n\
    \ + 2);\n    for (int r = 0; r < n; r++) {\n        int c = rowcol[r];\n     \
    \   if (red[r] ? c + 1 < K[r + 1] : c >= K[r]) res[r] = c;\n        int lo = std::max(K[r\
    \ + 1] - 1, 0), hi = K[r] - 1;\n        if (lo > hi) continue;\n        // dr[k\
    \ - lo] = \u03B4(r, k)\uFF0Cdr1[k - lo] = \u03B4(r + 1, k) (k \u2208 [lo, hi +\
    \ 1])\n        dr[K[r] - lo] = 0;\n        for (int k = K[r] - 1; k >= lo; k--)\
    \ dr[k - lo] = dr[k + 1 - lo] - colstep(r, k);\n        dr1[K[r + 1] - lo] = 0;\n\
    \        if (lo == K[r + 1] - 1) dr1[0] = -colstep(r + 1, lo);\n        for (int\
    \ k = K[r + 1]; k <= hi; k++) dr1[k + 1 - lo] = dr1[k - lo] + colstep(r + 1, k);\n\
    \        auto m = [](int x) { return x < 0 ? x : 0; };\n        for (int cc =\
    \ lo; cc <= hi; cc++) {\n            int v = int(!red[r] && c == cc) + m(dr[cc\
    \ + 1 - lo]) - m(dr1[cc + 1 - lo]) - m(dr[cc - lo]) + m(dr1[cc - lo]);\n     \
    \       if (v) res[r] = cc;\n        }\n    }\n    ar.top = saved;\n}\n\ninline\
    \ vector<int> sticky_product(const vector<int> &a, const vector<int> &b) {\n \
    \   int n = a.size();\n    vector<int> res(n);\n    if (n == 0) return res;\n\
    \    Arena ar;\n    ar.buf.resize(40 * (size_t)n + 256);  // 1 \u6BB5\u3067\u7D04\
    \ 17n\uFF0C\u518D\u5E30\u5168\u4F53\u3067\u7D04 34n\n    sticky_product_rec(a.data(),\
    \ b.data(), res.data(), n, ar);\n    return res;\n}\n\n// \u9806\u5217 q (\u5217\
    \ j \u306E\u5024 q[j]) \u306E seaweed \u306E\u884C\u304D\u5148 (\u5927\u304D\u3055\
    \ 2m) \u3092 out \u306B\u66F8\u304F\n// \u59CB\u70B9: \u5DE6\u8FBA\u306E\u884C\
    \ i \u306F m-1-i\uFF0C\u4E0A\u8FBA\u306E\u5217 j \u306F m+j\uFF0E\u7D42\u70B9\
    : \u4E0B\u8FBA\u306E\u5217 j \u306F j\uFF0C\u53F3\u8FBA\u306E\u884C i \u306F m+(m-1-i)\n\
    inline void seaweed_rec(const int *q, int m, int *out, Arena &ar) {\n    if (m\
    \ == 1) {  // \u4E00\u81F4\u3059\u308B\u5347: \u3072\u3082\u306F\u4EA4\u5DEE\u3057\
    \u306A\u3044\n        out[0] = 0, out[1] = 1;\n        return;\n    }\n    size_t\
    \ saved = ar.top;\n    int h = m / 2;\n    int *cols_lo = ar.alloc(h), *cols_hi\
    \ = ar.alloc(m - h), *q_lo = ar.alloc(h), *q_hi = ar.alloc(m - h);\n    int nl\
    \ = 0, nh = 0;\n    for (int j = 0; j < m; j++) {\n        if (q[j] < h) cols_lo[nl]\
    \ = j, q_lo[nl++] = q[j];\n        else cols_hi[nh] = j, q_hi[nh++] = q[j] - h;\n\
    \    }\n    int *k_lo = ar.alloc(2 * h), *k_hi = ar.alloc(2 * (m - h));\n    seaweed_rec(q_lo,\
    \ h, k_lo, ar);\n    seaweed_rec(q_hi, m - h, k_hi, ar);\n    // \u5727\u7E2E\u3057\
    \u305F\u5217\u306E\u30D6\u30ED\u30C3\u30AF\u3092 m \u5217\u306B\u5E83\u3052\u308B\
    \ (\u4E00\u81F4\u306E\u306A\u3044\u5217\u306E\u3072\u3082\u306F\u307E\u3063\u3059\
    \u3050\u4E0B\u306B\u629C\u3051\u308B)\n    // \u4E0A\u306E\u30D6\u30ED\u30C3\u30AF\
    \ (\u5024 < h) \u306F\u4F4D\u7F6E [m-h, 2m) \u306B\uFF0C\u4E0B\u306E\u30D6\u30ED\
    \u30C3\u30AF\u306F [0, 2m-h) \u306B\u4F5C\u7528\u3059\u308B\n    int *top = ar.alloc(2\
    \ * m), *bot = ar.alloc(2 * m), *used = ar.alloc(m);\n    auto extend = [&](const\
    \ int *kk, const int *cols, int c, int rows, int *e) {\n        auto map_end =\
    \ [&](int x) { return x < c ? cols[x] : m + (x - c); };\n        for (int t =\
    \ 0; t < rows; t++) e[t] = map_end(kk[t]);\n        for (int j = 0; j < m; j++)\
    \ used[j] = 0;\n        for (int x = 0; x < c; x++) e[rows + cols[x]] = map_end(kk[rows\
    \ + x]), used[cols[x]] = 1;\n        for (int j = 0; j < m; j++) if (!used[j])\
    \ e[rows + j] = j;\n    };\n    for (int x = 0; x < m - h; x++) top[x] = x;\n\
    \    extend(k_lo, cols_lo, h, h, top + (m - h));\n    for (int y = m - h; y <\
    \ 2 * m; y++) top[y] += m - h;\n    extend(k_hi, cols_hi, m - h, m - h, bot);\n\
    \    for (int x = 2 * m - h; x < 2 * m; x++) bot[x] = x;\n    sticky_product_rec(top,\
    \ bot, out, 2 * m, ar);\n    ar.top = saved;\n}\n\ninline vector<int> seaweed(const\
    \ vector<int> &q) {\n    int m = q.size();\n    vector<int> res(2 * m);\n    if\
    \ (m == 0) return res;\n    Arena ar;\n    ar.buf.resize(100 * (size_t)m + 256);\
    \  // seaweed \u306E\u5C40\u6240 \u7D04 24m + \u6700\u4E0A\u6BB5\u306E\u7A4D \u7D04\
    \ 68m\n    seaweed_rec(q.data(), m, res.data(), ar);\n    return res;\n}\n\n}\
    \  // namespace seaweed_internal\n\nstruct StaticRangeLIS {\n    int n;\n    vector<int>\
    \ end_col;  // end_col[j]: \u4E0A\u8FBA\u306E\u5217 j \u304B\u3089\u5165\u3063\
    \u305F\u3072\u3082\u306E\u7D42\u70B9 (n \u4EE5\u4E0A\u306A\u3089\u53F3\u8FBA)\n\
    \    WaveletMatrix<int> wm;\n\n    // a \u306F\u4EFB\u610F\u306E\u6570\u5217 (\u72ED\
    \u7FA9\u5897\u52A0\u3067\u6570\u3048\u308B)\n    template <class T>\n    StaticRangeLIS(const\
    \ vector<T> &a) : n(a.size()) {\n        if (n == 0) return;\n        // \u5024\
    \u306E\u6607\u9806\uFF0C\u540C\u3058\u5024\u306F\u4F4D\u7F6E\u306E\u964D\u9806\
    \u306B\u756A\u53F7\u3092\u632F\u3063\u3066\u9806\u5217\u306B\u3059\u308B\n   \
    \     vector<int> ord(n), q(n);\n        iota(ord.begin(), ord.end(), 0);\n  \
    \      sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j] ||\
    \ (!(a[j] < a[i]) && i > j); });\n        for (int k = 0; k < n; k++) q[ord[k]]\
    \ = k;\n        vector<int> k = seaweed_internal::seaweed(q);\n        end_col.resize(n);\n\
    \        for (int j = 0; j < n; j++) end_col[j] = k[n + j];\n        wm = WaveletMatrix<int>(end_col);\n\
    \    }\n\n    // a[l..r) \u306E LIS \u306E\u9577\u3055\n    int query(int l, int\
    \ r) const {\n        if (l >= r) return 0;\n        return (r - l) - wm.count_lt(l,\
    \ r, r);\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"wavelet_matrix.hpp\"\
    \n\n// \u533A\u9593 LIS (Static Range LIS Query)\uFF0ESeaweed \u6CD5 (Tiskin)\n\
    // \u6570\u5217 a \u306E\u5404\u533A\u9593 [l, r) \u306E\u6700\u9577\u72ED\u7FA9\
    \u5897\u52A0\u90E8\u5206\u5217\u306E\u9577\u3055\u3092\uFF0C\u524D\u8A08\u7B97\
    \ O(n log^2 n)\u30FB\u30AF\u30A8\u30EA O(log n) \u3067\u7B54\u3048\u308B (\u30AA\
    \u30F3\u30E9\u30A4\u30F3)\n//\n// \u4F4D\u7F6E\u3092\u5217\uFF0C\u5024\u3092\u884C\
    \u3068\u3059\u308B n \xD7 n \u306E\u683C\u5B50\u3067\u300Ca[j] = \u5024 \u306E\
    \u5347\u3060\u3051\u4E00\u81F4\u300D\u3068\u3057\u305F LCS \u306E seaweed (\u3072\
    \u3082) \u3092\u8003\u3048\u308B\uFF0E\n// \u4E0A\u8FBA\u306E\u5217 j \u304B\u3089\
    \u5165\u3063\u305F\u3072\u3082\u304C\u4E0B\u8FBA\u306E\u5217 end[j] \u306B\u51FA\
    \u308B\u3068\u304D\uFF0CLIS(a[l..r)) = (r - l) - #{j \u2208 [l, r) : end[j] <\
    \ r}\n// \u3072\u3082\u5168\u4F53\u306E\u884C\u304D\u5148 (\u7F6E\u63DB) \u306F\
    \u300C\u5024\u3067\u4E0A\u4E0B\u534A\u5206\u306B\u5206\u3051\u3066\u518D\u5E30\
    \ \u2192 unit-Monge \u7A4D (steady ant) \u3067\u5408\u6210\u300D\u3067\u6C42\u3081\
    \u308B\nnamespace seaweed_internal {\n\n// \u4F5C\u696D\u9818\u57DF (\u518D\u5E30\
    \u306E\u4E2D\u3067 LIFO \u306B\u78BA\u4FDD\u30FB\u89E3\u653E\u3059\u308B)\nstruct\
    \ Arena {\n    vector<int> buf;\n    size_t top = 0;\n    int *alloc(size_t n)\
    \ {\n        assert(top + n <= buf.size());  // \u78BA\u4FDD\u3057\u76F4\u3059\
    \u3068\u30DD\u30A4\u30F3\u30BF\u304C\u7121\u52B9\u306B\u306A\u308B\u306E\u3067\
    \uFF0C\u6700\u521D\u306B\u5341\u5206\u78BA\u4FDD\u3057\u3066\u304A\u304F\n   \
    \     int *p = buf.data() + top;\n        top += n;\n        return p;\n    }\n\
    };\n\n// 0-Hecke (sticky) \u7A4D\uFF0Ea \u3092\u5148\u306B\uFF0Cb \u3092\u5F8C\
    \u306B\u9069\u7528\u3057\u305F\u7F6E\u63DB (\u3069\u3061\u3089\u3082\u59CB\u70B9\
    \ \u2192 \u7D42\u70B9) \u3092 res \u306B\u66F8\u304F\uFF0EO(n log n)\n// a, b,\
    \ res \u306F arena \u306E\u5916 (\u307E\u305F\u306F\u547C\u3073\u51FA\u3057\u5074\
    \u304C\u78BA\u4FDD\u6E08\u307F) \u306E\u9818\u57DF\ninline void sticky_product_rec(const\
    \ int *a, const int *b, int *res, int n, Arena &ar) {\n    if (n == 1) {\n   \
    \     res[0] = 0;\n        return;\n    }\n    if (n <= 32) {\n        // \u5C0F\
    \u3055\u3044\u3068\u304D\u306F\u76F4\u63A5: b \u3092\u30D0\u30D6\u30EB\u30BD\u30FC\
    \u30C8\u3067\u96A3\u63A5\u4E92\u63DB\u306E\u5217\u306B\u5206\u89E3\u3057\uFF0C\
    a \u306E\u914D\u7F6E\u306B\u300C\u307E\u3060\u4EA4\u5DEE\u3057\u3066\u3044\u306A\
    \u3051\u308C\u3070\u4EA4\u5DEE\u300D\u3067\u9069\u7528\u3059\u308B\n        int\
    \ at[32], tb[32], word[32 * 31 / 2], len = 0;\n        for (int i = 0; i < n;\
    \ i++) at[a[i]] = i, tb[b[i]] = i;\n        for (int i = 0; i < n; i++)\n    \
    \        for (int p = 0; p + 1 < n - i; p++)\n                if (tb[p] > tb[p\
    \ + 1]) swap(tb[p], tb[p + 1]), word[len++] = p;\n        for (int t = len - 1;\
    \ t >= 0; t--) {\n            int p = word[t];\n            if (at[p] < at[p +\
    \ 1]) swap(at[p], at[p + 1]);\n        }\n        for (int x = 0; x < n; x++)\
    \ res[at[x]] = x;\n        return;\n    }\n    size_t saved = ar.top;\n    int\
    \ h = n / 2;\n    int *rows_lo = ar.alloc(h), *rows_hi = ar.alloc(n - h), *a_lo\
    \ = ar.alloc(h), *a_hi = ar.alloc(n - h);\n    int nl = 0, nh = 0;\n    for (int\
    \ i = 0; i < n; i++) {\n        if (a[i] < h) rows_lo[nl] = i, a_lo[nl++] = a[i];\n\
    \        else rows_hi[nh] = i, a_hi[nh++] = a[i] - h;\n    }\n    // b \u306E\u884C\
    \ [0, h) / [h, n) \u306E\u7D42\u70B9\u3092\u5727\u7E2E\n    int *cid = ar.alloc(n),\
    \ *cols_lo = ar.alloc(h), *cols_hi = ar.alloc(n - h);\n    for (int c = 0; c <\
    \ n; c++) cid[c] = -1;\n    for (int j = 0; j < h; j++) cid[b[j]] = 0;\n    nl\
    \ = nh = 0;\n    for (int c = 0; c < n; c++) {\n        if (cid[c] == 0) cid[c]\
    \ = nl, cols_lo[nl++] = c;\n        else cid[c] = nh, cols_hi[nh++] = c;\n   \
    \ }\n    int *b_lo = ar.alloc(h), *b_hi = ar.alloc(n - h);\n    for (int j = 0;\
    \ j < h; j++) b_lo[j] = cid[b[j]];\n    for (int j = h; j < n; j++) b_hi[j - h]\
    \ = cid[b[j]];\n    int *r_lo = ar.alloc(h), *r_hi = ar.alloc(n - h);\n    sticky_product_rec(a_lo,\
    \ b_lo, r_lo, h, ar);\n    sticky_product_rec(a_hi, b_hi, r_hi, n - h, ar);\n\n\
    \    // \u8D64 (lo) \u3068\u9752 (hi) \u306E\u70B9\u3092\u5408\u308F\u305B\u308B\
    \uFF0E\u5404\u884C\u30FB\u5404\u5217\u306B\u3061\u3087\u3046\u3069 1 \u70B9\n\
    \    int *rowcol = ar.alloc(n), *colrow = ar.alloc(n), *red = ar.alloc(n), *K\
    \ = ar.alloc(n + 1);\n    for (int x = 0; x < h; x++) {\n        int r = rows_lo[x],\
    \ c = cols_lo[r_lo[x]];\n        rowcol[r] = c, colrow[c] = r, red[r] = 1;\n \
    \   }\n    for (int x = 0; x < n - h; x++) {\n        int r = rows_hi[x], c =\
    \ cols_hi[r_hi[x]];\n        rowcol[r] = c, colrow[c] = r, red[r] = 0;\n    }\n\
    \    // \u03B4(i, k) = #{\u9752: \u884C < i, \u5217 < k} - #{\u8D64: \u884C >=\
    \ i, \u5217 >= k}\n    // \u03B4 < 0 \u306E\u9818\u57DF\u3067\u306F\u8D64\uFF0C\
    \u03B4 >= 0 \u306E\u9818\u57DF\u3067\u306F\u9752\u3092\u63A1\u7528\u3057\uFF0C\
    \u5883\u754C\u306E\u5347\u3060\u3051\u8A08\u7B97\u3057\u76F4\u3059\n    // K[i]\
    \ = \u03B4(i, k) >= 0 \u3068\u306A\u308B\u6700\u5C0F\u306E k (\u87FB\u304C\u5883\
    \u754C\u3092 (n, 0) \u304B\u3089 (0, n) \u307E\u3067\u6B69\u3044\u3066\u6C42\u3081\
    \u308B)\n    auto colstep = [&](int i, int k) {  // \u03B4(i, k+1) - \u03B4(i,\
    \ k)\n        int r = colrow[k];\n        return red[r] ? int(r >= i) : int(r\
    \ < i);\n    };\n    {\n        int i = n, k = 0, d = 0;\n        K[n] = 0;\n\
    \        while (i > 0) {\n            int r = i - 1, c = rowcol[r];\n        \
    \    int t = red[r] ? int(c >= k) : int(c < k);  // \u03B4(i, k) - \u03B4(i-1,\
    \ k)\n            if (d - t >= 0) d -= t, K[--i] = k;\n            else d += colstep(i,\
    \ k), k++;\n        }\n    }\n    int *dr = ar.alloc(n + 2), *dr1 = ar.alloc(n\
    \ + 2);\n    for (int r = 0; r < n; r++) {\n        int c = rowcol[r];\n     \
    \   if (red[r] ? c + 1 < K[r + 1] : c >= K[r]) res[r] = c;\n        int lo = std::max(K[r\
    \ + 1] - 1, 0), hi = K[r] - 1;\n        if (lo > hi) continue;\n        // dr[k\
    \ - lo] = \u03B4(r, k)\uFF0Cdr1[k - lo] = \u03B4(r + 1, k) (k \u2208 [lo, hi +\
    \ 1])\n        dr[K[r] - lo] = 0;\n        for (int k = K[r] - 1; k >= lo; k--)\
    \ dr[k - lo] = dr[k + 1 - lo] - colstep(r, k);\n        dr1[K[r + 1] - lo] = 0;\n\
    \        if (lo == K[r + 1] - 1) dr1[0] = -colstep(r + 1, lo);\n        for (int\
    \ k = K[r + 1]; k <= hi; k++) dr1[k + 1 - lo] = dr1[k - lo] + colstep(r + 1, k);\n\
    \        auto m = [](int x) { return x < 0 ? x : 0; };\n        for (int cc =\
    \ lo; cc <= hi; cc++) {\n            int v = int(!red[r] && c == cc) + m(dr[cc\
    \ + 1 - lo]) - m(dr1[cc + 1 - lo]) - m(dr[cc - lo]) + m(dr1[cc - lo]);\n     \
    \       if (v) res[r] = cc;\n        }\n    }\n    ar.top = saved;\n}\n\ninline\
    \ vector<int> sticky_product(const vector<int> &a, const vector<int> &b) {\n \
    \   int n = a.size();\n    vector<int> res(n);\n    if (n == 0) return res;\n\
    \    Arena ar;\n    ar.buf.resize(40 * (size_t)n + 256);  // 1 \u6BB5\u3067\u7D04\
    \ 17n\uFF0C\u518D\u5E30\u5168\u4F53\u3067\u7D04 34n\n    sticky_product_rec(a.data(),\
    \ b.data(), res.data(), n, ar);\n    return res;\n}\n\n// \u9806\u5217 q (\u5217\
    \ j \u306E\u5024 q[j]) \u306E seaweed \u306E\u884C\u304D\u5148 (\u5927\u304D\u3055\
    \ 2m) \u3092 out \u306B\u66F8\u304F\n// \u59CB\u70B9: \u5DE6\u8FBA\u306E\u884C\
    \ i \u306F m-1-i\uFF0C\u4E0A\u8FBA\u306E\u5217 j \u306F m+j\uFF0E\u7D42\u70B9\
    : \u4E0B\u8FBA\u306E\u5217 j \u306F j\uFF0C\u53F3\u8FBA\u306E\u884C i \u306F m+(m-1-i)\n\
    inline void seaweed_rec(const int *q, int m, int *out, Arena &ar) {\n    if (m\
    \ == 1) {  // \u4E00\u81F4\u3059\u308B\u5347: \u3072\u3082\u306F\u4EA4\u5DEE\u3057\
    \u306A\u3044\n        out[0] = 0, out[1] = 1;\n        return;\n    }\n    size_t\
    \ saved = ar.top;\n    int h = m / 2;\n    int *cols_lo = ar.alloc(h), *cols_hi\
    \ = ar.alloc(m - h), *q_lo = ar.alloc(h), *q_hi = ar.alloc(m - h);\n    int nl\
    \ = 0, nh = 0;\n    for (int j = 0; j < m; j++) {\n        if (q[j] < h) cols_lo[nl]\
    \ = j, q_lo[nl++] = q[j];\n        else cols_hi[nh] = j, q_hi[nh++] = q[j] - h;\n\
    \    }\n    int *k_lo = ar.alloc(2 * h), *k_hi = ar.alloc(2 * (m - h));\n    seaweed_rec(q_lo,\
    \ h, k_lo, ar);\n    seaweed_rec(q_hi, m - h, k_hi, ar);\n    // \u5727\u7E2E\u3057\
    \u305F\u5217\u306E\u30D6\u30ED\u30C3\u30AF\u3092 m \u5217\u306B\u5E83\u3052\u308B\
    \ (\u4E00\u81F4\u306E\u306A\u3044\u5217\u306E\u3072\u3082\u306F\u307E\u3063\u3059\
    \u3050\u4E0B\u306B\u629C\u3051\u308B)\n    // \u4E0A\u306E\u30D6\u30ED\u30C3\u30AF\
    \ (\u5024 < h) \u306F\u4F4D\u7F6E [m-h, 2m) \u306B\uFF0C\u4E0B\u306E\u30D6\u30ED\
    \u30C3\u30AF\u306F [0, 2m-h) \u306B\u4F5C\u7528\u3059\u308B\n    int *top = ar.alloc(2\
    \ * m), *bot = ar.alloc(2 * m), *used = ar.alloc(m);\n    auto extend = [&](const\
    \ int *kk, const int *cols, int c, int rows, int *e) {\n        auto map_end =\
    \ [&](int x) { return x < c ? cols[x] : m + (x - c); };\n        for (int t =\
    \ 0; t < rows; t++) e[t] = map_end(kk[t]);\n        for (int j = 0; j < m; j++)\
    \ used[j] = 0;\n        for (int x = 0; x < c; x++) e[rows + cols[x]] = map_end(kk[rows\
    \ + x]), used[cols[x]] = 1;\n        for (int j = 0; j < m; j++) if (!used[j])\
    \ e[rows + j] = j;\n    };\n    for (int x = 0; x < m - h; x++) top[x] = x;\n\
    \    extend(k_lo, cols_lo, h, h, top + (m - h));\n    for (int y = m - h; y <\
    \ 2 * m; y++) top[y] += m - h;\n    extend(k_hi, cols_hi, m - h, m - h, bot);\n\
    \    for (int x = 2 * m - h; x < 2 * m; x++) bot[x] = x;\n    sticky_product_rec(top,\
    \ bot, out, 2 * m, ar);\n    ar.top = saved;\n}\n\ninline vector<int> seaweed(const\
    \ vector<int> &q) {\n    int m = q.size();\n    vector<int> res(2 * m);\n    if\
    \ (m == 0) return res;\n    Arena ar;\n    ar.buf.resize(100 * (size_t)m + 256);\
    \  // seaweed \u306E\u5C40\u6240 \u7D04 24m + \u6700\u4E0A\u6BB5\u306E\u7A4D \u7D04\
    \ 68m\n    seaweed_rec(q.data(), m, res.data(), ar);\n    return res;\n}\n\n}\
    \  // namespace seaweed_internal\n\nstruct StaticRangeLIS {\n    int n;\n    vector<int>\
    \ end_col;  // end_col[j]: \u4E0A\u8FBA\u306E\u5217 j \u304B\u3089\u5165\u3063\
    \u305F\u3072\u3082\u306E\u7D42\u70B9 (n \u4EE5\u4E0A\u306A\u3089\u53F3\u8FBA)\n\
    \    WaveletMatrix<int> wm;\n\n    // a \u306F\u4EFB\u610F\u306E\u6570\u5217 (\u72ED\
    \u7FA9\u5897\u52A0\u3067\u6570\u3048\u308B)\n    template <class T>\n    StaticRangeLIS(const\
    \ vector<T> &a) : n(a.size()) {\n        if (n == 0) return;\n        // \u5024\
    \u306E\u6607\u9806\uFF0C\u540C\u3058\u5024\u306F\u4F4D\u7F6E\u306E\u964D\u9806\
    \u306B\u756A\u53F7\u3092\u632F\u3063\u3066\u9806\u5217\u306B\u3059\u308B\n   \
    \     vector<int> ord(n), q(n);\n        iota(ord.begin(), ord.end(), 0);\n  \
    \      sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j] ||\
    \ (!(a[j] < a[i]) && i > j); });\n        for (int k = 0; k < n; k++) q[ord[k]]\
    \ = k;\n        vector<int> k = seaweed_internal::seaweed(q);\n        end_col.resize(n);\n\
    \        for (int j = 0; j < n; j++) end_col[j] = k[n + j];\n        wm = WaveletMatrix<int>(end_col);\n\
    \    }\n\n    // a[l..r) \u306E LIS \u306E\u9577\u3055\n    int query(int l, int\
    \ r) const {\n        if (l >= r) return 0;\n        return (r - l) - wm.count_lt(l,\
    \ r, r);\n    }\n};\n"
  dependsOn:
  - template.hpp
  - data_structure/wavelet_matrix.hpp
  isVerificationFile: false
  path: data_structure/static_range_lis.hpp
  requiredBy: []
  timestamp: '2026-10-14 23:42:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/static_range_lis.test.cpp
  - test/static_range_lis_query.test.cpp
documentation_of: data_structure/static_range_lis.hpp
layout: document
title: "\u533A\u9593 LIS (Static Range LIS Query, Seaweed \u6CD5)"
---

## 概要

静的な数列 $a$ について、区間 $[l, r)$ の **最長狭義増加部分列（LIS）の長さ** を、前計算 $O(n \log^2 n)$・クエリ $O(\log n)$ で答える（**オンライン**）。Tiskin の Seaweed 法。

- 列を位置、行を値とする $n \times n$ の格子で、$a_j$ = 行 のマスだけ「一致」とする LCS を考える。各マスで 2 本のひも（seaweed）が「一致なら交差しない、不一致なら **まだ交差していなければ** 交差する」というルールで流れる。
- 上辺の列 $j$ から入ったひもが下辺の列 $\mathrm{end}_j$ に出るとき、$\mathrm{LIS}(a[l..r)) = (r - l) - \#\{j \in [l, r) : \mathrm{end}_j < r\}$。これはウェーブレット行列で $O(\log n)$。
- ひもの行き先（置換）は、値で上下半分に分けて再帰的に求め、2 つを **unit-Monge 積（steady ant 法、$O(n \log n)$）** で合成する。全体 $O(n \log^2 n)$。

## 使い方

```cpp
StaticRangeLIS lis(a);   // vector<T> a (順列でなくてもよい．狭義増加で数える)
lis.query(l, r);         // a[l..r) の LIS の長さ
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `StaticRangeLIS(const vector<T> &a)` | 構築 | $O(n \log^2 n)$ |
| `int query(int l, int r)` | 区間 LIS の長さ（$l \ge r$ なら 0） | $O(\log n)$ |

内部の `seaweed_internal::sticky_product(a, b)` は、置換（始点 → 終点）$a$ を先に、$b$ を後に適用した 0-Hecke 積（ひもが 2 回交差しない合成）を返す。

## 注意

- 同じ値は「位置が後ろのものほど小さい」とみなして順列にしてから計算する（狭義増加になる）。広義増加で数えたいときは、同じ値を位置の昇順に小さくした順列を自分で作って渡す。
- 前計算の作業領域として約 $100n$ 個の int を一時的に使う。
