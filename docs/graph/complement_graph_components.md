---
title: 補グラフの連結成分分解
documentation_of: //graph/complement_graph_components.hpp
---

## 概要

単純無向グラフの **補グラフ**（辺がないところに辺を張ったグラフ）の連結成分を、補グラフを作らずに $O(n + m)$ で求める。

まだどの成分にも入っていない頂点を連結リストで持ち、BFS で頂点 $v$ を取り出したら、$v$ の隣接頂点に印を付けてから未訪問リストを 1 周し、印のない頂点（補グラフで $v$ と隣接）を全部取り出してキューに入れる。1 周で取り出さなかった頂点は $v$ の隣接頂点なので、1 周のコストは $\deg(v) + (\text{取り出した数})$ で抑えられ、全体 $O(n + m)$。

## 使い方

```cpp
vector<pair<int, int>> edges;   // 元のグラフ (単純)
auto groups = complement_graph_components(n, edges);   // 補グラフの連結成分ごとの頂点
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<vector<int>> complement_graph_components(n, edges)` | 補グラフの連結成分 | $O(n + m)$ |
