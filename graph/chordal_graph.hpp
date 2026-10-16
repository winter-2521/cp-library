#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 弦グラフ (長さ 4 以上の誘導閉路がないグラフ) の判定．単純無向グラフについて O(n + m)
// 1. 最大基数探索 (MCS): 「訪問済みの隣の数」が最大の未訪問頂点を順に訪れる (重みごとのバケットで O(n + m))．
//    弦グラフなら訪問順の逆が完全消去順序 (PEO: 各頂点 v と，v より後ろの v の隣が全てクリークになる順序)
// 2. 検査 (Tarjan-Yannakakis): 訪問順で頂点 x の「先に訪れた隣」のうち最後に訪れたものを親 z とし，
//    x の他の先に訪れた隣 y が全て z と隣接するかを，z ごとにまとめて印を付けて調べる
// 3. 検査に失敗した (y - x - z で y と z が隣接しない) なら，x と x の隣 (z 以外) を通らない y から z への最短路を BFS で求め，
//    x を足すと長さ 4 以上の誘導閉路になる
// 返り値: chordal なら peo (完全消去順序)，そうでなければ cycle (誘導閉路の頂点列)
struct ChordalResult {
    bool chordal;
    vector<int> peo, cycle;
};

inline ChordalResult chordal_graph(int n, const vector<pair<int, int>> &edges) {
    vector<int> start(n + 1, 0), adj(2 * edges.size());
    for (auto [a, b] : edges) start[a + 1]++, start[b + 1]++;
    for (int i = 0; i < n; i++) start[i + 1] += start[i];
    {
        vector<int> p(start.begin(), start.end() - 1);
        for (auto [a, b] : edges) adj[p[a]++] = b, adj[p[b]++] = a;
    }
    // 1. MCS．重み w のバケットを双方向連結リストで持つ
    vector<int> w(n, 0), head(n + 1, -1), nx(n), pv(n), ord, idx(n, -1);
    ord.reserve(n);
    auto ins = [&](int v) {
        nx[v] = head[w[v]], pv[v] = -1;
        if (head[w[v]] >= 0) pv[head[w[v]]] = v;
        head[w[v]] = v;
    };
    auto era = [&](int v) {
        if (pv[v] >= 0) nx[pv[v]] = nx[v];
        else head[w[v]] = nx[v];
        if (nx[v] >= 0) pv[nx[v]] = pv[v];
    };
    for (int v = n - 1; v >= 0; v--) ins(v);
    int mx = 0;
    for (int it = 0; it < n; it++) {
        while (head[mx] < 0) mx--;
        int v = head[mx];
        era(v);
        idx[v] = ord.size(), ord.push_back(v);
        for (int j = start[v]; j < start[v + 1]; j++) {
            int u = adj[j];
            if (idx[u] >= 0) continue;
            era(u), w[u]++, ins(u);
            if (w[u] > mx) mx = w[u];
        }
    }
    // 2. 親 z(x) = 先に訪れた隣のうち最後のもの．要求 (z, y, x) を z ごとにまとめる
    vector<int> parent(n, -1), rs(n + 1, 0);
    for (int x = 0; x < n; x++)
        for (int j = start[x]; j < start[x + 1]; j++) {
            int y = adj[j];
            if (idx[y] < idx[x] && (parent[x] < 0 || idx[y] > idx[parent[x]])) parent[x] = y;
        }
    for (int x = 0; x < n; x++)
        if (parent[x] >= 0)
            for (int j = start[x]; j < start[x + 1]; j++)
                if (idx[adj[j]] < idx[x] && adj[j] != parent[x]) rs[parent[x] + 1]++;
    for (int i = 0; i < n; i++) rs[i + 1] += rs[i];
    vector<pair<int, int>> req(rs[n]);
    {
        vector<int> p(rs.begin(), rs.end() - 1);
        for (int x = 0; x < n; x++) {
            int z = parent[x];
            if (z < 0) continue;
            for (int j = start[x]; j < start[x + 1]; j++) {
                int y = adj[j];
                if (idx[y] < idx[x] && y != z) req[p[z]++] = {y, x};
            }
        }
    }
    vector<int> mark(n, -1);
    for (int z = 0; z < n; z++) {
        if (rs[z] == rs[z + 1]) continue;
        for (int j = start[z]; j < start[z + 1]; j++) mark[adj[j]] = z;
        for (int k = rs[z]; k < rs[z + 1]; k++) {
            auto [y, x] = req[k];
            if (mark[y] == z) continue;
            // 3. y - x - z で y, z が隣接しない．x と x の隣 (z 以外) を避けて y から z へ BFS
            vector<char> ban(n, 0);
            ban[x] = 1;
            for (int j = start[x]; j < start[x + 1]; j++) ban[adj[j]] = 1;
            ban[z] = 0;
            vector<int> from(n, -2), que{y};
            from[y] = -1;
            for (size_t h = 0; h < que.size() && from[z] == -2; h++) {
                int v = que[h];
                for (int j = start[v]; j < start[v + 1]; j++) {
                    int u = adj[j];
                    if (ban[u] || from[u] != -2) continue;
                    from[u] = v, que.push_back(u);
                }
            }
            ChordalResult res{false, {}, {}};
            for (int v = z; v >= 0; v = from[v]) res.cycle.push_back(v);
            res.cycle.push_back(x);
            return res;
        }
    }
    reverse(ord.begin(), ord.end());
    return {true, ord, {}};
}
