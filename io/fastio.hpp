#pragma once
#include "../template.hpp"

// 高速入出力
// fin >> a >> b;  fout << a + b << '\n';  のように cin / cout と同じ感覚で使う
// cin / cout / scanf / printf と混ぜて使ってはいけない
// 入力はブロック単位で読むので，インタラクティブ問題には使えない

namespace fastio {

// 入出力バッファの大きさ
constexpr size_t BUF_SIZE = 1 << 17;

// 0000 ~ 9999 の 4 桁の文字列を前計算しておく表
struct DigitTable {
    char d[10000][4];
    constexpr DigitTable() : d() {
        for (int i = 0; i < 10000; i++) {
            int x = i;
            for (int j = 3; j >= 0; j--) d[i][j] = char('0' + x % 10), x /= 10;
        }
    }
};
inline constexpr DigitTable digit_table{};

// __int128 は -std=c++17 (gnu 拡張なし) だと is_integral にならないので自前で判定する
template <class T> struct is_int128 : false_type {};
template <> struct is_int128<__int128> : true_type {};
template <> struct is_int128<unsigned __int128> : true_type {};

// 符号付き整数型に対応する符号なし整数型
template <class T> struct unsigned_of { using type = make_unsigned_t<T>; };
template <> struct unsigned_of<__int128> { using type = unsigned __int128; };
template <class T> using unsigned_of_t = typename unsigned_of<T>::type;

template <class T> constexpr bool is_integer_v = (is_integral_v<T> && !is_same_v<T, bool> && !is_same_v<T, char>) || is_int128<T>::value;
template <class T> constexpr bool is_signed_integer_v = is_same_v<T, __int128> || (is_integral_v<T> && is_signed_v<T>);

struct Reader {
    // 数値を読む前に常に TOKEN_MARGIN 文字以上が buf に残っているようにして，数値の読み込み中の境界チェックを省く
    static constexpr size_t TOKEN_MARGIN = 64;
    char buf[BUF_SIZE + TOKEN_MARGIN + 8];
    size_t pos = 0, len = 0;
    bool eof = false;

    // 未読部分を先頭に寄せてから読み足す
    void refill() {
        size_t rem = len - pos;
        memmove(buf, buf + pos, rem);
        pos = 0, len = rem;
        while (!eof && len < TOKEN_MARGIN) {
            size_t r = fread(buf + len, 1, BUF_SIZE - len, stdin);
            if (r == 0) eof = true;
            len += r;
        }
        // 8 バイト単位で数字を読むときに末尾の先を読んでも止まるよう番兵を置く
        memset(buf + len, 0, 8);
    }

    // 空白を読み飛ばす．読み終わった後は TOKEN_MARGIN 文字以上(または EOF まで)が残っている
    void skip_space() {
        while (true) {
            if (len - pos < TOKEN_MARGIN && !eof) refill();
            while (pos < len && (unsigned char)buf[pos] <= ' ') pos++;
            if (pos < len || eof) break;
        }
        if (len - pos < TOKEN_MARGIN && !eof) refill();
    }

    // 8 バイトがすべて '0'~'9' か判定
    static bool is_8digits(uint64_t v) {
        return ((v & 0xF0F0F0F0F0F0F0F0ULL) | (((v + 0x0606060606060606ULL) & 0xF0F0F0F0F0F0F0F0ULL) >> 4)) == 0x3333333333333333ULL;
    }

    // 8 桁の数字列 (先頭の桁が下位バイト) を整数に変換 (SWAR)
    static uint32_t parse_8digits(uint64_t v) {
        v -= 0x3030303030303030ULL;
        v = (v * 10 + (v >> 8)) & 0x00FF00FF00FF00FFULL;
        v = (v * 100 + (v >> 16)) & 0x0000FFFF0000FFFFULL;
        v = (v * 10000 + (v >> 32)) & 0x00000000FFFFFFFFULL;
        return uint32_t(v);
    }

    template <class U> U read_unsigned() {
        U r = 0;
        const char *p = buf + pos;
        uint64_t v;
        memcpy(&v, p, 8);
        while (is_8digits(v)) {
            r = r * 100000000 + parse_8digits(v);
            p += 8;
            memcpy(&v, p, 8);
        }
        while (uint32_t(*p - '0') < 10) r = r * 10 + (*p++ - '0');
        pos = p - buf;
        return r;
    }

    template <class T> void read_integer(T &x) {
        skip_space();
        if constexpr (is_signed_integer_v<T>) {
            using U = unsigned_of_t<T>;
            bool neg = buf[pos] == '-';
            pos += neg;
            U r = read_unsigned<U>();
            x = T(neg ? U(0) - r : r);
        } else {
            x = read_unsigned<T>();
        }
    }

    void read_char(char &c) {
        skip_space();
        c = buf[pos++];
    }

    void read_string(string &s) {
        skip_space();
        s.clear();
        while (true) {
            size_t st = pos;
            while (pos < len && (unsigned char)buf[pos] > ' ') pos++;
            s.append(buf + st, pos - st);
            if (pos < len || eof) break;
            refill();
            if (pos == len) break;
        }
    }

    template <class T> void read_float(T &x) {
        skip_space();
        char *end;
        x = T(strtold(buf + pos, &end));
        pos = end - buf;
    }

