#pragma once
#include "../template.hpp"
#include "wavelet_matrix.hpp"

// 区間 LIS (Static Range LIS Query)．Seaweed 法 (Tiskin)
// 数列 a の各区間 [l, r) の最長狭義増加部分列の長さを，前計算 O(n log^2 n)・クエリ O(log n) で答える (オンライン)
//
// 位置を列，値を行とする n × n の格子で「a[j] = 値 の升だけ一致」とした LCS の seaweed (ひも) を考える．
// 上辺の列 j から入ったひもが下辺の列 end[j] に出るとき，LIS(a[l..r)) = (r - l) - #{j ∈ [l, r) : end[j] < r}
// ひも全体の行き先 (置換) は「値で上下半分に分けて再帰 → unit-Monge 積 (steady ant) で合成」で求める
namespace seaweed_internal {

// 作業領域 (再帰の中で LIFO に確保・解放する)
struct Arena {
    vector<int> buf;
    size_t top = 0;
    int *alloc(size_t n) {
        assert(top + n <= buf.size());  // 確保し直すとポインタが無効になるので，最初に十分確保しておく
        int *p = buf.data() + top;
        top += n;
        return p;
    }
};

// 0-Hecke (sticky) 積．a を先に，b を後に適用した置換 (どちらも始点 → 終点) を res に書く．O(n log n)
// a, b, res は arena の外 (または呼び出し側が確保済み) の領域
inline void sticky_product_rec(const int *a, const int *b, int *res, int n, Arena &ar) {
    if (n == 1) {
        res[0] = 0;
        return;
    }
    if (n <= 32) {
        // 小さいときは直接: b をバブルソートで隣接互換の列に分解し，a の配置に「まだ交差していなければ交差」で適用する
        int at[32], tb[32], word[32 * 31 / 2], len = 0;
        for (int i = 0; i < n; i++) at[a[i]] = i, tb[b[i]] = i;
        for (int i = 0; i < n; i++)
            for (int p = 0; p + 1 < n - i; p++)
                if (tb[p] > tb[p + 1]) swap(tb[p], tb[p + 1]), word[len++] = p;
        for (int t = len - 1; t >= 0; t--) {
            int p = word[t];
            if (at[p] < at[p + 1]) swap(at[p], at[p + 1]);
        }
        for (int x = 0; x < n; x++) res[at[x]] = x;
        return;
    }
    size_t saved = ar.top;
    int h = n / 2;
    int *rows_lo = ar.alloc(h), *rows_hi = ar.alloc(n - h), *a_lo = ar.alloc(h), *a_hi = ar.alloc(n - h);
    int nl = 0, nh = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < h) rows_lo[nl] = i, a_lo[nl++] = a[i];
        else rows_hi[nh] = i, a_hi[nh++] = a[i] - h;
    }
    // b の行 [0, h) / [h, n) の終点を圧縮
    int *cid = ar.alloc(n), *cols_lo = ar.alloc(h), *cols_hi = ar.alloc(n - h);
    for (int c = 0; c < n; c++) cid[c] = -1;
    for (int j = 0; j < h; j++) cid[b[j]] = 0;
    nl = nh = 0;
    for (int c = 0; c < n; c++) {
        if (cid[c] == 0) cid[c] = nl, cols_lo[nl++] = c;
        else cid[c] = nh, cols_hi[nh++] = c;
    }
    int *b_lo = ar.alloc(h), *b_hi = ar.alloc(n - h);
    for (int j = 0; j < h; j++) b_lo[j] = cid[b[j]];
    for (int j = h; j < n; j++) b_hi[j - h] = cid[b[j]];
    int *r_lo = ar.alloc(h), *r_hi = ar.alloc(n - h);
    sticky_product_rec(a_lo, b_lo, r_lo, h, ar);
    sticky_product_rec(a_hi, b_hi, r_hi, n - h, ar);

    // 赤 (lo) と青 (hi) の点を合わせる．各行・各列にちょうど 1 点
    int *rowcol = ar.alloc(n), *colrow = ar.alloc(n), *red = ar.alloc(n), *K = ar.alloc(n + 1);
    for (int x = 0; x < h; x++) {
        int r = rows_lo[x], c = cols_lo[r_lo[x]];
        rowcol[r] = c, colrow[c] = r, red[r] = 1;
    }
    for (int x = 0; x < n - h; x++) {
        int r = rows_hi[x], c = cols_hi[r_hi[x]];
        rowcol[r] = c, colrow[c] = r, red[r] = 0;
    }
    // δ(i, k) = #{青: 行 < i, 列 < k} - #{赤: 行 >= i, 列 >= k}
    // δ < 0 の領域では赤，δ >= 0 の領域では青を採用し，境界の升だけ計算し直す
    // K[i] = δ(i, k) >= 0 となる最小の k (蟻が境界を (n, 0) から (0, n) まで歩いて求める)
    auto colstep = [&](int i, int k) {  // δ(i, k+1) - δ(i, k)
        int r = colrow[k];
        return red[r] ? int(r >= i) : int(r < i);
    };
    {
        int i = n, k = 0, d = 0;
        K[n] = 0;
        while (i > 0) {
            int r = i - 1, c = rowcol[r];
            int t = red[r] ? int(c >= k) : int(c < k);  // δ(i, k) - δ(i-1, k)
            if (d - t >= 0) d -= t, K[--i] = k;
            else d += colstep(i, k), k++;
        }
    }
    int *dr = ar.alloc(n + 2), *dr1 = ar.alloc(n + 2);
    for (int r = 0; r < n; r++) {
        int c = rowcol[r];
        if (red[r] ? c + 1 < K[r + 1] : c >= K[r]) res[r] = c;
        int lo = std::max(K[r + 1] - 1, 0), hi = K[r] - 1;
        if (lo > hi) continue;
        // dr[k - lo] = δ(r, k)，dr1[k - lo] = δ(r + 1, k) (k ∈ [lo, hi + 1])
        dr[K[r] - lo] = 0;
        for (int k = K[r] - 1; k >= lo; k--) dr[k - lo] = dr[k + 1 - lo] - colstep(r, k);
        dr1[K[r + 1] - lo] = 0;
        if (lo == K[r + 1] - 1) dr1[0] = -colstep(r + 1, lo);
        for (int k = K[r + 1]; k <= hi; k++) dr1[k + 1 - lo] = dr1[k - lo] + colstep(r + 1, k);
        auto m = [](int x) { return x < 0 ? x : 0; };
        for (int cc = lo; cc <= hi; cc++) {
            int v = int(!red[r] && c == cc) + m(dr[cc + 1 - lo]) - m(dr1[cc + 1 - lo]) - m(dr[cc - lo]) + m(dr1[cc - lo]);
            if (v) res[r] = cc;
        }
    }
    ar.top = saved;
}

