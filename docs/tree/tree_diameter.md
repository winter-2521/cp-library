---
title: 木の直径
documentation_of: //tree/tree_diameter.hpp
---

## 概要

重み付き木（重みは非負）の直径（最も遠い 2 頂点の距離）とその道を求める。適当な頂点から最も遠い頂点 $u$ を求め、$u$ から最も遠い頂点 $v$ を求めると $u$–$v$ が直径。木なので最短距離は BFS の順に親の距離に足すだけで求まる。$O(n)$、非再帰。

## 使い方

```cpp
vector<tuple<int, int, long long>> edges;     // (u, v, 重み)．n-1 本
auto [len, path] = tree_diameter(n, edges);   // 長さ, 道の頂点列
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `pair<T, vector<int>> tree_diameter(int n, edges)` | 直径と道 | $O(n)$ |

## 注意

- 重みのない木では全て 1 にして渡す。
- 重みが負の辺があると 2 回の探索は正しくない。
