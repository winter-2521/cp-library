#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 部分集合畳み込み h(S) = Σ_{T ⊆ S} f(T) g(S \ T)．O(n^2 2^n)
// 「ランク付きゼータ変換」: R[S][d] = Σ_{T ⊆ S, |T| = d} f(T) とすると，h の R は d について多項式の積になる．
// 各 S で多項式の積を取り，メビウス変換で戻して R[S][|S|] を取り出す
namespace subset_convolution_internal {
// 長さ 2^n の f を R[S * (n+1) + d] に
template <class mint>
vector<mint> ranked_zeta(const vector<mint> &f, int n) {
    int N = 1 << n, W = n + 1;
    vector<mint> R((size_t)N * W, mint(0));
    for (int s = 0; s < N; s++) R[(size_t)s * W + __builtin_popcount(s)] = f[s];
    // R[S][d] は d <= |S| でしか 0 でない
    for (int i = 0; i < n; i++)
        for (int s = 0; s < N; s++)
            if (s >> i & 1) {
                mint *t = &R[(size_t)s * W], *u = &R[(size_t)(s ^ (1 << i)) * W];
                int pc = __builtin_popcount(s);
                for (int d = 0; d < pc; d++) t[d] += u[d];
            }
    return R;
}
template <class mint>
vector<mint> ranked_mobius(vector<mint> &R, int n) {
    int N = 1 << n, W = n + 1;
    // 最後に使うのは R[S][|S|] で，それは部分集合 T の R[T][|S|] (|S| >= |T|) からしか作られないので，
    // 各 S について d >= |S| の段だけ計算すればよい
    for (int i = 0; i < n; i++)
        for (int s = 0; s < N; s++)
            if (s >> i & 1) {
                mint *t = &R[(size_t)s * W], *u = &R[(size_t)(s ^ (1 << i)) * W];
                for (int d = __builtin_popcount(s); d <= n; d++) t[d] -= u[d];
            }
    vector<mint> f(N);
    for (int s = 0; s < N; s++) f[s] = R[(size_t)s * W + __builtin_popcount(s)];
    return f;
}
// ランク付きゼータ変換どうしの積 (各 S で多項式の積．次数 n 以下だけ)
template <class mint>
void ranked_multiply(vector<mint> &A, const vector<mint> &B, int n) {
    // 必要なのは d >= |S| の段だけ．a, b は |S| 次までなので積は 2|S| 次まで
    // 積の和は剰余を取らずに 64 bit で足し，8 mod^2 を超えたら引く (mod < 2^30 を仮定)
    int N = 1 << n, W = n + 1;
    const unsigned long long M = mint::mod(), M8 = 8 * M * M;
    vector<unsigned long long> av(W), bv(W);
    for (int s = 0; s < N; s++) {
        mint *a = &A[(size_t)s * W];
        const mint *b = &B[(size_t)s * W];
        int pc = __builtin_popcount(s), hi = std::min(n, 2 * pc);
        for (int i = 0; i <= pc; i++) av[i] = a[i].val(), bv[i] = b[i].val();
        for (int d = hi; d >= pc; d--) {
            unsigned long long x = 0;
            for (int i = d - pc; i <= pc; i++) {
                x += av[i] * bv[d - i];
                if (x >= M8) x -= M8;
            }
            a[d] = mint(x % M);
        }
        for (int d = 0; d < pc; d++) a[d] = 0;
        for (int d = hi + 1; d <= n; d++) a[d] = 0;
    }
}
}  // namespace subset_convolution_internal

// f, g の長さは同じ 2 冪
template <class mint>
vector<mint> subset_convolution(const vector<mint> &f, const vector<mint> &g) {
    using namespace subset_convolution_internal;
    int n = __builtin_ctz(f.size());
    assert(f.size() == g.size() && (1u << n) == f.size());
    auto A = ranked_zeta(f, n), B = ranked_zeta(g, n);
    ranked_multiply(A, B, n);
    return ranked_mobius(A, n);
}