inline vector<int> sticky_product(const vector<int> &a, const vector<int> &b) {
    int n = a.size();
    vector<int> res(n);
    if (n == 0) return res;
    Arena ar;
    ar.buf.resize(40 * (size_t)n + 256);  // 1 段で約 17n，再帰全体で約 34n
    sticky_product_rec(a.data(), b.data(), res.data(), n, ar);
    return res;
}

// 順列 q (列 j の値 q[j]) の seaweed の行き先 (大きさ 2m) を out に書く
// 始点: 左辺の行 i は m-1-i，上辺の列 j は m+j．終点: 下辺の列 j は j，右辺の行 i は m+(m-1-i)
inline void seaweed_rec(const int *q, int m, int *out, Arena &ar) {
    if (m == 1) {  // 一致する升: ひもは交差しない
        out[0] = 0, out[1] = 1;
        return;
    }
    size_t saved = ar.top;
    int h = m / 2;
    int *cols_lo = ar.alloc(h), *cols_hi = ar.alloc(m - h), *q_lo = ar.alloc(h), *q_hi = ar.alloc(m - h);
    int nl = 0, nh = 0;
    for (int j = 0; j < m; j++) {
        if (q[j] < h) cols_lo[nl] = j, q_lo[nl++] = q[j];
        else cols_hi[nh] = j, q_hi[nh++] = q[j] - h;
    }
    int *k_lo = ar.alloc(2 * h), *k_hi = ar.alloc(2 * (m - h));
    seaweed_rec(q_lo, h, k_lo, ar);
    seaweed_rec(q_hi, m - h, k_hi, ar);
    // 圧縮した列のブロックを m 列に広げる (一致のない列のひもはまっすぐ下に抜ける)
    // 上のブロック (値 < h) は位置 [m-h, 2m) に，下のブロックは [0, 2m-h) に作用する
    int *top = ar.alloc(2 * m), *bot = ar.alloc(2 * m), *used = ar.alloc(m);
    auto extend = [&](const int *kk, const int *cols, int c, int rows, int *e) {
        auto map_end = [&](int x) { return x < c ? cols[x] : m + (x - c); };
        for (int t = 0; t < rows; t++) e[t] = map_end(kk[t]);
        for (int j = 0; j < m; j++) used[j] = 0;
        for (int x = 0; x < c; x++) e[rows + cols[x]] = map_end(kk[rows + x]), used[cols[x]] = 1;
        for (int j = 0; j < m; j++) if (!used[j]) e[rows + j] = j;
    };
    for (int x = 0; x < m - h; x++) top[x] = x;
    extend(k_lo, cols_lo, h, h, top + (m - h));
    for (int y = m - h; y < 2 * m; y++) top[y] += m - h;
    extend(k_hi, cols_hi, m - h, m - h, bot);
    for (int x = 2 * m - h; x < 2 * m; x++) bot[x] = x;
    sticky_product_rec(top, bot, out, 2 * m, ar);
    ar.top = saved;
}

inline vector<int> seaweed(const vector<int> &q) {
    int m = q.size();
    vector<int> res(2 * m);
    if (m == 0) return res;
    Arena ar;
    ar.buf.resize(100 * (size_t)m + 256);  // seaweed の局所 約 24m + 最上段の積 約 68m
    seaweed_rec(q.data(), m, res.data(), ar);
    return res;
}

}  // namespace seaweed_internal

struct StaticRangeLIS {
    int n;
    vector<int> end_col;  // end_col[j]: 上辺の列 j から入ったひもの終点 (n 以上なら右辺)
    WaveletMatrix<int> wm;

    // a は任意の数列 (狭義増加で数える)
    template <class T>
    StaticRangeLIS(const vector<T> &a) : n(a.size()) {
        if (n == 0) return;
        // 値の昇順，同じ値は位置の降順に番号を振って順列にする
        vector<int> ord(n), q(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j] || (!(a[j] < a[i]) && i > j); });
        for (int k = 0; k < n; k++) q[ord[k]] = k;
        vector<int> k = seaweed_internal::seaweed(q);
        end_col.resize(n);
        for (int j = 0; j < n; j++) end_col[j] = k[n + j];
        wm = WaveletMatrix<int>(end_col);
    }

    // a[l..r) の LIS の長さ
    int query(int l, int r) const {
        if (l >= r) return 0;
        return (r - l) - wm.count_lt(l, r, r);
    }
};
