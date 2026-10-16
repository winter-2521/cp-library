---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/biconnected_components.hpp
    title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3 (Biconnected\
      \ Components)"
  - icon: ':question:'
    path: graph/complement_graph_components.hpp
    title: "\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':question:'
    path: graph/csr.hpp
    title: "CSR (\u96A3\u63A5\u30EA\u30B9\u30C8\u3092 1 \u672C\u306E\u914D\u5217\u3067\
      \u6301\u3064)"
  - icon: ':question:'
    path: graph/cycle_detection.hpp
    title: "\u9589\u8DEF\u691C\u51FA (Cycle Detection)"
  - icon: ':x:'
    path: graph/eulerian_trail.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u8DEF (Eulerian Trail)"
  - icon: ':x:'
    path: graph/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 (SCC)"
  - icon: ':x:'
    path: graph/three_edge_connected_components.hpp
    title: "\u4E09\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 (Three-Edge-Connected\
      \ Components)"
  - icon: ':x:'
    path: graph/two_edge_connected_components.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 (Two-Edge-Connected\
      \ Components)"
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
  bundledCode: "#line 1 \"test/unittest/graph_components.test.cpp\"\n#define PROBLEM\
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
    \n\n// https://github.com/winter-2521/cp-library\n\n// \u96A3\u63A5\u30EA\u30B9\
    \u30C8\u3092 1 \u672C\u306E\u914D\u5217\u3067\u6301\u3064 (Compressed Sparse Row)\n\
    // \u9802\u70B9 v \u306E\u96A3\u63A5\u306F elist[start[v] .. start[v+1])\uFF0E\
    vector<vector<int>> \u3088\u308A\u901F\u304F\u30E1\u30E2\u30EA\u3082\u5C11\u306A\
    \u3044\ntemplate <class E>\nstruct CSR {\n    vector<int> start;\n    vector<E>\
    \ elist;\n    CSR() = default;\n    // edges[i] = (from, \u4E2D\u8EAB)\n    CSR(int\
    \ n, const vector<pair<int, E>> &edges) : start(n + 1, 0), elist(edges.size())\
    \ {\n        for (auto &e : edges) start[e.first + 1]++;\n        for (int i =\
    \ 1; i <= n; i++) start[i] += start[i - 1];\n        vector<int> pos(start.begin(),\
    \ start.end() - 1);\n        for (auto &e : edges) elist[pos[e.first]++] = e.second;\n\
    \    }\n    int size() const { return (int)start.size() - 1; }\n};\n#line 4 \"\
    graph/cycle_detection.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\n\
    // \u9589\u8DEF\u691C\u51FA\n// find_cycle_directed(n, edges)   : \u6709\u5411\
    \u30B0\u30E9\u30D5\u306E\u9589\u8DEF\u3092 1 \u3064\uFF0E\u8FBA\u756A\u53F7\u306E\
    \u5217 (\u306A\u3051\u308C\u3070\u7A7A)\n// find_cycle_undirected(n, edges) :\
    \ \u7121\u5411\u30B0\u30E9\u30D5\u306E\u9589\u8DEF\u3092 1 \u3064\uFF0E{\u9802\
    \u70B9\u306E\u5217, \u8FBA\u756A\u53F7\u306E\u5217} (\u306A\u3051\u308C\u3070\u7A7A\
    )\n// \u3069\u3061\u3089\u3082\u975E\u518D\u5E30\u306E DFS \u3067 O(n + m)\n\n\
    inline vector<int> find_cycle_directed(int n, const vector<pair<int, int>> &edges)\
    \ {\n    int m = edges.size();\n    vector<pair<int, int>> el(m);\n    for (int\
    \ i = 0; i < m; i++) el[i] = {edges[i].first, i};\n    CSR<int> g(n, el);\n  \
    \  // state: 0 = \u672A\u8A2A\u554F\uFF0C1 = \u63A2\u7D22\u4E2D (\u30B9\u30BF\u30C3\
    \u30AF\u306B\u3042\u308B)\uFF0C2 = \u7D42\u4E86\n    vector<char> state(n, 0);\n\
    \    vector<int> it(n), par_edge(n, -1), stk;\n    for (int s = 0; s < n; s++)\
    \ {\n        if (state[s]) continue;\n        stk.push_back(s), state[s] = 1,\
    \ it[s] = g.start[s];\n        while (!stk.empty()) {\n            int v = stk.back();\n\
    \            if (it[v] == g.start[v + 1]) {\n                state[v] = 2, stk.pop_back();\n\
    \                continue;\n            }\n            int e = g.elist[it[v]++],\
    \ to = edges[e].second;\n            if (state[to] == 0) {\n                par_edge[to]\
    \ = e, state[to] = 1, it[to] = g.start[to];\n                stk.push_back(to);\n\
    \            } else if (state[to] == 1) {\n                // to \u2192 ... \u2192\
    \ v \u2192 to \u304C\u9589\u8DEF\n                vector<int> cyc{e};\n      \
    \          for (int x = v; x != to; x = edges[par_edge[x]].first) cyc.push_back(par_edge[x]);\n\
    \                reverse(cyc.begin(), cyc.end());\n                return cyc;\n\
    \            }\n        }\n    }\n    return {};\n}\n\ninline pair<vector<int>,\
    \ vector<int>> find_cycle_undirected(int n, const vector<pair<int, int>> &edges)\
    \ {\n    int m = edges.size();\n    vector<pair<int, int>> el;\n    el.reserve(2\
    \ * m);\n    for (int i = 0; i < m; i++) {\n        auto [u, v] = edges[i];\n\
    \        if (u == v) return {{u}, {i}};  // \u81EA\u5DF1\u30EB\u30FC\u30D7\n \
    \       el.push_back({u, i}), el.push_back({v, i});\n    }\n    CSR<int> g(n,\
    \ el);\n    vector<int> depth(n, -1), it(n), par_edge(n, -1), stk;\n    for (int\
    \ s = 0; s < n; s++) {\n        if (depth[s] >= 0) continue;\n        depth[s]\
    \ = 0, it[s] = g.start[s], stk.push_back(s);\n        while (!stk.empty()) {\n\
    \            int v = stk.back();\n            if (it[v] == g.start[v + 1]) {\n\
    \                stk.pop_back();\n                continue;\n            }\n \
    \           int e = g.elist[it[v]++];\n            if (e == par_edge[v]) continue;\n\
    \            int to = edges[e].first ^ edges[e].second ^ v;\n            if (depth[to]\
    \ < 0) {\n                depth[to] = depth[v] + 1, par_edge[to] = e, it[to] =\
    \ g.start[to];\n                stk.push_back(to);\n            } else if (depth[to]\
    \ < depth[v]) {\n                // to \u2192 ... \u2192 v \u2192 to (\u5F8C\u9000\
    \u8FBA e)\n                vector<int> vs, es;\n                for (int x = v;\
    \ x != to;) {\n                    vs.push_back(x), es.push_back(par_edge[x]);\n\
    \                    int pe = par_edge[x];\n                    x = edges[pe].first\
    \ ^ edges[pe].second ^ x;\n                }\n                vs.push_back(to);\n\
    \                reverse(vs.begin(), vs.end()), reverse(es.begin(), es.end());\n\
    \                es.push_back(e);\n                return {vs, es};\n        \
    \    }\n        }\n    }\n    return {};\n}\n#line 2 \"template.hpp\"\nusing namespace\
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
    \ 4 \"graph/scc.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\n// \u5F37\
    \u9023\u7D50\u6210\u5206\u5206\u89E3 (Tarjan, \u975E\u518D\u5E30)\n// build()\
    \ \u5F8C: groups \u306F\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806 (\u8FBA u \u2192\
    \ v \u306A\u3089 u \u306E\u6210\u5206\u304C\u5148)\uFF0Ccomp[v] \u306F\u305D\u306E\
    \u756A\u53F7\uFF0EO(n + m)\nstruct StronglyConnectedComponents {\n    int n;\n\
    \    vector<pair<int, int>> edges;\n    vector<int> comp;\n    vector<vector<int>>\
    \ groups;\n\n    StronglyConnectedComponents(int n = 0) : n(n) {}\n    void reserve(int\
    \ m) { edges.reserve(m); }\n    void add_edge(int u, int v) { edges.push_back({u,\
    \ v}); }\n\n    // \u6210\u5206\u306E\u500B\u6570\u3092\u8FD4\u3059\n    int build()\
    \ {\n        CSR<int> g(n, edges);\n        vector<int> ord(n, -1), low(n), it(n),\
    \ stk, call;\n        comp.assign(n, -1);\n        stk.reserve(n), call.reserve(n);\n\
    \        int now = 0, k = 0;\n        for (int s = 0; s < n; s++) {\n        \
    \    if (ord[s] >= 0) continue;\n            call.push_back(s), ord[s] = low[s]\
    \ = now++, it[s] = g.start[s], stk.push_back(s);\n            while (!call.empty())\
    \ {\n                int v = call.back();\n                if (it[v] < g.start[v\
    \ + 1]) {\n                    int to = g.elist[it[v]++];\n                  \
    \  if (ord[to] < 0) {\n                        ord[to] = low[to] = now++, it[to]\
    \ = g.start[to];\n                        stk.push_back(to), call.push_back(to);\n\
    \                    } else if (comp[to] < 0) {\n                        low[v]\
    \ = std::min(low[v], ord[to]);\n                    }\n                    continue;\n\
    \                }\n                call.pop_back();\n                if (!call.empty())\
    \ low[call.back()] = std::min(low[call.back()], low[v]);\n                if (low[v]\
    \ == ord[v]) {\n                    while (true) {\n                        int\
    \ u = stk.back();\n                        stk.pop_back();\n                 \
    \       comp[u] = k;\n                        if (u == v) break;\n           \
    \         }\n                    k++;\n                }\n            }\n    \
    \    }\n        // Tarjan \u306F\u9006\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\
    \u306B\u756A\u53F7\u3092\u632F\u308B\u306E\u3067\u53CD\u8EE2\u3059\u308B\n   \
    \     for (auto &c : comp) c = k - 1 - c;\n        groups.assign(k, {});\n   \
    \     vector<int> cnt(k, 0);\n        for (int v = 0; v < n; v++) cnt[comp[v]]++;\n\
    \        for (int i = 0; i < k; i++) groups[i].reserve(cnt[i]);\n        for (int\
    \ v = 0; v < n; v++) groups[comp[v]].push_back(v);\n        return k;\n    }\n\
    };\n#line 2 \"template.hpp\"\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
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
    \ 4 \"graph/two_edge_connected_components.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 (\u6A4B\u3067\u5207\
    \u3063\u305F\u9023\u7D50\u6210\u5206)\uFF0Elowlink\uFF0C\u975E\u518D\u5E30 DFS\
    \ \u3067 O(n + m)\n// \u8FD4\u308A\u5024: \u6210\u5206\u3054\u3068\u306E\u9802\
    \u70B9\u306E\u5217\uFF0Ecomp \u3092\u6E21\u3059\u3068\u5404\u9802\u70B9\u306E\u6210\
    \u5206\u756A\u53F7\u3082\u5165\u308B\n// is_bridge \u3092\u6E21\u3059\u3068\u5404\
    \u8FBA\u304C\u6A4B\u304B\u3069\u3046\u304B\u3082\u5165\u308B\ninline vector<vector<int>>\
    \ two_edge_connected_components(int n, const vector<pair<int, int>> &edges, vector<int>\
    \ *comp_out = nullptr,\n                                                     \
    \    vector<char> *is_bridge = nullptr) {\n    int m = edges.size();\n    vector<pair<int,\
    \ int>> el;\n    el.reserve(2 * m);\n    for (int i = 0; i < m; i++) {\n     \
    \   if (edges[i].first == edges[i].second) continue;\n        el.push_back({edges[i].first,\
    \ i}), el.push_back({edges[i].second, i});\n    }\n    CSR<int> g(n, el);\n  \
    \  vector<int> ord(n, -1), low(n), it(n), par_edge(n, -1), call, stk, comp(n,\
    \ -1);\n    vector<vector<int>> groups;\n    if (is_bridge) is_bridge->assign(m,\
    \ 0);\n    int now = 0;\n    for (int s = 0; s < n; s++) {\n        if (ord[s]\
    \ >= 0) continue;\n        ord[s] = low[s] = now++, it[s] = g.start[s], call.push_back(s),\
    \ stk.push_back(s);\n        while (!call.empty()) {\n            int v = call.back();\n\
    \            if (it[v] < g.start[v + 1]) {\n                int e = g.elist[it[v]++];\n\
    \                if (e == par_edge[v]) continue;  // \u6765\u305F\u8FBA (\u591A\
    \u91CD\u8FBA\u306F\u5225\u306E\u8FBA\u3068\u3057\u3066\u6271\u3046)\n        \
    \        int to = edges[e].first ^ edges[e].second ^ v;\n                if (ord[to]\
    \ < 0) {\n                    ord[to] = low[to] = now++, it[to] = g.start[to],\
    \ par_edge[to] = e;\n                    call.push_back(to), stk.push_back(to);\n\
    \                } else {\n                    low[v] = std::min(low[v], ord[to]);\n\
    \                }\n                continue;\n            }\n            call.pop_back();\n\
    \            if (!call.empty()) low[call.back()] = std::min(low[call.back()],\
    \ low[v]);\n            if (low[v] == ord[v]) {\n                // v \u304B\u3089\
    \u4E0B\u306E (\u307E\u3060\u53D6\u308A\u51FA\u3057\u3066\u3044\u306A\u3044) \u9802\
    \u70B9\u304C 1 \u3064\u306E\u6210\u5206\uFF0Ev \u306E\u89AA\u3078\u306E\u8FBA\u306F\
    \u6A4B\n                if (is_bridge && par_edge[v] >= 0) (*is_bridge)[par_edge[v]]\
    \ = 1;\n                int k = groups.size();\n                groups.emplace_back();\n\
    \                while (true) {\n                    int u = stk.back();\n   \
    \                 stk.pop_back();\n                    comp[u] = k, groups[k].push_back(u);\n\
    \                    if (u == v) break;\n                }\n            }\n  \
    \      }\n    }\n    if (comp_out) *comp_out = comp;\n    return groups;\n}\n\
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
    \ 4 \"graph/three_edge_connected_components.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E09\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 (Tsin \u306E\u30D1\
    \u30B9\u5438\u53CE\u6CD5\uFF0C\u975E\u518D\u5E30)\uFF0EO(n + m)\n// \u5404\u9802\
    \u70B9 v \u306B\u3064\u3044\u3066 DFS \u6728\u306E\u4E0B\u306B\u4F38\u3073\u308B\
    \u300Cv \u306E\u30D1\u30B9\u300D(path[v] \u3067\u3064\u306A\u304C\u308B\u9802\u70B9\
    \u306E\u5217) \u3068\uFF0C\n// v \u306E\u6210\u5206\u304B\u3089\u7956\u5148\u3078\
    \u51FA\u3066\u3044\u304F\u8FBA\u306E\u672C\u6570 deg[v] \u3092\u6301\u3064\uFF0E\
    \u5B50\u306E\u6210\u5206\u306E deg \u304C 1 \u4EE5\u4E0B (\u6A4B / 2 \u8FBA\u30AB\
    \u30C3\u30C8) \u306A\u3089\u5207\u308A\u96E2\u3057\uFF0C\n// \u305D\u3046\u3067\
    \u306A\u3051\u308C\u3070\u30D1\u30B9\u3092 v \u306B\u5438\u53CE (\u540C\u3058\u6210\
    \u5206\u3068\u3057\u3066\u4F75\u5408) \u3059\u308B\ninline vector<vector<int>>\
    \ three_edge_connected_components(int n, const vector<pair<int, int>> &edges)\
    \ {\n    int m = edges.size();\n    vector<pair<int, int>> el;\n    el.reserve(2\
    \ * m);\n    for (int i = 0; i < m; i++) {\n        auto [a, b] = edges[i];\n\
    \        if (a == b) continue;\n        el.push_back({a, b}), el.push_back({b,\
    \ a});\n    }\n    CSR<int> g(n, el);\n    const int NONE = n;\n    vector<int>\
    \ in(n, -1), out(n), low(n, NONE), deg(n, 0), path(n, NONE), nxt(n);\n    iota(nxt.begin(),\
    \ nxt.end(), 0);  // \u6210\u5206\u3092\u5DE1\u56DE\u30EA\u30B9\u30C8\u3067\u6301\
    \u3064 (\u4F75\u5408\u306F nxt \u306E\u4EA4\u63DB)\n    auto absorb = [&](int\
    \ v, int w) { swap(nxt[v], nxt[w]), deg[v] += deg[w]; };\n    vector<int> it(n),\
    \ par(n, NONE), call;\n    vector<char> par_used(n, 0);  // \u89AA\u3078\u306E\
    \u8FBA\u3092 1 \u672C\u3060\u3051\u98DB\u3070\u3057\u305F\u304B (\u591A\u91CD\u8FBA\
    \u5BFE\u7B56)\n    int cnt = 0;\n    for (int s = 0; s < n; s++) {\n        if\
    \ (in[s] >= 0) continue;\n        in[s] = cnt++, it[s] = g.start[s], call.push_back(s);\n\
    \        while (!call.empty()) {\n            int v = call.back();\n         \
    \   if (it[v] < g.start[v + 1]) {\n                int w = g.elist[it[v]++];\n\
    \                if (w == par[v] && !par_used[v]) {\n                    par_used[v]\
    \ = 1;\n                    continue;\n                }\n                if (in[w]\
    \ >= 0) {\n                    if (in[w] < in[v]) {  // \u7956\u5148\u3078\u306E\
    \u5F8C\u9000\u8FBA\n                        deg[v]++;\n                      \
    \  low[v] = std::min(low[v], in[w]);\n                    } else {  // \u5B50\u5B6B\
    \u304B\u3089\u306E\u5F8C\u9000\u8FBA: \u305D\u306E\u5B50\u5B6B\u3092\u542B\u3080\
    \u30D1\u30B9\u4E0A\u306E\u9802\u70B9\u3092\u5438\u53CE\n                     \
    \   deg[v]--;\n                        int u = path[v];\n                    \
    \    while (u != NONE && in[u] <= in[w] && in[w] < out[u]) {\n               \
    \             absorb(v, u);\n                            u = path[u];\n      \
    \                  }\n                        path[v] = u;\n                 \
    \   }\n                    continue;\n                }\n                par[w]\
    \ = v, in[w] = cnt++, it[w] = g.start[w];\n                call.push_back(w);\n\
    \                continue;\n            }\n            // v \u306E\u63A2\u7D22\
    \u7D42\u4E86\n            out[v] = cnt;\n            call.pop_back();\n      \
    \      if (call.empty()) break;\n            int p = call.back(), w = v;\n   \
    \         if (path[w] == NONE && deg[w] <= 1) {\n                // w \u306E\u6210\
    \u5206\u306F (p, w) \u3068\u9AD8\u3005 1 \u672C\u306E\u8FBA\u3067\u3057\u304B\u3064\
    \u306A\u304C\u3089\u306A\u3044 \u2192 \u72EC\u7ACB\u3057\u305F\u6210\u5206\n \
    \               deg[p] += deg[w];\n                low[p] = std::min(low[p], low[w]);\n\
    \                continue;\n            } else if (deg[w] == 0) {\n          \
    \      w = path[w];  // w \u81EA\u8EAB\u306F\u5207\u308A\u96E2\u3057\uFF0C\u305D\
    \u306E\u4E0B\u306E\u30D1\u30B9\u3060\u3051\u6B8B\u3059\n            }\n      \
    \      if (low[w] < low[p]) {\n                low[p] = low[w];\n            \
    \    swap(w, path[p]);  // \u3088\u308A\u4E0A\u306B\u5C4A\u304F\u30D1\u30B9\u3092\
    \ p \u306E\u30D1\u30B9\u306B\u3057\uFF0C\u5143\u306E\u30D1\u30B9\u306F\u5438\u53CE\
    \u3059\u308B\n            }\n            while (w != NONE) {\n               \
    \ absorb(p, w);\n                w = path[w];\n            }\n        }\n    }\n\
    \    vector<vector<int>> res;\n    vector<char> vis(n, 0);\n    for (int i = 0;\
    \ i < n; i++) {\n        if (vis[i]) continue;\n        res.emplace_back();\n\
    \        int y = i;\n        do {\n            vis[y] = 1, res.back().push_back(y);\n\
    \            y = nxt[y];\n        } while (y != i);\n    }\n    return res;\n\
    }\n#line 2 \"template.hpp\"\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
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
    \ 4 \"graph/biconnected_components.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3 (\u95A2\u7BC0\
    \u70B9\u3067\u5207\u3063\u305F\u6210\u5206)\uFF0Elowlink + \u8FBA\u306E\u30B9\u30BF\
    \u30C3\u30AF\uFF0C\u975E\u518D\u5E30 DFS \u3067 O(n + m)\n// \u8FD4\u308A\u5024\
    : \u6210\u5206\u3054\u3068\u306E\u9802\u70B9\u306E\u5217 (\u95A2\u7BC0\u70B9\u306F\
    \u8907\u6570\u306E\u6210\u5206\u306B\u5165\u308B\uFF0E\u5B64\u7ACB\u70B9\u306F\
    \ 1 \u9802\u70B9\u306E\u6210\u5206)\n// edge_groups \u3092\u6E21\u3059\u3068\u6210\
    \u5206\u3054\u3068\u306E\u8FBA\u756A\u53F7\u306E\u5217\u3082\u5165\u308B\ninline\
    \ vector<vector<int>> biconnected_components(int n, const vector<pair<int, int>>\
    \ &edges, vector<vector<int>> *edge_groups = nullptr) {\n    int m = edges.size();\n\
    \    vector<pair<int, int>> el;\n    el.reserve(2 * m);\n    for (int i = 0; i\
    \ < m; i++) {\n        if (edges[i].first == edges[i].second) continue;\n    \
    \    el.push_back({edges[i].first, i}), el.push_back({edges[i].second, i});\n\
    \    }\n    CSR<int> g(n, el);\n    vector<int> ord(n, -1), low(n), it(n), par_edge(n,\
    \ -1), call, estk;\n    vector<vector<int>> res;\n    if (edge_groups) edge_groups->clear();\n\
    \    vector<int> mark(n, -1);  // \u6210\u5206\u306B\u5165\u308C\u305F\u9802\u70B9\
    \u306E\u5370 (\u6210\u5206\u756A\u53F7)\n    int now = 0;\n    for (int s = 0;\
    \ s < n; s++) {\n        if (ord[s] >= 0) continue;\n        ord[s] = low[s] =\
    \ now++, it[s] = g.start[s], call.push_back(s);\n        if (g.start[s] == g.start[s\
    \ + 1]) {  // \u5B64\u7ACB\u70B9 (\u81EA\u5DF1\u30EB\u30FC\u30D7\u3060\u3051\u306E\
    \u9802\u70B9\u3082)\n            res.push_back({s});\n            if (edge_groups)\
    \ edge_groups->emplace_back();\n        }\n        while (!call.empty()) {\n \
    \           int v = call.back();\n            if (it[v] < g.start[v + 1]) {\n\
    \                int e = g.elist[it[v]++];\n                if (e == par_edge[v])\
    \ continue;\n                int to = edges[e].first ^ edges[e].second ^ v;\n\
    \                if (ord[to] < 0) {\n                    estk.push_back(e);\n\
    \                    ord[to] = low[to] = now++, it[to] = g.start[to], par_edge[to]\
    \ = e;\n                    call.push_back(to);\n                } else if (ord[to]\
    \ < ord[v]) {\n                    estk.push_back(e);  // \u5F8C\u9000\u8FBA (\u5B50\
    \u5B6B\u304B\u3089\u898B\u305F 1 \u56DE\u3060\u3051\u7A4D\u3080)\n           \
    \         low[v] = std::min(low[v], ord[to]);\n                }\n           \
    \     continue;\n            }\n            call.pop_back();\n            if (call.empty())\
    \ break;\n            int p = call.back();\n            low[p] = std::min(low[p],\
    \ low[v]);\n            if (low[v] >= ord[p]) {\n                // p \u306F\u95A2\
    \u7BC0\u70B9 (\u307E\u305F\u306F\u6839)\uFF0E\u8FBA (p, v) \u307E\u3067\u3092\u30B9\
    \u30BF\u30C3\u30AF\u304B\u3089\u53D6\u308A\u51FA\u3057\u305F\u3082\u306E\u304C\
    \ 1 \u3064\u306E\u6210\u5206\n                int k = res.size();\n          \
    \      res.emplace_back();\n                if (edge_groups) edge_groups->emplace_back();\n\
    \                while (true) {\n                    int e = estk.back();\n  \
    \                  estk.pop_back();\n                    if (edge_groups) (*edge_groups)[k].push_back(e);\n\
    \                    for (int x : {edges[e].first, edges[e].second})\n       \
    \                 if (mark[x] != k) mark[x] = k, res[k].push_back(x);\n      \
    \              if (e == par_edge[v]) break;\n                }\n            }\n\
    \        }\n    }\n    return res;\n}\n#line 2 \"template.hpp\"\nusing namespace\
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
    \ 4 \"graph/complement_graph_components.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3\uFF0E\
    O(n + m)\n// \u307E\u3060\u3069\u306E\u6210\u5206\u306B\u3082\u5165\u3063\u3066\
    \u3044\u306A\u3044\u9802\u70B9\u3092\u9023\u7D50\u30EA\u30B9\u30C8\u3067\u6301\
    \u3061\uFF0CBFS \u3067\u9802\u70B9 v \u304B\u3089\u300Cv \u3068\u5143\u306E\u30B0\
    \u30E9\u30D5\u3067\u96A3\u63A5\u3057\u3066\u3044\u306A\u3044\u672A\u8A2A\u554F\
    \u9802\u70B9\u300D\u3092\u5168\u90E8\u53D6\u308B\uFF0E\n// \u672A\u8A2A\u554F\u30EA\
    \u30B9\u30C8\u3092 1 \u5468\u3059\u308B\u3068\u304D\uFF0C\u53D6\u3089\u306A\u304B\
    \u3063\u305F\u9802\u70B9\u306F v \u306E\u96A3\u63A5\u9802\u70B9\u306A\u306E\u3067\
    \uFF0C1 \u5468\u306E\u30B3\u30B9\u30C8\u306F deg(v) + (\u53D6\u3063\u305F\u6570\
    ) \u3067\u6291\u3048\u3089\u308C\u308B\ninline vector<vector<int>> complement_graph_components(int\
    \ n, const vector<pair<int, int>> &edges) {\n    vector<pair<int, int>> el;\n\
    \    el.reserve(2 * edges.size());\n    for (auto [a, b] : edges) el.push_back({a,\
    \ b}), el.push_back({b, a});\n    CSR<int> g(n, el);\n    // \u672A\u8A2A\u554F\
    \u9802\u70B9\u306E\u53CC\u65B9\u5411\u30EA\u30B9\u30C8 (\u756A\u5175 n)\n    vector<int>\
    \ nx(n + 1), pv(n + 1);\n    for (int i = 0; i <= n; i++) nx[i] = (i + 1) % (n\
    \ + 1), pv[i] = (i + n) % (n + 1);\n    auto erase = [&](int v) { nx[pv[v]] =\
    \ nx[v], pv[nx[v]] = pv[v]; };\n    vector<int> stamp(n, -1), que;\n    que.reserve(n);\n\
    \    vector<vector<int>> res;\n    while (nx[n] != n) {\n        int s = nx[n];\n\
    \        erase(s);\n        que.clear(), que.push_back(s);\n        for (size_t\
    \ h = 0; h < que.size(); h++) {\n            int v = que[h];\n            for\
    \ (int i = g.start[v]; i < g.start[v + 1]; i++) stamp[g.elist[i]] = v;\n     \
    \       for (int u = nx[n]; u != n;) {\n                int nu = nx[u];\n    \
    \            if (stamp[u] != v) erase(u), que.push_back(u);\n                u\
    \ = nu;\n            }\n        }\n        res.push_back(que);\n    }\n    return\
    \ res;\n}\n#line 2 \"template.hpp\"\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
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
    \ 4 \"graph/eulerian_trail.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u30AA\u30A4\u30E9\u30FC\u8DEF (\u5168\u3066\u306E\u8FBA\u3092\u3061\u3087\
    \u3046\u3069 1 \u56DE\u305A\u3064\u901A\u308B\u8DEF)\uFF0EHierholzer \u6CD5\uFF0C\
    \u975E\u518D\u5E30\u3067 O(n + m)\n// \u8FD4\u308A\u5024: {\u9802\u70B9\u306E\u5217\
    \ (m+1 \u500B), \u8FBA\u756A\u53F7\u306E\u5217 (m \u500B)}\uFF0E\u5B58\u5728\u3057\
    \u306A\u3051\u308C\u3070\u7A7A\u306E pair\n// \u8FBA\u304C\u306A\u3044\u3068\u304D\
    \u306F {{0}, {}} (\u9802\u70B9 0 \u304B\u3089\u9577\u3055 0 \u306E\u8DEF)\n//\
    \ DIRECTED = true \u306A\u3089\u6709\u5411\u30B0\u30E9\u30D5\uFF0Cfalse \u306A\
    \u3089\u7121\u5411\u30B0\u30E9\u30D5\n\ntemplate <bool DIRECTED>\npair<vector<int>,\
    \ vector<int>> eulerian_trail(int n, const vector<pair<int, int>> &edges) {\n\
    \    int m = edges.size();\n    if (m == 0) return {{0}, {}};\n    vector<int>\
    \ deg(n, 0);  // \u6709\u5411: \u51FA\u6B21\u6570 - \u5165\u6B21\u6570\uFF0C\u7121\
    \u5411: \u6B21\u6570\n    vector<pair<int, int>> el;\n    el.reserve(DIRECTED\
    \ ? m : 2 * m);\n    for (int i = 0; i < m; i++) {\n        auto [a, b] = edges[i];\n\
    \        el.push_back({a, i});\n        if (DIRECTED) deg[a]++, deg[b]--;\n  \
    \      else {\n            el.push_back({b, i});\n            deg[a]++, deg[b]++;\n\
    \        }\n    }\n    // \u59CB\u70B9: \u6709\u5411\u306A\u3089 \u51FA - \u5165\
    \ = 1 \u306E\u9802\u70B9\uFF0C\u7121\u5411\u306A\u3089\u6B21\u6570\u304C\u5947\
    \u6570\u306E\u9802\u70B9\uFF0E\u306A\u3051\u308C\u3070\u8FBA\u3092\u6301\u3064\
    \u9802\u70B9\n    int s = edges[0].first, odd = 0;\n    for (int v = 0; v < n;\
    \ v++) {\n        if (DIRECTED) {\n            if (deg[v] == 1) s = v, odd++;\n\
    \            else if (deg[v] != 0 && deg[v] != -1) return {};\n            else\
    \ if (deg[v] == -1) odd++;\n        } else if (deg[v] & 1) {\n            if (odd\
    \ == 0) s = v;\n            odd++;\n        }\n    }\n    if (odd > 2) return\
    \ {};\n    CSR<int> g(n, el);\n    vector<int> it(g.start.begin(), g.start.end()\
    \ - 1);\n    vector<char> used(m, 0);\n    vector<int> vs, es;\n    vs.reserve(m\
    \ + 1), es.reserve(m);\n    // \u30B9\u30BF\u30C3\u30AF\u306B\u306F (\u9802\u70B9\
    , \u305D\u3053\u3078\u6765\u305F\u8FBA)\n    vector<pair<int, int>> stk{{s, -1}};\n\
    \    while (!stk.empty()) {\n        auto [v, ein] = stk.back();\n        int\
    \ &i = it[v];\n        while (i < g.start[v + 1] && used[g.elist[i]]) i++;\n \
    \       if (i == g.start[v + 1]) {\n            vs.push_back(v);\n           \
    \ if (ein >= 0) es.push_back(ein);\n            stk.pop_back();\n            continue;\n\
    \        }\n        int e = g.elist[i++];\n        used[e] = 1;\n        int to\
    \ = DIRECTED ? edges[e].second : edges[e].first ^ edges[e].second ^ v;\n     \
    \   stk.push_back({to, e});\n    }\n    if ((int)es.size() != m) return {};  //\
    \ \u9023\u7D50\u3067\u306A\u3044\n    reverse(vs.begin(), vs.end()), reverse(es.begin(),\
    \ es.end());\n    return {vs, es};\n}\n#line 10 \"test/unittest/graph_components.test.cpp\"\
    \n\n// \u9589\u8DEF\u691C\u51FA\u30FBSCC\u30FB\u4E8C\u91CD\u8FBA\u9023\u7D50\u30FB\
    \u4E09\u91CD\u8FBA\u9023\u7D50\u30FB\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u30FB\
    \u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u30FB\u30AA\u30A4\u30E9\
    \u30FC\u8DEF\u3092\n// \u5C0F\u3055\u3044\u30E9\u30F3\u30C0\u30E0\u30B0\u30E9\u30D5\
    \ (\u591A\u91CD\u8FBA\u30FB\u81EA\u5DF1\u30EB\u30FC\u30D7\u3042\u308A) \u3067\u611A\
    \u76F4\u3068\u7167\u5408\u3059\u308B\n\nusing Edges = vector<pair<int, int>>;\n\
    \n// removed[e] \u306E\u8FBA\u3092\u9664\u3044\u305F\u7121\u5411\u30B0\u30E9\u30D5\
    \u306E\u9023\u7D50\u6210\u5206\u756A\u53F7\nvector<int> undirected_cc(int n, const\
    \ Edges &es, const vector<char> &removed) {\n    vector<int> p(n);\n    iota(p.begin(),\
    \ p.end(), 0);\n    auto f = [&](auto self, int x) -> int { return p[x] == x ?\
    \ x : p[x] = self(self, p[x]); };\n    for (int i = 0; i < (int)es.size(); i++)\n\
    \        if (!removed[i]) p[f(f, es[i].first)] = f(f, es[i].second);\n    vector<int>\
    \ c(n);\n    for (int i = 0; i < n; i++) c[i] = f(f, i);\n    return c;\n}\n\n\
    // \u9802\u70B9\u306E\u5206\u5272\u3092\u6B63\u898F\u5316 (\u5404\u96C6\u5408\u3092\
    \u30BD\u30FC\u30C8\u3057\u3066\u5168\u4F53\u3092\u30BD\u30FC\u30C8)\nvector<vector<int>>\
    \ normalize(vector<vector<int>> g) {\n    for (auto &x : g) sort(x.begin(), x.end());\n\
    \    sort(g.begin(), g.end());\n    return g;\n}\n\nint main() {\n    mt19937_64\
    \ rng(31);\n    for (int it = 0; it < 3000; it++) {\n        int n = rng() % 7\
    \ + 1, m = rng() % 9;\n        Edges es(m);\n        for (auto &[a, b] : es) a\
    \ = rng() % n, b = rng() % n;\n        // \u6709\u5411: \u5230\u9054\u53EF\u80FD\
    \u6027\n        vector<vector<char>> reach(n, vector<char>(n, 0));\n        for\
    \ (int i = 0; i < n; i++) reach[i][i] = 1;\n        for (auto [a, b] : es) reach[a][b]\
    \ = 1;\n        for (int k = 0; k < n; k++)\n            for (int i = 0; i < n;\
    \ i++)\n                for (int j = 0; j < n; j++) reach[i][j] |= reach[i][k]\
    \ && reach[k][j];\n        // \u6709\u5411\u9589\u8DEF\n        {\n          \
    \  bool has = false;\n            for (auto [a, b] : es) has |= reach[b][a];\n\
    \            auto cyc = find_cycle_directed(n, es);\n            assert(has ==\
    \ !cyc.empty());\n            if (!cyc.empty()) {\n                set<int> used(cyc.begin(),\
    \ cyc.end());\n                assert(used.size() == cyc.size());\n          \
    \      for (size_t i = 0; i < cyc.size(); i++) assert(es[cyc[i]].second == es[cyc[(i\
    \ + 1) % cyc.size()]].first);\n            }\n        }\n        // SCC\n    \
    \    {\n            StronglyConnectedComponents scc(n);\n            for (auto\
    \ [a, b] : es) scc.add_edge(a, b);\n            scc.build();\n            for\
    \ (int i = 0; i < n; i++)\n                for (int j = 0; j < n; j++) assert((scc.comp[i]\
    \ == scc.comp[j]) == (reach[i][j] && reach[j][i]));\n            for (auto [a,\
    \ b] : es) assert(scc.comp[a] <= scc.comp[b]);\n            for (int k = 0; k\
    \ < (int)scc.groups.size(); k++)\n                for (int v : scc.groups[k])\
    \ assert(scc.comp[v] == k);\n        }\n        // \u7121\u5411\u9589\u8DEF (\u68EE\
    \u3067\u306A\u3044\u304B)\n        {\n            vector<char> none(m, 0);\n \
    \           auto c = undirected_cc(n, es, none);\n            set<int> comps(c.begin(),\
    \ c.end());\n            bool has = m > n - (int)comps.size();\n            auto\
    \ [vs, ecs] = find_cycle_undirected(n, es);\n            assert(has == !ecs.empty());\n\
    \            if (!ecs.empty()) {\n                int L = vs.size();\n       \
    \         assert((int)ecs.size() == L && set<int>(vs.begin(), vs.end()).size()\
    \ == vs.size() && set<int>(ecs.begin(), ecs.end()).size() == ecs.size());\n  \
    \              for (int i = 0; i < L; i++) {\n                    auto [a, b]\
    \ = es[ecs[i]];\n                    int x = vs[i], y = vs[(i + 1) % L];\n   \
    \                 assert((a == x && b == y) || (a == y && b == x));\n        \
    \        }\n            }\n        }\n        // \u4E8C\u91CD\u8FBA\u9023\u7D50\
    \u30FB\u4E09\u91CD\u8FBA\u9023\u7D50: k \u672C\u672A\u6E80\u306E\u8FBA\u3092\u9664\
    \u3044\u3066\u975E\u9023\u7D50\u306B\u3067\u304D\u306A\u3044\u304B\n        for\
    \ (int k : {2, 3}) {\n            vector<vector<char>> same(n, vector<char>(n,\
    \ 1));\n            vector<char> rem(m, 0);\n            auto check = [&]() {\n\
    \                auto c = undirected_cc(n, es, rem);\n                for (int\
    \ i = 0; i < n; i++)\n                    for (int j = 0; j < n; j++)\n      \
    \                  if (c[i] != c[j]) same[i][j] = 0;\n            };\n       \
    \     check();\n            for (int a = 0; a < m; a++) {\n                rem[a]\
    \ = 1, check();\n                if (k == 3)\n                    for (int b =\
    \ a + 1; b < m; b++) rem[b] = 1, check(), rem[b] = 0;\n                rem[a]\
    \ = 0;\n            }\n            auto groups = k == 2 ? two_edge_connected_components(n,\
    \ es) : three_edge_connected_components(n, es);\n            vector<int> gid(n,\
    \ -1);\n            for (int g = 0; g < (int)groups.size(); g++)\n           \
    \     for (int v : groups[g]) assert(gid[v] < 0), gid[v] = g;\n            for\
    \ (int i = 0; i < n; i++)\n                for (int j = 0; j < n; j++) assert((gid[i]\
    \ == gid[j]) == (bool)same[i][j]);\n        }\n        // \u4E8C\u91CD\u9802\u70B9\
    \u9023\u7D50: \u5358\u7D14\u9589\u8DEF\u3092\u5168\u5217\u6319\u3057\uFF0C\u540C\
    \u3058\u9589\u8DEF\u306B\u4E57\u308B\u8FBA\u3092\u4F75\u5408\n        {\n    \
    \        vector<int> p(m);\n            iota(p.begin(), p.end(), 0);\n       \
    \     auto f = [&](auto self, int x) -> int { return p[x] == x ? x : p[x] = self(self,\
    \ p[x]); };\n            vector<char> onv(n, 0);\n            vector<int> path;\n\
    \            // \u9802\u70B9 s \u3092\u6700\u5C0F\u3068\u3059\u308B\u5358\u7D14\
    \u9589\u8DEF\u3092\u8FBA\u306E\u5217\u3067\u5217\u6319\n            auto dfs =\
    \ [&](auto self, int s, int v) -> void {\n                for (int e = 0; e <\
    \ m; e++) {\n                    auto [a, b] = es[e];\n                    if\
    \ (a == b) continue;\n                    if (a != v && b != v) continue;\n  \
    \                  if (!path.empty() && path.back() == e) continue;\n        \
    \            int to = a ^ b ^ v;\n                    if (to == s && !path.empty())\
    \ {\n                        if (path.size() == 1 && path[0] == e) continue;\n\
    \                        for (int x : path) p[f(f, x)] = f(f, e);\n          \
    \              continue;\n                    }\n                    if (to <\
    \ s || onv[to]) continue;\n                    onv[to] = 1, path.push_back(e);\n\
    \                    self(self, s, to);\n                    onv[to] = 0, path.pop_back();\n\
    \                }\n            };\n            for (int s = 0; s < n; s++) onv[s]\
    \ = 1, dfs(dfs, s, s), onv[s] = 0;\n            map<int, set<int>> blocks;\n \
    \           vector<char> has_edge(n, 0);\n            for (int e = 0; e < m; e++)\
    \ {\n                auto [a, b] = es[e];\n                if (a == b) continue;\n\
    \                blocks[f(f, e)].insert(a), blocks[f(f, e)].insert(b);\n     \
    \           has_edge[a] = has_edge[b] = 1;\n            }\n            vector<vector<int>>\
    \ exp;\n            for (auto &[k2, st] : blocks) exp.push_back(vector<int>(st.begin(),\
    \ st.end()));\n            for (int v = 0; v < n; v++)\n                if (!has_edge[v])\
    \ exp.push_back({v});\n            assert(normalize(biconnected_components(n,\
    \ es)) == normalize(exp));\n        }\n        // \u88DC\u30B0\u30E9\u30D5 (\u5358\
    \u7D14\u30B0\u30E9\u30D5\u306B\u3057\u3066\u304B\u3089)\n        {\n         \
    \   set<pair<int, int>> st;\n            for (auto [a, b] : es)\n            \
    \    if (a != b) st.insert({min(a, b), max(a, b)});\n            Edges simple(st.begin(),\
    \ st.end());\n            vector<vector<char>> adj(n, vector<char>(n, 0));\n \
    \           for (auto [a, b] : simple) adj[a][b] = adj[b][a] = 1;\n          \
    \  Edges comp_edges;\n            for (int i = 0; i < n; i++)\n              \
    \  for (int j = i + 1; j < n; j++)\n                    if (!adj[i][j]) comp_edges.push_back({i,\
    \ j});\n            auto c = undirected_cc(n, comp_edges, vector<char>(comp_edges.size(),\
    \ 0));\n            map<int, vector<int>> mp;\n            for (int i = 0; i <\
    \ n; i++) mp[c[i]].push_back(i);\n            vector<vector<int>> exp;\n     \
    \       for (auto &[k2, v] : mp) exp.push_back(v);\n            assert(normalize(complement_graph_components(n,\
    \ simple)) == normalize(exp));\n        }\n        // \u30AA\u30A4\u30E9\u30FC\
    \u8DEF (\u6709\u5411\u30FB\u7121\u5411)\uFF0E\u8FBA\u306E\u9806\u5217\u3092\u5168\
    \u90E8\u8A66\u3059\u611A\u76F4 (m <= 6)\n        if (m <= 6) {\n            for\
    \ (int dir = 0; dir < 2; dir++) {\n                vector<int> perm(m);\n    \
    \            iota(perm.begin(), perm.end(), 0);\n                bool exists =\
    \ false;\n                do {\n                    // \u7121\u5411\u306F\u5404\
    \u8FBA\u306E\u5411\u304D\u3082\u8A66\u3059\n                    for (int mask\
    \ = 0; mask < (dir ? 1 : (1 << m)) && !exists; mask++) {\n                   \
    \     bool ok = true;\n                        int cur = -1;\n               \
    \         for (int i = 0; i < m && ok; i++) {\n                            auto\
    \ [a, b] = es[perm[i]];\n                            if (mask >> i & 1) swap(a,\
    \ b);\n                            if (cur >= 0 && a != cur) ok = false;\n   \
    \                         cur = b;\n                        }\n              \
    \          exists |= ok;\n                    }\n                } while (!exists\
    \ && next_permutation(perm.begin(), perm.end()));\n                auto [vs, ecs]\
    \ = dir ? eulerian_trail<true>(n, es) : eulerian_trail<false>(n, es);\n      \
    \          assert(exists == !vs.empty() || m == 0);\n                if (!vs.empty())\
    \ {\n                    assert((int)vs.size() == m + 1 && (int)ecs.size() ==\
    \ m);\n                    assert(set<int>(ecs.begin(), ecs.end()).size() == ecs.size());\n\
    \                    for (int i = 0; i < m; i++) {\n                        auto\
    \ [a, b] = es[ecs[i]];\n                        if (dir) assert(a == vs[i] &&\
    \ b == vs[i + 1]);\n                        else assert((a == vs[i] && b == vs[i\
    \ + 1]) || (b == vs[i] && a == vs[i + 1]));\n                    }\n         \
    \       }\n            }\n        }\n    }\n    long long a_, b_;\n    fin >>\
    \ a_ >> b_;\n    fout << a_ + b_ << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../io/fastio.hpp\"\
    \n#include \"../../graph/cycle_detection.hpp\"\n#include \"../../graph/scc.hpp\"\
    \n#include \"../../graph/two_edge_connected_components.hpp\"\n#include \"../../graph/three_edge_connected_components.hpp\"\
    \n#include \"../../graph/biconnected_components.hpp\"\n#include \"../../graph/complement_graph_components.hpp\"\
    \n#include \"../../graph/eulerian_trail.hpp\"\n\n// \u9589\u8DEF\u691C\u51FA\u30FB\
    SCC\u30FB\u4E8C\u91CD\u8FBA\u9023\u7D50\u30FB\u4E09\u91CD\u8FBA\u9023\u7D50\u30FB\
    \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u30FB\u88DC\u30B0\u30E9\u30D5\u306E\u9023\
    \u7D50\u6210\u5206\u30FB\u30AA\u30A4\u30E9\u30FC\u8DEF\u3092\n// \u5C0F\u3055\u3044\
    \u30E9\u30F3\u30C0\u30E0\u30B0\u30E9\u30D5 (\u591A\u91CD\u8FBA\u30FB\u81EA\u5DF1\
    \u30EB\u30FC\u30D7\u3042\u308A) \u3067\u611A\u76F4\u3068\u7167\u5408\u3059\u308B\
    \n\nusing Edges = vector<pair<int, int>>;\n\n// removed[e] \u306E\u8FBA\u3092\u9664\
    \u3044\u305F\u7121\u5411\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u756A\
    \u53F7\nvector<int> undirected_cc(int n, const Edges &es, const vector<char> &removed)\
    \ {\n    vector<int> p(n);\n    iota(p.begin(), p.end(), 0);\n    auto f = [&](auto\
    \ self, int x) -> int { return p[x] == x ? x : p[x] = self(self, p[x]); };\n \
    \   for (int i = 0; i < (int)es.size(); i++)\n        if (!removed[i]) p[f(f,\
    \ es[i].first)] = f(f, es[i].second);\n    vector<int> c(n);\n    for (int i =\
    \ 0; i < n; i++) c[i] = f(f, i);\n    return c;\n}\n\n// \u9802\u70B9\u306E\u5206\
    \u5272\u3092\u6B63\u898F\u5316 (\u5404\u96C6\u5408\u3092\u30BD\u30FC\u30C8\u3057\
    \u3066\u5168\u4F53\u3092\u30BD\u30FC\u30C8)\nvector<vector<int>> normalize(vector<vector<int>>\
    \ g) {\n    for (auto &x : g) sort(x.begin(), x.end());\n    sort(g.begin(), g.end());\n\
    \    return g;\n}\n\nint main() {\n    mt19937_64 rng(31);\n    for (int it =\
    \ 0; it < 3000; it++) {\n        int n = rng() % 7 + 1, m = rng() % 9;\n     \
    \   Edges es(m);\n        for (auto &[a, b] : es) a = rng() % n, b = rng() % n;\n\
    \        // \u6709\u5411: \u5230\u9054\u53EF\u80FD\u6027\n        vector<vector<char>>\
    \ reach(n, vector<char>(n, 0));\n        for (int i = 0; i < n; i++) reach[i][i]\
    \ = 1;\n        for (auto [a, b] : es) reach[a][b] = 1;\n        for (int k =\
    \ 0; k < n; k++)\n            for (int i = 0; i < n; i++)\n                for\
    \ (int j = 0; j < n; j++) reach[i][j] |= reach[i][k] && reach[k][j];\n       \
    \ // \u6709\u5411\u9589\u8DEF\n        {\n            bool has = false;\n    \
    \        for (auto [a, b] : es) has |= reach[b][a];\n            auto cyc = find_cycle_directed(n,\
    \ es);\n            assert(has == !cyc.empty());\n            if (!cyc.empty())\
    \ {\n                set<int> used(cyc.begin(), cyc.end());\n                assert(used.size()\
    \ == cyc.size());\n                for (size_t i = 0; i < cyc.size(); i++) assert(es[cyc[i]].second\
    \ == es[cyc[(i + 1) % cyc.size()]].first);\n            }\n        }\n       \
    \ // SCC\n        {\n            StronglyConnectedComponents scc(n);\n       \
    \     for (auto [a, b] : es) scc.add_edge(a, b);\n            scc.build();\n \
    \           for (int i = 0; i < n; i++)\n                for (int j = 0; j < n;\
    \ j++) assert((scc.comp[i] == scc.comp[j]) == (reach[i][j] && reach[j][i]));\n\
    \            for (auto [a, b] : es) assert(scc.comp[a] <= scc.comp[b]);\n    \
    \        for (int k = 0; k < (int)scc.groups.size(); k++)\n                for\
    \ (int v : scc.groups[k]) assert(scc.comp[v] == k);\n        }\n        // \u7121\
    \u5411\u9589\u8DEF (\u68EE\u3067\u306A\u3044\u304B)\n        {\n            vector<char>\
    \ none(m, 0);\n            auto c = undirected_cc(n, es, none);\n            set<int>\
    \ comps(c.begin(), c.end());\n            bool has = m > n - (int)comps.size();\n\
    \            auto [vs, ecs] = find_cycle_undirected(n, es);\n            assert(has\
    \ == !ecs.empty());\n            if (!ecs.empty()) {\n                int L =\
    \ vs.size();\n                assert((int)ecs.size() == L && set<int>(vs.begin(),\
    \ vs.end()).size() == vs.size() && set<int>(ecs.begin(), ecs.end()).size() ==\
    \ ecs.size());\n                for (int i = 0; i < L; i++) {\n              \
    \      auto [a, b] = es[ecs[i]];\n                    int x = vs[i], y = vs[(i\
    \ + 1) % L];\n                    assert((a == x && b == y) || (a == y && b ==\
    \ x));\n                }\n            }\n        }\n        // \u4E8C\u91CD\u8FBA\
    \u9023\u7D50\u30FB\u4E09\u91CD\u8FBA\u9023\u7D50: k \u672C\u672A\u6E80\u306E\u8FBA\
    \u3092\u9664\u3044\u3066\u975E\u9023\u7D50\u306B\u3067\u304D\u306A\u3044\u304B\
    \n        for (int k : {2, 3}) {\n            vector<vector<char>> same(n, vector<char>(n,\
    \ 1));\n            vector<char> rem(m, 0);\n            auto check = [&]() {\n\
    \                auto c = undirected_cc(n, es, rem);\n                for (int\
    \ i = 0; i < n; i++)\n                    for (int j = 0; j < n; j++)\n      \
    \                  if (c[i] != c[j]) same[i][j] = 0;\n            };\n       \
    \     check();\n            for (int a = 0; a < m; a++) {\n                rem[a]\
    \ = 1, check();\n                if (k == 3)\n                    for (int b =\
    \ a + 1; b < m; b++) rem[b] = 1, check(), rem[b] = 0;\n                rem[a]\
    \ = 0;\n            }\n            auto groups = k == 2 ? two_edge_connected_components(n,\
    \ es) : three_edge_connected_components(n, es);\n            vector<int> gid(n,\
    \ -1);\n            for (int g = 0; g < (int)groups.size(); g++)\n           \
    \     for (int v : groups[g]) assert(gid[v] < 0), gid[v] = g;\n            for\
    \ (int i = 0; i < n; i++)\n                for (int j = 0; j < n; j++) assert((gid[i]\
    \ == gid[j]) == (bool)same[i][j]);\n        }\n        // \u4E8C\u91CD\u9802\u70B9\
    \u9023\u7D50: \u5358\u7D14\u9589\u8DEF\u3092\u5168\u5217\u6319\u3057\uFF0C\u540C\
    \u3058\u9589\u8DEF\u306B\u4E57\u308B\u8FBA\u3092\u4F75\u5408\n        {\n    \
    \        vector<int> p(m);\n            iota(p.begin(), p.end(), 0);\n       \
    \     auto f = [&](auto self, int x) -> int { return p[x] == x ? x : p[x] = self(self,\
    \ p[x]); };\n            vector<char> onv(n, 0);\n            vector<int> path;\n\
    \            // \u9802\u70B9 s \u3092\u6700\u5C0F\u3068\u3059\u308B\u5358\u7D14\
    \u9589\u8DEF\u3092\u8FBA\u306E\u5217\u3067\u5217\u6319\n            auto dfs =\
    \ [&](auto self, int s, int v) -> void {\n                for (int e = 0; e <\
    \ m; e++) {\n                    auto [a, b] = es[e];\n                    if\
    \ (a == b) continue;\n                    if (a != v && b != v) continue;\n  \
    \                  if (!path.empty() && path.back() == e) continue;\n        \
    \            int to = a ^ b ^ v;\n                    if (to == s && !path.empty())\
    \ {\n                        if (path.size() == 1 && path[0] == e) continue;\n\
    \                        for (int x : path) p[f(f, x)] = f(f, e);\n          \
    \              continue;\n                    }\n                    if (to <\
    \ s || onv[to]) continue;\n                    onv[to] = 1, path.push_back(e);\n\
    \                    self(self, s, to);\n                    onv[to] = 0, path.pop_back();\n\
    \                }\n            };\n            for (int s = 0; s < n; s++) onv[s]\
    \ = 1, dfs(dfs, s, s), onv[s] = 0;\n            map<int, set<int>> blocks;\n \
    \           vector<char> has_edge(n, 0);\n            for (int e = 0; e < m; e++)\
    \ {\n                auto [a, b] = es[e];\n                if (a == b) continue;\n\
    \                blocks[f(f, e)].insert(a), blocks[f(f, e)].insert(b);\n     \
    \           has_edge[a] = has_edge[b] = 1;\n            }\n            vector<vector<int>>\
    \ exp;\n            for (auto &[k2, st] : blocks) exp.push_back(vector<int>(st.begin(),\
    \ st.end()));\n            for (int v = 0; v < n; v++)\n                if (!has_edge[v])\
    \ exp.push_back({v});\n            assert(normalize(biconnected_components(n,\
    \ es)) == normalize(exp));\n        }\n        // \u88DC\u30B0\u30E9\u30D5 (\u5358\
    \u7D14\u30B0\u30E9\u30D5\u306B\u3057\u3066\u304B\u3089)\n        {\n         \
    \   set<pair<int, int>> st;\n            for (auto [a, b] : es)\n            \
    \    if (a != b) st.insert({min(a, b), max(a, b)});\n            Edges simple(st.begin(),\
    \ st.end());\n            vector<vector<char>> adj(n, vector<char>(n, 0));\n \
    \           for (auto [a, b] : simple) adj[a][b] = adj[b][a] = 1;\n          \
    \  Edges comp_edges;\n            for (int i = 0; i < n; i++)\n              \
    \  for (int j = i + 1; j < n; j++)\n                    if (!adj[i][j]) comp_edges.push_back({i,\
    \ j});\n            auto c = undirected_cc(n, comp_edges, vector<char>(comp_edges.size(),\
    \ 0));\n            map<int, vector<int>> mp;\n            for (int i = 0; i <\
    \ n; i++) mp[c[i]].push_back(i);\n            vector<vector<int>> exp;\n     \
    \       for (auto &[k2, v] : mp) exp.push_back(v);\n            assert(normalize(complement_graph_components(n,\
    \ simple)) == normalize(exp));\n        }\n        // \u30AA\u30A4\u30E9\u30FC\
    \u8DEF (\u6709\u5411\u30FB\u7121\u5411)\uFF0E\u8FBA\u306E\u9806\u5217\u3092\u5168\
    \u90E8\u8A66\u3059\u611A\u76F4 (m <= 6)\n        if (m <= 6) {\n            for\
    \ (int dir = 0; dir < 2; dir++) {\n                vector<int> perm(m);\n    \
    \            iota(perm.begin(), perm.end(), 0);\n                bool exists =\
    \ false;\n                do {\n                    // \u7121\u5411\u306F\u5404\
    \u8FBA\u306E\u5411\u304D\u3082\u8A66\u3059\n                    for (int mask\
    \ = 0; mask < (dir ? 1 : (1 << m)) && !exists; mask++) {\n                   \
    \     bool ok = true;\n                        int cur = -1;\n               \
    \         for (int i = 0; i < m && ok; i++) {\n                            auto\
    \ [a, b] = es[perm[i]];\n                            if (mask >> i & 1) swap(a,\
    \ b);\n                            if (cur >= 0 && a != cur) ok = false;\n   \
    \                         cur = b;\n                        }\n              \
    \          exists |= ok;\n                    }\n                } while (!exists\
    \ && next_permutation(perm.begin(), perm.end()));\n                auto [vs, ecs]\
    \ = dir ? eulerian_trail<true>(n, es) : eulerian_trail<false>(n, es);\n      \
    \          assert(exists == !vs.empty() || m == 0);\n                if (!vs.empty())\
    \ {\n                    assert((int)vs.size() == m + 1 && (int)ecs.size() ==\
    \ m);\n                    assert(set<int>(ecs.begin(), ecs.end()).size() == ecs.size());\n\
    \                    for (int i = 0; i < m; i++) {\n                        auto\
    \ [a, b] = es[ecs[i]];\n                        if (dir) assert(a == vs[i] &&\
    \ b == vs[i + 1]);\n                        else assert((a == vs[i] && b == vs[i\
    \ + 1]) || (b == vs[i] && a == vs[i + 1]));\n                    }\n         \
    \       }\n            }\n        }\n    }\n    long long a_, b_;\n    fin >>\
    \ a_ >> b_;\n    fout << a_ + b_ << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - io/fastio.hpp
  - template.hpp
  - graph/cycle_detection.hpp
  - template.hpp
  - graph/csr.hpp
  - graph/scc.hpp
  - graph/two_edge_connected_components.hpp
  - graph/three_edge_connected_components.hpp
  - graph/biconnected_components.hpp
  - graph/complement_graph_components.hpp
  - graph/eulerian_trail.hpp
  isVerificationFile: true
  path: test/unittest/graph_components.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unittest/graph_components.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/graph_components.test.cpp
- /verify/test/unittest/graph_components.test.cpp.html
title: test/unittest/graph_components.test.cpp
---
