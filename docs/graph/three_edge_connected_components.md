---
title: 三重辺連結成分分解 (Three-Edge-Connected Components)
documentation_of: //graph/three_edge_connected_components.hpp
---

## 概要

無向グラフを三重辺連結成分（どの 2 本の辺を取り除いても互いに連結なままの頂点の極大集合）に分解する。Tsin のパス吸収法を非再帰で実装。$O(n + m)$。

DFS をしながら、各頂点 $v$ について

- $\mathrm{deg}[v]$：$v$ の（今の）成分から祖先へ出ていく辺の本数（DFS 木の親への辺を除く）
- $v$ のパス：$v$ から DFS 木を下に伸びる、まだ成分が確定していない頂点の列（`path` でつなぐ）

を持つ。子 $w$ の探索が終わったとき、$w$ のパスが $w$ だけで $\mathrm{deg}[w] \le 1$ なら、$w$ の成分は「親への辺 + 高々 1 本」でしか外とつながらない（橋か 2 辺カット）ので独立した成分として確定する。そうでなければ、low の小さい方のパスを残し、もう一方を $v$ に吸収（同じ成分として併合）する。子孫からの後退辺を見たときは、その子孫を含むパス上の頂点を吸収する。

## 使い方

```cpp
vector<pair<int, int>> edges;
auto groups = three_edge_connected_components(n, edges);   // 成分ごとの頂点
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<vector<int>> three_edge_connected_components(n, edges)` | 成分ごとの頂点 | $O(n + m)$ |

## 参考

- Y. H. Tsin, "A Simple 3-Edge-Connected Component Algorithm", Theory of Computing Systems, 2007.
