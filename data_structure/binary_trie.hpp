#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 2 分トライ (非負整数の多重集合)
// [0, 2^LOG) の整数を上位ビットから持つ．xor_min / xor_max / k 番目 / x 未満の個数を「全体に xor したもの」に対して求められる
// ノードは削除しても消さない (個数 0 のまま残す)
template <int LOG = 30, class T = unsigned int>
struct BinaryTrie {
    struct Node {
        int ch[2];
        int cnt;
    };
    vector<Node> d;
    static constexpr T MASK = LOG == (int)sizeof(T) * 8 ? ~T(0) : (T(1) << LOG) - 1;

    BinaryTrie() { d.push_back({{0, 0}, 0}); }  // 0 番が根

    void reserve(int n) { d.reserve(n); }
    int size() const { return d[0].cnt; }
    bool empty() const { return d[0].cnt == 0; }

    // x を k 個追加
    void insert(T x, int k = 1) {
        int v = 0;
        d[v].cnt += k;
        for (int b = LOG - 1; b >= 0; b--) {
            int c = (x >> b) & 1;
            if (!d[v].ch[c]) {
                d[v].ch[c] = d.size();
                d.push_back({{0, 0}, 0});
            }
            v = d[v].ch[c];
            d[v].cnt += k;
        }
    }

    // x を k 個削除 (k 個以上入っていること)
    void erase(T x, int k = 1) {
        int v = 0;
        d[v].cnt -= k;
        for (int b = LOG - 1; b >= 0; b--) {
            v = d[v].ch[(x >> b) & 1];
            d[v].cnt -= k;
        }
    }

    // x が入っていなければ追加して true
    bool insert_unique(T x) {
        if (count(x)) return false;
        insert(x);
        return true;
    }

    // x が入っていれば 1 個削除して true
    bool erase_one(T x) {
        if (!count(x)) return false;
        erase(x);
        return true;
    }

    // x の個数
    int count(T x) const {
        int v = 0;
        for (int b = LOG - 1; b >= 0; b--) {
            v = d[v].ch[(x >> b) & 1];
            if (!v || !d[v].cnt) return 0;
        }
        return d[v].cnt;
    }

    // min_{y ∈ S} (x xor y) (空でないこと)
    T xor_min(T x) const {
        int v = 0;
        T res = 0;
        for (int b = LOG - 1; b >= 0; b--) {
            int c = (x >> b) & 1;
            int to = d[v].ch[c];
            if (to && d[to].cnt) v = to;
            else v = d[v].ch[c ^ 1], res |= T(1) << b;
        }
        return res;
    }

    // max_{y ∈ S} (x xor y) (空でないこと)
    T xor_max(T x) const { return xor_min(x ^ MASK) ^ MASK; }

    // {y xor x : y ∈ S} の中で小さい方から k 番目 (0-indexed, k < size())
    T kth(int k, T x = 0) const {
        int v = 0;
        T res = 0;
        for (int b = LOG - 1; b >= 0; b--) {
            int c = (x >> b) & 1;
            int l = d[v].ch[c];
            int lc = l ? d[l].cnt : 0;
            if (k < lc) v = l;
            else k -= lc, v = d[v].ch[c ^ 1], res |= T(1) << b;
        }
        return res;
    }

    // {y xor x : y ∈ S} の最小値 / 最大値 (空でないこと)
    T min(T x = 0) const { return xor_min(x); }
    T max(T x = 0) const { return xor_max(x); }

    // #{y ∈ S : (y xor x) < a}
    int count_less(T a, T x = 0) const {
        if (a > MASK) return size();
        int v = 0, res = 0;
        for (int b = LOG - 1; b >= 0; b--) {
            int c = (x >> b) & 1, ab = (a >> b) & 1;
            if (ab) {
                int l = d[v].ch[c];
                if (l) res += d[l].cnt;
                v = d[v].ch[c ^ 1];
            } else {
                v = d[v].ch[c];
            }
            if (!v) return res;
        }
        return res;
    }
};
