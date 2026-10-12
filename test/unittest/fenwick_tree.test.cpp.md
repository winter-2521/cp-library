---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: Fenwick Tree (Binary Indexed Tree)
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
  bundledCode: "#line 1 \"test/unittest/fenwick_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"template.hpp\"\n#include <bits/stdc++.h>\n\
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
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 3 \"io/fastio.hpp\"\
    \n\n// \u9AD8\u901F\u5165\u51FA\u529B\n// fin >> a >> b;  fout << a + b << '\\\
    n';  \u306E\u3088\u3046\u306B cin / cout \u3068\u540C\u3058\u611F\u899A\u3067\u4F7F\
    \u3046\n// cin / cout / scanf / printf \u3068\u6DF7\u305C\u3066\u4F7F\u3063\u3066\
    \u306F\u3044\u3051\u306A\u3044\n// \u5165\u529B\u306F\u30D6\u30ED\u30C3\u30AF\u5358\
    \u4F4D\u3067\u8AAD\u3080\u306E\u3067\uFF0C\u30A4\u30F3\u30BF\u30E9\u30AF\u30C6\
    \u30A3\u30D6\u554F\u984C\u306B\u306F\u4F7F\u3048\u306A\u3044\n\nnamespace fastio\
    \ {\n\n// \u5165\u51FA\u529B\u30D0\u30C3\u30D5\u30A1\u306E\u5927\u304D\u3055\n\
    constexpr size_t BUF_SIZE = 1 << 17;\n\n// 0000 ~ 9999 \u306E 4 \u6841\u306E\u6587\
    \u5B57\u5217\u3092\u524D\u8A08\u7B97\u3057\u3066\u304A\u304F\u8868\nstruct DigitTable\
    \ {\n    char d[10000][4];\n    constexpr DigitTable() : d() {\n        for (int\
    \ i = 0; i < 10000; i++) {\n            int x = i;\n            for (int j = 3;\
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
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 3 \"data_structure/fenwick_tree.hpp\"\
    \n\n// Fenwick Tree (Binary Indexed Tree)\n// \u4E00\u70B9\u52A0\u7B97\u30FB\u533A\
    \u9593\u548C\u3092 O(log n) \u3067\u51E6\u7406\u3059\u308B\uFF0E\u5916\u90E8\u304B\
    \u3089\u306F 0-indexed \u3067\u6271\u3046\ntemplate <class T>\nstruct FenwickTree\
    \ {\n    int n;\n    // d[i] (1-indexed) \u306F\u533A\u9593 (i - lowbit(i), i]\
    \ \u306E\u548C\n    vector<T> d;\n\n    FenwickTree(int n = 0) : n(n), d(n + 1,\
    \ T(0)) {}\n\n    // \u914D\u5217 a \u3067 O(n) \u521D\u671F\u5316\n    FenwickTree(const\
    \ vector<T> &a) : n(a.size()), d(a.size() + 1, T(0)) {\n        for (int i = 0;\
    \ i < n; i++) d[i + 1] = a[i];\n        for (int i = 1; i <= n; i++) {\n     \
    \       int j = i + (i & -i);\n            if (j <= n) d[j] += d[i];\n       \
    \ }\n    }\n\n    int size() const { return n; }\n\n    // a[i] += x\n    void\
    \ add(int i, T x) {\n        for (i++; i <= n; i += i & -i) d[i] += x;\n    }\n\
    \n    // a[0] + ... + a[r-1]\n    T sum(int r) const {\n        T s = T(0);\n\
    \        for (; r > 0; r &= r - 1) s += d[r];\n        return s;\n    }\n\n  \
    \  // a[l] + ... + a[r-1]\n    // sum(r) - sum(l) \u3092\uFF0Cl \u3068 r \u306E\
    \u5171\u901A\u306E\u7956\u5148\u307E\u3067\u964D\u308A\u305F\u3068\u3053\u308D\
    \u3067\u6253\u3061\u5207\u3063\u3066\u8A08\u7B97\u3059\u308B\n    T sum(int l,\
    \ int r) const {\n        T s = T(0);\n        while (l < r) s += d[r], r &= r\
    \ - 1;\n        while (r < l) s -= d[l], l &= l - 1;\n        return s;\n    }\n\
    \n    // a[i]\n    T get(int i) const { return sum(i, i + 1); }\n\n    // a[i]\
    \ = x\n    void set(int i, T x) { add(i, x - get(i)); }\n\n    // a[0] + ... +\
    \ a[i] >= w \u3068\u306A\u308B\u6700\u5C0F\u306E i \u3092\u8FD4\u3059 (\u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070 n)\n    // \u5168\u8981\u7D20\u304C\u975E\u8CA0\
    \u3067\u3042\u308B\u3053\u3068\n    int lower_bound(T w) const {\n        if (w\
    \ <= T(0)) return 0;\n        int x = 0;\n        int k = 1;\n        while (k\
    \ * 2 <= n) k *= 2;\n        for (; k > 0; k >>= 1) {\n            if (x + k <=\
    \ n && d[x + k] < w) {\n                x += k;\n                w -= d[x];\n\
    \            }\n        }\n        return x;\n    }\n\n    // a[0] + ... + a[i]\
    \ > w \u3068\u306A\u308B\u6700\u5C0F\u306E i \u3092\u8FD4\u3059 (\u5B58\u5728\u3057\
    \u306A\u3051\u308C\u3070 n)\n    // \u5168\u8981\u7D20\u304C\u975E\u8CA0\u3067\
    \u3042\u308B\u3053\u3068\n    int upper_bound(T w) const {\n        int x = 0;\n\
    \        int k = 1;\n        while (k * 2 <= n) k *= 2;\n        for (; k > 0;\
    \ k >>= 1) {\n            if (x + k <= n && !(w < d[x + k])) {\n             \
    \   x += k;\n                w -= d[x];\n            }\n        }\n        return\
    \ x;\n    }\n};\n#line 4 \"test/unittest/fenwick_tree.test.cpp\"\n\n// FenwickTree\
    \ \u3092\u611A\u76F4\u306A\u914D\u5217\u3068\u7167\u5408\u3059\u308B\n\nint main()\
    \ {\n    mt19937_64 rng(4);\n    for (int n : {0, 1, 2, 3, 7, 8, 9, 100, 1000})\
    \ {\n        vector<long long> a(n);\n        for (auto &x : a) x = rng() % 5;\n\
    \        FenwickTree<long long> bit(a);\n        assert(bit.size() == n);\n  \
    \      for (int it = 0; it < 20000; it++) {\n            int t = rng() % 5;\n\
    \            if (n == 0) t = 4;\n            if (t == 0) {\n                int\
    \ i = rng() % n;\n                long long x = rng() % 4;\n                bit.add(i,\
    \ x), a[i] += x;\n            } else if (t == 1) {\n                int i = rng()\
    \ % n;\n                long long x = rng() % 4;\n                bit.set(i, x),\
    \ a[i] = x;\n            } else if (t == 2) {\n                int l = rng() %\
    \ (n + 1), r = rng() % (n + 1);\n                if (l > r) swap(l, r);\n    \
    \            long long s = 0;\n                for (int i = l; i < r; i++) s +=\
    \ a[i];\n                assert(bit.sum(l, r) == s && bit.sum(r) - bit.sum(l)\
    \ == s);\n                if (l < n) assert(bit.get(l) == a[l]);\n           \
    \ } else {\n                long long total = accumulate(a.begin(), a.end(), 0LL);\n\
    \                long long w = (long long)(rng() % (total + 3)) - 1;\n       \
    \         int lb = n, ub = n;\n                long long s = 0;\n            \
    \    for (int i = n - 1; i >= 0; i--) {\n                    s = 0;\n        \
    \            for (int j = 0; j <= i; j++) s += a[j];\n                    if (s\
    \ >= w) lb = i;\n                    if (s > w) ub = i;\n                }\n \
    \               assert(bit.lower_bound(w) == lb);\n                assert(bit.upper_bound(w)\
    \ == ub);\n            }\n        }\n    }\n    long long a_, b_;\n    fin >>\
    \ a_ >> b_;\n    fout << a_ + b_ << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../io/fastio.hpp\"\
    \n#include \"../../data_structure/fenwick_tree.hpp\"\n\n// FenwickTree \u3092\u611A\
    \u76F4\u306A\u914D\u5217\u3068\u7167\u5408\u3059\u308B\n\nint main() {\n    mt19937_64\
    \ rng(4);\n    for (int n : {0, 1, 2, 3, 7, 8, 9, 100, 1000}) {\n        vector<long\
    \ long> a(n);\n        for (auto &x : a) x = rng() % 5;\n        FenwickTree<long\
    \ long> bit(a);\n        assert(bit.size() == n);\n        for (int it = 0; it\
    \ < 20000; it++) {\n            int t = rng() % 5;\n            if (n == 0) t\
    \ = 4;\n            if (t == 0) {\n                int i = rng() % n;\n      \
    \          long long x = rng() % 4;\n                bit.add(i, x), a[i] += x;\n\
    \            } else if (t == 1) {\n                int i = rng() % n;\n      \
    \          long long x = rng() % 4;\n                bit.set(i, x), a[i] = x;\n\
    \            } else if (t == 2) {\n                int l = rng() % (n + 1), r\
    \ = rng() % (n + 1);\n                if (l > r) swap(l, r);\n               \
    \ long long s = 0;\n                for (int i = l; i < r; i++) s += a[i];\n \
    \               assert(bit.sum(l, r) == s && bit.sum(r) - bit.sum(l) == s);\n\
    \                if (l < n) assert(bit.get(l) == a[l]);\n            } else {\n\
    \                long long total = accumulate(a.begin(), a.end(), 0LL);\n    \
    \            long long w = (long long)(rng() % (total + 3)) - 1;\n           \
    \     int lb = n, ub = n;\n                long long s = 0;\n                for\
    \ (int i = n - 1; i >= 0; i--) {\n                    s = 0;\n               \
    \     for (int j = 0; j <= i; j++) s += a[j];\n                    if (s >= w)\
    \ lb = i;\n                    if (s > w) ub = i;\n                }\n       \
    \         assert(bit.lower_bound(w) == lb);\n                assert(bit.upper_bound(w)\
    \ == ub);\n            }\n        }\n    }\n    long long a_, b_;\n    fin >>\
    \ a_ >> b_;\n    fout << a_ + b_ << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - io/fastio.hpp
  - template.hpp
  - data_structure/fenwick_tree.hpp
  - template.hpp
  isVerificationFile: true
  path: test/unittest/fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2026-10-12 10:14:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/fenwick_tree.test.cpp
- /verify/test/unittest/fenwick_tree.test.cpp.html
title: test/unittest/fenwick_tree.test.cpp
---
