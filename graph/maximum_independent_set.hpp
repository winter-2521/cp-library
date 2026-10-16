#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 最大独立集合 (n <= 64)．頂点集合を 64 bit で持ち，分枝限定法で探す
// - 残りの次数が 0 か 1 の頂点 v は必ず取ってよい (v の代わりに隣を取っても得にならない)
// - そうでなければ次数最大の頂点 v について「v を取る (隣を全部消す)」「v を取らない」の 2 通りに分ける
// 次数 3 以上で分けるので T(n) = T(n-1) + T(n-4) より O(1.381^n) 程度．現在の最良より大きくなれない枝は打ち切る
// 返り値: 最大独立集合の頂点の列 (昇順)
inline vector<int> maximum_independent_set(int n, const vector<pair<int, int>> &edges) {
    assert(n <= 64);
    using u64 = unsigned long long;
    vector<u64> nb(n, 0);
    for (auto [a, b] : edges)
        if (a != b) nb[a] |= 1ULL << b, nb[b] |= 1ULL << a;
    u64 best = 0;
    int best_cnt = 0;
    auto rec = [&](auto self, u64 rem, u64 cur, int cnt) -> void {
        // 次数 0, 1 の頂点を取れるだけ取る
        while (true) {
            bool changed = false;
            for (u64 r = rem; r;) {
                int v = __builtin_ctzll(r);
                r &= r - 1;
                if (!(rem >> v & 1)) continue;
                if (__builtin_popcountll(nb[v] & rem) <= 1) {
                    cur |= 1ULL << v, cnt++;
                    rem &= ~(nb[v] | 1ULL << v);
                    changed = true;
                }
            }
            if (!changed) break;
        }
        if (cnt + __builtin_popcountll(rem) <= best_cnt) return;
        if (!rem) {
            best = cur, best_cnt = cnt;
            return;
        }
        int v = -1, dmax = -1;
        for (u64 r = rem; r; r &= r - 1) {
            int x = __builtin_ctzll(r), dg = __builtin_popcountll(nb[x] & rem);
            if (dg > dmax) dmax = dg, v = x;
        }
        // v を取る / 取らない
        self(self, rem & ~(nb[v] | 1ULL << v), cur | 1ULL << v, cnt + 1);
        self(self, rem & ~(1ULL << v), cur, cnt);
    };
    rec(rec, n == 64 ? ~0ULL : (1ULL << n) - 1, 0, 0);
    vector<int> res;
    for (int v = 0; v < n; v++)
        if (best >> v & 1) res.push_back(v);
    return res;
}
