#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// Fenwick Tree (Binary Indexed Tree)
// 一点加算・区間和を O(log n) で処理する．外部からは 0-indexed で扱う
template <class T>
struct FenwickTree {
    int n;
    // d[i] (1-indexed) は区間 (i - lowbit(i), i] の和
    vector<T> d;

    FenwickTree(int n = 0) : n(n), d(n + 1, T(0)) {}

    // 配列 a で O(n) 初期化
    FenwickTree(const vector<T> &a) : n(a.size()), d(a.size() + 1, T(0)) {
        for (int i = 0; i < n; i++) d[i + 1] = a[i];
        for (int i = 1; i <= n; i++) {
            int j = i + (i & -i);
            if (j <= n) d[j] += d[i];
        }
    }

    int size() const { return n; }

    // a[i] += x
    void add(int i, T x) {
        for (i++; i <= n; i += i & -i) d[i] += x;
    }

    // a[0] + ... + a[r-1]
    T sum(int r) const {
        T s = T(0);
        for (; r > 0; r &= r - 1) s += d[r];
        return s;
    }

    // a[l] + ... + a[r-1]
    // sum(r) - sum(l) を，l と r の共通の祖先まで降りたところで打ち切って計算する
    T sum(int l, int r) const {
        T s = T(0);
        while (l < r) s += d[r], r &= r - 1;
        while (r < l) s -= d[l], l &= l - 1;
        return s;
    }

    // a[i]
    T get(int i) const { return sum(i, i + 1); }

    // a[i] = x
    void set(int i, T x) { add(i, x - get(i)); }

    // a[0] + ... + a[i] >= w となる最小の i を返す (存在しなければ n)
    // 全要素が非負であること
    int lower_bound(T w) const {
        if (w <= T(0)) return 0;
        int x = 0;
        int k = 1;
        while (k * 2 <= n) k *= 2;
        for (; k > 0; k >>= 1) {
            if (x + k <= n && d[x + k] < w) {
                x += k;
                w -= d[x];
            }
        }
        return x;
    }

    // a[0] + ... + a[i] > w となる最小の i を返す (存在しなければ n)
    // 全要素が非負であること
    int upper_bound(T w) const {
        int x = 0;
        int k = 1;
        while (k * 2 <= n) k *= 2;
        for (; k > 0; k >>= 1) {
            if (x + k <= n && !(w < d[x + k])) {
                x += k;
                w -= d[x];
            }
        }
        return x;
    }
};
