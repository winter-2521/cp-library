---
title: 4-閉路の数え上げ (Counting C4)
documentation_of: //graph/counting_c4.hpp
---

## 概要

無向グラフの各辺について、その辺を含む 4-閉路（4 頂点を一周する閉路）の個数を求める。多重辺は別の辺として数える。$O(m\sqrt{m})$。

1. 多重辺をまとめ、単純グラフの辺に重み（本数）を付ける。
2. 頂点を (次数, 番号) で順位付けし、閉路を「順位最大の頂点 $u$」と「その対角の頂点 $w$」で分類する。$u - v - w$（$v, w$ は $u$ より順位が小さい）という道を列挙して $\mathrm{cnt}[w]$ に足す。
3. もう一度同じ道を列挙し、道 $u - v - w$ を含む閉路の数 $\mathrm{cnt}[w] - c(uv)c(vw)$ を 2 本の辺に足す。

## 使い方

```cpp
vector<pair<int, int>> edges;
vector<long long> a = counting_c4(n, edges);   // a[i] = 辺 i を含む 4-閉路の数
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<long long> counting_c4(int n, edges)` | 各辺を含む 4-閉路の個数 | $O(m\sqrt{m} + m \log m)$ |

## 注意

- 自己ループは無視される（4-閉路には入らない）。
- 4-閉路の総数は `accumulate(a) / 4`。
