---
title: 二重頂点連結成分分解 (Biconnected Components)
documentation_of: //graph/biconnected_components.hpp
---

## 概要

無向グラフを二重頂点連結成分（関節点で切った「ブロック」）に分解する。DFS で辺をスタックに積み、子 $v$ の探索が終わって $\mathrm{low}[v] \ge \mathrm{ord}[\text{親}]$ なら、親は関節点（または根）なので、辺 (親, $v$) までをスタックから取り出したものが 1 つの成分。非再帰で $O(n + m)$。

関節点は複数の成分に入る。辺のない頂点は 1 頂点だけの成分になる。

## 使い方

```cpp
vector<pair<int, int>> edges;
vector<vector<int>> edge_groups;
auto groups = biconnected_components(n, edges, &edge_groups);   // 成分ごとの頂点 (edge_groups は省略可)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<vector<int>> biconnected_components(n, edges, edge_groups = nullptr)` | 成分ごとの頂点（と辺） | $O(n + m)$ |

## 注意

- 自己ループは無視する。
