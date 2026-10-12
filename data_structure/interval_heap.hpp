#pragma once
#include "../template.hpp"

// Interval Heap (両端優先度付きキュー)
// 最小値・最大値の取得を O(1)，挿入・最小値の削除・最大値の削除を O(log n) で処理する
// 節点 k が d[2k] (区間の左端) と d[2k+1] (区間の右端) を持ち，
// 左端だけを見ると min-heap，右端だけを見ると max-heap になっている
template <class T, class Compare = less<T>>
struct IntervalHeap {
    vector<T> d;
    Compare comp;

    IntervalHeap(Compare comp = Compare()) : comp(comp) {}

    IntervalHeap(const vector<T> &a, Compare comp = Compare()) : comp(comp) {
        d.reserve(a.size());
        for (const T &x : a) push(x);
    }

    int size() const { return d.size(); }
    bool empty() const { return d.empty(); }
    void reserve(int n) { d.reserve(n); }
    void clear() { d.clear(); }

    const T &min() const { return d[0]; }
    const T &max() const { return d.size() == 1 ? d[0] : d[1]; }

    void push(const T &x) {
        int i = d.size();
        d.push_back(x);
        if (i & 1) {
            // 節点 i/2 の右端に入った
            if (comp(d[i], d[i - 1])) {
                swap(d[i], d[i - 1]);
                up_min(i - 1);
            } else {
                up_max(i);
            }
        } else {
            // 新しい節点ができた (要素 1 個なので左端かつ右端)
            if (i == 0) return;
            int p = (((i >> 1) - 1) >> 1) << 1;
            if (comp(d[i], d[p])) up_min(i);
            else if (comp(d[p + 1], d[i])) up_max(i);
        }
    }

    T pop_min() {
        T res = move(d[0]);
        T last = move(d.back());
        d.pop_back();
        if (!d.empty()) {
            d[0] = move(last);
            down_min();
        }
        return res;
    }

    T pop_max() {
        if (d.size() <= 2) {
            T res = move(d.back());
            d.pop_back();
            return res;
        }
        T res = move(d[1]);
        T last = move(d.back());
        d.pop_back();
        d[1] = move(last);
        down_max();
        return res;
    }

  private:
    // 位置 i (左端) の要素を min-heap として上げる
    void up_min(int i) {
        T x = move(d[i]);
        int k = i >> 1;
        while (k > 0) {
            int p = (k - 1) >> 1;
            if (!comp(x, d[p << 1])) break;
            d[k << 1] = move(d[p << 1]);
            k = p;
        }
        d[k << 1] = move(x);
    }

    // 位置 i (右端．要素 1 個の節点なら左端) の要素を max-heap として上げる
    void up_max(int i) {
        T x = move(d[i]);
        int k = i >> 1;
        int pos = i;
        while (k > 0) {
            int p = (k - 1) >> 1;
            if (!comp(d[p << 1 | 1], x)) break;
            d[pos] = move(d[p << 1 | 1]);
            pos = p << 1 | 1;
            k = p;
        }
        d[pos] = move(x);
    }

    void down_min() {
        int n = d.size();
        int k = 0;
        while (true) {
            int lo = k << 1;
            if (lo + 1 < n && comp(d[lo + 1], d[lo])) swap(d[lo], d[lo + 1]);
            int c = (k << 1) + 1;
            if ((c << 1) >= n) break;
            if (((c + 1) << 1) < n && comp(d[(c + 1) << 1], d[c << 1])) c++;
            if (!comp(d[c << 1], d[lo])) break;
            swap(d[c << 1], d[lo]);
            k = c;
        }
        // 最後に移った節点の区間の向きを直す
        int lo = k << 1;
        if (lo + 1 < n && comp(d[lo + 1], d[lo])) swap(d[lo], d[lo + 1]);
    }

    void down_max() {
        int n = d.size();
        int k = 0;
        while (true) {
            int hi = k << 1 | 1;
            if (hi < n && comp(d[hi], d[hi - 1])) swap(d[hi], d[hi - 1]);
            int c = (k << 1) + 1;
            if ((c << 1) >= n) break;
            // 子の右端 (要素 1 個の節点なら左端)
            int hc = std::min((c << 1) | 1, n - 1);
            if (((c + 1) << 1) < n) {
                int hc2 = std::min(((c + 1) << 1) | 1, n - 1);
                if (comp(d[hc], d[hc2])) hc = hc2, c++;
            }
            if (!comp(d[hi], d[hc])) break;
            swap(d[hc], d[hi]);
            k = c;
        }
        int hi = k << 1 | 1;
        if (hi < n && comp(d[hi], d[hi - 1])) swap(d[hi], d[hi - 1]);
    }
};
