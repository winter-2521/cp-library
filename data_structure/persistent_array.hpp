#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 永続配列 (Persistent Array)．どの版からでも一点更新でき，新しい版の番号を返す
// 2^LOG 分木で持ち，更新は根から葉までの道のノードだけを複製する (path copying)
// 取得・更新 O(log_{2^LOG} n)．更新ごとに O(2^LOG log_{2^LOG} n) のメモリ
template <class T, int LOG = 3>
struct PersistentArray {
    static constexpr int K = 1 << LOG;
    int n, height;
    vector<array<int, K>> ch;   // 内部ノードの子 (ch のノード番号，葉の段では vals の番号)
    vector<T> vals;              // 葉の値
    vector<int> roots;           // 版ごとの根

    PersistentArray(const vector<T> &a = {}) : n(a.size()) {
        height = 0;
        while ((1LL << (LOG * height)) < std::max(n, 1)) height++;
        vals = a;
        if (vals.empty()) vals.push_back(T());
        roots.push_back(build(0, height));
    }

    PersistentArray(int n, const T &x) : PersistentArray(vector<T>(n, x)) {}

    void reserve(int updates) {
        ch.reserve(ch.size() + (size_t)updates * height);
        vals.reserve(vals.size() + updates);
        roots.reserve(roots.size() + updates);
    }

    int size() const { return n; }
    int versions() const { return roots.size(); }

    // 版 v の a[i]
    T get(int v, int i) const {
        int t = roots[v];
        for (int h = height - 1; h >= 0; h--) t = ch[t][(i >> (LOG * h)) & (K - 1)];
        return vals[t];
    }

    // 版 v の a[i] を x にした版を作り，その番号を返す
    int set(int v, int i, const T &x) {
        vals.push_back(x);
        int leaf = vals.size() - 1;
        if (height == 0) {
            roots.push_back(leaf);
            return roots.size() - 1;
        }
        roots.push_back(set_rec(roots[v], height - 1, i, leaf));
        return roots.size() - 1;
    }

  private:
    // 段 h (h = height なら根) から下の，先頭 lo の部分を作る．葉の段なら vals の番号を返す
    int build(int lo, int h) {
        if (h == 0) return std::min(lo, (int)vals.size() - 1);
        array<int, K> c;
        long long w = 1LL << (LOG * (h - 1));
        for (int k = 0; k < K; k++) c[k] = build(std::min<long long>(lo + w * k, std::max(n - 1, 0)), h - 1);
        ch.push_back(c);
        return ch.size() - 1;
    }

    int set_rec(int t, int h, int i, int leaf) {
        array<int, K> c = ch[t];
        int k = (i >> (LOG * h)) & (K - 1);
        c[k] = h == 0 ? leaf : set_rec(c[k], h - 1, i, leaf);
        ch.push_back(c);
        return ch.size() - 1;
    }
};
