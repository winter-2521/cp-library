#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 最小費用 b-flow (供給・需要と，辺の流量の下限・上限・費用)．容量スケーリング法
//   各頂点 v: (出ていく流量) - (入ってくる流量) = b[v]，各辺 e: lower[e] <= f[e] <= upper[e]，Σ cost[e] f[e] を最小化
// Δ = 2^k, ..., 1 の順に，「残余容量が Δ 以上の辺」だけのグラフで，超過が Δ 以上の頂点から不足が Δ 以上の頂点へ
// Δ ずつ最短路 (ポテンシャル付き Dijkstra) で流す．各段の始めに，残余容量 Δ 以上で被約費用が負の辺は飽和させる．
// 最後に残余グラフで Bellman-Ford をして双対 (ポテンシャル) p を求める (c[e] + p[s] - p[t] >= 0 が残余辺で成り立つ)
// O(m log U · (m + n) log n) (U は容量・供給の最大値)
template <class Cap = long long, class Cost = long long>
struct MinCostBFlow {
    struct Arc {
        int to, rev;
        Cap cap;
        Cost cost;
    };
    int n;
    vector<vector<Arc>> g;
    vector<Cap> b;
    vector<pair<int, int>> pos;  // 辺 e の (頂点, 添字)
    vector<Cap> lower;
    vector<Cost> pot;

    MinCostBFlow(int n) : n(n), g(n), b(n, 0), pot(n, 0) {}

    // 頂点 v の供給を x 増やす (負なら需要)
    void add_supply(int v, Cap x) { b[v] += x; }
    void add_demand(int v, Cap x) { b[v] -= x; }

    // 辺 u → v (流量 [lo, hi]，費用 c) を追加し，番号を返す
    int add_edge(int u, int v, Cap lo, Cap hi, Cost c) {
        assert(lo <= hi);
        int id = pos.size();
        pos.push_back({u, (int)g[u].size()});
        lower.push_back(lo);
        int ru = g[u].size(), rv = g[v].size() + (u == v);
        g[u].push_back({v, rv, hi - lo, c});
        g[v].push_back({u, ru, 0, -c});
        // 下限分を先に流しておく
        b[u] -= lo, b[v] += lo;
        return id;
    }

    // 解けたら true (実行可能でなければ false)
    bool solve() {
        vector<Cap> ex = b;  // 超過 (正なら出したい量)
        Cap total = 0, mx = 1;
        for (int v = 0; v < n; v++) total += ex[v], mx = std::max({mx, ex[v], -ex[v]});
        if (total != 0) return false;
        for (int v = 0; v < n; v++)
            for (auto &a : g[v]) mx = std::max(mx, a.cap);
        Cap delta = 1;
        while (delta <= mx / 2) delta *= 2;
        const Cost INF = numeric_limits<Cost>::max();
        vector<Cost> dist(n);
        vector<int> pv(n), pe(n);
        vector<char> done(n);
        for (; delta >= 1; delta /= 2) {
            // 残余容量 delta 以上で被約費用が負の辺を飽和させる
            for (int v = 0; v < n; v++) {
                for (auto &a : g[v]) {
                    if (a.cap >= delta && a.cost + pot[v] - pot[a.to] < 0) {
                        Cap f = a.cap;
                        a.cap -= f, g[a.to][a.rev].cap += f;
                        ex[v] -= f, ex[a.to] += f;
                    }
                }
            }
            while (true) {
                // 超過 >= delta の頂点から，不足 >= delta の頂点への最短路 (多始点 Dijkstra)
                priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<>> pq;
                fill(dist.begin(), dist.end(), INF);
                fill(done.begin(), done.end(), 0);
                for (int v = 0; v < n; v++)
                    if (ex[v] >= delta) dist[v] = 0, pv[v] = -1, pq.push({0, v});
                if (pq.empty()) break;
                int t = -1;
                Cost dt = 0;
                while (!pq.empty()) {
                    auto [d, v] = pq.top();
                    pq.pop();
                    if (done[v]) continue;
                    done[v] = 1;
                    if (ex[v] <= -delta) {
                        t = v, dt = d;
                        break;
                    }
                    for (int i = 0; i < (int)g[v].size(); i++) {
                        auto &a = g[v][i];
                        if (a.cap < delta) continue;
                        Cost nd = d + a.cost + pot[v] - pot[a.to];
                        if (nd < dist[a.to]) dist[a.to] = nd, pv[a.to] = v, pe[a.to] = i, pq.push({nd, a.to});
                    }
                }
                if (t < 0) break;
                // ポテンシャルの更新 (被約費用を非負に保つ)
                for (int v = 0; v < n; v++) pot[v] += std::min(dist[v], dt);
                // delta 流す
                for (int v = t; pv[v] >= 0; v = pv[v]) {
                    auto &a = g[pv[v]][pe[v]];
                    a.cap -= delta, g[v][a.rev].cap += delta;
                }
                int s = t;
                while (pv[s] >= 0) s = pv[s];
                ex[s] -= delta, ex[t] += delta;
            }
        }
        for (int v = 0; v < n; v++)
            if (ex[v] != 0) return false;
        // 双対: 残余グラフで Bellman-Ford (全頂点を始点 0 として)
        fill(pot.begin(), pot.end(), 0);
        for (int iter = 0; iter < n; iter++) {
            bool upd = false;
            for (int v = 0; v < n; v++)
                for (auto &a : g[v])
                    if (a.cap > 0 && pot[v] + a.cost < pot[a.to]) pot[a.to] = pot[v] + a.cost, upd = true;
            if (!upd) break;
        }
        return true;
    }

    Cap flow(int e) const {
        auto [v, i] = pos[e];
        return lower[e] + g[g[v][i].to][g[v][i].rev].cap;
    }
    Cost potential(int v) const { return pot[v]; }

    // 費用の合計 (大きくなりうるので __int128)
    __int128 cost() const {
        __int128 res = 0;
        for (int e = 0; e < (int)pos.size(); e++) {
            auto [v, i] = pos[e];
            res += (__int128)g[v][i].cost * flow(e);
        }
        return res;
    }
};
