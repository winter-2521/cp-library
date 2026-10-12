#pragma once
#include "../template.hpp"

// 法 MOD が コンパイル時定数の modint
// MOD < 2^31 であること (素数でなくてもよい．ただし inv() は MOD と互いに素な値に対してのみ有効)
// インターフェースは ACL (atcoder::static_modint) と揃えてある．
// このライブラリの他のファイル (fastio など) は ACL の modint でもそのまま動く
template <uint32_t MOD>
struct ModInt {
    static_assert(1 <= MOD && MOD < (1u << 31), "MOD must be in [1, 2^31)");
    using mint = ModInt;
    uint32_t v;

    static constexpr int mod() { return MOD; }

    constexpr ModInt() : v(0) {}

    template <class T, enable_if_t<is_integral_v<T>, nullptr_t> = nullptr>
    constexpr ModInt(T x) : v(0) {
        if constexpr (is_signed_v<T>) {
            long long y = (long long)(x % (long long)MOD);
            if (y < 0) y += MOD;
            v = uint32_t(y);
        } else {
            v = uint32_t(x % MOD);
        }
    }

    // 0 <= x < MOD が分かっているときに剰余を取らずに作る
    static constexpr mint raw(int x) {
        mint r;
        r.v = x;
        return r;
    }

    constexpr unsigned int val() const { return v; }

    constexpr mint &operator+=(const mint &r) {
        v += r.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    constexpr mint &operator-=(const mint &r) {
        v += MOD - r.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    constexpr mint &operator*=(const mint &r) {
        // MOD が定数なので % は乗算とシフトに最適化される
        v = uint32_t((uint64_t)v * r.v % MOD);
        return *this;
    }
    constexpr mint &operator/=(const mint &r) { return *this *= r.inv(); }

    constexpr mint operator+() const { return *this; }
    constexpr mint operator-() const { return raw(v == 0 ? 0 : MOD - v); }

    constexpr mint &operator++() { return *this += raw(1); }
    constexpr mint &operator--() { return *this -= raw(1); }
    constexpr mint operator++(int) { mint r = *this; ++*this; return r; }
    constexpr mint operator--(int) { mint r = *this; --*this; return r; }

    friend constexpr mint operator+(mint l, const mint &r) { return l += r; }
    friend constexpr mint operator-(mint l, const mint &r) { return l -= r; }
    friend constexpr mint operator*(mint l, const mint &r) { return l *= r; }
    friend constexpr mint operator/(mint l, const mint &r) { return l /= r; }
    friend constexpr bool operator==(const mint &l, const mint &r) { return l.v == r.v; }
    friend constexpr bool operator!=(const mint &l, const mint &r) { return l.v != r.v; }

    // this^n (n < 0 なら逆元の -n 乗)
    constexpr mint pow(long long n) const {
        mint x = n >= 0 ? *this : inv(), r = raw(1 % MOD);
        unsigned long long e = n >= 0 ? (unsigned long long)n : 0ULL - (unsigned long long)n;
        while (e) {
            if (e & 1) r *= x;
            x *= x;
            e >>= 1;
        }
        return r;
    }

    // 拡張ユークリッドの互除法による逆元 (MOD が素数でなくても gcd(v, MOD) = 1 なら正しい)
    constexpr mint inv() const {
        long long a = v, b = MOD, x = 1, y = 0;
        while (b) {
            long long t = a / b;
            a -= t * b, swap(a, b);
            x -= t * y, swap(x, y);
        }
        assert(a == 1);
        return mint(x);
    }

    friend ostream &operator<<(ostream &os, const mint &x) { return os << x.v; }
    friend istream &operator>>(istream &is, mint &x) {
        long long t;
        is >> t;
        x = mint(t);
        return is;
    }
};

using ModInt998244353 = ModInt<998244353>;
using ModInt1000000007 = ModInt<1000000007>;
