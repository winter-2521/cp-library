#pragma once
#include "../template.hpp"
#include "wavelet_matrix.hpp"

// 静的な数列の区間に含まれる値の種類数 (Static Range Count Distinct)．オンライン
// prev[i] = i より前で a[i] と同じ値が最後に出てくる位置 (なければ -1) とすると，
// [l, r) の種類数 = #{i ∈ [l, r) : prev[i] < l}．これをウェーブレット行列で数える
// 構築 O(n log n)，クエリ O(log n)
template <class T>
struct StaticRangeCountDistinct {
    int n;
    WaveletMatrix<int> wm;

    StaticRangeCountDistinct(const vector<T> &a) : n(a.size()) {
        vector<int> ord(n), prev(n, -1);
        iota(ord.begin(), ord.end(), 0);
        stable_sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });
        for (int k = 1; k < n; k++)
            if (!(a[ord[k - 1]] < a[ord[k]])) prev[ord[k]] = ord[k - 1];
        wm = WaveletMatrix<int>(prev);
    }

    // a[l..r) の値の種類数
    int count(int l, int r) const { return l < r ? wm.count_lt(l, r, l) : 0; }
};
