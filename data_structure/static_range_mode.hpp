#pragma once
#include "../template.hpp"

// 静的な数列の区間最頻値 (Static Range Mode Query)．オンライン，平方分割
// ブロックの区間 [bi, bj] ごとに最頻値と個数を前計算しておき，端の要素は
// 「値ごとの出現位置の列」で個数を 1 ずつ伸ばせるか確かめる．構築 O(n √n)，クエリ O(√n)
template <class T>
struct StaticRangeMode {
    int n, B, nb;
    vector<T> vals;              // 座標圧縮後の値 → 元の値
    vector<int> c;               // 圧縮後の値
    vector<int> rank_in;         // i が pos[c[i]] の何番目か
    vector<vector<int>> pos;     // 値ごとの出現位置
    vector<int> mode_val, mode_cnt;  // ブロック区間 [bi, bj] の最頻値・個数 (bi * nb + bj)

    StaticRangeMode(const vector<T> &a) : n(a.size()) {
        vals = a;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = vals.size();
        c.resize(n), rank_in.resize(n), pos.assign(m, {});
        for (int i = 0; i < n; i++) {
            c[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
            rank_in[i] = pos[c[i]].size();
            pos[c[i]].push_back(i);
        }
        B = std::max(1, (int)sqrt(n));
        nb = (n + B - 1) / B;
        mode_val.assign(nb * nb, -1), mode_cnt.assign(nb * nb, 0);
        vector<int> cnt(m, 0);
        for (int bi = 0; bi < nb; bi++) {
            int best = -1, bc = 0;
            for (int bj = bi; bj < nb; bj++) {
                for (int i = bj * B; i < std::min(n, (bj + 1) * B); i++) {
                    if (++cnt[c[i]] > bc) bc = cnt[c[i]], best = c[i];
                }
                mode_val[bi * nb + bj] = best, mode_cnt[bi * nb + bj] = bc;
            }
            for (int i = bi * B; i < n; i++) cnt[c[i]]--;
        }
    }

    // a[l..r) の最頻値とその個数 (l < r)．最頻値が複数あればどれか 1 つ
    pair<T, int> query(int l, int r) const {
        int lb = l / B, rb = (r - 1) / B;
        int best = -1, bc = 0;
        auto extend_right = [&](int i) {  // i から右に数えて bc + 1 個目が r 未満にあるか
            int v = c[i], k = rank_in[i];
            const auto &p = pos[v];
            while (k + bc < (int)p.size() && p[k + bc] < r) bc++, best = v;
        };
        if (rb - lb <= 1) {
            for (int i = l; i < r; i++) extend_right(i);
            return {vals[best], bc};
        }
        best = mode_val[(lb + 1) * nb + rb - 1], bc = mode_cnt[(lb + 1) * nb + rb - 1];
        for (int i = l; i < (lb + 1) * B; i++) extend_right(i);
        for (int i = rb * B; i < r; i++) {  // 左に数えて bc + 1 個目が l 以上にあるか
            int v = c[i], k = rank_in[i];
            const auto &p = pos[v];
            while (k - bc >= 0 && p[k - bc] >= l) bc++, best = v;
        }
        return {vals[best], bc};
    }
};
