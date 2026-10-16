#pragma once
#include "../template.hpp"
#include "../math/subset_convolution.hpp"

// https://github.com/winter-2521/cp-library

// 彩色数・彩色多項式 (n <= 20 程度)
// I(S) = 「頂点集合 S に含まれる独立集合 (空集合も含む) の個数」は
// 「S の最小の頂点 v を使わない: I(S \ v)」+「使う: I(S \ N[v])」で全 S について O(2^n)

namespace chromatic_internal {
// 全ての S について I(S)．自己ループのある頂点は独立集合に入れられない
inline vector<uint32_t> count_independent_sets(int n, const vector<pair<int, int>> &edges) {
    vector<uint32_t> nb(n, 0);
    for (auto [a, b] : edges) nb[a] |= 1u << b, nb[b] |= 1u << a;
    vector<uint32_t> I(1u << n);
    I[0] = 1;
    for (uint32_t S = 1; S < (1u << n); S++) {
        int v = __builtin_ctz(S);
        uint32_t rest = S & (S - 1);
        I[S] = I[rest] + ((nb[v] >> v & 1) ? 0 : I[rest & ~nb[v]]);
    }
    return I;
}
}  // namespace chromatic_internal

// 彩色数 (辺がなければ 1，n = 0 なら 0)．自己ループがあれば -1
// c(k) = Σ_{S ⊆ V} (-1)^{n - |S|} I(S)^k は「k 個の独立集合 (重なってもよい) の組で，和集合が V 全体のもの」の個数 (包除原理)．
// 重なりは小さい独立集合に削れるので，c(k) > 0 ⇔ k 色で塗れる．
// c(k) を k = 1, 2, ... の順に 2^61 - 1 を法として計算し，最初に 0 でなくなる k を返す．O(2^n χ)
inline int chromatic_number(int n, const vector<pair<int, int>> &edges) {
    if (n == 0) return 0;
    for (auto [a, b] : edges)
        if (a == b) return -1;
    auto I = chromatic_internal::count_independent_sets(n, edges);
    using u64 = unsigned long long;
    const u64 MOD = (1ULL << 61) - 1;
    auto mul = [&](u64 a, u64 b) {
        unsigned __int128 t = (unsigned __int128)a * b;
        u64 r = (u64)(t >> 61) + (u64)(t & MOD);
        return r >= MOD ? r - MOD : r;
    };
    vector<u64> pw(1u << n, 1);
    for (int k = 1; k < n; k++) {
        u64 pos = 0, neg = 0;
        for (uint32_t S = 0; S < (1u << n); S++) {
            pw[S] = mul(pw[S], I[S]);
            if ((n - __builtin_popcount(S)) & 1) {
                neg += pw[S];
                if (neg >= MOD) neg -= MOD;
            } else {
                pos += pw[S];
                if (pos >= MOD) pos -= MOD;
            }
        }
        if (pos != neg) return k;
    }
    return n;
}

// 彩色多項式 P(x) = p_0 + p_1 x + ... + p_n x^n の係数 (mint)．O(n^2 2^n)
// a_m = 「頂点全体を m 個の (空でない) 独立集合に分ける方法の数」とすると P(x) = Σ_m a_m x(x-1)...(x-m+1)
// a_m = (s^m / m!)(V) (s = 空でない独立集合の指示関数，積は部分集合畳み込み) を m = 0..n について同時に求める．
// 「V の最大の要素を含むブロック」で分けると (s^m/m!)(U) = Σ_{T ∋ max U} s(T) (s^{m-1}/(m-1)!)(U \ T) なので，
// 重み w (最初は V だけ 1) との内積 <w, s^m/m!> を「最大の要素が j のブロックを 1 つ外す」転置した部分集合畳み込みで
// <w', s^{m-1}/(m-1)!> (宇宙が 1 つ小さい) に移していける (転置原理)
template <class mint>
vector<mint> chromatic_polynomial(int n, const vector<pair<int, int>> &edges) {
    using namespace subset_convolution_internal;
    vector<mint> res(n + 1, mint(0));
    if (n == 0) {
        res[0] = 1;
        return res;
    }
    // s(T) = 1 (T が空でない独立集合)
    vector<uint32_t> nb(n, 0);
    for (auto [a, b] : edges) nb[a] |= 1u << b, nb[b] |= 1u << a;
    vector<char> indep(1u << n, 0);
    indep[0] = 1;
    for (uint32_t T = 1; T < (1u << n); T++) {
        int v = 31 - __builtin_clz(T);
        uint32_t rest = T ^ (1u << v);
        indep[T] = indep[rest] && !(nb[v] & (rest | 1u << v));
    }
    // ブロック j (最大の要素が j) の s のランク付きゼータ変換を先に作っておく
    vector<vector<mint>> RS(n);
    for (int j = 0; j < n; j++) {
        vector<mint> a(1u << j);
        for (uint32_t t = 0; t < (1u << j); t++) a[t] = indep[(1u << j) | t] ? 1 : 0;
        RS[j] = ranked_zeta(a, j);
    }
    vector<mint> a(n + 1, mint(0));  // a[m]
    vector<mint> dp(1u << n, mint(0));
    dp.back() = 1;
    for (int i = 0; i < n; i++) {
        int k = n - i;  // 今の宇宙の大きさ
        vector<mint> nd(1u << (k - 1), mint(0));
        for (int j = 0; j < k; j++) {
            // 転置: y(T) = Σ_{U ⊇ T, U ⊆ [0,j)} dp(2^j + U) s(2^j + (U \ T))
            //        = rev(subset_conv(rev(x), s_j))(T)  (rev は補集合)
            uint32_t sz = 1u << j;
            vector<mint> x(sz);
            for (uint32_t t = 0; t < sz; t++) x[t] = dp[sz + (sz - 1 - t)];
            auto RX = ranked_zeta(x, j);
            ranked_multiply(RX, RS[j], j);
            auto y = ranked_mobius(RX, j);
            for (uint32_t t = 0; t < sz; t++) nd[t] += y[sz - 1 - t];
        }
        dp.swap(nd);
        a[i + 1] = dp[0];
    }
    // 下降階乗 x(x-1)...(x-m+1) を足し合わせる
    vector<mint> ff(n + 1, mint(0));
    ff[0] = 1;
    for (int m = 0; m <= n; m++) {
        for (int d = 0; d <= m; d++) res[d] += a[m] * ff[d];
        // ff *= (x - m)
        for (int d = m + 1; d >= 1; d--)
            if (d <= n) ff[d] = ff[d - 1] - ff[d] * mint(m);
        ff[0] = -ff[0] * mint(m);
    }
    return res;
}
