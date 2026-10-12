#pragma once
#include "../template.hpp"

// 64 分木による [0, n) の整数集合
// 挿入・削除・存在判定・次の要素・前の要素を O(log_64 n) で処理する
struct FastSet {
    int n, lg;
    // seg[0] が最下段．seg[h+1] の bit i は seg[h] の i 番目のワードが 0 でないかを表す
    vector<vector<uint64_t>> seg;

    FastSet(int n = 0) : n(n) {
        int m = n;
        do {
            seg.push_back(vector<uint64_t>(std::max(1, (m + 63) >> 6)));
            m = (m + 63) >> 6;
        } while (m > 1);
        lg = seg.size();
    }

    // f(i) が true の i を全て入れた状態で初期化する．O(n)
    template <class F>
    FastSet(int n, F f) : FastSet(n) {
        for (int i = 0; i < n; i++) if (f(i)) seg[0][i >> 6] |= 1ULL << (i & 63);
        build_upper();
    }

    // 最下段から上の段を作り直す
    void build_upper() {
        for (int h = 0; h + 1 < lg; h++) {
            fill(seg[h + 1].begin(), seg[h + 1].end(), 0);
            for (size_t i = 0; i < seg[h].size(); i++) if (seg[h][i]) seg[h + 1][i >> 6] |= 1ULL << (i & 63);
        }
    }

    int size() const { return n; }

    bool contains(int i) const { return seg[0][i >> 6] >> (i & 63) & 1; }
    bool operator[](int i) const { return contains(i); }

    void insert(int i) {
        for (int h = 0; h < lg; h++) {
            uint64_t &w = seg[h][i >> 6];
            bool was_empty = w == 0;
            w |= 1ULL << (i & 63);
            // すでに上の段にフラグが立っているので打ち切る
            if (!was_empty) break;
            i >>= 6;
        }
    }

    void erase(int i) {
        for (int h = 0; h < lg; h++) {
            uint64_t &w = seg[h][i >> 6];
            w &= ~(1ULL << (i & 63));
            // ワードがまだ空でなければ上の段は変わらない
            if (w) break;
            i >>= 6;
        }
    }

    // i 以上の最小の要素 (存在しなければ n)
    int next(int i) const {
        if (i < 0) i = 0;
        if (i >= n) return n;
        for (int h = 0; h < lg; h++) {
            if ((i >> 6) == (int)seg[h].size()) break;
            uint64_t d = seg[h][i >> 6] >> (i & 63);
            if (d == 0) {
                i = (i >> 6) + 1;
                continue;
            }
            i += __builtin_ctzll(d);
            for (int g = h - 1; g >= 0; g--) {
                i <<= 6;
                i += __builtin_ctzll(seg[g][i >> 6]);
            }
            return i;
        }
        return n;
    }

    // i 以下の最大の要素 (存在しなければ -1)
    int prev(int i) const {
        if (i >= n) i = n - 1;
        for (int h = 0; h < lg; h++) {
            if (i < 0) break;
            uint64_t d = seg[h][i >> 6] << (63 - (i & 63));
            if (d == 0) {
                i = (i >> 6) - 1;
                continue;
            }
            i -= __builtin_clzll(d);
            for (int g = h - 1; g >= 0; g--) {
                i <<= 6;
                i += 63 - __builtin_clzll(seg[g][i >> 6]);
            }
            return i;
        }
        return -1;
    }

    // 最小の要素 (空なら n)
    int min() const { return next(0); }
    // 最大の要素 (空なら -1)
    int max() const { return prev(n - 1); }
    bool empty() const { return seg[lg - 1][0] == 0; }

    // [l, r) に含まれる要素を昇順に f に渡す
    template <class F>
    void enumerate(int l, int r, F f) const {
        for (int x = next(l); x < r; x = next(x + 1)) f(x);
    }
};
