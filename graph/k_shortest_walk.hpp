#pragma once
#include "../template.hpp"
#include "csr.hpp"

// s から t への短い方から K 個のウォーク (同じ頂点・辺を何度通ってもよい路) の長さ (Eppstein 法)
// 辺の重みは非負．返り値は長さの昇順で，K 個に満たなければその分だけ
// 1. t への最短距離 dist と，各頂点から t への最短路木を作る
// 2. 最短路木に使わない辺 e = (u → w) を「寄り道」と呼び，その追加コスト δ(e) = c + dist[w] - dist[u] >= 0
// 3. H[v] = v から最短路木で t に向かう途中の頂点から出る寄り道全部を δ でまとめた永続ヒープ (H[v] = H[親] + v の寄り道)
// 4. ウォークは「寄り道の列」と 1 対 1 に対応し，それを優先度付きキューで小さい順に取り出す
// O((n + m) log m + K log K)
template <class T>
vector<T> k_shortest_walks(int n, const vector<tuple<int, int, T>> &edges, int s, int t, int K) {
    int m = edges.size();
    const T INF = numeric_limits<T>::max();
    // 逆向きの Dijkstra (t から)
    vector<pair<int, int>> rel(m);
    for (int i = 0; i < m; i++) rel[i] = {get<1>(edges[i]), i};
    CSR<int> rg(n, rel);
    vector<T> dist(n, INF);
    vector<int> tree_edge(n, -1), order;  // tree_edge[v]: v から t への最短路木で使う辺
    order.reserve(n);
    {
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;
        dist[t] = 0, pq.push({0, t});
        while (!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if (d != dist[v]) continue;
            order.push_back(v);
            for (int i = rg.start[v]; i < rg.start[v + 1]; i++) {
                int e = rg.elist[i], u = get<0>(edges[e]);
                T nd = d + get<2>(edges[e]);
                if (nd < dist[u]) dist[u] = nd, tree_edge[u] = e, pq.push({nd, u});
            }
        }
    }
    vector<T> res;
    if (dist[s] == INF) return res;
    // 永続 leftist heap (キーは δ，値は寄り道の行き先の頂点)
    struct Node {
        T key;
        int to, l, r, rk;
    };
    vector<Node> hp{{T(0), -1, 0, 0, 0}};  // 0 番は空
    auto merge = [&](auto self, int a, int b) -> int {
        if (!a || !b) return a ^ b;
        if (hp[b].key < hp[a].key) swap(a, b);
        Node nd = hp[a];
        int r = self(self, nd.r, b);
        nd.r = r;
        if (hp[nd.l].rk < hp[nd.r].rk) swap(nd.l, nd.r);
        nd.rk = hp[nd.r].rk + 1;
        hp.push_back(nd);
        return hp.size() - 1;
    };
    vector<pair<int, int>> fel(m);
    for (int i = 0; i < m; i++) fel[i] = {get<0>(edges[i]), i};
    CSR<int> fg(n, fel);
    vector<int> H(n, 0);
    // t に近い順 (dist の昇順) に H を作る
    for (int v : order) {
        int h = v == t ? 0 : H[get<1>(edges[tree_edge[v]])];
        for (int i = fg.start[v]; i < fg.start[v + 1]; i++) {
            int e = fg.elist[i], w = get<1>(edges[e]);
            if (e == tree_edge[v] || dist[w] == INF) continue;
            T delta = get<2>(edges[e]) + dist[w] - dist[v];
            hp.push_back({delta, w, 0, 0, 1});
            h = merge(merge, h, (int)hp.size() - 1);
        }
        H[v] = h;
    }
    res.push_back(dist[s]);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;  // (長さ, ヒープのノード)
    if (H[s]) pq.push({dist[s] + hp[H[s]].key, H[s]});
    while ((int)res.size() < K && !pq.empty()) {
        auto [d, x] = pq.top();
        pq.pop();
        res.push_back(d);
        // 同じヒープの中で次の寄り道に替える
        for (int c : {hp[x].l, hp[x].r})
            if (c) pq.push({d - hp[x].key + hp[c].key, c});
        // この寄り道の後に，行き先から更に寄り道を足す
        int nh = H[hp[x].to];
        if (nh) pq.push({d + hp[nh].key, nh});
    }
    return res;
}
