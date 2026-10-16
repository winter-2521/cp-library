#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// Segment Tree Beats
// 区間 chmin・区間 chmax・区間加算・区間代入と，区間和・区間最小値・区間最大値を処理する
// 計算量はならし O((n + q) log^2 n) (加算がなければ O((n + q) log n))
template <class T = long long>
struct SegmentTreeBeats {
    static constexpr T INF = numeric_limits<T>::max();
    static constexpr T NINF = numeric_limits<T>::lowest();
    int n, sz;
    // mx1 / mx2: 最大値と 2 番目の最大値 (なければ NINF)，mxc: 最大値の個数．min も同様
    vector<T> mx1, mx2, mn1, mn2, sm, lz;
    vector<int> mxc, mnc, len;

    SegmentTreeBeats(int n = 0) : SegmentTreeBeats(vector<T>(n, T(0))) {}

    SegmentTreeBeats(const vector<T> &a) : n(a.size()) {
        sz = 1;
        while (sz < n) sz <<= 1;
        mx1.assign(2 * sz, NINF), mx2.assign(2 * sz, NINF), mn1.assign(2 * sz, INF), mn2.assign(2 * sz, INF);
        sm.assign(2 * sz, T(0)), lz.assign(2 * sz, T(0));
        mxc.assign(2 * sz, 0), mnc.assign(2 * sz, 0), len.assign(2 * sz, 0);
        for (int i = 0; i < n; i++) {
            int k = sz + i;
            mx1[k] = mn1[k] = sm[k] = a[i];
            mxc[k] = mnc[k] = len[k] = 1;
        }
        for (int k = sz - 1; k >= 1; k--) {
            len[k] = len[2 * k] + len[2 * k + 1];
            update(k);
        }
    }

    int size() const { return n; }

    // i in [l, r) について a[i] = min(a[i], x)
    void chmin(int l, int r, T x) { chmin(l, r, x, 1, 0, sz); }
    // i in [l, r) について a[i] = max(a[i], x)
    void chmax(int l, int r, T x) { chmax(l, r, x, 1, 0, sz); }
    // i in [l, r) について a[i] += x
    void add(int l, int r, T x) { add(l, r, x, 1, 0, sz); }
    // i in [l, r) について a[i] = x
    void assign(int l, int r, T x) {
        chmin(l, r, x);
        chmax(l, r, x);
    }

    // a[l] + ... + a[r-1]
    T sum(int l, int r) { return sum(l, r, 1, 0, sz); }
    // min(a[l], ..., a[r-1])．l == r なら INF
    T min(int l, int r) { return get_min(l, r, 1, 0, sz); }
    // max(a[l], ..., a[r-1])．l == r なら NINF
    T max(int l, int r) { return get_max(l, r, 1, 0, sz); }
    T get(int i) { return sum(i, i + 1); }

