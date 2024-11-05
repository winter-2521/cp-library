#pragma once
#include "graph-template.hpp"

template <typename T>
struct Pathutil{
    // 各頂点への距離を表す配列
    vector<T> dist;

    // どこからきたかを表す配列
    vector<int> prev;

    // 最短経路をパスで返す配列
    vector<int> path;
};

// グラフは全て 0-index で扱っている
template <typename T = long long>
Pathutil<T> Dijikstra(const Graph<T> &G, int from, int to = 0){

    // 比較用に最大値を定数で定義
    const T INF = numeric_limits<T>::max();
    // 頂点数
    int n = G.size();

    // 距離を格納するvector
    vector<T> distance;

    // パスの復元を行うためにどこから遷移したかをメモ
    vector<int> prev;

    using P = pair<T,int>;

    distance.resize(n,INF);
    prev.resize(n,-1);

    priority_queue<P,vector<P>,greater<P>> pq;
    distance[from] = 0;
    pq.emplace(distance[from], from);

    while(!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;

        // 今見ている頂点の距離が最新の値でなければ飛ばす (高速化用)
        if(distance[v] < p.first) continue;

        for(auto e : G[v]) {
            // ダイクストラは負辺があると壊れる．
            // 正確にはこのアルゴリズムは負の閉路があるとき停止しない
            // 参考 -> https://theory-and-me.hatenablog.com/entry/2019/09/08/182442
            assert(e.to >= 0);
            if(distance[e.to] > distance[v] + e.cost) {
                distance[e.to] = distance[v] + e.cost;
                // v を通って e.to にきた
                prev[e.to] = v;
                pq.emplace(distance[e.to], e.to);
            }
        }
    }

    // 到達不可能な頂点への距離を -1 にする．(競プロでは到達不可能なら　-1　を出力することが通例．)
    for (T &costs : distance)if(costs == INF) costs = -1;

    vector<int> path;
    for (int cur = to; cur != -1; cur = prev[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end()); // 逆順なのでひっくり返す

    return {distance, prev, path};

};
