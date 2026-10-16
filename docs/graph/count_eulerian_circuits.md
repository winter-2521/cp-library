---
title: オイラー閉路の数え上げ (BEST 定理)
documentation_of: //graph/count_eulerian_circuits.hpp
---

## 概要

有向グラフのオイラー閉路の個数（巡回シフトで一致するものは同じ = 辺 0 から始まるものの個数）を BEST 定理で数える。

$$
\mathrm{ec}(G) = t_w(G) \prod_v (\mathrm{outdeg}(v) - 1)!
$$

$t_w(G)$ は頂点 $w$ に向かう有向全域木の個数で、辺を逆にしたグラフの $w$ から出る有向全域木の個数（[全域木の数え上げ](count_spanning_trees.hpp)）。辺のない頂点は除いて考える。$O(n^3 + m)$。

## 使い方

```cpp
mint c = count_eulerian_circuits<mint>(n, edges);   // 有向辺 (from, to)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `mint count_eulerian_circuits<mint>(int n, edges)` | オイラー閉路の個数 | $O(n^3 + m)$ |

## 注意

- 入次数 ≠ 出次数の頂点がある、または辺のある頂点が全てつながっていなければ 0。
- 辺は全て区別する（多重辺は別の辺）。
