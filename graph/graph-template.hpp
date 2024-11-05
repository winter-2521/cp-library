#pragma once
#include "../template.hpp"

/*
大きめの道具を作りたくなった時用にグラフテンプレートを作りました
どんな機能が欲しくなるか見通せないので一旦うしさんのライブラリを参考に整備してます (欲しい機能が増えたら変わるかも)
https://ei1333.github.io/library/graph/graph-template.hpp
*/

template <typename T = int>
struct Edge {
    // 辺のfrom , to
    int from, to;

    // 重み付きグラフ用コスト
    T cost;

    // 橋の列挙等が必要な時用の辺の番号
    int idx;

    Edge() = default;

    Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}
};

template <typename T = int>
struct Graph {

    // グラフ本体
    vector<vector<Edge<T> > > g;
    // 辺の番号づけ用変数
    int es;

    Graph() = default;

    explicit Graph(int n) : g(n), es(0) {}

    // 頂点数を返す
    size_t size() const { return g.size(); }

    // 有向辺を追加
    void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }

    // 無向辺を追加
    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    // 頂点番号を入力するとその頂点から生えてる辺の集合を返す
    inline vector<Edge<T> > &operator[](const int &k) { return g[k]; }
    inline const vector<Edge<T> > &operator[](const int &k) const { return g[k]; }
};