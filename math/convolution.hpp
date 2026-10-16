#pragma once
#include "../template.hpp"
#include "modint.hpp"

// https://github.com/winter-2521/cp-library

// 畳み込み c[k] = Σ_{i+j=k} a[i] b[j]
// convolve<mint>(a, b)    : mod が NTT 向きの素数 (998244353 など，mod - 1 が大きな 2 冪で割り切れる) のとき．数論変換 (NTT)
// convolve_ll(a, b)        : 整数のまま (結果が long long に収まること)．3 つの素数で NTT して中国剰余定理で復元
// convolve_small(a, b)     : 非負整数で，結果が 7.5 × 10^17 未満と分かっているとき．2 つの素数で済むので convolve_ll より速い
// 長さが小さいときは素朴な O(nm) の方が速いのでそちらを使う．O((n + m) log(n + m))
// 名前は ACL の convolution と衝突しないように convolve にしてある

namespace convolution_internal {
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    long long r = 1;
    x %= m;
    while (n) {
        if (n & 1) r = r * x % m;
        x = x * x % m, n >>= 1;
    }
    return r;
}
// 素数 m の原始根
constexpr int primitive_root(int m) {
    if (m == 2) return 1;
    int divs[20] = {};
    int cnt = 0, x = (m - 1) / 2;
    divs[cnt++] = 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)i * i <= x; i += 2)
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) x /= i;
        }
    if (x > 1) divs[cnt++] = x;
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt && ok; i++)
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) ok = false;
        if (ok) return g;
    }
}

// a を長さ n (2 冪) の NTT で変換する (inverse なら逆変換．1/n 倍はしない)
// ビット反転してから Cooley-Tukey．rt[k + j] = (2k 乗根)^j を長さに応じて伸ばして使い回す
template <class mint>
void ntt(vector<mint> &a, bool inverse) {
    static constexpr int MOD = mint::mod();
    static constexpr int G = primitive_root(MOD);
    static vector<mint> rt{mint(0), mint(1)};
    int n = a.size();
    if (n <= 1) return;
    if ((int)rt.size() < n) {
        int k = rt.size();
        rt.resize(n);
        for (; k < n; k *= 2) {
            // 2k 乗根
            mint z = mint(G).pow((MOD - 1) / (2 * k));
            for (int i = k / 2; i < k; i++) rt[2 * i] = rt[i], rt[2 * i + 1] = rt[i] * z;
        }
    }
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k)
            for (int j = 0; j < k; j++) {
                mint z = rt[j + k] * a[i + j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
    if (inverse) reverse(a.begin() + 1, a.end());
}
}  // namespace convolution_internal

template <class mint>
vector<mint> convolve(vector<mint> a, vector<mint> b) {
    using namespace convolution_internal;
    int n = a.size(), m = b.size();
    if (!n || !m) return {};
    if (std::min(n, m) <= 40) {
        vector<mint> c(n + m - 1, mint(0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) c[i + j] += a[i] * b[j];
        return c;
    }
    int sz = 1;
    while (sz < n + m - 1) sz <<= 1;
    bool same = (a == b);
    a.resize(sz), ntt(a, false);
    if (same) {
        for (int i = 0; i < sz; i++) a[i] *= a[i];
    } else {
        b.resize(sz), ntt(b, false);
        for (int i = 0; i < sz; i++) a[i] *= b[i];
    }
    ntt(a, true);
    mint inv = mint(sz).inv();
    a.resize(n + m - 1);
    for (auto &x : a) x *= inv;
    return a;
}

// 整数の畳み込み (結果が long long に収まること)
inline vector<long long> convolve_ll(const vector<long long> &a, const vector<long long> &b) {
    int n = a.size(), m = b.size();
    if (!n || !m) return {};
    if (std::min(n, m) <= 40) {
        vector<long long> c(n + m - 1, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) c[i + j] += a[i] * b[j];
        return c;
    }
    static constexpr unsigned long long M1 = 754974721, M2 = 167772161, M3 = 469762049;
    using m1 = ModInt<M1>;
    using m2 = ModInt<M2>;
    using m3 = ModInt<M3>;
    auto conv = [&](auto tag) {
        using mint = decltype(tag);
        vector<mint> x(n), y(m);
        for (int i = 0; i < n; i++) x[i] = mint(a[i]);
        for (int i = 0; i < m; i++) y[i] = mint(b[i]);
        return convolve(std::move(x), std::move(y));
    };
    auto c1 = conv(m1());
    auto c2 = conv(m2());
    auto c3 = conv(m3());
    // 中国剰余定理 (ACL と同じ方法)
    static constexpr unsigned long long M2M3 = M2 * M3, M1M3 = M1 * M3, M1M2 = M1 * M2, M1M2M3 = M1M2 * M3;
    static constexpr unsigned long long i1 = 190329765, i2 = 58587104, i3 = 187290749;  // (M_jM_k)^{-1} mod M_i
    vector<long long> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        unsigned long long x = 0;
        x += (c1[i].val() * i1) % M1 * M2M3;
        x += (c2[i].val() * i2) % M2 * M1M3;
        x += (c3[i].val() * i3) % M3 * M1M2;
        // 本当の値 v は x ≡ v (mod M1M2M3) で，x - v ∈ {0, M1M2M3, 2M1M2M3, 3M1M2M3, 4M1M2M3} (mod 2^64) のどれか．
        // (x - v) mod M1 で決まるので，v ≡ c1 (mod M1) から判定する
        long long r = (long long)x % (long long)M1;  // x を符号付きとして見た剰余 (ACL と同じ)
        if (r < 0) r += M1;
        long long diff = c1[i].val() - r;
        if (diff < 0) diff += M1;
        static constexpr unsigned long long offset[5] = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};
        x -= offset[diff % 5];
        c[i] = x;
    }
    return c;
}

// 非負整数の畳み込みで，結果の各項が 998244353 × 754974721 (≈ 7.5 × 10^17) 未満のとき
inline vector<long long> convolve_small(const vector<long long> &a, const vector<long long> &b) {
    int n = a.size(), m = b.size();
    if (!n || !m) return {};
    if (std::min(n, m) <= 40) {
        vector<long long> c(n + m - 1, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) c[i + j] += a[i] * b[j];
        return c;
    }
    static constexpr long long M1 = 998244353, M2 = 754974721;
    using m1 = ModInt<M1>;
    using m2 = ModInt<M2>;
    vector<m1> x1(n), y1(m);
    vector<m2> x2(n), y2(m);
    for (int i = 0; i < n; i++) x1[i] = m1(a[i]), x2[i] = m2(a[i]);
    for (int i = 0; i < m; i++) y1[i] = m1(b[i]), y2[i] = m2(b[i]);
    auto c1 = convolve(std::move(x1), std::move(y1));
    auto c2 = convolve(std::move(x2), std::move(y2));
    // v = r1 + M1 * ((r2 - r1) / M1 mod M2)
    static const m2 inv = m2(M1).inv();
    vector<long long> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        long long r1 = c1[i].val();
        long long t = ((m2(c2[i].val()) - m2(r1)) * inv).val();
        c[i] = r1 + M1 * t;
    }
    return c;
}
