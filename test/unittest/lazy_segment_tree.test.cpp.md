---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/acted_monoid.hpp
    title: "\u4F5C\u7528\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (Acted Monoid)"
  - icon: ':question:'
    path: algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9 (Monoid)"
  - icon: ':x:'
    path: data_structure/dynamic_lazy_segment_tree.hpp
    title: "\u52D5\u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dynamic\
      \ Lazy Segment Tree)"
  - icon: ':x:'
    path: data_structure/lazy_segment_tree.hpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Lazy Segment Tree)"
  - icon: ':x:'
    path: data_structure/persistent_lazy_segment_tree.hpp
    title: "\u6C38\u7D9A\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Persistent\
      \ Lazy Segment Tree)"
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
  bundledCode: "#line 1 \"test/unittest/lazy_segment_tree.test.cpp\"\n#define PROBLEM\
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
    \ 4 \"data_structure/lazy_segment_tree.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u4F5C\u7528\
    \u30FB\u533A\u9593\u7A4D)\n// AM \u306F\u4F5C\u7528\u4ED8\u304D\u30E2\u30CE\u30A4\
    \u30C9 (algebra/acted_monoid.hpp \u53C2\u7167\uFF0E\u898F\u7D04\u306F ACL \u306E\
    \ lazy_segtree \u3068\u540C\u3058)\ntemplate <class AM>\nstruct LazySegmentTree\
    \ {\n    using S = typename AM::S;\n    using F = typename AM::F;\n    int n,\
    \ sz, lg;\n    vector<S> d;\n    vector<F> lz;\n\n    LazySegmentTree(int n =\
    \ 0) : LazySegmentTree(vector<S>(n, AM::e())) {}\n\n    LazySegmentTree(const\
    \ vector<S> &a) : n(a.size()) {\n        lg = 0;\n        while ((1 << lg) < n)\
    \ lg++;\n        sz = 1 << lg;\n        d.assign(2 * sz, AM::e());\n        lz.assign(sz,\
    \ AM::id());\n        copy(a.begin(), a.end(), d.begin() + sz);\n        for (int\
    \ i = sz - 1; i >= 1; i--) update(i);\n    }\n\n    int size() const { return\
    \ n; }\n\n    // a[p] = x\n    void set(int p, const S &x) {\n        p += sz;\n\
    \        for (int i = lg; i >= 1; i--) push(p >> i);\n        d[p] = x;\n    \
    \    for (int i = 1; i <= lg; i++) update(p >> i);\n    }\n\n    S get(int p)\
    \ {\n        p += sz;\n        for (int i = lg; i >= 1; i--) push(p >> i);\n \
    \       return d[p];\n    }\n\n    // op(a[l], ..., a[r-1])\uFF0El == r \u306A\
    \u3089 e()\n    S prod(int l, int r) {\n        if (l == r) return AM::e();\n\
    \        l += sz, r += sz;\n        for (int i = lg; i >= 1; i--) {\n        \
    \    if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i)\
    \ != r) push((r - 1) >> i);\n        }\n        S sml = AM::e(), smr = AM::e();\n\
    \        while (l < r) {\n            if (l & 1) sml = AM::op(sml, d[l++]);\n\
    \            if (r & 1) smr = AM::op(d[--r], smr);\n            l >>= 1, r >>=\
    \ 1;\n        }\n        return AM::op(sml, smr);\n    }\n\n    S all_prod() const\
    \ { return d[1]; }\n\n    // a[p] = f(a[p])\n    void apply(int p, const F &f)\
    \ {\n        p += sz;\n        for (int i = lg; i >= 1; i--) push(p >> i);\n \
    \       d[p] = AM::mapping(f, d[p]);\n        for (int i = 1; i <= lg; i++) update(p\
    \ >> i);\n    }\n\n    // i in [l, r) \u306B\u3064\u3044\u3066 a[i] = f(a[i])\n\
    \    void apply(int l, int r, const F &f) {\n        if (l == r) return;\n   \
    \     l += sz, r += sz;\n        for (int i = lg; i >= 1; i--) {\n           \
    \ if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) !=\
    \ r) push((r - 1) >> i);\n        }\n        {\n            int l2 = l, r2 = r;\n\
    \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
    \                if (r & 1) all_apply(--r, f);\n                l >>= 1, r >>=\
    \ 1;\n            }\n            l = l2, r = r2;\n        }\n        for (int\
    \ i = 1; i <= lg; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n\
    \            if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\
    \n    // g(op(a[l], ..., a[r-1])) \u304C true \u3068\u306A\u308B\u6700\u5927\u306E\
    \ r (g(e()) \u306F true \u3067\u3042\u308B\u3053\u3068)\n    template <class G>\n\
    \    int max_right(int l, G g) {\n        if (l == n) return n;\n        l +=\
    \ sz;\n        for (int i = lg; i >= 1; i--) push(l >> i);\n        S sm = AM::e();\n\
    \        do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(AM::op(sm,\
    \ d[l]))) {\n                while (l < sz) {\n                    push(l);\n\
    \                    l = 2 * l;\n                    if (g(AM::op(sm, d[l])))\
    \ sm = AM::op(sm, d[l++]);\n                }\n                return l - sz;\n\
    \            }\n            sm = AM::op(sm, d[l++]);\n        } while ((l & -l)\
    \ != l);\n        return n;\n    }\n\n    // g(op(a[l], ..., a[r-1])) \u304C true\
    \ \u3068\u306A\u308B\u6700\u5C0F\u306E l (g(e()) \u306F true \u3067\u3042\u308B\
    \u3053\u3068)\n    template <class G>\n    int min_left(int r, G g) {\n      \
    \  if (r == 0) return 0;\n        r += sz;\n        for (int i = lg; i >= 1; i--)\
    \ push((r - 1) >> i);\n        S sm = AM::e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(AM::op(d[r],\
    \ sm))) {\n                while (r < sz) {\n                    push(r);\n  \
    \                  r = 2 * r + 1;\n                    if (g(AM::op(d[r], sm)))\
    \ sm = AM::op(d[r--], sm);\n                }\n                return r + 1 -\
    \ sz;\n            }\n            sm = AM::op(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n  private:\n    void update(int k)\
    \ { d[k] = AM::op(d[2 * k], d[2 * k + 1]); }\n    void all_apply(int k, const\
    \ F &f) {\n        d[k] = AM::mapping(f, d[k]);\n        if (k < sz) lz[k] = AM::composition(f,\
    \ lz[k]);\n    }\n    void push(int k) {\n        all_apply(2 * k, lz[k]);\n \
    \       all_apply(2 * k + 1, lz[k]);\n        lz[k] = AM::id();\n    }\n};\n#line\
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
    \ 4 \"data_structure/dynamic_lazy_segment_tree.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u52D5\u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u6DFB\u5B57\
    \u304C\u5927\u304D\u3044\u5834\u5408\u306E\u533A\u9593\u4F5C\u7528\u30FB\u533A\
    \u9593\u7A4D)\n// \u6DFB\u5B57\u306F [0, n) (n \u306F 2^62 \u7A0B\u5EA6\u307E\u3067\
    )\uFF0E\u306F\u3058\u3081\u5168\u3066\u306E\u8981\u7D20\u304C x0 (\u7701\u7565\
    \u6642 e())\n// \u89E6\u3063\u305F\u90E8\u5206\u3060\u3051\u30CE\u30FC\u30C9\u3092\
    \u4F5C\u308B\uFF0E1 \u56DE\u306E\u64CD\u4F5C\u3067\u4F5C\u308B\u30CE\u30FC\u30C9\
    \u306F O(log n) \u500B\n//\n// \u5927\u304D\u3055\u3092 2 \u51AA\u306B\u5207\u308A\
    \u4E0A\u3052\uFF0C\u307E\u3060\u4F5C\u3063\u3066\u3044\u306A\u3044\u9577\u3055\
    \ 2^k \u306E\u533A\u9593\u306E\u7A4D\u306F x0^(2^k) \u3092\u4E8B\u524D\u8A08\u7B97\
    \u3057\u3066\u304A\u3044\u3066\u4F7F\u3046\ntemplate <class AM>\nstruct DynamicLazySegmentTree\
    \ {\n    using S = typename AM::S;\n    using F = typename AM::F;\n    struct\
    \ Node {\n        S val;\n        F lz;\n        int l, r;\n    };\n    long long\
    \ n;\n    int lg;\n    vector<S> pw;  // pw[k] = x0^(2^k)\n    vector<Node> t;\n\
    \    int root;\n\n    DynamicLazySegmentTree(long long n = 0, S x0 = AM::e())\
    \ : n(n) {\n        lg = 0;\n        while ((1LL << lg) < n) lg++;\n        pw.resize(lg\
    \ + 1);\n        pw[0] = x0;\n        for (int k = 1; k <= lg; k++) pw[k] = AM::op(pw[k\
    \ - 1], pw[k - 1]);\n        root = new_node(lg);\n    }\n\n    void reserve(int\
    \ k) { t.reserve(k); }\n\n    // a[p] = x\n    void set(long long p, const S &x)\
    \ { set(root, lg, 0, p, x); }\n\n    S get(long long p) { return prod(p, p + 1);\
    \ }\n\n    // op(a[l], ..., a[r-1])\uFF0El == r \u306A\u3089 e()\n    S prod(long\
    \ long l, long long r) {\n        if (l >= r) return AM::e();\n        return\
    \ prod(root, lg, 0, l, r, AM::id());\n    }\n\n    S all_prod() const { return\
    \ t[root].val; }\n\n    // i in [l, r) \u306B\u3064\u3044\u3066 a[i] = f(a[i])\n\
    \    void apply(long long l, long long r, const F &f) {\n        if (l >= r) return;\n\
    \        apply(root, lg, 0, l, r, f);\n    }\n\n  private:\n    int new_node(int\
    \ k) {\n        t.push_back({pw[k], AM::id(), -1, -1});\n        return int(t.size())\
    \ - 1;\n    }\n    // \u5B50\u3092 (\u306A\u3051\u308C\u3070\u4F5C\u3063\u3066\
    ) \u4F5C\u7528\u3092\u4E0B\u308D\u3059\n    void push(int v, int k) {\n      \
    \  if (t[v].l == -1) {\n            int a = new_node(k - 1);\n            int\
    \ b = new_node(k - 1);\n            t[v].l = a, t[v].r = b;\n        }\n     \
    \   const F f = t[v].lz;\n        all_apply(t[v].l, f);\n        all_apply(t[v].r,\
    \ f);\n        t[v].lz = AM::id();\n    }\n    void all_apply(int v, const F &f)\
    \ {\n        t[v].val = AM::mapping(f, t[v].val);\n        t[v].lz = AM::composition(f,\
    \ t[v].lz);\n    }\n    void update(int v) { t[v].val = AM::op(t[t[v].l].val,\
    \ t[t[v].r].val); }\n\n    // \u30CE\u30FC\u30C9 v \u306F\u533A\u9593 [lo, lo\
    \ + 2^k)\n    void set(int v, int k, long long lo, long long p, const S &x) {\n\
    \        if (k == 0) {\n            t[v].val = x;\n            return;\n     \
    \   }\n        push(v, k);\n        long long mid = lo + (1LL << (k - 1));\n \
    \       if (p < mid) set(t[v].l, k - 1, lo, p, x);\n        else set(t[v].r, k\
    \ - 1, mid, p, x);\n        update(v);\n    }\n\n    void apply(int v, int k,\
    \ long long lo, long long l, long long r, const F &f) {\n        long long hi\
    \ = lo + (1LL << k);\n        if (r <= lo || hi <= l) return;\n        if (l <=\
    \ lo && hi <= r) {\n            all_apply(v, f);\n            return;\n      \
    \  }\n        push(v, k);\n        long long mid = lo + (1LL << (k - 1));\n  \
    \      apply(t[v].l, k - 1, lo, l, r, f);\n        apply(t[v].r, k - 1, mid, l,\
    \ r, f);\n        update(v);\n    }\n\n    // \u5B50\u3092\u4F5C\u3089\u305A\u306B\
    \u6E08\u3080\u3088\u3046\uFF0C\u4E0A\u304B\u3089\u4F5C\u7528\u3092\u6301\u3061\
    \u8D8A\u3057\u3066\u8A08\u7B97\u3059\u308B (g: \u307E\u3060\u4E0B\u308D\u3057\u3066\
    \u3044\u306A\u3044\u4F5C\u7528)\n    S prod(int v, int k, long long lo, long long\
    \ l, long long r, const F &g) {\n        long long hi = lo + (1LL << k);\n   \
    \     if (r <= lo || hi <= l) return AM::e();\n        if (l <= lo && hi <= r)\
    \ return AM::mapping(g, t[v].val);\n        long long mid = lo + (1LL << (k -\
    \ 1));\n        if (t[v].l == -1) {\n            // \u307E\u3060\u5B50\u304C\u306A\
    \u3044 = \u533A\u9593\u5168\u4F53\u306B x0 \u304C\u4E26\u3093\u3067\u3044\u3066\
    \uFF0C\u4F5C\u7528 lz \u304C\u304B\u304B\u3063\u3066\u3044\u308B\n           \
    \ long long a = std::max(l, lo), b = std::min(r, hi);\n            S s = AM::e();\n\
    \            for (int j = k - 1; j >= 0; j--) if ((b - a) >> j & 1) s = AM::op(s,\
    \ pw[j]);\n            return AM::mapping(AM::composition(g, t[v].lz), s);\n \
    \       }\n        F h = AM::composition(g, t[v].lz);\n        return AM::op(prod(t[v].l,\
    \ k - 1, lo, l, r, h), prod(t[v].r, k - 1, mid, l, r, h));\n    }\n};\n#line 2\
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
    \ 4 \"data_structure/persistent_lazy_segment_tree.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u6C38\u7D9A\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n// \u5404\u30D0\
    \u30FC\u30B8\u30E7\u30F3\u3092\u6839\u306E\u30CE\u30FC\u30C9\u756A\u53F7 (int)\
    \ \u3067\u8868\u3059\uFF0E\u66F4\u65B0\u306F\u65B0\u3057\u3044\u30D0\u30FC\u30B8\
    \u30E7\u30F3\u306E\u6839\u3092\u8FD4\u3057\uFF0C\u53E4\u3044\u30D0\u30FC\u30B8\
    \u30E7\u30F3\u306F\u5909\u308F\u3089\u306A\u3044\n// 1 \u56DE\u306E\u66F4\u65B0\
    \u3067\u4F5C\u308B\u30CE\u30FC\u30C9\u306F O(log n) \u500B\uFF0E\u533A\u9593\u7A4D\
    \u306F\u30CE\u30FC\u30C9\u3092\u4F5C\u3089\u306A\u3044\ntemplate <class AM>\n\
    struct PersistentLazySegmentTree {\n    using S = typename AM::S;\n    using F\
    \ = typename AM::F;\n    struct Node {\n        S val;\n        F lz;\n      \
    \  int l, r;\n        bool has_lz;  // lz \u304C\u6052\u7B49\u5199\u50CF\u3067\
    \u306A\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u304B\n    };\n    int n;\n\n\
    \    // \u30CE\u30FC\u30C9\u306F 2^16 \u500B\u305A\u3064\u306E\u30D6\u30ED\u30C3\
    \u30AF\u306B\u78BA\u4FDD\u3059\u308B (vector \u306E\u518D\u78BA\u4FDD\u306B\u3088\
    \u308B\u30B3\u30D4\u30FC\u3068\u30E1\u30E2\u30EA\u306E\u4E00\u6642\u7684\u306A\
    \u500D\u5897\u3092\u907F\u3051\u308B)\n    static constexpr int BLK = 16;\n  \
    \  vector<unique_ptr<Node[]>> blocks;\n    int cnt = 0;\n\n    PersistentLazySegmentTree(int\
    \ n = 0) : n(n) {}\n\n    // \u4F5C\u3063\u305F\u30CE\u30FC\u30C9\u306E\u500B\u6570\
    \n    int node_count() const { return cnt; }\n\n    // \u914D\u5217 a (\u9577\u3055\
    \ n) \u306E\u30D0\u30FC\u30B8\u30E7\u30F3\u3092\u4F5C\u3063\u3066\u6839\u3092\u8FD4\
    \u3059\n    int build(const vector<S> &a) {\n        assert((int)a.size() == n);\n\
    \        return build(a, 0, n);\n    }\n    // \u5168\u3066 x \u306E\u30D0\u30FC\
    \u30B8\u30E7\u30F3\n    int build(const S &x = AM::e()) { return build(vector<S>(n,\
    \ x)); }\n\n    // \u30D0\u30FC\u30B8\u30E7\u30F3 root \u306E a[p] \u3092 x \u306B\
    \u3057\u305F\u30D0\u30FC\u30B8\u30E7\u30F3\n    int set(int root, int p, const\
    \ S &x) {\n        int v = clone(root);\n        set(v, 0, n, p, x);\n       \
    \ return v;\n    }\n\n    S get(int root, int p) const { return prod(root, p,\
    \ p + 1); }\n\n    // \u30D0\u30FC\u30B8\u30E7\u30F3 root \u306E op(a[l], ...,\
    \ a[r-1])\n    S prod(int root, int l, int r) const {\n        if (l >= r) return\
    \ AM::e();\n        return prod(root, 0, n, l, r, AM::id());\n    }\n    S all_prod(int\
    \ root) const { return nd_(root).val; }\n\n    // \u30D0\u30FC\u30B8\u30E7\u30F3\
    \ root \u3067 i in [l, r) \u306B\u3064\u3044\u3066 a[i] = f(a[i]) \u3068\u3057\
    \u305F\u30D0\u30FC\u30B8\u30E7\u30F3\n    int apply(int root, int l, int r, const\
    \ F &f) {\n        if (l >= r) return root;\n        int v = clone(root);\n  \
    \      apply(v, 0, n, l, r, f);\n        return v;\n    }\n\n    // \u30D0\u30FC\
    \u30B8\u30E7\u30F3 dst \u306E [l, r) \u3092\u30D0\u30FC\u30B8\u30E7\u30F3 src\
    \ \u306E [l, r) \u3067\u7F6E\u304D\u63DB\u3048\u305F\u30D0\u30FC\u30B8\u30E7\u30F3\
    \n    int copy_range(int dst, int src, int l, int r) {\n        if (l >= r) return\
    \ dst;\n        return copy_range(dst, src, 0, n, l, r, AM::id());\n    }\n\n\
    \    // \u30D0\u30FC\u30B8\u30E7\u30F3 root \u306E\u914D\u5217\u5168\u4F53\n \
    \   vector<S> to_vector(int root) const {\n        vector<S> res;\n        res.reserve(n);\n\
    \        auto dfs = [&](auto self, int v, int lo, int hi, const F &g) -> void\
    \ {\n            if (hi - lo == 1) {\n                res.push_back(AM::mapping(g,\
    \ nd_(v).val));\n                return;\n            }\n            int mid =\
    \ (lo + hi) >> 1;\n            F h = AM::composition(g, nd_(v).lz);\n        \
    \    self(self, nd_(v).l, lo, mid, h);\n            self(self, nd_(v).r, mid,\
    \ hi, h);\n        };\n        if (n) dfs(dfs, root, 0, n, AM::id());\n      \
    \  return res;\n    }\n\n  private:\n    Node &nd_(int i) { return blocks[i >>\
    \ BLK][i & ((1 << BLK) - 1)]; }\n    const Node &nd_(int i) const { return blocks[i\
    \ >> BLK][i & ((1 << BLK) - 1)]; }\n    int new_node(const Node &x) {\n      \
    \  if ((cnt >> BLK) == (int)blocks.size()) blocks.emplace_back(new Node[1 << BLK]);\n\
    \        nd_(cnt) = x;\n        return cnt++;\n    }\n    int clone(int v) { return\
    \ new_node(Node(nd_(v))); }\n    int build(const vector<S> &a, int lo, int hi)\
    \ {\n        if (hi - lo == 1) {\n            return new_node({a[lo], AM::id(),\
    \ -1, -1, false});\n        }\n        int mid = (lo + hi) >> 1;\n        int\
    \ l = build(a, lo, mid), r = build(a, mid, hi);\n        return new_node({AM::op(nd_(l).val,\
    \ nd_(r).val), AM::id(), l, r, false});\n    }\n    void all_apply(int v, const\
    \ F &f) {\n        nd_(v).val = AM::mapping(f, nd_(v).val);\n        nd_(v).lz\
    \ = AM::composition(f, nd_(v).lz);\n        nd_(v).has_lz = true;\n    }\n   \
    \ // v \u306F\u4ECA\u56DE\u4F5C\u3063\u305F\u30CE\u30FC\u30C9\uFF0E\u4F5C\u7528\
    \u304C\u6B8B\u3063\u3066\u3044\u308C\u3070\u5B50\u3092\u4E21\u65B9\u8907\u88FD\
    \u3057\u3066\u4E0B\u308D\u3059 (\u5B50\u3082\u4ECA\u56DE\u4F5C\u3063\u305F\u30CE\
    \u30FC\u30C9\u306B\u306A\u308B)\n    // \u4F5C\u7528\u304C\u306A\u3051\u308C\u3070\
    \u4F55\u3082\u3057\u306A\u3044 (\u89E6\u308B\u5B50\u3060\u3051\u3092 own_left\
    \ / own_right \u3067\u8907\u88FD\u3059\u308B)\n    void push(int v) {\n      \
    \  if (!nd_(v).has_lz) return;\n        int a = clone(nd_(v).l);\n        int\
    \ b = clone(nd_(v).r);\n        nd_(v).l = a, nd_(v).r = b;\n        const F f\
    \ = nd_(v).lz;\n        all_apply(a, f), all_apply(b, f);\n        nd_(v).lz =\
    \ AM::id();\n        nd_(v).has_lz = false;\n        fresh_l = fresh_r = true;\n\
    \    }\n    // push \u306E\u76F4\u5F8C\u306B\u547C\u3076\uFF0E\u5B50\u304C\u4ECA\
    \u56DE\u4F5C\u3063\u305F\u30CE\u30FC\u30C9\u3067\u306A\u3051\u308C\u3070\u8907\
    \u88FD\u3059\u308B\n    int own_left(int v) {\n        if (!fresh_l) {\n     \
    \       int c = clone(nd_(v).l);\n            nd_(v).l = c;\n        }\n     \
    \   return nd_(v).l;\n    }\n    int own_right(int v) {\n        if (!fresh_r)\
    \ {\n            int c = clone(nd_(v).r);\n            nd_(v).r = c;\n       \
    \ }\n        return nd_(v).r;\n    }\n    bool fresh_l = false, fresh_r = false;\n\
    \    void begin_push(int v) {\n        fresh_l = fresh_r = false;\n        push(v);\n\
    \    }\n    void update(int v) { nd_(v).val = AM::op(nd_(nd_(v).l).val, nd_(nd_(v).r).val);\
    \ }\n\n    void set(int v, int lo, int hi, int p, const S &x) {\n        if (hi\
    \ - lo == 1) {\n            nd_(v).val = x;\n            return;\n        }\n\
    \        begin_push(v);\n        int mid = (lo + hi) >> 1;\n        if (p < mid)\
    \ set(own_left(v), lo, mid, p, x);\n        else set(own_right(v), mid, hi, p,\
    \ x);\n        update(v);\n    }\n\n    void apply(int v, int lo, int hi, int\
    \ l, int r, const F &f) {\n        if (l <= lo && hi <= r) {\n            all_apply(v,\
    \ f);\n            return;\n        }\n        begin_push(v);\n        int mid\
    \ = (lo + hi) >> 1;\n        // own_* \u306F push \u76F4\u5F8C\u306E\u72B6\u614B\
    \ (fresh_*) \u3092\u4F7F\u3046\u306E\u3067\uFF0C\u518D\u5E30\u306E\u524D\u306B\
    \u4E21\u65B9\u78BA\u5B9A\u3055\u305B\u308B\n        int a = l < mid ? own_left(v)\
    \ : -1;\n        int b = mid < r ? own_right(v) : -1;\n        if (a != -1) apply(a,\
    \ lo, mid, l, r, f);\n        if (b != -1) apply(b, mid, hi, l, r, f);\n     \
    \   update(v);\n    }\n\n    // g: \u307E\u3060\u4E0B\u308D\u3057\u3066\u3044\u306A\
    \u3044\u4E0A\u304B\u3089\u306E\u4F5C\u7528\n    S prod(int v, int lo, int hi,\
    \ int l, int r, const F &g) const {\n        if (l <= lo && hi <= r) return AM::mapping(g,\
    \ nd_(v).val);\n        int mid = (lo + hi) >> 1;\n        F h = AM::composition(g,\
    \ nd_(v).lz);\n        if (r <= mid) return prod(nd_(v).l, lo, mid, l, r, h);\n\
    \        if (mid <= l) return prod(nd_(v).r, mid, hi, l, r, h);\n        return\
    \ AM::op(prod(nd_(v).l, lo, mid, l, r, h), prod(nd_(v).r, mid, hi, l, r, h));\n\
    \    }\n\n    // g: src \u5074\u3067\u307E\u3060\u4E0B\u308D\u3057\u3066\u3044\
    \u306A\u3044\u4E0A\u304B\u3089\u306E\u4F5C\u7528\n    int copy_range(int d, int\
    \ s, int lo, int hi, int l, int r, const F &g) {\n        if (r <= lo || hi <=\
    \ l) return d;\n        if (l <= lo && hi <= r) {\n            int v = clone(s);\n\
    \            all_apply(v, g);\n            return v;\n        }\n        int v\
    \ = clone(d);\n        begin_push(v);\n        int mid = (lo + hi) >> 1;\n   \
    \     F h = AM::composition(g, nd_(s).lz);\n        int a = copy_range(nd_(v).l,\
    \ nd_(s).l, lo, mid, l, r, h);\n        int b = copy_range(nd_(v).r, nd_(s).r,\
    \ mid, hi, l, r, h);\n        nd_(v).l = a, nd_(v).r = b;\n        update(v);\n\
    \        return v;\n    }\n};\n#line 7 \"test/unittest/lazy_segment_tree.test.cpp\"\
    \n\n// LazySegmentTree / DynamicLazySegmentTree / PersistentLazySegmentTree \u3068\
    \uFF0C\n// algebra/acted_monoid.hpp \u306E\u5404\u4F5C\u7528\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9\u3092\u611A\u76F4\u3068\u7167\u5408\u3059\u308B\n\nusing mint\
    \ = ModInt998244353;\nusing ll = long long;\n\n// \u4F5C\u7528\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9 AM \u306B\u3064\u3044\u3066\uFF0C\u611A\u76F4\u306E\u914D\u5217\
    \ (long long) \u3068\u7167\u5408\u3059\u308B\n// to_s: \u5024 -> S\uFF0Cfrom_s:\
    \ S -> \u6BD4\u8F03\u7528\u306E\u5024\uFF0Cgen_f: \u4E71\u6570\u3067\u4F5C\u7528\
    \u3092\u4F5C\u308B\uFF0Cact: \u4F5C\u7528\u3092\u5024\u306B\u9069\u7528\ntemplate\
    \ <class AM, class ToS, class Val, class GenF, class Act>\nvoid check_lazy(mt19937_64\
    \ &rng, ToS to_s, Val val, GenF gen_f, Act act) {\n    for (int n : {1, 2, 3,\
    \ 5, 8, 13, 64, 100}) {\n        vector<ll> a(n);\n        for (auto &x : a) x\
    \ = rng() % 10;\n        vector<typename AM::S> init(n);\n        for (int i =\
    \ 0; i < n; i++) init[i] = to_s(a[i]);\n        LazySegmentTree<AM> seg(init);\n\
    \        for (int it = 0; it < 1500; it++) {\n            int t = rng() % 4;\n\
    \            int l = rng() % (n + 1), r = rng() % (n + 1);\n            if (l\
    \ > r) swap(l, r);\n            if (t == 0) {\n                auto f = gen_f();\n\
    \                seg.apply(l, r, f);\n                for (int i = l; i < r; i++)\
    \ a[i] = act(f, a[i]);\n            } else if (t == 1) {\n                int\
    \ p = rng() % n;\n                if (rng() % 2) {\n                    a[p] =\
    \ rng() % 10;\n                    seg.set(p, to_s(a[p]));\n                }\
    \ else {\n                    auto f = gen_f();\n                    seg.apply(p,\
    \ f);\n                    a[p] = act(f, a[p]);\n                }\n         \
    \       assert(val(seg.get(p)) == val(to_s(a[p])));\n            } else if (t\
    \ == 2) {\n                auto s = AM::e();\n                for (int i = l;\
    \ i < r; i++) s = AM::op(s, to_s(a[i]));\n                assert(val(seg.prod(l,\
    \ r)) == val(s));\n                auto all = AM::e();\n                for (int\
    \ i = 0; i < n; i++) all = AM::op(all, to_s(a[i]));\n                assert(val(seg.all_prod())\
    \ == val(all));\n            } else {\n                int p = rng() % n;\n  \
    \              assert(val(seg.get(p)) == val(to_s(a[p])));\n            }\n  \
    \      }\n    }\n}\n\nint main() {\n    mt19937_64 rng(33);\n    // \u533A\u9593\
    \ 1 \u6B21\u95A2\u6570\u30FB\u533A\u9593\u548C\n    {\n        using AM = ActedAffineSum<mint>;\n\
    \        check_lazy<AM>(\n            rng, [](ll x) { return AM::make(mint(x));\
    \ }, [](const AM::S &s) { return pair<int, int>(s.sum.val(), s.len.val()); },\n\
    \            [&]() { return Affine<mint>(rng() % 5 + 1, rng() % 5); }, [](const\
    \ Affine<mint> &f, ll x) { return (ll)f(mint(x)).val(); });\n    }\n    // \u533A\
    \u9593\u52A0\u7B97\u30FB\u533A\u9593\u548C\n    {\n        using AM = ActedAddSum<ll>;\n\
    \        check_lazy<AM>(\n            rng, [](ll x) { return AM::make(x); }, [](const\
    \ AM::S &s) { return pair<ll, ll>(s.sum, s.len); },\n            [&]() { return\
    \ (ll)(rng() % 11) - 5; }, [](ll f, ll x) { return x + f; });\n    }\n    // \u533A\
    \u9593\u52A0\u7B97\u30FB\u533A\u9593\u6700\u5C0F\u5024 / \u6700\u5927\u5024\n\
    \    {\n        using AM = ActedAddMin<ll>;\n        check_lazy<AM>(\n       \
    \     rng, [](ll x) { return x; }, [](ll s) { return s; }, [&]() { return (ll)(rng()\
    \ % 11) - 5; }, [](ll f, ll x) { return x + f; });\n    }\n    {\n        using\
    \ AM = ActedAddMax<ll>;\n        check_lazy<AM>(\n            rng, [](ll x) {\
    \ return x; }, [](ll s) { return s; }, [&]() { return (ll)(rng() % 11) - 5; },\
    \ [](ll f, ll x) { return x + f; });\n    }\n    // \u533A\u9593\u4EE3\u5165\u30FB\
    \u533A\u9593\u548C / \u6700\u5C0F\u5024 / \u6700\u5927\u5024\n    {\n        using\
    \ AM = ActedAssignSum<ll>;\n        check_lazy<AM>(\n            rng, [](ll x)\
    \ { return AM::make(x); }, [](const AM::S &s) { return pair<ll, ll>(s.sum, s.len);\
    \ },\n            [&]() { return AM::F((ll)(rng() % 10)); }, [](const AM::F &f,\
    \ ll x) { return f.has ? f.x : x; });\n    }\n    {\n        using AM = ActedAssignMin<ll>;\n\
    \        check_lazy<AM>(\n            rng, [](ll x) { return x; }, [](ll s) {\
    \ return s; }, [&]() { return AM::F((ll)(rng() % 10)); },\n            [](const\
    \ AM::F &f, ll x) { return f.has ? f.x : x; });\n    }\n    {\n        using AM\
    \ = ActedAssignMax<ll>;\n        check_lazy<AM>(\n            rng, [](ll x) {\
    \ return x; }, [](ll s) { return s; }, [&]() { return AM::F((ll)(rng() % 10));\
    \ },\n            [](const AM::F &f, ll x) { return f.has ? f.x : x; });\n   \
    \ }\n\n    // LazySegmentTree \u306E max_right / min_left: \u533A\u9593\u52A0\u7B97\
    \u30FB\u533A\u9593\u548C\u3067\u300C\u548C\u304C lim \u4EE5\u4E0B\u300D\n    {\n\
    \        using AM = ActedAddSum<ll>;\n        int n = 50;\n        vector<ll>\
    \ a(n, 0);\n        vector<AM::S> init(n, AM::make(0));\n        LazySegmentTree<AM>\
    \ seg(init);\n        for (int it = 0; it < 3000; it++) {\n            int l =\
    \ rng() % (n + 1), r = rng() % (n + 1);\n            if (l > r) swap(l, r);\n\
    \            if (rng() % 2) {\n                ll x = rng() % 3;\n           \
    \     seg.apply(l, r, x);\n                for (int i = l; i < r; i++) a[i] +=\
    \ x;\n            } else {\n                ll lim = rng() % 40;\n           \
    \     int rr = l;\n                ll s = 0;\n                while (rr < n &&\
    \ s + a[rr] <= lim) s += a[rr++];\n                assert(seg.max_right(l, [&](const\
    \ AM::S &x) { return x.sum <= lim; }) == rr);\n                int ll2 = r;\n\
    \                s = 0;\n                while (ll2 > 0 && s + a[ll2 - 1] <= lim)\
    \ s += a[--ll2];\n                assert(seg.min_left(r, [&](const AM::S &x) {\
    \ return x.sum <= lim; }) == ll2);\n            }\n        }\n    }\n\n    //\
    \ DynamicLazySegmentTree: \u521D\u671F\u5024 x0 \u306E\u5927\u304D\u306A\u914D\
    \u5217 (\u5C0F\u3055\u3044 n \u3067\u306F\u611A\u76F4\u3068\u7167\u5408)\n   \
    \ for (ll n : {1LL, 2LL, 5LL, 37LL, 64LL, 100LL}) {\n        using AM = ActedAffineSum<mint>;\n\
    \        mint x0 = rng() % 10;\n        vector<mint> a(n, x0);\n        DynamicLazySegmentTree<AM>\
    \ seg(n, AM::make(x0));\n        for (int it = 0; it < 2000; it++) {\n       \
    \     int t = rng() % 3;\n            int l = rng() % (n + 1), r = rng() % (n\
    \ + 1);\n            if (l > r) swap(l, r);\n            if (t == 0) {\n     \
    \           Affine<mint> f(rng() % 5 + 1, rng() % 5);\n                seg.apply(l,\
    \ r, f);\n                for (int i = l; i < r; i++) a[i] = f(a[i]);\n      \
    \      } else if (t == 1) {\n                int p = rng() % n;\n            \
    \    a[p] = rng() % 10;\n                seg.set(p, AM::make(a[p]));\n       \
    \         assert(seg.get(p).sum == a[p]);\n            } else {\n            \
    \    mint s = 0;\n                for (int i = l; i < r; i++) s += a[i];\n   \
    \             assert(seg.prod(l, r).sum == s && seg.prod(l, r).len == mint(r -\
    \ l));\n            }\n        }\n    }\n    // \u5927\u304D\u306A n \u3067\u3082\
    \u5C0F\u3055\u306A\u7BC4\u56F2\u306E\u64CD\u4F5C\u306F\u6B63\u3057\u3044\n   \
    \ {\n        using AM = ActedAddSum<ll>;\n        ll n = 1LL << 40;\n        DynamicLazySegmentTree<AM>\
    \ seg(n, AM::make(1));\n        seg.apply(5, 10, 3);\n        assert(seg.prod(0,\
    \ n).sum == n + 15);\n        assert(seg.prod(7, 1LL << 35).sum == (1LL << 35)\
    \ - 7 + 9);\n        assert(seg.all_prod().sum == n + 15);\n    }\n\n    // PersistentLazySegmentTree:\
    \ \u5168\u30D0\u30FC\u30B8\u30E7\u30F3\u3092\u611A\u76F4\u306B\u6301\u3063\u3066\
    \u7167\u5408\n    for (int n : {1, 2, 3, 7, 16, 33}) {\n        using AM = ActedAffineSum<mint>;\n\
    \        PersistentLazySegmentTree<AM> seg(n);\n        vector<vector<mint>> ver;\n\
    \        vector<int> roots;\n        vector<mint> a(n);\n        for (auto &x\
    \ : a) x = rng() % 10;\n        vector<AM::S> init(n);\n        for (int i = 0;\
    \ i < n; i++) init[i] = AM::make(a[i]);\n        ver.push_back(a), roots.push_back(seg.build(init));\n\
    \        ver.push_back(vector<mint>(n, 2)), roots.push_back(seg.build(AM::make(2)));\n\
    \        for (int it = 0; it < 1500; it++) {\n            int k = rng() % ver.size(),\
    \ t = rng() % 4;\n            int l = rng() % (n + 1), r = rng() % (n + 1);\n\
    \            if (l > r) swap(l, r);\n            if (t == 0) {\n             \
    \   Affine<mint> f(rng() % 5 + 1, rng() % 5);\n                auto b = ver[k];\n\
    \                for (int i = l; i < r; i++) b[i] = f(b[i]);\n               \
    \ ver.push_back(b), roots.push_back(seg.apply(roots[k], l, r, f));\n         \
    \   } else if (t == 1) {\n                int s = rng() % ver.size();\n      \
    \          auto b = ver[k];\n                for (int i = l; i < r; i++) b[i]\
    \ = ver[s][i];\n                ver.push_back(b), roots.push_back(seg.copy_range(roots[k],\
    \ roots[s], l, r));\n            } else if (t == 2) {\n                int p =\
    \ rng() % n;\n                mint x = rng() % 10;\n                auto b = ver[k];\n\
    \                b[p] = x;\n                ver.push_back(b), roots.push_back(seg.set(roots[k],\
    \ p, AM::make(x)));\n            } else {\n                mint s = 0;\n     \
    \           for (int i = l; i < r; i++) s += ver[k][i];\n                assert(seg.prod(roots[k],\
    \ l, r).sum == s);\n                int p = rng() % n;\n                assert(seg.get(roots[k],\
    \ p).sum == ver[k][p]);\n            }\n        }\n        // \u5168\u30D0\u30FC\
    \u30B8\u30E7\u30F3\u304C\u58CA\u308C\u3066\u3044\u306A\u3044\n        for (size_t\
    \ k = 0; k < ver.size(); k++) {\n            auto v = seg.to_vector(roots[k]);\n\
    \            for (int i = 0; i < n; i++) assert(v[i].sum == ver[k][i]);\n    \
    \        mint s = 0;\n            for (auto x : ver[k]) s += x;\n            assert(seg.all_prod(roots[k]).sum\
    \ == s);\n        }\n        assert(seg.node_count() > 0);\n    }\n\n    long\
    \ long a_, b_;\n    fin >> a_ >> b_;\n    fout << a_ + b_ << '\\n';\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../io/fastio.hpp\"\
    \n#include \"../../math/modint.hpp\"\n#include \"../../data_structure/lazy_segment_tree.hpp\"\
    \n#include \"../../data_structure/dynamic_lazy_segment_tree.hpp\"\n#include \"\
    ../../data_structure/persistent_lazy_segment_tree.hpp\"\n\n// LazySegmentTree\
    \ / DynamicLazySegmentTree / PersistentLazySegmentTree \u3068\uFF0C\n// algebra/acted_monoid.hpp\
    \ \u306E\u5404\u4F5C\u7528\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u3092\u611A\u76F4\
    \u3068\u7167\u5408\u3059\u308B\n\nusing mint = ModInt998244353;\nusing ll = long\
    \ long;\n\n// \u4F5C\u7528\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 AM \u306B\u3064\
    \u3044\u3066\uFF0C\u611A\u76F4\u306E\u914D\u5217 (long long) \u3068\u7167\u5408\
    \u3059\u308B\n// to_s: \u5024 -> S\uFF0Cfrom_s: S -> \u6BD4\u8F03\u7528\u306E\u5024\
    \uFF0Cgen_f: \u4E71\u6570\u3067\u4F5C\u7528\u3092\u4F5C\u308B\uFF0Cact: \u4F5C\
    \u7528\u3092\u5024\u306B\u9069\u7528\ntemplate <class AM, class ToS, class Val,\
    \ class GenF, class Act>\nvoid check_lazy(mt19937_64 &rng, ToS to_s, Val val,\
    \ GenF gen_f, Act act) {\n    for (int n : {1, 2, 3, 5, 8, 13, 64, 100}) {\n \
    \       vector<ll> a(n);\n        for (auto &x : a) x = rng() % 10;\n        vector<typename\
    \ AM::S> init(n);\n        for (int i = 0; i < n; i++) init[i] = to_s(a[i]);\n\
    \        LazySegmentTree<AM> seg(init);\n        for (int it = 0; it < 1500; it++)\
    \ {\n            int t = rng() % 4;\n            int l = rng() % (n + 1), r =\
    \ rng() % (n + 1);\n            if (l > r) swap(l, r);\n            if (t == 0)\
    \ {\n                auto f = gen_f();\n                seg.apply(l, r, f);\n\
    \                for (int i = l; i < r; i++) a[i] = act(f, a[i]);\n          \
    \  } else if (t == 1) {\n                int p = rng() % n;\n                if\
    \ (rng() % 2) {\n                    a[p] = rng() % 10;\n                    seg.set(p,\
    \ to_s(a[p]));\n                } else {\n                    auto f = gen_f();\n\
    \                    seg.apply(p, f);\n                    a[p] = act(f, a[p]);\n\
    \                }\n                assert(val(seg.get(p)) == val(to_s(a[p])));\n\
    \            } else if (t == 2) {\n                auto s = AM::e();\n       \
    \         for (int i = l; i < r; i++) s = AM::op(s, to_s(a[i]));\n           \
    \     assert(val(seg.prod(l, r)) == val(s));\n                auto all = AM::e();\n\
    \                for (int i = 0; i < n; i++) all = AM::op(all, to_s(a[i]));\n\
    \                assert(val(seg.all_prod()) == val(all));\n            } else\
    \ {\n                int p = rng() % n;\n                assert(val(seg.get(p))\
    \ == val(to_s(a[p])));\n            }\n        }\n    }\n}\n\nint main() {\n \
    \   mt19937_64 rng(33);\n    // \u533A\u9593 1 \u6B21\u95A2\u6570\u30FB\u533A\u9593\
    \u548C\n    {\n        using AM = ActedAffineSum<mint>;\n        check_lazy<AM>(\n\
    \            rng, [](ll x) { return AM::make(mint(x)); }, [](const AM::S &s) {\
    \ return pair<int, int>(s.sum.val(), s.len.val()); },\n            [&]() { return\
    \ Affine<mint>(rng() % 5 + 1, rng() % 5); }, [](const Affine<mint> &f, ll x) {\
    \ return (ll)f(mint(x)).val(); });\n    }\n    // \u533A\u9593\u52A0\u7B97\u30FB\
    \u533A\u9593\u548C\n    {\n        using AM = ActedAddSum<ll>;\n        check_lazy<AM>(\n\
    \            rng, [](ll x) { return AM::make(x); }, [](const AM::S &s) { return\
    \ pair<ll, ll>(s.sum, s.len); },\n            [&]() { return (ll)(rng() % 11)\
    \ - 5; }, [](ll f, ll x) { return x + f; });\n    }\n    // \u533A\u9593\u52A0\
    \u7B97\u30FB\u533A\u9593\u6700\u5C0F\u5024 / \u6700\u5927\u5024\n    {\n     \
    \   using AM = ActedAddMin<ll>;\n        check_lazy<AM>(\n            rng, [](ll\
    \ x) { return x; }, [](ll s) { return s; }, [&]() { return (ll)(rng() % 11) -\
    \ 5; }, [](ll f, ll x) { return x + f; });\n    }\n    {\n        using AM = ActedAddMax<ll>;\n\
    \        check_lazy<AM>(\n            rng, [](ll x) { return x; }, [](ll s) {\
    \ return s; }, [&]() { return (ll)(rng() % 11) - 5; }, [](ll f, ll x) { return\
    \ x + f; });\n    }\n    // \u533A\u9593\u4EE3\u5165\u30FB\u533A\u9593\u548C /\
    \ \u6700\u5C0F\u5024 / \u6700\u5927\u5024\n    {\n        using AM = ActedAssignSum<ll>;\n\
    \        check_lazy<AM>(\n            rng, [](ll x) { return AM::make(x); }, [](const\
    \ AM::S &s) { return pair<ll, ll>(s.sum, s.len); },\n            [&]() { return\
    \ AM::F((ll)(rng() % 10)); }, [](const AM::F &f, ll x) { return f.has ? f.x :\
    \ x; });\n    }\n    {\n        using AM = ActedAssignMin<ll>;\n        check_lazy<AM>(\n\
    \            rng, [](ll x) { return x; }, [](ll s) { return s; }, [&]() { return\
    \ AM::F((ll)(rng() % 10)); },\n            [](const AM::F &f, ll x) { return f.has\
    \ ? f.x : x; });\n    }\n    {\n        using AM = ActedAssignMax<ll>;\n     \
    \   check_lazy<AM>(\n            rng, [](ll x) { return x; }, [](ll s) { return\
    \ s; }, [&]() { return AM::F((ll)(rng() % 10)); },\n            [](const AM::F\
    \ &f, ll x) { return f.has ? f.x : x; });\n    }\n\n    // LazySegmentTree \u306E\
    \ max_right / min_left: \u533A\u9593\u52A0\u7B97\u30FB\u533A\u9593\u548C\u3067\
    \u300C\u548C\u304C lim \u4EE5\u4E0B\u300D\n    {\n        using AM = ActedAddSum<ll>;\n\
    \        int n = 50;\n        vector<ll> a(n, 0);\n        vector<AM::S> init(n,\
    \ AM::make(0));\n        LazySegmentTree<AM> seg(init);\n        for (int it =\
    \ 0; it < 3000; it++) {\n            int l = rng() % (n + 1), r = rng() % (n +\
    \ 1);\n            if (l > r) swap(l, r);\n            if (rng() % 2) {\n    \
    \            ll x = rng() % 3;\n                seg.apply(l, r, x);\n        \
    \        for (int i = l; i < r; i++) a[i] += x;\n            } else {\n      \
    \          ll lim = rng() % 40;\n                int rr = l;\n               \
    \ ll s = 0;\n                while (rr < n && s + a[rr] <= lim) s += a[rr++];\n\
    \                assert(seg.max_right(l, [&](const AM::S &x) { return x.sum <=\
    \ lim; }) == rr);\n                int ll2 = r;\n                s = 0;\n    \
    \            while (ll2 > 0 && s + a[ll2 - 1] <= lim) s += a[--ll2];\n       \
    \         assert(seg.min_left(r, [&](const AM::S &x) { return x.sum <= lim; })\
    \ == ll2);\n            }\n        }\n    }\n\n    // DynamicLazySegmentTree:\
    \ \u521D\u671F\u5024 x0 \u306E\u5927\u304D\u306A\u914D\u5217 (\u5C0F\u3055\u3044\
    \ n \u3067\u306F\u611A\u76F4\u3068\u7167\u5408)\n    for (ll n : {1LL, 2LL, 5LL,\
    \ 37LL, 64LL, 100LL}) {\n        using AM = ActedAffineSum<mint>;\n        mint\
    \ x0 = rng() % 10;\n        vector<mint> a(n, x0);\n        DynamicLazySegmentTree<AM>\
    \ seg(n, AM::make(x0));\n        for (int it = 0; it < 2000; it++) {\n       \
    \     int t = rng() % 3;\n            int l = rng() % (n + 1), r = rng() % (n\
    \ + 1);\n            if (l > r) swap(l, r);\n            if (t == 0) {\n     \
    \           Affine<mint> f(rng() % 5 + 1, rng() % 5);\n                seg.apply(l,\
    \ r, f);\n                for (int i = l; i < r; i++) a[i] = f(a[i]);\n      \
    \      } else if (t == 1) {\n                int p = rng() % n;\n            \
    \    a[p] = rng() % 10;\n                seg.set(p, AM::make(a[p]));\n       \
    \         assert(seg.get(p).sum == a[p]);\n            } else {\n            \
    \    mint s = 0;\n                for (int i = l; i < r; i++) s += a[i];\n   \
    \             assert(seg.prod(l, r).sum == s && seg.prod(l, r).len == mint(r -\
    \ l));\n            }\n        }\n    }\n    // \u5927\u304D\u306A n \u3067\u3082\
    \u5C0F\u3055\u306A\u7BC4\u56F2\u306E\u64CD\u4F5C\u306F\u6B63\u3057\u3044\n   \
    \ {\n        using AM = ActedAddSum<ll>;\n        ll n = 1LL << 40;\n        DynamicLazySegmentTree<AM>\
    \ seg(n, AM::make(1));\n        seg.apply(5, 10, 3);\n        assert(seg.prod(0,\
    \ n).sum == n + 15);\n        assert(seg.prod(7, 1LL << 35).sum == (1LL << 35)\
    \ - 7 + 9);\n        assert(seg.all_prod().sum == n + 15);\n    }\n\n    // PersistentLazySegmentTree:\
    \ \u5168\u30D0\u30FC\u30B8\u30E7\u30F3\u3092\u611A\u76F4\u306B\u6301\u3063\u3066\
    \u7167\u5408\n    for (int n : {1, 2, 3, 7, 16, 33}) {\n        using AM = ActedAffineSum<mint>;\n\
    \        PersistentLazySegmentTree<AM> seg(n);\n        vector<vector<mint>> ver;\n\
    \        vector<int> roots;\n        vector<mint> a(n);\n        for (auto &x\
    \ : a) x = rng() % 10;\n        vector<AM::S> init(n);\n        for (int i = 0;\
    \ i < n; i++) init[i] = AM::make(a[i]);\n        ver.push_back(a), roots.push_back(seg.build(init));\n\
    \        ver.push_back(vector<mint>(n, 2)), roots.push_back(seg.build(AM::make(2)));\n\
    \        for (int it = 0; it < 1500; it++) {\n            int k = rng() % ver.size(),\
    \ t = rng() % 4;\n            int l = rng() % (n + 1), r = rng() % (n + 1);\n\
    \            if (l > r) swap(l, r);\n            if (t == 0) {\n             \
    \   Affine<mint> f(rng() % 5 + 1, rng() % 5);\n                auto b = ver[k];\n\
    \                for (int i = l; i < r; i++) b[i] = f(b[i]);\n               \
    \ ver.push_back(b), roots.push_back(seg.apply(roots[k], l, r, f));\n         \
    \   } else if (t == 1) {\n                int s = rng() % ver.size();\n      \
    \          auto b = ver[k];\n                for (int i = l; i < r; i++) b[i]\
    \ = ver[s][i];\n                ver.push_back(b), roots.push_back(seg.copy_range(roots[k],\
    \ roots[s], l, r));\n            } else if (t == 2) {\n                int p =\
    \ rng() % n;\n                mint x = rng() % 10;\n                auto b = ver[k];\n\
    \                b[p] = x;\n                ver.push_back(b), roots.push_back(seg.set(roots[k],\
    \ p, AM::make(x)));\n            } else {\n                mint s = 0;\n     \
    \           for (int i = l; i < r; i++) s += ver[k][i];\n                assert(seg.prod(roots[k],\
    \ l, r).sum == s);\n                int p = rng() % n;\n                assert(seg.get(roots[k],\
    \ p).sum == ver[k][p]);\n            }\n        }\n        // \u5168\u30D0\u30FC\
    \u30B8\u30E7\u30F3\u304C\u58CA\u308C\u3066\u3044\u306A\u3044\n        for (size_t\
    \ k = 0; k < ver.size(); k++) {\n            auto v = seg.to_vector(roots[k]);\n\
    \            for (int i = 0; i < n; i++) assert(v[i].sum == ver[k][i]);\n    \
    \        mint s = 0;\n            for (auto x : ver[k]) s += x;\n            assert(seg.all_prod(roots[k]).sum\
    \ == s);\n        }\n        assert(seg.node_count() > 0);\n    }\n\n    long\
    \ long a_, b_;\n    fin >> a_ >> b_;\n    fout << a_ + b_ << '\\n';\n    return\
    \ 0;\n}\n"
  dependsOn:
  - io/fastio.hpp
  - template.hpp
  - math/modint.hpp
  - template.hpp
  - data_structure/lazy_segment_tree.hpp
  - template.hpp
  - algebra/acted_monoid.hpp
  - algebra/monoid.hpp
  - template.hpp
  - data_structure/dynamic_lazy_segment_tree.hpp
  - data_structure/persistent_lazy_segment_tree.hpp
  isVerificationFile: true
  path: test/unittest/lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unittest/lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/lazy_segment_tree.test.cpp
- /verify/test/unittest/lazy_segment_tree.test.cpp.html
title: test/unittest/lazy_segment_tree.test.cpp
---
