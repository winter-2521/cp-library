---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/potentialized_unionfind.hpp
    title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union-Find (\u975E\u53EF\
      \u63DB\u7FA4\u5BFE\u5FDC)"
  - icon: ':question:'
    path: io/fastio.hpp
    title: "\u9AD8\u901F\u5165\u51FA\u529B (Fast I/O)"
  - icon: ':question:'
    path: math/modint.hpp
    title: "ModInt (\u6CD5\u304C\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u5B9A\u6570\u306E\
      \ modint)"
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group
  bundledCode: "#line 1 \"test/unionfind_with_potential_non_commutative_group.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group\"\
    \n#line 1 \"template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n#if\
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
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 3 \"math/modint.hpp\"\
    \n\n// https://github.com/winter-2521/cp-library\n\n// \u6CD5 MOD \u304C \u30B3\
    \u30F3\u30D1\u30A4\u30EB\u6642\u5B9A\u6570\u306E modint\n// MOD < 2^31 \u3067\u3042\
    \u308B\u3053\u3068 (\u7D20\u6570\u3067\u306A\u304F\u3066\u3082\u3088\u3044\uFF0E\
    \u305F\u3060\u3057 inv() \u306F MOD \u3068\u4E92\u3044\u306B\u7D20\u306A\u5024\
    \u306B\u5BFE\u3057\u3066\u306E\u307F\u6709\u52B9)\n// \u30A4\u30F3\u30BF\u30FC\
    \u30D5\u30A7\u30FC\u30B9\u306F ACL (atcoder::static_modint) \u3068\u63C3\u3048\
    \u3066\u3042\u308B\uFF0E\n// \u3053\u306E\u30E9\u30A4\u30D6\u30E9\u30EA\u306E\u4ED6\
    \u306E\u30D5\u30A1\u30A4\u30EB (fastio \u306A\u3069) \u306F ACL \u306E modint\
    \ \u3067\u3082\u305D\u306E\u307E\u307E\u52D5\u304F\ntemplate <uint32_t MOD>\n\
    struct ModInt {\n    static_assert(1 <= MOD && MOD < (1u << 31), \"MOD must be\
    \ in [1, 2^31)\");\n    using mint = ModInt;\n    uint32_t v;\n\n    static constexpr\
    \ int mod() { return MOD; }\n\n    constexpr ModInt() : v(0) {}\n\n    template\
    \ <class T, enable_if_t<is_integral_v<T>, nullptr_t> = nullptr>\n    constexpr\
    \ ModInt(T x) : v(0) {\n        if constexpr (is_signed_v<T>) {\n            long\
    \ long y = (long long)(x % (long long)MOD);\n            if (y < 0) y += MOD;\n\
    \            v = uint32_t(y);\n        } else {\n            v = uint32_t(x %\
    \ MOD);\n        }\n    }\n\n    // 0 <= x < MOD \u304C\u5206\u304B\u3063\u3066\
    \u3044\u308B\u3068\u304D\u306B\u5270\u4F59\u3092\u53D6\u3089\u305A\u306B\u4F5C\
    \u308B\n    static constexpr mint raw(int x) {\n        mint r;\n        r.v =\
    \ x;\n        return r;\n    }\n\n    // ACL (\u73FE\u884C\u7248) \u3068\u540C\
    \u3058\u304F int \u3067\u8FD4\u3059\n    constexpr int val() const { return int(v);\
    \ }\n\n    constexpr mint &operator+=(const mint &r) {\n        v += r.v;\n  \
    \      if (v >= MOD) v -= MOD;\n        return *this;\n    }\n    constexpr mint\
    \ &operator-=(const mint &r) {\n        v += MOD - r.v;\n        if (v >= MOD)\
    \ v -= MOD;\n        return *this;\n    }\n    constexpr mint &operator*=(const\
    \ mint &r) {\n        // MOD \u304C\u5B9A\u6570\u306A\u306E\u3067 % \u306F\u4E57\
    \u7B97\u3068\u30B7\u30D5\u30C8\u306B\u6700\u9069\u5316\u3055\u308C\u308B\n   \
    \     v = uint32_t((uint64_t)v * r.v % MOD);\n        return *this;\n    }\n \
    \   constexpr mint &operator/=(const mint &r) { return *this *= r.inv(); }\n\n\
    \    constexpr mint operator+() const { return *this; }\n    constexpr mint operator-()\
    \ const { return raw(v == 0 ? 0 : MOD - v); }\n\n    constexpr mint &operator++()\
    \ { return *this += raw(1); }\n    constexpr mint &operator--() { return *this\
    \ -= raw(1); }\n    constexpr mint operator++(int) { mint r = *this; ++*this;\
    \ return r; }\n    constexpr mint operator--(int) { mint r = *this; --*this; return\
    \ r; }\n\n    friend constexpr mint operator+(mint l, const mint &r) { return\
    \ l += r; }\n    friend constexpr mint operator-(mint l, const mint &r) { return\
    \ l -= r; }\n    friend constexpr mint operator*(mint l, const mint &r) { return\
    \ l *= r; }\n    friend constexpr mint operator/(mint l, const mint &r) { return\
    \ l /= r; }\n    friend constexpr bool operator==(const mint &l, const mint &r)\
    \ { return l.v == r.v; }\n    friend constexpr bool operator!=(const mint &l,\
    \ const mint &r) { return l.v != r.v; }\n\n    // this^n (n < 0 \u306A\u3089\u9006\
    \u5143\u306E -n \u4E57)\n    constexpr mint pow(long long n) const {\n       \
    \ mint x = n >= 0 ? *this : inv(), r = raw(1 % MOD);\n        unsigned long long\
    \ e = n >= 0 ? (unsigned long long)n : 0ULL - (unsigned long long)n;\n       \
    \ while (e) {\n            if (e & 1) r *= x;\n            x *= x;\n         \
    \   e >>= 1;\n        }\n        return r;\n    }\n\n    // \u62E1\u5F35\u30E6\
    \u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\u306B\u3088\u308B\u9006\
    \u5143 (MOD \u304C\u7D20\u6570\u3067\u306A\u304F\u3066\u3082 gcd(v, MOD) = 1 \u306A\
    \u3089\u6B63\u3057\u3044)\n    constexpr mint inv() const {\n        long long\
    \ a = v, b = MOD, x = 1, y = 0;\n        while (b) {\n            long long t\
    \ = a / b;\n            a -= t * b, swap(a, b);\n            x -= t * y, swap(x,\
    \ y);\n        }\n        assert(a == 1);\n        return mint(x);\n    }\n\n\
    \    friend ostream &operator<<(ostream &os, const mint &x) { return os << x.v;\
    \ }\n    friend istream &operator>>(istream &is, mint &x) {\n        long long\
    \ t;\n        is >> t;\n        x = mint(t);\n        return is;\n    }\n};\n\n\
    using ModInt998244353 = ModInt<998244353>;\nusing ModInt1000000007 = ModInt<1000000007>;\n\
    #line 2 \"template.hpp\"\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
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
    \ 3 \"data_structure/potentialized_unionfind.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union-Find\n// \u5404\u8981\
    \u7D20 u \u306B\u7FA4 G \u306E\u5143 a_u \u3092\u6301\u305F\u305B\uFF0C\u300C\
    a_u = a_v w\u300D\u3068\u3044\u3046\u95A2\u4FC2\u3092\u8FFD\u52A0\u30FB\u77DB\u76FE\
    \u5224\u5B9A\u3057\uFF0Ca_v^{-1} a_u \u3092\u53D6\u5F97\u3059\u308B\n// G \u306F\
    \u975E\u53EF\u63DB\u7FA4\u3067\u3082\u3088\u3044\uFF0E\u52A0\u6CD5\u7FA4\u306A\
    \u3089\u300Ca_u - a_v = w\u300D\u3068\u3044\u3046\u610F\u5473\u306B\u306A\u308B\
    \ (Library Checker \u3068\u540C\u3058\u5411\u304D)\n//\n// G \u306B\u306F\u6B21\
    \u3092\u5B9A\u7FA9\u3059\u308B:\n//   using T = \u7FA4\u306E\u5143\u306E\u578B\
    ;\n//   static T op(const T &a, const T &b);  // \u7FA4\u6F14\u7B97 a * b\n//\
    \   static T inv(const T &a);             // \u9006\u5143\n//   static T e();\
    \                         // \u5358\u4F4D\u5143\n// T \u306F == \u3067\u6BD4\u8F03\
    \u3067\u304D\u308B\u3053\u3068\ntemplate <class G>\nstruct PotentializedUnionFind\
    \ {\n    using T = typename G::T;\n    // \u6839\u306A\u3089 -(\u96C6\u5408\u306E\
    \u30B5\u30A4\u30BA)\uFF0C\u305D\u3046\u3067\u306A\u3051\u308C\u3070\u89AA\n  \
    \  vector<int> par;\n    // pot[x] = a_{par[x]}^{-1} a_x  (\u6839\u306A\u3089\u5358\
    \u4F4D\u5143)\n    vector<T> pot;\n\n    PotentializedUnionFind(int n = 0) : par(n,\
    \ -1), pot(n, G::e()) {}\n\n    // \u6839\u3092\u8FD4\u3059\uFF0E\u7D4C\u8DEF\u5727\
    \u7E2E\u306E\u3064\u3044\u3067\u306B pot[x] \u3092\u6839\u304B\u3089\u306E\u5024\
    \u306B\u66F4\u65B0\u3059\u308B\n    int leader(int x) {\n        if (par[x] <\
    \ 0) return x;\n        int p = par[x];\n        int r = leader(p);\n        //\
    \ pot[p] \u306F a_r^{-1} a_p \u306B\u306A\u3063\u3066\u3044\u308B\n        if\
    \ (p != r) pot[x] = G::op(pot[p], pot[x]);\n        return par[x] = r;\n    }\n\
    \n    bool same(int x, int y) { return leader(x) == leader(y); }\n\n    int size(int\
    \ x) { return -par[leader(x)]; }\n\n    // a_r^{-1} a_x  (r \u306F x \u306E\u5C5E\
    \u3059\u308B\u96C6\u5408\u306E\u6839)\n    T potential(int x) {\n        leader(x);\n\
    \        return pot[x];\n    }\n\n    // a_v^{-1} a_u (\u52A0\u6CD5\u7FA4\u306A\
    \u3089 a_u - a_v)\uFF0E\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\
    \u3053\u3068\n    T diff(int u, int v) {\n        assert(same(u, v));\n      \
    \  return G::op(G::inv(potential(v)), potential(u));\n    }\n\n    // a_u = a_v\
    \ w (\u52A0\u6CD5\u7FA4\u306A\u3089 a_u - a_v = w) \u3068\u3044\u3046\u95A2\u4FC2\
    \u3092\u8FFD\u52A0\u3059\u308B\n    // \u3053\u308C\u307E\u3067\u306E\u95A2\u4FC2\
    \u3068\u77DB\u76FE\u3059\u308B\u306A\u3089\u4F55\u3082\u305B\u305A false\uFF0C\
    \u77DB\u76FE\u3057\u306A\u3051\u308C\u3070 true (\u65E2\u306B\u5206\u304B\u3063\
    \u3066\u3044\u305F\u95A2\u4FC2\u3067\u3082 true)\n    bool merge(int u, int v,\
    \ T w) {\n        // \u4EE5\u4E0B\u3067\u306F x = v, y = u \u3068\u3057\u3066\
    \ a_x^{-1} a_y = w \u3092\u6271\u3046\n        int x = v, y = u;\n        int\
    \ rx = leader(x), ry = leader(y);\n        const T &px = pot[x], &py = pot[y];\n\
    \        if (rx == ry) return G::op(G::inv(px), py) == w;\n        // a_x = a_rx\
    \ px, a_y = a_ry py, a_y = a_x w \u3088\u308A a_rx^{-1} a_ry = px w py^{-1}\n\
    \        T d = G::op(G::op(px, w), G::inv(py));\n        if (par[rx] > par[ry])\
    \ {\n            // rx \u306E\u65B9\u304C\u5C0F\u3055\u3044\u306E\u3067 ry \u306E\
    \u4E0B\u306B\u3064\u3051\u308B\n            par[ry] += par[rx];\n            par[rx]\
    \ = ry;\n            pot[rx] = G::inv(d);\n        } else {\n            par[rx]\
    \ += par[ry];\n            par[ry] = rx;\n            pot[ry] = d;\n        }\n\
    \        return true;\n    }\n\n    // \u96C6\u5408\u3054\u3068\u306B\u8981\u7D20\
    \u3092\u5217\u6319\n    vector<vector<int>> groups() {\n        int n = par.size();\n\
    \        vector<vector<int>> res(n);\n        for (int i = 0; i < n; i++) res[leader(i)].push_back(i);\n\
    \        res.erase(remove_if(res.begin(), res.end(), [](const vector<int> &v)\
    \ { return v.empty(); }), res.end());\n        return res;\n    }\n};\n\n// \u52A0\
    \u6CD5\u7FA4 (a_u - a_v = w)\ntemplate <class X>\nstruct AdditiveGroup {\n   \
    \ using T = X;\n    static T op(const T &a, const T &b) { return a + b; }\n  \
    \  static T inv(const T &a) { return -a; }\n    static T e() { return T(0); }\n\
    };\n\n// xor \u306E\u7FA4 (a_u xor a_v = w)\uFF0E\u5076\u5947\u306E\u5236\u7D04\
    \u306A\u3069\u306B\u4F7F\u3046\ntemplate <class X>\nstruct XorGroup {\n    using\
    \ T = X;\n    static T op(const T &a, const T &b) { return a ^ b; }\n    static\
    \ T inv(const T &a) { return a; }\n    static T e() { return T(0); }\n};\n#line\
    \ 5 \"test/unionfind_with_potential_non_commutative_group.test.cpp\"\n\nusing\
    \ mint = ModInt998244353;\n\n// \u884C\u5217\u5F0F 1 \u306E 2x2 \u884C\u5217\u306E\
    \u306A\u3059\u7FA4\nstruct SL2 {\n    using T = array<mint, 4>;  // {a00, a01,\
    \ a10, a11}\n    static T op(const T &a, const T &b) {\n        return {a[0] *\
    \ b[0] + a[1] * b[2], a[0] * b[1] + a[1] * b[3], a[2] * b[0] + a[3] * b[2], a[2]\
    \ * b[1] + a[3] * b[3]};\n    }\n    static T inv(const T &a) { return {a[3],\
    \ -a[1], -a[2], a[0]}; }\n    static T e() { return {1, 0, 0, 1}; }\n};\n\nint\
    \ main() {\n    int n, q;\n    fin >> n >> q;\n    PotentializedUnionFind<SL2>\
    \ uf(n);\n    while (q--) {\n        int t, u, v;\n        fin >> t >> u >> v;\n\
    \        if (t == 0) {\n            SL2::T x;\n            for (auto &c : x) fin\
    \ >> c;\n            fout << uf.merge(u, v, x) << '\\n';\n        } else {\n \
    \           if (uf.same(u, v)) {\n                auto m = uf.diff(u, v);\n  \
    \              fout << m[0] << ' ' << m[1] << ' ' << m[2] << ' ' << m[3] << '\\\
    n';\n            } else {\n                fout << -1 << '\\n';\n            }\n\
    \        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group\"\
    \n#include \"../io/fastio.hpp\"\n#include \"../math/modint.hpp\"\n#include \"\
    ../data_structure/potentialized_unionfind.hpp\"\n\nusing mint = ModInt998244353;\n\
    \n// \u884C\u5217\u5F0F 1 \u306E 2x2 \u884C\u5217\u306E\u306A\u3059\u7FA4\nstruct\
    \ SL2 {\n    using T = array<mint, 4>;  // {a00, a01, a10, a11}\n    static T\
    \ op(const T &a, const T &b) {\n        return {a[0] * b[0] + a[1] * b[2], a[0]\
    \ * b[1] + a[1] * b[3], a[2] * b[0] + a[3] * b[2], a[2] * b[1] + a[3] * b[3]};\n\
    \    }\n    static T inv(const T &a) { return {a[3], -a[1], -a[2], a[0]}; }\n\
    \    static T e() { return {1, 0, 0, 1}; }\n};\n\nint main() {\n    int n, q;\n\
    \    fin >> n >> q;\n    PotentializedUnionFind<SL2> uf(n);\n    while (q--) {\n\
    \        int t, u, v;\n        fin >> t >> u >> v;\n        if (t == 0) {\n  \
    \          SL2::T x;\n            for (auto &c : x) fin >> c;\n            fout\
    \ << uf.merge(u, v, x) << '\\n';\n        } else {\n            if (uf.same(u,\
    \ v)) {\n                auto m = uf.diff(u, v);\n                fout << m[0]\
    \ << ' ' << m[1] << ' ' << m[2] << ' ' << m[3] << '\\n';\n            } else {\n\
    \                fout << -1 << '\\n';\n            }\n        }\n    }\n    return\
    \ 0;\n}\n"
  dependsOn:
  - io/fastio.hpp
  - template.hpp
  - math/modint.hpp
  - template.hpp
  - data_structure/potentialized_unionfind.hpp
  - template.hpp
  isVerificationFile: true
  path: test/unionfind_with_potential_non_commutative_group.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unionfind_with_potential_non_commutative_group.test.cpp
layout: document
redirect_from:
- /verify/test/unionfind_with_potential_non_commutative_group.test.cpp
- /verify/test/unionfind_with_potential_non_commutative_group.test.cpp.html
title: test/unionfind_with_potential_non_commutative_group.test.cpp
---
