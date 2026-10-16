---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/ordered_set.hpp
    title: "\u9806\u5E8F\u4ED8\u304D\u96C6\u5408 (Ordered Set)"
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
    PROBLEM: https://judge.yosupo.jp/problem/ordered_set
    links:
    - https://judge.yosupo.jp/problem/ordered_set
  bundledCode: "#line 1 \"test/ordered_set.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/ordered_set\"\
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
    \ ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line 3 \"data_structure/ordered_set.hpp\"\
    \n\n// https://github.com/winter-2521/cp-library\n\n// \u9806\u5E8F\u4ED8\u304D\
    \u96C6\u5408 (\u30AA\u30F3\u30E9\u30A4\u30F3\u30FB\u5024\u306E\u5148\u8AAD\u307F\
    \u4E0D\u8981)\n// \u5404\u30CE\u30FC\u30C9\u304C\u6700\u5927 B \u500B\u306E\u5024\
    \u3092\u30BD\u30FC\u30C8\u6E08\u307F\u914D\u5217\u3067\u6301\u3064 AVL \u6728\uFF0E\
    \n// 1 \u30CE\u30FC\u30C9\u3092 128 \u30D0\u30A4\u30C8\u7A0B\u5EA6\u306B\u3057\
    \u3066\u30AD\u30E3\u30C3\u30B7\u30E5\u52B9\u7387\u3092\u4E0A\u3052\uFF0C\u30CE\
    \u30FC\u30C9\u5185\u306F\u7DDA\u5F62\u63A2\u7D22\u3059\u308B\uFF0E\u5404\u64CD\
    \u4F5C O(log n)\n//\n// \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306E\u623B\
    \u308A\u5024\u306F def (\u7701\u7565\u6642 -1)\ntemplate <class T, int B = std::max(4,\
    \ int(112 / sizeof(T)))>\nstruct OrderedSet {\n    struct Node {\n        T data[B];\n\
    \        int left, right, total;  // total: \u90E8\u5206\u6728\u306E\u8981\u7D20\
    \u6570\n        short height, size;\n    };\n\n    vector<Node> t;\n    vector<int>\
    \ free_list;\n    int root = 0;\n\n    OrderedSet() { t.push_back(Node{}); } \
    \ // t[0] \u306F\u756A\u5175 (height = total = 0)\n\n    // \u521D\u671F\u8981\
    \u7D20 a (\u9806\u4E0D\u540C\u30FB\u91CD\u8907\u53EF) \u3067 O(n log n) \u69CB\
    \u7BC9 (\u30BD\u30FC\u30C8\u6E08\u307F\u306A\u3089 O(n))\n    OrderedSet(vector<T>\
    \ a) : OrderedSet() {\n        if (!is_sorted(a.begin(), a.end())) sort(a.begin(),\
    \ a.end());\n        a.erase(unique(a.begin(), a.end()), a.end());\n        int\
    \ n = a.size();\n        if (n == 0) return;\n        // \u5F8C\u304B\u3089\u633F\
    \u5165\u3067\u304D\u308B\u3088\u3046\u5C11\u3057\u4F59\u88D5\u3092\u6B8B\u3057\
    \u3066\u8A70\u3081\u308B\n        int bs = std::max(1, B * 6 / 7);\n        int\
    \ m = (n + bs - 1) / bs;\n        t.reserve(m + 1);\n        vector<int> ids(m);\n\
    \        for (int i = 0; i < m; i++) {\n            int v = ids[i] = new_node();\n\
    \            int l = i * bs, r = std::min(n, l + bs);\n            for (int j\
    \ = l; j < r; j++) t[v].data[j - l] = a[j];\n            t[v].size = r - l;\n\
    \        }\n        root = build(ids, 0, m);\n    }\n\n    int size() const {\
    \ return t[root].total; }\n    bool empty() const { return root == 0; }\n\n  \
    \  // x \u3092\u633F\u5165\u3059\u308B\uFF0E\u633F\u5165\u3057\u305F\u3089 true\uFF0C\
    \u65E2\u306B\u3042\u308C\u3070 false\n    bool insert(const T &x) {\n        done\
    \ = false;\n        root = insert(root, x);\n        return done;\n    }\n\n \
    \   // x \u3092\u524A\u9664\u3059\u308B\uFF0E\u524A\u9664\u3057\u305F\u3089 true\uFF0C\
    \u306A\u3051\u308C\u3070 false\n    bool erase(const T &x) {\n        done = false;\n\
    \        root = erase(root, x);\n        return done;\n    }\n\n    bool contains(const\
    \ T &x) const {\n        for (int v = root; v;) {\n            const Node &nd\
    \ = t[v];\n            if (x < nd.data[0]) v = nd.left;\n            else if (nd.data[nd.size\
    \ - 1] < x) v = nd.right;\n            else {\n                for (int i = 0;\
    \ i < nd.size; i++) if (!(nd.data[i] < x)) return !(x < nd.data[i]);\n       \
    \         return false;\n            }\n        }\n        return false;\n   \
    \ }\n    size_t count(const T &x) const { return contains(x); }\n\n    // \u5C0F\
    \u3055\u3044\u65B9\u304B\u3089 k \u756A\u76EE (0-indexed) \u306E\u8981\u7D20\uFF0E\
    k >= size() \u306A\u3089 def\n    T kth(int k, T def = T(-1)) const {\n      \
    \  if (k < 0 || k >= size()) return def;\n        for (int v = root;;) {\n   \
    \         const Node &nd = t[v];\n            int ls = t[nd.left].total;\n   \
    \         if (k < ls) v = nd.left;\n            else if (k < ls + nd.size) return\
    \ nd.data[k - ls];\n            else k -= ls + nd.size, v = nd.right;\n      \
    \  }\n    }\n\n    // x \u672A\u6E80\u306E\u8981\u7D20\u306E\u500B\u6570\n   \
    \ int count_lt(const T &x) const {\n        int res = 0;\n        for (int v =\
    \ root; v;) {\n            const Node &nd = t[v];\n            if (!(nd.data[0]\
    \ < x)) v = nd.left;\n            else if (nd.data[nd.size - 1] < x) res += nd.total\
    \ - t[nd.right].total, v = nd.right;\n            else {\n                int\
    \ i = 0;\n                while (nd.data[i] < x) i++;\n                return\
    \ res + t[nd.left].total + i;\n            }\n        }\n        return res;\n\
    \    }\n\n    // x \u4EE5\u4E0B\u306E\u8981\u7D20\u306E\u500B\u6570\n    int count_le(const\
    \ T &x) const {\n        int res = 0;\n        for (int v = root; v;) {\n    \
    \        const Node &nd = t[v];\n            if (x < nd.data[0]) v = nd.left;\n\
    \            else if (!(x < nd.data[nd.size - 1])) res += nd.total - t[nd.right].total,\
    \ v = nd.right;\n            else {\n                int i = 0;\n            \
    \    while (!(x < nd.data[i])) i++;\n                return res + t[nd.left].total\
    \ + i;\n            }\n        }\n        return res;\n    }\n\n    // [lo, hi)\
    \ \u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u306E\u500B\u6570\n    int count_range(const\
    \ T &lo, const T &hi) const { return lo < hi ? count_lt(hi) - count_lt(lo) : 0;\
    \ }\n\n    // x \u672A\u6E80\u306E\u6700\u5927\u306E\u8981\u7D20 (\u306A\u3051\
    \u308C\u3070 def)\n    T max_lt(const T &x, T def = T(-1)) const {\n        for\
    \ (int v = root; v;) {\n            const Node &nd = t[v];\n            if (!(nd.data[0]\
    \ < x)) v = nd.left;\n            else if (nd.data[nd.size - 1] < x) def = nd.data[nd.size\
    \ - 1], v = nd.right;\n            else {\n                int i = 1;\n      \
    \          while (nd.data[i] < x) i++;\n                return nd.data[i - 1];\n\
    \            }\n        }\n        return def;\n    }\n\n    // x \u4EE5\u4E0B\
    \u306E\u6700\u5927\u306E\u8981\u7D20 (\u306A\u3051\u308C\u3070 def)\n    T max_le(const\
    \ T &x, T def = T(-1)) const {\n        for (int v = root; v;) {\n           \
    \ const Node &nd = t[v];\n            if (x < nd.data[0]) v = nd.left;\n     \
    \       else if (!(x < nd.data[nd.size - 1])) def = nd.data[nd.size - 1], v =\
    \ nd.right;\n            else {\n                int i = 1;\n                while\
    \ (!(x < nd.data[i])) i++;\n                return nd.data[i - 1];\n         \
    \   }\n        }\n        return def;\n    }\n\n    // x \u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u306E\u8981\u7D20 (\u306A\u3051\u308C\u3070 def)\n    T min_ge(const T\
    \ &x, T def = T(-1)) const {\n        for (int v = root; v;) {\n            const\
    \ Node &nd = t[v];\n            if (!(nd.data[0] < x)) def = nd.data[0], v = nd.left;\n\
    \            else if (nd.data[nd.size - 1] < x) v = nd.right;\n            else\
    \ {\n                int i = 1;\n                while (nd.data[i] < x) i++;\n\
    \                return nd.data[i];\n            }\n        }\n        return\
    \ def;\n    }\n\n    // x \u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u8981\
    \u7D20 (\u306A\u3051\u308C\u3070 def)\n    T min_gt(const T &x, T def = T(-1))\
    \ const {\n        for (int v = root; v;) {\n            const Node &nd = t[v];\n\
    \            if (x < nd.data[0]) def = nd.data[0], v = nd.left;\n            else\
    \ if (!(x < nd.data[nd.size - 1])) v = nd.right;\n            else {\n       \
    \         int i = 1;\n                while (!(x < nd.data[i])) i++;\n       \
    \         return nd.data[i];\n            }\n        }\n        return def;\n\
    \    }\n\n    // \u6700\u5C0F\u306E\u8981\u7D20 / \u6700\u5927\u306E\u8981\u7D20\
    \ (\u7A7A\u306A\u3089 def)\n    T min(T def = T(-1)) const {\n        if (!root)\
    \ return def;\n        int v = root;\n        while (t[v].left) v = t[v].left;\n\
    \        return t[v].data[0];\n    }\n    T max(T def = T(-1)) const {\n     \
    \   if (!root) return def;\n        int v = root;\n        while (t[v].right)\
    \ v = t[v].right;\n        return t[v].data[t[v].size - 1];\n    }\n\n    // \u8981\
    \u7D20\u3092\u6607\u9806\u306B\u5217\u6319\n    vector<T> to_vector() const {\n\
    \        vector<T> res;\n        res.reserve(size());\n        auto dfs = [&](auto\
    \ self, int v) -> void {\n            if (!v) return;\n            self(self,\
    \ t[v].left);\n            res.insert(res.end(), t[v].data, t[v].data + t[v].size);\n\
    \            self(self, t[v].right);\n        };\n        dfs(dfs, root);\n  \
    \      return res;\n    }\n\n  private:\n    bool done = false;\n\n    int new_node()\
    \ {\n        int v;\n        if (!free_list.empty()) v = free_list.back(), free_list.pop_back();\n\
    \        else v = t.size(), t.emplace_back();\n        Node &nd = t[v];\n    \
    \    nd.left = nd.right = 0, nd.size = 0, nd.height = 1, nd.total = 0;\n     \
    \   return v;\n    }\n\n    int build(const vector<int> &ids, int l, int r) {\n\
    \        int m = (l + r) / 2, v = ids[m];\n        t[v].left = l < m ? build(ids,\
    \ l, m) : 0;\n        t[v].right = m + 1 < r ? build(ids, m + 1, r) : 0;\n   \
    \     update(v);\n        return v;\n    }\n\n    void update(int v) {\n     \
    \   Node &nd = t[v];\n        nd.height = std::max(t[nd.left].height, t[nd.right].height)\
    \ + 1;\n        nd.total = nd.size + t[nd.left].total + t[nd.right].total;\n \
    \   }\n    int balance_factor(int v) const { return t[t[v].left].height - t[t[v].right].height;\
    \ }\n\n    int rotate_right(int v) {\n        int l = t[v].left;\n        t[v].left\
    \ = t[l].right, t[l].right = v;\n        update(v), update(l);\n        return\
    \ l;\n    }\n    int rotate_left(int v) {\n        int r = t[v].right;\n     \
    \   t[v].right = t[r].left, t[r].left = v;\n        update(v), update(r);\n  \
    \      return r;\n    }\n    // update(v) \u6E08\u307F\u3067\u3042\u308B\u3053\
    \u3068\n    int balance(int v) {\n        int bf = balance_factor(v);\n      \
    \  if (bf == 2) {\n            if (balance_factor(t[v].left) < 0) t[v].left =\
    \ rotate_left(t[v].left);\n            return rotate_right(v);\n        }\n  \
    \      if (bf == -2) {\n            if (balance_factor(t[v].right) > 0) t[v].right\
    \ = rotate_right(t[v].right);\n            return rotate_left(v);\n        }\n\
    \        return v;\n    }\n\n    // \u30CE\u30FC\u30C9\u5185\u306B\u633F\u5165\
    \ (size < B \u3067\u3042\u308B\u3053\u3068)\uFF0E\u65E2\u306B\u3042\u308C\u3070\
    \ false\n    bool node_insert(Node &nd, const T &x) {\n        int i = 0;\n  \
    \      while (i < nd.size && nd.data[i] < x) i++;\n        if (i < nd.size &&\
    \ !(x < nd.data[i])) return false;\n        for (int j = nd.size; j > i; j--)\
    \ nd.data[j] = nd.data[j - 1];\n        nd.data[i] = x, nd.size++;\n        return\
    \ true;\n    }\n    bool node_erase(Node &nd, const T &x) {\n        int i = 0;\n\
    \        while (i < nd.size && nd.data[i] < x) i++;\n        if (i == nd.size\
    \ || x < nd.data[i]) return false;\n        for (int j = i + 1; j < nd.size; j++)\
    \ nd.data[j - 1] = nd.data[j];\n        nd.size--;\n        return true;\n   \
    \ }\n    // \u6E80\u676F\u306E\u30CE\u30FC\u30C9 v \u306E\u5F8C\u534A\u3092\u65B0\
    \u3057\u3044\u30CE\u30FC\u30C9\u306B\u79FB\u3057\u3066\uFF0C\u305D\u306E\u756A\
    \u53F7\u3092\u8FD4\u3059\n    int split(int v) {\n        int u = new_node();\n\
    \        constexpr int h = B / 2;\n        for (int i = 0; i < B - h; i++) t[u].data[i]\
    \ = t[v].data[h + i];\n        t[u].size = B - h, t[v].size = h;\n        return\
    \ u;\n    }\n\n    // \u90E8\u5206\u6728 v \u306E\u5168\u8981\u7D20\u3088\u308A\
    \u5C0F\u3055\u3044 x \u3092\u633F\u5165\u3059\u308B\n    int insert_leftmost(int\
    \ v, const T &x) {\n        if (t[v].left) {\n            int l = insert_leftmost(t[v].left,\
    \ x);\n            t[v].left = l;\n            update(v);\n            return\
    \ balance(v);\n        }\n        node_insert(t[v], x);\n        if (t[v].size\
    \ < B) {\n            update(v);\n            return v;\n        }\n        int\
    \ u = split(v);\n        t[u].left = v, t[u].right = t[v].right, t[v].right =\
    \ 0;\n        update(v), update(u);\n        return balance(u);\n    }\n\n   \
    \ int insert(int v, const T &x) {\n        if (!v) {\n            v = new_node();\n\
    \            t[v].data[0] = x, t[v].size = 1;\n            update(v);\n      \
    \      done = true;\n            return v;\n        }\n        if (t[v].left &&\
    \ x < t[v].data[0]) {\n            int l = insert(t[v].left, x);\n           \
    \ t[v].left = l;\n        } else if (t[v].right && t[v].data[t[v].size - 1] <\
    \ x) {\n            int r = insert(t[v].right, x);\n            t[v].right = r;\n\
    \        } else {\n            done = node_insert(t[v], x);\n            if (t[v].size\
    \ == B) {\n                if (t[v].right) {\n                    // \u6700\u5927\
    \u306E\u8981\u7D20\u3092\u53F3\u90E8\u5206\u6728\u306E\u5148\u982D\u306B\u56DE\
    \u3059\n                    T y = t[v].data[--t[v].size];\n                  \
    \  int r = insert_leftmost(t[v].right, y);\n                    t[v].right = r;\n\
    \                } else {\n                    int u = split(v);\n           \
    \         update(u);\n                    t[v].right = u;\n                }\n\
    \            }\n        }\n        update(v);\n        return balance(v);\n  \
    \  }\n\n    // \u90E8\u5206\u6728 v \u306E\u6700\u3082\u5DE6\u306E\u30CE\u30FC\
    \u30C9\u3092\u5207\u308A\u96E2\u3059 (u \u306B\u5165\u308C\u308B)\uFF0E\u6B8B\u3063\
    \u305F\u90E8\u5206\u6728\u306E\u6839\u3092\u8FD4\u3059\n    int cut_leftmost(int\
    \ v, int &u) {\n        if (!t[v].left) {\n            u = v;\n            return\
    \ t[v].right;\n        }\n        int l = cut_leftmost(t[v].left, u);\n      \
    \  t[v].left = l;\n        update(v);\n        return balance(v);\n    }\n\n \
    \   int erase(int v, const T &x) {\n        if (!v) return 0;\n        if (x <\
    \ t[v].data[0]) {\n            int l = erase(t[v].left, x);\n            t[v].left\
    \ = l;\n        } else if (t[v].data[t[v].size - 1] < x) {\n            int r\
    \ = erase(t[v].right, x);\n            t[v].right = r;\n        } else {\n   \
    \         done = node_erase(t[v], x);\n            if (t[v].size == 0) {\n   \
    \             // \u7A7A\u306B\u306A\u3063\u305F\u30CE\u30FC\u30C9\u3092\u6728\u304B\
    \u3089\u5916\u3059\n                free_list.push_back(v);\n                if\
    \ (!t[v].left || !t[v].right) return t[v].left ? t[v].left : t[v].right;\n   \
    \             int u = 0;\n                int r = cut_leftmost(t[v].right, u);\n\
    \                t[u].left = t[v].left, t[u].right = r;\n                update(u);\n\
    \                return balance(u);\n            }\n        }\n        update(v);\n\
    \        return balance(v);\n    }\n};\n#line 4 \"test/ordered_set.test.cpp\"\n\
    \nint main() {\n    int n, q;\n    fin >> n >> q;\n    vector<int> a(n);\n   \
    \ fin >> a;\n    OrderedSet<int> st(a);\n    while (q--) {\n        int t, x;\n\
    \        fin >> t >> x;\n        if (t == 0) st.insert(x);\n        else if (t\
    \ == 1) st.erase(x);\n        else if (t == 2) fout << st.kth(x - 1) << '\\n';\n\
    \        else if (t == 3) fout << st.count_le(x) << '\\n';\n        else if (t\
    \ == 4) fout << st.max_le(x) << '\\n';\n        else fout << st.min_ge(x) << '\\\
    n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/ordered_set\"\n#include\
    \ \"../io/fastio.hpp\"\n#include \"../data_structure/ordered_set.hpp\"\n\nint\
    \ main() {\n    int n, q;\n    fin >> n >> q;\n    vector<int> a(n);\n    fin\
    \ >> a;\n    OrderedSet<int> st(a);\n    while (q--) {\n        int t, x;\n  \
    \      fin >> t >> x;\n        if (t == 0) st.insert(x);\n        else if (t ==\
    \ 1) st.erase(x);\n        else if (t == 2) fout << st.kth(x - 1) << '\\n';\n\
    \        else if (t == 3) fout << st.count_le(x) << '\\n';\n        else if (t\
    \ == 4) fout << st.max_le(x) << '\\n';\n        else fout << st.min_ge(x) << '\\\
    n';\n    }\n    return 0;\n}\n"
  dependsOn:
  - io/fastio.hpp
  - template.hpp
  - data_structure/ordered_set.hpp
  - template.hpp
  isVerificationFile: true
  path: test/ordered_set.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/ordered_set.test.cpp
layout: document
redirect_from:
- /verify/test/ordered_set.test.cpp
- /verify/test/ordered_set.test.cpp.html
title: test/ordered_set.test.cpp
---
