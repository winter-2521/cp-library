---
title: 二部グラフの辺彩色 (Bipartite Edge Coloring)
documentation_of: //graph/bipartite_edge_coloring.hpp
---

## 概要

二部グラフの辺を、同じ頂点に接する辺が全て異なる色になるように、最大次数 $\Delta$ 色で塗る（Kőnig の辺彩色定理より $\Delta$ 色で必ず足りる）。$O(m\sqrt{n}\log\Delta)$。

1. 同じ側の頂点を「次数の和が $\Delta$ 以下」になるようにまとめて両側の頂点数をそろえ、ダミー辺を足して $\Delta$-正則な二部多重グラフにする（色の衝突は元のグラフでも起きない）。
2. $\Delta$ が奇数なら完全マッチング（正則二部グラフには必ずある。[二部マッチング](bipartite_matching.hpp)）を 1 色で塗って取り除き、$\Delta - 1$ にする。
3. $\Delta$ が偶数ならオイラー閉路に沿って辺を交互に 2 つに分ける。各頂点で次数がちょうど半分ずつになり、$\Delta/2$-正則グラフ 2 つを再帰的に塗る。

## 使い方

```cpp
vector<pair<int, int>> edges;   // (左, 右)
auto [k, color] = bipartite_edge_coloring(L, R, edges);   // k = Δ, color[i] ∈ [0, k)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `pair<int, vector<int>> bipartite_edge_coloring(int L, int R, edges)` | 色数 $\Delta$ と各辺の色 | $O(m\sqrt{n}\log\Delta)$ |

## 注意

- 多重辺があってもよい（同じ頂点対の辺にも別の色がつく）。
