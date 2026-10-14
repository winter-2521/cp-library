---
title: CSR (隣接リストを 1 本の配列で持つ)
documentation_of: //graph/csr.hpp
---

## 概要

グラフの隣接リストを、`vector<vector<int>>` ではなく 1 本の配列で持つ（Compressed Sparse Row）。頂点 $v$ の隣接は `elist[start[v] .. start[v+1])`。メモリの確保が 2 回で済み、隣接を読むときも連続アクセスになるので速い。グラフのライブラリの内部で使っている。

## 使い方

```cpp
vector<pair<int, int>> el;          // (from, 中身) の列．中身は行き先や辺番号など
CSR<int> g(n, el);
for (int i = g.start[v]; i < g.start[v + 1]; i++) { int x = g.elist[i]; ... }
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `CSR<E>(int n, const vector<pair<int, E>> &edges)` | 構築（同じ頂点の中では入力順） | $O(n + m)$ |
