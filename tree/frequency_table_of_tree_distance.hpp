#pragma once
#include "../template.hpp"
#include "../math/convolution.hpp"

// https://github.com/winter-2521/cp-library

// 木の距離の度数表．res[d] = 距離 (辺の本数) が d の頂点の組 {u, v} (u ≠ v) の個数 (d = 0..n-1，res[0] = 0)
// 重心分解: 重心 c を通る組を数えてから c を取り除き，残りの各部分木で再帰する．
// c を通る組は「別々の子の部分木 (または c 自身) から 1 つずつ」選んだ組．子を深さの浅い順に見て，
// それまでの深さの度数 A と今の子の度数 C を畳み込んで足し，A += C とする．A の長さは C 以下なので
// 1 回の畳み込みは O(|C| log n)，各段の合計は O(n log n) で全体 O(n log^2 n)
inline vector<long long> frequency_table_of_tree_distance(int n, const vector<pair<int, int>> &edges) {
    vector<long long> res(n, 0);
    if (n <= 1) return res;
    vector<int> start(n + 1, 0), adj(2 * (n - 1));
    for (auto [a, b] : edges) start[a + 1]++, start[b + 1]++;
    for (int i = 0; i < n; i++) start[i + 1] += start[i];
    {
        vector<int> p(start.begin(), start.end() - 1);
        for (auto [a, b] : edges) adj[p[a]++] = b, adj[p[b]++] = a;
    }
    vector<char> removed(n, 0);
    vector<int> sz(n), par(n), que(n), dep(n);
    vector<int> stk{0};
    while (!stk.empty()) {
        int r = stk.back();
        stk.pop_back();
        // r を含む成分の BFS 順と部分木の大きさ
        int qt = 0;
        que[qt++] = r, par[r] = -1;
        for (int qh = 0; qh < qt; qh++) {
            int v = que[qh];
            for (int j = start[v]; j < start[v + 1]; j++) {
                int w = adj[j];
                if (!removed[w] && w != par[v]) par[w] = v, que[qt++] = w;
            }
        }
        for (int i = qt - 1; i >= 0; i--) {
            int v = que[i];
            sz[v] = 1;
            for (int j = start[v]; j < start[v + 1]; j++) {
                int w = adj[j];
                if (!removed[w] && w != par[v]) sz[v] += sz[w];
            }
        }
        // 重心: 子の部分木も上側も qt / 2 以下になる頂点
        int c = r;
        while (true) {
            int nxt = -1;
            for (int j = start[c]; j < start[c + 1]; j++) {
                int w = adj[j];
                if (!removed[w] && w != par[c] && sz[w] * 2 > qt) nxt = w;
            }
            if (nxt < 0) break;
            c = nxt;
        }
        // 子の部分木ごとの深さの度数
        vector<vector<long long>> cnts;
        for (int j = start[c]; j < start[c + 1]; j++) {
            int s = adj[j];
            if (removed[s]) continue;
            int t = 0;
            que[t++] = s, par[s] = c, dep[s] = 1;
            vector<long long> cnt{0};
            for (int h = 0; h < t; h++) {
                int v = que[h];
                if ((int)cnt.size() <= dep[v]) cnt.push_back(0);
                cnt[dep[v]]++;
                for (int k = start[v]; k < start[v + 1]; k++) {
                    int w = adj[k];
                    if (!removed[w] && w != par[v]) par[w] = v, dep[w] = dep[v] + 1, que[t++] = w;
                }
            }
            cnts.push_back(std::move(cnt));
        }
        sort(cnts.begin(), cnts.end(), [](const auto &x, const auto &y) { return x.size() < y.size(); });
        vector<long long> acc{1};  // c 自身 (深さ 0)
        for (auto &cnt : cnts) {
            auto pr = convolve_small(acc, cnt);
            for (int d = 1; d < (int)pr.size(); d++) res[d] += pr[d];
            if (acc.size() < cnt.size()) acc.resize(cnt.size(), 0);
            for (size_t d = 0; d < cnt.size(); d++) acc[d] += cnt[d];
        }
        removed[c] = 1;
        for (int j = start[c]; j < start[c + 1]; j++)
            if (!removed[adj[j]]) stk.push_back(adj[j]);
    }
    return res;
}
