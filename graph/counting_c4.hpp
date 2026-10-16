#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 各辺を含む 4-閉路 (C4) の個数．多重辺があってもよい (多重辺は別の辺として数える．自己ループは使われない)．O(m √m)
// 1. 多重辺をまとめ，単純グラフの辺 e に重み (本数) c(e) を付ける
// 2. 頂点を (次数, 番号) で順位付けし，閉路の中で順位最大の頂点 u と，その対角の頂点 w で閉路を分類する．
//    u - v - w (v, w は u より順位が小さい) という道を全部列挙し，cnt[w] += c(uv) c(vw) とする (道 1 本 = 半分の閉路)
// 3. もう一度同じ道を列挙し，道 u - v - w を含む閉路の数 (重み付き) = cnt[w] - c(uv) c(vw) を，
//    辺 uv には c(vw) 倍，辺 vw には c(uv) 倍して足す (もう半分の道 u - x - w の 2 辺も，その道を列挙したときに足される)
// 順位が u より小さい隣だけを見るので，各 u からの列挙は O(√m) × 次数で全体 O(m √m)
// 返り値: 元の辺ごとの個数
inline vector<long long> counting_c4(int n, const vector<pair<int, int>> &edges) {
    int m = edges.size();
    // 1. 多重辺をまとめる
    vector<long long> key(m);
    for (int i = 0; i < m; i++) {
        auto [a, b] = edges[i];
        if (a > b) swap(a, b);
        key[i] = (long long)a * n + b;
    }
    vector<int> ord(m);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return key[i] < key[j]; });
    vector<int> sid(m);
    vector<pair<int, int>> se;
    vector<long long> mult;
    for (int k = 0; k < m; k++) {
        int i = ord[k];
        if (edges[i].first == edges[i].second) {
            sid[i] = -1;
            continue;
        }
        if (se.empty() || key[ord[k - 1]] != key[i] || edges[ord[k - 1]].first == edges[ord[k - 1]].second)
            se.push_back({(int)(key[i] / n), (int)(key[i] % n)}), mult.push_back(0);
        sid[i] = se.size() - 1, mult.back()++;
    }
    int k = se.size();
    // 2. 順位．隣接リストを順位の昇順に並べる
    vector<int> deg(n, 0);
    for (auto [a, b] : se) deg[a]++, deg[b]++;
    vector<int> byrank(n), rnk(n);
    iota(byrank.begin(), byrank.end(), 0);
    sort(byrank.begin(), byrank.end(), [&](int a, int b) { return deg[a] != deg[b] ? deg[a] < deg[b] : a < b; });
    for (int i = 0; i < n; i++) rnk[byrank[i]] = i;
    vector<int> start(n + 1, 0);
    for (auto [a, b] : se) start[a + 1]++, start[b + 1]++;
    for (int i = 0; i < n; i++) start[i + 1] += start[i];
    vector<pair<int, int>> adj(2 * k);  // (順位, 単純辺の番号)
    {
        vector<int> pos(start.begin(), start.end() - 1);
        for (int e = 0; e < k; e++) {
            auto [a, b] = se[e];
            adj[pos[a]++] = {rnk[b], e}, adj[pos[b]++] = {rnk[a], e};
        }
        for (int v = 0; v < n; v++) sort(adj.begin() + start[v], adj.begin() + start[v + 1]);
    }
    vector<long long> cnt(n, 0), sres(k, 0);
    vector<int> touched;
    for (int ru = 0; ru < n; ru++) {
        int u = byrank[ru];
        for (int pass = 0; pass < 2; pass++) {
            for (int i = start[u]; i < start[u + 1] && adj[i].first < ru; i++) {
                int v = byrank[adj[i].first], e1 = adj[i].second;
                long long c1 = mult[e1];
                for (int j = start[v]; j < start[v + 1] && adj[j].first < ru; j++) {
                    int w = adj[j].first, e2 = adj[j].second;
                    long long c2 = mult[e2];
                    if (pass == 0) {
                        if (cnt[w] == 0) touched.push_back(w);
                        cnt[w] += c1 * c2;
                    } else {
                        long long other = cnt[w] - c1 * c2;
                        sres[e1] += c2 * other, sres[e2] += c1 * other;
                    }
                }
            }
        }
        for (int w : touched) cnt[w] = 0;
        touched.clear();
    }
    vector<long long> res(m, 0);
    for (int i = 0; i < m; i++)
        if (sid[i] >= 0) res[i] = sres[sid[i]];
    return res;
}
