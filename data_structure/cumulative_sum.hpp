#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 1 次元累積和．区間和を O(1) で求める
template <class T>
struct CumulativeSum {
    // s[i] = a[0] + ... + a[i-1]
    vector<T> s;

    CumulativeSum() : s(1, T(0)) {}

    template <class U>
    CumulativeSum(const vector<U> &a) : s(a.size() + 1) {
        s[0] = T(0);
        for (size_t i = 0; i < a.size(); i++) s[i + 1] = s[i] + T(a[i]);
    }

    int size() const { return int(s.size()) - 1; }

    // 末尾に x を追加
    void push_back(const T &x) { s.push_back(s.back() + x); }

    // a[0] + ... + a[r-1]
    T prefix(int r) const { return s[r]; }

    // a[l] + ... + a[r-1]
    T sum(int l, int r) const { return s[r] - s[l]; }
};

// 2 次元累積和．長方形領域の和を O(1) で求める
template <class T>
struct CumulativeSum2D {
    int h, w;
    // s[(i * (w + 1)) + j] = 左上 [0, i) x [0, j) の和
    vector<T> s;

    template <class U>
    CumulativeSum2D(const vector<vector<U>> &a) : h(a.size()), w(a.empty() ? 0 : a[0].size()), s((h + 1) * (w + 1), T(0)) {
        for (int i = 0; i < h; i++) {
            T row = T(0);
            for (int j = 0; j < w; j++) {
                row += T(a[i][j]);
                s[(i + 1) * (w + 1) + j + 1] = s[i * (w + 1) + j + 1] + row;
            }
        }
    }

    // 行 [x1, x2) x 列 [y1, y2) の和
    T sum(int x1, int y1, int x2, int y2) const {
        return s[x2 * (w + 1) + y2] - s[x1 * (w + 1) + y2] - s[x2 * (w + 1) + y1] + s[x1 * (w + 1) + y1];
    }
};
