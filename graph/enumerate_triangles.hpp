#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 三角形の列挙．単純無向グラフの全ての三角形 {a, b, c} について f(a, b, c) を呼ぶ．O(m √m)
// 辺を (次数, 番号) の小さい方から大きい方へ向けると，各頂点から出る辺は √(2m) 本以下になる．
// 各頂点 u について出る先に印を付け，u → v → w と 2 歩進んだ w に印があれば三角形 (各三角形はちょうど 1 回)
template <class F>
void enumerate_triangles(int n, const vector<pair<int, int>> &edges, F f) {
    vector<int> deg(n, 0);
    for (auto [a, b] : edges) deg[a]++, deg[b]++;
    auto less = [&](int a, int b) { return deg[a] != deg[b] ? deg[a] < deg[b] : a < b; };
    vector<int> start(n + 1, 0), to(edges.size());
    for (auto [a, b] : edges) start[(less(a, b) ? a : b) + 1]++;
    for (int i = 0; i < n; i++) start[i + 1] += start[i];
    {
        vector<int> pos(start.begin(), start.end() - 1);
        for (auto [a, b] : edges) {
            if (!less(a, b)) swap(a, b);
            to[pos[a]++] = b;
        }
    }
    vector<int> mark(n, -1);
    for (int u = 0; u < n; u++) {
        for (int i = start[u]; i < start[u + 1]; i++) mark[to[i]] = u;
        for (int i = start[u]; i < start[u + 1]; i++) {
            int v = to[i];
            for (int j = start[v]; j < start[v + 1]; j++)
                if (mark[to[j]] == u) f(u, v, to[j]);
        }
    }
}
