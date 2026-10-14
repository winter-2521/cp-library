#pragma once
#include "../template.hpp"

// 静的な数列の区間に x が何個あるか (Static Range Frequency)
// 値ごとに出現位置を昇順に並べておき，x の位置の列で [l, r) に入るものを二分探索で数える．構築 O(n log n)，クエリ O(log n)
template <class T>
struct StaticRangeFrequency {
    int n;
    vector<T> vals;     // 値の種類 (昇順)
    vector<int> start;  // 値 vals[k] の出現位置は pos[start[k] .. start[k+1])
    vector<int> pos;

    StaticRangeFrequency(const vector<T> &a) : n(a.size()) {
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        stable_sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });
        pos = ord;
        for (int k = 0; k < n; k++) {
            if (k == 0 || vals.back() < a[ord[k]]) vals.push_back(a[ord[k]]), start.push_back(k);
        }
        start.push_back(n);
    }

    // a[l..r) の中の x の個数
    int count(int l, int r, const T &x) const {
        int k = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
        if (k == (int)vals.size() || x < vals[k]) return 0;
        auto b = pos.begin() + start[k], e = pos.begin() + start[k + 1];
        return lower_bound(b, e, r) - lower_bound(b, e, l);
    }
};
