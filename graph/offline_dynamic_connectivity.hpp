#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// オフライン動的連結性 (辺の追加・削除，頂点の値の加算，連結成分の値の和)．クエリを全部先読みできるときのみ使える
// 各辺が存在する時刻の区間 [l, r) を，時刻のセグメント木の O(log Q) 個のノードに載せる．
// セグメント木を DFS し，ノードに入るときにその辺を Union-Find で併合し，出るときに戻す (経路圧縮なし・大きさで併合)．
// 葉 (時刻 t) でその時刻の操作を行う．頂点 v への加算は「v から根までの各頂点の部分木の和」に足すので，
// 併合を戻しても正しく残る．O(Q log Q log n)
// 使い方: 操作を順に登録してから solve() を呼ぶと，query() の答えが登録順に返る
struct OfflineDynamicConnectivity {
    using ll = long long;
    int n;
    vector<ll> init;
    // 操作: type 0 = 辺の追加，1 = 辺の削除，2 = 加算，3 = 質問
    struct Op {
        int type, u, v;
        ll x;
    };
    vector<Op> ops;

    explicit OfflineDynamicConnectivity(int n, vector<ll> a = {}) : n(n), init(a.empty() ? vector<ll>(n, 0) : a) {}
    void link(int u, int v) { ops.push_back({0, u, v, 0}); }
    void cut(int u, int v) { ops.push_back({1, u, v, 0}); }
    void add(int v, ll x) { ops.push_back({2, v, -1, x}); }
    // v の連結成分の値の和を尋ねる
    void query(int v) { ops.push_back({3, v, -1, 0}); }

    vector<ll> solve() {
        int T = ops.size();
        int sz = 1;
        while (sz < std::max(T, 1)) sz <<= 1;
        vector<vector<pair<int, int>>> seg(2 * sz);
        auto put = [&](int l, int r, pair<int, int> e) {
            for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
                if (l & 1) seg[l++].push_back(e);
                if (r & 1) seg[--r].push_back(e);
            }
        };
        // 辺 (小さい方, 大きい方) → 追加された時刻
        map<pair<int, int>, int> alive;
        for (int t = 0; t < T; t++) {
            auto &o = ops[t];
            if (o.type > 1) continue;
            pair<int, int> e = minmax(o.u, o.v);
            if (o.type == 0) alive[e] = t;
            else {
                auto it = alive.find(e);
                put(it->second, t, e);
                alive.erase(it);
            }
        }
        for (auto &[e, t] : alive) put(t, T, e);
        // 巻き戻せる Union-Find (経路圧縮なし，大きさで併合)．sum[v] = v の部分木 (Union-Find の木) の値の和
        vector<int> par(n, -1), size_(n, 1), hist;  // hist: 併合で根 a の下に付けた根 b
        vector<ll> sum = init, res;
        auto find = [&](int x) {
            while (par[x] >= 0) x = par[x];
            return x;
        };
        auto dfs = [&](auto self, int k, int l, int r) -> void {
            if (l >= T) return;
            size_t mark = hist.size();
            for (auto [u, v] : seg[k]) {
                int a = find(u), b = find(v);
                if (a == b) continue;
                if (size_[a] < size_[b]) swap(a, b);
                par[b] = a, size_[a] += size_[b], sum[a] += sum[b];
                hist.push_back(b);
            }
            if (r - l == 1) {
                auto &o = ops[l];
                if (o.type == 2) {
                    for (int x = o.u; x >= 0; x = par[x]) sum[x] += o.x;
                } else if (o.type == 3) {
                    res.push_back(sum[find(o.u)]);
                }
            } else {
                int m = (l + r) / 2;
                self(self, 2 * k, l, m), self(self, 2 * k + 1, m, r);
            }
            while (hist.size() > mark) {
                int b = hist.back(), a = par[b];
                hist.pop_back();
                par[b] = -1, size_[a] -= size_[b], sum[a] -= sum[b];
            }
        };
        dfs(dfs, 1, 0, sz);
        return res;
    }
};
