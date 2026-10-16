---
title: 一般グラフの最大マッチング (Edmonds の花アルゴリズム)
documentation_of: //graph/general_matching.hpp
---

## 概要

二部とは限らない無向グラフの最大マッチングを求める。$O(n^3)$（実際には辺の数に応じてずっと速い）。

未マッチの頂点から交互路を BFS で探す。二部グラフと違い奇閉路（**花**）があると交互路がうまく延びないので、花を見つけたらその根（base）1 頂点に縮約したものとして扱う。縮約は各頂点の `base` を書き換えるだけで、グラフは作り直さない。

## 使い方

```cpp
GeneralMatching gm(n);
gm.add_edge(u, v);
int k = gm.solve();                         // 最大マッチングの大きさ
for (auto [u, v] : gm.matching()) { ... }   // u < v
gm.mate[v];                                 // 相手 (いなければ -1)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `GeneralMatching(int n)` | 空のグラフ | $O(n)$ |
| `void add_edge(int u, int v)` | 辺を追加 | 償却 $O(1)$ |
| `int solve()` | 最大マッチングの大きさ | $O(n^3)$ |
| `vector<pair<int,int>> matching()` | マッチングの辺 | $O(n)$ |

## 注意

- 自己ループは無視される。多重辺はあってもよい。
- 二部グラフと分かっているなら [`BipartiteMatching`](bipartite_matching.hpp) の方が速い。
