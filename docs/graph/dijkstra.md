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
// path    : s から t への最短経路の頂点列 (s, ..., t)。到達不可能なら空
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `Pathutil<T> Dijikstra(const Graph<T> &G, int from, int to = 0)` | `from` からの最短距離と、`from` から `to` への経路を返す | $O((V + E) \log V)$ |

## 注意

- **辺のコストは非負であること。** 負辺を見つけると `assert` で落ちる（`-DNDEBUG` 付きでコンパイルするとチェックされず、誤った答えになる）。
- `to` に到達できない場合、`path` は空になる。
- 到達不可能を `-1` で表すので、`T` は符号付き型を使うこと。
- 経路が不要なら `to` は省略してよい（`to = 0` への経路が計算されるだけ）。
