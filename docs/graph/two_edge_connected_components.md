---
title: 二重辺連結成分分解 (Two-Edge-Connected Components)
documentation_of: //graph/two_edge_connected_components.hpp
---

## 概要

無向グラフを、**橋**（取り除くと連結成分が増える辺）で切った連結成分に分解する。lowlink（DFS 木で、子孫から後退辺 1 本で行ける最も浅い頂点の訪問順）を非再帰 DFS で求め、$\mathrm{low}[v] = \mathrm{ord}[v]$ となる頂点 $v$ の部分木（の、まだ取り出していない頂点）を 1 つの成分として取り出す。多重辺は辺番号で区別するので、2 本の平行な辺は橋にならない。$O(n + m)$。

## 使い方

```cpp
vector<pair<int, int>> edges;
vector<int> comp;
vector<char> is_bridge;
auto groups = two_edge_connected_components(n, edges, &comp, &is_bridge);   // comp, is_bridge は省略可
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<vector<int>> two_edge_connected_components(n, edges, comp = nullptr, is_bridge = nullptr)` | 成分ごとの頂点 | $O(n + m)$ |
