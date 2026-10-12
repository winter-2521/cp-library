---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/range_parallel_unionfind.hpp
    title: "\u533A\u9593\u4E26\u5217 Union-Find (Range Parallel Union-Find)"
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
    PROBLEM: https://judge.yosupo.jp/problem/range_parallel_unionfind
    links:
    - https://judge.yosupo.jp/problem/range_parallel_unionfind
  bundledCode: "#line 1 \"test/range_parallel_unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_parallel_unionfind\"\n#line 1 \"template.hpp\"\
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
    \ 3 \"data_structure/range_parallel_unionfind.hpp\"\n\n// \u533A\u9593\u4E26\u5217\
    \ Union-Find\n// \u300Ci = 0, ..., k-1 \u306B\u3064\u3044\u3066 a+i \u3068 b+i\
    \ \u3092\u4F75\u5408\u3059\u308B\u300D\u3092\u9AD8\u901F\u306B\u51E6\u7406\u3059\
    \u308B\n// \u5168\u4F53\u3067 O((n log n + q) \u03B1(n))\n//\n// \u6BB5 j \u306E\
    \ Union-Find \u306F\u300C\u9577\u3055 2^j \u306E\u533A\u9593 [i, i + 2^j)\u300D\
    \u3092\u8981\u7D20 i \u3068\u3057\u3066\u6301\u3061\uFF0C\n// \u6BB5 j \u3067\u533A\
    \u9593 [a, a+2^j) \u3068 [b, b+2^j) \u3092\u4F75\u5408\u3057\u305F\u3089\uFF0C\
    \u6BB5 j-1 \u3067\u524D\u534A\u540C\u58EB\u30FB\u5F8C\u534A\u540C\u58EB\u3092\u4F75\
    \u5408\u3059\u308B\uFF0E\n// \u5404\u6BB5\u3067\u5B9F\u969B\u306B\u4F75\u5408\u304C\
    \u8D77\u304D\u308B\u306E\u306F\u9AD8\u3005 n-1 \u56DE\u306A\u306E\u3067\uFF0C\u4E0B\
    \u306E\u6BB5\u306B\u4F1D\u308F\u308B\u56DE\u6570\u3082\u6291\u3048\u3089\u308C\
    \u308B\nstruct RangeParallelUnionFind {\n    int n, lg;\n    // par[j][i]: \u6BB5\
    \ j \u306E Union-Find (\u6839\u306A\u3089 -(\u30B5\u30A4\u30BA))\n    vector<vector<int>>\
    \ par;\n\n    RangeParallelUnionFind(int n = 0) : n(n) {\n        lg = 1;\n  \
    \      while ((1 << lg) <= n) lg++;\n        par.resize(lg);\n        for (int\
    \ j = 0; j < lg; j++) par[j].assign(std::max(0, n - (1 << j) + 1), -1);\n    }\n\
    \n    static int find(vector<int> &p, int x) {\n        int r = x;\n        while\
    \ (p[r] >= 0) r = p[r];\n        // \u7D4C\u8DEF\u5727\u7E2E\n        while (p[x]\
    \ >= 0 && p[x] != r) {\n            int nx = p[x];\n            p[x] = r;\n  \
    \          x = nx;\n        }\n        return r;\n    }\n\n    // \u4F75\u5408\
    \u3057\u3066 (\u6B8B\u3063\u305F\u6839, \u5438\u53CE\u3055\u308C\u305F\u6839)\
    \ \u3092\u8FD4\u3059\uFF0E\u65E2\u306B\u540C\u3058\u306A\u3089 {-1, -1}\n    static\
    \ pair<int, int> unite(vector<int> &p, int x, int y) {\n        x = find(p, x),\
    \ y = find(p, y);\n        if (x == y) return {-1, -1};\n        if (p[x] > p[y])\
    \ swap(x, y);\n        p[x] += p[y];\n        p[y] = x;\n        return {x, y};\n\
    \    }\n\n    int leader(int x) { return find(par[0], x); }\n    bool same(int\
    \ x, int y) { return leader(x) == leader(y); }\n    int size(int x) { return -par[0][leader(x)];\
    \ }\n\n    // i = 0, ..., k-1 \u306B\u3064\u3044\u3066 a+i \u3068 b+i \u3092\u4F75\
    \u5408\u3059\u308B\n    // \u6BB5 0 \u3067\u5B9F\u969B\u306B\u4F75\u5408\u304C\
    \u8D77\u304D\u308B\u305F\u3073\u306B f(\u6B8B\u3063\u305F\u6839, \u5438\u53CE\u3055\
    \u308C\u305F\u6839) \u3092\u547C\u3076\n    template <class F>\n    void merge(int\
    \ a, int b, int k, F f) {\n        if (k <= 0 || a == b) return;\n        int\
    \ j = 31 - __builtin_clz(k);\n        // \u9577\u3055 2^j \u306E\u533A\u9593 2\
    \ \u3064\u3067 [a, a+k) \u3092\u8986\u3046\n        stk.clear();\n        stk.push_back({j,\
    \ a, b});\n        stk.push_back({j, a + k - (1 << j), b + k - (1 << j)});\n \
    \       while (!stk.empty()) {\n            auto [lv, x, y] = stk.back();\n  \
    \          stk.pop_back();\n            auto [r, c] = unite(par[lv], x, y);\n\
    \            if (r < 0) continue;\n            if (lv == 0) {\n              \
    \  f(r, c);\n            } else {\n                int h = 1 << (lv - 1);\n  \
    \              stk.push_back({lv - 1, x, y});\n                stk.push_back({lv\
    \ - 1, x + h, y + h});\n            }\n        }\n    }\n\n    void merge(int\
    \ a, int b, int k) {\n        merge(a, b, k, [](int, int) {});\n    }\n\n    //\
    \ \u30AF\u30A8\u30EA\u3092\u5148\u8AAD\u307F\u3067\u304D\u308B\u3068\u304D\u306E\
    \u9AD8\u901F\u7248 (\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306F\u4F5C\u3089\u305A\
    \u306B\u4F7F\u3046)\n    // qs[t] = {a, b, k} \u3092 t = 0, 1, ... \u306E\u9806\
    \u306B\u51E6\u7406\u3057\u305F\u3068\u304D\uFF0C\u6BB5 0 \u3067\u5B9F\u969B\u306B\
    \u4F75\u5408\u304C\u8D77\u304D\u308B\u305F\u3073\u306B\n    // f(t, \u6B8B\u3063\
    \u305F\u6839, \u5438\u53CE\u3055\u308C\u305F\u6839) \u3092 t \u306E\u6607\u9806\
    \u306B\u547C\u3076\uFF0E\u8A08\u7B97\u91CF\u306F merge \u3068\u540C\u3058\n  \
    \  //\n    // \u6BB5\u3092\u4E0A\u304B\u3089 1 \u3064\u305A\u3064\u51E6\u7406\u3057\
    \uFF0C\u5404\u6BB5\u306E\u4F75\u5408\u306F\u6642\u523B\u9806\u306B\u884C\u3046\
    \uFF0E\u6BB5 j \u3067\u6210\u529F\u3057\u305F\u4F75\u5408\u3092\u6BB5 j-1 \u306B\
    \u6642\u523B\u3064\u304D\u3067\u6E21\u3059\uFF0E\n    // \u540C\u6642\u306B\u89E6\
    \u308B Union-Find \u304C 1 \u6BB5\u5206\u3060\u3051\u306B\u306A\u308B\u306E\u3067\
    \uFF0C\u30AA\u30F3\u30E9\u30A4\u30F3\u7248\u3088\u308A\u30AD\u30E3\u30C3\u30B7\
    \u30E5\u306B\u4E57\u308A\u3084\u3059\u3044\n    template <class F>\n    static\
    \ void merge_offline(int n, const vector<array<int, 3>> &qs, F f) {\n        int\
    \ q = qs.size();\n        int lg = 1;\n        while ((1 << lg) <= n) lg++;\n\
    \        // \u6BB5\u3054\u3068\u306B\uFF0C\u305D\u306E\u6BB5\u306B\u76F4\u63A5\
    \u5165\u308B\u30AF\u30A8\u30EA (\u9577\u3055 2^j \u306E\u533A\u9593 2 \u3064\u3067\
    \u8986\u3046) \u3092\u6642\u523B\u9806\u306B\u4E26\u3079\u308B\n        vector<int>\
    \ start(lg + 1, 0);\n        for (auto &[a, b, k] : qs) if (k > 0 && a != b) start[31\
    \ - __builtin_clz(k)]++;\n        for (int j = 0; j < lg; j++) start[j + 1] +=\
    \ start[j];\n        vector<int> direct(start[lg]);\n        for (int t = q -\
    \ 1; t >= 0; t--) {\n            auto &[a, b, k] = qs[t];\n            if (k >\
    \ 0 && a != b) direct[--start[31 - __builtin_clz(k)]] = t;\n        }\n      \
    \  struct Item {\n            int t, x, y;\n        };\n        vector<Item> cur,\
    \ nxt;\n        vector<int> p(n);\n        for (int j = lg - 1; j >= 0; j--) {\n\
    \            int m = n - (1 << j) + 1;\n            fill(p.begin(), p.begin()\
    \ + m, -1);\n            nxt.clear();\n            int h = j > 0 ? 1 << (j - 1)\
    \ : 0;\n            auto process = [&](int t, int x, int y) {\n              \
    \  auto [r, c] = unite(p, x, y);\n                if (r < 0) return;\n       \
    \         if (j == 0) {\n                    f(t, r, c);\n                } else\
    \ {\n                    nxt.push_back({t, x, y});\n                    nxt.push_back({t,\
    \ x + h, y + h});\n                }\n            };\n            // \u76F4\u63A5\
    \u306E\u30AF\u30A8\u30EA\u3068\u4E0A\u306E\u6BB5\u304B\u3089\u6765\u305F\u3082\
    \u306E\u3092\u6642\u523B\u9806\u306B\u30DE\u30FC\u30B8\u3057\u306A\u304C\u3089\
    \u51E6\u7406\u3059\u308B\n            size_t ci = 0;\n            for (int di\
    \ = start[j]; di < start[j + 1]; di++) {\n                int t = direct[di];\n\
    \                for (; ci < cur.size() && cur[ci].t < t; ci++) process(cur[ci].t,\
    \ cur[ci].x, cur[ci].y);\n                auto &[a, b, k] = qs[t];\n         \
    \       int w = 1 << j;\n                process(t, a, b);\n                process(t,\
    \ a + k - w, b + k - w);\n            }\n            for (; ci < cur.size(); ci++)\
    \ process(cur[ci].t, cur[ci].x, cur[ci].y);\n            swap(cur, nxt);\n   \
    \     }\n    }\n\n  private:\n    vector<tuple<int, int, int>> stk;\n};\n#line\
    \ 5 \"test/range_parallel_unionfind.test.cpp\"\n\nusing mint = ModInt998244353;\n\
    \n// \u30AF\u30A8\u30EA\u3092\u5148\u8AAD\u307F\u3059\u308B\u9AD8\u901F\u7248\
    \ (\u30AA\u30F3\u30E9\u30A4\u30F3\u7248\u306F range_parallel_unionfind_online.test.cpp)\n\
    int main() {\n    int n, q;\n    fin >> n >> q;\n    vector<mint> sum(n);\n  \
    \  fin >> sum;\n    vector<array<int, 3>> qs(q);\n    for (auto &[a, b, k] : qs)\
    \ fin >> k >> a >> b;\n    // \u6642\u523B t \u306E\u4F75\u5408\u3067\u5897\u3048\
    \u305F\u5206\n    vector<mint> add(q);\n    RangeParallelUnionFind::merge_offline(n,\
    \ qs, [&](int t, int r, int c) {\n        add[t] += sum[r] * sum[c];\n       \
    \ sum[r] += sum[c];\n    });\n    mint ans = 0;\n    for (int t = 0; t < q; t++)\
    \ {\n        ans += add[t];\n        fout << ans << '\\n';\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_parallel_unionfind\"\
    \n#include \"../io/fastio.hpp\"\n#include \"../math/modint.hpp\"\n#include \"\
    ../data_structure/range_parallel_unionfind.hpp\"\n\nusing mint = ModInt998244353;\n\
    \n// \u30AF\u30A8\u30EA\u3092\u5148\u8AAD\u307F\u3059\u308B\u9AD8\u901F\u7248\
    \ (\u30AA\u30F3\u30E9\u30A4\u30F3\u7248\u306F range_parallel_unionfind_online.test.cpp)\n\
    int main() {\n    int n, q;\n    fin >> n >> q;\n    vector<mint> sum(n);\n  \
    \  fin >> sum;\n    vector<array<int, 3>> qs(q);\n    for (auto &[a, b, k] : qs)\
    \ fin >> k >> a >> b;\n    // \u6642\u523B t \u306E\u4F75\u5408\u3067\u5897\u3048\
    \u305F\u5206\n    vector<mint> add(q);\n    RangeParallelUnionFind::merge_offline(n,\
    \ qs, [&](int t, int r, int c) {\n        add[t] += sum[r] * sum[c];\n       \
    \ sum[r] += sum[c];\n    });\n    mint ans = 0;\n    for (int t = 0; t < q; t++)\
    \ {\n        ans += add[t];\n        fout << ans << '\\n';\n    }\n    return\
    \ 0;\n}\n"
  dependsOn:
  - io/fastio.hpp
  - template.hpp
  - math/modint.hpp
  - template.hpp
  - data_structure/range_parallel_unionfind.hpp
  - template.hpp
  isVerificationFile: true
  path: test/range_parallel_unionfind.test.cpp
  requiredBy: []
  timestamp: '2026-10-12 11:00:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/range_parallel_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/range_parallel_unionfind.test.cpp
- /verify/test/range_parallel_unionfind.test.cpp.html
title: test/range_parallel_unionfind.test.cpp
---
