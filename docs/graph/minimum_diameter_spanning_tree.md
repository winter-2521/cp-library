---
title: 最小直径全域木 (Minimum Diameter Spanning Tree)
documentation_of: //graph/minimum_diameter_spanning_tree.hpp
---

## 概要

連結な重み付き無向グラフの全域木のうち、直径（木の上の最遠 2 点間の距離）が最小のものを求める。

グラフの **絶対 1-中心**（辺の途中も含めて、最も遠い頂点までの距離が最小になる点 $c$）を求め、$c$ からの最短路木を作ると、その直径が最小（= $c$ の離心率の 2 倍）になる。

1. 全点対最短距離を Dijkstra で求める。
2. 各辺 $(u, v, w)$ について、$u$ から $x$ の点の離心率 $\max_k \min(d(u,k) + x,\ d(v,k) + w - x)$ を最小にする $x$ を、頂点を $d(u, \cdot)$ の降順に並べて走査する（Kariv-Hakimi）。
3. 中心を仮の頂点として最短路木を作る。

重みは 2 倍して扱うので、中心が辺の中点のような位置でも整数で計算できる。

## 使い方

```cpp
vector<tuple<int, int, long long>> edges;   // (u, v, 重み)
auto [diam, used] = minimum_diameter_spanning_tree(n, edges);   // 直径, 使う辺の番号 (n-1 本)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `pair<T, vector<int>> minimum_diameter_spanning_tree(int n, edges)` | 最小の直径と全域木 | $O(nm \log n + n^2 \log n)$ |

## 注意

- グラフは連結であること。多重辺・自己ループはあってもよい。
- 全点対の距離を持つのでメモリは $O(n^2)$。
