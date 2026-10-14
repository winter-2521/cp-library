---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/static_range_lis.hpp
    title: "\u533A\u9593 LIS (Static Range LIS Query, Seaweed \u6CD5)"
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.hpp
    title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217 (Wavelet Matrix)"
  - icon: ':heavy_check_mark:'
    path: io/fastio.hpp
    title: "\u9AD8\u901F\u5165\u51FA\u529B (Fast I/O)"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/unittest/static_range_lis.test.cpp\"\n#define PROBLEM\
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
    \ 3 \"io/fastio.hpp\"\n\n// \u9AD8\u901F\u5165\u51FA\u529B\n// fin >> a >> b;\
    \  fout << a + b << '\\n';  \u306E\u3088\u3046\u306B cin / cout \u3068\u540C\u3058\
    \u611F\u899A\u3067\u4F7F\u3046\n// cin / cout / scanf / printf \u3068\u6DF7\u305C\
    \u3066\u4F7F\u3063\u3066\u306F\u3044\u3051\u306A\u3044\n// \u5165\u529B\u306F\u30D6\
    \u30ED\u30C3\u30AF\u5358\u4F4D\u3067\u8AAD\u3080\u306E\u3067\uFF0C\u30A4\u30F3\
    \u30BF\u30E9\u30AF\u30C6\u30A3\u30D6\u554F\u984C\u306B\u306F\u4F7F\u3048\u306A\
    \u3044\n\nnamespace fastio {\n\n// \u5165\u51FA\u529B\u30D0\u30C3\u30D5\u30A1\u306E\
    \u5927\u304D\u3055\nconstexpr size_t BUF_SIZE = 1 << 17;\n\n// 0000 ~ 9999 \u306E\
    \ 4 \u6841\u306E\u6587\u5B57\u5217\u3092\u524D\u8A08\u7B97\u3057\u3066\u304A\u304F\
    \u8868\nstruct DigitTable {\n    char d[10000][4];\n    constexpr DigitTable()\
    \ : d() {\n        for (int i = 0; i < 10000; i++) {\n            int x = i;\n\
    \            for (int j = 3; j >= 0; j--) d[i][j] = char('0' + x % 10), x /= 10;\n\
    \        }\n    }\n};\ninline constexpr DigitTable digit_table{};\n\n// __int128\
    \ \u306F -std=c++17 (gnu \u62E1\u5F35\u306A\u3057) \u3060\u3068 is_integral \u306B\
    \u306A\u3089\u306A\u3044\u306E\u3067\u81EA\u524D\u3067\u5224\u5B9A\u3059\u308B\
    \ntemplate <class T> struct is_int128 : false_type {};\ntemplate <> struct is_int128<__int128>\
    \ : true_type {};\ntemplate <> struct is_int128<unsigned __int128> : true_type\
    \ {};\n\n// \u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B\u306B\u5BFE\u5FDC\u3059\
    \u308B\u7B26\u53F7\u306A\u3057\u6574\u6570\u578B\ntemplate <class T> struct unsigned_of\
    \ { using type = make_unsigned_t<T>; };\ntemplate <> struct unsigned_of<__int128>\
    \ { using type = unsigned __int128; };\ntemplate <class T> using unsigned_of_t\
    \ = typename unsigned_of<T>::type;\n\ntemplate <class T> constexpr bool is_integer_v\
    \ = (is_integral_v<T> && !is_same_v<T, bool> && !is_same_v<T, char>) || is_int128<T>::value;\n\
    // ModInt \u306E\u3088\u3046\u306B val() \u3067\u6574\u6570\u5024\u3092\u8FD4\u3057\
    \uFF0C\u6574\u6570\u304B\u3089\u69CB\u7BC9\u3067\u304D\u308B\u578B\ntemplate <class\
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
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 2 \"template.hpp\"\
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
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 3 \"data_structure/wavelet_matrix.hpp\"\
    \n\n// \u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217 (\u9759\u7684\u306A\
    \u6570\u5217\u306B\u5BFE\u3059\u308B\u533A\u9593 k \u756A\u76EE\u30FB\u533A\u9593\
    \u306E\u5024\u306E\u500B\u6570\u306A\u3069)\n// \u5024\u306F\u5185\u90E8\u3067\
    \u5EA7\u6A19\u5727\u7E2E\u3059\u308B\uFF0E\u69CB\u7BC9 O(n log n)\uFF0C\u5404\u30AF\
    \u30A8\u30EA O(log \u03C3) (\u03C3 \u306F\u5024\u306E\u7A2E\u985E\u6570)\ntemplate\
    \ <class T>\nstruct WaveletMatrix {\n    // 64 bit \u3054\u3068\u306B\uFF0C\u30D3\
    \u30C3\u30C8\u5217\u3068\u305D\u308C\u3088\u308A\u524D\u306E 1 \u306E\u500B\u6570\
    \u3092\u307E\u3068\u3081\u3066\u6301\u3064\n    struct BitVector {\n        struct\
    \ Block {\n            uint64_t bits;\n            int cnt;\n        };\n    \
    \    vector<Block> b;\n        void init(int n) { b.assign((n >> 6) + 1, {0, 0});\
    \ }\n        void set(int i) { b[i >> 6].bits |= 1ULL << (i & 63); }\n       \
    \ void build() {\n            for (size_t i = 1; i < b.size(); i++) b[i].cnt =\
    \ b[i - 1].cnt + __builtin_popcountll(b[i - 1].bits);\n        }\n        // [0,\
    \ i) \u306E 1 \u306E\u500B\u6570\n        int rank1(int i) const {\n         \
    \   const Block &x = b[i >> 6];\n            return x.cnt + __builtin_popcountll(x.bits\
    \ & ((1ULL << (i & 63)) - 1));\n        }\n        bool get(int i) const { return\
    \ b[i >> 6].bits >> (i & 63) & 1; }\n    };\n\n    int n, lg;\n    vector<T> vals;\
    \  // \u5EA7\u6A19\u5727\u7E2E\u5F8C\u306E\u5024 (\u6607\u9806)\n    vector<BitVector>\
    \ bv;\n    vector<int> zeros;\n\n    WaveletMatrix(const vector<T> &a = {}) :\
    \ n(a.size()) {\n        vals = a;\n        sort(vals.begin(), vals.end());\n\
    \        vals.erase(unique(vals.begin(), vals.end()), vals.end());\n        vector<int>\
    \ cur(n);\n        for (int i = 0; i < n; i++) cur[i] = int(lower_bound(vals.begin(),\
    \ vals.end(), a[i]) - vals.begin());\n        lg = 1;\n        while ((1 << lg)\
    \ < (int)vals.size()) lg++;\n        bv.resize(lg);\n        zeros.resize(lg);\n\
    \        vector<int> nxt(n);\n        for (int h = lg - 1; h >= 0; h--) {\n  \
    \          bv[h].init(n);\n            int z = 0;\n            for (int i = 0;\
    \ i < n; i++) {\n                if (cur[i] >> h & 1) bv[h].set(i);\n        \
    \        else z++;\n            }\n            bv[h].build();\n            zeros[h]\
    \ = z;\n            // 0 \u306E\u3082\u306E\u3092\u524D\u306B\uFF0C1 \u306E\u3082\
    \u306E\u3092\u5F8C\u308D\u306B (\u5B89\u5B9A)\n            int p0 = 0, p1 = z;\n\
    \            for (int i = 0; i < n; i++) nxt[(cur[i] >> h & 1) ? p1++ : p0++]\
    \ = cur[i];\n            swap(cur, nxt);\n        }\n    }\n\n    int size() const\
    \ { return n; }\n\n    // a[i]\n    T access(int i) const {\n        int res =\
    \ 0;\n        for (int h = lg - 1; h >= 0; h--) {\n            int r1 = bv[h].rank1(i);\n\
    \            if (bv[h].get(i)) res |= 1 << h, i = zeros[h] + r1;\n           \
    \ else i -= r1;\n        }\n        return vals[res];\n    }\n    T operator[](int\
    \ i) const { return access(i); }\n\n    // a[l..r) \u306E\u4E2D\u3067\u5C0F\u3055\
    \u3044\u65B9\u304B\u3089 k \u756A\u76EE (0-indexed) \u306E\u5024\uFF0E0 <= k <\
    \ r - l \u3067\u3042\u308B\u3053\u3068\n    T kth_smallest(int l, int r, int k)\
    \ const {\n        int res = 0;\n        for (int h = lg - 1; h >= 0; h--) {\n\
    \            int l1 = bv[h].rank1(l), r1 = bv[h].rank1(r);\n            int z\
    \ = (r - r1) - (l - l1);\n            if (k < z) {\n                l -= l1, r\
    \ -= r1;\n            } else {\n                k -= z;\n                res |=\
    \ 1 << h;\n                l = zeros[h] + l1, r = zeros[h] + r1;\n           \
    \ }\n        }\n        return vals[res];\n    }\n    // a[l..r) \u306E\u4E2D\u3067\
    \u5927\u304D\u3044\u65B9\u304B\u3089 k \u756A\u76EE (0-indexed) \u306E\u5024\n\
    \    T kth_largest(int l, int r, int k) const { return kth_smallest(l, r, r -\
    \ l - 1 - k); }\n\n    // a[l..r) \u306E\u4E2D\u306E x \u672A\u6E80\u306E\u5024\
    \u306E\u500B\u6570\n    int count_lt(int l, int r, const T &x) const { return\
    \ count_lt_id(l, r, id_lower(x)); }\n    // a[l..r) \u306E\u4E2D\u306E x \u4EE5\
    \u4E0B\u306E\u5024\u306E\u500B\u6570\n    int count_le(int l, int r, const T &x)\
    \ const { return count_lt_id(l, r, id_upper(x)); }\n    // a[l..r) \u306E\u4E2D\
    \u306E lo \u4EE5\u4E0A hi \u672A\u6E80\u306E\u5024\u306E\u500B\u6570\n    int\
    \ count_range(int l, int r, const T &lo, const T &hi) const {\n        if (!(lo\
    \ < hi)) return 0;\n        return count_lt(l, r, hi) - count_lt(l, r, lo);\n\
    \    }\n    // a[l..r) \u306E\u4E2D\u306E x \u306E\u500B\u6570\n    int count(int\
    \ l, int r, const T &x) const { return count_le(l, r, x) - count_lt(l, r, x);\
    \ }\n\n    // a[l..r) \u306E\u4E2D\u306E x \u672A\u6E80\u306E\u6700\u5927\u306E\
    \u5024 (\u306A\u3051\u308C\u3070 def)\n    T max_lt(int l, int r, const T &x,\
    \ T def = T(-1)) const {\n        int c = count_lt(l, r, x);\n        return c\
    \ == 0 ? def : kth_smallest(l, r, c - 1);\n    }\n    // a[l..r) \u306E\u4E2D\u306E\
    \ x \u4EE5\u4E0B\u306E\u6700\u5927\u306E\u5024 (\u306A\u3051\u308C\u3070 def)\n\
    \    T max_le(int l, int r, const T &x, T def = T(-1)) const {\n        int c\
    \ = count_le(l, r, x);\n        return c == 0 ? def : kth_smallest(l, r, c - 1);\n\
    \    }\n    // a[l..r) \u306E\u4E2D\u306E x \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\
    \u5024 (\u306A\u3051\u308C\u3070 def)\n    T min_ge(int l, int r, const T &x,\
    \ T def = T(-1)) const {\n        int c = count_lt(l, r, x);\n        return c\
    \ == r - l ? def : kth_smallest(l, r, c);\n    }\n    // a[l..r) \u306E\u4E2D\u306E\
    \ x \u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u5024 (\u306A\u3051\u308C\
    \u3070 def)\n    T min_gt(int l, int r, const T &x, T def = T(-1)) const {\n \
    \       int c = count_le(l, r, x);\n        return c == r - l ? def : kth_smallest(l,\
    \ r, c);\n    }\n\n  private:\n    int id_lower(const T &x) const { return int(lower_bound(vals.begin(),\
    \ vals.end(), x) - vals.begin()); }\n    int id_upper(const T &x) const { return\
    \ int(upper_bound(vals.begin(), vals.end(), x) - vals.begin()); }\n    // a[l..r)\
    \ \u306E\u4E2D\u3067\u5727\u7E2E\u5F8C\u306E\u5024\u304C v \u672A\u6E80\u306E\u3082\
    \u306E\u306E\u500B\u6570\n    int count_lt_id(int l, int r, int v) const {\n \
    \       if (l >= r) return 0;\n        if (v >= (1 << lg)) return r - l;\n   \
    \     int res = 0;\n        for (int h = lg - 1; h >= 0; h--) {\n            int\
    \ l1 = bv[h].rank1(l), r1 = bv[h].rank1(r);\n            if (v >> h & 1) {\n \
    \               res += (r - r1) - (l - l1);\n                l = zeros[h] + l1,\
    \ r = zeros[h] + r1;\n            } else {\n                l -= l1, r -= r1;\n\
    \            }\n        }\n        return res;\n    }\n};\n#line 4 \"data_structure/static_range_lis.hpp\"\
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
    \ r, r);\n    }\n};\n#line 4 \"test/unittest/static_range_lis.test.cpp\"\n\n//\
    \ StaticRangeLIS \u3092\u611A\u76F4\u3068\u7167\u5408\u3059\u308B\n// sticky_product\u30FB\
    seaweed \u3082\u611A\u76F4 (\u5347\u3054\u3068\u306E\u3072\u3082\u306E\u4EA4\u63DB\
    ) \u3068\u7167\u5408\u3059\u308B\n\nint brute_lis(const vector<int> &a, int l,\
    \ int r) {\n    vector<int> d;\n    for (int i = l; i < r; i++) {\n        auto\
    \ it = lower_bound(d.begin(), d.end(), a[i]);\n        if (it == d.end()) d.push_back(a[i]);\n\
    \        else *it = a[i];\n    }\n    return d.size();\n}\n\n// \u96A3\u63A5\u4E92\
    \u63DB s_p \u3092\u300C\u307E\u3060\u4EA4\u5DEE\u3057\u3066\u3044\u306A\u3051\u308C\
    \u3070\u4EA4\u5DEE\u300D\u3067\u9806\u306B\u9069\u7528 (0-Hecke)\nvector<int>\
    \ apply_word(int n, const vector<int> &word) {\n    vector<int> at(n);  // at[\u4F4D\
    \u7F6E] = \u305D\u3053\u306B\u3044\u308B\u3072\u3082\u306E\u59CB\u70B9\n    iota(at.begin(),\
    \ at.end(), 0);\n    for (int p : word) if (at[p] < at[p + 1]) swap(at[p], at[p\
    \ + 1]);\n    vector<int> res(n);\n    for (int x = 0; x < n; x++) res[at[x]]\
    \ = x;\n    return res;\n}\n\nint main() {\n    mt19937_64 rng(11);\n    // sticky_product:\
    \ \u30E9\u30F3\u30C0\u30E0\u306A\u8A9E w1, w2 \u306B\u3064\u3044\u3066 product(w1,\
    \ w2) == w1 w2\n    for (int it = 0; it < 3000; it++) {\n        int n = rng()\
    \ % (it % 3 ? 9 : 60) + 1;\n        vector<int> w1, w2;\n        if (n > 1) {\n\
    \            for (int t = rng() % (n * 4); t--;) w1.push_back(rng() % (n - 1));\n\
    \            for (int t = rng() % (n * 4); t--;) w2.push_back(rng() % (n - 1));\n\
    \        }\n        vector<int> w12 = w1;\n        w12.insert(w12.end(), w2.begin(),\
    \ w2.end());\n        assert(seaweed_internal::sticky_product(apply_word(n, w1),\
    \ apply_word(n, w2)) == apply_word(n, w12));\n    }\n    // seaweed: \u5347\u3054\
    \u3068\u306B\u51E6\u7406\u3059\u308B\u611A\u76F4\n    for (int it = 0; it < 500;\
    \ it++) {\n        int m = rng() % 10 + 1;\n        vector<int> q(m);\n      \
    \  iota(q.begin(), q.end(), 0);\n        shuffle(q.begin(), q.end(), rng);\n \
    \       vector<int> word;\n        for (int i = 0; i < m; i++)\n            for\
    \ (int j = 0; j < m; j++) if (q[j] != i) word.push_back(m - 1 - i + j);\n    \
    \    assert(seaweed_internal::seaweed(q) == apply_word(2 * m, word));\n    }\n\
    \    // \u533A\u9593 LIS (\u91CD\u8907\u306E\u3042\u308B\u6570\u5217\u3082)\n\
    \    for (int it = 0; it < 300; it++) {\n        int n = rng() % 40 + 1;\n   \
    \     vector<int> a(n);\n        for (auto &x : a) x = rng() % (it % 2 ? 5 : 100);\n\
    \        StaticRangeLIS lis(a);\n        for (int l = 0; l <= n; l++)\n      \
    \      for (int r = l; r <= n; r++) assert(lis.query(l, r) == brute_lis(a, l,\
    \ r));\n    }\n    long long a_, b_;\n    fin >> a_ >> b_;\n    fout << a_ + b_\
    \ << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../io/fastio.hpp\"\
    \n#include \"../../data_structure/static_range_lis.hpp\"\n\n// StaticRangeLIS\
    \ \u3092\u611A\u76F4\u3068\u7167\u5408\u3059\u308B\n// sticky_product\u30FBseaweed\
    \ \u3082\u611A\u76F4 (\u5347\u3054\u3068\u306E\u3072\u3082\u306E\u4EA4\u63DB)\
    \ \u3068\u7167\u5408\u3059\u308B\n\nint brute_lis(const vector<int> &a, int l,\
    \ int r) {\n    vector<int> d;\n    for (int i = l; i < r; i++) {\n        auto\
    \ it = lower_bound(d.begin(), d.end(), a[i]);\n        if (it == d.end()) d.push_back(a[i]);\n\
    \        else *it = a[i];\n    }\n    return d.size();\n}\n\n// \u96A3\u63A5\u4E92\
    \u63DB s_p \u3092\u300C\u307E\u3060\u4EA4\u5DEE\u3057\u3066\u3044\u306A\u3051\u308C\
    \u3070\u4EA4\u5DEE\u300D\u3067\u9806\u306B\u9069\u7528 (0-Hecke)\nvector<int>\
    \ apply_word(int n, const vector<int> &word) {\n    vector<int> at(n);  // at[\u4F4D\
    \u7F6E] = \u305D\u3053\u306B\u3044\u308B\u3072\u3082\u306E\u59CB\u70B9\n    iota(at.begin(),\
    \ at.end(), 0);\n    for (int p : word) if (at[p] < at[p + 1]) swap(at[p], at[p\
    \ + 1]);\n    vector<int> res(n);\n    for (int x = 0; x < n; x++) res[at[x]]\
    \ = x;\n    return res;\n}\n\nint main() {\n    mt19937_64 rng(11);\n    // sticky_product:\
    \ \u30E9\u30F3\u30C0\u30E0\u306A\u8A9E w1, w2 \u306B\u3064\u3044\u3066 product(w1,\
    \ w2) == w1 w2\n    for (int it = 0; it < 3000; it++) {\n        int n = rng()\
    \ % (it % 3 ? 9 : 60) + 1;\n        vector<int> w1, w2;\n        if (n > 1) {\n\
    \            for (int t = rng() % (n * 4); t--;) w1.push_back(rng() % (n - 1));\n\
    \            for (int t = rng() % (n * 4); t--;) w2.push_back(rng() % (n - 1));\n\
    \        }\n        vector<int> w12 = w1;\n        w12.insert(w12.end(), w2.begin(),\
    \ w2.end());\n        assert(seaweed_internal::sticky_product(apply_word(n, w1),\
    \ apply_word(n, w2)) == apply_word(n, w12));\n    }\n    // seaweed: \u5347\u3054\
    \u3068\u306B\u51E6\u7406\u3059\u308B\u611A\u76F4\n    for (int it = 0; it < 500;\
    \ it++) {\n        int m = rng() % 10 + 1;\n        vector<int> q(m);\n      \
    \  iota(q.begin(), q.end(), 0);\n        shuffle(q.begin(), q.end(), rng);\n \
    \       vector<int> word;\n        for (int i = 0; i < m; i++)\n            for\
    \ (int j = 0; j < m; j++) if (q[j] != i) word.push_back(m - 1 - i + j);\n    \
    \    assert(seaweed_internal::seaweed(q) == apply_word(2 * m, word));\n    }\n\
    \    // \u533A\u9593 LIS (\u91CD\u8907\u306E\u3042\u308B\u6570\u5217\u3082)\n\
    \    for (int it = 0; it < 300; it++) {\n        int n = rng() % 40 + 1;\n   \
    \     vector<int> a(n);\n        for (auto &x : a) x = rng() % (it % 2 ? 5 : 100);\n\
    \        StaticRangeLIS lis(a);\n        for (int l = 0; l <= n; l++)\n      \
    \      for (int r = l; r <= n; r++) assert(lis.query(l, r) == brute_lis(a, l,\
    \ r));\n    }\n    long long a_, b_;\n    fin >> a_ >> b_;\n    fout << a_ + b_\
    \ << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - io/fastio.hpp
  - template.hpp
  - data_structure/static_range_lis.hpp
  - template.hpp
  - data_structure/wavelet_matrix.hpp
  isVerificationFile: true
  path: test/unittest/static_range_lis.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:42:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/static_range_lis.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/static_range_lis.test.cpp
- /verify/test/unittest/static_range_lis.test.cpp.html
title: test/unittest/static_range_lis.test.cpp
---
