#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 静的な区間最小値 (Range Minimum Query)
// 構築 O(n)，クエリ O(1)．区間の最小値とその位置 (最小値が複数あれば一番左) を返す
//
// 64 要素ずつのブロックに分け，
// - ブロック内: 各 i について「ブロックの先頭から i までの単調スタック」をビットマスクで持つ
// - ブロック間: ブロックごとの最小値に対する Sparse Table
// を使う．Sparse Table を直接作るより使うメモリが少なく，キャッシュに乗りやすい
template <class T, class Compare = less<T>>
struct StaticRMQ {
    static constexpr int B = 64;
    int n, nb;
    vector<T> a;
    Compare comp;
    // mask[i] の bit j: ブロック先頭 + j が a[ブロック先頭 + j .. i] の最小値の位置 (単調スタックに残っている)
    vector<uint64_t> mask;
    // ブロック間 Sparse Table (値ではなく位置を持つ)
    vector<int> table;
    int lg;

    StaticRMQ(const vector<T> &v, Compare comp = Compare()) : n(v.size()), a(v), comp(comp), mask(v.size()) {
        nb = (n + B - 1) / B;
        // ブロック内の単調スタック
        for (int s = 0; s < n; s += B) {
            int e = std::min(n, s + B);
            uint64_t st = 0;
            for (int i = s; i < e; i++) {
                // a[i] より真に大きい要素をスタックから取り除く (等しい要素は左を残す)
                while (st) {
                    int top = s + 63 - __builtin_clzll(st);
                    if (comp(a[i], a[top])) st ^= 1ULL << (top - s);
                    else break;
                }
                st |= 1ULL << (i - s);
                mask[i] = st;
            }
        }
        // ブロック間 Sparse Table
        lg = 1;
        while ((1 << lg) <= nb) lg++;
        table.resize((size_t)lg * std::max(nb, 1));
        for (int b = 0; b < nb; b++) table[b] = b * B + __builtin_ctzll(mask[std::min(n, (b + 1) * B) - 1]);
        for (int k = 1; k < lg; k++) {
            const int *src = table.data() + (size_t)(k - 1) * nb;
            int *dst = table.data() + (size_t)k * nb;
            int half = 1 << (k - 1);
            for (int i = 0; i + (1 << k) <= nb; i++) dst[i] = better(src[i], src[i + half]);
        }
    }

    // 位置 i, j のうち値が小さい方 (同じなら左)
    int better(int i, int j) const { return comp(a[j], a[i]) ? j : i; }

    // 同じブロック内の [l, r] (閉区間) の最小値の位置
    int in_block(int l, int r) const {
        return l + __builtin_ctzll(mask[r] >> (l & (B - 1)));
    }

    // [l, r) の最小値の位置 (最小値が複数あれば一番左)．l < r であること
    int argmin(int l, int r) const {
        r--;
        int bl = l / B, br = r / B;
        if (bl == br) return in_block(l, r);
        int res = in_block(l, bl * B + B - 1);
        if (bl + 1 < br) {
            int k = 31 - __builtin_clz(br - bl - 1);
            int x = better(table[(size_t)k * nb + bl + 1], table[(size_t)k * nb + br - (1 << k)]);
            res = better(res, x);
        }
        return better(res, in_block(br * B, r));
    }

    // [l, r) の最小値．l < r であること
    T prod(int l, int r) const { return a[argmin(l, r)]; }
};
