---
title: 閉路検出 (Cycle Detection)
documentation_of: //graph/cycle_detection.hpp
---

## 概要

グラフの閉路を 1 つ見つける。非再帰の DFS で $O(n + m)$。

- 有向：DFS 中に「探索中（スタックにある）頂点」への辺を見つけたら、それが閉路を作る。
- 無向：DFS 木の親への辺（**辺番号** で区別するので多重辺も正しく扱う）以外で、訪問済みの祖先への辺（後退辺）を見つけたら閉路。自己ループも閉路。

## 使い方

```cpp
vector<pair<int, int>> edges;                       // 辺 i = (u, v)
vector<int> cyc = find_cycle_directed(n, edges);    // 辺番号の列 (この順にたどると閉路)．なければ空
auto [vs, es] = find_cycle_undirected(n, edges);    // 頂点の列と辺番号の列 (es[i] は vs[i] と vs[i+1] を結ぶ)．なければ空
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<int> find_cycle_directed(int n, edges)` | 有向グラフの閉路 | $O(n + m)$ |
| `pair<vector<int>, vector<int>> find_cycle_undirected(int n, edges)` | 無向グラフの閉路（頂点も辺も重複しない） | $O(n + m)$ |
