---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/fast_set.hpp
    title: "64 \u5206\u6728\u306B\u3088\u308B\u6574\u6570\u96C6\u5408 (Fast Set)"
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
  bundledCode: "#line 1 \"test/unittest/fast_set.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
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
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 3 \"data_structure/fast_set.hpp\"\
    \n\n// https://github.com/winter-2521/cp-library\n\n// 64 \u5206\u6728\u306B\u3088\
    \u308B [0, n) \u306E\u6574\u6570\u96C6\u5408\n// \u633F\u5165\u30FB\u524A\u9664\
    \u30FB\u5B58\u5728\u5224\u5B9A\u30FB\u6B21\u306E\u8981\u7D20\u30FB\u524D\u306E\
    \u8981\u7D20\u3092 O(log_64 n) \u3067\u51E6\u7406\u3059\u308B\nstruct FastSet\
    \ {\n    int n, lg;\n    // seg[0] \u304C\u6700\u4E0B\u6BB5\uFF0Eseg[h+1] \u306E\
    \ bit i \u306F seg[h] \u306E i \u756A\u76EE\u306E\u30EF\u30FC\u30C9\u304C 0 \u3067\
    \u306A\u3044\u304B\u3092\u8868\u3059\n    vector<vector<uint64_t>> seg;\n\n  \
    \  FastSet(int n = 0) : n(n) {\n        int m = n;\n        do {\n           \
    \ seg.push_back(vector<uint64_t>(std::max(1, (m + 63) >> 6)));\n            m\
    \ = (m + 63) >> 6;\n        } while (m > 1);\n        lg = seg.size();\n    }\n\
    \n    // f(i) \u304C true \u306E i \u3092\u5168\u3066\u5165\u308C\u305F\u72B6\u614B\
    \u3067\u521D\u671F\u5316\u3059\u308B\uFF0EO(n)\n    template <class F>\n    FastSet(int\
    \ n, F f) : FastSet(n) {\n        for (int i = 0; i < n; i++) if (f(i)) seg[0][i\
    \ >> 6] |= 1ULL << (i & 63);\n        build_upper();\n    }\n\n    // \u6700\u4E0B\
    \u6BB5\u304B\u3089\u4E0A\u306E\u6BB5\u3092\u4F5C\u308A\u76F4\u3059\n    void build_upper()\
    \ {\n        for (int h = 0; h + 1 < lg; h++) {\n            fill(seg[h + 1].begin(),\
    \ seg[h + 1].end(), 0);\n            for (size_t i = 0; i < seg[h].size(); i++)\
    \ if (seg[h][i]) seg[h + 1][i >> 6] |= 1ULL << (i & 63);\n        }\n    }\n\n\
    \    int size() const { return n; }\n\n    bool contains(int i) const { return\
    \ seg[0][i >> 6] >> (i & 63) & 1; }\n    bool operator[](int i) const { return\
    \ contains(i); }\n\n    void insert(int i) {\n        for (int h = 0; h < lg;\
    \ h++) {\n            uint64_t &w = seg[h][i >> 6];\n            bool was_empty\
    \ = w == 0;\n            w |= 1ULL << (i & 63);\n            // \u3059\u3067\u306B\
    \u4E0A\u306E\u6BB5\u306B\u30D5\u30E9\u30B0\u304C\u7ACB\u3063\u3066\u3044\u308B\
    \u306E\u3067\u6253\u3061\u5207\u308B\n            if (!was_empty) break;\n   \
    \         i >>= 6;\n        }\n    }\n\n    void erase(int i) {\n        for (int\
    \ h = 0; h < lg; h++) {\n            uint64_t &w = seg[h][i >> 6];\n         \
    \   w &= ~(1ULL << (i & 63));\n            // \u30EF\u30FC\u30C9\u304C\u307E\u3060\
    \u7A7A\u3067\u306A\u3051\u308C\u3070\u4E0A\u306E\u6BB5\u306F\u5909\u308F\u3089\
    \u306A\u3044\n            if (w) break;\n            i >>= 6;\n        }\n   \
    \ }\n\n    // i \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20 (\u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070 -1)\n    int next(int i) const {\n        if (i\
    \ < 0) i = 0;\n        if (i >= n) return -1;\n        for (int h = 0; h < lg;\
    \ h++) {\n            if ((i >> 6) == (int)seg[h].size()) break;\n           \
    \ uint64_t d = seg[h][i >> 6] >> (i & 63);\n            if (d == 0) {\n      \
    \          i = (i >> 6) + 1;\n                continue;\n            }\n     \
    \       i += __builtin_ctzll(d);\n            for (int g = h - 1; g >= 0; g--)\
    \ {\n                i <<= 6;\n                i += __builtin_ctzll(seg[g][i >>\
    \ 6]);\n            }\n            return i;\n        }\n        return -1;\n\
    \    }\n\n    // i \u4EE5\u4E0B\u306E\u6700\u5927\u306E\u8981\u7D20 (\u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070 -1)\n    int prev(int i) const {\n        if (i\
    \ >= n) i = n - 1;\n        for (int h = 0; h < lg; h++) {\n            if (i\
    \ < 0) break;\n            uint64_t d = seg[h][i >> 6] << (63 - (i & 63));\n \
    \           if (d == 0) {\n                i = (i >> 6) - 1;\n               \
    \ continue;\n            }\n            i -= __builtin_clzll(d);\n           \
    \ for (int g = h - 1; g >= 0; g--) {\n                i <<= 6;\n             \
    \   i += 63 - __builtin_clzll(seg[g][i >> 6]);\n            }\n            return\
    \ i;\n        }\n        return -1;\n    }\n\n    // \u6700\u5C0F\u306E\u8981\u7D20\
    \ (\u7A7A\u306A\u3089 -1)\n    int min() const { return next(0); }\n    // \u6700\
    \u5927\u306E\u8981\u7D20 (\u7A7A\u306A\u3089 -1)\n    int max() const { return\
    \ prev(n - 1); }\n    bool empty() const { return seg[lg - 1][0] == 0; }\n\n \
    \   // [l, r) \u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u3092\u6607\u9806\u306B\
    \ f \u306B\u6E21\u3059\n    template <class F>\n    void enumerate(int l, int\
    \ r, F f) const {\n        for (int x = next(l); x != -1 && x < r; x = next(x\
    \ + 1)) f(x);\n    }\n};\n#line 4 \"test/unittest/fast_set.test.cpp\"\n\n// FastSet\
    \ \u3092 std::set \u3068\u7167\u5408\u3059\u308B\n\nint main() {\n    mt19937_64\
    \ rng(3);\n    for (int n : {0, 1, 2, 63, 64, 65, 100, 4095, 4096, 4097, 300000})\
    \ {\n        vector<int> init(n);\n        for (auto &x : init) x = rng() % 3\
    \ == 0;\n        FastSet fs(n, [&](int i) { return init[i] == 1; });\n       \
    \ set<int> ref;\n        for (int i = 0; i < n; i++) if (init[i]) ref.insert(i);\n\
    \        int ops = n == 300000 ? 300000 : 20000;\n        for (int it = 0; it\
    \ < ops; it++) {\n            int k = n == 0 ? 0 : (int)(rng() % (n + 4)) - 2;\n\
    \            int t = rng() % 5;\n            bool in = 0 <= k && k < n;\n    \
    \        if (t == 0 && in) fs.insert(k), ref.insert(k);\n            else if (t\
    \ == 1 && in) fs.erase(k), ref.erase(k);\n            else if (t == 2 && in) assert(fs.contains(k)\
    \ == (ref.count(k) == 1) && fs[k] == fs.contains(k));\n            else if (t\
    \ == 3) {\n                auto p = ref.lower_bound(k);\n                assert(fs.next(k)\
    \ == (p == ref.end() ? -1 : *p));\n            } else {\n                auto\
    \ p = ref.upper_bound(k);\n                assert(fs.prev(k) == (p == ref.begin()\
    \ ? -1 : *prev(p)));\n            }\n            assert(fs.empty() == ref.empty());\n\
    \            assert(fs.min() == (ref.empty() ? -1 : *ref.begin()));\n        \
    \    assert(fs.max() == (ref.empty() ? -1 : *ref.rbegin()));\n        }\n    \
    \    int l = n ? rng() % n : 0, r = n ? rng() % (n + 1) : 0;\n        vector<int>\
    \ got, exp;\n        fs.enumerate(l, r, [&](int x) { got.push_back(x); });\n \
    \       for (int x : ref) if (l <= x && x < r) exp.push_back(x);\n        assert(got\
    \ == exp);\n    }\n    long long a_, b_;\n    fin >> a_ >> b_;\n    fout << a_\
    \ + b_ << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../io/fastio.hpp\"\
    \n#include \"../../data_structure/fast_set.hpp\"\n\n// FastSet \u3092 std::set\
    \ \u3068\u7167\u5408\u3059\u308B\n\nint main() {\n    mt19937_64 rng(3);\n   \
    \ for (int n : {0, 1, 2, 63, 64, 65, 100, 4095, 4096, 4097, 300000}) {\n     \
    \   vector<int> init(n);\n        for (auto &x : init) x = rng() % 3 == 0;\n \
    \       FastSet fs(n, [&](int i) { return init[i] == 1; });\n        set<int>\
    \ ref;\n        for (int i = 0; i < n; i++) if (init[i]) ref.insert(i);\n    \
    \    int ops = n == 300000 ? 300000 : 20000;\n        for (int it = 0; it < ops;\
    \ it++) {\n            int k = n == 0 ? 0 : (int)(rng() % (n + 4)) - 2;\n    \
    \        int t = rng() % 5;\n            bool in = 0 <= k && k < n;\n        \
    \    if (t == 0 && in) fs.insert(k), ref.insert(k);\n            else if (t ==\
    \ 1 && in) fs.erase(k), ref.erase(k);\n            else if (t == 2 && in) assert(fs.contains(k)\
    \ == (ref.count(k) == 1) && fs[k] == fs.contains(k));\n            else if (t\
    \ == 3) {\n                auto p = ref.lower_bound(k);\n                assert(fs.next(k)\
    \ == (p == ref.end() ? -1 : *p));\n            } else {\n                auto\
    \ p = ref.upper_bound(k);\n                assert(fs.prev(k) == (p == ref.begin()\
    \ ? -1 : *prev(p)));\n            }\n            assert(fs.empty() == ref.empty());\n\
    \            assert(fs.min() == (ref.empty() ? -1 : *ref.begin()));\n        \
    \    assert(fs.max() == (ref.empty() ? -1 : *ref.rbegin()));\n        }\n    \
    \    int l = n ? rng() % n : 0, r = n ? rng() % (n + 1) : 0;\n        vector<int>\
    \ got, exp;\n        fs.enumerate(l, r, [&](int x) { got.push_back(x); });\n \
    \       for (int x : ref) if (l <= x && x < r) exp.push_back(x);\n        assert(got\
    \ == exp);\n    }\n    long long a_, b_;\n    fin >> a_ >> b_;\n    fout << a_\
    \ + b_ << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - io/fastio.hpp
  - template.hpp
  - data_structure/fast_set.hpp
  - template.hpp
  isVerificationFile: true
  path: test/unittest/fast_set.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unittest/fast_set.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/fast_set.test.cpp
- /verify/test/unittest/fast_set.test.cpp.html
title: test/unittest/fast_set.test.cpp
---
