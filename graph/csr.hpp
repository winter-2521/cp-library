#pragma once
#include "../template.hpp"

// 隣接リストを 1 本の配列で持つ (Compressed Sparse Row)
// 頂点 v の隣接は elist[start[v] .. start[v+1])．vector<vector<int>> より速くメモリも少ない
template <class E>
struct CSR {
    vector<int> start;
    vector<E> elist;
    CSR() = default;
    // edges[i] = (from, 中身)
    CSR(int n, const vector<pair<int, E>> &edges) : start(n + 1, 0), elist(edges.size()) {
        for (auto &e : edges) start[e.first + 1]++;
        for (int i = 1; i <= n; i++) start[i] += start[i - 1];
        vector<int> pos(start.begin(), start.end() - 1);
        for (auto &e : edges) elist[pos[e.first]++] = e.second;
    }
    int size() const { return (int)start.size() - 1; }
};
