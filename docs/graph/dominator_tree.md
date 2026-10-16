---
title: 支配木 (Dominator Tree)
documentation_of: //graph/dominator_tree.hpp
---

## 概要

有向グラフと始点 $s$ について、$s$ から $v$ へのどの道も必ず通る頂点を $v$ の **支配点** と呼ぶ。$v$ に最も近い支配点 $\mathrm{idom}(v)$（直接支配点）を親とすると木になる（支配木）。Semi-NCA 法で $O(m \log n)$（実用上ほぼ線形）。

1. $s$ から DFS して先行順の番号を振る。
2. 先行順の逆順に **半支配点** $\mathrm{sdom}(w)$ を求める（処理済みの頂点を DFS 木の親につなぐ Union-Find で、経路上の最小の sdom を覚える）。
3. $\mathrm{idom}(w)$ は、DFS 木の親から始めて番号が $\mathrm{sdom}(w)$ 以下になるまで idom をたどったもの。

DFS も経路圧縮も非再帰。

## 使い方

```cpp
vector<pair<int, int>> edges;              // 有向辺 (from, to)
vector<int> par = dominator_tree(n, edges, s);
// par[v] = idom(v)，par[s] = s，s から到達できない頂点は -1
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<int> dominator_tree(int n, edges, int s)` | 各頂点の直接支配点 | $O(m \log n)$ |

## 注意

- 多重辺・自己ループがあってもよい。
- 3. の手順は最悪 $O(n^2)$ になりうるが、実際のケースではほぼ線形で Lengauer-Tarjan 法より速い。
