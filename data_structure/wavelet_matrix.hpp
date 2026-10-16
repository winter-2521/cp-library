#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// ウェーブレット行列 (静的な数列に対する区間 k 番目・区間の値の個数など)
// 値は内部で座標圧縮する．構築 O(n log n)，各クエリ O(log σ) (σ は値の種類数)
template <class T>
struct WaveletMatrix {
    // 64 bit ごとに，ビット列とそれより前の 1 の個数をまとめて持つ
    struct BitVector {
        struct Block {
            uint64_t bits;
            int cnt;
        };
        vector<Block> b;
        void init(int n) { b.assign((n >> 6) + 1, {0, 0}); }
        void set(int i) { b[i >> 6].bits |= 1ULL << (i & 63); }
        void build() {
            for (size_t i = 1; i < b.size(); i++) b[i].cnt = b[i - 1].cnt + __builtin_popcountll(b[i - 1].bits);
        }
        // [0, i) の 1 の個数
        int rank1(int i) const {
            const Block &x = b[i >> 6];
            return x.cnt + __builtin_popcountll(x.bits & ((1ULL << (i & 63)) - 1));
        }
        bool get(int i) const { return b[i >> 6].bits >> (i & 63) & 1; }
    };

    int n, lg;
    vector<T> vals;  // 座標圧縮後の値 (昇順)
    vector<BitVector> bv;
    vector<int> zeros;

    WaveletMatrix(const vector<T> &a = {}) : n(a.size()) {
        vals = a;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        vector<int> cur(n);
        for (int i = 0; i < n; i++) cur[i] = int(lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin());
        lg = 1;
        while ((1 << lg) < (int)vals.size()) lg++;
        bv.resize(lg);
        zeros.resize(lg);
        vector<int> nxt(n);
        for (int h = lg - 1; h >= 0; h--) {
            bv[h].init(n);
            int z = 0;
            for (int i = 0; i < n; i++) {
                if (cur[i] >> h & 1) bv[h].set(i);
                else z++;
            }
            bv[h].build();
            zeros[h] = z;
            // 0 のものを前に，1 のものを後ろに (安定)
            int p0 = 0, p1 = z;
            for (int i = 0; i < n; i++) nxt[(cur[i] >> h & 1) ? p1++ : p0++] = cur[i];
            swap(cur, nxt);
        }
    }

    int size() const { return n; }

    // a[i]
    T access(int i) const {
        int res = 0;
        for (int h = lg - 1; h >= 0; h--) {
            int r1 = bv[h].rank1(i);
            if (bv[h].get(i)) res |= 1 << h, i = zeros[h] + r1;
            else i -= r1;
        }
        return vals[res];
    }
    T operator[](int i) const { return access(i); }

    // a[l..r) の中で小さい方から k 番目 (0-indexed) の値．0 <= k < r - l であること
    T kth_smallest(int l, int r, int k) const {
        int res = 0;
        for (int h = lg - 1; h >= 0; h--) {
            int l1 = bv[h].rank1(l), r1 = bv[h].rank1(r);
            int z = (r - r1) - (l - l1);
            if (k < z) {
                l -= l1, r -= r1;
            } else {
                k -= z;
                res |= 1 << h;
                l = zeros[h] + l1, r = zeros[h] + r1;
            }
        }
        return vals[res];
    }
    // a[l..r) の中で大きい方から k 番目 (0-indexed) の値
    T kth_largest(int l, int r, int k) const { return kth_smallest(l, r, r - l - 1 - k); }

    // a[l..r) の中の x 未満の値の個数
    int count_lt(int l, int r, const T &x) const { return count_lt_id(l, r, id_lower(x)); }
    // a[l..r) の中の x 以下の値の個数
    int count_le(int l, int r, const T &x) const { return count_lt_id(l, r, id_upper(x)); }
    // a[l..r) の中の lo 以上 hi 未満の値の個数
    int count_range(int l, int r, const T &lo, const T &hi) const {
        if (!(lo < hi)) return 0;
        return count_lt(l, r, hi) - count_lt(l, r, lo);
    }
    // a[l..r) の中の x の個数
    int count(int l, int r, const T &x) const { return count_le(l, r, x) - count_lt(l, r, x); }

    // a[l..r) の中の x 未満の最大の値 (なければ def)
    T max_lt(int l, int r, const T &x, T def = T(-1)) const {
        int c = count_lt(l, r, x);
        return c == 0 ? def : kth_smallest(l, r, c - 1);
    }
    // a[l..r) の中の x 以下の最大の値 (なければ def)
    T max_le(int l, int r, const T &x, T def = T(-1)) const {
        int c = count_le(l, r, x);
        return c == 0 ? def : kth_smallest(l, r, c - 1);
    }
    // a[l..r) の中の x 以上の最小の値 (なければ def)
    T min_ge(int l, int r, const T &x, T def = T(-1)) const {
        int c = count_lt(l, r, x);
        return c == r - l ? def : kth_smallest(l, r, c);
    }
    // a[l..r) の中の x より大きい最小の値 (なければ def)
    T min_gt(int l, int r, const T &x, T def = T(-1)) const {
        int c = count_le(l, r, x);
        return c == r - l ? def : kth_smallest(l, r, c);
    }

  private:
    int id_lower(const T &x) const { return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()); }
    int id_upper(const T &x) const { return int(upper_bound(vals.begin(), vals.end(), x) - vals.begin()); }
    // a[l..r) の中で圧縮後の値が v 未満のものの個数
    int count_lt_id(int l, int r, int v) const {
        if (l >= r) return 0;
        if (v >= (1 << lg)) return r - l;
        int res = 0;
        for (int h = lg - 1; h >= 0; h--) {
            int l1 = bv[h].rank1(l), r1 = bv[h].rank1(r);
            if (v >> h & 1) {
                res += (r - r1) - (l - l1);
                l = zeros[h] + l1, r = zeros[h] + r1;
            } else {
                l -= l1, r -= r1;
            }
        }
        return res;
    }
};
