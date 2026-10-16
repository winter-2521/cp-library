#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 行列式 (mod 素数)．ガウスの消去法で上三角にして対角成分の積．O(n^3)
// 行を入れ替えたら符号を反転する．ピボットの逆元は列ごとに 1 回だけ求める
template <class mint>
mint determinant(vector<vector<mint>> a) {
    int n = a.size();
    mint res = 1;
    for (int c = 0; c < n; c++) {
        int p = c;
        while (p < n && a[p][c] == mint(0)) p++;
        if (p == n) return mint(0);
        if (p != c) swap(a[p], a[c]), res = -res;
        res *= a[c][c];
        mint inv = a[c][c].inv();
        const mint *rc = a[c].data();
        for (int r = c + 1; r < n; r++) {
            if (a[r][c] == mint(0)) continue;
            mint f = a[r][c] * inv;
            mint *rr = a[r].data();
            for (int k = c; k < n; k++) rr[k] -= f * rc[k];
        }
    }
    return res;
}