  private:
    void update(int k) {
        int a = 2 * k, b = 2 * k + 1;
        sm[k] = sm[a] + sm[b];
        if (mx1[a] > mx1[b]) mx1[k] = mx1[a], mxc[k] = mxc[a], mx2[k] = std::max(mx2[a], mx1[b]);
        else if (mx1[a] < mx1[b]) mx1[k] = mx1[b], mxc[k] = mxc[b], mx2[k] = std::max(mx1[a], mx2[b]);
        else mx1[k] = mx1[a], mxc[k] = mxc[a] + mxc[b], mx2[k] = std::max(mx2[a], mx2[b]);
        if (mn1[a] < mn1[b]) mn1[k] = mn1[a], mnc[k] = mnc[a], mn2[k] = std::min(mn2[a], mn1[b]);
        else if (mn1[a] > mn1[b]) mn1[k] = mn1[b], mnc[k] = mnc[b], mn2[k] = std::min(mn1[a], mn2[b]);
        else mn1[k] = mn1[a], mnc[k] = mnc[a] + mnc[b], mn2[k] = std::min(mn2[a], mn2[b]);
    }
    // 最大値を x にする (mx2 < x < mx1)
    void node_chmin(int k, T x) {
        sm[k] += (x - mx1[k]) * mxc[k];
        if (mx1[k] == mn1[k]) mx1[k] = mn1[k] = x;
        else if (mx1[k] == mn2[k]) mx1[k] = mn2[k] = x;
        else mx1[k] = x;
    }
    // 最小値を x にする (mn1 < x < mn2)
    void node_chmax(int k, T x) {
        sm[k] += (x - mn1[k]) * mnc[k];
        if (mx1[k] == mn1[k]) mx1[k] = mn1[k] = x;
        else if (mx2[k] == mn1[k]) mn1[k] = mx2[k] = x;
        else mn1[k] = x;
    }
    void node_add(int k, T x) {
        if (len[k] == 0) return;
        mx1[k] += x, mn1[k] += x;
        if (mx2[k] != NINF) mx2[k] += x;
        if (mn2[k] != INF) mn2[k] += x;
        sm[k] += x * len[k];
        lz[k] += x;
    }
    void push(int k) {
        int a = 2 * k, b = 2 * k + 1;
        if (lz[k] != 0) {
            node_add(a, lz[k]), node_add(b, lz[k]);
            lz[k] = 0;
        }
        if (mx1[a] > mx1[k]) node_chmin(a, mx1[k]);
        if (mx1[b] > mx1[k]) node_chmin(b, mx1[k]);
        if (mn1[a] < mn1[k]) node_chmax(a, mn1[k]);
        if (mn1[b] < mn1[k]) node_chmax(b, mn1[k]);
    }

    void chmin(int l, int r, T x, int k, int lo, int hi) {
        if (r <= lo || hi <= l || mx1[k] <= x) return;
        if (l <= lo && hi <= r && mx2[k] < x) {
            node_chmin(k, x);
            return;
        }
        push(k);
        int mid = (lo + hi) >> 1;
        chmin(l, r, x, 2 * k, lo, mid);
        chmin(l, r, x, 2 * k + 1, mid, hi);
        update(k);
    }
    void chmax(int l, int r, T x, int k, int lo, int hi) {
        if (r <= lo || hi <= l || mn1[k] >= x) return;
        if (l <= lo && hi <= r && mn2[k] > x) {
            node_chmax(k, x);
            return;
        }
        push(k);
        int mid = (lo + hi) >> 1;
        chmax(l, r, x, 2 * k, lo, mid);
        chmax(l, r, x, 2 * k + 1, mid, hi);
        update(k);
    }
    void add(int l, int r, T x, int k, int lo, int hi) {
        if (r <= lo || hi <= l) return;
        if (l <= lo && hi <= r) {
            node_add(k, x);
            return;
        }
        push(k);
        int mid = (lo + hi) >> 1;
        add(l, r, x, 2 * k, lo, mid);
        add(l, r, x, 2 * k + 1, mid, hi);
        update(k);
    }
    T sum(int l, int r, int k, int lo, int hi) {
        if (r <= lo || hi <= l) return T(0);
        if (l <= lo && hi <= r) return sm[k];
        push(k);
        int mid = (lo + hi) >> 1;
        return sum(l, r, 2 * k, lo, mid) + sum(l, r, 2 * k + 1, mid, hi);
    }
    T get_min(int l, int r, int k, int lo, int hi) {
        if (r <= lo || hi <= l) return INF;
        if (l <= lo && hi <= r) return mn1[k];
        push(k);
        int mid = (lo + hi) >> 1;
        return std::min(get_min(l, r, 2 * k, lo, mid), get_min(l, r, 2 * k + 1, mid, hi));
    }
    T get_max(int l, int r, int k, int lo, int hi) {
        if (r <= lo || hi <= l) return NINF;
        if (l <= lo && hi <= r) return mx1[k];
        push(k);
        int mid = (lo + hi) >> 1;
        return std::max(get_max(l, r, 2 * k, lo, mid), get_max(l, r, 2 * k + 1, mid, hi));
    }
};
