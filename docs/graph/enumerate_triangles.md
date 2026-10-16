---
title: 三角形の列挙
documentation_of: //graph/enumerate_triangles.hpp
---

## 概要

単純無向グラフの全ての三角形を列挙する。$O(m\sqrt{m})$。

辺を (次数, 番号) の小さい方から大きい方へ向けると、各頂点から出る辺は $\sqrt{2m}$ 本以下になる。各頂点 $u$ について出る先に印を付け、$u \to v \to w$ と 2 歩進んだ $w$ に印があれば三角形（各三角形はちょうど 1 回見つかる）。

## 使い方

```cpp
vector<pair<int, int>> edges;
enumerate_triangles(n, edges, [&](int a, int b, int c) { ... });
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `void enumerate_triangles(int n, edges, F f)` | 全ての三角形で `f(a, b, c)` を呼ぶ | $O(m\sqrt{m})$ |

## 注意

- 単純グラフであること（多重辺があると同じ三角形を複数回数える）。
- 三角形の個数は $O(m\sqrt{m})$ 個以下。
