---
title: ダイクストラ法 (Dijkstra)
documentation_of: //graph/dijkstra.hpp
---

## 概要

非負の辺コストを持つグラフで、単一始点からの最短距離と最短経路を求める。
入力は [グラフテンプレート](graph-template.hpp) の `Graph<T>`。頂点は 0-indexed。

## 使い方

```cpp
Graph<long long> g(n);
g.add_directed_edge(a, b, c);

auto [dist, prev, path] = Dijikstra(g, s, t);   // 関数名の綴りは Dijikstra
// dist[v] : s から v への最短距離 (到達不可能なら -1)
// prev[v] : 最短経路木における v の親 (s と到達不可能な頂点は -1)
// path    : s から t への最短経路の頂点列 (s, ..., t)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `Pathutil<T> Dijikstra(const Graph<T> &G, int from, int to = 0)` | `from` からの最短距離と、`from` から `to` への経路を返す | $O((V + E) \log V)$ |

## 注意

- **辺のコストは非負であること。** 負辺があると正しく動かない（ソース中の `assert(e.to >= 0)` は辺コストではなく行き先をチェックしているため、負辺は検出されない）。
- `to` に到達できない場合、`path` は `{to}`（要素数 1）になる。経路を使う前に `dist[to] != -1` を確認すること。
- 到達不可能を `-1` で表すので、`T` は符号付き型を使うこと。
- 経路が不要なら `to` は省略してよい（`to = 0` への経路が計算されるだけ）。
