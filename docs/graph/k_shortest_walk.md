---
title: K 最短路 (K-Shortest Walk, Eppstein)
documentation_of: //graph/k_shortest_walk.hpp
---

## 概要

辺の重みが非負の有向グラフで、$s$ から $t$ への **ウォーク**（同じ頂点・辺を何度通ってもよい路）を短い順に $K$ 個求める（Eppstein のアルゴリズム）。

1. $t$ への最短距離 $\mathrm{dist}$ と、$t$ への最短路木を Dijkstra で求める。
2. 最短路木に使わない辺 $e = (u \to w, c)$ を「寄り道」とし、その追加コスト $\delta(e) = c + \mathrm{dist}[w] - \mathrm{dist}[u] \ge 0$ とする。どのウォークも「寄り道の列」で一意に表せ、長さは $\mathrm{dist}[s] + \sum \delta$。
3. 各頂点 $v$ について、$v$ から最短路木で $t$ に向かう途中の頂点から出る寄り道全部を、$\delta$ をキーとする **永続 leftist heap** $H[v]$ にまとめる（$H[v] = H[\text{木の親}] + v \text{ の寄り道}$ で、親と共有する）。
4. 「今の最後の寄り道を、ヒープの中の子に替える」「今の寄り道の行き先 $w$ から $H[w]$ の最小の寄り道を足す」の 2 通りで次の候補を作り、優先度付きキューで小さい順に取り出す。

## 使い方

```cpp
vector<tuple<int, int, long long>> edges;           // (from, to, 重み)．重みは非負
vector<long long> len = k_shortest_walks(n, edges, s, t, K);   // 昇順．K 個に満たなければその分だけ
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<T> k_shortest_walks(int n, edges, int s, int t, int K)` | 短い順に $K$ 個のウォークの長さ | $O((n + m) \log m + K \log K)$ |

## 注意

- 長さが同じでも、通る辺の列が違えば別のウォークとして数える。
- 永続ヒープのノードは寄り道 1 本あたり $O(\log m)$ 個できる。
