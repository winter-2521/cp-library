#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 重み付き木の直径．適当な頂点 s から最も遠い頂点 u を求め，u から最も遠い頂点 v を求めると u - v が直径 (2 回の探索)
// 木なので最短路は BFS の順 (親から子へ) に距離を足すだけで求まる．O(n)
// 返り値: {直径の長さ, 道の頂点列 (u から v)}
template <class T>
pair<T, vector<int>> tree_diameter(int n, const vector<tuple<int, int, T>> &edges) {
    vector<int> start(n + 1, 0);
    vector<pair<int, T>> adj(2 * (n - 1));
    for (auto &[a, b, c] : edges) start[a + 1]++, start[b + 1]++;
    for (int i = 0; i < n; i++) start[i + 1] += start[i];
    {
        vector<int> p(start.begin(), start.end() - 1);
        for (auto &[a, b, c] : edges) adj[p[a]++] = {b, c}, adj[p[b]++] = {a, c};
    }
    vector<T> dist(n);
    vector<int> par(n), que(n);
    // s から最も遠い頂点 (par に最短路木)
    auto farthest = [&](int s) {
        dist[s] = 0, par[s] = -1, que[0] = s;
        int qt = 1, best = s;
        for (int qh = 0; qh < qt; qh++) {
            int v = que[qh];
            if (dist[v] > dist[best]) best = v;
            for (int j = start[v]; j < start[v + 1]; j++) {
                auto [w, c] = adj[j];
                if (w != par[v]) dist[w] = dist[v] + c, par[w] = v, que[qt++] = w;
            }
        }
        return best;
    };
    int u = farthest(0), v = farthest(u);
    vector<int> path;
    for (int x = v; x >= 0; x = par[x]) path.push_back(x);
    reverse(path.begin(), path.end());
    return {dist[v], path};
}
