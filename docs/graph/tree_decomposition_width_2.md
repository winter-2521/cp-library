---
title: 木幅 2 の木分解
documentation_of: //graph/tree_decomposition_width_2.hpp
---

## 概要

単純無向グラフの木幅が 2 以下か判定し、そうなら木幅 2 以下の木分解を作る。期待 $O(n + m)$。

木幅 2 以下 ⇔「次数 0, 1 の頂点を消す」「次数 2 の頂点を消し、2 つの隣を辺で結ぶ（多重辺は 1 本に）」を繰り返して全部消せる。消した順から木分解を作る。

- 頂点 $v$ を消したときのバッグ = $\{v\} \cup$（そのときの隣）
- その親 = 隣のうち先に消えた頂点のバッグ

辺の有無はハッシュ集合、隣接は連結リストで持つ。

## 使い方

```cpp
vector<pair<int, int>> edges;
auto td = tree_decomposition_width_2(n, edges);
if (!td) { /* 木幅 3 以上 */ }
td->bags[v];        // array<int, 3>．先頭 td->bag_size[v] 個が頂点 v を消したときのバッグ
td->edges;          // 木の辺 (バッグ番号の組)．バッグは n 個
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `optional<TreeDecomposition> tree_decomposition_width_2(int n, edges)` | 木分解．なければ `nullopt` | 期待 $O(n + m)$ |

## 注意

- 非連結でもよい（各成分の根を道でつなぐ）。自己ループ・多重辺は無視される。
