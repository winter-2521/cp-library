#pragma once
#include "../template.hpp"

// Sparse Table
// 冪等な演算 (min, max, gcd, and, or など) の区間クエリを，構築 O(n log n)・クエリ O(1) で処理する
// SparseTable st(a, [](int x, int y) { return min(x, y); });
template <class T, class Op>
struct SparseTable {
    int n, lg;
    Op op;
    // t[k * n + i] = op(a[i], ..., a[i + 2^k - 1])  (1 本の配列にまとめてキャッシュ効率を上げる)
    vector<T> t;

    SparseTable(const vector<T> &a, Op op) : n(a.size()), op(op) {
        lg = 1;
        while ((1 << lg) <= n) lg++;
        t.resize((size_t)lg * max(n, 1));
        copy(a.begin(), a.end(), t.begin());
        for (int k = 1; k < lg; k++) {
            const T *src = t.data() + (size_t)(k - 1) * n;
            T *dst = t.data() + (size_t)k * n;
            int half = 1 << (k - 1);
            for (int i = 0; i + (1 << k) <= n; i++) dst[i] = op(src[i], src[i + half]);
        }
    }

    // op(a[l], ..., a[r-1])．l < r であること
    T prod(int l, int r) const {
        int k = 31 - __builtin_clz(r - l);
        return op(t[(size_t)k * n + l], t[(size_t)k * n + r - (1 << k)]);
    }
};
