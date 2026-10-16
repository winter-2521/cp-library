---
title: st 番号付け (st-Numbering)
documentation_of: //graph/st_numbering.hpp
---

## 概要

無向グラフの頂点 $s, t$ について、$s$ が最小・$t$ が最大で、それ以外の全ての頂点が「自分より番号が小さい隣接頂点」と「大きい隣接頂点」を両方持つような番号付け（st 番号付け）を求める。$O(n + m)$。

- 存在条件（$n \ge 3$）：辺 $(s, t)$ を足したグラフが二重頂点連結であること。

$s$ を根、$t$ を最初の子とする DFS で lowlink を求め、先行順に各頂点 $v$ を連結リスト中の「親の直前」か「親の直後」に挿入する（$\mathrm{low}[v]$ の頂点が親より前にあるか後ろにあるかで決める。Tarjan の方法）。最後にリストの順に番号を振る。DFS は非再帰。

## 使い方

```cpp
vector<pair<int, int>> edges;
vector<int> num = st_numbering(n, edges, s, t);   // num[v] ∈ [0, n)
if (num.empty()) { /* 存在しない */ }
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<int> st_numbering(int n, edges, int s, int t)` | 各頂点の番号．なければ空 | $O(n + m)$ |

## 注意

- $n \ge 2$ では $s \ne t$ を仮定する（$n = 1$ なら `{0}`）。$n = 2$ では辺 $s$-$t$ があるときだけ存在する。
- 多重辺・自己ループがあってもよい。
