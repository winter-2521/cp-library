#pragma once
#include "../template.hpp"

// 静的な数列の区間転倒数 (Static Range Inversions Query)．オンライン，平方分割
// ブロックの大きさを B，個数を nb とする．前計算:
//   lt[R][i] = #{j : block(i) < block(j) < R, a[j] < a[i]}   (i より右，ブロック R の手前までで a[i] より小さいもの)
//   gt[L][j] = #{i : L <= block(i) < block(j), a[i] > a[j]}  (ブロック L から j の手前のブロックまでで a[j] より大きいもの)
//   big[L][R] = ブロック L..R-1 の中の転倒数
//   pre[i], suf[i] = i のブロック内で [ブロック先頭, i] / [i, ブロック末尾) の転倒数
//   各ブロックの (値, 位置) の昇順リスト
// クエリは「左の端・右の端・間の完全なブロック」に分けて数える．lt / gt は位置の順に並べてあるので，端の要素を順に見るとき連続アクセスになる
// 構築 O(n √n)，クエリ O(√n)，メモリ O(n √n)
template <class T>
struct StaticRangeInversions {
    int n, B, nb;
    vector<int> c;                    // 圧縮後の値
    vector<int> lt, gt;               // lt[R * n + i], gt[L * n + j]
    vector<long long> big;            // big[L * (nb + 1) + R]
    vector<long long> pre, suf;
    vector<pair<int, int>> sorted_;   // ブロックごとに (値, 位置) を昇順に並べたもの

    StaticRangeInversions(const vector<T> &a, int block = -1) : n(a.size()) {
        vector<T> vals = a;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        c.resize(n);
        for (int i = 0; i < n; i++) c[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
        B = block > 0 ? block : std::max(16, (int)(1.25 * sqrt(n)));
        nb = std::max(1, (n + B - 1) / B);
        sorted_.resize(n);
        for (int i = 0; i < n; i++) sorted_[i] = {c[i], i};
        for (int b = 0; b < nb; b++) sort(sorted_.begin() + std::min(n, b * B), sorted_.begin() + std::min(n, (b + 1) * B));
        vector<pair<int, int>> all = sorted_;  // 全体を (値, 位置) の昇順に
        sort(all.begin(), all.end());
        // lt[R][i] = lt[R-1][i] + #{j ∈ ブロック R-1 : c[j] < c[i]} (block(i) < R-1 のとき)
        lt.assign((size_t)(nb + 1) * n, 0);
        for (int R = 2; R <= nb; R++) {
            int *cur = &lt[(size_t)R * n], *prv = &lt[(size_t)(R - 1) * n];
            int bs = (R - 1) * B, be = std::min(n, R * B), p = bs;
            for (auto [v, i] : all) {
                while (p < be && sorted_[p].first < v) p++;
                if (i < bs) cur[i] = prv[i] + (p - bs);
            }
        }
        // gt[L][j] = gt[L+1][j] + #{i ∈ ブロック L : c[i] > c[j]} (block(j) > L のとき)
        gt.assign((size_t)(nb + 1) * n, 0);
        for (int L = nb - 2; L >= 0; L--) {
            int *cur = &gt[(size_t)L * n], *nxt = &gt[(size_t)(L + 1) * n];
            int bs = L * B, be = std::min(n, (L + 1) * B), p = bs;
            for (auto [v, j] : all) {
                while (p < be && sorted_[p].first <= v) p++;
                if (j >= be) cur[j] = nxt[j] + (be - p);
            }
        }
        // ブロック内の転倒数
        pre.assign(n, 0), suf.assign(n, 0);
        for (int b = 0; b < nb; b++) {
            int s = b * B, e = std::min(n, (b + 1) * B);
            for (int i = s; i < e; i++) {
                long long x = i > s ? pre[i - 1] : 0;
                for (int j = s; j < i; j++) x += c[j] > c[i];
                pre[i] = x;
            }
            for (int i = e - 1; i >= s; i--) {
                long long x = i + 1 < e ? suf[i + 1] : 0;
                for (int j = i + 1; j < e; j++) x += c[i] > c[j];
                suf[i] = x;
            }
        }
        // big[L][R] = big[L][R-1] + big[L+1][R] - big[L+1][R-1] + (ブロック L の要素 > ブロック R-1 の要素 の組)
        big.assign((size_t)(nb + 1) * (nb + 1), 0);
        auto BIG = [&](int L, int R) -> long long & { return big[(size_t)L * (nb + 1) + R]; };
        for (int L = nb - 1; L >= 0; L--) {
            if (L * B < n) BIG(L, L + 1) = suf[L * B];
            for (int R = L + 2; R <= nb; R++) {
                long long cross = 0;
                const int *hi = &lt[(size_t)R * n], *lo = &lt[(size_t)(R - 1) * n];
                for (int i = L * B; i < (L + 1) * B; i++) cross += hi[i] - lo[i];
                BIG(L, R) = BIG(L, R - 1) + BIG(L + 1, R) - BIG(L + 1, R - 1) + cross;
            }
        }
    }

    // a[l..r) の転倒数
    long long query(int l, int r) const {
        if (r - l <= 1) return 0;
        int lb = l / B, rb = (r - 1) / B;
        if (lb == rb) {
            int s = lb * B, e = std::min(n, s + B);
            long long res = pre[r - 1] - (l > s ? pre[l - 1] : 0);
            // [s, l) の要素 > [l, r) の要素 の組を引く (値の昇順に見る．同じ値は位置の昇順なので数えない)
            int seen = 0;
            for (int k = s; k < e; k++) {
                int i = sorted_[k].second;
                if (i < l) res -= seen;
                else if (i < r) seen++;
            }
            return res;
        }
        long long res = suf[l] + pre[r - 1] + big[(size_t)(lb + 1) * (nb + 1) + rb];
        const int *ltr = &lt[(size_t)rb * n], *gtl = &gt[(size_t)(lb + 1) * n];
        for (int i = l; i < (lb + 1) * B; i++) res += ltr[i];
        for (int j = rb * B; j < r; j++) res += gtl[j];
        // 左の端の要素 > 右の端の要素 の組 (どちらも値の昇順に見る)
        int ls = lb * B, le = (lb + 1) * B, rs = rb * B, re = std::min(n, rs + B);
        int p = rs, smaller = 0;
        for (int k = ls; k < le; k++) {
            if (sorted_[k].second < l) continue;
            int v = sorted_[k].first;
            while (p < re && sorted_[p].first < v) {
                if (sorted_[p].second < r) smaller++;
                p++;
            }
            res += smaller;
        }
        return res;
    }
};