    template <class T> Reader &operator>>(T &x) {
        if constexpr (is_integer_v<T>) read_integer(x);
        else if constexpr (is_same_v<T, char>) read_char(x);
        else if constexpr (is_same_v<T, string>) read_string(x);
        else if constexpr (is_floating_point_v<T>) read_float(x);
        else if constexpr (is_same_v<T, bool>) { int t; read_integer(t); x = t; }
        else static_assert(is_integer_v<T>, "fastio: unsupported type");
        return *this;
    }

    template <class T> Reader &operator>>(vector<T> &v) {
        for (auto &e : v) *this >> e;
        return *this;
    }

    template <class T, class U> Reader &operator>>(pair<T, U> &p) { return *this >> p.first >> p.second; }

    template <class T> T read() {
        T x;
        *this >> x;
        return x;
    }
};

struct Writer {
    // 1 トークンの書き込みでは境界チェックをせず，書いた後にまとめて flush 判定する
    static constexpr size_t TOKEN_MARGIN = 128;
    char buf[BUF_SIZE + TOKEN_MARGIN];
    size_t pos = 0;
    int precision = 15;

    ~Writer() { flush(); }

    void flush() {
        fwrite(buf, 1, pos, stdout);
        pos = 0;
        fflush(stdout);
    }

    void check_flush() {
        if (pos >= BUF_SIZE) flush();
    }

    void write_char(char c) {
        buf[pos++] = c;
        check_flush();
    }

    // 10^16 未満の x をちょうど 16 桁 (0 埋め) で書く
    void write_16digits(uint64_t x) {
        uint64_t hi = x / 100000000, lo = x % 100000000;
        memcpy(buf + pos, digit_table.d[hi / 10000], 4);
        memcpy(buf + pos + 4, digit_table.d[hi % 10000], 4);
        memcpy(buf + pos + 8, digit_table.d[lo / 10000], 4);
        memcpy(buf + pos + 12, digit_table.d[lo % 10000], 4);
        pos += 16;
    }

    void write_u64(uint64_t x) {
        // 下位から 4 桁ずつ一時領域に書き，最後に先頭の 1~4 桁を書く
        char tmp[20];
        int i = 20;
        while (x >= 10000) {
            memcpy(tmp + i - 4, digit_table.d[x % 10000], 4);
            i -= 4;
            x /= 10000;
        }
        int k = x >= 1000 ? 4 : x >= 100 ? 3 : x >= 10 ? 2 : 1;
        memcpy(tmp + i - k, digit_table.d[x] + 4 - k, k);
        i -= k;
        memcpy(buf + pos, tmp + i, 20 - i);
        pos += 20 - i;
    }

    void write_u128(unsigned __int128 x) {
        if (x >> 64 == 0) return write_u64(uint64_t(x));
        constexpr uint64_t P16 = 10000000000000000ULL;
        uint64_t lo = uint64_t(x % P16);
        x /= P16;
        if (x >> 64 == 0) {
            write_u64(uint64_t(x));
        } else {
            // 2^128 / 10^32 < 10^7 なので最上位は 64 bit に収まる
            uint64_t mid = uint64_t(x % P16);
            write_u64(uint64_t(x / P16));
            write_16digits(mid);
        }
        write_16digits(lo);
    }

    template <class T> void write_integer(T x) {
        if constexpr (is_signed_integer_v<T>) {
            using U = unsigned_of_t<T>;
            U u = U(x);
            if (x < 0) buf[pos++] = '-', u = U(0) - u;
            write_integer(u);
        } else if constexpr (is_int128<T>::value) {
            write_u128(x);
        } else {
            write_u64(x);
        }
    }

    void write_string(const char *s, size_t n) {
        while (n > 0) {
            size_t k = min(n, BUF_SIZE - pos);
            memcpy(buf + pos, s, k);
            pos += k, s += k, n -= k;
            check_flush();
        }
    }

    template <class T> void write_float(T x) {
        char tmp[64];
        int n = snprintf(tmp, sizeof(tmp), "%.*Lf", precision, (long double)x);
        if (n < (int)sizeof(tmp)) return write_string(tmp, n);
        // 桁数が多すぎるときだけ動的に確保する
        string t(n + 1, '\0');
        snprintf(t.data(), n + 1, "%.*Lf", precision, (long double)x);
        write_string(t.data(), n);
    }

    void set_precision(int p) { precision = p; }

    template <class T> Writer &operator<<(const T &x) {
        if constexpr (is_integer_v<T>) write_integer(x), check_flush();
        else if constexpr (is_same_v<T, char>) write_char(x);
        else if constexpr (is_same_v<T, bool>) write_char(char('0' + x));
        else if constexpr (is_same_v<T, string>) write_string(x.data(), x.size());
        else if constexpr (is_same_v<T, string_view>) write_string(x.data(), x.size());
        else if constexpr (is_convertible_v<T, const char *>) { const char *s = x; write_string(s, strlen(s)); }
        else if constexpr (is_floating_point_v<T>) write_float(x);
        else static_assert(is_integer_v<T>, "fastio: unsupported type");
        return *this;
    }

    // vector は空白区切りで出力する
    template <class T> Writer &operator<<(const vector<T> &v) {
        for (size_t i = 0; i < v.size(); i++) {
            if (i) write_char(' ');
            *this << v[i];
        }
        return *this;
    }
};

inline Reader fin;
inline Writer fout;

}  // namespace fastio

using fastio::fin;
using fastio::fout;
