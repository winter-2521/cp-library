#pragma once
#include "../template.hpp"

// https://github.com/winter-2521/cp-library

// 根付き木の部分木の同型類の分類 (AHU 法)．各頂点 v を根とする部分木に番号 id[v] を振り，
// id[u] == id[v] ⇔ 2 つの部分木が根付き木として同型，となるようにする．
// 葉から順に「子の番号を昇順に並べた列」を作り，同じ列には同じ番号を振る．
// 同型な部分木は高さが等しいので，高さごとに列をソートして番号を付ける．O(n log n)
// 引数: par[v] = 親 (根は -1)．返り値: {種類数, id}
inline pair<int, vector<int>> rooted_tree_isomorphism(const vector<int> &par) {
    int n = par.size();
    vector<int> start(n + 1, 0), ch(n), height(n, 0);
    for (int v = 0; v < n; v++)
        if (par[v] >= 0) start[par[v] + 1]++;
    for (int i = 0; i < n; i++) start[i + 1] += start[i];
    {
        vector<int> p(start.begin(), start.end() - 1);
        for (int v = 0; v < n; v++)
            if (par[v] >= 0) ch[p[par[v]]++] = v;
    }
    // BFS 順の逆 (子が先) で高さ
    vector<int> bfs;
    bfs.reserve(n);
    for (int v = 0; v < n; v++)
        if (par[v] < 0) bfs.push_back(v);
    for (int i = 0; i < (int)bfs.size(); i++)
        for (int j = start[bfs[i]]; j < start[bfs[i] + 1]; j++) bfs.push_back(ch[j]);
    int H = 0;
    for (int i = n - 1; i >= 0; i--) {
        int v = bfs[i];
        if (par[v] >= 0) height[par[v]] = std::max(height[par[v]], height[v] + 1);
        H = std::max(H, height[v]);
    }
    // 高さごとの頂点
    vector<int> hs(H + 2, 0), byh(n);
    for (int v = 0; v < n; v++) hs[height[v] + 1]++;
    for (int h = 0; h <= H; h++) hs[h + 1] += hs[h];
    {
        vector<int> p(hs.begin(), hs.end() - 1);
        for (int v = 0; v < n; v++) byh[p[height[v]]++] = v;
    }
    vector<int> id(n, -1), sig(n);  // sig: 子の番号 (頂点ごとに start の区間)
    int K = 0;
    for (int h = 0; h <= H; h++) {
        // 子の番号を昇順に
        for (int i = hs[h]; i < hs[h + 1]; i++) {
            int v = byh[i];
            for (int j = start[v]; j < start[v + 1]; j++) sig[j] = id[ch[j]];
            sort(sig.begin() + start[v], sig.begin() + start[v + 1]);
        }
        auto less = [&](int a, int b) {
            return lexicographical_compare(sig.begin() + start[a], sig.begin() + start[a + 1], sig.begin() + start[b],
                                           sig.begin() + start[b + 1]);
        };
        sort(byh.begin() + hs[h], byh.begin() + hs[h + 1], less);
        for (int i = hs[h]; i < hs[h + 1]; i++) {
            int v = byh[i];
            if (i > hs[h] && !less(byh[i - 1], v)) id[v] = id[byh[i - 1]];
            else id[v] = K++;
        }
    }
    return {K, id};
}
