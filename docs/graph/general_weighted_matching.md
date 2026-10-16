---
title: 一般グラフの最大重みマッチング
documentation_of: //graph/general_weighted_matching.hpp
---

## 概要

無向グラフで、端点を共有しない辺の集合のうち重みの和が最大のものを求める（Edmonds の主双対法）。$O(n^3)$。

各頂点と花（奇閉路を縮約した頂点）に双対変数（ラベル）を持ち、「両端のラベルの和 = 重み × 2」になる**タイトな辺**だけで交互木を伸ばす。増加路が見つかれば増加し、伸ばせなくなったら双対変数を一斉に $d$ だけ動かして新しいタイトな辺を作る。奇閉路は花として縮約し、花のラベルが 0 になったら展開する。

## 使い方

```cpp
GeneralWeightedMatching<long long> wm(n);
wm.add_edge(u, v, w);                       // 0-indexed, w > 0
auto [sum, cnt] = wm.solve();               // 重みの和, マッチングの辺数
for (auto [u, v] : wm.matching_edges()) { ... }   // u < v
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `GeneralWeightedMatching<W>(int n)` | 空のグラフ | $O(n^2)$ |
| `void add_edge(int u, int v, W w)` | 辺を追加（同じ頂点対は重い方が残る） | $O(1)$ |
| `pair<W,int> solve()` | 最大重みと辺数 | $O(n^3)$ |
| `vector<pair<int,int>> matching_edges()` | マッチングの辺 | $O(n)$ |

## 注意

- 隣接行列で持つのでメモリは $O(n^2)$（$n = 500$ で数十 MB 程度）。
- 求めるのは「重み最大」であって「辺数最大の中で重み最大」ではない。後者が欲しいときは全ての重みに十分大きい定数を足す。
- 重み 0 以下の辺は使われない（足しても意味がない）。
