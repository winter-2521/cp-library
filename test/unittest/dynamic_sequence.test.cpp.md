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
    path: data_structure/dynamic_sequence.hpp
    title: "\u5217\u306E\u633F\u5165\u30FB\u524A\u9664\u30FB\u53CD\u8EE2\u30FB\u533A\
      \u9593\u4F5C\u7528 (Dynamic Sequence, Splay \u6728)"
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
  bundledCode: "#line 1 \"test/unittest/dynamic_sequence.test.cpp\"\n#define PROBLEM\
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
    \ 4 \"data_structure/dynamic_sequence.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u5217\u306E\u633F\u5165\u30FB\u524A\u9664\u30FB\u533A\u9593\u53CD\u8EE2\u30FB\
    \u533A\u9593\u4F5C\u7528\u30FB\u533A\u9593\u7A4D (Splay \u6728)\n// AM \u306F\u4F5C\
    \u7528\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (algebra/acted_monoid.hpp \u53C2\u7167\
    )\n// COMMUTATIVE = false \u306A\u3089\u975E\u53EF\u63DB\u306A\u30E2\u30CE\u30A4\
    \u30C9\u3067\u3082\u53CD\u8EE2\u3067\u304D\u308B (\u9006\u9806\u306E\u7A4D\u3082\
    \u6301\u3064\uFF0E\u5C11\u3057\u9045\u3044)\n// \u4E21\u7AEF\u306B\u756A\u5175\
    \u3092\u7F6E\u304D\uFF0C\u533A\u9593 [l, r) \u306F\u300Cl-1 \u756A\u76EE\u3092\
    \u6839\u306B\uFF0Cr \u756A\u76EE\u3092\u6839\u306E\u53F3\u306E\u5B50\u306B splay\
    \ \u3057\u305F\u5F8C\u306E\uFF0C\u305D\u306E\u5DE6\u306E\u5B50\u300D\u3068\u3057\
    \u3066\u53D6\u308A\u51FA\u3059\ntemplate <class AM, bool COMMUTATIVE = true>\n\
    struct DynamicSequence {\n    using S = typename AM::S;\n    using F = typename\
    \ AM::F;\n    // \u9006\u9806\u306E\u7A4D rsum \u306F COMMUTATIVE = false \u306E\
    \u3068\u304D\u3060\u3051\u6301\u3064\n    struct NoRSum {};\n    struct WithRSum\
    \ {\n        S rsum;\n    };\n    struct Node : conditional_t<COMMUTATIVE, NoRSum,\
    \ WithRSum> {\n        int ch[2], p, sz;\n        S val, sum;\n        F lz;\n\
    \        bool has_lz, rev;\n    };\n    vector<Node> d;  // d[0] \u306F\u7A7A\u30CE\
    \u30FC\u30C9\n    int root;\n\n    DynamicSequence(const vector<S> &a = {}) {\n\
    \        int n = a.size();\n        d.reserve(n + 3);\n        d.push_back(make_node(AM::e()));\n\
    \        d[0].sz = 0;\n        vector<int> ids(n + 2);\n        ids[0] = new_node(AM::e());\n\
    \        for (int i = 0; i < n; i++) ids[i + 1] = new_node(a[i]);\n        ids[n\
    \ + 1] = new_node(AM::e());\n        root = build(ids, 0, n + 2, 0);\n    }\n\n\
    \    void reserve(int n) { d.reserve(n + 3); }\n    int size() const { return\
    \ d[root].sz - 2; }\n\n    // i \u756A\u76EE\u306E\u76F4\u524D\u306B x \u3092\u633F\
    \u5165 (i = size() \u306A\u3089\u672B\u5C3E)\n    void insert(int i, const S &x)\
    \ {\n        int t = new_node(x);\n        int r = range(i, i);\n        d[r].ch[0]\
    \ = t, d[t].p = r;\n        update(r), update(root);\n    }\n    void push_back(const\
    \ S &x) { insert(size(), x); }\n    void push_front(const S &x) { insert(0, x);\
    \ }\n\n    // i \u756A\u76EE\u3092\u524A\u9664\n    void erase(int i) {\n    \
    \    int r = range(i, i + 1);\n        d[r].ch[0] = 0;\n        update(r), update(root);\n\
    \    }\n\n    S get(int i) {\n        int t = kth(i + 1);\n        splay(t, 0);\n\
    \        return d[t].val;\n    }\n\n    void set(int i, const S &x) {\n      \
    \  int t = kth(i + 1);\n        splay(t, 0);\n        d[t].val = x;\n        update(t);\n\
    \    }\n\n    // op(a[l], ..., a[r-1])\uFF0El == r \u306A\u3089 e()\n    S prod(int\
    \ l, int r) {\n        if (l == r) return AM::e();\n        return d[d[range(l,\
    \ r)].ch[0]].sum;\n    }\n    S all_prod() { return prod(0, size()); }\n\n   \
    \ // i in [l, r) \u306B\u3064\u3044\u3066 a[i] = f(a[i])\n    void apply(int l,\
    \ int r, const F &f) {\n        if (l == r) return;\n        int rr = range(l,\
    \ r);\n        all_apply(d[rr].ch[0], f);\n        update(rr), update(root);\n\
    \    }\n\n    // a[l], ..., a[r-1] \u3092\u53CD\u8EE2\n    void reverse(int l,\
    \ int r) {\n        if (r - l <= 1) return;\n        int rr = range(l, r);\n \
    \       toggle(d[rr].ch[0]);\n        update(rr), update(root);\n    }\n\n   \
    \ // \u5217\u5168\u4F53 (\u30C7\u30D0\u30C3\u30B0\u7528)\uFF0EO(n)\n    vector<S>\
    \ to_vector() {\n        vector<S> res;\n        res.reserve(size());\n      \
    \  dfs(root, res);\n        return vector<S>(res.begin() + 1, res.end() - 1);\n\
    \    }\n\n  private:\n    Node make_node(const S &x) {\n        Node t;\n    \
    \    t.ch[0] = t.ch[1] = t.p = 0, t.sz = 1;\n        t.val = t.sum = x;\n    \
    \    if constexpr (!COMMUTATIVE) t.rsum = x;\n        t.lz = AM::id(), t.has_lz\
    \ = t.rev = false;\n        return t;\n    }\n    int new_node(const S &x) {\n\
    \        d.push_back(make_node(x));\n        return d.size() - 1;\n    }\n\n \
    \   int build(const vector<int> &ids, int l, int r, int p) {\n        if (l ==\
    \ r) return 0;\n        int m = (l + r) >> 1, t = ids[m];\n        d[t].p = p;\n\
    \        d[t].ch[0] = build(ids, l, m, t);\n        d[t].ch[1] = build(ids, m\
    \ + 1, r, t);\n        update(t);\n        return t;\n    }\n\n    void update(int\
    \ t) {\n        Node &x = d[t];\n        const Node &a = d[x.ch[0]], &b = d[x.ch[1]];\n\
    \        x.sz = a.sz + b.sz + 1;\n        x.sum = AM::op(AM::op(a.sum, x.val),\
    \ b.sum);\n        if constexpr (!COMMUTATIVE) x.rsum = AM::op(AM::op(b.rsum,\
    \ x.val), a.rsum);\n    }\n\n    void all_apply(int t, const F &f) {\n       \
    \ Node &x = d[t];\n        x.val = AM::mapping(f, x.val);\n        x.sum = AM::mapping(f,\
    \ x.sum);\n        if constexpr (!COMMUTATIVE) x.rsum = AM::mapping(f, x.rsum);\n\
    \        x.lz = x.has_lz ? AM::composition(f, x.lz) : f;\n        x.has_lz = true;\n\
    \    }\n\n    void toggle(int t) {\n        Node &x = d[t];\n        swap(x.ch[0],\
    \ x.ch[1]);\n        if constexpr (!COMMUTATIVE) swap(x.sum, x.rsum);\n      \
    \  x.rev ^= 1;\n    }\n\n    void push(int t) {\n        Node &x = d[t];\n   \
    \     if (x.rev) {\n            if (x.ch[0]) toggle(x.ch[0]);\n            if\
    \ (x.ch[1]) toggle(x.ch[1]);\n            x.rev = false;\n        }\n        if\
    \ (x.has_lz) {\n            if (x.ch[0]) all_apply(x.ch[0], x.lz);\n         \
    \   if (x.ch[1]) all_apply(x.ch[1], x.lz);\n            x.has_lz = false;\n  \
    \      }\n    }\n\n    // x \u3092\u89AA\u306E\u4F4D\u7F6E\u306B\u56DE\u8EE2 (\u89AA\
    \u306E update \u3060\u3051\u3059\u308B)\n    void rotate(int x) {\n        int\
    \ y = d[x].p, z = d[y].p;\n        int c = d[y].ch[1] == x;\n        int b = d[x].ch[c\
    \ ^ 1];\n        d[y].ch[c] = b;\n        if (b) d[b].p = y;\n        d[x].ch[c\
    \ ^ 1] = y, d[y].p = x;\n        d[x].p = z;\n        if (z) d[z].ch[d[z].ch[1]\
    \ == y] = x;\n        update(y);\n    }\n\n    // x \u3092 goal \u306E\u5B50\u306B\
    \u306A\u308B\u307E\u3067 splay (goal = 0 \u306A\u3089\u6839)\uFF0Ex \u306E\u7956\
    \u5148\u306F push \u6E08\u307F\u3067\u3042\u308B\u3053\u3068\n    void splay(int\
    \ x, int goal) {\n        while (d[x].p != goal) {\n            int y = d[x].p,\
    \ z = d[y].p;\n            if (z != goal) rotate((d[y].ch[1] == x) == (d[z].ch[1]\
    \ == y) ? y : x);\n            rotate(x);\n        }\n        update(x);\n   \
    \     if (!goal) root = x;\n    }\n\n    // \u756A\u5175\u8FBC\u307F\u3067 k \u756A\
    \u76EE\u306E\u30CE\u30FC\u30C9 (\u7D4C\u8DEF\u3092 push \u3059\u308B)\n    int\
    \ kth(int k) {\n        int t = root;\n        while (true) {\n            push(t);\n\
    \            int ls = d[d[t].ch[0]].sz;\n            if (k < ls) t = d[t].ch[0];\n\
    \            else if (k == ls) return t;\n            else k -= ls + 1, t = d[t].ch[1];\n\
    \        }\n    }\n\n    // [l, r) \u304C\u300C\u6839\u306E\u53F3\u306E\u5B50\u306E\
    \u5DE6\u306E\u5B50\u300D\u306E\u90E8\u5206\u6728\u306B\u306A\u308B\u3088\u3046\
    \u306B\u3057\u3066\uFF0C\u6839\u306E\u53F3\u306E\u5B50\u3092\u8FD4\u3059\n   \
    \ int range(int l, int r) {\n        int a = kth(l);\n        splay(a, 0);\n \
    \       int b = kth(r + 1);\n        splay(b, a);\n        return b;\n    }\n\n\
    \    void dfs(int t, vector<S> &res) {\n        if (!t) return;\n        push(t);\n\
    \        dfs(d[t].ch[0], res);\n        res.push_back(d[t].val);\n        dfs(d[t].ch[1],\
    \ res);\n    }\n};\n#line 5 \"test/unittest/dynamic_sequence.test.cpp\"\n\n//\
    \ DynamicSequence \u3092\u611A\u76F4\u3068\u7167\u5408\u3059\u308B\n// \u975E\u53EF\
    \u63DB: \u5024\u306F 1 \u6B21\u95A2\u6570\uFF0C\u4F5C\u7528\u306A\u3057 (ActedNone)\
    \ \u3067\u53CD\u8EE2\u3068\u7A4D\u3092\u78BA\u8A8D\n// \u53EF\u63DB: ActedAffineSum\
    \ \u3067\u633F\u5165\u30FB\u524A\u9664\u30FB\u53CD\u8EE2\u30FB\u533A\u9593\u4F5C\
    \u7528\u30FB\u533A\u9593\u548C\u3092\u78BA\u8A8D\n\nusing mint = ModInt998244353;\n\
    using F = Affine<mint>;\nusing AM = ActedAffineSum<mint>;\n\nint main() {\n  \
    \  mt19937_64 rng(9);\n    for (int it = 0; it < 30; it++) {\n        int n =\
    \ rng() % 20;\n        vector<F> a(n);\n        for (auto &f : a) f = F(rng()\
    \ % 5 + 1, rng() % 5);\n        DynamicSequence<ActedNone<MonoidAffine<mint>>,\
    \ false> seq(a);\n        vector<mint> b(n);\n        vector<AM::S> bs(n);\n \
    \       for (int i = 0; i < n; i++) b[i] = rng() % 10, bs[i] = AM::make(b[i]);\n\
    \        DynamicSequence<AM> sb(bs);\n        for (int step = 0; step < 2000;\
    \ step++) {\n            int t = rng() % 7;\n            int m = a.size();\n \
    \           if (t == 0 || m == 0) {\n                int i = rng() % (m + 1);\n\
    \                F f(rng() % 5 + 1, rng() % 5);\n                a.insert(a.begin()\
    \ + i, f), seq.insert(i, f);\n                mint x = rng() % 10;\n         \
    \       b.insert(b.begin() + i, x), sb.insert(i, AM::make(x));\n            }\
    \ else if (t == 1) {\n                int i = rng() % m;\n                a.erase(a.begin()\
    \ + i), seq.erase(i);\n                b.erase(b.begin() + i), sb.erase(i);\n\
    \            } else {\n                int l = rng() % (m + 1), r = rng() % (m\
    \ + 1);\n                if (l > r) swap(l, r);\n                if (t == 2) {\n\
    \                    reverse(a.begin() + l, a.begin() + r), seq.reverse(l, r);\n\
    \                    reverse(b.begin() + l, b.begin() + r), sb.reverse(l, r);\n\
    \                } else if (t == 3) {\n                    F f(rng() % 5, rng()\
    \ % 5);\n                    for (int i = l; i < r; i++) b[i] = f(b[i]);\n   \
    \                 sb.apply(l, r, f);\n                } else if (t == 4) {\n \
    \                   F res;\n                    for (int i = l; i < r; i++) res\
    \ = res.then(a[i]);\n                    assert(seq.prod(l, r) == res);\n    \
    \                mint s = 0;\n                    for (int i = l; i < r; i++)\
    \ s += b[i];\n                    assert(sb.prod(l, r).sum == s && sb.prod(l,\
    \ r).len == mint(r - l));\n                } else if (t == 5 && m > 0) {\n   \
    \                 int i = rng() % m;\n                    assert(seq.get(i) ==\
    \ a[i] && sb.get(i).sum == b[i]);\n                    F f(rng() % 5 + 1, rng()\
    \ % 5);\n                    a[i] = f, seq.set(i, f);\n                } else\
    \ {\n                    if (rng() % 2) {\n                        F f(rng() %\
    \ 5 + 1, rng() % 5);\n                        a.push_back(f), seq.push_back(f);\n\
    \                        b.push_back(0), sb.push_back(AM::make(0));\n        \
    \            } else {\n                        F f(rng() % 5 + 1, rng() % 5);\n\
    \                        a.insert(a.begin(), f), seq.push_front(f);\n        \
    \                b.insert(b.begin(), 0), sb.push_front(AM::make(0));\n       \
    \             }\n                }\n            }\n            assert(seq.size()\
    \ == (int)a.size() && sb.size() == (int)b.size());\n        }\n        assert(seq.to_vector()\
    \ == a);\n        F all;\n        for (auto &f : a) all = all.then(f);\n     \
    \   assert(seq.all_prod() == all);\n    }\n    long long a_, b_;\n    fin >> a_\
    \ >> b_;\n    fout << a_ + b_ << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../io/fastio.hpp\"\
    \n#include \"../../math/modint.hpp\"\n#include \"../../data_structure/dynamic_sequence.hpp\"\
    \n\n// DynamicSequence \u3092\u611A\u76F4\u3068\u7167\u5408\u3059\u308B\n// \u975E\
    \u53EF\u63DB: \u5024\u306F 1 \u6B21\u95A2\u6570\uFF0C\u4F5C\u7528\u306A\u3057\
    \ (ActedNone) \u3067\u53CD\u8EE2\u3068\u7A4D\u3092\u78BA\u8A8D\n// \u53EF\u63DB\
    : ActedAffineSum \u3067\u633F\u5165\u30FB\u524A\u9664\u30FB\u53CD\u8EE2\u30FB\u533A\
    \u9593\u4F5C\u7528\u30FB\u533A\u9593\u548C\u3092\u78BA\u8A8D\n\nusing mint = ModInt998244353;\n\
    using F = Affine<mint>;\nusing AM = ActedAffineSum<mint>;\n\nint main() {\n  \
    \  mt19937_64 rng(9);\n    for (int it = 0; it < 30; it++) {\n        int n =\
    \ rng() % 20;\n        vector<F> a(n);\n        for (auto &f : a) f = F(rng()\
    \ % 5 + 1, rng() % 5);\n        DynamicSequence<ActedNone<MonoidAffine<mint>>,\
    \ false> seq(a);\n        vector<mint> b(n);\n        vector<AM::S> bs(n);\n \
    \       for (int i = 0; i < n; i++) b[i] = rng() % 10, bs[i] = AM::make(b[i]);\n\
    \        DynamicSequence<AM> sb(bs);\n        for (int step = 0; step < 2000;\
    \ step++) {\n            int t = rng() % 7;\n            int m = a.size();\n \
    \           if (t == 0 || m == 0) {\n                int i = rng() % (m + 1);\n\
    \                F f(rng() % 5 + 1, rng() % 5);\n                a.insert(a.begin()\
    \ + i, f), seq.insert(i, f);\n                mint x = rng() % 10;\n         \
    \       b.insert(b.begin() + i, x), sb.insert(i, AM::make(x));\n            }\
    \ else if (t == 1) {\n                int i = rng() % m;\n                a.erase(a.begin()\
    \ + i), seq.erase(i);\n                b.erase(b.begin() + i), sb.erase(i);\n\
    \            } else {\n                int l = rng() % (m + 1), r = rng() % (m\
    \ + 1);\n                if (l > r) swap(l, r);\n                if (t == 2) {\n\
    \                    reverse(a.begin() + l, a.begin() + r), seq.reverse(l, r);\n\
    \                    reverse(b.begin() + l, b.begin() + r), sb.reverse(l, r);\n\
    \                } else if (t == 3) {\n                    F f(rng() % 5, rng()\
    \ % 5);\n                    for (int i = l; i < r; i++) b[i] = f(b[i]);\n   \
    \                 sb.apply(l, r, f);\n                } else if (t == 4) {\n \
    \                   F res;\n                    for (int i = l; i < r; i++) res\
    \ = res.then(a[i]);\n                    assert(seq.prod(l, r) == res);\n    \
    \                mint s = 0;\n                    for (int i = l; i < r; i++)\
    \ s += b[i];\n                    assert(sb.prod(l, r).sum == s && sb.prod(l,\
    \ r).len == mint(r - l));\n                } else if (t == 5 && m > 0) {\n   \
    \                 int i = rng() % m;\n                    assert(seq.get(i) ==\
    \ a[i] && sb.get(i).sum == b[i]);\n                    F f(rng() % 5 + 1, rng()\
    \ % 5);\n                    a[i] = f, seq.set(i, f);\n                } else\
    \ {\n                    if (rng() % 2) {\n                        F f(rng() %\
    \ 5 + 1, rng() % 5);\n                        a.push_back(f), seq.push_back(f);\n\
    \                        b.push_back(0), sb.push_back(AM::make(0));\n        \
    \            } else {\n                        F f(rng() % 5 + 1, rng() % 5);\n\
    \                        a.insert(a.begin(), f), seq.push_front(f);\n        \
    \                b.insert(b.begin(), 0), sb.push_front(AM::make(0));\n       \
    \             }\n                }\n            }\n            assert(seq.size()\
    \ == (int)a.size() && sb.size() == (int)b.size());\n        }\n        assert(seq.to_vector()\
    \ == a);\n        F all;\n        for (auto &f : a) all = all.then(f);\n     \
    \   assert(seq.all_prod() == all);\n    }\n    long long a_, b_;\n    fin >> a_\
    \ >> b_;\n    fout << a_ + b_ << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - io/fastio.hpp
  - template.hpp
  - math/modint.hpp
  - template.hpp
  - data_structure/dynamic_sequence.hpp
  - template.hpp
  - algebra/acted_monoid.hpp
  - algebra/monoid.hpp
  - template.hpp
  isVerificationFile: true
  path: test/unittest/dynamic_sequence.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unittest/dynamic_sequence.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/dynamic_sequence.test.cpp
- /verify/test/unittest/dynamic_sequence.test.cpp.html
title: test/unittest/dynamic_sequence.test.cpp
---
