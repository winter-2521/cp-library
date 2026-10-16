---
title: 最小全域木 (Kruskal)
documentation_of: //graph/minimum_spanning_tree.hpp
---

## 概要

無向グラフの最小全域木（非連結なら最小全域森）を Kruskal 法で求める。$O(m \log m)$。

辺を重みの昇順に見て、両端がまだつながっていなければ採用する（Union-Find で判定）。

## 使い方

```cpp
vector<tuple<int, int, long long>> edges;   // (u, v, 重み)
auto [w, used] = minimum_spanning_tree(n, edges);   // 重みの和, 採用した辺の番号
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `pair<T, vector<int>> minimum_spanning_tree(int n, edges)` | 重みの和と採用した辺の番号の列 | $O(m \log m)$ |

## 注意

- 非連結なら最小全域森（採用辺は $n - (\text{連結成分数})$ 本）を返す。連結か確かめたいときは `used.size() == n - 1` を見る。
- 重みが同じ辺は番号が小さい方を優先する。
