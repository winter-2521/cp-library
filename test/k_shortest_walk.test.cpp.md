---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/csr.hpp
    title: "CSR (\u96A3\u63A5\u30EA\u30B9\u30C8\u3092 1 \u672C\u306E\u914D\u5217\u3067\
      \u6301\u3064)"
  - icon: ':heavy_check_mark:'
    path: graph/k_shortest_walk.hpp
    title: "K \u6700\u77ED\u8DEF (K-Shortest Walk, Eppstein)"
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
    PROBLEM: https://judge.yosupo.jp/problem/k_shortest_walk
    links:
    - https://judge.yosupo.jp/problem/k_shortest_walk
  bundledCode: "#line 1 \"test/k_shortest_walk.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/k_shortest_walk\"\
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
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 3 \"graph/csr.hpp\"\
    \n\n// \u96A3\u63A5\u30EA\u30B9\u30C8\u3092 1 \u672C\u306E\u914D\u5217\u3067\u6301\
    \u3064 (Compressed Sparse Row)\n// \u9802\u70B9 v \u306E\u96A3\u63A5\u306F elist[start[v]\
    \ .. start[v+1])\uFF0Evector<vector<int>> \u3088\u308A\u901F\u304F\u30E1\u30E2\
    \u30EA\u3082\u5C11\u306A\u3044\ntemplate <class E>\nstruct CSR {\n    vector<int>\
    \ start;\n    vector<E> elist;\n    CSR() = default;\n    // edges[i] = (from,\
    \ \u4E2D\u8EAB)\n    CSR(int n, const vector<pair<int, E>> &edges) : start(n +\
    \ 1, 0), elist(edges.size()) {\n        for (auto &e : edges) start[e.first +\
    \ 1]++;\n        for (int i = 1; i <= n; i++) start[i] += start[i - 1];\n    \
    \    vector<int> pos(start.begin(), start.end() - 1);\n        for (auto &e :\
    \ edges) elist[pos[e.first]++] = e.second;\n    }\n    int size() const { return\
    \ (int)start.size() - 1; }\n};\n#line 4 \"graph/k_shortest_walk.hpp\"\n\n// s\
    \ \u304B\u3089 t \u3078\u306E\u77ED\u3044\u65B9\u304B\u3089 K \u500B\u306E\u30A6\
    \u30A9\u30FC\u30AF (\u540C\u3058\u9802\u70B9\u30FB\u8FBA\u3092\u4F55\u5EA6\u901A\
    \u3063\u3066\u3082\u3088\u3044\u8DEF) \u306E\u9577\u3055 (Eppstein \u6CD5)\n//\
    \ \u8FBA\u306E\u91CD\u307F\u306F\u975E\u8CA0\uFF0E\u8FD4\u308A\u5024\u306F\u9577\
    \u3055\u306E\u6607\u9806\u3067\uFF0CK \u500B\u306B\u6E80\u305F\u306A\u3051\u308C\
    \u3070\u305D\u306E\u5206\u3060\u3051\n// 1. t \u3078\u306E\u6700\u77ED\u8DDD\u96E2\
    \ dist \u3068\uFF0C\u5404\u9802\u70B9\u304B\u3089 t \u3078\u306E\u6700\u77ED\u8DEF\
    \u6728\u3092\u4F5C\u308B\n// 2. \u6700\u77ED\u8DEF\u6728\u306B\u4F7F\u308F\u306A\
    \u3044\u8FBA e = (u \u2192 w) \u3092\u300C\u5BC4\u308A\u9053\u300D\u3068\u547C\
    \u3073\uFF0C\u305D\u306E\u8FFD\u52A0\u30B3\u30B9\u30C8 \u03B4(e) = c + dist[w]\
    \ - dist[u] >= 0\n// 3. H[v] = v \u304B\u3089\u6700\u77ED\u8DEF\u6728\u3067 t\
    \ \u306B\u5411\u304B\u3046\u9014\u4E2D\u306E\u9802\u70B9\u304B\u3089\u51FA\u308B\
    \u5BC4\u308A\u9053\u5168\u90E8\u3092 \u03B4 \u3067\u307E\u3068\u3081\u305F\u6C38\
    \u7D9A\u30D2\u30FC\u30D7 (H[v] = H[\u89AA] + v \u306E\u5BC4\u308A\u9053)\n// 4.\
    \ \u30A6\u30A9\u30FC\u30AF\u306F\u300C\u5BC4\u308A\u9053\u306E\u5217\u300D\u3068\
    \ 1 \u5BFE 1 \u306B\u5BFE\u5FDC\u3057\uFF0C\u305D\u308C\u3092\u512A\u5148\u5EA6\
    \u4ED8\u304D\u30AD\u30E5\u30FC\u3067\u5C0F\u3055\u3044\u9806\u306B\u53D6\u308A\
    \u51FA\u3059\n// O((n + m) log m + K log K)\ntemplate <class T>\nvector<T> k_shortest_walks(int\
    \ n, const vector<tuple<int, int, T>> &edges, int s, int t, int K) {\n    int\
    \ m = edges.size();\n    const T INF = numeric_limits<T>::max();\n    // \u9006\
    \u5411\u304D\u306E Dijkstra (t \u304B\u3089)\n    vector<pair<int, int>> rel(m);\n\
    \    for (int i = 0; i < m; i++) rel[i] = {get<1>(edges[i]), i};\n    CSR<int>\
    \ rg(n, rel);\n    vector<T> dist(n, INF);\n    vector<int> tree_edge(n, -1),\
    \ order;  // tree_edge[v]: v \u304B\u3089 t \u3078\u306E\u6700\u77ED\u8DEF\u6728\
    \u3067\u4F7F\u3046\u8FBA\n    order.reserve(n);\n    {\n        priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<>> pq;\n        dist[t] = 0, pq.push({0,\
    \ t});\n        while (!pq.empty()) {\n            auto [d, v] = pq.top();\n \
    \           pq.pop();\n            if (d != dist[v]) continue;\n            order.push_back(v);\n\
    \            for (int i = rg.start[v]; i < rg.start[v + 1]; i++) {\n         \
    \       int e = rg.elist[i], u = get<0>(edges[e]);\n                T nd = d +\
    \ get<2>(edges[e]);\n                if (nd < dist[u]) dist[u] = nd, tree_edge[u]\
    \ = e, pq.push({nd, u});\n            }\n        }\n    }\n    vector<T> res;\n\
    \    if (dist[s] == INF) return res;\n    // \u6C38\u7D9A leftist heap (\u30AD\
    \u30FC\u306F \u03B4\uFF0C\u5024\u306F\u5BC4\u308A\u9053\u306E\u884C\u304D\u5148\
    \u306E\u9802\u70B9)\n    struct Node {\n        T key;\n        int to, l, r,\
    \ rk;\n    };\n    vector<Node> hp{{T(0), -1, 0, 0, 0}};  // 0 \u756A\u306F\u7A7A\
    \n    auto merge = [&](auto self, int a, int b) -> int {\n        if (!a || !b)\
    \ return a ^ b;\n        if (hp[b].key < hp[a].key) swap(a, b);\n        Node\
    \ nd = hp[a];\n        int r = self(self, nd.r, b);\n        nd.r = r;\n     \
    \   if (hp[nd.l].rk < hp[nd.r].rk) swap(nd.l, nd.r);\n        nd.rk = hp[nd.r].rk\
    \ + 1;\n        hp.push_back(nd);\n        return hp.size() - 1;\n    };\n   \
    \ vector<pair<int, int>> fel(m);\n    for (int i = 0; i < m; i++) fel[i] = {get<0>(edges[i]),\
    \ i};\n    CSR<int> fg(n, fel);\n    vector<int> H(n, 0);\n    // t \u306B\u8FD1\
    \u3044\u9806 (dist \u306E\u6607\u9806) \u306B H \u3092\u4F5C\u308B\n    for (int\
    \ v : order) {\n        int h = v == t ? 0 : H[get<1>(edges[tree_edge[v]])];\n\
    \        for (int i = fg.start[v]; i < fg.start[v + 1]; i++) {\n            int\
    \ e = fg.elist[i], w = get<1>(edges[e]);\n            if (e == tree_edge[v] ||\
    \ dist[w] == INF) continue;\n            T delta = get<2>(edges[e]) + dist[w]\
    \ - dist[v];\n            hp.push_back({delta, w, 0, 0, 1});\n            h =\
    \ merge(merge, h, (int)hp.size() - 1);\n        }\n        H[v] = h;\n    }\n\
    \    res.push_back(dist[s]);\n    priority_queue<pair<T, int>, vector<pair<T,\
    \ int>>, greater<>> pq;  // (\u9577\u3055, \u30D2\u30FC\u30D7\u306E\u30CE\u30FC\
    \u30C9)\n    if (H[s]) pq.push({dist[s] + hp[H[s]].key, H[s]});\n    while ((int)res.size()\
    \ < K && !pq.empty()) {\n        auto [d, x] = pq.top();\n        pq.pop();\n\
    \        res.push_back(d);\n        // \u540C\u3058\u30D2\u30FC\u30D7\u306E\u4E2D\
    \u3067\u6B21\u306E\u5BC4\u308A\u9053\u306B\u66FF\u3048\u308B\n        for (int\
    \ c : {hp[x].l, hp[x].r})\n            if (c) pq.push({d - hp[x].key + hp[c].key,\
    \ c});\n        // \u3053\u306E\u5BC4\u308A\u9053\u306E\u5F8C\u306B\uFF0C\u884C\
    \u304D\u5148\u304B\u3089\u66F4\u306B\u5BC4\u308A\u9053\u3092\u8DB3\u3059\n   \
    \     int nh = H[hp[x].to];\n        if (nh) pq.push({d + hp[nh].key, nh});\n\
    \    }\n    return res;\n}\n#line 4 \"test/k_shortest_walk.test.cpp\"\n\nint main()\
    \ {\n    int n, m, s, t, k;\n    fin >> n >> m >> s >> t >> k;\n    vector<tuple<int,\
    \ int, long long>> edges(m);\n    for (auto &[a, b, c] : edges) fin >> a >> b\
    \ >> c;\n    auto res = k_shortest_walks(n, edges, s, t, k);\n    for (int i =\
    \ 0; i < k; i++) fout << (i < (int)res.size() ? res[i] : -1) << '\\n';\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/k_shortest_walk\"\n#include\
    \ \"../io/fastio.hpp\"\n#include \"../graph/k_shortest_walk.hpp\"\n\nint main()\
    \ {\n    int n, m, s, t, k;\n    fin >> n >> m >> s >> t >> k;\n    vector<tuple<int,\
    \ int, long long>> edges(m);\n    for (auto &[a, b, c] : edges) fin >> a >> b\
    \ >> c;\n    auto res = k_shortest_walks(n, edges, s, t, k);\n    for (int i =\
    \ 0; i < k; i++) fout << (i < (int)res.size() ? res[i] : -1) << '\\n';\n    return\
    \ 0;\n}\n"
  dependsOn:
  - io/fastio.hpp
  - template.hpp
  - graph/k_shortest_walk.hpp
  - template.hpp
  - graph/csr.hpp
  isVerificationFile: true
  path: test/k_shortest_walk.test.cpp
  requiredBy: []
  timestamp: '2026-10-15 00:32:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/k_shortest_walk.test.cpp
layout: document
redirect_from:
- /verify/test/k_shortest_walk.test.cpp
- /verify/test/k_shortest_walk.test.cpp.html
title: test/k_shortest_walk.test.cpp
---
