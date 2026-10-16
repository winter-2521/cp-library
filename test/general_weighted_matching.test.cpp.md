---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/general_weighted_matching.hpp
    title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u91CD\u307F\u30DE\u30C3\
      \u30C1\u30F3\u30B0"
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
    PROBLEM: https://judge.yosupo.jp/problem/general_weighted_matching
    links:
    - https://judge.yosupo.jp/problem/general_weighted_matching
  bundledCode: "#line 1 \"test/general_weighted_matching.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/general_weighted_matching\"\n#line 1 \"template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
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
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 3 \"graph/general_weighted_matching.hpp\"\
    \n\n// https://github.com/winter-2521/cp-library\n\n// \u4E00\u822C\u30B0\u30E9\
    \u30D5\u306E\u6700\u5927\u91CD\u307F\u30DE\u30C3\u30C1\u30F3\u30B0 (Edmonds \u306E\
    \u4E3B\u53CC\u5BFE\u6CD5\u30FB\u82B1\u306E\u7E2E\u7D04)\uFF0EO(n^3)\n// \u9802\
    \u70B9\u30E9\u30D9\u30EB (\u53CC\u5BFE\u5909\u6570) lab \u3068\uFF0C\u82B1 (\u5947\
    \u9589\u8DEF\u3092\u7E2E\u7D04\u3057\u305F\u9802\u70B9) \u3054\u3068\u306E\u30E9\
    \u30D9\u30EB\u3092\u6301\u3061\uFF0C\n// \u300C\u30E9\u30D9\u30EB\u306E\u548C\
    \ = \u8FBA\u306E\u91CD\u307F \xD7 2\u300D\u3068\u306A\u308B\u8FBA (\u30BF\u30A4\
    \u30C8\u306A\u8FBA) \u3060\u3051\u3067\u4EA4\u4E92\u6728\u3092\u4F38\u3070\u3059\
    \uFF0E\u4F38\u3070\u305B\u306A\u304F\u306A\u3063\u305F\u3089\u53CC\u5BFE\u3092\
    \ d \u3060\u3051\u52D5\u304B\u3059\uFF0E\n// \u9802\u70B9\u306F\u5185\u90E8\u3067\
    \ 1-indexed\uFF0C\u82B1\u306F n+1 .. 2n\ntemplate <class W = long long>\nstruct\
    \ GeneralWeightedMatching {\n    struct Edge {\n        int u, v;\n        W w;\n\
    \    };\n    int n, nx;\n    vector<vector<Edge>> g;\n    vector<W> lab;\n   \
    \ vector<int> mate, slack, st, pa, S, vis;\n    vector<vector<int>> flo_from;\n\
    \    vector<vector<int>> flo;\n    vector<int> que;\n    size_t qh = 0;\n    int\
    \ vis_t = 0;\n\n    GeneralWeightedMatching(int n_)\n        : n(n_), nx(n_),\
    \ g(2 * n_ + 1, vector<Edge>(2 * n_ + 1)), lab(2 * n_ + 1), mate(2 * n_ + 1),\
    \ slack(2 * n_ + 1), st(2 * n_ + 1),\n          pa(2 * n_ + 1), S(2 * n_ + 1),\
    \ vis(2 * n_ + 1), flo_from(2 * n_ + 1, vector<int>(n_ + 1)), flo(2 * n_ + 1)\
    \ {\n        for (int u = 1; u <= n; u++)\n            for (int v = 1; v <= n;\
    \ v++) g[u][v] = {u, v, 0};\n    }\n\n    // \u8FBA (u, v) \u91CD\u307F w (0-indexed\uFF0C\
    w > 0\uFF0E\u540C\u3058\u7D44\u306F\u91CD\u3044\u65B9)\n    void add_edge(int\
    \ u, int v, W w) {\n        u++, v++;\n        if (w > g[u][v].w) g[u][v].w =\
    \ g[v][u].w = w;\n    }\n\n    // {\u91CD\u307F\u306E\u548C, \u30DE\u30C3\u30C1\
    \u30F3\u30B0\u306E\u8FBA\u306E\u6570}\n    pair<W, int> solve() {\n        fill(mate.begin(),\
    \ mate.end(), 0);\n        nx = n;\n        for (int u = 0; u <= n; u++) st[u]\
    \ = u, flo[u].clear();\n        W wmax = 0;\n        for (int u = 1; u <= n; u++)\n\
    \            for (int v = 1; v <= n; v++) {\n                flo_from[u][v] =\
    \ (u == v ? u : 0);\n                wmax = std::max(wmax, g[u][v].w);\n     \
    \       }\n        for (int u = 1; u <= n; u++) lab[u] = wmax;\n        int cnt\
    \ = 0;\n        while (matching()) cnt++;\n        W tot = 0;\n        for (int\
    \ u = 1; u <= n; u++)\n            if (mate[u] && mate[u] < u) tot += g[u][mate[u]].w;\n\
    \        return {tot, cnt};\n    }\n\n    // \u30DE\u30C3\u30C1\u30F3\u30B0\u306E\
    \u8FBA (0-indexed, u < v)\n    vector<pair<int, int>> matching_edges() const {\n\
    \        vector<pair<int, int>> res;\n        for (int u = 1; u <= n; u++)\n \
    \           if (mate[u] && u < mate[u]) res.push_back({u - 1, mate[u] - 1});\n\
    \        return res;\n    }\n\n  private:\n    W e_delta(const Edge &e) const\
    \ { return lab[e.u] + lab[e.v] - g[e.u][e.v].w * 2; }\n    void update_slack(int\
    \ u, int x) {\n        if (!slack[x] || e_delta(g[u][x]) < e_delta(g[slack[x]][x]))\
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
    \        return false;\n    }\n};\n#line 4 \"test/general_weighted_matching.test.cpp\"\
    \n\nint main() {\n    int n, m;\n    fin >> n >> m;\n    GeneralWeightedMatching<long\
    \ long> wm(n);\n    for (int i = 0; i < m; i++) {\n        int u, v;\n       \
    \ long long w;\n        fin >> u >> v >> w;\n        wm.add_edge(u, v, w);\n \
    \   }\n    auto [w, k] = wm.solve();\n    auto es = wm.matching_edges();\n   \
    \ fout << es.size() << ' ' << w << '\\n';\n    for (auto [u, v] : es) fout <<\
    \ u << ' ' << v << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/general_weighted_matching\"\
    \n#include \"../io/fastio.hpp\"\n#include \"../graph/general_weighted_matching.hpp\"\
    \n\nint main() {\n    int n, m;\n    fin >> n >> m;\n    GeneralWeightedMatching<long\
    \ long> wm(n);\n    for (int i = 0; i < m; i++) {\n        int u, v;\n       \
    \ long long w;\n        fin >> u >> v >> w;\n        wm.add_edge(u, v, w);\n \
    \   }\n    auto [w, k] = wm.solve();\n    auto es = wm.matching_edges();\n   \
    \ fout << es.size() << ' ' << w << '\\n';\n    for (auto [u, v] : es) fout <<\
    \ u << ' ' << v << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - io/fastio.hpp
  - template.hpp
  - graph/general_weighted_matching.hpp
  - template.hpp
  isVerificationFile: true
  path: test/general_weighted_matching.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/general_weighted_matching.test.cpp
layout: document
redirect_from:
- /verify/test/general_weighted_matching.test.cpp
- /verify/test/general_weighted_matching.test.cpp.html
title: test/general_weighted_matching.test.cpp
---
