---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/bipartite_edge_coloring.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u8FBA\u5F69\u8272 (Bipartite Edge\
      \ Coloring)"
  - icon: ':question:'
    path: graph/bipartite_matching.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0 (Bipartite Matching)"
  - icon: ':question:'
    path: graph/csr.hpp
    title: "CSR (\u96A3\u63A5\u30EA\u30B9\u30C8\u3092 1 \u672C\u306E\u914D\u5217\u3067\
      \u6301\u3064)"
  - icon: ':question:'
    path: graph/directed_mst.hpp
    title: "\u6700\u5C0F\u6709\u5411\u5168\u57DF\u6728 (Directed MST)"
  - icon: ':x:'
    path: graph/general_matching.hpp
    title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0 (Edmonds \u306E\u82B1\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0)"
  - icon: ':x:'
    path: graph/general_weighted_matching.hpp
    title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u91CD\u307F\u30DE\u30C3\
      \u30C1\u30F3\u30B0"
  - icon: ':question:'
    path: graph/hungarian.hpp
    title: "\u5272\u5F53\u554F\u984C (Hungarian \u6CD5)"
  - icon: ':x:'
    path: graph/min_cost_b_flow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528 b-flow (Min Cost b-Flow)"
  - icon: ':x:'
    path: graph/minimum_spanning_tree.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728 (Kruskal)"
  - icon: ':x:'
    path: graph/st_numbering.hpp
    title: "st \u756A\u53F7\u4ED8\u3051 (st-Numbering)"
  - icon: ':question:'
    path: io/fastio.hpp
    title: "\u9AD8\u901F\u5165\u51FA\u529B (Fast I/O)"
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/unittest/graph_optimization.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"template.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#if __has_include(<atcoder/all>)\n#include\
    \ <atcoder/all>\nusing namespace atcoder;\n#endif\n// QCfium\u6CD5\u3092\u4F7F\
    \u3046\u6642\u306F\u30B3\u30E1\u30F3\u30C8\u30A2\u30A6\u30C8\u3092\u5916\u3059\
    \n/*/\n#pragma GCC optimize(\"Ofast,unroll-loops,no-stack-protector,fast-math\"\
    )\n#pragma GCC target(\"avx2,bmi,bmi2,lzcnt,popcnt\")\n#pragma GCC target(\"avx,avx2,fma\"\
    )\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma\"\
    )\n//*/\n#define rep(i,n) for(int i=0;i<n;i++)\n#define Rep(i,a,b) for(int i=a;i<b;i++)\n\
    #define ALL(x) (x).begin(),(x).end()\n#define dbgv(x); for(auto now : x) cout\
    \ << now << \" \"; cout << endl;\n//using P = pair<int,int>;\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\ntypedef pair<int, int> pii;\ntypedef\
    \ pair<ll, ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line\
    \ 3 \"io/fastio.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\n// \u9AD8\
    \u901F\u5165\u51FA\u529B\n// fin >> a >> b;  fout << a + b << '\\n';  \u306E\u3088\
    \u3046\u306B cin / cout \u3068\u540C\u3058\u611F\u899A\u3067\u4F7F\u3046\n// cin\
    \ / cout / scanf / printf \u3068\u6DF7\u305C\u3066\u4F7F\u3063\u3066\u306F\u3044\
    \u3051\u306A\u3044\n// \u5165\u529B\u306F\u30D6\u30ED\u30C3\u30AF\u5358\u4F4D\u3067\
    \u8AAD\u3080\u306E\u3067\uFF0C\u30A4\u30F3\u30BF\u30E9\u30AF\u30C6\u30A3\u30D6\
    \u554F\u984C\u306B\u306F\u4F7F\u3048\u306A\u3044\n\nnamespace fastio {\n\n// \u5165\
    \u51FA\u529B\u30D0\u30C3\u30D5\u30A1\u306E\u5927\u304D\u3055\nconstexpr size_t\
    \ BUF_SIZE = 1 << 17;\n\n// 0000 ~ 9999 \u306E 4 \u6841\u306E\u6587\u5B57\u5217\
    \u3092\u524D\u8A08\u7B97\u3057\u3066\u304A\u304F\u8868\nstruct DigitTable {\n\
    \    char d[10000][4];\n    constexpr DigitTable() : d() {\n        for (int i\
    \ = 0; i < 10000; i++) {\n            int x = i;\n            for (int j = 3;\
    \ j >= 0; j--) d[i][j] = char('0' + x % 10), x /= 10;\n        }\n    }\n};\n\
    inline constexpr DigitTable digit_table{};\n\n// __int128 \u306F -std=c++17 (gnu\
    \ \u62E1\u5F35\u306A\u3057) \u3060\u3068 is_integral \u306B\u306A\u3089\u306A\u3044\
    \u306E\u3067\u81EA\u524D\u3067\u5224\u5B9A\u3059\u308B\ntemplate <class T> struct\
    \ is_int128 : false_type {};\ntemplate <> struct is_int128<__int128> : true_type\
    \ {};\ntemplate <> struct is_int128<unsigned __int128> : true_type {};\n\n// \u7B26\
    \u53F7\u4ED8\u304D\u6574\u6570\u578B\u306B\u5BFE\u5FDC\u3059\u308B\u7B26\u53F7\
    \u306A\u3057\u6574\u6570\u578B\ntemplate <class T> struct unsigned_of { using\
    \ type = make_unsigned_t<T>; };\ntemplate <> struct unsigned_of<__int128> { using\
    \ type = unsigned __int128; };\ntemplate <class T> using unsigned_of_t = typename\
    \ unsigned_of<T>::type;\n\ntemplate <class T> constexpr bool is_integer_v = (is_integral_v<T>\
    \ && !is_same_v<T, bool> && !is_same_v<T, char>) || is_int128<T>::value;\n// ModInt\
    \ \u306E\u3088\u3046\u306B val() \u3067\u6574\u6570\u5024\u3092\u8FD4\u3057\uFF0C\
    \u6574\u6570\u304B\u3089\u69CB\u7BC9\u3067\u304D\u308B\u578B\ntemplate <class\
    \ T, class = void> struct has_val : false_type {};\ntemplate <class T> struct\
    \ has_val<T, void_t<decltype(declval<const T &>().val())>> : true_type {};\n\n\
    template <class T> constexpr bool is_signed_integer_v = is_same_v<T, __int128>\
    \ || (is_integral_v<T> && is_signed_v<T>);\n\nstruct Reader {\n    // \u6570\u5024\
    \u3092\u8AAD\u3080\u524D\u306B\u5E38\u306B TOKEN_MARGIN \u6587\u5B57\u4EE5\u4E0A\
    \u304C buf \u306B\u6B8B\u3063\u3066\u3044\u308B\u3088\u3046\u306B\u3057\u3066\uFF0C\
    \u6570\u5024\u306E\u8AAD\u307F\u8FBC\u307F\u4E2D\u306E\u5883\u754C\u30C1\u30A7\
    \u30C3\u30AF\u3092\u7701\u304F\n    static constexpr size_t TOKEN_MARGIN = 64;\n\
    \    char buf[BUF_SIZE + TOKEN_MARGIN + 8];\n    size_t pos = 0, len = 0;\n  \
    \  bool eof = false;\n\n    // \u672A\u8AAD\u90E8\u5206\u3092\u5148\u982D\u306B\
    \u5BC4\u305B\u3066\u304B\u3089\u8AAD\u307F\u8DB3\u3059\n    void refill() {\n\
    \        size_t rem = len - pos;\n        memmove(buf, buf + pos, rem);\n    \
    \    pos = 0, len = rem;\n        while (!eof && len < TOKEN_MARGIN) {\n     \
    \       size_t r = fread(buf + len, 1, BUF_SIZE - len, stdin);\n            if\
    \ (r == 0) eof = true;\n            len += r;\n        }\n        // 8 \u30D0\u30A4\
    \u30C8\u5358\u4F4D\u3067\u6570\u5B57\u3092\u8AAD\u3080\u3068\u304D\u306B\u672B\
    \u5C3E\u306E\u5148\u3092\u8AAD\u3093\u3067\u3082\u6B62\u307E\u308B\u3088\u3046\
    \u756A\u5175\u3092\u7F6E\u304F\n        memset(buf + len, 0, 8);\n    }\n\n  \
    \  // \u7A7A\u767D\u3092\u8AAD\u307F\u98DB\u3070\u3059\uFF0E\u8AAD\u307F\u7D42\
    \u308F\u3063\u305F\u5F8C\u306F TOKEN_MARGIN \u6587\u5B57\u4EE5\u4E0A(\u307E\u305F\
    \u306F EOF \u307E\u3067)\u304C\u6B8B\u3063\u3066\u3044\u308B\n    void skip_space()\
    \ {\n        while (true) {\n            if (len - pos < TOKEN_MARGIN && !eof)\
    \ refill();\n            while (pos < len && (unsigned char)buf[pos] <= ' ') pos++;\n\
    \            if (pos < len || eof) break;\n        }\n        if (len - pos <\
    \ TOKEN_MARGIN && !eof) refill();\n    }\n\n    // 8 \u30D0\u30A4\u30C8\u304C\u3059\
    \u3079\u3066 '0'~'9' \u304B\u5224\u5B9A\n    static bool is_8digits(uint64_t v)\
    \ {\n        return ((v & 0xF0F0F0F0F0F0F0F0ULL) | (((v + 0x0606060606060606ULL)\
    \ & 0xF0F0F0F0F0F0F0F0ULL) >> 4)) == 0x3333333333333333ULL;\n    }\n\n    // 8\
    \ \u6841\u306E\u6570\u5B57\u5217 (\u5148\u982D\u306E\u6841\u304C\u4E0B\u4F4D\u30D0\
    \u30A4\u30C8) \u3092\u6574\u6570\u306B\u5909\u63DB (SWAR)\n    static uint32_t\
    \ parse_8digits(uint64_t v) {\n        v -= 0x3030303030303030ULL;\n        v\
    \ = (v * 10 + (v >> 8)) & 0x00FF00FF00FF00FFULL;\n        v = (v * 100 + (v >>\
    \ 16)) & 0x0000FFFF0000FFFFULL;\n        v = (v * 10000 + (v >> 32)) & 0x00000000FFFFFFFFULL;\n\
    \        return uint32_t(v);\n    }\n\n    template <class U> U read_unsigned()\
    \ {\n        U r = 0;\n        const char *p = buf + pos;\n        uint64_t v;\n\
    \        memcpy(&v, p, 8);\n        while (is_8digits(v)) {\n            r = r\
    \ * 100000000 + parse_8digits(v);\n            p += 8;\n            memcpy(&v,\
    \ p, 8);\n        }\n        while (uint32_t(*p - '0') < 10) r = r * 10 + (*p++\
    \ - '0');\n        pos = p - buf;\n        return r;\n    }\n\n    template <class\
    \ T> void read_integer(T &x) {\n        skip_space();\n        if constexpr (is_signed_integer_v<T>)\
    \ {\n            using U = unsigned_of_t<T>;\n            bool neg = buf[pos]\
    \ == '-';\n            pos += neg;\n            U r = read_unsigned<U>();\n  \
    \          x = T(neg ? U(0) - r : r);\n        } else {\n            x = read_unsigned<T>();\n\
    \        }\n    }\n\n    void read_char(char &c) {\n        skip_space();\n  \
    \      c = buf[pos++];\n    }\n\n    void read_string(string &s) {\n        skip_space();\n\
    \        s.clear();\n        while (true) {\n            size_t st = pos;\n  \
    \          while (pos < len && (unsigned char)buf[pos] > ' ') pos++;\n       \
    \     s.append(buf + st, pos - st);\n            if (pos < len || eof) break;\n\
    \            refill();\n            if (pos == len) break;\n        }\n    }\n\
    \n    template <class T> void read_float(T &x) {\n        skip_space();\n    \
    \    char *end;\n        x = T(strtold(buf + pos, &end));\n        pos = end -\
    \ buf;\n    }\n\n    template <class T> Reader &operator>>(T &x) {\n        if\
    \ constexpr (is_integer_v<T>) read_integer(x);\n        else if constexpr (is_same_v<T,\
    \ char>) read_char(x);\n        else if constexpr (is_same_v<T, string>) read_string(x);\n\
    \        else if constexpr (is_floating_point_v<T>) read_float(x);\n        else\
    \ if constexpr (is_same_v<T, bool>) { int t; read_integer(t); x = t; }\n     \
    \   else if constexpr (has_val<T>::value) { long long t; read_integer(t); x =\
    \ T(t); }\n        else static_assert(is_integer_v<T>, \"fastio: unsupported type\"\
    );\n        return *this;\n    }\n\n    template <class T> Reader &operator>>(vector<T>\
    \ &v) {\n        for (auto &e : v) *this >> e;\n        return *this;\n    }\n\
    \n    template <class T, class U> Reader &operator>>(pair<T, U> &p) { return *this\
    \ >> p.first >> p.second; }\n\n    template <class T> T read() {\n        T x;\n\
    \        *this >> x;\n        return x;\n    }\n};\n\nstruct Writer {\n    //\
    \ 1 \u30C8\u30FC\u30AF\u30F3\u306E\u66F8\u304D\u8FBC\u307F\u3067\u306F\u5883\u754C\
    \u30C1\u30A7\u30C3\u30AF\u3092\u305B\u305A\uFF0C\u66F8\u3044\u305F\u5F8C\u306B\
    \u307E\u3068\u3081\u3066 flush \u5224\u5B9A\u3059\u308B\n    static constexpr\
    \ size_t TOKEN_MARGIN = 128;\n    char buf[BUF_SIZE + TOKEN_MARGIN];\n    size_t\
    \ pos = 0;\n    int precision = 15;\n\n    ~Writer() { flush(); }\n\n    void\
    \ flush() {\n        fwrite(buf, 1, pos, stdout);\n        pos = 0;\n        fflush(stdout);\n\
    \    }\n\n    void check_flush() {\n        if (pos >= BUF_SIZE) flush();\n  \
    \  }\n\n    void write_char(char c) {\n        buf[pos++] = c;\n        check_flush();\n\
    \    }\n\n    // 10^16 \u672A\u6E80\u306E x \u3092\u3061\u3087\u3046\u3069 16\
    \ \u6841 (0 \u57CB\u3081) \u3067\u66F8\u304F\n    void write_16digits(uint64_t\
    \ x) {\n        uint64_t hi = x / 100000000, lo = x % 100000000;\n        memcpy(buf\
    \ + pos, digit_table.d[hi / 10000], 4);\n        memcpy(buf + pos + 4, digit_table.d[hi\
    \ % 10000], 4);\n        memcpy(buf + pos + 8, digit_table.d[lo / 10000], 4);\n\
    \        memcpy(buf + pos + 12, digit_table.d[lo % 10000], 4);\n        pos +=\
    \ 16;\n    }\n\n    void write_u64(uint64_t x) {\n        // \u4E0B\u4F4D\u304B\
    \u3089 4 \u6841\u305A\u3064\u4E00\u6642\u9818\u57DF\u306B\u66F8\u304D\uFF0C\u6700\
    \u5F8C\u306B\u5148\u982D\u306E 1~4 \u6841\u3092\u66F8\u304F\n        char tmp[20];\n\
    \        int i = 20;\n        while (x >= 10000) {\n            memcpy(tmp + i\
    \ - 4, digit_table.d[x % 10000], 4);\n            i -= 4;\n            x /= 10000;\n\
    \        }\n        int k = x >= 1000 ? 4 : x >= 100 ? 3 : x >= 10 ? 2 : 1;\n\
    \        memcpy(tmp + i - k, digit_table.d[x] + 4 - k, k);\n        i -= k;\n\
    \        memcpy(buf + pos, tmp + i, 20 - i);\n        pos += 20 - i;\n    }\n\n\
    \    void write_u128(unsigned __int128 x) {\n        if (x >> 64 == 0) return\
    \ write_u64(uint64_t(x));\n        constexpr uint64_t P16 = 10000000000000000ULL;\n\
    \        uint64_t lo = uint64_t(x % P16);\n        x /= P16;\n        if (x >>\
    \ 64 == 0) {\n            write_u64(uint64_t(x));\n        } else {\n        \
    \    // 2^128 / 10^32 < 10^7 \u306A\u306E\u3067\u6700\u4E0A\u4F4D\u306F 64 bit\
    \ \u306B\u53CE\u307E\u308B\n            uint64_t mid = uint64_t(x % P16);\n  \
    \          write_u64(uint64_t(x / P16));\n            write_16digits(mid);\n \
    \       }\n        write_16digits(lo);\n    }\n\n    template <class T> void write_integer(T\
    \ x) {\n        if constexpr (is_signed_integer_v<T>) {\n            using U =\
    \ unsigned_of_t<T>;\n            U u = U(x);\n            if (x < 0) buf[pos++]\
    \ = '-', u = U(0) - u;\n            write_integer(u);\n        } else if constexpr\
    \ (is_int128<T>::value) {\n            write_u128(x);\n        } else {\n    \
    \        write_u64(x);\n        }\n    }\n\n    void write_string(const char *s,\
    \ size_t n) {\n        while (n > 0) {\n            size_t k = min(n, BUF_SIZE\
    \ - pos);\n            memcpy(buf + pos, s, k);\n            pos += k, s += k,\
    \ n -= k;\n            check_flush();\n        }\n    }\n\n    template <class\
    \ T> void write_float(T x) {\n        char tmp[64];\n        int n = snprintf(tmp,\
    \ sizeof(tmp), \"%.*Lf\", precision, (long double)x);\n        if (n < (int)sizeof(tmp))\
    \ return write_string(tmp, n);\n        // \u6841\u6570\u304C\u591A\u3059\u304E\
    \u308B\u3068\u304D\u3060\u3051\u52D5\u7684\u306B\u78BA\u4FDD\u3059\u308B\n   \
    \     string t(n + 1, '\\0');\n        snprintf(t.data(), n + 1, \"%.*Lf\", precision,\
    \ (long double)x);\n        write_string(t.data(), n);\n    }\n\n    void set_precision(int\
    \ p) { precision = p; }\n\n    template <class T> Writer &operator<<(const T &x)\
    \ {\n        if constexpr (is_integer_v<T>) write_integer(x), check_flush();\n\
    \        else if constexpr (is_same_v<T, char>) write_char(x);\n        else if\
    \ constexpr (is_same_v<T, bool>) write_char(char('0' + x));\n        else if constexpr\
    \ (is_same_v<T, string>) write_string(x.data(), x.size());\n        else if constexpr\
    \ (is_same_v<T, string_view>) write_string(x.data(), x.size());\n        else\
    \ if constexpr (is_convertible_v<T, const char *>) { const char *s = x; write_string(s,\
    \ strlen(s)); }\n        else if constexpr (is_floating_point_v<T>) write_float(x);\n\
    \        else if constexpr (has_val<T>::value) write_integer(x.val()), check_flush();\n\
    \        else static_assert(is_integer_v<T>, \"fastio: unsupported type\");\n\
    \        return *this;\n    }\n\n    // vector \u306F\u7A7A\u767D\u533A\u5207\u308A\
    \u3067\u51FA\u529B\u3059\u308B\n    template <class T> Writer &operator<<(const\
    \ vector<T> &v) {\n        for (size_t i = 0; i < v.size(); i++) {\n         \
    \   if (i) write_char(' ');\n            *this << v[i];\n        }\n        return\
    \ *this;\n    }\n};\n\ninline Reader fin;\ninline Writer fout;\n\n}  // namespace\
    \ fastio\n\nusing fastio::fin;\nusing fastio::fout;\n#line 2 \"template.hpp\"\n\
    using namespace std;\n#if __has_include(<atcoder/all>)\n#include <atcoder/all>\n\
    using namespace atcoder;\n#endif\n// QCfium\u6CD5\u3092\u4F7F\u3046\u6642\u306F\
    \u30B3\u30E1\u30F3\u30C8\u30A2\u30A6\u30C8\u3092\u5916\u3059\n/*/\n#pragma GCC\
    \ optimize(\"Ofast,unroll-loops,no-stack-protector,fast-math\")\n#pragma GCC target(\"\
    avx2,bmi,bmi2,lzcnt,popcnt\")\n#pragma GCC target(\"avx,avx2,fma\")\n#pragma GCC\
    \ target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma\")\n//*/\n#define\
    \ rep(i,n) for(int i=0;i<n;i++)\n#define Rep(i,a,b) for(int i=a;i<b;i++)\n#define\
    \ ALL(x) (x).begin(),(x).end()\n#define dbgv(x); for(auto now : x) cout << now\
    \ << \" \"; cout << endl;\n//using P = pair<int,int>;\nusing ll = long long;\n\
    using ull = unsigned long long;\ntypedef pair<int, int> pii;\ntypedef pair<ll,\
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 3 \"graph/minimum_spanning_tree.hpp\"\
    \n\n// https://github.com/winter-2521/cp-library\n\n// \u6700\u5C0F\u5168\u57DF\
    \u6728 (Kruskal)\uFF0E\u8FBA\u3092\u91CD\u307F\u306E\u6607\u9806\u306B\u898B\u3066\
    \uFF0C\u4E21\u7AEF\u304C\u307E\u3060\u3064\u306A\u304C\u3063\u3066\u3044\u306A\
    \u3051\u308C\u3070\u63A1\u7528\u3059\u308B\uFF0EO(m log m)\n// \u8FD4\u308A\u5024\
    : {\u91CD\u307F\u306E\u548C, \u63A1\u7528\u3057\u305F\u8FBA\u306E\u756A\u53F7\u306E\
    \u5217}\uFF0E\u975E\u9023\u7D50\u306A\u3089\u6700\u5C0F\u5168\u57DF\u68EE\ntemplate\
    \ <class T>\npair<T, vector<int>> minimum_spanning_tree(int n, const vector<tuple<int,\
    \ int, T>> &edges) {\n    int m = edges.size();\n    vector<pair<T, int>> ord(m);\n\
    \    for (int i = 0; i < m; i++) ord[i] = {get<2>(edges[i]), i};\n    sort(ord.begin(),\
    \ ord.end());\n    vector<int> par(n, -1);\n    auto find = [&](int x) {\n   \
    \     while (par[x] >= 0) {\n            if (par[par[x]] >= 0) par[x] = par[par[x]];\
    \  // \u7D4C\u8DEF\u3092\u534A\u5206\u306B\u3059\u308B\n            x = par[x];\n\
    \        }\n        return x;\n    };\n    T total = 0;\n    vector<int> used;\n\
    \    used.reserve(n ? n - 1 : 0);\n    for (auto &[w, i] : ord) {\n        int\
    \ a = find(get<0>(edges[i])), b = find(get<1>(edges[i]));\n        if (a == b)\
    \ continue;\n        if (par[a] > par[b]) swap(a, b);\n        par[a] += par[b],\
    \ par[b] = a;\n        total += w, used.push_back(i);\n        if ((int)used.size()\
    \ == n - 1) break;\n    }\n    return {total, used};\n}\n#line 2 \"template.hpp\"\
    \nusing namespace std;\n#if __has_include(<atcoder/all>)\n#include <atcoder/all>\n\
    using namespace atcoder;\n#endif\n// QCfium\u6CD5\u3092\u4F7F\u3046\u6642\u306F\
    \u30B3\u30E1\u30F3\u30C8\u30A2\u30A6\u30C8\u3092\u5916\u3059\n/*/\n#pragma GCC\
    \ optimize(\"Ofast,unroll-loops,no-stack-protector,fast-math\")\n#pragma GCC target(\"\
    avx2,bmi,bmi2,lzcnt,popcnt\")\n#pragma GCC target(\"avx,avx2,fma\")\n#pragma GCC\
    \ target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma\")\n//*/\n#define\
    \ rep(i,n) for(int i=0;i<n;i++)\n#define Rep(i,a,b) for(int i=a;i<b;i++)\n#define\
    \ ALL(x) (x).begin(),(x).end()\n#define dbgv(x); for(auto now : x) cout << now\
    \ << \" \"; cout << endl;\n//using P = pair<int,int>;\nusing ll = long long;\n\
    using ull = unsigned long long;\ntypedef pair<int, int> pii;\ntypedef pair<ll,\
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 3 \"graph/directed_mst.hpp\"\
    \n\n// https://github.com/winter-2521/cp-library\n\n// \u6700\u5C0F\u6709\u5411\
    \u5168\u57DF\u6728 (\u6839 r \u304B\u3089\u5168\u9802\u70B9\u306B\u5230\u9054\u3067\
    \u304D\u308B\uFF0C\u8FBA\u306E\u91CD\u307F\u306E\u548C\u304C\u6700\u5C0F\u306E\
    \u6709\u5411\u6728)\uFF0EChu-Liu/Edmonds \u6CD5\u3092\n// \u4F75\u5408\u3067\u304D\
    \u308B\u30D2\u30FC\u30D7 (skew heap\uFF0C\u9045\u5EF6\u52A0\u7B97) \u3068 Union-Find\
    \ \u3067 O(m log n) \u306B\u3057\u305F\u3082\u306E (Tarjan / Gabow \u3089)\n//\
    \ \u8FD4\u308A\u5024: {\u91CD\u307F\u306E\u548C, par (par[v] = v \u306E\u89AA\uFF0E\
    par[r] = r)}\uFF0E\u5230\u9054\u3067\u304D\u306A\u3044\u9802\u70B9\u304C\u3042\
    \u308C\u3070 {-1 \u76F8\u5F53, \u7A7A}\ntemplate <class T>\npair<T, vector<int>>\
    \ directed_mst(int n, const vector<tuple<int, int, T>> &edges, int r) {\n    int\
    \ m = edges.size();\n    // skew heap: \u5404\u9802\u70B9\u306B\u5165\u3063\u3066\
    \u304F\u308B\u8FBA (\u30AD\u30FC\u306F\u91CD\u307F) \u3092\u5165\u308C\u308B\uFF0E\
    lz \u306F\u90E8\u5206\u6728\u5168\u4F53\u306B\u8DB3\u3059\u5024\n    vector<int>\
    \ hl(m, -1), hr(m, -1);\n    vector<T> key(m), lz(m, 0);\n    for (int i = 0;\
    \ i < m; i++) key[i] = get<2>(edges[i]);\n    auto push = [&](int x) {\n     \
    \   if (lz[x] != 0) {\n            if (hl[x] >= 0) key[hl[x]] += lz[x], lz[hl[x]]\
    \ += lz[x];\n            if (hr[x] >= 0) key[hr[x]] += lz[x], lz[hr[x]] += lz[x];\n\
    \            lz[x] = 0;\n        }\n    };\n    auto meld = [&](auto self, int\
    \ a, int b) -> int {\n        if (a < 0) return b;\n        if (b < 0) return\
    \ a;\n        if (key[b] < key[a]) swap(a, b);\n        push(a);\n        hr[a]\
    \ = self(self, hr[a], b);\n        swap(hl[a], hr[a]);\n        return a;\n  \
    \  };\n    auto pop = [&](int a) {\n        push(a);\n        return meld(meld,\
    \ hl[a], hr[a]);\n    };\n    vector<int> heap(n, -1);\n    for (int i = 0; i\
    \ < m; i++) {\n        int b = get<1>(edges[i]);\n        if (b == r) continue;\n\
    \        hl[i] = hr[i] = -1;\n        heap[b] = meld(meld, heap[b], i);\n    }\n\
    \    // \u7E2E\u7D04\u3092 Union-Find \u3067\u8868\u3059 (\u9802\u70B9 \u2192\
    \ \u7E2E\u7D04\u5F8C\u306E\u4EE3\u8868)\n    vector<int> uf(2 * n, -1);\n    auto\
    \ find = [&](int x) {\n        while (uf[x] >= 0) {\n            if (uf[uf[x]]\
    \ >= 0) uf[x] = uf[uf[x]];\n            x = uf[x];\n        }\n        return\
    \ x;\n    };\n    // \u7E2E\u7D04\u306E\u305F\u3073\u306B\u65B0\u3057\u3044\u9802\
    \u70B9 (\u756A\u53F7 n, n+1, ...) \u3092\u4F5C\u308B\uFF0Epar_c[x]: \u7E2E\u7D04\
    \u9802\u70B9 x \u3092\u542B\u3080\uFF0C\u3088\u308A\u5927\u304D\u3044\u7E2E\u7D04\
    \u9802\u70B9\n    vector<int> seen(2 * n, -1), in_edge(2 * n, -1), par_c(2 * n,\
    \ -1), heap2(2 * n, -1);\n    for (int v = 0; v < n; v++) heap2[v] = heap[v];\n\
    \    int cnt = n;\n    T total = 0;\n    seen[r] = r;\n    vector<int> path;\n\
    \    for (int s = 0; s < n; s++) {\n        int v = find(s);\n        path.clear();\n\
    \        while (seen[v] < 0) {\n            seen[v] = s;\n            path.push_back(v);\n\
    \            // v \u306B\u5165\u3063\u3066\u304F\u308B\u6700\u5C0F\u306E\u8FBA\
    \ (\u7E2E\u7D04\u306E\u5185\u5074\u306E\u8FBA\u306F\u6368\u3066\u308B)\n     \
    \       while (true) {\n                if (heap2[v] < 0) return {T(-1), {}};\
    \  // \u5230\u9054\u3067\u304D\u306A\u3044\n                int e = heap2[v];\n\
    \                if (find(get<0>(edges[e])) == v) {\n                    heap2[v]\
    \ = pop(e);\n                    continue;\n                }\n              \
    \  break;\n            }\n            int e = heap2[v];\n            in_edge[v]\
    \ = e;\n            total += key[e];\n            // v \u306B\u5165\u308B\u4ED6\
    \u306E\u8FBA\u306F\uFF0C\u3053\u306E\u8FBA\u3092\u4F7F\u3063\u305F\u524D\u63D0\
    \u3067\u91CD\u307F\u3092\u5DEE\u3057\u5F15\u3044\u3066\u304A\u304F (\u7E2E\u7D04\
    \u3057\u305F\u3068\u304D\u7528)\n            T w = key[e];\n            heap2[v]\
    \ = pop(e);\n            if (heap2[v] >= 0) key[heap2[v]] -= w, lz[heap2[v]] -=\
    \ w;\n            int u = find(get<0>(edges[e]));\n            if (seen[u] ==\
    \ s) {\n                // \u9589\u8DEF: path \u306E u \u304B\u3089 v \u307E\u3067\
    \u3092\u65B0\u3057\u3044\u9802\u70B9 c \u306B\u7E2E\u7D04\u3059\u308B\n      \
    \          int c = cnt++;\n                int h = -1;\n                while\
    \ (true) {\n                    int x = path.back();\n                    path.pop_back();\n\
    \                    uf[x] = c, par_c[x] = c;\n                    if (heap2[x]\
    \ >= 0) h = meld(meld, h, heap2[x]);\n                    if (x == u) break;\n\
    \                }\n                heap2[c] = h;\n                v = c;  //\
    \ seen[c] = -1 \u306A\u306E\u3067\uFF0C\u30EB\u30FC\u30D7\u306E\u5148\u982D\u3067\
    \ c \u306B\u5165\u308B\u8FBA\u3092\u63A2\u3059\n                continue;\n  \
    \          }\n            v = u;\n        }\n    }\n    // \u5FA9\u5143: \u7E2E\
    \u7D04\u9802\u70B9\u3092\u65B0\u3057\u3044\u9806\u306B\u898B\u308B\uFF0Ex \u306B\
    \u5165\u308B\u8FBA e \u3092\u4F7F\u3046\u306A\u3089\uFF0Ce \u306E\u884C\u304D\u5148\
    \u306E\u5143\u306E\u9802\u70B9 b \u304B\u3089 x \u307E\u3067\u306E\u9593\u306E\
    \u9802\u70B9\u306B\u5165\u308B\u8FBA\u306F\u4F7F\u308F\u306A\u3044\n    // (\u7E2E\
    \u7D04\u3057\u305F\u9589\u8DEF\u306E\u3046\u3061\uFF0Cb \u306E\u3068\u3053\u308D\
    \u3060\u3051\u9589\u8DEF\u306E\u8FBA\u306E\u4EE3\u308F\u308A\u306B e \u304C\u5165\
    \u308B)\n    vector<int> par(n, -1);\n    vector<char> unused(cnt, 0);\n    par[r]\
    \ = r;\n    for (int x = cnt - 1; x >= 0; x--) {\n        if (x == r || unused[x])\
    \ continue;\n        int e = in_edge[x], b = get<1>(edges[e]);\n        par[b]\
    \ = get<0>(edges[e]);\n        for (int y = b; y != x; y = par_c[y]) unused[y]\
    \ = 1;\n    }\n    return {total, par};\n}\n#line 2 \"template.hpp\"\nusing namespace\
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
    \ 3 \"graph/hungarian.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\n\
    // \u5272\u5F53\u554F\u984C (Hungarian \u6CD5)\uFF0En \xD7 m (n <= m) \u306E\u884C\
    \u5217 a \u3067\uFF0C\u5404\u884C\u306B\u76F8\u7570\u306A\u308B\u5217\u3092\u5272\
    \u308A\u5F53\u3066\u3066\u548C\u3092\u6700\u5C0F\u306B\u3059\u308B\uFF0EO(n^2\
    \ m)\n// \u884C i \u3092 1 \u3064\u305A\u3064\u8FFD\u52A0\u3057\uFF0C\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB (\u53CC\u5BFE\u5909\u6570) u, v \u3092\u4FDD\u3063\u305F\
    \u307E\u307E\uFF0CDijkstra \u98A8\u306B\u6700\u77ED\u306E\u5897\u52A0\u8DEF\u3092\
    \u898B\u3064\u3051\u308B\n// \u8FD4\u308A\u5024: {\u6700\u5C0F\u5024, p (p[i]\
    \ = \u884C i \u306B\u5272\u308A\u5F53\u3066\u305F\u5217)}\ntemplate <class T>\n\
    pair<T, vector<int>> hungarian(const vector<vector<T>> &a) {\n    int n = a.size();\n\
    \    if (n == 0) return {T(0), {}};\n    int m = a[0].size();\n    assert(n <=\
    \ m);\n    const T INF = numeric_limits<T>::max() / 2;\n    // 1-indexed\uFF0E\
    \u5217 0 \u306F\u300C\u307E\u3060\u5272\u308A\u5F53\u3066\u3066\u3044\u306A\u3044\
    \u884C\u300D\u3092\u7F6E\u304F\u4EEE\u306E\u5217\n    vector<T> u(n + 1, 0), v(m\
    \ + 1, 0), minv(m + 1);\n    vector<int> p(m + 1, 0), way(m + 1, 0);  // p[j]:\
    \ \u5217 j \u306B\u5272\u308A\u5F53\u3066\u305F\u884C\n    vector<char> used(m\
    \ + 1);\n    for (int i = 1; i <= n; i++) {\n        p[0] = i;\n        int j0\
    \ = 0;\n        fill(minv.begin(), minv.end(), INF);\n        fill(used.begin(),\
    \ used.end(), 0);\n        do {\n            used[j0] = 1;\n            int i0\
    \ = p[j0], j1 = 0;\n            T delta = INF;\n            const T *row = a[i0\
    \ - 1].data();\n            for (int j = 1; j <= m; j++) {\n                if\
    \ (used[j]) continue;\n                T cur = row[j - 1] - u[i0] - v[j];\n  \
    \              if (cur < minv[j]) minv[j] = cur, way[j] = j0;\n              \
    \  if (minv[j] < delta) delta = minv[j], j1 = j;\n            }\n            for\
    \ (int j = 0; j <= m; j++) {\n                if (used[j]) u[p[j]] += delta, v[j]\
    \ -= delta;\n                else minv[j] -= delta;\n            }\n         \
    \   j0 = j1;\n        } while (p[j0] != 0);\n        // \u5897\u52A0\u8DEF\u3092\
    \u53CD\u8EE2\n        do {\n            int j1 = way[j0];\n            p[j0] =\
    \ p[j1];\n            j0 = j1;\n        } while (j0);\n    }\n    vector<int>\
    \ ans(n);\n    for (int j = 1; j <= m; j++)\n        if (p[j]) ans[p[j] - 1] =\
    \ j - 1;\n    T total = 0;\n    for (int i = 0; i < n; i++) total += a[i][ans[i]];\n\
    \    return {total, ans};\n}\n#line 2 \"template.hpp\"\nusing namespace std;\n\
    #if __has_include(<atcoder/all>)\n#include <atcoder/all>\nusing namespace atcoder;\n\
    #endif\n// QCfium\u6CD5\u3092\u4F7F\u3046\u6642\u306F\u30B3\u30E1\u30F3\u30C8\u30A2\
    \u30A6\u30C8\u3092\u5916\u3059\n/*/\n#pragma GCC optimize(\"Ofast,unroll-loops,no-stack-protector,fast-math\"\
    )\n#pragma GCC target(\"avx2,bmi,bmi2,lzcnt,popcnt\")\n#pragma GCC target(\"avx,avx2,fma\"\
    )\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma\"\
    )\n//*/\n#define rep(i,n) for(int i=0;i<n;i++)\n#define Rep(i,a,b) for(int i=a;i<b;i++)\n\
    #define ALL(x) (x).begin(),(x).end()\n#define dbgv(x); for(auto now : x) cout\
    \ << now << \" \"; cout << endl;\n//using P = pair<int,int>;\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\ntypedef pair<int, int> pii;\ntypedef\
    \ pair<ll, ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line\
    \ 3 \"graph/bipartite_matching.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\
    \uFF0EO(m \u221An)\n// 1. \u521D\u671F\u30DE\u30C3\u30C1\u30F3\u30B0\u306F Karp-Sipser\
    \ \u306E\u8CAA\u6B32 (\u6B21\u6570 1 \u306E\u9802\u70B9\u304B\u3089\u7D44\u3080\
    ) \u3067\u4F5C\u308B\n// 2. \u5DE6\u306E\u672A\u30DE\u30C3\u30C1\u9802\u70B9\u5168\
    \u90E8\u304B\u3089\u540C\u6642\u306B BFS \u3057\uFF0C\u5404\u9802\u70B9\u306B\u300C\
    \u3069\u306E\u59CB\u70B9\u304B\u3089\u6765\u305F\u304B (root)\u300D\u3092\u4ED8\
    \u3051\u308B\uFF0E\n//    \u672A\u30DE\u30C3\u30C1\u306E\u53F3\u9802\u70B9\u306B\
    \u7740\u3044\u305F\u3089\u305D\u306E\u5834\u3067\u5897\u52A0\u3057\uFF0C\u540C\
    \u3058 root \u306E\u63A2\u7D22\u306F\u6253\u3061\u5207\u308B\uFF0E1 \u56DE O(m)\
    \ \u3067\u591A\u6570\u306E\u5897\u52A0\u8DEF\u304C\u53D6\u308C\uFF0C\u5B9F\u7528\
    \u4E0A\u3068\u3066\u3082\u901F\u3044\n// 3. 2 \u3092 \u221An \u56DE\u3084\u3063\
    \u3066\u3082\u7D42\u308F\u3089\u306A\u3051\u308C\u3070 Hopcroft-Karp (\u5C64\u306B\
    \u6CBF\u3063\u305F DFS \u3067\u6700\u77ED\u5897\u52A0\u8DEF\u3092\u307E\u3068\u3081\
    \u3066\u53D6\u308B) \u306B\u5207\u308A\u66FF\u3048\u3066 O(m \u221An) \u3092\u4FDD\
    \u8A3C\u3059\u308B\nstruct BipartiteMatching {\n    int L, R;\n    vector<pair<int,\
    \ int>> edges;\n    vector<int> match_l, match_r;  // \u76F8\u624B (\u3044\u306A\
    \u3051\u308C\u3070 -1)\n\n    BipartiteMatching(int L, int R) : L(L), R(R) {}\n\
    \    void reserve(int m) { edges.reserve(m); }\n    // \u5DE6 a \u3068\u53F3 b\
    \ \u306E\u9593\u306B\u8FBA\n    void add_edge(int a, int b) { edges.push_back({a,\
    \ b}); }\n\n    // \u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\u306E\u5927\u304D\
    \u3055\u3092\u8FD4\u3059\n    int solve() {\n        vector<int> start(L + 1,\
    \ 0), adj(edges.size());\n        for (auto &[a, b] : edges) start[a + 1]++;\n\
    \        for (int i = 0; i < L; i++) start[i + 1] += start[i];\n        {\n  \
    \          vector<int> pos(start.begin(), start.end() - 1);\n            for (auto\
    \ &[a, b] : edges) adj[pos[a]++] = b;\n        }\n        match_l.assign(L, -1),\
    \ match_r.assign(R, -1);\n        // \u521D\u671F\u30DE\u30C3\u30C1\u30F3\u30B0\
    \ (Karp-Sipser): \u6B8B\u308A\u306E\u6B21\u6570\u304C 1 \u306E\u9802\u70B9\u306F\
    \uFF0C\u305D\u306E\u552F\u4E00\u306E\u76F8\u624B\u3068\u7D44\u307E\u305B\u3066\
    \u3082\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\u3092\u640D\u306A\u308F\u306A\
    \u3044\uFF0E\n        // \u305D\u3046\u3044\u3046\u9802\u70B9\u304C\u3042\u308C\
    \u3070\u5148\u306B\u7D44\u307F\uFF0C\u306A\u3051\u308C\u3070\u9069\u5F53\u306A\
    \u9802\u70B9\u3092\u7D44\u3080\uFF0E\u5F8C\u306E\u5897\u52A0\u8DEF\u306E\u63A2\
    \u7D22\u304C\u305A\u3063\u3068\u6E1B\u308B\n        int res = 0;\n        {\n\
    \            vector<int> rstart(R + 1, 0), radj(edges.size());\n            for\
    \ (auto &[a, b] : edges) rstart[b + 1]++;\n            for (int i = 0; i < R;\
    \ i++) rstart[i + 1] += rstart[i];\n            {\n                vector<int>\
    \ pos(rstart.begin(), rstart.end() - 1);\n                for (auto &[a, b] :\
    \ edges) radj[pos[b]++] = a;\n            }\n            // \u9802\u70B9\u756A\
    \u53F7: \u5DE6 0..L-1\uFF0C\u53F3 L..L+R-1\n            vector<int> deg(L + R);\n\
    \            for (int a = 0; a < L; a++) deg[a] = start[a + 1] - start[a];\n \
    \           for (int b = 0; b < R; b++) deg[L + b] = rstart[b + 1] - rstart[b];\n\
    \            vector<char> dead(L + R, 0);\n            vector<int> ones;\n   \
    \         for (int x = 0; x < L + R; x++)\n                if (deg[x] == 1) ones.push_back(x);\n\
    \            auto remove = [&](int x) {  // x \u3092\u53D6\u308A\u9664\u304D\uFF0C\
    \u96A3\u306E\u6B21\u6570\u3092\u4E0B\u3052\u308B\n                dead[x] = 1;\n\
    \                if (x < L) {\n                    for (int i = start[x]; i <\
    \ start[x + 1]; i++) {\n                        int y = L + adj[i];\n        \
    \                if (!dead[y] && --deg[y] == 1) ones.push_back(y);\n         \
    \           }\n                } else {\n                    int b = x - L;\n\
    \                    for (int i = rstart[b]; i < rstart[b + 1]; i++) {\n     \
    \                   int y = radj[i];\n                        if (!dead[y] &&\
    \ --deg[y] == 1) ones.push_back(y);\n                    }\n                }\n\
    \            };\n            auto partner = [&](int x) {  // \u751F\u304D\u3066\
    \u3044\u308B\u96A3\u3092 1 \u3064\n                if (x < L) {\n            \
    \        for (int i = start[x]; i < start[x + 1]; i++)\n                     \
    \   if (!dead[L + adj[i]]) return L + adj[i];\n                } else {\n    \
    \                int b = x - L;\n                    for (int i = rstart[b]; i\
    \ < rstart[b + 1]; i++)\n                        if (!dead[radj[i]]) return radj[i];\n\
    \                }\n                return -1;\n            };\n            auto\
    \ pair_up = [&](int x, int y) {\n                int a = x < L ? x : y, b = (x\
    \ < L ? y : x) - L;\n                match_l[a] = b, match_r[b] = a, res++;\n\
    \                remove(x), remove(y);\n            };\n            int scan =\
    \ 0;\n            while (true) {\n                if (!ones.empty()) {\n     \
    \               int x = ones.back();\n                    ones.pop_back();\n \
    \                   if (dead[x] || deg[x] != 1) continue;\n                  \
    \  int y = partner(x);\n                    if (y >= 0) pair_up(x, y);\n     \
    \               continue;\n                }\n                while (scan < L\
    \ && (dead[scan] || deg[scan] == 0)) scan++;\n                if (scan == L) break;\n\
    \                int y = partner(scan);\n                if (y < 0) {\n      \
    \              dead[scan] = 1;\n                    continue;\n              \
    \  }\n                pair_up(scan, y);\n            }\n        }\n        vector<int>\
    \ que(L);\n        {\n            vector<int> root(L, -1), prev(L);\n        \
    \    int rounds = 0, lim_rounds = (int)sqrt((double)(L + R)) + 1;\n          \
    \  while (rounds++ < lim_rounds) {\n                int qt = 0;\n            \
    \    for (int a = 0; a < L; a++)\n                    if (match_l[a] < 0) root[a]\
    \ = a, prev[a] = -1, que[qt++] = a;\n                bool updated = false;\n \
    \               for (int qh = 0; qh < qt; qh++) {\n                    int a =\
    \ que[qh];\n                    if (match_l[root[a]] >= 0) continue;  // \u3053\
    \u306E\u59CB\u70B9\u306F\u3082\u3046\u5897\u52A0\u3057\u305F\n               \
    \     for (int i = start[a]; i < start[a + 1]; i++) {\n                      \
    \  int b = adj[i], c = match_r[b];\n                        if (c < 0) {\n   \
    \                         // prev \u3092\u9061\u308A\u306A\u304C\u3089\u53CD\u8EE2\
    : a-b \u3092\u7D44\u307F\uFF0Ca \u306E\u5143\u306E\u76F8\u624B\u3092 prev[a] \u306B\
    \u6E21\u3059\n                            while (b >= 0) {\n                 \
    \               int t = match_l[a];\n                                match_l[a]\
    \ = b, match_r[b] = a;\n                                b = t, a = prev[a];\n\
    \                            }\n                            res++, updated = true;\n\
    \                            break;\n                        }\n             \
    \           if (root[c] < 0) root[c] = root[a], prev[c] = a, que[qt++] = c;\n\
    \                    }\n                }\n                for (int k = 0; k <\
    \ qt; k++) root[que[k]] = -1;\n                if (!updated) return res;\n   \
    \         }\n        }\n        vector<int> dist(L), it(L), stk;\n        while\
    \ (true) {\n            // BFS: \u5DE6\u306E\u672A\u30DE\u30C3\u30C1\u9802\u70B9\
    \u3092\u8DDD\u96E2 0 \u3068\u3057\u3066\u5C64\u3092\u4F5C\u308B\n            int\
    \ qh = 0, qt = 0;\n            for (int a = 0; a < L; a++) {\n               \
    \ if (match_l[a] < 0) dist[a] = 0, que[qt++] = a;\n                else dist[a]\
    \ = -1;\n            }\n            // \u672A\u30DE\u30C3\u30C1\u306E\u53F3\u9802\
    \u70B9\u306B\u6700\u521D\u306B\u5C4A\u3044\u305F\u5C64 lim \u3088\u308A\u6DF1\u304F\
    \u306F\u5E83\u3052\u306A\u3044 (\u6700\u77ED\u306E\u5897\u52A0\u8DEF\u3060\u3051\
    \u3092\u4F7F\u3046)\n            int lim = -1;\n            while (qh < qt) {\n\
    \                int a = que[qh++];\n                if (lim >= 0 && dist[a] >=\
    \ lim) break;\n                for (int i = start[a]; i < start[a + 1]; i++) {\n\
    \                    int c = match_r[adj[i]];\n                    if (c < 0)\
    \ {\n                        if (lim < 0) lim = dist[a];\n                   \
    \ } else if (dist[c] < 0) {\n                        dist[c] = dist[a] + 1, que[qt++]\
    \ = c;\n                    }\n                }\n            }\n            if\
    \ (lim < 0) break;\n            // DFS (\u975E\u518D\u5E30): \u5C64\u3092 1 \u3064\
    \u305A\u3064\u4E0B\u308A\u308B\u5897\u52A0\u8DEF\n            for (int a = 0;\
    \ a < L; a++) it[a] = start[a];\n            for (int s = 0; s < L; s++) {\n \
    \               if (match_l[s] >= 0) continue;\n                stk.clear(), stk.push_back(s);\n\
    \                while (!stk.empty()) {\n                    int a = stk.back();\n\
    \                    bool advanced = false;\n                    while (it[a]\
    \ < start[a + 1]) {\n                        int b = adj[it[a]], c = match_r[b];\n\
    \                        if (c < 0 && dist[a] == lim) {\n                    \
    \        // \u5897\u52A0\u8DEF\u304C\u898B\u3064\u304B\u3063\u305F: \u30B9\u30BF\
    \u30C3\u30AF\u306B\u6CBF\u3063\u3066\u53CD\u8EE2\n                           \
    \ for (int k = (int)stk.size() - 1; k >= 0; k--) {\n                         \
    \       int x = stk[k], y = adj[it[x]];\n                                match_l[x]\
    \ = y, match_r[y] = x;\n                            }\n                      \
    \      res++;\n                            stk.clear();\n                    \
    \        advanced = true;\n                            break;\n              \
    \          }\n                        if (c >= 0 && dist[c] == dist[a] + 1 &&\
    \ dist[a] < lim) {\n                            stk.push_back(c);\n          \
    \                  advanced = true;\n                            break;\n    \
    \                    }\n                        it[a]++;\n                   \
    \ }\n                    if (!advanced) {\n                        dist[a] = -1;\
    \  // \u884C\u304D\u6B62\u307E\u308A\n                        stk.pop_back();\n\
    \                        if (!stk.empty()) it[stk.back()]++;\n               \
    \     }\n                }\n            }\n        }\n        return res;\n  \
    \  }\n\n    // \u30DE\u30C3\u30C1\u30F3\u30B0\u306E\u8FBA (\u5DE6, \u53F3) \u306E\
    \u5217\n    vector<pair<int, int>> matching() const {\n        vector<pair<int,\
    \ int>> res;\n        for (int a = 0; a < L; a++)\n            if (match_l[a]\
    \ >= 0) res.push_back({a, match_l[a]});\n        return res;\n    }\n};\n#line\
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
    \ 3 \"graph/csr.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\n// \u96A3\
    \u63A5\u30EA\u30B9\u30C8\u3092 1 \u672C\u306E\u914D\u5217\u3067\u6301\u3064 (Compressed\
    \ Sparse Row)\n// \u9802\u70B9 v \u306E\u96A3\u63A5\u306F elist[start[v] .. start[v+1])\uFF0E\
    vector<vector<int>> \u3088\u308A\u901F\u304F\u30E1\u30E2\u30EA\u3082\u5C11\u306A\
    \u3044\ntemplate <class E>\nstruct CSR {\n    vector<int> start;\n    vector<E>\
    \ elist;\n    CSR() = default;\n    // edges[i] = (from, \u4E2D\u8EAB)\n    CSR(int\
    \ n, const vector<pair<int, E>> &edges) : start(n + 1, 0), elist(edges.size())\
    \ {\n        for (auto &e : edges) start[e.first + 1]++;\n        for (int i =\
    \ 1; i <= n; i++) start[i] += start[i - 1];\n        vector<int> pos(start.begin(),\
    \ start.end() - 1);\n        for (auto &e : edges) elist[pos[e.first]++] = e.second;\n\
    \    }\n    int size() const { return (int)start.size() - 1; }\n};\n#line 4 \"\
    graph/general_matching.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\
    \ (Edmonds \u306E\u82B1\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0)\uFF0EO(n^3)\n// \u672A\
    \u30DE\u30C3\u30C1\u306E\u9802\u70B9\u304B\u3089\u4EA4\u4E92\u8DEF\u3092 BFS \u3067\
    \u63A2\u3057\uFF0C\u5947\u9589\u8DEF (\u82B1) \u3092\u898B\u3064\u3051\u305F\u3089\
    \ 1 \u9802\u70B9 (base) \u306B\u7E2E\u7D04\u3057\u305F\u3082\u306E\u3068\u3057\
    \u3066\u6271\u3046\uFF0E\n// \u7E2E\u7D04\u306F base[] (\u5404\u9802\u70B9\u304C\
    \u5C5E\u3059\u308B\u82B1\u306E\u4EE3\u8868) \u3067\u8868\u3057\uFF0C\u5B9F\u969B\
    \u306B\u306F\u30B0\u30E9\u30D5\u3092\u4F5C\u308A\u76F4\u3055\u306A\u3044\nstruct\
    \ GeneralMatching {\n    int n;\n    vector<pair<int, int>> edges;\n    vector<int>\
    \ mate;  // \u76F8\u624B (\u3044\u306A\u3051\u308C\u3070 -1)\n\n    GeneralMatching(int\
    \ n) : n(n), mate(n, -1) {}\n    void add_edge(int u, int v) { edges.push_back({u,\
    \ v}); }\n\n    int solve() {\n        vector<pair<int, int>> el;\n        el.reserve(2\
    \ * edges.size());\n        for (auto [u, v] : edges)\n            if (u != v)\
    \ el.push_back({u, v}), el.push_back({v, u});\n        CSR<int> g(n, el);\n  \
    \      // \u8CAA\u6B32\u306B\u521D\u671F\u30DE\u30C3\u30C1\u30F3\u30B0\n     \
    \   for (int v = 0; v < n; v++) {\n            if (mate[v] >= 0) continue;\n \
    \           for (int i = g.start[v]; i < g.start[v + 1]; i++) {\n            \
    \    int w = g.elist[i];\n                if (mate[w] < 0) {\n               \
    \     mate[v] = w, mate[w] = v;\n                    break;\n                }\n\
    \            }\n        }\n        vector<int> par(n), base(n), que(n), mark(n,\
    \ 0);\n        vector<char> used(n), in_blossom(n);\n        int stamp = 0;\n\
    \        // \u82B1\u306E base \u3092\u6C42\u3081\u308B (\u4EA4\u4E92\u6728\u306E\
    \ 2 \u9802\u70B9\u306E\u6700\u8FD1\u5171\u901A\u7956\u5148)\n        auto lca\
    \ = [&](int a, int b) {\n            stamp++;\n            while (true) {\n  \
    \              a = base[a];\n                mark[a] = stamp;\n              \
    \  if (mate[a] < 0) break;\n                a = par[mate[a]];\n            }\n\
    \            while (true) {\n                b = base[b];\n                if\
    \ (mark[b] == stamp) return b;\n                b = par[mate[b]];\n          \
    \  }\n        };\n        auto mark_path = [&](int v, int b, int child) {\n  \
    \          while (base[v] != b) {\n                in_blossom[base[v]] = in_blossom[base[mate[v]]]\
    \ = 1;\n                par[v] = child;\n                child = mate[v];\n  \
    \              v = par[mate[v]];\n            }\n        };\n        // root \u304B\
    \u3089\u5897\u52A0\u8DEF\u3092\u63A2\u3057\uFF0C\u7D42\u70B9 (\u672A\u30DE\u30C3\
    \u30C1\u9802\u70B9) \u3092\u8FD4\u3059\uFF0E\u306A\u3051\u308C\u3070 -1\n    \
    \    auto find_path = [&](int root) {\n            fill(used.begin(), used.end(),\
    \ 0);\n            fill(par.begin(), par.end(), -1);\n            iota(base.begin(),\
    \ base.end(), 0);\n            int qh = 0, qt = 0;\n            used[root] = 1,\
    \ que[qt++] = root;\n            while (qh < qt) {\n                int v = que[qh++];\n\
    \                for (int i = g.start[v]; i < g.start[v + 1]; i++) {\n       \
    \             int to = g.elist[i];\n                    if (base[v] == base[to]\
    \ || mate[v] == to) continue;\n                    if (to == root || (mate[to]\
    \ >= 0 && par[mate[to]] >= 0)) {\n                        // \u5947\u9589\u8DEF\
    \ (\u82B1) \u3092\u898B\u3064\u3051\u305F: base \u3092 cur \u306B\u307E\u3068\u3081\
    \u308B\n                        int cur = lca(v, to);\n                      \
    \  fill(in_blossom.begin(), in_blossom.end(), 0);\n                        mark_path(v,\
    \ cur, to), mark_path(to, cur, v);\n                        for (int x = 0; x\
    \ < n; x++) {\n                            if (!in_blossom[base[x]]) continue;\n\
    \                            base[x] = cur;\n                            if (!used[x])\
    \ used[x] = 1, que[qt++] = x;\n                        }\n                   \
    \ } else if (par[to] < 0) {\n                        par[to] = v;\n          \
    \              if (mate[to] < 0) return to;\n                        int nx =\
    \ mate[to];\n                        used[nx] = 1, que[qt++] = nx;\n         \
    \           }\n                }\n            }\n            return -1;\n    \
    \    };\n        for (int v = 0; v < n; v++) {\n            if (mate[v] >= 0)\
    \ continue;\n            int u = find_path(v);\n            // \u5897\u52A0\u8DEF\
    \u306B\u6CBF\u3063\u3066\u30DE\u30C3\u30C1\u30F3\u30B0\u3092\u53CD\u8EE2\n   \
    \         while (u >= 0) {\n                int pv = par[u], ppv = mate[pv];\n\
    \                mate[u] = pv, mate[pv] = u;\n                u = ppv;\n     \
    \       }\n        }\n        int res = 0;\n        for (int v = 0; v < n; v++)\n\
    \            if (mate[v] > v) res++;\n        return res;\n    }\n\n    // \u30DE\
    \u30C3\u30C1\u30F3\u30B0\u306E\u8FBA (u < v)\n    vector<pair<int, int>> matching()\
    \ const {\n        vector<pair<int, int>> res;\n        for (int v = 0; v < n;\
    \ v++)\n            if (mate[v] > v) res.push_back({v, mate[v]});\n        return\
    \ res;\n    }\n};\n#line 2 \"template.hpp\"\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
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
    \ 3 \"graph/general_weighted_matching.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u91CD\u307F\u30DE\u30C3\u30C1\
    \u30F3\u30B0 (Edmonds \u306E\u4E3B\u53CC\u5BFE\u6CD5\u30FB\u82B1\u306E\u7E2E\u7D04\
    )\uFF0EO(n^3)\n// \u9802\u70B9\u30E9\u30D9\u30EB (\u53CC\u5BFE\u5909\u6570) lab\
    \ \u3068\uFF0C\u82B1 (\u5947\u9589\u8DEF\u3092\u7E2E\u7D04\u3057\u305F\u9802\u70B9\
    ) \u3054\u3068\u306E\u30E9\u30D9\u30EB\u3092\u6301\u3061\uFF0C\n// \u300C\u30E9\
    \u30D9\u30EB\u306E\u548C = \u8FBA\u306E\u91CD\u307F \xD7 2\u300D\u3068\u306A\u308B\
    \u8FBA (\u30BF\u30A4\u30C8\u306A\u8FBA) \u3060\u3051\u3067\u4EA4\u4E92\u6728\u3092\
    \u4F38\u3070\u3059\uFF0E\u4F38\u3070\u305B\u306A\u304F\u306A\u3063\u305F\u3089\
    \u53CC\u5BFE\u3092 d \u3060\u3051\u52D5\u304B\u3059\uFF0E\n// \u9802\u70B9\u306F\
    \u5185\u90E8\u3067 1-indexed\uFF0C\u82B1\u306F n+1 .. 2n\ntemplate <class W =\
    \ long long>\nstruct GeneralWeightedMatching {\n    struct Edge {\n        int\
    \ u, v;\n        W w;\n    };\n    int n, nx;\n    vector<vector<Edge>> g;\n \
    \   vector<W> lab;\n    vector<int> mate, slack, st, pa, S, vis;\n    vector<vector<int>>\
    \ flo_from;\n    vector<vector<int>> flo;\n    vector<int> que;\n    size_t qh\
    \ = 0;\n    int vis_t = 0;\n\n    GeneralWeightedMatching(int n_)\n        : n(n_),\
    \ nx(n_), g(2 * n_ + 1, vector<Edge>(2 * n_ + 1)), lab(2 * n_ + 1), mate(2 * n_\
    \ + 1), slack(2 * n_ + 1), st(2 * n_ + 1),\n          pa(2 * n_ + 1), S(2 * n_\
    \ + 1), vis(2 * n_ + 1), flo_from(2 * n_ + 1, vector<int>(n_ + 1)), flo(2 * n_\
    \ + 1) {\n        for (int u = 1; u <= n; u++)\n            for (int v = 1; v\
    \ <= n; v++) g[u][v] = {u, v, 0};\n    }\n\n    // \u8FBA (u, v) \u91CD\u307F\
    \ w (0-indexed\uFF0Cw > 0\uFF0E\u540C\u3058\u7D44\u306F\u91CD\u3044\u65B9)\n \
    \   void add_edge(int u, int v, W w) {\n        u++, v++;\n        if (w > g[u][v].w)\
    \ g[u][v].w = g[v][u].w = w;\n    }\n\n    // {\u91CD\u307F\u306E\u548C, \u30DE\
    \u30C3\u30C1\u30F3\u30B0\u306E\u8FBA\u306E\u6570}\n    pair<W, int> solve() {\n\
    \        fill(mate.begin(), mate.end(), 0);\n        nx = n;\n        for (int\
    \ u = 0; u <= n; u++) st[u] = u, flo[u].clear();\n        W wmax = 0;\n      \
    \  for (int u = 1; u <= n; u++)\n            for (int v = 1; v <= n; v++) {\n\
    \                flo_from[u][v] = (u == v ? u : 0);\n                wmax = std::max(wmax,\
    \ g[u][v].w);\n            }\n        for (int u = 1; u <= n; u++) lab[u] = wmax;\n\
    \        int cnt = 0;\n        while (matching()) cnt++;\n        W tot = 0;\n\
    \        for (int u = 1; u <= n; u++)\n            if (mate[u] && mate[u] < u)\
    \ tot += g[u][mate[u]].w;\n        return {tot, cnt};\n    }\n\n    // \u30DE\u30C3\
    \u30C1\u30F3\u30B0\u306E\u8FBA (0-indexed, u < v)\n    vector<pair<int, int>>\
    \ matching_edges() const {\n        vector<pair<int, int>> res;\n        for (int\
    \ u = 1; u <= n; u++)\n            if (mate[u] && u < mate[u]) res.push_back({u\
    \ - 1, mate[u] - 1});\n        return res;\n    }\n\n  private:\n    W e_delta(const\
    \ Edge &e) const { return lab[e.u] + lab[e.v] - g[e.u][e.v].w * 2; }\n    void\
    \ update_slack(int u, int x) {\n        if (!slack[x] || e_delta(g[u][x]) < e_delta(g[slack[x]][x]))\
    \ slack[x] = u;\n    }\n    void set_slack(int x) {\n        slack[x] = 0;\n \
    \       for (int u = 1; u <= n; u++)\n            if (g[u][x].w > 0 && st[u] !=\
    \ x && S[st[u]] == 0) update_slack(u, x);\n    }\n    void q_push(int x) {\n \
    \       if (x <= n) que.push_back(x);\n        else\n            for (int y :\
    \ flo[x]) q_push(y);\n    }\n    void set_st(int x, int b) {\n        st[x] =\
    \ b;\n        if (x > n)\n            for (int y : flo[x]) set_st(y, b);\n   \
    \ }\n    int get_pr(int b, int xr) {\n        int pr = find(flo[b].begin(), flo[b].end(),\
    \ xr) - flo[b].begin();\n        if (pr % 2 == 1) {\n            reverse(flo[b].begin()\
    \ + 1, flo[b].end());\n            return (int)flo[b].size() - pr;\n        }\n\
    \        return pr;\n    }\n    void set_match(int u, int v) {\n        mate[u]\
    \ = g[u][v].v;\n        if (u <= n) return;\n        Edge e = g[u][v];\n     \
    \   int xr = flo_from[u][e.u], pr = get_pr(u, xr);\n        for (int i = 0; i\
    \ < pr; i++) set_match(flo[u][i], flo[u][i ^ 1]);\n        set_match(xr, v);\n\
    \        rotate(flo[u].begin(), flo[u].begin() + pr, flo[u].end());\n    }\n \
    \   void augment(int u, int v) {\n        while (true) {\n            int xnv\
    \ = st[mate[u]];\n            set_match(u, v);\n            if (!xnv) return;\n\
    \            set_match(xnv, st[pa[xnv]]);\n            u = st[pa[xnv]], v = xnv;\n\
    \        }\n    }\n    int get_lca(int u, int v) {\n        for (++vis_t; u ||\
    \ v; swap(u, v)) {\n            if (u == 0) continue;\n            if (vis[u]\
    \ == vis_t) return u;\n            vis[u] = vis_t;\n            u = st[mate[u]];\n\
    \            if (u) u = st[pa[u]];\n        }\n        return 0;\n    }\n    void\
    \ add_blossom(int u, int lca, int v) {\n        int b = n + 1;\n        while\
    \ (b <= nx && st[b]) b++;\n        if (b > nx) nx++;\n        lab[b] = 0, S[b]\
    \ = 0;\n        mate[b] = mate[lca];\n        flo[b].clear();\n        flo[b].push_back(lca);\n\
    \        for (int x = u, y; x != lca; x = st[pa[y]]) flo[b].push_back(x), flo[b].push_back(y\
    \ = st[mate[x]]), q_push(y);\n        reverse(flo[b].begin() + 1, flo[b].end());\n\
    \        for (int x = v, y; x != lca; x = st[pa[y]]) flo[b].push_back(x), flo[b].push_back(y\
    \ = st[mate[x]]), q_push(y);\n        set_st(b, b);\n        for (int x = 1; x\
    \ <= nx; x++) g[b][x].w = g[x][b].w = 0;\n        for (int x = 1; x <= n; x++)\
    \ flo_from[b][x] = 0;\n        for (int xs : flo[b]) {\n            for (int x\
    \ = 1; x <= nx; x++)\n                if (g[b][x].w == 0 || e_delta(g[xs][x])\
    \ < e_delta(g[b][x])) g[b][x] = g[xs][x], g[x][b] = g[x][xs];\n            for\
    \ (int x = 1; x <= n; x++)\n                if (flo_from[xs][x]) flo_from[b][x]\
    \ = xs;\n        }\n        set_slack(b);\n    }\n    void expand_blossom(int\
    \ b) {\n        for (int x : flo[b]) set_st(x, x);\n        int xr = flo_from[b][g[b][pa[b]].u],\
    \ pr = get_pr(b, xr);\n        for (int i = 0; i < pr; i += 2) {\n           \
    \ int xs = flo[b][i], xns = flo[b][i + 1];\n            pa[xs] = g[xns][xs].u;\n\
    \            S[xs] = 1, S[xns] = 0;\n            slack[xs] = 0, set_slack(xns);\n\
    \            q_push(xns);\n        }\n        S[xr] = 1, pa[xr] = pa[b];\n   \
    \     for (size_t i = pr + 1; i < flo[b].size(); i++) {\n            int xs =\
    \ flo[b][i];\n            S[xs] = -1, set_slack(xs);\n        }\n        st[b]\
    \ = 0;\n    }\n    bool on_found_edge(const Edge &e) {\n        int u = st[e.u],\
    \ v = st[e.v];\n        if (S[v] == -1) {\n            pa[v] = e.u, S[v] = 1;\n\
    \            int nu = st[mate[v]];\n            slack[v] = slack[nu] = 0;\n  \
    \          S[nu] = 0, q_push(nu);\n        } else if (S[v] == 0) {\n         \
    \   int lca = get_lca(u, v);\n            if (!lca) {\n                augment(u,\
    \ v), augment(v, u);\n                return true;\n            }\n          \
    \  add_blossom(u, lca, v);\n        }\n        return false;\n    }\n    bool\
    \ matching() {\n        for (int x = 1; x <= nx; x++) S[x] = -1, slack[x] = 0;\n\
    \        que.clear(), qh = 0;\n        for (int x = 1; x <= nx; x++)\n       \
    \     if (st[x] == x && !mate[x]) pa[x] = 0, S[x] = 0, q_push(x);\n        if\
    \ (que.empty()) return false;\n        while (true) {\n            while (qh <\
    \ que.size()) {\n                int u = que[qh++];\n                if (S[st[u]]\
    \ == 1) continue;\n                for (int v = 1; v <= n; v++) {\n          \
    \          if (g[u][v].w > 0 && st[u] != st[v]) {\n                        if\
    \ (e_delta(g[u][v]) == 0) {\n                            if (on_found_edge(g[u][v]))\
    \ return true;\n                        } else {\n                           \
    \ update_slack(u, st[v]);\n                        }\n                    }\n\
    \                }\n            }\n            W d = numeric_limits<W>::max();\n\
    \            for (int b = n + 1; b <= nx; b++)\n                if (st[b] == b\
    \ && S[b] == 1) d = std::min(d, lab[b] / 2);\n            for (int x = 1; x <=\
    \ nx; x++) {\n                if (st[x] == x && slack[x]) {\n                \
    \    if (S[x] == -1) d = std::min(d, e_delta(g[slack[x]][x]));\n             \
    \       else if (S[x] == 0) d = std::min(d, e_delta(g[slack[x]][x]) / 2);\n  \
    \              }\n            }\n            // \u5916\u5074\u306E\u9802\u70B9\
    \u306E\u30E9\u30D9\u30EB\u304C 0 \u306B\u306A\u308B\u306A\u3089\uFF0C\u3053\u308C\
    \u4EE5\u4E0A\u91CD\u307F\u3092\u5897\u3084\u305B\u306A\u3044 (\u5148\u306B\u5224\
    \u5B9A\u3057\u3066\u304B\u3089\u52D5\u304B\u3059)\n            for (int u = 1;\
    \ u <= n; u++)\n                if (S[st[u]] == 0 && lab[u] <= d) return false;\n\
    \            for (int u = 1; u <= n; u++) {\n                if (S[st[u]] == 0)\
    \ lab[u] -= d;\n                else if (S[st[u]] == 1) lab[u] += d;\n       \
    \     }\n            for (int b = n + 1; b <= nx; b++) {\n                if (st[b]\
    \ == b) {\n                    if (S[st[b]] == 0) lab[b] += d * 2;\n         \
    \           else if (S[st[b]] == 1) lab[b] -= d * 2;\n                }\n    \
    \        }\n            que.clear(), qh = 0;\n            for (int x = 1; x <=\
    \ nx; x++)\n                if (st[x] == x && slack[x] && st[slack[x]] != x &&\
    \ e_delta(g[slack[x]][x]) == 0)\n                    if (on_found_edge(g[slack[x]][x]))\
    \ return true;\n            for (int b = n + 1; b <= nx; b++)\n              \
    \  if (st[b] == b && S[b] == 1 && lab[b] == 0) expand_blossom(b);\n        }\n\
    \        return false;\n    }\n};\n#line 2 \"template.hpp\"\nusing namespace std;\n\
    #if __has_include(<atcoder/all>)\n#include <atcoder/all>\nusing namespace atcoder;\n\
    #endif\n// QCfium\u6CD5\u3092\u4F7F\u3046\u6642\u306F\u30B3\u30E1\u30F3\u30C8\u30A2\
    \u30A6\u30C8\u3092\u5916\u3059\n/*/\n#pragma GCC optimize(\"Ofast,unroll-loops,no-stack-protector,fast-math\"\
    )\n#pragma GCC target(\"avx2,bmi,bmi2,lzcnt,popcnt\")\n#pragma GCC target(\"avx,avx2,fma\"\
    )\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma\"\
    )\n//*/\n#define rep(i,n) for(int i=0;i<n;i++)\n#define Rep(i,a,b) for(int i=a;i<b;i++)\n\
    #define ALL(x) (x).begin(),(x).end()\n#define dbgv(x); for(auto now : x) cout\
    \ << now << \" \"; cout << endl;\n//using P = pair<int,int>;\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\ntypedef pair<int, int> pii;\ntypedef\
    \ pair<ll, ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line\
    \ 4 \"graph/bipartite_edge_coloring.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u8FBA\u5F69\u8272 (\u6700\u5927\u6B21\
    \u6570 \u0394 \u8272\u3067\uFF0C\u540C\u3058\u9802\u70B9\u306B\u63A5\u3059\u308B\
    \u8FBA\u306E\u8272\u304C\u5168\u3066\u7570\u306A\u308B\u3088\u3046\u306B\u5857\
    \u308B\uFF0EK\u0151nig \u306E\u5B9A\u7406\u3088\u308A \u0394 \u8272\u3067\u8DB3\
    \u308A\u308B)\n// 1. \u9802\u70B9\u3092\u307E\u3068\u3081\u3066 (\u6B21\u6570\u306E\
    \u548C\u304C \u0394 \u4EE5\u4E0B\u306B\u306A\u308B\u3088\u3046\u306B) \u4E21\u5074\
    \ k \u9802\u70B9\u305A\u3064\u306B\u3057\uFF0C\u30C0\u30DF\u30FC\u8FBA\u3092\u8DB3\
    \u3057\u3066 \u0394-\u6B63\u5247\u306A\u4E8C\u90E8\u591A\u91CD\u30B0\u30E9\u30D5\
    \u306B\u3059\u308B\n// 2. \u0394 \u304C\u5947\u6570\u306A\u3089\u5B8C\u5168\u30DE\
    \u30C3\u30C1\u30F3\u30B0 (\u6B63\u5247\u4E8C\u90E8\u30B0\u30E9\u30D5\u306B\u306F\
    \u5FC5\u305A\u3042\u308B) \u3092 1 \u8272\u3067\u5857\u3063\u3066\u53D6\u308A\u9664\
    \u304F\n//    \u0394 \u304C\u5076\u6570\u306A\u3089\u30AA\u30A4\u30E9\u30FC\u9589\
    \u8DEF\u306B\u6CBF\u3063\u3066\u8FBA\u3092\u4EA4\u4E92\u306B 2 \u3064\u306B\u5206\
    \u3051 (\u5404\u9802\u70B9\u3067\u534A\u5206\u305A\u3064\u306B\u306A\u308B)\uFF0C\
    \u305D\u308C\u305E\u308C\u3092\u518D\u5E30\u7684\u306B\u5857\u308B\n// O(m \u221A\
    n log \u0394)\n// \u8FD4\u308A\u5024: {\u8272\u6570 \u0394, \u5404\u8FBA\u306E\
    \u8272 (0 .. \u0394-1)}\ninline pair<int, vector<int>> bipartite_edge_coloring(int\
    \ L, int R, const vector<pair<int, int>> &edges) {\n    int m = edges.size();\n\
    \    if (m == 0) return {0, {}};\n    vector<int> degl(L, 0), degr(R, 0);\n  \
    \  for (auto [a, b] : edges) degl[a]++, degr[b]++;\n    int D = std::max(*max_element(degl.begin(),\
    \ degl.end()), *max_element(degr.begin(), degr.end()));\n    // 1. \u9802\u70B9\
    \u3092\u307E\u3068\u3081\u308B (\u9806\u306B\u8A70\u3081\u308B)\n    auto pack\
    \ = [&](const vector<int> &deg, vector<int> &grp) {\n        int k = 0, cur =\
    \ 0;\n        grp.assign(deg.size(), 0);\n        for (size_t v = 0; v < deg.size();\
    \ v++) {\n            if (cur + deg[v] > D) k++, cur = 0;\n            grp[v]\
    \ = k, cur += deg[v];\n        }\n        return k + 1;\n    };\n    vector<int>\
    \ gl, gr;\n    int kl = pack(degl, gl), kr = pack(degr, gr), k = std::max(kl,\
    \ kr);\n    vector<int> el(k, 0), er(k, 0);  // \u307E\u3068\u3081\u305F\u9802\
    \u70B9\u306E\u6B21\u6570\n    vector<pair<int, int>> E;        // \u307E\u3068\
    \u3081\u305F\u30B0\u30E9\u30D5\u306E\u8FBA (\u5DE6 0..k-1\uFF0C\u53F3 0..k-1)\n\
    \    E.reserve((size_t)k * D);\n    for (auto [a, b] : edges) E.push_back({gl[a],\
    \ gr[b]}), el[gl[a]]++, er[gr[b]]++;\n    // \u30C0\u30DF\u30FC\u8FBA\u3067 \u0394\
    -\u6B63\u5247\u306B\u3059\u308B (\u4E0D\u8DB3\u3057\u3066\u3044\u308B\u5DE6\u3068\
    \u53F3\u3092\u9806\u306B\u7D50\u3076)\n    for (int x = 0, y = 0; x < k; x++)\
    \ {\n        while (el[x] < D) {\n            while (er[y] == D) y++;\n      \
    \      int f = std::min(D - el[x], D - er[y]);\n            for (int t = 0; t\
    \ < f; t++) E.push_back({x, y});\n            el[x] += f, er[y] += f;\n      \
    \  }\n    }\n    int M = E.size();\n    vector<int> color(M, -1);\n    // 2. \u518D\
    \u5E30 (\u660E\u793A\u7684\u306A\u30B9\u30BF\u30C3\u30AF\u3067): (\u8FBA\u306E\
    \u96C6\u5408, \u6B21\u6570, \u4F7F\u3046\u8272\u306E\u5148\u982D)\n    struct\
    \ Task {\n        vector<int> es;\n        int deg, base;\n    };\n    vector<Task>\
    \ stk;\n    {\n        vector<int> all(M);\n        iota(all.begin(), all.end(),\
    \ 0);\n        stk.push_back({all, D, 0});\n    }\n    vector<int> head(2 * k),\
    \ nxt, used_mark;\n    while (!stk.empty()) {\n        Task t = std::move(stk.back());\n\
    \        stk.pop_back();\n        if (t.deg == 0) continue;\n        if (t.deg\
    \ == 1) {\n            for (int e : t.es) color[e] = t.base;\n            continue;\n\
    \        }\n        if (t.deg & 1) {\n            // \u5B8C\u5168\u30DE\u30C3\u30C1\
    \u30F3\u30B0\u3092 1 \u8272\u3067\u5857\u308B\n            BipartiteMatching bm(k,\
    \ k);\n            bm.reserve(t.es.size());\n            for (int e : t.es) bm.add_edge(E[e].first,\
    \ E[e].second);\n            int got = bm.solve();\n            assert(got ==\
    \ k);\n            // \u30DE\u30C3\u30C1\u3057\u305F\u7D44 (\u5DE6, \u53F3) \u3054\
    \u3068\u306B\u8FBA\u3092 1 \u672C\u9078\u3076\n            vector<char> taken(k,\
    \ 0);\n            vector<int> rest;\n            rest.reserve(t.es.size() - k);\n\
    \            for (int e : t.es) {\n                int a = E[e].first;\n     \
    \           if (!taken[a] && bm.match_l[a] == E[e].second) taken[a] = 1, color[e]\
    \ = t.base + t.deg - 1;\n                else rest.push_back(e);\n           \
    \ }\n            stk.push_back({std::move(rest), t.deg - 1, t.base});\n      \
    \      continue;\n        }\n        // \u30AA\u30A4\u30E9\u30FC\u5206\u5272:\
    \ \u9802\u70B9 (\u5DE6 x \u2192 x\uFF0C\u53F3 y \u2192 k + y) \u3054\u3068\u306B\
    \u8FBA\u306E\u30EA\u30B9\u30C8\n        int sz = t.es.size();\n        fill(head.begin(),\
    \ head.end(), -1);\n        nxt.assign(2 * sz, -1);\n        used_mark.assign(sz,\
    \ 0);\n        // \u534A\u8FBA 2i \u306F\u5DE6\u304B\u3089\uFF0C2i+1 \u306F\u53F3\
    \u304B\u3089\n        for (int i = 0; i < sz; i++) {\n            auto [a, b]\
    \ = E[t.es[i]];\n            nxt[2 * i] = head[a], head[a] = 2 * i;\n        \
    \    nxt[2 * i + 1] = head[k + b], head[k + b] = 2 * i + 1;\n        }\n     \
    \   vector<int> A, B;\n        A.reserve(sz / 2), B.reserve(sz / 2);\n       \
    \ // \u5404\u9023\u7D50\u6210\u5206\u3067\u30AA\u30A4\u30E9\u30FC\u9589\u8DEF\u3092\
    \u4F5C\u308A\uFF0C\u9589\u8DEF\u306E\u9806\u306B\u4EA4\u4E92\u306B\u5206\u3051\
    \u308B (Hierholzer\uFF0C\u975E\u518D\u5E30)\n        vector<pair<int, int>> st;\
    \  // (\u9802\u70B9, \u6765\u305F\u8FBA)\n        vector<int> circuit;\n     \
    \   for (int s = 0; s < 2 * k; s++) {\n            if (head[s] < 0) continue;\n\
    \            circuit.clear();\n            st.clear(), st.push_back({s, -1});\n\
    \            while (!st.empty()) {\n                int v = st.back().first;\n\
    \                while (head[v] >= 0 && used_mark[head[v] >> 1]) head[v] = nxt[head[v]];\n\
    \                if (head[v] < 0) {\n                    if (st.back().second\
    \ >= 0) circuit.push_back(st.back().second);\n                    st.pop_back();\n\
    \                    continue;\n                }\n                int h = head[v],\
    \ i = h >> 1;\n                used_mark[i] = 1;\n                head[v] = nxt[h];\n\
    \                auto [a, b] = E[t.es[i]];\n                int to = (h & 1) ?\
    \ a : k + b;\n                st.push_back({to, i});\n            }\n        \
    \    for (size_t j = 0; j < circuit.size(); j++) (j & 1 ? B : A).push_back(t.es[circuit[j]]);\n\
    \        }\n        stk.push_back({std::move(A), t.deg / 2, t.base});\n      \
    \  stk.push_back({std::move(B), t.deg / 2, t.base + t.deg / 2});\n    }\n    vector<int>\
    \ res(color.begin(), color.begin() + m);\n    return {D, res};\n}\n#line 2 \"\
    template.hpp\"\nusing namespace std;\n#if __has_include(<atcoder/all>)\n#include\
    \ <atcoder/all>\nusing namespace atcoder;\n#endif\n// QCfium\u6CD5\u3092\u4F7F\
    \u3046\u6642\u306F\u30B3\u30E1\u30F3\u30C8\u30A2\u30A6\u30C8\u3092\u5916\u3059\
    \n/*/\n#pragma GCC optimize(\"Ofast,unroll-loops,no-stack-protector,fast-math\"\
    )\n#pragma GCC target(\"avx2,bmi,bmi2,lzcnt,popcnt\")\n#pragma GCC target(\"avx,avx2,fma\"\
    )\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma\"\
    )\n//*/\n#define rep(i,n) for(int i=0;i<n;i++)\n#define Rep(i,a,b) for(int i=a;i<b;i++)\n\
    #define ALL(x) (x).begin(),(x).end()\n#define dbgv(x); for(auto now : x) cout\
    \ << now << \" \"; cout << endl;\n//using P = pair<int,int>;\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\ntypedef pair<int, int> pii;\ntypedef\
    \ pair<ll, ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line\
    \ 4 \"graph/st_numbering.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// st \u756A\u53F7\u4ED8\u3051\uFF0Es \u304C\u6700\u5C0F\uFF0Ct \u304C\u6700\
    \u5927\u3067\uFF0C\u4ED6\u306E\u5168\u3066\u306E\u9802\u70B9\u304C\u300C\u756A\
    \u53F7\u304C\u5C0F\u3055\u3044\u96A3\u63A5\u9802\u70B9\u300D\u3068\u300C\u5927\
    \u304D\u3044\u96A3\u63A5\u9802\u70B9\u300D\u3092\u4E21\u65B9\u6301\u3064\u3088\
    \u3046\u306A\u756A\u53F7\u4ED8\u3051\uFF0E\n// \u5B58\u5728\u3059\u308B \u21D4\
    \ G \u306B\u8FBA (s, t) \u3092\u8DB3\u3057\u305F\u30B0\u30E9\u30D5\u304C\u4E8C\
    \u91CD\u9802\u70B9\u9023\u7D50 (n >= 3 \u306E\u3068\u304D)\n// s \u3092\u6839\uFF0C\
    t \u3092\u6700\u521D\u306E\u5B50\u3068\u3059\u308B DFS \u3067 lowlink \u3092\u6C42\
    \u3081\uFF0C\u5148\u884C\u9806\u306B\u5404\u9802\u70B9\u3092\u300C\u89AA\u306E\
    \u76F4\u524D\u304B\u76F4\u5F8C\u300D\u306B\u9023\u7D50\u30EA\u30B9\u30C8\u3078\
    \u633F\u5165\u3059\u308B (Tarjan)\uFF0EO(n + m)\n// \u8FD4\u308A\u5024: \u5404\
    \u9802\u70B9\u306E\u756A\u53F7 (0 .. n-1)\uFF0E\u5B58\u5728\u3057\u306A\u3051\u308C\
    \u3070\u7A7A\ninline vector<int> st_numbering(int n, const vector<pair<int, int>>\
    \ &edges, int s, int t) {\n    if (n == 1) return {0};\n    if (n == 2) {\n  \
    \      // \u8FBA (s, t) \u3092\u8DB3\u3057\u3066\u8003\u3048\u308B\u306E\u306F\
    \ n >= 3 \u306E\u3068\u304D\u3060\u3051\u6B63\u3057\u3044\uFF0En = 2 \u3067\u306F\
    \u5B9F\u969B\u306B\u8FBA s - t \u304C\u5FC5\u8981\n        for (auto [a, b] :\
    \ edges)\n            if ((a == s && b == t) || (a == t && b == s)) {\n      \
    \          vector<int> num(2);\n                num[s] = 0, num[t] = 1;\n    \
    \            return num;\n            }\n        return {};\n    }\n    vector<pair<int,\
    \ int>> el;\n    el.reserve(2 * edges.size() + 2);\n    el.push_back({s, t}),\
    \ el.push_back({t, s});  // \u8FBA (s, t) \u3092\u8DB3\u3059 (s \u304B\u3089\u6700\
    \u521D\u306B t \u3078\u964D\u308A\u308B)\n    for (auto [a, b] : edges) el.push_back({a,\
    \ b}), el.push_back({b, a});\n    CSR<int> g(n, el);\n    vector<int> pre(n, -1),\
    \ low(n), par(n, -1), order, it(n), call;\n    order.reserve(n);\n    int cnt\
    \ = 0;\n    pre[s] = low[s] = cnt++, order.push_back(s), it[s] = g.start[s], call.push_back(s);\n\
    \    vector<char> skipped(n, 0);  // \u89AA\u3078\u306E\u8FBA\u3092 1 \u672C\u3060\
    \u3051\u98DB\u3070\u3057\u305F\u304B\n    while (!call.empty()) {\n        int\
    \ v = call.back();\n        if (it[v] < g.start[v + 1]) {\n            int w =\
    \ g.elist[it[v]++];\n            if (w == par[v] && !skipped[v]) {\n         \
    \       skipped[v] = 1;\n                continue;\n            }\n          \
    \  if (pre[w] < 0) {\n                par[w] = v, pre[w] = low[w] = cnt++, order.push_back(w),\
    \ it[w] = g.start[w];\n                call.push_back(w);\n            } else\
    \ {\n                low[v] = std::min(low[v], pre[w]);\n            }\n     \
    \       continue;\n        }\n        call.pop_back();\n        if (!call.empty())\
    \ low[call.back()] = std::min(low[call.back()], low[v]);\n    }\n    if (cnt !=\
    \ n) return {};  // \u975E\u9023\u7D50\n    // \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\
    \u304B: \u6839 s \u306E\u5B50\u306F t \u3060\u3051\uFF0C\u4ED6\u306E\u6728\u306E\
    \u8FBA (p, c) \u306F low[c] < pre[p]\n    for (int v = 0; v < n; v++) {\n    \
    \    if (v == s) continue;\n        int p = par[v];\n        if (p == s) {\n \
    \           if (v != t) return {};\n        } else if (low[v] >= pre[p]) {\n \
    \           return {};\n        }\n    }\n    // low \u3092\u9802\u70B9\u3067\u6301\
    \u3061\u76F4\u3059 (pre \u306E\u5024 \u2192 \u9802\u70B9)\n    // sign[v] = -1\
    \ \u306A\u3089 v \u306F\u300C\u89AA\u3088\u308A\u524D\u300D\u5074\u306B\u3044\u308B\
    \u5370\n    vector<int> who(n);\n    for (int v = 0; v < n; v++) who[pre[v]] =\
    \ v;\n    vector<int> nx(n, -1), pv(n, -1);\n    vector<char> minus(n, 0);\n \
    \   // \u30EA\u30B9\u30C8: s \u2192 t\n    nx[s] = t, pv[t] = s, minus[s] = 1;\n\
    \    for (int v : order) {\n        if (v == s || v == t) continue;\n        int\
    \ p = par[v], lw = who[low[v]];\n        if (minus[lw]) {\n            // p \u306E\
    \u76F4\u524D\u306B\u633F\u5165\n            int q = pv[p];\n            nx[q]\
    \ = v, pv[v] = q, nx[v] = p, pv[p] = v;\n            minus[p] = 0;\n        }\
    \ else {\n            // p \u306E\u76F4\u5F8C\u306B\u633F\u5165\n            int\
    \ q = nx[p];\n            nx[p] = v, pv[v] = p, nx[v] = q;\n            if (q\
    \ >= 0) pv[q] = v;\n            minus[p] = 1;\n        }\n    }\n    vector<int>\
    \ num(n);\n    int k = 0;\n    for (int v = s; v >= 0; v = nx[v]) num[v] = k++;\n\
    \    return num;\n}\n#line 2 \"template.hpp\"\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
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
    \ 3 \"graph/min_cost_b_flow.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u6700\u5C0F\u8CBB\u7528 b-flow (\u4F9B\u7D66\u30FB\u9700\u8981\u3068\uFF0C\
    \u8FBA\u306E\u6D41\u91CF\u306E\u4E0B\u9650\u30FB\u4E0A\u9650\u30FB\u8CBB\u7528\
    )\uFF0E\u5BB9\u91CF\u30B9\u30B1\u30FC\u30EA\u30F3\u30B0\u6CD5\n//   \u5404\u9802\
    \u70B9 v: (\u51FA\u3066\u3044\u304F\u6D41\u91CF) - (\u5165\u3063\u3066\u304F\u308B\
    \u6D41\u91CF) = b[v]\uFF0C\u5404\u8FBA e: lower[e] <= f[e] <= upper[e]\uFF0C\u03A3\
    \ cost[e] f[e] \u3092\u6700\u5C0F\u5316\n// \u0394 = 2^k, ..., 1 \u306E\u9806\u306B\
    \uFF0C\u300C\u6B8B\u4F59\u5BB9\u91CF\u304C \u0394 \u4EE5\u4E0A\u306E\u8FBA\u300D\
    \u3060\u3051\u306E\u30B0\u30E9\u30D5\u3067\uFF0C\u8D85\u904E\u304C \u0394 \u4EE5\
    \u4E0A\u306E\u9802\u70B9\u304B\u3089\u4E0D\u8DB3\u304C \u0394 \u4EE5\u4E0A\u306E\
    \u9802\u70B9\u3078\n// \u0394 \u305A\u3064\u6700\u77ED\u8DEF (\u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\u4ED8\u304D Dijkstra) \u3067\u6D41\u3059\uFF0E\u5404\u6BB5\u306E\
    \u59CB\u3081\u306B\uFF0C\u6B8B\u4F59\u5BB9\u91CF \u0394 \u4EE5\u4E0A\u3067\u88AB\
    \u7D04\u8CBB\u7528\u304C\u8CA0\u306E\u8FBA\u306F\u98FD\u548C\u3055\u305B\u308B\
    \uFF0E\n// \u6700\u5F8C\u306B\u6B8B\u4F59\u30B0\u30E9\u30D5\u3067 Bellman-Ford\
    \ \u3092\u3057\u3066\u53CC\u5BFE (\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB) p \u3092\
    \u6C42\u3081\u308B (c[e] + p[s] - p[t] >= 0 \u304C\u6B8B\u4F59\u8FBA\u3067\u6210\
    \u308A\u7ACB\u3064)\n// O(m log U \xB7 (m + n) log n) (U \u306F\u5BB9\u91CF\u30FB\
    \u4F9B\u7D66\u306E\u6700\u5927\u5024)\ntemplate <class Cap = long long, class\
    \ Cost = long long>\nstruct MinCostBFlow {\n    struct Arc {\n        int to,\
    \ rev;\n        Cap cap;\n        Cost cost;\n    };\n    int n;\n    vector<vector<Arc>>\
    \ g;\n    vector<Cap> b;\n    vector<pair<int, int>> pos;  // \u8FBA e \u306E\
    \ (\u9802\u70B9, \u6DFB\u5B57)\n    vector<Cap> lower;\n    vector<Cost> pot;\n\
    \n    MinCostBFlow(int n) : n(n), g(n), b(n, 0), pot(n, 0) {}\n\n    // \u9802\
    \u70B9 v \u306E\u4F9B\u7D66\u3092 x \u5897\u3084\u3059 (\u8CA0\u306A\u3089\u9700\
    \u8981)\n    void add_supply(int v, Cap x) { b[v] += x; }\n    void add_demand(int\
    \ v, Cap x) { b[v] -= x; }\n\n    // \u8FBA u \u2192 v (\u6D41\u91CF [lo, hi]\uFF0C\
    \u8CBB\u7528 c) \u3092\u8FFD\u52A0\u3057\uFF0C\u756A\u53F7\u3092\u8FD4\u3059\n\
    \    int add_edge(int u, int v, Cap lo, Cap hi, Cost c) {\n        assert(lo <=\
    \ hi);\n        int id = pos.size();\n        pos.push_back({u, (int)g[u].size()});\n\
    \        lower.push_back(lo);\n        int ru = g[u].size(), rv = g[v].size()\
    \ + (u == v);\n        g[u].push_back({v, rv, hi - lo, c});\n        g[v].push_back({u,\
    \ ru, 0, -c});\n        // \u4E0B\u9650\u5206\u3092\u5148\u306B\u6D41\u3057\u3066\
    \u304A\u304F\n        b[u] -= lo, b[v] += lo;\n        return id;\n    }\n\n \
    \   // \u89E3\u3051\u305F\u3089 true (\u5B9F\u884C\u53EF\u80FD\u3067\u306A\u3051\
    \u308C\u3070 false)\n    bool solve() {\n        vector<Cap> ex = b;  // \u8D85\
    \u904E (\u6B63\u306A\u3089\u51FA\u3057\u305F\u3044\u91CF)\n        Cap total =\
    \ 0, mx = 1;\n        for (int v = 0; v < n; v++) total += ex[v], mx = std::max({mx,\
    \ ex[v], -ex[v]});\n        if (total != 0) return false;\n        for (int v\
    \ = 0; v < n; v++)\n            for (auto &a : g[v]) mx = std::max(mx, a.cap);\n\
    \        Cap delta = 1;\n        while (delta <= mx / 2) delta *= 2;\n       \
    \ const Cost INF = numeric_limits<Cost>::max();\n        vector<Cost> dist(n);\n\
    \        vector<int> pv(n), pe(n);\n        vector<char> done(n);\n        for\
    \ (; delta >= 1; delta /= 2) {\n            // \u6B8B\u4F59\u5BB9\u91CF delta\
    \ \u4EE5\u4E0A\u3067\u88AB\u7D04\u8CBB\u7528\u304C\u8CA0\u306E\u8FBA\u3092\u98FD\
    \u548C\u3055\u305B\u308B\n            for (int v = 0; v < n; v++) {\n        \
    \        for (auto &a : g[v]) {\n                    if (a.cap >= delta && a.cost\
    \ + pot[v] - pot[a.to] < 0) {\n                        Cap f = a.cap;\n      \
    \                  a.cap -= f, g[a.to][a.rev].cap += f;\n                    \
    \    ex[v] -= f, ex[a.to] += f;\n                    }\n                }\n  \
    \          }\n            while (true) {\n                // \u8D85\u904E >= delta\
    \ \u306E\u9802\u70B9\u304B\u3089\uFF0C\u4E0D\u8DB3 >= delta \u306E\u9802\u70B9\
    \u3078\u306E\u6700\u77ED\u8DEF (\u591A\u59CB\u70B9 Dijkstra)\n               \
    \ priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<>> pq;\n  \
    \              fill(dist.begin(), dist.end(), INF);\n                fill(done.begin(),\
    \ done.end(), 0);\n                for (int v = 0; v < n; v++)\n             \
    \       if (ex[v] >= delta) dist[v] = 0, pv[v] = -1, pq.push({0, v});\n      \
    \          if (pq.empty()) break;\n                int t = -1;\n             \
    \   Cost dt = 0;\n                while (!pq.empty()) {\n                    auto\
    \ [d, v] = pq.top();\n                    pq.pop();\n                    if (done[v])\
    \ continue;\n                    done[v] = 1;\n                    if (ex[v] <=\
    \ -delta) {\n                        t = v, dt = d;\n                        break;\n\
    \                    }\n                    for (int i = 0; i < (int)g[v].size();\
    \ i++) {\n                        auto &a = g[v][i];\n                       \
    \ if (a.cap < delta) continue;\n                        Cost nd = d + a.cost +\
    \ pot[v] - pot[a.to];\n                        if (nd < dist[a.to]) dist[a.to]\
    \ = nd, pv[a.to] = v, pe[a.to] = i, pq.push({nd, a.to});\n                   \
    \ }\n                }\n                if (t < 0) break;\n                //\
    \ \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u66F4\u65B0 (\u88AB\u7D04\u8CBB\u7528\
    \u3092\u975E\u8CA0\u306B\u4FDD\u3064)\n                for (int v = 0; v < n;\
    \ v++) pot[v] += std::min(dist[v], dt);\n                // delta \u6D41\u3059\
    \n                for (int v = t; pv[v] >= 0; v = pv[v]) {\n                 \
    \   auto &a = g[pv[v]][pe[v]];\n                    a.cap -= delta, g[v][a.rev].cap\
    \ += delta;\n                }\n                int s = t;\n                while\
    \ (pv[s] >= 0) s = pv[s];\n                ex[s] -= delta, ex[t] += delta;\n \
    \           }\n        }\n        for (int v = 0; v < n; v++)\n            if\
    \ (ex[v] != 0) return false;\n        // \u53CC\u5BFE: \u6B8B\u4F59\u30B0\u30E9\
    \u30D5\u3067 Bellman-Ford (\u5168\u9802\u70B9\u3092\u59CB\u70B9 0 \u3068\u3057\
    \u3066)\n        fill(pot.begin(), pot.end(), 0);\n        for (int iter = 0;\
    \ iter < n; iter++) {\n            bool upd = false;\n            for (int v =\
    \ 0; v < n; v++)\n                for (auto &a : g[v])\n                    if\
    \ (a.cap > 0 && pot[v] + a.cost < pot[a.to]) pot[a.to] = pot[v] + a.cost, upd\
    \ = true;\n            if (!upd) break;\n        }\n        return true;\n   \
    \ }\n\n    Cap flow(int e) const {\n        auto [v, i] = pos[e];\n        return\
    \ lower[e] + g[g[v][i].to][g[v][i].rev].cap;\n    }\n    Cost potential(int v)\
    \ const { return pot[v]; }\n\n    // \u8CBB\u7528\u306E\u5408\u8A08 (\u5927\u304D\
    \u304F\u306A\u308A\u3046\u308B\u306E\u3067 __int128)\n    __int128 cost() const\
    \ {\n        __int128 res = 0;\n        for (int e = 0; e < (int)pos.size(); e++)\
    \ {\n            auto [v, i] = pos[e];\n            res += (__int128)g[v][i].cost\
    \ * flow(e);\n        }\n        return res;\n    }\n};\n#line 12 \"test/unittest/graph_optimization.test.cpp\"\
    \n\n// \u6700\u5C0F\u5168\u57DF\u6728\u30FB\u6700\u5C0F\u6709\u5411\u5168\u57DF\
    \u6728\u30FB\u5272\u5F53\u554F\u984C\u30FB\u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\
    \u30B0\u30FB\u4E00\u822C\u30DE\u30C3\u30C1\u30F3\u30B0\u30FB\u91CD\u307F\u4ED8\
    \u304D\u4E00\u822C\u30DE\u30C3\u30C1\u30F3\u30B0\u30FB\n// \u4E8C\u90E8\u30B0\u30E9\
    \u30D5\u306E\u8FBA\u5F69\u8272\u30FBst \u756A\u53F7\u4ED8\u3051\u30FB\u6700\u5C0F\
    \u8CBB\u7528 b-flow \u3092\u5C0F\u3055\u3044\u5165\u529B\u306E\u5168\u63A2\u7D22\
    \u3068\u7167\u5408\u3059\u308B\n\nint main() {\n    mt19937_64 rng(41);\n    auto\
    \ rnd = [&](long long lo, long long hi) { return lo + (long long)(rng() % (hi\
    \ - lo + 1)); };\n    for (int it = 0; it < 1500; it++) {\n        int n = rnd(1,\
    \ 6);\n        // \u6700\u5C0F\u5168\u57DF\u6728 (\u9023\u7D50\u306A\u3089 n-1\
    \ \u672C\uFF0E\u8FBA\u306E\u90E8\u5206\u96C6\u5408\u3092\u5168\u63A2\u7D22)\n\
    \        {\n            int m = rnd(0, 8);\n            vector<tuple<int, int,\
    \ long long>> es(m);\n            for (auto &[a, b, c] : es) a = rnd(0, n - 1),\
    \ b = rnd(0, n - 1), c = rnd(0, 9);\n            auto [w, used] = minimum_spanning_tree(n,\
    \ es);\n            long long best = LLONG_MAX;\n            int best_cnt = -1;\n\
    \            for (int mask = 0; mask < (1 << m); mask++) {\n                vector<int>\
    \ p(n);\n                iota(p.begin(), p.end(), 0);\n                auto f\
    \ = [&](auto self, int x) -> int { return p[x] == x ? x : p[x] = self(self, p[x]);\
    \ };\n                bool ok = true;\n                long long s = 0;\n    \
    \            int cnt = 0;\n                for (int i = 0; i < m; i++)\n     \
    \               if (mask >> i & 1) {\n                        auto [a, b, c] =\
    \ es[i];\n                        if (f(f, a) == f(f, b)) ok = false;\n      \
    \                  p[f(f, a)] = f(f, b), s += c, cnt++;\n                    }\n\
    \                if (!ok) continue;\n                if (cnt > best_cnt || (cnt\
    \ == best_cnt && s < best)) best_cnt = cnt, best = s;\n            }\n       \
    \     assert((int)used.size() == best_cnt && w == best);\n        }\n        //\
    \ \u6700\u5C0F\u6709\u5411\u5168\u57DF\u6728 (\u5404\u9802\u70B9\u306E\u89AA\u3092\
    \u5168\u63A2\u7D22)\n        {\n            int m = rnd(0, 10), r = rnd(0, n -\
    \ 1);\n            vector<tuple<int, int, long long>> es;\n            set<pair<int,\
    \ int>> seen;\n            for (int i = 0; i < m; i++) {\n                int\
    \ a = rnd(0, n - 1), b = rnd(0, n - 1);\n                if (a == b || seen.count({a,\
    \ b})) continue;\n                seen.insert({a, b}), es.push_back({a, b, rnd(0,\
    \ 9)});\n            }\n            // in[v] = v \u306B\u5165\u308B\u8FBA\u306E\
    \u5019\u88DC\n            vector<vector<int>> in(n);\n            for (int i =\
    \ 0; i < (int)es.size(); i++) in[get<1>(es[i])].push_back(i);\n            long\
    \ long best = LLONG_MAX;\n            vector<int> choice(n, -1);\n           \
    \ auto rec = [&](auto self, int v) -> void {\n                if (v == n) {\n\
    \                    // \u5168\u9802\u70B9\u304C r \u304B\u3089\u5230\u9054\u3067\
    \u304D\u308B\u304B (\u89AA\u3092\u305F\u3069\u3063\u3066 r \u306B\u7740\u304F\u304B\
    )\n                    long long s = 0;\n                    for (int u = 0; u\
    \ < n; u++) {\n                        if (u == r) continue;\n               \
    \         s += get<2>(es[choice[u]]);\n                        int x = u, steps\
    \ = 0;\n                        while (x != r && steps <= n) x = get<0>(es[choice[x]]),\
    \ steps++;\n                        if (x != r) return;\n                    }\n\
    \                    best = std::min(best, s);\n                    return;\n\
    \                }\n                if (v == r) return self(self, v + 1);\n  \
    \              for (int e : in[v]) choice[v] = e, self(self, v + 1);\n       \
    \     };\n            rec(rec, 0);\n            auto [w, par] = directed_mst(n,\
    \ es, r);\n            if (best == LLONG_MAX) assert(par.empty());\n         \
    \   else {\n                assert(w == best && par[r] == r);\n              \
    \  long long s = 0;\n                for (int v = 0; v < n; v++) {\n         \
    \           if (v == r) continue;\n                    long long c = -1;\n   \
    \                 for (auto &[a, b, cc] : es)\n                        if (a ==\
    \ par[v] && b == v) c = cc;\n                    assert(c >= 0);\n           \
    \         s += c;\n                }\n                assert(s == best);\n   \
    \         }\n        }\n        // \u5272\u5F53\u554F\u984C (n \xD7 m\uFF0Cn <=\
    \ m)\n        {\n            int rows = rnd(1, 5), cols = rnd(rows, 6);\n    \
    \        vector<vector<long long>> a(rows, vector<long long>(cols));\n       \
    \     for (auto &row : a)\n                for (auto &x : row) x = rnd(-20, 20);\n\
    \            auto [w, p] = hungarian(a);\n            vector<int> perm(cols);\n\
    \            iota(perm.begin(), perm.end(), 0);\n            long long best =\
    \ LLONG_MAX;\n            do {\n                long long s = 0;\n           \
    \     for (int i = 0; i < rows; i++) s += a[i][perm[i]];\n                best\
    \ = std::min(best, s);\n            } while (next_permutation(perm.begin(), perm.end()));\n\
    \            long long s = 0;\n            set<int> cs(p.begin(), p.end());\n\
    \            for (int i = 0; i < rows; i++) s += a[i][p[i]];\n            assert(w\
    \ == best && s == best && (int)cs.size() == rows);\n        }\n        // \u4E8C\
    \u90E8\u30DE\u30C3\u30C1\u30F3\u30B0\u30FB\u8FBA\u5F69\u8272\n        {\n    \
    \        int L = rnd(1, 5), R = rnd(1, 5), m = rnd(0, 10);\n            vector<pair<int,\
    \ int>> es(m);\n            for (auto &[a, b] : es) a = rnd(0, L - 1), b = rnd(0,\
    \ R - 1);\n            BipartiteMatching bm(L, R);\n            for (auto [a,\
    \ b] : es) bm.add_edge(a, b);\n            int got = bm.solve();\n           \
    \ int best = 0;\n            for (int mask = 0; mask < (1 << m); mask++) {\n \
    \               vector<char> ul(L, 0), ur(R, 0);\n                bool ok = true;\n\
    \                for (int i = 0; i < m && ok; i++)\n                    if (mask\
    \ >> i & 1) {\n                        auto [a, b] = es[i];\n                \
    \        if (ul[a] || ur[b]) ok = false;\n                        ul[a] = ur[b]\
    \ = 1;\n                    }\n                if (ok) best = std::max(best, __builtin_popcount(mask));\n\
    \            }\n            assert(got == best);\n            auto mt = bm.matching();\n\
    \            assert((int)mt.size() == best);\n            set<pair<int, int>>\
    \ eset(es.begin(), es.end());\n            for (auto e : mt) assert(eset.count(e));\n\
    \            auto [K, col] = bipartite_edge_coloring(L, R, es);\n            int\
    \ D = 0;\n            vector<int> dl(L, 0), dr(R, 0);\n            for (auto [a,\
    \ b] : es) D = std::max({D, ++dl[a], ++dr[b]});\n            assert(K == D);\n\
    \            set<pair<int, int>> usedl, usedr;\n            for (int i = 0; i\
    \ < m; i++) {\n                assert(0 <= col[i] && col[i] < K);\n          \
    \      assert(usedl.insert({es[i].first, col[i]}).second);\n                assert(usedr.insert({es[i].second,\
    \ col[i]}).second);\n            }\n        }\n        // \u4E00\u822C\u30DE\u30C3\
    \u30C1\u30F3\u30B0\u30FB\u91CD\u307F\u4ED8\u304D\u4E00\u822C\u30DE\u30C3\u30C1\
    \u30F3\u30B0 (\u30D3\u30C3\u30C8 DP)\n        {\n            int nn = rnd(1, 8),\
    \ m = rnd(0, 14);\n            vector<vector<long long>> w(nn, vector<long long>(nn,\
    \ 0));\n            GeneralMatching gm(nn);\n            GeneralWeightedMatching<long\
    \ long> wm(nn);\n            for (int i = 0; i < m; i++) {\n                int\
    \ a = rnd(0, nn - 1), b = rnd(0, nn - 1);\n                if (a == b || w[a][b])\
    \ continue;\n                long long c = rnd(1, 10);\n                w[a][b]\
    \ = w[b][a] = c;\n                gm.add_edge(a, b), wm.add_edge(a, b, c);\n \
    \           }\n            vector<int> card(1 << nn, 0);\n            vector<long\
    \ long> wt(1 << nn, 0);\n            for (int mask = 1; mask < (1 << nn); mask++)\
    \ {\n                int v = __builtin_ctz(mask), rest = mask & ~(1 << v);\n \
    \               card[mask] = card[rest], wt[mask] = wt[rest];\n              \
    \  for (int u = 0; u < nn; u++)\n                    if ((rest >> u & 1) && w[v][u])\
    \ {\n                        card[mask] = std::max(card[mask], card[rest & ~(1\
    \ << u)] + 1);\n                        wt[mask] = std::max(wt[mask], wt[rest\
    \ & ~(1 << u)] + w[v][u]);\n                    }\n            }\n           \
    \ int full = (1 << nn) - 1;\n            assert(gm.solve() == card[full]);\n \
    \           for (auto [a, b] : gm.matching()) assert(w[a][b]);\n            auto\
    \ [tw, cnt] = wm.solve();\n            assert(tw == wt[full]);\n            long\
    \ long s = 0;\n            vector<char> usedv(nn, 0);\n            for (auto [a,\
    \ b] : wm.matching_edges()) {\n                assert(w[a][b] && !usedv[a] &&\
    \ !usedv[b]);\n                usedv[a] = usedv[b] = 1, s += w[a][b];\n      \
    \      }\n            assert(s == tw);\n        }\n        // st \u756A\u53F7\u4ED8\
    \u3051 (\u9806\u5217\u3092\u5168\u63A2\u7D22)\n        if (n >= 2) {\n       \
    \     int m = rnd(0, 8), s = rnd(0, n - 1), t = rnd(0, n - 2);\n            if\
    \ (t >= s) t++;\n            vector<pair<int, int>> es;\n            for (int\
    \ i = 0; i < m; i++) {\n                int a = rnd(0, n - 1), b = rnd(0, n -\
    \ 1);\n                if (a != b) es.push_back({a, b});\n            }\n    \
    \        auto valid = [&](const vector<int> &p) {\n                if (p[s] !=\
    \ 0 || p[t] != n - 1) return false;\n                for (int v = 0; v < n; v++)\
    \ {\n                    if (v == s || v == t) continue;\n                   \
    \ bool lo = false, hi = false;\n                    for (auto [a, b] : es) {\n\
    \                        int o = a == v ? b : (b == v ? a : -1);\n           \
    \             if (o < 0) continue;\n                        if (p[o] < p[v]) lo\
    \ = true;\n                        else hi = true;\n                    }\n  \
    \                  if (!lo || !hi) return false;\n                }\n        \
    \        // s \u304B\u3089 t \u306B\u8FBA\u304C\u3042\u308B\u304B (n = 2)\n  \
    \              if (n == 2) {\n                    bool e = false;\n          \
    \          for (auto [a, b] : es) e |= (a == s && b == t) || (a == t && b == s);\n\
    \                    return e;\n                }\n                return true;\n\
    \            };\n            vector<int> perm(n);\n            iota(perm.begin(),\
    \ perm.end(), 0);\n            bool exists = false;\n            do exists |=\
    \ valid(perm);\n            while (!exists && next_permutation(perm.begin(), perm.end()));\n\
    \            auto p = st_numbering(n, es, s, t);\n            assert(exists ==\
    \ !p.empty());\n            if (!p.empty()) assert(valid(p));\n        }\n   \
    \     // \u6700\u5C0F\u8CBB\u7528 b-flow (\u6D41\u91CF\u3092\u5168\u63A2\u7D22\
    \uFF0E\u5BB9\u91CF\u306F\u5C0F\u3055\u304F)\n        {\n            int nn = rnd(1,\
    \ 3), m = rnd(0, 4);\n            MinCostBFlow<long long, long long> mf(nn);\n\
    \            vector<long long> b(nn);\n            for (auto &x : b) x = rnd(-2,\
    \ 2);\n            long long sum = 0;\n            for (auto x : b) sum += x;\n\
    \            b[0] -= sum;  // \u548C\u3092 0 \u306B\n            for (int v =\
    \ 0; v < nn; v++) mf.add_supply(v, b[v]);\n            vector<array<long long,\
    \ 5>> es(m);\n            for (auto &e : es) {\n                e[0] = rnd(0,\
    \ nn - 1), e[1] = rnd(0, nn - 1), e[2] = rnd(0, 1), e[3] = e[2] + rnd(0, 2), e[4]\
    \ = rnd(-5, 5);\n                mf.add_edge(e[0], e[1], e[2], e[3], e[4]);\n\
    \            }\n            // \u5168\u63A2\u7D22\n            long long best\
    \ = LLONG_MAX;\n            vector<long long> f(m);\n            auto rec = [&](auto\
    \ self, int i) -> void {\n                if (i == m) {\n                    vector<long\
    \ long> bal(nn, 0);\n                    long long c = 0;\n                  \
    \  for (int j = 0; j < m; j++) bal[es[j][0]] += f[j], bal[es[j][1]] -= f[j], c\
    \ += es[j][4] * f[j];\n                    if (bal == b) best = std::min(best,\
    \ c);\n                    return;\n                }\n                for (f[i]\
    \ = es[i][2]; f[i] <= es[i][3]; f[i]++) self(self, i + 1);\n            };\n \
    \           rec(rec, 0);\n            bool ok = mf.solve();\n            assert(ok\
    \ == (best != LLONG_MAX));\n            if (ok) {\n                assert(mf.cost()\
    \ == (__int128)best);\n                vector<long long> bal(nn, 0);\n       \
    \         for (int j = 0; j < m; j++) {\n                    long long fl = mf.flow(j);\n\
    \                    assert(es[j][2] <= fl && fl <= es[j][3]);\n             \
    \       bal[es[j][0]] += fl, bal[es[j][1]] -= fl;\n                    long long\
    \ rc = es[j][4] + mf.potential(es[j][0]) - mf.potential(es[j][1]);\n         \
    \           if (fl > es[j][2]) assert(rc <= 0);\n                    if (fl <\
    \ es[j][3]) assert(rc >= 0);\n                }\n                assert(bal ==\
    \ b);\n            }\n        }\n    }\n    long long a_, b_;\n    fin >> a_ >>\
    \ b_;\n    fout << a_ + b_ << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../io/fastio.hpp\"\
    \n#include \"../../graph/minimum_spanning_tree.hpp\"\n#include \"../../graph/directed_mst.hpp\"\
    \n#include \"../../graph/hungarian.hpp\"\n#include \"../../graph/bipartite_matching.hpp\"\
    \n#include \"../../graph/general_matching.hpp\"\n#include \"../../graph/general_weighted_matching.hpp\"\
    \n#include \"../../graph/bipartite_edge_coloring.hpp\"\n#include \"../../graph/st_numbering.hpp\"\
    \n#include \"../../graph/min_cost_b_flow.hpp\"\n\n// \u6700\u5C0F\u5168\u57DF\u6728\
    \u30FB\u6700\u5C0F\u6709\u5411\u5168\u57DF\u6728\u30FB\u5272\u5F53\u554F\u984C\
    \u30FB\u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\u30B0\u30FB\u4E00\u822C\u30DE\u30C3\
    \u30C1\u30F3\u30B0\u30FB\u91CD\u307F\u4ED8\u304D\u4E00\u822C\u30DE\u30C3\u30C1\
    \u30F3\u30B0\u30FB\n// \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u8FBA\u5F69\u8272\u30FB\
    st \u756A\u53F7\u4ED8\u3051\u30FB\u6700\u5C0F\u8CBB\u7528 b-flow \u3092\u5C0F\u3055\
    \u3044\u5165\u529B\u306E\u5168\u63A2\u7D22\u3068\u7167\u5408\u3059\u308B\n\nint\
    \ main() {\n    mt19937_64 rng(41);\n    auto rnd = [&](long long lo, long long\
    \ hi) { return lo + (long long)(rng() % (hi - lo + 1)); };\n    for (int it =\
    \ 0; it < 1500; it++) {\n        int n = rnd(1, 6);\n        // \u6700\u5C0F\u5168\
    \u57DF\u6728 (\u9023\u7D50\u306A\u3089 n-1 \u672C\uFF0E\u8FBA\u306E\u90E8\u5206\
    \u96C6\u5408\u3092\u5168\u63A2\u7D22)\n        {\n            int m = rnd(0, 8);\n\
    \            vector<tuple<int, int, long long>> es(m);\n            for (auto\
    \ &[a, b, c] : es) a = rnd(0, n - 1), b = rnd(0, n - 1), c = rnd(0, 9);\n    \
    \        auto [w, used] = minimum_spanning_tree(n, es);\n            long long\
    \ best = LLONG_MAX;\n            int best_cnt = -1;\n            for (int mask\
    \ = 0; mask < (1 << m); mask++) {\n                vector<int> p(n);\n       \
    \         iota(p.begin(), p.end(), 0);\n                auto f = [&](auto self,\
    \ int x) -> int { return p[x] == x ? x : p[x] = self(self, p[x]); };\n       \
    \         bool ok = true;\n                long long s = 0;\n                int\
    \ cnt = 0;\n                for (int i = 0; i < m; i++)\n                    if\
    \ (mask >> i & 1) {\n                        auto [a, b, c] = es[i];\n       \
    \                 if (f(f, a) == f(f, b)) ok = false;\n                      \
    \  p[f(f, a)] = f(f, b), s += c, cnt++;\n                    }\n             \
    \   if (!ok) continue;\n                if (cnt > best_cnt || (cnt == best_cnt\
    \ && s < best)) best_cnt = cnt, best = s;\n            }\n            assert((int)used.size()\
    \ == best_cnt && w == best);\n        }\n        // \u6700\u5C0F\u6709\u5411\u5168\
    \u57DF\u6728 (\u5404\u9802\u70B9\u306E\u89AA\u3092\u5168\u63A2\u7D22)\n      \
    \  {\n            int m = rnd(0, 10), r = rnd(0, n - 1);\n            vector<tuple<int,\
    \ int, long long>> es;\n            set<pair<int, int>> seen;\n            for\
    \ (int i = 0; i < m; i++) {\n                int a = rnd(0, n - 1), b = rnd(0,\
    \ n - 1);\n                if (a == b || seen.count({a, b})) continue;\n     \
    \           seen.insert({a, b}), es.push_back({a, b, rnd(0, 9)});\n          \
    \  }\n            // in[v] = v \u306B\u5165\u308B\u8FBA\u306E\u5019\u88DC\n  \
    \          vector<vector<int>> in(n);\n            for (int i = 0; i < (int)es.size();\
    \ i++) in[get<1>(es[i])].push_back(i);\n            long long best = LLONG_MAX;\n\
    \            vector<int> choice(n, -1);\n            auto rec = [&](auto self,\
    \ int v) -> void {\n                if (v == n) {\n                    // \u5168\
    \u9802\u70B9\u304C r \u304B\u3089\u5230\u9054\u3067\u304D\u308B\u304B (\u89AA\u3092\
    \u305F\u3069\u3063\u3066 r \u306B\u7740\u304F\u304B)\n                    long\
    \ long s = 0;\n                    for (int u = 0; u < n; u++) {\n           \
    \             if (u == r) continue;\n                        s += get<2>(es[choice[u]]);\n\
    \                        int x = u, steps = 0;\n                        while\
    \ (x != r && steps <= n) x = get<0>(es[choice[x]]), steps++;\n               \
    \         if (x != r) return;\n                    }\n                    best\
    \ = std::min(best, s);\n                    return;\n                }\n     \
    \           if (v == r) return self(self, v + 1);\n                for (int e\
    \ : in[v]) choice[v] = e, self(self, v + 1);\n            };\n            rec(rec,\
    \ 0);\n            auto [w, par] = directed_mst(n, es, r);\n            if (best\
    \ == LLONG_MAX) assert(par.empty());\n            else {\n                assert(w\
    \ == best && par[r] == r);\n                long long s = 0;\n               \
    \ for (int v = 0; v < n; v++) {\n                    if (v == r) continue;\n \
    \                   long long c = -1;\n                    for (auto &[a, b, cc]\
    \ : es)\n                        if (a == par[v] && b == v) c = cc;\n        \
    \            assert(c >= 0);\n                    s += c;\n                }\n\
    \                assert(s == best);\n            }\n        }\n        // \u5272\
    \u5F53\u554F\u984C (n \xD7 m\uFF0Cn <= m)\n        {\n            int rows = rnd(1,\
    \ 5), cols = rnd(rows, 6);\n            vector<vector<long long>> a(rows, vector<long\
    \ long>(cols));\n            for (auto &row : a)\n                for (auto &x\
    \ : row) x = rnd(-20, 20);\n            auto [w, p] = hungarian(a);\n        \
    \    vector<int> perm(cols);\n            iota(perm.begin(), perm.end(), 0);\n\
    \            long long best = LLONG_MAX;\n            do {\n                long\
    \ long s = 0;\n                for (int i = 0; i < rows; i++) s += a[i][perm[i]];\n\
    \                best = std::min(best, s);\n            } while (next_permutation(perm.begin(),\
    \ perm.end()));\n            long long s = 0;\n            set<int> cs(p.begin(),\
    \ p.end());\n            for (int i = 0; i < rows; i++) s += a[i][p[i]];\n   \
    \         assert(w == best && s == best && (int)cs.size() == rows);\n        }\n\
    \        // \u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\u30B0\u30FB\u8FBA\u5F69\u8272\
    \n        {\n            int L = rnd(1, 5), R = rnd(1, 5), m = rnd(0, 10);\n \
    \           vector<pair<int, int>> es(m);\n            for (auto &[a, b] : es)\
    \ a = rnd(0, L - 1), b = rnd(0, R - 1);\n            BipartiteMatching bm(L, R);\n\
    \            for (auto [a, b] : es) bm.add_edge(a, b);\n            int got =\
    \ bm.solve();\n            int best = 0;\n            for (int mask = 0; mask\
    \ < (1 << m); mask++) {\n                vector<char> ul(L, 0), ur(R, 0);\n  \
    \              bool ok = true;\n                for (int i = 0; i < m && ok; i++)\n\
    \                    if (mask >> i & 1) {\n                        auto [a, b]\
    \ = es[i];\n                        if (ul[a] || ur[b]) ok = false;\n        \
    \                ul[a] = ur[b] = 1;\n                    }\n                if\
    \ (ok) best = std::max(best, __builtin_popcount(mask));\n            }\n     \
    \       assert(got == best);\n            auto mt = bm.matching();\n         \
    \   assert((int)mt.size() == best);\n            set<pair<int, int>> eset(es.begin(),\
    \ es.end());\n            for (auto e : mt) assert(eset.count(e));\n         \
    \   auto [K, col] = bipartite_edge_coloring(L, R, es);\n            int D = 0;\n\
    \            vector<int> dl(L, 0), dr(R, 0);\n            for (auto [a, b] : es)\
    \ D = std::max({D, ++dl[a], ++dr[b]});\n            assert(K == D);\n        \
    \    set<pair<int, int>> usedl, usedr;\n            for (int i = 0; i < m; i++)\
    \ {\n                assert(0 <= col[i] && col[i] < K);\n                assert(usedl.insert({es[i].first,\
    \ col[i]}).second);\n                assert(usedr.insert({es[i].second, col[i]}).second);\n\
    \            }\n        }\n        // \u4E00\u822C\u30DE\u30C3\u30C1\u30F3\u30B0\
    \u30FB\u91CD\u307F\u4ED8\u304D\u4E00\u822C\u30DE\u30C3\u30C1\u30F3\u30B0 (\u30D3\
    \u30C3\u30C8 DP)\n        {\n            int nn = rnd(1, 8), m = rnd(0, 14);\n\
    \            vector<vector<long long>> w(nn, vector<long long>(nn, 0));\n    \
    \        GeneralMatching gm(nn);\n            GeneralWeightedMatching<long long>\
    \ wm(nn);\n            for (int i = 0; i < m; i++) {\n                int a =\
    \ rnd(0, nn - 1), b = rnd(0, nn - 1);\n                if (a == b || w[a][b])\
    \ continue;\n                long long c = rnd(1, 10);\n                w[a][b]\
    \ = w[b][a] = c;\n                gm.add_edge(a, b), wm.add_edge(a, b, c);\n \
    \           }\n            vector<int> card(1 << nn, 0);\n            vector<long\
    \ long> wt(1 << nn, 0);\n            for (int mask = 1; mask < (1 << nn); mask++)\
    \ {\n                int v = __builtin_ctz(mask), rest = mask & ~(1 << v);\n \
    \               card[mask] = card[rest], wt[mask] = wt[rest];\n              \
    \  for (int u = 0; u < nn; u++)\n                    if ((rest >> u & 1) && w[v][u])\
    \ {\n                        card[mask] = std::max(card[mask], card[rest & ~(1\
    \ << u)] + 1);\n                        wt[mask] = std::max(wt[mask], wt[rest\
    \ & ~(1 << u)] + w[v][u]);\n                    }\n            }\n           \
    \ int full = (1 << nn) - 1;\n            assert(gm.solve() == card[full]);\n \
    \           for (auto [a, b] : gm.matching()) assert(w[a][b]);\n            auto\
    \ [tw, cnt] = wm.solve();\n            assert(tw == wt[full]);\n            long\
    \ long s = 0;\n            vector<char> usedv(nn, 0);\n            for (auto [a,\
    \ b] : wm.matching_edges()) {\n                assert(w[a][b] && !usedv[a] &&\
    \ !usedv[b]);\n                usedv[a] = usedv[b] = 1, s += w[a][b];\n      \
    \      }\n            assert(s == tw);\n        }\n        // st \u756A\u53F7\u4ED8\
    \u3051 (\u9806\u5217\u3092\u5168\u63A2\u7D22)\n        if (n >= 2) {\n       \
    \     int m = rnd(0, 8), s = rnd(0, n - 1), t = rnd(0, n - 2);\n            if\
    \ (t >= s) t++;\n            vector<pair<int, int>> es;\n            for (int\
    \ i = 0; i < m; i++) {\n                int a = rnd(0, n - 1), b = rnd(0, n -\
    \ 1);\n                if (a != b) es.push_back({a, b});\n            }\n    \
    \        auto valid = [&](const vector<int> &p) {\n                if (p[s] !=\
    \ 0 || p[t] != n - 1) return false;\n                for (int v = 0; v < n; v++)\
    \ {\n                    if (v == s || v == t) continue;\n                   \
    \ bool lo = false, hi = false;\n                    for (auto [a, b] : es) {\n\
    \                        int o = a == v ? b : (b == v ? a : -1);\n           \
    \             if (o < 0) continue;\n                        if (p[o] < p[v]) lo\
    \ = true;\n                        else hi = true;\n                    }\n  \
    \                  if (!lo || !hi) return false;\n                }\n        \
    \        // s \u304B\u3089 t \u306B\u8FBA\u304C\u3042\u308B\u304B (n = 2)\n  \
    \              if (n == 2) {\n                    bool e = false;\n          \
    \          for (auto [a, b] : es) e |= (a == s && b == t) || (a == t && b == s);\n\
    \                    return e;\n                }\n                return true;\n\
    \            };\n            vector<int> perm(n);\n            iota(perm.begin(),\
    \ perm.end(), 0);\n            bool exists = false;\n            do exists |=\
    \ valid(perm);\n            while (!exists && next_permutation(perm.begin(), perm.end()));\n\
    \            auto p = st_numbering(n, es, s, t);\n            assert(exists ==\
    \ !p.empty());\n            if (!p.empty()) assert(valid(p));\n        }\n   \
    \     // \u6700\u5C0F\u8CBB\u7528 b-flow (\u6D41\u91CF\u3092\u5168\u63A2\u7D22\
    \uFF0E\u5BB9\u91CF\u306F\u5C0F\u3055\u304F)\n        {\n            int nn = rnd(1,\
    \ 3), m = rnd(0, 4);\n            MinCostBFlow<long long, long long> mf(nn);\n\
    \            vector<long long> b(nn);\n            for (auto &x : b) x = rnd(-2,\
    \ 2);\n            long long sum = 0;\n            for (auto x : b) sum += x;\n\
    \            b[0] -= sum;  // \u548C\u3092 0 \u306B\n            for (int v =\
    \ 0; v < nn; v++) mf.add_supply(v, b[v]);\n            vector<array<long long,\
    \ 5>> es(m);\n            for (auto &e : es) {\n                e[0] = rnd(0,\
    \ nn - 1), e[1] = rnd(0, nn - 1), e[2] = rnd(0, 1), e[3] = e[2] + rnd(0, 2), e[4]\
    \ = rnd(-5, 5);\n                mf.add_edge(e[0], e[1], e[2], e[3], e[4]);\n\
    \            }\n            // \u5168\u63A2\u7D22\n            long long best\
    \ = LLONG_MAX;\n            vector<long long> f(m);\n            auto rec = [&](auto\
    \ self, int i) -> void {\n                if (i == m) {\n                    vector<long\
    \ long> bal(nn, 0);\n                    long long c = 0;\n                  \
    \  for (int j = 0; j < m; j++) bal[es[j][0]] += f[j], bal[es[j][1]] -= f[j], c\
    \ += es[j][4] * f[j];\n                    if (bal == b) best = std::min(best,\
    \ c);\n                    return;\n                }\n                for (f[i]\
    \ = es[i][2]; f[i] <= es[i][3]; f[i]++) self(self, i + 1);\n            };\n \
    \           rec(rec, 0);\n            bool ok = mf.solve();\n            assert(ok\
    \ == (best != LLONG_MAX));\n            if (ok) {\n                assert(mf.cost()\
    \ == (__int128)best);\n                vector<long long> bal(nn, 0);\n       \
    \         for (int j = 0; j < m; j++) {\n                    long long fl = mf.flow(j);\n\
    \                    assert(es[j][2] <= fl && fl <= es[j][3]);\n             \
    \       bal[es[j][0]] += fl, bal[es[j][1]] -= fl;\n                    long long\
    \ rc = es[j][4] + mf.potential(es[j][0]) - mf.potential(es[j][1]);\n         \
    \           if (fl > es[j][2]) assert(rc <= 0);\n                    if (fl <\
    \ es[j][3]) assert(rc >= 0);\n                }\n                assert(bal ==\
    \ b);\n            }\n        }\n    }\n    long long a_, b_;\n    fin >> a_ >>\
    \ b_;\n    fout << a_ + b_ << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - io/fastio.hpp
  - template.hpp
  - graph/minimum_spanning_tree.hpp
  - template.hpp
  - graph/directed_mst.hpp
  - graph/hungarian.hpp
  - graph/bipartite_matching.hpp
  - graph/general_matching.hpp
  - graph/csr.hpp
  - graph/general_weighted_matching.hpp
  - graph/bipartite_edge_coloring.hpp
  - graph/st_numbering.hpp
  - graph/min_cost_b_flow.hpp
  isVerificationFile: true
  path: test/unittest/graph_optimization.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unittest/graph_optimization.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/graph_optimization.test.cpp
- /verify/test/unittest/graph_optimization.test.cpp.html
title: test/unittest/graph_optimization.test.cpp
---
