---
title: グラフテンプレート
documentation_of: //graph/graph-template.hpp
---

## 概要

隣接リスト形式のグラフ。グラフ系ライブラリ（ダイクストラ法など）の共通の入力形式。
頂点は 0-indexed。[ei1333 さんのライブラリ](https://ei1333.github.io/library/graph/graph-template.hpp) を参考にしている。

## 使い方

```cpp
Graph<long long> g(n);          // 頂点数 n, 辺のコストの型 T (デフォルト int)
g.add_edge(a, b, c);            // 無向辺 a - b (コスト c, 省略時 1)
g.add_directed_edge(a, b, c);   // 有向辺 a -> b (コスト c, 省略時 1)
for (auto &e : g[v]) {          // v から出る辺
    // e.from, e.to, e.cost, e.idx (辺の追加順の番号)
}
g.size();                       // 頂点数
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `Graph(int n)` | 頂点数 `n` で初期化 | $O(n)$ |
| `void add_directed_edge(int from, int to, T cost = 1)` | 有向辺を追加 | ならし $O(1)$ |
| `void add_edge(int from, int to, T cost = 1)` | 無向辺を追加（両方向に同じ `idx` を振る） | ならし $O(1)$ |
| `operator[](int k)` | 頂点 `k` から出る辺のリスト | $O(1)$ |
| `size_t size()` | 頂点数 | $O(1)$ |

## 注意

- 辺番号 `idx` は追加順に 0, 1, 2, ... と振られる。無向辺は両方向の辺が同じ番号を持つので、橋・関節点などで「来た辺」を判定するのに使える。
