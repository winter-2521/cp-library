#pragma once
#include "../template.hpp"
#include "ordered_set.hpp"

// 一点更新ができる区間の値の個数 (Point Set Range Frequency)．オンライン
// (値, 位置) の組を順序付き集合に入れておき，(x, l) 以上 (x, r) 未満の個数を数える
// 更新・クエリ O(log n)
template <class T>
struct DynamicRangeFrequency {
    int n;
    vector<T> a;
    OrderedSet<pair<T, int>> st;

    DynamicRangeFrequency(const vector<T> &a_) : n(a_.size()), a(a_) {
        vector<pair<T, int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {a[i], i};
        sort(v.begin(), v.end());
        st = OrderedSet<pair<T, int>>(v);
    }

    T get(int i) const { return a[i]; }

    // a[i] = x
    void set(int i, const T &x) {
        st.erase({a[i], i});
        a[i] = x;
        st.insert({a[i], i});
    }

    // a[l..r) の中の x の個数
    int count(int l, int r, const T &x) const { return l < r ? st.count_range({x, l}, {x, r}) : 0; }
};
