---
title: 根付き木の同型分類 (AHU)
documentation_of: //tree/rooted_tree_isomorphism.hpp
---

## 概要

根付き木の各頂点 $v$ を根とする部分木に番号 `id[v]` を振り、「`id` が等しい ⇔ 根付き木として同型」とする（AHU 法）。

葉から順に「子の番号を昇順に並べた列」を作り、同じ列には同じ番号を振る。同型な部分木は高さが等しいので、高さごとに列をソートして番号を付ける。$O(n \log n)$。

## 使い方

```cpp
vector<int> par(n);                           // 親 (根は -1)
auto [K, id] = rooted_tree_isomorphism(par);  // 種類数, 各頂点の番号 (0..K-1)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `pair<int, vector<int>> rooted_tree_isomorphism(par)` | 部分木の同型類の番号 | $O(n \log n)$ |

## 注意

- 森（根が複数）でもよい。
- 根なし木の同型判定は、中心（1 つか 2 つ）を根にして比べる。
