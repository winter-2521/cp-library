#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 割当問題 (Hungarian 法)．n × m (n <= m) の行列 a で，各行に相異なる列を割り当てて和を最小にする．O(n^2 m)
// 行 i を 1 つずつ追加し，ポテンシャル (双対変数) u, v を保ったまま，Dijkstra 風に最短の増加路を見つける
// 返り値: {最小値, p (p[i] = 行 i に割り当てた列)}
template <class T>
pair<T, vector<int>> hungarian(const vector<vector<T>> &a) {
    int n = a.size();
    if (n == 0) return {T(0), {}};
    int m = a[0].size();
    assert(n <= m);
    const T INF = numeric_limits<T>::max() / 2;
    // 1-indexed．列 0 は「まだ割り当てていない行」を置く仮の列
    vector<T> u(n + 1, 0), v(m + 1, 0), minv(m + 1);
    vector<int> p(m + 1, 0), way(m + 1, 0);  // p[j]: 列 j に割り当てた行
    vector<char> used(m + 1);
    for (int i = 1; i <= n; i++) {
        p[0] = i;
        int j0 = 0;
        fill(minv.begin(), minv.end(), INF);
        fill(used.begin(), used.end(), 0);
        do {
            used[j0] = 1;
            int i0 = p[j0], j1 = 0;
            T delta = INF;
            const T *row = a[i0 - 1].data();
            for (int j = 1; j <= m; j++) {
                if (used[j]) continue;
                T cur = row[j - 1] - u[i0] - v[j];
                if (cur < minv[j]) minv[j] = cur, way[j] = j0;
                if (minv[j] < delta) delta = minv[j], j1 = j;
            }
            for (int j = 0; j <= m; j++) {
                if (used[j]) u[p[j]] += delta, v[j] -= delta;
                else minv[j] -= delta;
            }
            j0 = j1;
        } while (p[j0] != 0);
        // 増加路を反転
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    vector<int> ans(n);
    for (int j = 1; j <= m; j++)
        if (p[j]) ans[p[j] - 1] = j - 1;
    T total = 0;
    for (int i = 0; i < n; i++) total += a[i][ans[i]];
    return {total, ans};
}
