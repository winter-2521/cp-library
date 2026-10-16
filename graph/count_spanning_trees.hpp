#pragma once
#include "../template.hpp"
#include "../math/determinant.hpp"

// https://github.com/winter-2521/cp-library

// 全域木の数え上げ (行列木定理)．多重辺は別の辺として数える．自己ループは使われない．O(n^3 + m)
// 無向: ラプラシアン L = (次数の対角行列) - (隣接行列) から 1 行 1 列を除いた行列式
// 有向 (根 r から全頂点に行ける有向全域木): L = (入次数の対角行列) - (隣接行列) から r の行と列を除いた行列式
//   (各頂点 v ≠ r が「入ってくる辺」を 1 本ずつ選ぶ選び方のうち，閉路のないものを数えている)

template <class mint>
mint count_spanning_trees_undirected(int n, const vector<pair<int, int>> &edges) {
    if (n == 1) return mint(1);
    // 頂点 n-1 を除く
    vector<vector<mint>> L(n - 1, vector<mint>(n - 1, mint(0)));
    for (auto [a, b] : edges) {
        if (a == b) continue;
        if (a < n - 1) L[a][a] += 1;
        if (b < n - 1) L[b][b] += 1;
        if (a < n - 1 && b < n - 1) L[a][b] -= 1, L[b][a] -= 1;
    }
    return determinant(std::move(L));
}

template <class mint>
mint count_spanning_trees_directed(int n, const vector<pair<int, int>> &edges, int r) {
    if (n == 1) return mint(1);
    // r を除いた番号
    auto id = [&](int v) { return v < r ? v : v - 1; };
    vector<vector<mint>> L(n - 1, vector<mint>(n - 1, mint(0)));
    for (auto [a, b] : edges) {
        if (a == b || b == r) continue;
        L[id(b)][id(b)] += 1;
        if (a != r) L[id(a)][id(b)] -= 1;
    }
    return determinant(std::move(L));
}
