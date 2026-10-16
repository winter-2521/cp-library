#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 最小全域木 (Kruskal)．辺を重みの昇順に見て，両端がまだつながっていなければ採用する．O(m log m)
// 返り値: {重みの和, 採用した辺の番号の列}．非連結なら最小全域森
template <class T>
pair<T, vector<int>> minimum_spanning_tree(int n, const vector<tuple<int, int, T>> &edges) {
    int m = edges.size();
    vector<pair<T, int>> ord(m);
    for (int i = 0; i < m; i++) ord[i] = {get<2>(edges[i]), i};
    sort(ord.begin(), ord.end());
    vector<int> par(n, -1);
    auto find = [&](int x) {
        while (par[x] >= 0) {
            if (par[par[x]] >= 0) par[x] = par[par[x]];  // 経路を半分にする
            x = par[x];
        }
        return x;
    };
    T total = 0;
    vector<int> used;
    used.reserve(n ? n - 1 : 0);
    for (auto &[w, i] : ord) {
        int a = find(get<0>(edges[i])), b = find(get<1>(edges[i]));
        if (a == b) continue;
        if (par[a] > par[b]) swap(a, b);
        par[a] += par[b], par[b] = a;
        total += w, used.push_back(i);
        if ((int)used.size() == n - 1) break;
    }
    return {total, used};
}
