---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/static_range_inversions.hpp
    title: "\u9759\u7684\u306A\u533A\u9593\u8EE2\u5012\u6570 (Static Range Inversions\
      \ Query)"
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/static_range_inversions_query.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\n#line 1 \"\
    template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
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
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 3 \"data_structure/static_range_inversions.hpp\"\
    \n\n// https://github.com/winter-2521/cp-library\n\n// \u9759\u7684\u306A\u6570\
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
    \        }\n        return res;\n    }\n};\n#line 4 \"test/static_range_inversions_query.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    fin >> n >> q;\n    vector<int> a(n);\n \
    \   fin >> a;\n    StaticRangeInversions<int> inv(a);\n    while (q--) {\n   \
    \     int l, r;\n        fin >> l >> r;\n        fout << inv.query(l, r) << '\\\
    n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#include \"../io/fastio.hpp\"\n#include \"../data_structure/static_range_inversions.hpp\"\
    \n\nint main() {\n    int n, q;\n    fin >> n >> q;\n    vector<int> a(n);\n \
    \   fin >> a;\n    StaticRangeInversions<int> inv(a);\n    while (q--) {\n   \
    \     int l, r;\n        fin >> l >> r;\n        fout << inv.query(l, r) << '\\\
    n';\n    }\n    return 0;\n}\n"
  dependsOn:
  - io/fastio.hpp
  - template.hpp
  - data_structure/static_range_inversions.hpp
  - template.hpp
  isVerificationFile: true
  path: test/static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/test/static_range_inversions_query.test.cpp
- /verify/test/static_range_inversions_query.test.cpp.html
title: test/static_range_inversions_query.test.cpp
---
