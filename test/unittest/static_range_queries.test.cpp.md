---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/dynamic_range_frequency.hpp
    title: "\u4E00\u70B9\u66F4\u65B0\u3042\u308A\u306E\u533A\u9593\u306E\u5024\u306E\
      \u500B\u6570 (Point Set Range Frequency)"
  - icon: ':heavy_check_mark:'
    path: data_structure/ordered_set.hpp
    title: "\u9806\u5E8F\u4ED8\u304D\u96C6\u5408 (Ordered Set)"
  - icon: ':heavy_check_mark:'
    path: data_structure/static_range_count_distinct.hpp
    title: "\u9759\u7684\u306A\u533A\u9593\u306E\u7A2E\u985E\u6570 (Static Range Count\
      \ Distinct)"
  - icon: ':heavy_check_mark:'
    path: data_structure/static_range_frequency.hpp
    title: "\u9759\u7684\u306A\u533A\u9593\u306E\u5024\u306E\u500B\u6570 (Static Range\
      \ Frequency)"
  - icon: ':heavy_check_mark:'
    path: data_structure/static_range_inversions.hpp
    title: "\u9759\u7684\u306A\u533A\u9593\u8EE2\u5012\u6570 (Static Range Inversions\
      \ Query)"
  - icon: ':heavy_check_mark:'
    path: data_structure/static_range_mode.hpp
    title: "\u9759\u7684\u306A\u533A\u9593\u6700\u983B\u5024 (Static Range Mode Query)"
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
  bundledCode: "#line 1 \"test/unittest/static_range_queries.test.cpp\"\n#define PROBLEM\
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
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 3 \"data_structure/static_range_frequency.hpp\"\
    \n\n// \u9759\u7684\u306A\u6570\u5217\u306E\u533A\u9593\u306B x \u304C\u4F55\u500B\
    \u3042\u308B\u304B (Static Range Frequency)\n// \u5024\u3054\u3068\u306B\u51FA\
    \u73FE\u4F4D\u7F6E\u3092\u6607\u9806\u306B\u4E26\u3079\u3066\u304A\u304D\uFF0C\
    x \u306E\u4F4D\u7F6E\u306E\u5217\u3067 [l, r) \u306B\u5165\u308B\u3082\u306E\u3092\
    \u4E8C\u5206\u63A2\u7D22\u3067\u6570\u3048\u308B\uFF0E\u69CB\u7BC9 O(n log n)\uFF0C\
    \u30AF\u30A8\u30EA O(log n)\ntemplate <class T>\nstruct StaticRangeFrequency {\n\
    \    int n;\n    vector<T> vals;     // \u5024\u306E\u7A2E\u985E (\u6607\u9806\
    )\n    vector<int> start;  // \u5024 vals[k] \u306E\u51FA\u73FE\u4F4D\u7F6E\u306F\
    \ pos[start[k] .. start[k+1])\n    vector<int> pos;\n\n    StaticRangeFrequency(const\
    \ vector<T> &a) : n(a.size()) {\n        vector<int> ord(n);\n        iota(ord.begin(),\
    \ ord.end(), 0);\n        stable_sort(ord.begin(), ord.end(), [&](int i, int j)\
    \ { return a[i] < a[j]; });\n        pos = ord;\n        for (int k = 0; k < n;\
    \ k++) {\n            if (k == 0 || vals.back() < a[ord[k]]) vals.push_back(a[ord[k]]),\
    \ start.push_back(k);\n        }\n        start.push_back(n);\n    }\n\n    //\
    \ a[l..r) \u306E\u4E2D\u306E x \u306E\u500B\u6570\n    int count(int l, int r,\
    \ const T &x) const {\n        int k = lower_bound(vals.begin(), vals.end(), x)\
    \ - vals.begin();\n        if (k == (int)vals.size() || x < vals[k]) return 0;\n\
    \        auto b = pos.begin() + start[k], e = pos.begin() + start[k + 1];\n  \
    \      return lower_bound(b, e, r) - lower_bound(b, e, l);\n    }\n};\n#line 2\
    \ \"template.hpp\"\nusing namespace std;\n#if __has_include(<atcoder/all>)\n#include\
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
    \   }\n        return res;\n    }\n};\n#line 4 \"data_structure/static_range_count_distinct.hpp\"\
    \n\n// \u9759\u7684\u306A\u6570\u5217\u306E\u533A\u9593\u306B\u542B\u307E\u308C\
    \u308B\u5024\u306E\u7A2E\u985E\u6570 (Static Range Count Distinct)\uFF0E\u30AA\
    \u30F3\u30E9\u30A4\u30F3\n// prev[i] = i \u3088\u308A\u524D\u3067 a[i] \u3068\u540C\
    \u3058\u5024\u304C\u6700\u5F8C\u306B\u51FA\u3066\u304F\u308B\u4F4D\u7F6E (\u306A\
    \u3051\u308C\u3070 -1) \u3068\u3059\u308B\u3068\uFF0C\n// [l, r) \u306E\u7A2E\u985E\
    \u6570 = #{i \u2208 [l, r) : prev[i] < l}\uFF0E\u3053\u308C\u3092\u30A6\u30A7\u30FC\
    \u30D6\u30EC\u30C3\u30C8\u884C\u5217\u3067\u6570\u3048\u308B\n// \u69CB\u7BC9\
    \ O(n log n)\uFF0C\u30AF\u30A8\u30EA O(log n)\ntemplate <class T>\nstruct StaticRangeCountDistinct\
    \ {\n    int n;\n    WaveletMatrix<int> wm;\n\n    StaticRangeCountDistinct(const\
    \ vector<T> &a) : n(a.size()) {\n        vector<int> ord(n), prev(n, -1);\n  \
    \      iota(ord.begin(), ord.end(), 0);\n        stable_sort(ord.begin(), ord.end(),\
    \ [&](int i, int j) { return a[i] < a[j]; });\n        for (int k = 1; k < n;\
    \ k++)\n            if (!(a[ord[k - 1]] < a[ord[k]])) prev[ord[k]] = ord[k - 1];\n\
    \        wm = WaveletMatrix<int>(prev);\n    }\n\n    // a[l..r) \u306E\u5024\u306E\
    \u7A2E\u985E\u6570\n    int count(int l, int r) const { return l < r ? wm.count_lt(l,\
    \ r, l) : 0; }\n};\n#line 2 \"template.hpp\"\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
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
    \ 3 \"data_structure/static_range_mode.hpp\"\n\n// \u9759\u7684\u306A\u6570\u5217\
    \u306E\u533A\u9593\u6700\u983B\u5024 (Static Range Mode Query)\uFF0E\u30AA\u30F3\
    \u30E9\u30A4\u30F3\uFF0C\u5E73\u65B9\u5206\u5272\n// \u30D6\u30ED\u30C3\u30AF\u306E\
    \u533A\u9593 [bi, bj] \u3054\u3068\u306B\u6700\u983B\u5024\u3068\u500B\u6570\u3092\
    \u524D\u8A08\u7B97\u3057\u3066\u304A\u304D\uFF0C\u7AEF\u306E\u8981\u7D20\u306F\
    \n// \u300C\u5024\u3054\u3068\u306E\u51FA\u73FE\u4F4D\u7F6E\u306E\u5217\u300D\u3067\
    \u500B\u6570\u3092 1 \u305A\u3064\u4F38\u3070\u305B\u308B\u304B\u78BA\u304B\u3081\
    \u308B\uFF0E\u69CB\u7BC9 O(n \u221An)\uFF0C\u30AF\u30A8\u30EA O(\u221An)\ntemplate\
    \ <class T>\nstruct StaticRangeMode {\n    int n, B, nb;\n    vector<T> vals;\
    \              // \u5EA7\u6A19\u5727\u7E2E\u5F8C\u306E\u5024 \u2192 \u5143\u306E\
    \u5024\n    vector<int> c;               // \u5727\u7E2E\u5F8C\u306E\u5024\n \
    \   vector<int> rank_in;         // i \u304C pos[c[i]] \u306E\u4F55\u756A\u76EE\
    \u304B\n    vector<vector<int>> pos;     // \u5024\u3054\u3068\u306E\u51FA\u73FE\
    \u4F4D\u7F6E\n    vector<int> mode_val, mode_cnt;  // \u30D6\u30ED\u30C3\u30AF\
    \u533A\u9593 [bi, bj] \u306E\u6700\u983B\u5024\u30FB\u500B\u6570 (bi * nb + bj)\n\
    \n    StaticRangeMode(const vector<T> &a) : n(a.size()) {\n        vals = a;\n\
    \        sort(vals.begin(), vals.end());\n        vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\n        int m = vals.size();\n        c.resize(n),\
    \ rank_in.resize(n), pos.assign(m, {});\n        for (int i = 0; i < n; i++) {\n\
    \            c[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();\n\
    \            rank_in[i] = pos[c[i]].size();\n            pos[c[i]].push_back(i);\n\
    \        }\n        B = std::max(1, (int)sqrt(n));\n        nb = (n + B - 1) /\
    \ B;\n        mode_val.assign(nb * nb, -1), mode_cnt.assign(nb * nb, 0);\n   \
    \     vector<int> cnt(m, 0);\n        for (int bi = 0; bi < nb; bi++) {\n    \
    \        int best = -1, bc = 0;\n            for (int bj = bi; bj < nb; bj++)\
    \ {\n                for (int i = bj * B; i < std::min(n, (bj + 1) * B); i++)\
    \ {\n                    if (++cnt[c[i]] > bc) bc = cnt[c[i]], best = c[i];\n\
    \                }\n                mode_val[bi * nb + bj] = best, mode_cnt[bi\
    \ * nb + bj] = bc;\n            }\n            for (int i = bi * B; i < n; i++)\
    \ cnt[c[i]]--;\n        }\n    }\n\n    // a[l..r) \u306E\u6700\u983B\u5024\u3068\
    \u305D\u306E\u500B\u6570 (l < r)\uFF0E\u6700\u983B\u5024\u304C\u8907\u6570\u3042\
    \u308C\u3070\u3069\u308C\u304B 1 \u3064\n    pair<T, int> query(int l, int r)\
    \ const {\n        int lb = l / B, rb = (r - 1) / B;\n        int best = -1, bc\
    \ = 0;\n        auto extend_right = [&](int i) {  // i \u304B\u3089\u53F3\u306B\
    \u6570\u3048\u3066 bc + 1 \u500B\u76EE\u304C r \u672A\u6E80\u306B\u3042\u308B\u304B\
    \n            int v = c[i], k = rank_in[i];\n            const auto &p = pos[v];\n\
    \            while (k + bc < (int)p.size() && p[k + bc] < r) bc++, best = v;\n\
    \        };\n        if (rb - lb <= 1) {\n            for (int i = l; i < r; i++)\
    \ extend_right(i);\n            return {vals[best], bc};\n        }\n        best\
    \ = mode_val[(lb + 1) * nb + rb - 1], bc = mode_cnt[(lb + 1) * nb + rb - 1];\n\
    \        for (int i = l; i < (lb + 1) * B; i++) extend_right(i);\n        for\
    \ (int i = rb * B; i < r; i++) {  // \u5DE6\u306B\u6570\u3048\u3066 bc + 1 \u500B\
    \u76EE\u304C l \u4EE5\u4E0A\u306B\u3042\u308B\u304B\n            int v = c[i],\
    \ k = rank_in[i];\n            const auto &p = pos[v];\n            while (k -\
    \ bc >= 0 && p[k - bc] >= l) bc++, best = v;\n        }\n        return {vals[best],\
    \ bc};\n    }\n};\n#line 2 \"template.hpp\"\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
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
    \ 3 \"data_structure/static_range_inversions.hpp\"\n\n// \u9759\u7684\u306A\u6570\
    \u5217\u306E\u533A\u9593\u8EE2\u5012\u6570 (Static Range Inversions Query)\uFF0E\
    \u30AA\u30F3\u30E9\u30A4\u30F3\uFF0C\u5E73\u65B9\u5206\u5272\n// \u30D6\u30ED\u30C3\
    \u30AF\u306E\u5927\u304D\u3055\u3092 B\uFF0C\u500B\u6570\u3092 nb \u3068\u3059\
    \u308B\uFF0E\u524D\u8A08\u7B97:\n//   lt[R][i] = #{j : block(i) < block(j) < R,\
    \ a[j] < a[i]}   (i \u3088\u308A\u53F3\uFF0C\u30D6\u30ED\u30C3\u30AF R \u306E\u624B\
    \u524D\u307E\u3067\u3067 a[i] \u3088\u308A\u5C0F\u3055\u3044\u3082\u306E)\n//\
    \   gt[L][j] = #{i : L <= block(i) < block(j), a[i] > a[j]}  (\u30D6\u30ED\u30C3\
    \u30AF L \u304B\u3089 j \u306E\u624B\u524D\u306E\u30D6\u30ED\u30C3\u30AF\u307E\
    \u3067\u3067 a[j] \u3088\u308A\u5927\u304D\u3044\u3082\u306E)\n//   big[L][R]\
    \ = \u30D6\u30ED\u30C3\u30AF L..R-1 \u306E\u4E2D\u306E\u8EE2\u5012\u6570\n// \
    \  pre[i], suf[i] = i \u306E\u30D6\u30ED\u30C3\u30AF\u5185\u3067 [\u30D6\u30ED\
    \u30C3\u30AF\u5148\u982D, i] / [i, \u30D6\u30ED\u30C3\u30AF\u672B\u5C3E) \u306E\
    \u8EE2\u5012\u6570\n//   \u5404\u30D6\u30ED\u30C3\u30AF\u306E (\u5024, \u4F4D\u7F6E\
    ) \u306E\u6607\u9806\u30EA\u30B9\u30C8\n// \u30AF\u30A8\u30EA\u306F\u300C\u5DE6\
    \u306E\u7AEF\u30FB\u53F3\u306E\u7AEF\u30FB\u9593\u306E\u5B8C\u5168\u306A\u30D6\
    \u30ED\u30C3\u30AF\u300D\u306B\u5206\u3051\u3066\u6570\u3048\u308B\uFF0Elt / gt\
    \ \u306F\u4F4D\u7F6E\u306E\u9806\u306B\u4E26\u3079\u3066\u3042\u308B\u306E\u3067\
    \uFF0C\u7AEF\u306E\u8981\u7D20\u3092\u9806\u306B\u898B\u308B\u3068\u304D\u9023\
    \u7D9A\u30A2\u30AF\u30BB\u30B9\u306B\u306A\u308B\n// \u69CB\u7BC9 O(n \u221An)\uFF0C\
    \u30AF\u30A8\u30EA O(\u221An)\uFF0C\u30E1\u30E2\u30EA O(n \u221An)\ntemplate <class\
    \ T>\nstruct StaticRangeInversions {\n    int n, B, nb;\n    vector<int> c;  \
    \                  // \u5727\u7E2E\u5F8C\u306E\u5024\n    vector<int> lt, gt;\
    \               // lt[R * n + i], gt[L * n + j]\n    vector<long long> big;  \
    \          // big[L * (nb + 1) + R]\n    vector<long long> pre, suf;\n    vector<pair<int,\
    \ int>> sorted_;   // \u30D6\u30ED\u30C3\u30AF\u3054\u3068\u306B (\u5024, \u4F4D\
    \u7F6E) \u3092\u6607\u9806\u306B\u4E26\u3079\u305F\u3082\u306E\n\n    StaticRangeInversions(const\
    \ vector<T> &a, int block = -1) : n(a.size()) {\n        vector<T> vals = a;\n\
    \        sort(vals.begin(), vals.end());\n        vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\n        c.resize(n);\n        for (int i = 0; i <\
    \ n; i++) c[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();\n\
    \        B = block > 0 ? block : std::max(16, (int)(1.25 * sqrt(n)));\n      \
    \  nb = std::max(1, (n + B - 1) / B);\n        sorted_.resize(n);\n        for\
    \ (int i = 0; i < n; i++) sorted_[i] = {c[i], i};\n        for (int b = 0; b <\
    \ nb; b++) sort(sorted_.begin() + std::min(n, b * B), sorted_.begin() + std::min(n,\
    \ (b + 1) * B));\n        vector<pair<int, int>> all = sorted_;  // \u5168\u4F53\
    \u3092 (\u5024, \u4F4D\u7F6E) \u306E\u6607\u9806\u306B\n        sort(all.begin(),\
    \ all.end());\n        // lt[R][i] = lt[R-1][i] + #{j \u2208 \u30D6\u30ED\u30C3\
    \u30AF R-1 : c[j] < c[i]} (block(i) < R-1 \u306E\u3068\u304D)\n        lt.assign((size_t)(nb\
    \ + 1) * n, 0);\n        for (int R = 2; R <= nb; R++) {\n            int *cur\
    \ = &lt[(size_t)R * n], *prv = &lt[(size_t)(R - 1) * n];\n            int bs =\
    \ (R - 1) * B, be = std::min(n, R * B), p = bs;\n            for (auto [v, i]\
    \ : all) {\n                while (p < be && sorted_[p].first < v) p++;\n    \
    \            if (i < bs) cur[i] = prv[i] + (p - bs);\n            }\n        }\n\
    \        // gt[L][j] = gt[L+1][j] + #{i \u2208 \u30D6\u30ED\u30C3\u30AF L : c[i]\
    \ > c[j]} (block(j) > L \u306E\u3068\u304D)\n        gt.assign((size_t)(nb + 1)\
    \ * n, 0);\n        for (int L = nb - 2; L >= 0; L--) {\n            int *cur\
    \ = &gt[(size_t)L * n], *nxt = &gt[(size_t)(L + 1) * n];\n            int bs =\
    \ L * B, be = std::min(n, (L + 1) * B), p = bs;\n            for (auto [v, j]\
    \ : all) {\n                while (p < be && sorted_[p].first <= v) p++;\n   \
    \             if (j >= be) cur[j] = nxt[j] + (be - p);\n            }\n      \
    \  }\n        // \u30D6\u30ED\u30C3\u30AF\u5185\u306E\u8EE2\u5012\u6570\n    \
    \    pre.assign(n, 0), suf.assign(n, 0);\n        for (int b = 0; b < nb; b++)\
    \ {\n            int s = b * B, e = std::min(n, (b + 1) * B);\n            for\
    \ (int i = s; i < e; i++) {\n                long long x = i > s ? pre[i - 1]\
    \ : 0;\n                for (int j = s; j < i; j++) x += c[j] > c[i];\n      \
    \          pre[i] = x;\n            }\n            for (int i = e - 1; i >= s;\
    \ i--) {\n                long long x = i + 1 < e ? suf[i + 1] : 0;\n        \
    \        for (int j = i + 1; j < e; j++) x += c[i] > c[j];\n                suf[i]\
    \ = x;\n            }\n        }\n        // big[L][R] = big[L][R-1] + big[L+1][R]\
    \ - big[L+1][R-1] + (\u30D6\u30ED\u30C3\u30AF L \u306E\u8981\u7D20 > \u30D6\u30ED\
    \u30C3\u30AF R-1 \u306E\u8981\u7D20 \u306E\u7D44)\n        big.assign((size_t)(nb\
    \ + 1) * (nb + 1), 0);\n        auto BIG = [&](int L, int R) -> long long & {\
    \ return big[(size_t)L * (nb + 1) + R]; };\n        for (int L = nb - 1; L >=\
    \ 0; L--) {\n            if (L * B < n) BIG(L, L + 1) = suf[L * B];\n        \
    \    for (int R = L + 2; R <= nb; R++) {\n                long long cross = 0;\n\
    \                const int *hi = &lt[(size_t)R * n], *lo = &lt[(size_t)(R - 1)\
    \ * n];\n                for (int i = L * B; i < (L + 1) * B; i++) cross += hi[i]\
    \ - lo[i];\n                BIG(L, R) = BIG(L, R - 1) + BIG(L + 1, R) - BIG(L\
    \ + 1, R - 1) + cross;\n            }\n        }\n    }\n\n    // a[l..r) \u306E\
    \u8EE2\u5012\u6570\n    long long query(int l, int r) const {\n        if (r -\
    \ l <= 1) return 0;\n        int lb = l / B, rb = (r - 1) / B;\n        if (lb\
    \ == rb) {\n            int s = lb * B, e = std::min(n, s + B);\n            long\
    \ long res = pre[r - 1] - (l > s ? pre[l - 1] : 0);\n            // [s, l) \u306E\
    \u8981\u7D20 > [l, r) \u306E\u8981\u7D20 \u306E\u7D44\u3092\u5F15\u304F (\u5024\
    \u306E\u6607\u9806\u306B\u898B\u308B\uFF0E\u540C\u3058\u5024\u306F\u4F4D\u7F6E\
    \u306E\u6607\u9806\u306A\u306E\u3067\u6570\u3048\u306A\u3044)\n            int\
    \ seen = 0;\n            for (int k = s; k < e; k++) {\n                int i\
    \ = sorted_[k].second;\n                if (i < l) res -= seen;\n            \
    \    else if (i < r) seen++;\n            }\n            return res;\n       \
    \ }\n        long long res = suf[l] + pre[r - 1] + big[(size_t)(lb + 1) * (nb\
    \ + 1) + rb];\n        const int *ltr = &lt[(size_t)rb * n], *gtl = &gt[(size_t)(lb\
    \ + 1) * n];\n        for (int i = l; i < (lb + 1) * B; i++) res += ltr[i];\n\
    \        for (int j = rb * B; j < r; j++) res += gtl[j];\n        // \u5DE6\u306E\
    \u7AEF\u306E\u8981\u7D20 > \u53F3\u306E\u7AEF\u306E\u8981\u7D20 \u306E\u7D44 (\u3069\
    \u3061\u3089\u3082\u5024\u306E\u6607\u9806\u306B\u898B\u308B)\n        int ls\
    \ = lb * B, le = (lb + 1) * B, rs = rb * B, re = std::min(n, rs + B);\n      \
    \  int p = rs, smaller = 0;\n        for (int k = ls; k < le; k++) {\n       \
    \     if (sorted_[k].second < l) continue;\n            int v = sorted_[k].first;\n\
    \            while (p < re && sorted_[p].first < v) {\n                if (sorted_[p].second\
    \ < r) smaller++;\n                p++;\n            }\n            res += smaller;\n\
    \        }\n        return res;\n    }\n};\n#line 2 \"template.hpp\"\nusing namespace\
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
    \ 3 \"data_structure/ordered_set.hpp\"\n\n// \u9806\u5E8F\u4ED8\u304D\u96C6\u5408\
    \ (\u30AA\u30F3\u30E9\u30A4\u30F3\u30FB\u5024\u306E\u5148\u8AAD\u307F\u4E0D\u8981\
    )\n// \u5404\u30CE\u30FC\u30C9\u304C\u6700\u5927 B \u500B\u306E\u5024\u3092\u30BD\
    \u30FC\u30C8\u6E08\u307F\u914D\u5217\u3067\u6301\u3064 AVL \u6728\uFF0E\n// 1\
    \ \u30CE\u30FC\u30C9\u3092 128 \u30D0\u30A4\u30C8\u7A0B\u5EA6\u306B\u3057\u3066\
    \u30AD\u30E3\u30C3\u30B7\u30E5\u52B9\u7387\u3092\u4E0A\u3052\uFF0C\u30CE\u30FC\
    \u30C9\u5185\u306F\u7DDA\u5F62\u63A2\u7D22\u3059\u308B\uFF0E\u5404\u64CD\u4F5C\
    \ O(log n)\n//\n// \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306E\u623B\u308A\
    \u5024\u306F def (\u7701\u7565\u6642 -1)\ntemplate <class T, int B = std::max(4,\
    \ int(112 / sizeof(T)))>\nstruct OrderedSet {\n    struct Node {\n        T data[B];\n\
    \        int left, right, total;  // total: \u90E8\u5206\u6728\u306E\u8981\u7D20\
    \u6570\n        short height, size;\n    };\n\n    vector<Node> t;\n    vector<int>\
    \ free_list;\n    int root = 0;\n\n    OrderedSet() { t.push_back(Node{}); } \
    \ // t[0] \u306F\u756A\u5175 (height = total = 0)\n\n    // \u521D\u671F\u8981\
    \u7D20 a (\u9806\u4E0D\u540C\u30FB\u91CD\u8907\u53EF) \u3067 O(n log n) \u69CB\
    \u7BC9 (\u30BD\u30FC\u30C8\u6E08\u307F\u306A\u3089 O(n))\n    OrderedSet(vector<T>\
    \ a) : OrderedSet() {\n        if (!is_sorted(a.begin(), a.end())) sort(a.begin(),\
    \ a.end());\n        a.erase(unique(a.begin(), a.end()), a.end());\n        int\
    \ n = a.size();\n        if (n == 0) return;\n        // \u5F8C\u304B\u3089\u633F\
    \u5165\u3067\u304D\u308B\u3088\u3046\u5C11\u3057\u4F59\u88D5\u3092\u6B8B\u3057\
    \u3066\u8A70\u3081\u308B\n        int bs = std::max(1, B * 6 / 7);\n        int\
    \ m = (n + bs - 1) / bs;\n        t.reserve(m + 1);\n        vector<int> ids(m);\n\
    \        for (int i = 0; i < m; i++) {\n            int v = ids[i] = new_node();\n\
    \            int l = i * bs, r = std::min(n, l + bs);\n            for (int j\
    \ = l; j < r; j++) t[v].data[j - l] = a[j];\n            t[v].size = r - l;\n\
    \        }\n        root = build(ids, 0, m);\n    }\n\n    int size() const {\
    \ return t[root].total; }\n    bool empty() const { return root == 0; }\n\n  \
    \  // x \u3092\u633F\u5165\u3059\u308B\uFF0E\u633F\u5165\u3057\u305F\u3089 true\uFF0C\
    \u65E2\u306B\u3042\u308C\u3070 false\n    bool insert(const T &x) {\n        done\
    \ = false;\n        root = insert(root, x);\n        return done;\n    }\n\n \
    \   // x \u3092\u524A\u9664\u3059\u308B\uFF0E\u524A\u9664\u3057\u305F\u3089 true\uFF0C\
    \u306A\u3051\u308C\u3070 false\n    bool erase(const T &x) {\n        done = false;\n\
    \        root = erase(root, x);\n        return done;\n    }\n\n    bool contains(const\
    \ T &x) const {\n        for (int v = root; v;) {\n            const Node &nd\
    \ = t[v];\n            if (x < nd.data[0]) v = nd.left;\n            else if (nd.data[nd.size\
    \ - 1] < x) v = nd.right;\n            else {\n                for (int i = 0;\
    \ i < nd.size; i++) if (!(nd.data[i] < x)) return !(x < nd.data[i]);\n       \
    \         return false;\n            }\n        }\n        return false;\n   \
    \ }\n    size_t count(const T &x) const { return contains(x); }\n\n    // \u5C0F\
    \u3055\u3044\u65B9\u304B\u3089 k \u756A\u76EE (0-indexed) \u306E\u8981\u7D20\uFF0E\
    k >= size() \u306A\u3089 def\n    T kth(int k, T def = T(-1)) const {\n      \
    \  if (k < 0 || k >= size()) return def;\n        for (int v = root;;) {\n   \
    \         const Node &nd = t[v];\n            int ls = t[nd.left].total;\n   \
    \         if (k < ls) v = nd.left;\n            else if (k < ls + nd.size) return\
    \ nd.data[k - ls];\n            else k -= ls + nd.size, v = nd.right;\n      \
    \  }\n    }\n\n    // x \u672A\u6E80\u306E\u8981\u7D20\u306E\u500B\u6570\n   \
    \ int count_lt(const T &x) const {\n        int res = 0;\n        for (int v =\
    \ root; v;) {\n            const Node &nd = t[v];\n            if (!(nd.data[0]\
    \ < x)) v = nd.left;\n            else if (nd.data[nd.size - 1] < x) res += nd.total\
    \ - t[nd.right].total, v = nd.right;\n            else {\n                int\
    \ i = 0;\n                while (nd.data[i] < x) i++;\n                return\
    \ res + t[nd.left].total + i;\n            }\n        }\n        return res;\n\
    \    }\n\n    // x \u4EE5\u4E0B\u306E\u8981\u7D20\u306E\u500B\u6570\n    int count_le(const\
    \ T &x) const {\n        int res = 0;\n        for (int v = root; v;) {\n    \
    \        const Node &nd = t[v];\n            if (x < nd.data[0]) v = nd.left;\n\
    \            else if (!(x < nd.data[nd.size - 1])) res += nd.total - t[nd.right].total,\
    \ v = nd.right;\n            else {\n                int i = 0;\n            \
    \    while (!(x < nd.data[i])) i++;\n                return res + t[nd.left].total\
    \ + i;\n            }\n        }\n        return res;\n    }\n\n    // [lo, hi)\
    \ \u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u306E\u500B\u6570\n    int count_range(const\
    \ T &lo, const T &hi) const { return lo < hi ? count_lt(hi) - count_lt(lo) : 0;\
    \ }\n\n    // x \u672A\u6E80\u306E\u6700\u5927\u306E\u8981\u7D20 (\u306A\u3051\
    \u308C\u3070 def)\n    T max_lt(const T &x, T def = T(-1)) const {\n        for\
    \ (int v = root; v;) {\n            const Node &nd = t[v];\n            if (!(nd.data[0]\
    \ < x)) v = nd.left;\n            else if (nd.data[nd.size - 1] < x) def = nd.data[nd.size\
    \ - 1], v = nd.right;\n            else {\n                int i = 1;\n      \
    \          while (nd.data[i] < x) i++;\n                return nd.data[i - 1];\n\
    \            }\n        }\n        return def;\n    }\n\n    // x \u4EE5\u4E0B\
    \u306E\u6700\u5927\u306E\u8981\u7D20 (\u306A\u3051\u308C\u3070 def)\n    T max_le(const\
    \ T &x, T def = T(-1)) const {\n        for (int v = root; v;) {\n           \
    \ const Node &nd = t[v];\n            if (x < nd.data[0]) v = nd.left;\n     \
    \       else if (!(x < nd.data[nd.size - 1])) def = nd.data[nd.size - 1], v =\
    \ nd.right;\n            else {\n                int i = 1;\n                while\
    \ (!(x < nd.data[i])) i++;\n                return nd.data[i - 1];\n         \
    \   }\n        }\n        return def;\n    }\n\n    // x \u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u306E\u8981\u7D20 (\u306A\u3051\u308C\u3070 def)\n    T min_ge(const T\
    \ &x, T def = T(-1)) const {\n        for (int v = root; v;) {\n            const\
    \ Node &nd = t[v];\n            if (!(nd.data[0] < x)) def = nd.data[0], v = nd.left;\n\
    \            else if (nd.data[nd.size - 1] < x) v = nd.right;\n            else\
    \ {\n                int i = 1;\n                while (nd.data[i] < x) i++;\n\
    \                return nd.data[i];\n            }\n        }\n        return\
    \ def;\n    }\n\n    // x \u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u8981\
    \u7D20 (\u306A\u3051\u308C\u3070 def)\n    T min_gt(const T &x, T def = T(-1))\
    \ const {\n        for (int v = root; v;) {\n            const Node &nd = t[v];\n\
    \            if (x < nd.data[0]) def = nd.data[0], v = nd.left;\n            else\
    \ if (!(x < nd.data[nd.size - 1])) v = nd.right;\n            else {\n       \
    \         int i = 1;\n                while (!(x < nd.data[i])) i++;\n       \
    \         return nd.data[i];\n            }\n        }\n        return def;\n\
    \    }\n\n    // \u6700\u5C0F\u306E\u8981\u7D20 / \u6700\u5927\u306E\u8981\u7D20\
    \ (\u7A7A\u306A\u3089 def)\n    T min(T def = T(-1)) const {\n        if (!root)\
    \ return def;\n        int v = root;\n        while (t[v].left) v = t[v].left;\n\
    \        return t[v].data[0];\n    }\n    T max(T def = T(-1)) const {\n     \
    \   if (!root) return def;\n        int v = root;\n        while (t[v].right)\
    \ v = t[v].right;\n        return t[v].data[t[v].size - 1];\n    }\n\n    // \u8981\
    \u7D20\u3092\u6607\u9806\u306B\u5217\u6319\n    vector<T> to_vector() const {\n\
    \        vector<T> res;\n        res.reserve(size());\n        auto dfs = [&](auto\
    \ self, int v) -> void {\n            if (!v) return;\n            self(self,\
    \ t[v].left);\n            res.insert(res.end(), t[v].data, t[v].data + t[v].size);\n\
    \            self(self, t[v].right);\n        };\n        dfs(dfs, root);\n  \
    \      return res;\n    }\n\n  private:\n    bool done = false;\n\n    int new_node()\
    \ {\n        int v;\n        if (!free_list.empty()) v = free_list.back(), free_list.pop_back();\n\
    \        else v = t.size(), t.emplace_back();\n        Node &nd = t[v];\n    \
    \    nd.left = nd.right = 0, nd.size = 0, nd.height = 1, nd.total = 0;\n     \
    \   return v;\n    }\n\n    int build(const vector<int> &ids, int l, int r) {\n\
    \        int m = (l + r) / 2, v = ids[m];\n        t[v].left = l < m ? build(ids,\
    \ l, m) : 0;\n        t[v].right = m + 1 < r ? build(ids, m + 1, r) : 0;\n   \
    \     update(v);\n        return v;\n    }\n\n    void update(int v) {\n     \
    \   Node &nd = t[v];\n        nd.height = std::max(t[nd.left].height, t[nd.right].height)\
    \ + 1;\n        nd.total = nd.size + t[nd.left].total + t[nd.right].total;\n \
    \   }\n    int balance_factor(int v) const { return t[t[v].left].height - t[t[v].right].height;\
    \ }\n\n    int rotate_right(int v) {\n        int l = t[v].left;\n        t[v].left\
    \ = t[l].right, t[l].right = v;\n        update(v), update(l);\n        return\
    \ l;\n    }\n    int rotate_left(int v) {\n        int r = t[v].right;\n     \
    \   t[v].right = t[r].left, t[r].left = v;\n        update(v), update(r);\n  \
    \      return r;\n    }\n    // update(v) \u6E08\u307F\u3067\u3042\u308B\u3053\
    \u3068\n    int balance(int v) {\n        int bf = balance_factor(v);\n      \
    \  if (bf == 2) {\n            if (balance_factor(t[v].left) < 0) t[v].left =\
    \ rotate_left(t[v].left);\n            return rotate_right(v);\n        }\n  \
    \      if (bf == -2) {\n            if (balance_factor(t[v].right) > 0) t[v].right\
    \ = rotate_right(t[v].right);\n            return rotate_left(v);\n        }\n\
    \        return v;\n    }\n\n    // \u30CE\u30FC\u30C9\u5185\u306B\u633F\u5165\
    \ (size < B \u3067\u3042\u308B\u3053\u3068)\uFF0E\u65E2\u306B\u3042\u308C\u3070\
    \ false\n    bool node_insert(Node &nd, const T &x) {\n        int i = 0;\n  \
    \      while (i < nd.size && nd.data[i] < x) i++;\n        if (i < nd.size &&\
    \ !(x < nd.data[i])) return false;\n        for (int j = nd.size; j > i; j--)\
    \ nd.data[j] = nd.data[j - 1];\n        nd.data[i] = x, nd.size++;\n        return\
    \ true;\n    }\n    bool node_erase(Node &nd, const T &x) {\n        int i = 0;\n\
    \        while (i < nd.size && nd.data[i] < x) i++;\n        if (i == nd.size\
    \ || x < nd.data[i]) return false;\n        for (int j = i + 1; j < nd.size; j++)\
    \ nd.data[j - 1] = nd.data[j];\n        nd.size--;\n        return true;\n   \
    \ }\n    // \u6E80\u676F\u306E\u30CE\u30FC\u30C9 v \u306E\u5F8C\u534A\u3092\u65B0\
    \u3057\u3044\u30CE\u30FC\u30C9\u306B\u79FB\u3057\u3066\uFF0C\u305D\u306E\u756A\
    \u53F7\u3092\u8FD4\u3059\n    int split(int v) {\n        int u = new_node();\n\
    \        constexpr int h = B / 2;\n        for (int i = 0; i < B - h; i++) t[u].data[i]\
    \ = t[v].data[h + i];\n        t[u].size = B - h, t[v].size = h;\n        return\
    \ u;\n    }\n\n    // \u90E8\u5206\u6728 v \u306E\u5168\u8981\u7D20\u3088\u308A\
    \u5C0F\u3055\u3044 x \u3092\u633F\u5165\u3059\u308B\n    int insert_leftmost(int\
    \ v, const T &x) {\n        if (t[v].left) {\n            int l = insert_leftmost(t[v].left,\
    \ x);\n            t[v].left = l;\n            update(v);\n            return\
    \ balance(v);\n        }\n        node_insert(t[v], x);\n        if (t[v].size\
    \ < B) {\n            update(v);\n            return v;\n        }\n        int\
    \ u = split(v);\n        t[u].left = v, t[u].right = t[v].right, t[v].right =\
    \ 0;\n        update(v), update(u);\n        return balance(u);\n    }\n\n   \
    \ int insert(int v, const T &x) {\n        if (!v) {\n            v = new_node();\n\
    \            t[v].data[0] = x, t[v].size = 1;\n            update(v);\n      \
    \      done = true;\n            return v;\n        }\n        if (t[v].left &&\
    \ x < t[v].data[0]) {\n            int l = insert(t[v].left, x);\n           \
    \ t[v].left = l;\n        } else if (t[v].right && t[v].data[t[v].size - 1] <\
    \ x) {\n            int r = insert(t[v].right, x);\n            t[v].right = r;\n\
    \        } else {\n            done = node_insert(t[v], x);\n            if (t[v].size\
    \ == B) {\n                if (t[v].right) {\n                    // \u6700\u5927\
    \u306E\u8981\u7D20\u3092\u53F3\u90E8\u5206\u6728\u306E\u5148\u982D\u306B\u56DE\
    \u3059\n                    T y = t[v].data[--t[v].size];\n                  \
    \  int r = insert_leftmost(t[v].right, y);\n                    t[v].right = r;\n\
    \                } else {\n                    int u = split(v);\n           \
    \         update(u);\n                    t[v].right = u;\n                }\n\
    \            }\n        }\n        update(v);\n        return balance(v);\n  \
    \  }\n\n    // \u90E8\u5206\u6728 v \u306E\u6700\u3082\u5DE6\u306E\u30CE\u30FC\
    \u30C9\u3092\u5207\u308A\u96E2\u3059 (u \u306B\u5165\u308C\u308B)\uFF0E\u6B8B\u3063\
    \u305F\u90E8\u5206\u6728\u306E\u6839\u3092\u8FD4\u3059\n    int cut_leftmost(int\
    \ v, int &u) {\n        if (!t[v].left) {\n            u = v;\n            return\
    \ t[v].right;\n        }\n        int l = cut_leftmost(t[v].left, u);\n      \
    \  t[v].left = l;\n        update(v);\n        return balance(v);\n    }\n\n \
    \   int erase(int v, const T &x) {\n        if (!v) return 0;\n        if (x <\
    \ t[v].data[0]) {\n            int l = erase(t[v].left, x);\n            t[v].left\
    \ = l;\n        } else if (t[v].data[t[v].size - 1] < x) {\n            int r\
    \ = erase(t[v].right, x);\n            t[v].right = r;\n        } else {\n   \
    \         done = node_erase(t[v], x);\n            if (t[v].size == 0) {\n   \
    \             // \u7A7A\u306B\u306A\u3063\u305F\u30CE\u30FC\u30C9\u3092\u6728\u304B\
    \u3089\u5916\u3059\n                free_list.push_back(v);\n                if\
    \ (!t[v].left || !t[v].right) return t[v].left ? t[v].left : t[v].right;\n   \
    \             int u = 0;\n                int r = cut_leftmost(t[v].right, u);\n\
    \                t[u].left = t[v].left, t[u].right = r;\n                update(u);\n\
    \                return balance(u);\n            }\n        }\n        update(v);\n\
    \        return balance(v);\n    }\n};\n#line 4 \"data_structure/dynamic_range_frequency.hpp\"\
    \n\n// \u4E00\u70B9\u66F4\u65B0\u304C\u3067\u304D\u308B\u533A\u9593\u306E\u5024\
    \u306E\u500B\u6570 (Point Set Range Frequency)\uFF0E\u30AA\u30F3\u30E9\u30A4\u30F3\
    \n// (\u5024, \u4F4D\u7F6E) \u306E\u7D44\u3092\u9806\u5E8F\u4ED8\u304D\u96C6\u5408\
    \u306B\u5165\u308C\u3066\u304A\u304D\uFF0C(x, l) \u4EE5\u4E0A (x, r) \u672A\u6E80\
    \u306E\u500B\u6570\u3092\u6570\u3048\u308B\n// \u66F4\u65B0\u30FB\u30AF\u30A8\u30EA\
    \ O(log n)\ntemplate <class T>\nstruct DynamicRangeFrequency {\n    int n;\n \
    \   vector<T> a;\n    OrderedSet<pair<T, int>> st;\n\n    DynamicRangeFrequency(const\
    \ vector<T> &a_) : n(a_.size()), a(a_) {\n        vector<pair<T, int>> v(n);\n\
    \        for (int i = 0; i < n; i++) v[i] = {a[i], i};\n        sort(v.begin(),\
    \ v.end());\n        st = OrderedSet<pair<T, int>>(v);\n    }\n\n    T get(int\
    \ i) const { return a[i]; }\n\n    // a[i] = x\n    void set(int i, const T &x)\
    \ {\n        st.erase({a[i], i});\n        a[i] = x;\n        st.insert({a[i],\
    \ i});\n    }\n\n    // a[l..r) \u306E\u4E2D\u306E x \u306E\u500B\u6570\n    int\
    \ count(int l, int r, const T &x) const { return l < r ? st.count_range({x, l},\
    \ {x, r}) : 0; }\n};\n#line 8 \"test/unittest/static_range_queries.test.cpp\"\n\
    \n// \u9759\u7684\u306A\u533A\u9593\u30AF\u30A8\u30EA (\u983B\u5EA6\u30FB\u7A2E\
    \u985E\u6570\u30FB\u6700\u983B\u5024\u30FB\u8EE2\u5012\u6570) \u3068 DynamicRangeFrequency\
    \ \u3092\u611A\u76F4\u3068\u7167\u5408\u3059\u308B\n\nint main() {\n    mt19937_64\
    \ rng(13);\n    for (int it = 0; it < 200; it++) {\n        int n = rng() % 60\
    \ + (it < 5 ? 0 : 1);\n        int sigma = rng() % 3 == 0 ? 3 : 1000000000;\n\
    \        vector<long long> a(n);\n        for (auto &x : a) x = (long long)(rng()\
    \ % sigma) - sigma / 2;\n        StaticRangeFrequency<long long> fr(a);\n    \
    \    StaticRangeCountDistinct<long long> cd(a);\n        StaticRangeMode<long\
    \ long> md(a);\n        StaticRangeInversions<long long> inv(a), inv3(a, 3);\n\
    \        for (int l = 0; l <= n; l++) {\n            for (int r = l; r <= n; r++)\
    \ {\n                map<long long, int> cnt;\n                long long iv =\
    \ 0;\n                for (int i = l; i < r; i++) {\n                    cnt[a[i]]++;\n\
    \                    for (int j = i + 1; j < r; j++) iv += a[i] > a[j];\n    \
    \            }\n                long long x = rng() % 2 && l < r ? a[l + rng()\
    \ % (r - l)] : (long long)(rng() % sigma) - sigma / 2;\n                assert(fr.count(l,\
    \ r, x) == (cnt.count(x) ? cnt[x] : 0));\n                assert(cd.count(l, r)\
    \ == (int)cnt.size());\n                assert(inv.query(l, r) == iv && inv3.query(l,\
    \ r) == iv);\n                if (l < r) {\n                    int mx = 0;\n\
    \                    for (auto &[k, v] : cnt) mx = max(mx, v);\n             \
    \       auto [v, c] = md.query(l, r);\n                    assert(c == mx && cnt[v]\
    \ == mx);\n                }\n            }\n        }\n        // DynamicRangeFrequency\n\
    \        vector<int> b(n);\n        for (auto &x : b) x = rng() % 4;\n       \
    \ DynamicRangeFrequency<int> df(b);\n        for (int step = 0; step < 300 &&\
    \ n > 0; step++) {\n            if (rng() % 2) {\n                int i = rng()\
    \ % n, v = rng() % 4;\n                b[i] = v, df.set(i, v);\n            }\n\
    \            int l = rng() % (n + 1), r = rng() % (n + 1), x = rng() % 5;\n  \
    \          if (l > r) swap(l, r);\n            assert(df.count(l, r, x) == count(b.begin()\
    \ + l, b.begin() + r, x));\n            int i = rng() % n;\n            assert(df.get(i)\
    \ == b[i]);\n        }\n    }\n    long long a_, b_;\n    fin >> a_ >> b_;\n \
    \   fout << a_ + b_ << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../io/fastio.hpp\"\
    \n#include \"../../data_structure/static_range_frequency.hpp\"\n#include \"../../data_structure/static_range_count_distinct.hpp\"\
    \n#include \"../../data_structure/static_range_mode.hpp\"\n#include \"../../data_structure/static_range_inversions.hpp\"\
    \n#include \"../../data_structure/dynamic_range_frequency.hpp\"\n\n// \u9759\u7684\
    \u306A\u533A\u9593\u30AF\u30A8\u30EA (\u983B\u5EA6\u30FB\u7A2E\u985E\u6570\u30FB\
    \u6700\u983B\u5024\u30FB\u8EE2\u5012\u6570) \u3068 DynamicRangeFrequency \u3092\
    \u611A\u76F4\u3068\u7167\u5408\u3059\u308B\n\nint main() {\n    mt19937_64 rng(13);\n\
    \    for (int it = 0; it < 200; it++) {\n        int n = rng() % 60 + (it < 5\
    \ ? 0 : 1);\n        int sigma = rng() % 3 == 0 ? 3 : 1000000000;\n        vector<long\
    \ long> a(n);\n        for (auto &x : a) x = (long long)(rng() % sigma) - sigma\
    \ / 2;\n        StaticRangeFrequency<long long> fr(a);\n        StaticRangeCountDistinct<long\
    \ long> cd(a);\n        StaticRangeMode<long long> md(a);\n        StaticRangeInversions<long\
    \ long> inv(a), inv3(a, 3);\n        for (int l = 0; l <= n; l++) {\n        \
    \    for (int r = l; r <= n; r++) {\n                map<long long, int> cnt;\n\
    \                long long iv = 0;\n                for (int i = l; i < r; i++)\
    \ {\n                    cnt[a[i]]++;\n                    for (int j = i + 1;\
    \ j < r; j++) iv += a[i] > a[j];\n                }\n                long long\
    \ x = rng() % 2 && l < r ? a[l + rng() % (r - l)] : (long long)(rng() % sigma)\
    \ - sigma / 2;\n                assert(fr.count(l, r, x) == (cnt.count(x) ? cnt[x]\
    \ : 0));\n                assert(cd.count(l, r) == (int)cnt.size());\n       \
    \         assert(inv.query(l, r) == iv && inv3.query(l, r) == iv);\n         \
    \       if (l < r) {\n                    int mx = 0;\n                    for\
    \ (auto &[k, v] : cnt) mx = max(mx, v);\n                    auto [v, c] = md.query(l,\
    \ r);\n                    assert(c == mx && cnt[v] == mx);\n                }\n\
    \            }\n        }\n        // DynamicRangeFrequency\n        vector<int>\
    \ b(n);\n        for (auto &x : b) x = rng() % 4;\n        DynamicRangeFrequency<int>\
    \ df(b);\n        for (int step = 0; step < 300 && n > 0; step++) {\n        \
    \    if (rng() % 2) {\n                int i = rng() % n, v = rng() % 4;\n   \
    \             b[i] = v, df.set(i, v);\n            }\n            int l = rng()\
    \ % (n + 1), r = rng() % (n + 1), x = rng() % 5;\n            if (l > r) swap(l,\
    \ r);\n            assert(df.count(l, r, x) == count(b.begin() + l, b.begin()\
    \ + r, x));\n            int i = rng() % n;\n            assert(df.get(i) == b[i]);\n\
    \        }\n    }\n    long long a_, b_;\n    fin >> a_ >> b_;\n    fout << a_\
    \ + b_ << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - io/fastio.hpp
  - template.hpp
  - data_structure/static_range_frequency.hpp
  - template.hpp
  - data_structure/static_range_count_distinct.hpp
  - data_structure/wavelet_matrix.hpp
  - data_structure/static_range_mode.hpp
  - data_structure/static_range_inversions.hpp
  - data_structure/dynamic_range_frequency.hpp
  - data_structure/ordered_set.hpp
  isVerificationFile: true
  path: test/unittest/static_range_queries.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:42:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/static_range_queries.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/static_range_queries.test.cpp
- /verify/test/unittest/static_range_queries.test.cpp.html
title: test/unittest/static_range_queries.test.cpp
---
