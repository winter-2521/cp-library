#pragma once
#include "../template.hpp"

template<typename T = int>
struct WeightedUnionFind {

    // 親・rank・重みを保存する配列を定義
    vector<int> par;
    vector<int> rank;
    vector<T> diff_weight;

    WeightedUnionFind(int n = 1, T SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    // 集合の代表元を返す
    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = find(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }
    
    // 単位元 SUM_UNITY を基準とした頂点 x の重みを返す
    T weight(int x) {
        find(x);
        return diff_weight[x];
    }

    // x と y が同じ集合に属すならtrue , それ以外でfalseを返す．
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    // x-y = w となるように集合をマージ，すでにマージ済みならfalseが帰る．
    bool unite(int x, int y, T w) {
        w += weight(x); w -= weight(y);
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    // x-yを出力
    T diff(int x, int y) {
        return weight(y) - weight(x);
    }
};