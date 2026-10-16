#pragma once
#include "../template.hpp"
#include "csr.hpp"

// https://github.com/winter-2521/cp-library

// 辺を順に追加していく有向グラフの強連結成分 (Incremental SCC)．オフライン (辺を全部先読みする)
// incremental_scc(n, edges) は各辺 i について「辺 0..t-1 を追加した時点で i の両端が同じ強連結成分になる最小の t」を返す
// (ならなければ m + 1)．t > i である．辺を t の順に Union-Find でつなげば，各時点の強連結成分が分かる
// 時刻について分割統治し，各段で強連結成分分解をする．O(m log m)
inline vector<int> incremental_scc(int n, const vector<pair<int, int>> &edges) {
    int m = edges.size();
    vector<int> ans(m, m + 1);
    // eu, ev: 各辺の端点 (分割統治の中で縮約後の番号に書き換わる)
    vector<int> eu(m), ev(m);
    for (int i = 0; i < m; i++) eu[i] = edges[i].first, ev[i] = edges[i].second;
    vector<int> id(n, -1);  // 頂点番号 → 局所番号 (使い終わったら -1 に戻す)
    vector<int> vs;
    // 局所グラフ (頂点 0..k-1，辺 el) の強連結成分．comp に番号を入れ，個数を返す (Tarjan, 非再帰)
    vector<int> ord, low, it, comp, stk, call;
    auto local_scc = [&](int k, const vector<pair<int, int>> &el) {
        CSR<int> g(k, el);
        ord.assign(k, -1), low.assign(k, 0), it.assign(k, 0), comp.assign(k, -1);
        int now = 0, nc = 0;
        for (int s = 0; s < k; s++) {
            if (ord[s] >= 0) continue;
            call.push_back(s), ord[s] = low[s] = now++, it[s] = g.start[s], stk.push_back(s);
            while (!call.empty()) {
                int v = call.back();
                if (it[v] < g.start[v + 1]) {
                    int to = g.elist[it[v]++];
                    if (ord[to] < 0) {
                        ord[to] = low[to] = now++, it[to] = g.start[to];
                        stk.push_back(to), call.push_back(to);
                    } else if (comp[to] < 0) {
                        low[v] = std::min(low[v], ord[to]);
                    }
                    continue;
                }
                call.pop_back();
                if (!call.empty()) low[call.back()] = std::min(low[call.back()], low[v]);
                if (low[v] == ord[v]) {
                    while (true) {
                        int u = stk.back();
                        stk.pop_back();
                        comp[u] = nc;
                        if (u == v) break;
                    }
                    nc++;
                }
            }
        }
        return nc;
    };
    // ids: 答えが (l, r] にある辺 (番号の昇順)
    auto rec = [&](auto self, int l, int r, vector<int> &ids) -> void {
        if (ids.empty()) return;
        if (r - l == 1) {
            for (int e : ids) ans[e] = r;
            return;
        }
        int mid = (l + r) / 2;
        // 番号が mid 未満の辺 (= 時刻 mid までに追加された辺) で局所グラフを作り，強連結成分分解する
        vs.clear();
        for (int e : ids)
            for (int x : {eu[e], ev[e]})
                if (id[x] < 0) id[x] = vs.size(), vs.push_back(x);
        int k = vs.size(), nc;
        {
            vector<pair<int, int>> el;
            for (int e : ids) {
                if (e >= mid) break;
                el.push_back({id[eu[e]], id[ev[e]]});
            }
            nc = local_scc(k, el);
        }
        // 左: 時刻 mid で両端が同じ成分になった辺 (端点はそのまま)
        // 右: それ以外．端点を成分の代表の頂点に縮約する
        vector<int> head(nc, -1), left, right;
        for (int i = 0; i < k; i++)
            if (head[comp[i]] < 0) head[comp[i]] = vs[i];
        for (int e : ids) {
            int cu = comp[id[eu[e]]], cv = comp[id[ev[e]]];
            if (e < mid && cu == cv) left.push_back(e);
            else right.push_back(e);
        }
        for (int e : right) {
            int nu = head[comp[id[eu[e]]]], nv = head[comp[id[ev[e]]]];
            eu[e] = nu, ev[e] = nv;
        }
        for (int x : vs) id[x] = -1;
        vector<int>().swap(ids), vector<int>().swap(head);
        self(self, mid, r, right);
        self(self, l, mid, left);
    };
    vector<int> all(m);
    iota(all.begin(), all.end(), 0);
    rec(rec, 0, m + 1, all);
    return ans;
}
