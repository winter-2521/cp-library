---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/area_of_union_of_rectangles.hpp
    title: "\u9577\u65B9\u5F62\u306E\u548C\u96C6\u5408\u306E\u9762\u7A4D (Area of\
      \ Union of Rectangles)"
  - icon: ':heavy_check_mark:'
    path: data_structure/rectangle_add_point_get.hpp
    title: "\u9577\u65B9\u5F62\u52A0\u7B97\u30FB\u4E00\u70B9\u53D6\u5F97 (Rectangle\
      \ Add Point Get)"
  - icon: ':heavy_check_mark:'
    path: data_structure/static_rectangle_add_rectangle_sum.hpp
    title: "\u9577\u65B9\u5F62\u52A0\u7B97\u306E\u5F8C\u306E\u9577\u65B9\u5F62\u548C\
      \ (Static Rectangle Add Rectangle Sum)"
  - icon: ':heavy_check_mark:'
    path: data_structure/static_rectangle_sum.hpp
    title: "\u9577\u65B9\u5F62\u306E\u4E2D\u306E\u70B9\u306E\u91CD\u307F\u306E\u548C\
      \ (Rectangle Sum)"
  - icon: ':heavy_check_mark:'
    path: io/fastio.hpp
    title: "\u9AD8\u901F\u5165\u51FA\u529B (Fast I/O)"
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: "ModInt (\u6CD5\u304C\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u5B9A\u6570\u306E\
      \ modint)"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
  bundledCode: "#line 1 \"test/unittest/rectangle_add.test.cpp\"\n#define PROBLEM\
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
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 3 \"math/modint.hpp\"\
    \n\n// \u6CD5 MOD \u304C \u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u5B9A\u6570\u306E\
    \ modint\n// MOD < 2^31 \u3067\u3042\u308B\u3053\u3068 (\u7D20\u6570\u3067\u306A\
    \u304F\u3066\u3082\u3088\u3044\uFF0E\u305F\u3060\u3057 inv() \u306F MOD \u3068\
    \u4E92\u3044\u306B\u7D20\u306A\u5024\u306B\u5BFE\u3057\u3066\u306E\u307F\u6709\
    \u52B9)\n// \u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9\u306F ACL (atcoder::static_modint)\
    \ \u3068\u63C3\u3048\u3066\u3042\u308B\uFF0E\n// \u3053\u306E\u30E9\u30A4\u30D6\
    \u30E9\u30EA\u306E\u4ED6\u306E\u30D5\u30A1\u30A4\u30EB (fastio \u306A\u3069) \u306F\
    \ ACL \u306E modint \u3067\u3082\u305D\u306E\u307E\u307E\u52D5\u304F\ntemplate\
    \ <uint32_t MOD>\nstruct ModInt {\n    static_assert(1 <= MOD && MOD < (1u <<\
    \ 31), \"MOD must be in [1, 2^31)\");\n    using mint = ModInt;\n    uint32_t\
    \ v;\n\n    static constexpr int mod() { return MOD; }\n\n    constexpr ModInt()\
    \ : v(0) {}\n\n    template <class T, enable_if_t<is_integral_v<T>, nullptr_t>\
    \ = nullptr>\n    constexpr ModInt(T x) : v(0) {\n        if constexpr (is_signed_v<T>)\
    \ {\n            long long y = (long long)(x % (long long)MOD);\n            if\
    \ (y < 0) y += MOD;\n            v = uint32_t(y);\n        } else {\n        \
    \    v = uint32_t(x % MOD);\n        }\n    }\n\n    // 0 <= x < MOD \u304C\u5206\
    \u304B\u3063\u3066\u3044\u308B\u3068\u304D\u306B\u5270\u4F59\u3092\u53D6\u3089\
    \u305A\u306B\u4F5C\u308B\n    static constexpr mint raw(int x) {\n        mint\
    \ r;\n        r.v = x;\n        return r;\n    }\n\n    // ACL (\u73FE\u884C\u7248\
    ) \u3068\u540C\u3058\u304F int \u3067\u8FD4\u3059\n    constexpr int val() const\
    \ { return int(v); }\n\n    constexpr mint &operator+=(const mint &r) {\n    \
    \    v += r.v;\n        if (v >= MOD) v -= MOD;\n        return *this;\n    }\n\
    \    constexpr mint &operator-=(const mint &r) {\n        v += MOD - r.v;\n  \
    \      if (v >= MOD) v -= MOD;\n        return *this;\n    }\n    constexpr mint\
    \ &operator*=(const mint &r) {\n        // MOD \u304C\u5B9A\u6570\u306A\u306E\u3067\
    \ % \u306F\u4E57\u7B97\u3068\u30B7\u30D5\u30C8\u306B\u6700\u9069\u5316\u3055\u308C\
    \u308B\n        v = uint32_t((uint64_t)v * r.v % MOD);\n        return *this;\n\
    \    }\n    constexpr mint &operator/=(const mint &r) { return *this *= r.inv();\
    \ }\n\n    constexpr mint operator+() const { return *this; }\n    constexpr mint\
    \ operator-() const { return raw(v == 0 ? 0 : MOD - v); }\n\n    constexpr mint\
    \ &operator++() { return *this += raw(1); }\n    constexpr mint &operator--()\
    \ { return *this -= raw(1); }\n    constexpr mint operator++(int) { mint r = *this;\
    \ ++*this; return r; }\n    constexpr mint operator--(int) { mint r = *this; --*this;\
    \ return r; }\n\n    friend constexpr mint operator+(mint l, const mint &r) {\
    \ return l += r; }\n    friend constexpr mint operator-(mint l, const mint &r)\
    \ { return l -= r; }\n    friend constexpr mint operator*(mint l, const mint &r)\
    \ { return l *= r; }\n    friend constexpr mint operator/(mint l, const mint &r)\
    \ { return l /= r; }\n    friend constexpr bool operator==(const mint &l, const\
    \ mint &r) { return l.v == r.v; }\n    friend constexpr bool operator!=(const\
    \ mint &l, const mint &r) { return l.v != r.v; }\n\n    // this^n (n < 0 \u306A\
    \u3089\u9006\u5143\u306E -n \u4E57)\n    constexpr mint pow(long long n) const\
    \ {\n        mint x = n >= 0 ? *this : inv(), r = raw(1 % MOD);\n        unsigned\
    \ long long e = n >= 0 ? (unsigned long long)n : 0ULL - (unsigned long long)n;\n\
    \        while (e) {\n            if (e & 1) r *= x;\n            x *= x;\n  \
    \          e >>= 1;\n        }\n        return r;\n    }\n\n    // \u62E1\u5F35\
    \u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\u306B\u3088\u308B\
    \u9006\u5143 (MOD \u304C\u7D20\u6570\u3067\u306A\u304F\u3066\u3082 gcd(v, MOD)\
    \ = 1 \u306A\u3089\u6B63\u3057\u3044)\n    constexpr mint inv() const {\n    \
    \    long long a = v, b = MOD, x = 1, y = 0;\n        while (b) {\n          \
    \  long long t = a / b;\n            a -= t * b, swap(a, b);\n            x -=\
    \ t * y, swap(x, y);\n        }\n        assert(a == 1);\n        return mint(x);\n\
    \    }\n\n    friend ostream &operator<<(ostream &os, const mint &x) { return\
    \ os << x.v; }\n    friend istream &operator>>(istream &is, mint &x) {\n     \
    \   long long t;\n        is >> t;\n        x = mint(t);\n        return is;\n\
    \    }\n};\n\nusing ModInt998244353 = ModInt<998244353>;\nusing ModInt1000000007\
    \ = ModInt<1000000007>;\n#line 2 \"template.hpp\"\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
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
    \ 3 \"data_structure/static_rectangle_sum.hpp\"\n\n// \u9759\u7684\u306A\u91CD\
    \u307F\u4ED8\u304D\u70B9\u306E\u9577\u65B9\u5F62\u548C (Rectangle Sum)\uFF0E\u30AA\
    \u30F3\u30E9\u30A4\u30F3\n// \u70B9\u3092 x \u3067\u30BD\u30FC\u30C8\u3057\uFF0C\
    y (\u5EA7\u6A19\u5727\u7E2E) \u306E\u5217\u3092\u91CD\u307F\u4ED8\u304D\u30A6\u30A7\
    \u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217\u3067\u6301\u3064\uFF0E\u69CB\u7BC9\
    \ O(n log n)\uFF0C\u30AF\u30A8\u30EA O(log n)\n// X: \u5EA7\u6A19\u306E\u578B\uFF0C\
    W: \u91CD\u307F\u306E\u578B\ntemplate <class X, class W>\nstruct StaticRectangleSum\
    \ {\n    // 64 bit \u3054\u3068\u306B\uFF0C\u30D3\u30C3\u30C8\u5217\u3068\u305D\
    \u308C\u3088\u308A\u524D\u306E 1 \u306E\u500B\u6570\u3092\u307E\u3068\u3081\u3066\
    \u6301\u3064\n    struct BitVector {\n        struct Block {\n            uint64_t\
    \ bits;\n            int cnt;\n        };\n        vector<Block> b;\n        void\
    \ init(int n) { b.assign((n >> 6) + 1, {0, 0}); }\n        void set(int i) { b[i\
    \ >> 6].bits |= 1ULL << (i & 63); }\n        void build() {\n            for (size_t\
    \ i = 1; i < b.size(); i++) b[i].cnt = b[i - 1].cnt + __builtin_popcountll(b[i\
    \ - 1].bits);\n        }\n        int rank1(int i) const {\n            const\
    \ Block &x = b[i >> 6];\n            return x.cnt + __builtin_popcountll(x.bits\
    \ & ((1ULL << (i & 63)) - 1));\n        }\n    };\n\n    int n, lg;\n    vector<X>\
    \ xs, ys;           // xs: \u70B9\u306E x (\u6607\u9806)\uFF0Cys: y \u306E\u7A2E\
    \u985E (\u6607\u9806)\n    vector<BitVector> bv;\n    vector<int> zeros;\n   \
    \ vector<vector<W>> sum;      // sum[h][i]: \u6BB5 h \u3067\u632F\u308A\u5206\u3051\
    \u305F\u5F8C\u306E\u5217\u306E\u5148\u982D i \u500B\u306E\u91CD\u307F\u306E\u548C\
    \n\n    StaticRectangleSum() : n(0), lg(0) {}\n    StaticRectangleSum(const vector<X>\
    \ &x, const vector<X> &y, const vector<W> &w) : n(x.size()) {\n        vector<int>\
    \ ord(n);\n        iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(),\
    \ ord.end(), [&](int i, int j) { return x[i] < x[j]; });\n        xs.resize(n);\n\
    \        for (int k = 0; k < n; k++) xs[k] = x[ord[k]];\n        ys = y;\n   \
    \     sort(ys.begin(), ys.end());\n        ys.erase(unique(ys.begin(), ys.end()),\
    \ ys.end());\n        vector<int> cur(n), nxt(n);\n        vector<W> cw(n), nw(n);\n\
    \        for (int k = 0; k < n; k++) {\n            cur[k] = lower_bound(ys.begin(),\
    \ ys.end(), y[ord[k]]) - ys.begin();\n            cw[k] = w[ord[k]];\n       \
    \ }\n        lg = 1;\n        while ((1 << lg) < (int)ys.size()) lg++;\n     \
    \   bv.resize(lg), zeros.resize(lg), sum.assign(lg, vector<W>(n + 1, W(0)));\n\
    \        for (int h = lg - 1; h >= 0; h--) {\n            bv[h].init(n);\n   \
    \         int z = 0;\n            for (int i = 0; i < n; i++) {\n            \
    \    if (cur[i] >> h & 1) bv[h].set(i);\n                else z++;\n         \
    \   }\n            bv[h].build();\n            zeros[h] = z;\n            int\
    \ p0 = 0, p1 = z;\n            for (int i = 0; i < n; i++) {\n               \
    \ int p = (cur[i] >> h & 1) ? p1++ : p0++;\n                nxt[p] = cur[i], nw[p]\
    \ = cw[i];\n            }\n            swap(cur, nxt), swap(cw, nw);\n       \
    \     for (int i = 0; i < n; i++) sum[h][i + 1] = sum[h][i] + cw[i];\n       \
    \ }\n    }\n\n    int size() const { return n; }\n\n    // l <= x < r, d <= y\
    \ < u \u306E\u70B9\u306E\u91CD\u307F\u306E\u548C\n    W sum_rect(X l, X d, X r,\
    \ X u) const {\n        int il = lower_idx(xs, l), ir = lower_idx(xs, r);\n  \
    \      int yd = lower_idx(ys, d), yu = lower_idx(ys, u);\n        if (il >= ir\
    \ || yd >= yu) return W(0);\n        if (yu >= (1 << lg)) return total(il, ir)\
    \ - prefix(il, ir, yd);\n        // \u4E0A\u306E\u6BB5\u3067 yd \u3068 yu \u306E\
    \u30D3\u30C3\u30C8\u304C\u540C\u3058\u9593\u306F 2 \u3064\u306E\u548C\u306E\u5DEE\
    \u306B\u52B9\u304B\u306A\u3044\u306E\u3067\uFF0C\u5171\u901A\u306B\u964D\u308A\
    \u308B\n        int h = lg - 1;\n        for (; h >= 0 && ((yd ^ yu) >> h & 1)\
    \ == 0; h--) {\n            int l1 = bv[h].rank1(il), r1 = bv[h].rank1(ir);\n\
    \            if (yu >> h & 1) il = zeros[h] + l1, ir = zeros[h] + r1;\n      \
    \      else il -= l1, ir -= r1;\n        }\n        // \u30D3\u30C3\u30C8 h \u3067\
    \ yd \u306F 0\uFF0Cyu \u306F 1\n        int l1 = bv[h].rank1(il), r1 = bv[h].rank1(ir);\n\
    \        int l0 = il - l1, r0 = ir - r1;\n        return (sum[h][r0] - sum[h][l0])\
    \ + prefix_from(zeros[h] + l1, zeros[h] + r1, yu, h - 1) - prefix_from(l0, r0,\
    \ yd, h - 1);\n    }\n    W operator()(X l, X d, X r, X u) const { return sum_rect(l,\
    \ d, r, u); }\n\n  private:\n    // \u5206\u5C90\u306E\u5C11\u306A\u3044 lower_bound\
    \ (\u6DFB\u5B57\u3092\u8FD4\u3059)\n    static int lower_idx(const vector<X> &v,\
    \ const X &x) {\n        int n = v.size();\n        if (n == 0) return 0;\n  \
    \      const X *base = v.data();\n        while (n > 1) {\n            int half\
    \ = n >> 1;\n            base = base[half - 1] < x ? base + half : base;\n   \
    \         n -= half;\n        }\n        return int(base - v.data()) + (*base\
    \ < x);\n    }\n\n    // x \u306E\u9806\u3067 [l, r) \u756A\u76EE\u306E\u70B9\u306E\
    \u3046\u3061 y \u306E\u756A\u53F7\u304C v \u672A\u6E80\u306E\u3082\u306E\u306E\
    \u91CD\u307F\u306E\u548C\n    W prefix(int l, int r, int v) const {\n        if\
    \ (v >= (1 << lg)) return total(l, r);\n        return prefix_from(l, r, v, lg\
    \ - 1);\n    }\n    // \u6BB5 h \u304B\u3089\u4E0B\u3060\u3051\u3092\u898B\u308B\
    \u7248 (\u6BB5 h \u3067\u306E\u533A\u9593\u304C [l, r))\n    W prefix_from(int\
    \ l, int r, int v, int h0) const {\n        W res(0);\n        for (int h = h0;\
    \ h >= 0; h--) {\n            int l1 = bv[h].rank1(l), r1 = bv[h].rank1(r);\n\
    \            int l0 = l - l1, r0 = r - r1;\n            if (v >> h & 1) {\n  \
    \              res += sum[h][r0] - sum[h][l0];\n                l = zeros[h] +\
    \ l1, r = zeros[h] + r1;\n            } else {\n                l = l0, r = r0;\n\
    \            }\n        }\n        return res;\n    }\n    W total(int l, int\
    \ r) const {\n        // \u6700\u4E0A\u6BB5\u3067\u632F\u308A\u5206\u3051\u308B\
    \u524D\u306E [l, r) \u306E\u548C = 0 \u5074\u3068 1 \u5074\u306E\u548C\n     \
    \   int h = lg - 1;\n        int l1 = bv[h].rank1(l), r1 = bv[h].rank1(r);\n \
    \       return (sum[h][r - r1] - sum[h][l - l1]) + (sum[h][zeros[h] + r1] - sum[h][zeros[h]\
    \ + l1]);\n    }\n};\n\n// \u70B9\u306E\u8FFD\u52A0\u304C\u3067\u304D\u308B\u9577\
    \u65B9\u5F62\u548C (Point Add Rectangle Sum)\uFF0E\u30AA\u30F3\u30E9\u30A4\u30F3\
    \n// \u5927\u304D\u3055\u304C 2 \u51AA\u306E StaticRectangleSum \u3092\u9AD8\u3005\
    \ log \u500B\u6301\u3061\uFF0C\u8FFD\u52A0\u306E\u305F\u3073\u306B\u540C\u3058\
    \u5927\u304D\u3055\u306E\u3082\u306E\u3092\u4F75\u5408\u3057\u3066\u4F5C\u308A\
    \u76F4\u3059 (\u4E8C\u9032\u30AB\u30A6\u30F3\u30BF)\n// \u8FFD\u52A0\u306A\u3089\
    \u3057 O(log^2 n)\uFF0C\u30AF\u30A8\u30EA O(log^2 n)\ntemplate <class X, class\
    \ W>\nstruct DynamicRectangleSum {\n    struct Bucket {\n        vector<X> x,\
    \ y;\n        vector<W> w;\n        StaticRectangleSum<X, W> rs;\n    };\n   \
    \ vector<Bucket> buckets;\n\n    DynamicRectangleSum() = default;\n    // \u521D\
    \u671F\u306E\u70B9\u3092\u307E\u3068\u3081\u3066\u5165\u308C\u308B\n    DynamicRectangleSum(const\
    \ vector<X> &x, const vector<X> &y, const vector<W> &w) {\n        if (!x.empty())\
    \ buckets.push_back({x, y, w, StaticRectangleSum<X, W>(x, y, w)});\n    }\n\n\
    \    // \u70B9 (x, y) \u306B\u91CD\u307F w \u306E\u70B9\u3092\u8FFD\u52A0\n  \
    \  void add(X x, X y, W w) {\n        Bucket b{{x}, {y}, {w}, {}};\n        while\
    \ (!buckets.empty() && buckets.back().x.size() <= b.x.size()) {\n            Bucket\
    \ &t = buckets.back();\n            b.x.insert(b.x.end(), t.x.begin(), t.x.end());\n\
    \            b.y.insert(b.y.end(), t.y.begin(), t.y.end());\n            b.w.insert(b.w.end(),\
    \ t.w.begin(), t.w.end());\n            buckets.pop_back();\n        }\n     \
    \   b.rs = StaticRectangleSum<X, W>(b.x, b.y, b.w);\n        buckets.push_back(std::move(b));\n\
    \    }\n\n    // l <= x < r, d <= y < u \u306E\u70B9\u306E\u91CD\u307F\u306E\u548C\
    \n    W sum_rect(X l, X d, X r, X u) const {\n        W res(0);\n        for (auto\
    \ &b : buckets) res += b.rs.sum_rect(l, d, r, u);\n        return res;\n    }\n\
    \    W operator()(X l, X d, X r, X u) const { return sum_rect(l, d, r, u); }\n\
    };\n#line 4 \"data_structure/rectangle_add_point_get.hpp\"\n\n// \u9577\u65B9\u5F62\
    \u52A0\u7B97\u30FB\u4E00\u70B9\u53D6\u5F97 (Rectangle Add Point Get)\uFF0E\u30AA\
    \u30F3\u30E9\u30A4\u30F3\n// \u9577\u65B9\u5F62 [l, r) \xD7 [d, u) \u306B w \u3092\
    \u8DB3\u3059\u306E\u3092\uFF0C4 \u9685\u306B \xB1w \u306E\u70B9\u3092\u7F6E\u304F\
    \u3053\u3068 (2 \u6B21\u5143\u306E\u5DEE\u5206) \u306B\u76F4\u3059\uFF0E\n// \u70B9\
    \ (x, y) \u306E\u5024 = x' <= x \u304B\u3064 y' <= y \u306E\u70B9\u306E\u91CD\u307F\
    \u306E\u548C (DynamicRectangleSum \u3067\u6570\u3048\u308B)\n// \u52A0\u7B97\u306A\
    \u3089\u3057 O(log^2 n)\uFF0C\u53D6\u5F97 O(log^2 n)\ntemplate <class X, class\
    \ W>\nstruct RectangleAddPointGet {\n    DynamicRectangleSum<X, W> rs;\n\n   \
    \ RectangleAddPointGet() = default;\n    // \u521D\u671F\u306E\u9577\u65B9\u5F62\
    \ (l[i], d[i], r[i], u[i], w[i]) \u3092\u307E\u3068\u3081\u3066\u5165\u308C\u308B\
    \n    RectangleAddPointGet(const vector<X> &l, const vector<X> &d, const vector<X>\
    \ &r, const vector<X> &u, const vector<W> &w) {\n        int n = l.size();\n \
    \       vector<X> xs, ys;\n        vector<W> ws;\n        xs.reserve(4 * n), ys.reserve(4\
    \ * n), ws.reserve(4 * n);\n        for (int i = 0; i < n; i++) {\n          \
    \  xs.push_back(l[i]), ys.push_back(d[i]), ws.push_back(w[i]);\n            xs.push_back(l[i]),\
    \ ys.push_back(u[i]), ws.push_back(-w[i]);\n            xs.push_back(r[i]), ys.push_back(d[i]),\
    \ ws.push_back(-w[i]);\n            xs.push_back(r[i]), ys.push_back(u[i]), ws.push_back(w[i]);\n\
    \        }\n        rs = DynamicRectangleSum<X, W>(xs, ys, ws);\n    }\n\n   \
    \ // l <= x < r, d <= y < u \u306E\u5168\u3066\u306E\u70B9\u306B w \u3092\u8DB3\
    \u3059\n    void add(X l, X d, X r, X u, W w) {\n        rs.add(l, d, w), rs.add(l,\
    \ u, -w), rs.add(r, d, -w), rs.add(r, u, w);\n    }\n\n    // \u70B9 (x, y) \u306E\
    \u5024\n    W get(X x, X y) const {\n        X lo = numeric_limits<X>::lowest();\n\
    \        return rs.sum_rect(lo, lo, x + 1, y + 1);\n    }\n};\n#line 2 \"template.hpp\"\
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
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 4 \"data_structure/static_rectangle_add_rectangle_sum.hpp\"\
    \n\n// \u9577\u65B9\u5F62\u52A0\u7B97\u3092\u3059\u3079\u3066\u884C\u3063\u305F\
    \u5F8C\u306E\u9577\u65B9\u5F62\u548C (Static Rectangle Add Rectangle Sum)\uFF0E\
    \u52A0\u7B97\u306E\u5F8C\u306E\u30AF\u30A8\u30EA\u306F\u30AA\u30F3\u30E9\u30A4\
    \u30F3\n// \u9577\u65B9\u5F62 [l, r) \xD7 [d, u) \u3078\u306E w \u306E\u52A0\u7B97\
    \u3092 4 \u9685\u306E\u70B9 (p, q, \xB1w) \u306B\u3059\u308B\u3068\uFF0C\n// \
    \  S(X, Y) = \u03A3_{x<X, y<Y} A[x][y] = \u03A3_{p<X, q<Y} c (X - p)(Y - q)\n\
    //           = XY \u03A3c - X \u03A3cq - Y \u03A3cp + \u03A3cpq\n// \u306A\u306E\
    \u3067\uFF0C\u91CD\u307F (c, cp, cq, cpq) \u306E\u9577\u65B9\u5F62\u548C (StaticRectangleSum)\
    \ 1 \u56DE\u3067 S(X, Y) \u304C\u6C42\u307E\u308B\n// \u69CB\u7BC9 O(n log n)\uFF0C\
    \u30AF\u30A8\u30EA O(log n)\uFF0ET \u306F\u5024\u306E\u578B (modint \u306A\u3069\
    \uFF0E\u5EA7\u6A19\u306E\u7A4D\u3092 T \u3067\u8A08\u7B97\u3059\u308B)\ntemplate\
    \ <class X, class T>\nstruct StaticRectangleAddRectangleSum {\n    struct Quad\
    \ {\n        T c, cp, cq, cpq;\n        Quad(int z = 0) : c(z), cp(z), cq(z),\
    \ cpq(z) {}\n        Quad(T c, T cp, T cq, T cpq) : c(c), cp(cp), cq(cq), cpq(cpq)\
    \ {}\n        Quad &operator+=(const Quad &o) { return c += o.c, cp += o.cp, cq\
    \ += o.cq, cpq += o.cpq, *this; }\n        Quad operator+(const Quad &o) const\
    \ { return Quad(*this) += o; }\n        Quad operator-(const Quad &o) const {\
    \ return Quad(c - o.c, cp - o.cp, cq - o.cq, cpq - o.cpq); }\n    };\n    vector<X>\
    \ xs, ys;\n    vector<Quad> ws;\n    StaticRectangleSum<X, Quad> rs;\n    bool\
    \ built = false;\n\n    StaticRectangleAddRectangleSum() = default;\n\n    //\
    \ l <= x < r, d <= y < u \u306B w \u3092\u8DB3\u3059 (build \u524D\u306B\u547C\
    \u3076\u3053\u3068)\n    void add(X l, X d, X r, X u, T w) {\n        assert(!built);\n\
    \        add_corner(l, d, w), add_corner(l, u, -w), add_corner(r, d, -w), add_corner(r,\
    \ u, w);\n    }\n\n    void build() {\n        rs = StaticRectangleSum<X, Quad>(xs,\
    \ ys, ws);\n        built = true;\n    }\n\n    // l <= x < r, d <= y < u \u306E\
    \u548C (\u521D\u56DE\u306B build \u3057\u3066\u3044\u306A\u3051\u308C\u3070 build\
    \ \u3059\u308B)\n    T sum(X l, X d, X r, X u) {\n        if (!built) build();\n\
    \        return prefix(r, u) - prefix(l, u) - prefix(r, d) + prefix(l, d);\n \
    \   }\n\n    // x < X, y < Y \u306E\u548C\n    T prefix(X x, X y) const {\n  \
    \      X lo = numeric_limits<X>::lowest();\n        Quad q = rs.sum_rect(lo, lo,\
    \ x, y);\n        T tx(x), ty(y);\n        return tx * ty * q.c - tx * q.cq -\
    \ ty * q.cp + q.cpq;\n    }\n\n  private:\n    void add_corner(X p, X q, T c)\
    \ {\n        xs.push_back(p), ys.push_back(q);\n        T tp(p), tq(q);\n    \
    \    ws.emplace_back(c, c * tp, c * tq, c * tp * tq);\n    }\n};\n#line 2 \"template.hpp\"\
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
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 3 \"data_structure/area_of_union_of_rectangles.hpp\"\
    \n\n// \u9577\u65B9\u5F62\u306E\u548C\u96C6\u5408\u306E\u9762\u7A4D (Area of Union\
    \ of Rectangles)\n// x \u306E\u5C0F\u3055\u3044\u9806\u306B\u8D70\u67FB\u3057\uFF0C\
    y \u65B9\u5411\u3092\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3067\u7BA1\u7406\u3059\
    \u308B\uFF0E\u5404\u30CE\u30FC\u30C9\u306F\n//   cnt: \u3053\u306E\u30CE\u30FC\
    \u30C9\u306E\u533A\u9593\u300C\u5168\u4F53\u300D\u3092\u3061\u3087\u3046\u3069\
    \u8986\u3063\u3066\u3044\u308B\u9577\u65B9\u5F62\u306E\u6570 (\u5B50\u306B\u306F\
    \u4F1D\u3048\u306A\u3044)\n//   cov: \u3053\u306E\u30CE\u30FC\u30C9\u306E\u533A\
    \u9593\u306E\u3046\u3061\uFF0C\u3053\u306E\u30CE\u30FC\u30C9\u4EE5\u4E0B\u306E\
    \ cnt \u3067\u8986\u308F\u308C\u3066\u3044\u308B\u9577\u3055\n// \u3092\u6301\u3061\
    \uFF0Ccov = (cnt > 0 ? \u533A\u9593\u306E\u9577\u3055 : \u5B50\u306E cov \u306E\
    \u548C)\uFF0E\u9045\u5EF6\u4F1D\u64AD\u304C\u8981\u3089\u306A\u3044\u306E\u3067\
    \u901F\u3044\uFF0EO(n log n)\n// \u9577\u65B9\u5F62 i \u306F [l[i], r[i]] \xD7\
    \ [d[i], u[i]] (\u9762\u7A4D\u306F\u9589\u533A\u9593\u3067\u3082\u534A\u958B\u533A\
    \u9593\u3067\u3082\u540C\u3058)\ntemplate <class T>\nT area_of_union_of_rectangles(const\
    \ vector<T> &l, const vector<T> &d, const vector<T> &r, const vector<T> &u) {\n\
    \    int n = l.size();\n    // y \u5EA7\u6A19\u3092 (\u5024, 2i \u307E\u305F\u306F\
    \ 2i+1) \u3067\u30BD\u30FC\u30C8\u3057\u3066\u756A\u53F7\u3092\u632F\u308B (\u4E8C\
    \u5206\u63A2\u7D22\u3057\u306A\u3044)\n    vector<pair<T, int>> yv(2 * n);\n \
    \   for (int i = 0; i < n; i++) yv[2 * i] = {d[i], 2 * i}, yv[2 * i + 1] = {u[i],\
    \ 2 * i + 1};\n    sort(yv.begin(), yv.end());\n    vector<T> ys;\n    ys.reserve(2\
    \ * n);\n    vector<int> yi(2 * n);  // yi[2i] = d[i] \u306E\u756A\u53F7\uFF0C\
    yi[2i+1] = u[i] \u306E\u756A\u53F7\n    for (auto &[y, id] : yv) {\n        if\
    \ (ys.empty() || ys.back() != y) ys.push_back(y);\n        yi[id] = ys.size()\
    \ - 1;\n    }\n    int m = (int)ys.size() - 1;\n    if (m <= 0) return T(0);\n\
    \    int sz = 1;\n    while (sz < m) sz <<= 1;\n    struct Node {\n        T cov,\
    \ len;\n        int cnt;\n    };\n    vector<Node> t(2 * sz, Node{T(0), T(0),\
    \ 0});\n    for (int i = 0; i < m; i++) t[sz + i].len = ys[i + 1] - ys[i];\n \
    \   for (int k = sz - 1; k >= 1; k--) t[k].len = t[2 * k].len + t[2 * k + 1].len;\n\
    \    auto fix = [&](int k) { t[k].cov = t[k].cnt ? t[k].len : (k < sz ? t[2 *\
    \ k].cov + t[2 * k + 1].cov : T(0)); };\n    auto update = [&](int a, int b, int\
    \ c) {  // y \u306E\u533A\u9593 [a, b) \u306E\u88AB\u8986\u56DE\u6570\u306B c\
    \ \u3092\u8DB3\u3059\n        int a0 = a + sz, b0 = b + sz;\n        for (int\
    \ x = a0, y = b0; x < y; x >>= 1, y >>= 1) {\n            if (x & 1) t[x].cnt\
    \ += c, fix(x), x++;\n            if (y & 1) --y, t[y].cnt += c, fix(y);\n   \
    \     }\n        for (int k = a0 >> 1; k; k >>= 1) fix(k);\n        for (int k\
    \ = (b0 - 1) >> 1; k; k >>= 1) fix(k);\n    };\n    // \u30A4\u30D9\u30F3\u30C8\
    : \u9577\u65B9\u5F62 i \u306E\u5DE6\u7AEF\u3067 +1 (\u756A\u53F7 i)\uFF0C\u53F3\
    \u7AEF\u3067 -1 (\u756A\u53F7 ~i)\n    vector<pair<T, int>> ev;\n    ev.reserve(2\
    \ * n);\n    for (int i = 0; i < n; i++) ev.emplace_back(l[i], i), ev.emplace_back(r[i],\
    \ ~i);\n    sort(ev.begin(), ev.end());\n    T res(0);\n    for (int k = 0; k\
    \ < (int)ev.size(); k++) {\n        if (k > 0) res += t[1].cov * (ev[k].first\
    \ - ev[k - 1].first);\n        int i = ev[k].second;\n        if (i >= 0) update(yi[2\
    \ * i], yi[2 * i + 1], 1);\n        else update(yi[2 * ~i], yi[2 * ~i + 1], -1);\n\
    \    }\n    return res;\n}\n#line 7 \"test/unittest/rectangle_add.test.cpp\"\n\
    \n// RectangleAddPointGet / StaticRectangleAddRectangleSum / area_of_union_of_rectangles\
    \ \u3092\n// \u5C0F\u3055\u3044\u683C\u5B50\u306E\u611A\u76F4\u3068\u7167\u5408\
    \u3059\u308B (\u8CA0\u306E\u5EA7\u6A19\u3082)\n\nusing mint = ModInt998244353;\n\
    \nint main() {\n    mt19937_64 rng(23);\n    const int C = 8, OFF = 4;  // \u5EA7\
    \u6A19\u306F [-4, 4)\n    for (int it = 0; it < 200; it++) {\n        int n =\
    \ rng() % 6;\n        auto rect = [&](int &l, int &d, int &r, int &u) {\n    \
    \        l = (int)(rng() % C) - OFF, r = (int)(rng() % C) - OFF, d = (int)(rng()\
    \ % C) - OFF, u = (int)(rng() % C) - OFF;\n            if (l > r) swap(l, r);\n\
    \            if (d > u) swap(d, u);\n            r++, u++;\n        };\n     \
    \   vector<int> L(n), D(n), R(n), U(n);\n        vector<long long> W(n);\n   \
    \     vector<vector<long long>> g(C + 2, vector<long long>(C + 2, 0));\n     \
    \   StaticRectangleAddRectangleSum<int, mint> sr;\n        for (int i = 0; i <\
    \ n; i++) {\n            rect(L[i], D[i], R[i], U[i]);\n            W[i] = rng()\
    \ % 10;\n            for (int x = L[i]; x < R[i]; x++)\n                for (int\
    \ y = D[i]; y < U[i]; y++) g[x + OFF][y + OFF] += W[i];\n            sr.add(L[i],\
    \ D[i], R[i], U[i], W[i]);\n        }\n        // \u9759\u7684: \u52A0\u7B97\u306E\
    \u5F8C\u306B\u9577\u65B9\u5F62\u548C\n        for (int qi = 0; qi < 30; qi++)\
    \ {\n            int l, d, r, u;\n            rect(l, d, r, u);\n            long\
    \ long s = 0;\n            for (int x = l; x < r; x++)\n                for (int\
    \ y = d; y < u; y++) s += g[x + OFF][y + OFF];\n            assert(sr.sum(l, d,\
    \ r, u) == mint(s));\n        }\n        // \u548C\u96C6\u5408\u306E\u9762\u7A4D\
    \n        {\n            vector<long long> l(n), d(n), r(n), u(n);\n         \
    \   long long area = 0;\n            vector<vector<int>> cov(C + 2, vector<int>(C\
    \ + 2, 0));\n            for (int i = 0; i < n; i++) {\n                l[i] =\
    \ L[i], d[i] = D[i], r[i] = R[i], u[i] = U[i];\n                for (int x = L[i];\
    \ x < R[i]; x++)\n                    for (int y = D[i]; y < U[i]; y++) cov[x\
    \ + OFF][y + OFF] = 1;\n            }\n            for (auto &row : cov) for (int\
    \ c : row) area += c;\n            assert(area_of_union_of_rectangles(l, d, r,\
    \ u) == area);\n        }\n        // \u9577\u65B9\u5F62\u52A0\u7B97\u30FB\u4E00\
    \u70B9\u53D6\u5F97\n        RectangleAddPointGet<int, long long> rp(L, D, R, U,\
    \ W);\n        RectangleAddPointGet<int, long long> rp_empty;\n        vector<vector<long\
    \ long>> g2(C + 2, vector<long long>(C + 2, 0));\n        for (int step = 0; step\
    \ < 100; step++) {\n            if (rng() % 2) {\n                int l, d, r,\
    \ u;\n                rect(l, d, r, u);\n                long long w = rng() %\
    \ 10;\n                rp.add(l, d, r, u, w), rp_empty.add(l, d, r, u, w);\n \
    \               for (int x = l; x < r; x++)\n                    for (int y =\
    \ d; y < u; y++) g[x + OFF][y + OFF] += w, g2[x + OFF][y + OFF] += w;\n      \
    \      }\n            int x = (int)(rng() % (C + 1)) - OFF, y = (int)(rng() %\
    \ (C + 1)) - OFF;\n            assert(rp.get(x, y) == g[x + OFF][y + OFF]);\n\
    \            assert(rp_empty.get(x, y) == g2[x + OFF][y + OFF]);\n        }\n\
    \    }\n    long long a_, b_;\n    fin >> a_ >> b_;\n    fout << a_ + b_ << '\\\
    n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../io/fastio.hpp\"\
    \n#include \"../../math/modint.hpp\"\n#include \"../../data_structure/rectangle_add_point_get.hpp\"\
    \n#include \"../../data_structure/static_rectangle_add_rectangle_sum.hpp\"\n#include\
    \ \"../../data_structure/area_of_union_of_rectangles.hpp\"\n\n// RectangleAddPointGet\
    \ / StaticRectangleAddRectangleSum / area_of_union_of_rectangles \u3092\n// \u5C0F\
    \u3055\u3044\u683C\u5B50\u306E\u611A\u76F4\u3068\u7167\u5408\u3059\u308B (\u8CA0\
    \u306E\u5EA7\u6A19\u3082)\n\nusing mint = ModInt998244353;\n\nint main() {\n \
    \   mt19937_64 rng(23);\n    const int C = 8, OFF = 4;  // \u5EA7\u6A19\u306F\
    \ [-4, 4)\n    for (int it = 0; it < 200; it++) {\n        int n = rng() % 6;\n\
    \        auto rect = [&](int &l, int &d, int &r, int &u) {\n            l = (int)(rng()\
    \ % C) - OFF, r = (int)(rng() % C) - OFF, d = (int)(rng() % C) - OFF, u = (int)(rng()\
    \ % C) - OFF;\n            if (l > r) swap(l, r);\n            if (d > u) swap(d,\
    \ u);\n            r++, u++;\n        };\n        vector<int> L(n), D(n), R(n),\
    \ U(n);\n        vector<long long> W(n);\n        vector<vector<long long>> g(C\
    \ + 2, vector<long long>(C + 2, 0));\n        StaticRectangleAddRectangleSum<int,\
    \ mint> sr;\n        for (int i = 0; i < n; i++) {\n            rect(L[i], D[i],\
    \ R[i], U[i]);\n            W[i] = rng() % 10;\n            for (int x = L[i];\
    \ x < R[i]; x++)\n                for (int y = D[i]; y < U[i]; y++) g[x + OFF][y\
    \ + OFF] += W[i];\n            sr.add(L[i], D[i], R[i], U[i], W[i]);\n       \
    \ }\n        // \u9759\u7684: \u52A0\u7B97\u306E\u5F8C\u306B\u9577\u65B9\u5F62\
    \u548C\n        for (int qi = 0; qi < 30; qi++) {\n            int l, d, r, u;\n\
    \            rect(l, d, r, u);\n            long long s = 0;\n            for\
    \ (int x = l; x < r; x++)\n                for (int y = d; y < u; y++) s += g[x\
    \ + OFF][y + OFF];\n            assert(sr.sum(l, d, r, u) == mint(s));\n     \
    \   }\n        // \u548C\u96C6\u5408\u306E\u9762\u7A4D\n        {\n          \
    \  vector<long long> l(n), d(n), r(n), u(n);\n            long long area = 0;\n\
    \            vector<vector<int>> cov(C + 2, vector<int>(C + 2, 0));\n        \
    \    for (int i = 0; i < n; i++) {\n                l[i] = L[i], d[i] = D[i],\
    \ r[i] = R[i], u[i] = U[i];\n                for (int x = L[i]; x < R[i]; x++)\n\
    \                    for (int y = D[i]; y < U[i]; y++) cov[x + OFF][y + OFF] =\
    \ 1;\n            }\n            for (auto &row : cov) for (int c : row) area\
    \ += c;\n            assert(area_of_union_of_rectangles(l, d, r, u) == area);\n\
    \        }\n        // \u9577\u65B9\u5F62\u52A0\u7B97\u30FB\u4E00\u70B9\u53D6\u5F97\
    \n        RectangleAddPointGet<int, long long> rp(L, D, R, U, W);\n        RectangleAddPointGet<int,\
    \ long long> rp_empty;\n        vector<vector<long long>> g2(C + 2, vector<long\
    \ long>(C + 2, 0));\n        for (int step = 0; step < 100; step++) {\n      \
    \      if (rng() % 2) {\n                int l, d, r, u;\n                rect(l,\
    \ d, r, u);\n                long long w = rng() % 10;\n                rp.add(l,\
    \ d, r, u, w), rp_empty.add(l, d, r, u, w);\n                for (int x = l; x\
    \ < r; x++)\n                    for (int y = d; y < u; y++) g[x + OFF][y + OFF]\
    \ += w, g2[x + OFF][y + OFF] += w;\n            }\n            int x = (int)(rng()\
    \ % (C + 1)) - OFF, y = (int)(rng() % (C + 1)) - OFF;\n            assert(rp.get(x,\
    \ y) == g[x + OFF][y + OFF]);\n            assert(rp_empty.get(x, y) == g2[x +\
    \ OFF][y + OFF]);\n        }\n    }\n    long long a_, b_;\n    fin >> a_ >> b_;\n\
    \    fout << a_ + b_ << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - io/fastio.hpp
  - template.hpp
  - math/modint.hpp
  - template.hpp
  - data_structure/rectangle_add_point_get.hpp
  - template.hpp
  - data_structure/static_rectangle_sum.hpp
  - data_structure/static_rectangle_add_rectangle_sum.hpp
  - data_structure/area_of_union_of_rectangles.hpp
  isVerificationFile: true
  path: test/unittest/rectangle_add.test.cpp
  requiredBy: []
  timestamp: '2026-10-15 00:08:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/rectangle_add.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/rectangle_add.test.cpp
- /verify/test/unittest/rectangle_add.test.cpp.html
title: test/unittest/rectangle_add.test.cpp
---
