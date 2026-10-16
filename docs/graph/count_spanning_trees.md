---
title: 全域木の数え上げ (行列木定理)
documentation_of: //graph/count_spanning_trees.hpp
---

## 概要

行列木定理で全域木の個数を mod で数える。多重辺は別の辺として数え、自己ループは使われない。$O(n^3 + m)$。

- **無向**：ラプラシアン $L = D - A$（$D$ は次数の対角行列、$A$ は隣接行列（多重度つき））から 1 行 1 列を除いた行列式。
- **有向**（根 $r$ から全頂点に到達できる有向全域木）：$L = D_{\mathrm{in}} - A$（入次数）から $r$ の行と列を除いた行列式。各頂点 $v \ne r$ が入ってくる辺を 1 本ずつ選ぶ選び方のうち、閉路のないものを数えている。

## 使い方

```cpp
mint a = count_spanning_trees_undirected<mint>(n, edges);
mint b = count_spanning_trees_directed<mint>(n, edges, r);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `mint count_spanning_trees_undirected<mint>(int n, edges)` | 無向グラフの全域木の個数 | $O(n^3 + m)$ |
| `mint count_spanning_trees_directed<mint>(int n, edges, int r)` | 根 $r$ の有向全域木の個数 | $O(n^3 + m)$ |

## 注意

- 「$r$ に向かう」有向全域木の個数は、辺を逆向きにして `count_spanning_trees_directed` に渡す。
