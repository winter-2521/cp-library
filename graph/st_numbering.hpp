#pragma once
#include "../template.hpp"
#include "csr.hpp"

// https://github.com/winter-2521/cp-library

// st 番号付け．s が最小，t が最大で，他の全ての頂点が「番号が小さい隣接頂点」と「大きい隣接頂点」を両方持つような番号付け．
// 存在する ⇔ G に辺 (s, t) を足したグラフが二重頂点連結 (n >= 3 のとき)
// s を根，t を最初の子とする DFS で lowlink を求め，先行順に各頂点を「親の直前か直後」に連結リストへ挿入する (Tarjan)．O(n + m)
// 返り値: 各頂点の番号 (0 .. n-1)．存在しなければ空
inline vector<int> st_numbering(int n, const vector<pair<int, int>> &edges, int s, int t) {
    if (n == 1) return {0};
    if (n == 2) {
        // 辺 (s, t) を足して考えるのは n >= 3 のときだけ正しい．n = 2 では実際に辺 s - t が必要
        for (auto [a, b] : edges)
            if ((a == s && b == t) || (a == t && b == s)) {
                vector<int> num(2);
                num[s] = 0, num[t] = 1;
                return num;
            }
        return {};
    }
    vector<pair<int, int>> el;
    el.reserve(2 * edges.size() + 2);
    el.push_back({s, t}), el.push_back({t, s});  // 辺 (s, t) を足す (s から最初に t へ降りる)
    for (auto [a, b] : edges) el.push_back({a, b}), el.push_back({b, a});
    CSR<int> g(n, el);
    vector<int> pre(n, -1), low(n), par(n, -1), order, it(n), call;
    order.reserve(n);
    int cnt = 0;
    pre[s] = low[s] = cnt++, order.push_back(s), it[s] = g.start[s], call.push_back(s);
    vector<char> skipped(n, 0);  // 親への辺を 1 本だけ飛ばしたか
    while (!call.empty()) {
        int v = call.back();
        if (it[v] < g.start[v + 1]) {
            int w = g.elist[it[v]++];
            if (w == par[v] && !skipped[v]) {
                skipped[v] = 1;
                continue;
            }
            if (pre[w] < 0) {
                par[w] = v, pre[w] = low[w] = cnt++, order.push_back(w), it[w] = g.start[w];
                call.push_back(w);
            } else {
                low[v] = std::min(low[v], pre[w]);
            }
            continue;
        }
        call.pop_back();
        if (!call.empty()) low[call.back()] = std::min(low[call.back()], low[v]);
    }
    if (cnt != n) return {};  // 非連結
    // 二重頂点連結か: 根 s の子は t だけ，他の木の辺 (p, c) は low[c] < pre[p]
    for (int v = 0; v < n; v++) {
        if (v == s) continue;
        int p = par[v];
        if (p == s) {
            if (v != t) return {};
        } else if (low[v] >= pre[p]) {
            return {};
        }
    }
    // low を頂点で持ち直す (pre の値 → 頂点)
    // sign[v] = -1 なら v は「親より前」側にいる印
    vector<int> who(n);
    for (int v = 0; v < n; v++) who[pre[v]] = v;
    vector<int> nx(n, -1), pv(n, -1);
    vector<char> minus(n, 0);
    // リスト: s → t
    nx[s] = t, pv[t] = s, minus[s] = 1;
    for (int v : order) {
        if (v == s || v == t) continue;
        int p = par[v], lw = who[low[v]];
        if (minus[lw]) {
            // p の直前に挿入
            int q = pv[p];
            nx[q] = v, pv[v] = q, nx[v] = p, pv[p] = v;
            minus[p] = 0;
        } else {
            // p の直後に挿入
            int q = nx[p];
            nx[p] = v, pv[v] = p, nx[v] = q;
            if (q >= 0) pv[q] = v;
            minus[p] = 1;
        }
    }
    vector<int> num(n);
    int k = 0;
    for (int v = s; v >= 0; v = nx[v]) num[v] = k++;
    return num;
}
