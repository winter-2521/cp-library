---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/static_rectangle_sum.hpp
    title: "\u9577\u65B9\u5F62\u306E\u4E2D\u306E\u70B9\u306E\u91CD\u307F\u306E\u548C\
      \ (Rectangle Sum)"
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
  bundledCode: "#line 1 \"test/unittest/static_rectangle_sum.test.cpp\"\n#define PROBLEM\
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
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 3 \"data_structure/static_rectangle_sum.hpp\"\
    \n\n// \u9759\u7684\u306A\u91CD\u307F\u4ED8\u304D\u70B9\u306E\u9577\u65B9\u5F62\
    \u548C (Rectangle Sum)\uFF0E\u30AA\u30F3\u30E9\u30A4\u30F3\n// \u70B9\u3092 x\
    \ \u3067\u30BD\u30FC\u30C8\u3057\uFF0Cy (\u5EA7\u6A19\u5727\u7E2E) \u306E\u5217\
    \u3092\u91CD\u307F\u4ED8\u304D\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\
    \u5217\u3067\u6301\u3064\uFF0E\u69CB\u7BC9 O(n log n)\uFF0C\u30AF\u30A8\u30EA\
    \ O(log n)\n// X: \u5EA7\u6A19\u306E\u578B\uFF0CW: \u91CD\u307F\u306E\u578B\n\
    template <class X, class W>\nstruct StaticRectangleSum {\n    // 64 bit \u3054\
    \u3068\u306B\uFF0C\u30D3\u30C3\u30C8\u5217\u3068\u305D\u308C\u3088\u308A\u524D\
    \u306E 1 \u306E\u500B\u6570\u3092\u307E\u3068\u3081\u3066\u6301\u3064\n    struct\
    \ BitVector {\n        struct Block {\n            uint64_t bits;\n          \
    \  int cnt;\n        };\n        vector<Block> b;\n        void init(int n) {\
    \ b.assign((n >> 6) + 1, {0, 0}); }\n        void set(int i) { b[i >> 6].bits\
    \ |= 1ULL << (i & 63); }\n        void build() {\n            for (size_t i =\
    \ 1; i < b.size(); i++) b[i].cnt = b[i - 1].cnt + __builtin_popcountll(b[i - 1].bits);\n\
    \        }\n        int rank1(int i) const {\n            const Block &x = b[i\
    \ >> 6];\n            return x.cnt + __builtin_popcountll(x.bits & ((1ULL << (i\
    \ & 63)) - 1));\n        }\n    };\n\n    int n, lg;\n    vector<X> xs, ys;  \
    \         // xs: \u70B9\u306E x (\u6607\u9806)\uFF0Cys: y \u306E\u7A2E\u985E (\u6607\
    \u9806)\n    vector<BitVector> bv;\n    vector<int> zeros;\n    vector<vector<W>>\
    \ sum;      // sum[h][i]: \u6BB5 h \u3067\u632F\u308A\u5206\u3051\u305F\u5F8C\u306E\
    \u5217\u306E\u5148\u982D i \u500B\u306E\u91CD\u307F\u306E\u548C\n\n    StaticRectangleSum()\
    \ : n(0), lg(0) {}\n    StaticRectangleSum(const vector<X> &x, const vector<X>\
    \ &y, const vector<W> &w) : n(x.size()) {\n        vector<int> ord(n);\n     \
    \   iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(), ord.end(), [&](int\
    \ i, int j) { return x[i] < x[j]; });\n        xs.resize(n);\n        for (int\
    \ k = 0; k < n; k++) xs[k] = x[ord[k]];\n        ys = y;\n        sort(ys.begin(),\
    \ ys.end());\n        ys.erase(unique(ys.begin(), ys.end()), ys.end());\n    \
    \    vector<int> cur(n), nxt(n);\n        vector<W> cw(n), nw(n);\n        for\
    \ (int k = 0; k < n; k++) {\n            cur[k] = lower_bound(ys.begin(), ys.end(),\
    \ y[ord[k]]) - ys.begin();\n            cw[k] = w[ord[k]];\n        }\n      \
    \  lg = 1;\n        while ((1 << lg) < (int)ys.size()) lg++;\n        bv.resize(lg),\
    \ zeros.resize(lg), sum.assign(lg, vector<W>(n + 1, W(0)));\n        for (int\
    \ h = lg - 1; h >= 0; h--) {\n            bv[h].init(n);\n            int z =\
    \ 0;\n            for (int i = 0; i < n; i++) {\n                if (cur[i] >>\
    \ h & 1) bv[h].set(i);\n                else z++;\n            }\n           \
    \ bv[h].build();\n            zeros[h] = z;\n            int p0 = 0, p1 = z;\n\
    \            for (int i = 0; i < n; i++) {\n                int p = (cur[i] >>\
    \ h & 1) ? p1++ : p0++;\n                nxt[p] = cur[i], nw[p] = cw[i];\n   \
    \         }\n            swap(cur, nxt), swap(cw, nw);\n            for (int i\
    \ = 0; i < n; i++) sum[h][i + 1] = sum[h][i] + cw[i];\n        }\n    }\n\n  \
    \  int size() const { return n; }\n\n    // l <= x < r, d <= y < u \u306E\u70B9\
    \u306E\u91CD\u307F\u306E\u548C\n    W sum_rect(X l, X d, X r, X u) const {\n \
    \       int il = lower_idx(xs, l), ir = lower_idx(xs, r);\n        int yd = lower_idx(ys,\
    \ d), yu = lower_idx(ys, u);\n        if (il >= ir || yd >= yu) return W(0);\n\
    \        if (yu >= (1 << lg)) return total(il, ir) - prefix(il, ir, yd);\n   \
    \     // \u4E0A\u306E\u6BB5\u3067 yd \u3068 yu \u306E\u30D3\u30C3\u30C8\u304C\u540C\
    \u3058\u9593\u306F 2 \u3064\u306E\u548C\u306E\u5DEE\u306B\u52B9\u304B\u306A\u3044\
    \u306E\u3067\uFF0C\u5171\u901A\u306B\u964D\u308A\u308B\n        int h = lg - 1;\n\
    \        for (; h >= 0 && ((yd ^ yu) >> h & 1) == 0; h--) {\n            int l1\
    \ = bv[h].rank1(il), r1 = bv[h].rank1(ir);\n            if (yu >> h & 1) il =\
    \ zeros[h] + l1, ir = zeros[h] + r1;\n            else il -= l1, ir -= r1;\n \
    \       }\n        // \u30D3\u30C3\u30C8 h \u3067 yd \u306F 0\uFF0Cyu \u306F 1\n\
    \        int l1 = bv[h].rank1(il), r1 = bv[h].rank1(ir);\n        int l0 = il\
    \ - l1, r0 = ir - r1;\n        return (sum[h][r0] - sum[h][l0]) + prefix_from(zeros[h]\
    \ + l1, zeros[h] + r1, yu, h - 1) - prefix_from(l0, r0, yd, h - 1);\n    }\n \
    \   W operator()(X l, X d, X r, X u) const { return sum_rect(l, d, r, u); }\n\n\
    \  private:\n    // \u5206\u5C90\u306E\u5C11\u306A\u3044 lower_bound (\u6DFB\u5B57\
    \u3092\u8FD4\u3059)\n    static int lower_idx(const vector<X> &v, const X &x)\
    \ {\n        int n = v.size();\n        if (n == 0) return 0;\n        const X\
    \ *base = v.data();\n        while (n > 1) {\n            int half = n >> 1;\n\
    \            base = base[half - 1] < x ? base + half : base;\n            n -=\
    \ half;\n        }\n        return int(base - v.data()) + (*base < x);\n    }\n\
    \n    // x \u306E\u9806\u3067 [l, r) \u756A\u76EE\u306E\u70B9\u306E\u3046\u3061\
    \ y \u306E\u756A\u53F7\u304C v \u672A\u6E80\u306E\u3082\u306E\u306E\u91CD\u307F\
    \u306E\u548C\n    W prefix(int l, int r, int v) const {\n        if (v >= (1 <<\
    \ lg)) return total(l, r);\n        return prefix_from(l, r, v, lg - 1);\n   \
    \ }\n    // \u6BB5 h \u304B\u3089\u4E0B\u3060\u3051\u3092\u898B\u308B\u7248 (\u6BB5\
    \ h \u3067\u306E\u533A\u9593\u304C [l, r))\n    W prefix_from(int l, int r, int\
    \ v, int h0) const {\n        W res(0);\n        for (int h = h0; h >= 0; h--)\
    \ {\n            int l1 = bv[h].rank1(l), r1 = bv[h].rank1(r);\n            int\
    \ l0 = l - l1, r0 = r - r1;\n            if (v >> h & 1) {\n                res\
    \ += sum[h][r0] - sum[h][l0];\n                l = zeros[h] + l1, r = zeros[h]\
    \ + r1;\n            } else {\n                l = l0, r = r0;\n            }\n\
    \        }\n        return res;\n    }\n    W total(int l, int r) const {\n  \
    \      // \u6700\u4E0A\u6BB5\u3067\u632F\u308A\u5206\u3051\u308B\u524D\u306E [l,\
    \ r) \u306E\u548C = 0 \u5074\u3068 1 \u5074\u306E\u548C\n        int h = lg -\
    \ 1;\n        int l1 = bv[h].rank1(l), r1 = bv[h].rank1(r);\n        return (sum[h][r\
    \ - r1] - sum[h][l - l1]) + (sum[h][zeros[h] + r1] - sum[h][zeros[h] + l1]);\n\
    \    }\n};\n\n// \u70B9\u306E\u8FFD\u52A0\u304C\u3067\u304D\u308B\u9577\u65B9\u5F62\
    \u548C (Point Add Rectangle Sum)\uFF0E\u30AA\u30F3\u30E9\u30A4\u30F3\n// \u5927\
    \u304D\u3055\u304C 2 \u51AA\u306E StaticRectangleSum \u3092\u9AD8\u3005 log \u500B\
    \u6301\u3061\uFF0C\u8FFD\u52A0\u306E\u305F\u3073\u306B\u540C\u3058\u5927\u304D\
    \u3055\u306E\u3082\u306E\u3092\u4F75\u5408\u3057\u3066\u4F5C\u308A\u76F4\u3059\
    \ (\u4E8C\u9032\u30AB\u30A6\u30F3\u30BF)\n// \u8FFD\u52A0\u306A\u3089\u3057 O(log^2\
    \ n)\uFF0C\u30AF\u30A8\u30EA O(log^2 n)\ntemplate <class X, class W>\nstruct DynamicRectangleSum\
    \ {\n    struct Bucket {\n        vector<X> x, y;\n        vector<W> w;\n    \
    \    StaticRectangleSum<X, W> rs;\n    };\n    vector<Bucket> buckets;\n\n   \
    \ DynamicRectangleSum() = default;\n    // \u521D\u671F\u306E\u70B9\u3092\u307E\
    \u3068\u3081\u3066\u5165\u308C\u308B\n    DynamicRectangleSum(const vector<X>\
    \ &x, const vector<X> &y, const vector<W> &w) {\n        if (!x.empty()) buckets.push_back({x,\
    \ y, w, StaticRectangleSum<X, W>(x, y, w)});\n    }\n\n    // \u70B9 (x, y) \u306B\
    \u91CD\u307F w \u306E\u70B9\u3092\u8FFD\u52A0\n    void add(X x, X y, W w) {\n\
    \        Bucket b{{x}, {y}, {w}, {}};\n        while (!buckets.empty() && buckets.back().x.size()\
    \ <= b.x.size()) {\n            Bucket &t = buckets.back();\n            b.x.insert(b.x.end(),\
    \ t.x.begin(), t.x.end());\n            b.y.insert(b.y.end(), t.y.begin(), t.y.end());\n\
    \            b.w.insert(b.w.end(), t.w.begin(), t.w.end());\n            buckets.pop_back();\n\
    \        }\n        b.rs = StaticRectangleSum<X, W>(b.x, b.y, b.w);\n        buckets.push_back(std::move(b));\n\
    \    }\n\n    // l <= x < r, d <= y < u \u306E\u70B9\u306E\u91CD\u307F\u306E\u548C\
    \n    W sum_rect(X l, X d, X r, X u) const {\n        W res(0);\n        for (auto\
    \ &b : buckets) res += b.rs.sum_rect(l, d, r, u);\n        return res;\n    }\n\
    \    W operator()(X l, X d, X r, X u) const { return sum_rect(l, d, r, u); }\n\
    };\n#line 4 \"test/unittest/static_rectangle_sum.test.cpp\"\n\n// StaticRectangleSum\
    \ / DynamicRectangleSum \u3092\u611A\u76F4\u3068\u7167\u5408\u3059\u308B (\u8CA0\
    \u306E\u5EA7\u6A19\u30FB\u91CD\u8907\u3059\u308B\u70B9\u3082)\n\nint main() {\n\
    \    mt19937_64 rng(17);\n    for (int it = 0; it < 100; it++) {\n        int\
    \ n = rng() % 50;\n        int C = rng() % 2 ? 5 : 1000;\n        vector<long\
    \ long> x(n), y(n), w(n);\n        for (int i = 0; i < n; i++) x[i] = (long long)(rng()\
    \ % C) - C / 2, y[i] = (long long)(rng() % C) - C / 2, w[i] = rng() % 100;\n \
    \       StaticRectangleSum<long long, long long> rs(x, y, w);\n        DynamicRectangleSum<long\
    \ long, long long> ds(x, y, w);\n        DynamicRectangleSum<long long, long long>\
    \ empty_start;\n        vector<long long> ex, ey, ew;\n        for (int step =\
    \ 0; step < 300; step++) {\n            if (rng() % 3 == 0) {\n              \
    \  long long px = (long long)(rng() % C) - C / 2, py = (long long)(rng() % C)\
    \ - C / 2, pw = rng() % 100;\n                ds.add(px, py, pw), empty_start.add(px,\
    \ py, pw);\n                x.push_back(px), y.push_back(py), w.push_back(pw);\n\
    \                ex.push_back(px), ey.push_back(py), ew.push_back(pw);\n     \
    \       }\n            long long l = (long long)(rng() % (C + 4)) - C / 2 - 2,\
    \ r = (long long)(rng() % (C + 4)) - C / 2 - 2;\n            long long d = (long\
    \ long)(rng() % (C + 4)) - C / 2 - 2, u = (long long)(rng() % (C + 4)) - C / 2\
    \ - 2;\n            long long s0 = 0, s1 = 0, s2 = 0;\n            for (int i\
    \ = 0; i < (int)x.size(); i++) {\n                bool in = l <= x[i] && x[i]\
    \ < r && d <= y[i] && y[i] < u;\n                if (in) s1 += w[i];\n       \
    \         if (in && i < n) s0 += w[i];\n            }\n            for (int i\
    \ = 0; i < (int)ex.size(); i++) if (l <= ex[i] && ex[i] < r && d <= ey[i] && ey[i]\
    \ < u) s2 += ew[i];\n            assert(rs.sum_rect(l, d, r, u) == s0 && rs(l,\
    \ d, r, u) == s0);\n            assert(ds.sum_rect(l, d, r, u) == s1);\n     \
    \       assert(empty_start(l, d, r, u) == s2);\n        }\n    }\n    long long\
    \ a_, b_;\n    fin >> a_ >> b_;\n    fout << a_ + b_ << '\\n';\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../io/fastio.hpp\"\
    \n#include \"../../data_structure/static_rectangle_sum.hpp\"\n\n// StaticRectangleSum\
    \ / DynamicRectangleSum \u3092\u611A\u76F4\u3068\u7167\u5408\u3059\u308B (\u8CA0\
    \u306E\u5EA7\u6A19\u30FB\u91CD\u8907\u3059\u308B\u70B9\u3082)\n\nint main() {\n\
    \    mt19937_64 rng(17);\n    for (int it = 0; it < 100; it++) {\n        int\
    \ n = rng() % 50;\n        int C = rng() % 2 ? 5 : 1000;\n        vector<long\
    \ long> x(n), y(n), w(n);\n        for (int i = 0; i < n; i++) x[i] = (long long)(rng()\
    \ % C) - C / 2, y[i] = (long long)(rng() % C) - C / 2, w[i] = rng() % 100;\n \
    \       StaticRectangleSum<long long, long long> rs(x, y, w);\n        DynamicRectangleSum<long\
    \ long, long long> ds(x, y, w);\n        DynamicRectangleSum<long long, long long>\
    \ empty_start;\n        vector<long long> ex, ey, ew;\n        for (int step =\
    \ 0; step < 300; step++) {\n            if (rng() % 3 == 0) {\n              \
    \  long long px = (long long)(rng() % C) - C / 2, py = (long long)(rng() % C)\
    \ - C / 2, pw = rng() % 100;\n                ds.add(px, py, pw), empty_start.add(px,\
    \ py, pw);\n                x.push_back(px), y.push_back(py), w.push_back(pw);\n\
    \                ex.push_back(px), ey.push_back(py), ew.push_back(pw);\n     \
    \       }\n            long long l = (long long)(rng() % (C + 4)) - C / 2 - 2,\
    \ r = (long long)(rng() % (C + 4)) - C / 2 - 2;\n            long long d = (long\
    \ long)(rng() % (C + 4)) - C / 2 - 2, u = (long long)(rng() % (C + 4)) - C / 2\
    \ - 2;\n            long long s0 = 0, s1 = 0, s2 = 0;\n            for (int i\
    \ = 0; i < (int)x.size(); i++) {\n                bool in = l <= x[i] && x[i]\
    \ < r && d <= y[i] && y[i] < u;\n                if (in) s1 += w[i];\n       \
    \         if (in && i < n) s0 += w[i];\n            }\n            for (int i\
    \ = 0; i < (int)ex.size(); i++) if (l <= ex[i] && ex[i] < r && d <= ey[i] && ey[i]\
    \ < u) s2 += ew[i];\n            assert(rs.sum_rect(l, d, r, u) == s0 && rs(l,\
    \ d, r, u) == s0);\n            assert(ds.sum_rect(l, d, r, u) == s1);\n     \
    \       assert(empty_start(l, d, r, u) == s2);\n        }\n    }\n    long long\
    \ a_, b_;\n    fin >> a_ >> b_;\n    fout << a_ + b_ << '\\n';\n    return 0;\n\
    }\n"
  dependsOn:
  - io/fastio.hpp
  - template.hpp
  - data_structure/static_rectangle_sum.hpp
  - template.hpp
  isVerificationFile: true
  path: test/unittest/static_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 23:42:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/static_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/static_rectangle_sum.test.cpp
- /verify/test/unittest/static_rectangle_sum.test.cpp.html
title: test/unittest/static_rectangle_sum.test.cpp
---
