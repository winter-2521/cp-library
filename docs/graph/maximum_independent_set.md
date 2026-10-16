---
title: 最大独立集合 (Maximum Independent Set)
documentation_of: //graph/maximum_independent_set.hpp
---

## 概要

$n \le 64$ の無向グラフで、どの 2 頂点も隣接しない頂点集合のうち最大のものを求める。頂点集合を 64 bit 整数で持つ分枝限定法。

- 残りの次数が 0 か 1 の頂点は必ず取ってよい（隣を取る代わりにその頂点を取っても損しない）。
- それ以外は次数最大の頂点 $v$ について「$v$ を取る（隣を全部消す）」「$v$ を取らない」に分ける。次数 3 以上で分けるので $T(n) = T(n-1) + T(n-4)$ より $O(1.381^n)$ 程度。
- 「今の個数 + 残りの頂点数」が今の最良以下なら打ち切る。

## 使い方

```cpp
vector<pair<int, int>> edges;
vector<int> s = maximum_independent_set(n, edges);   // 頂点の列 (昇順)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<int> maximum_independent_set(int n, edges)` | 最大独立集合 | $O(1.381^n n)$ |

## 注意

- 最大クリークは補グラフの最大独立集合、最小頂点被覆は最大独立集合の補集合。
