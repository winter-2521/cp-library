---
title: 割当問題 (Hungarian 法)
documentation_of: //graph/hungarian.hpp
---

## 概要

$n \times m$（$n \le m$）の行列 $a$ について、各行に相異なる列を 1 つずつ割り当て、$\sum_i a_{i, p_i}$ を最小にする。$O(n^2 m)$。

行を 1 つずつ追加していく。行・列のポテンシャル（双対変数）$u, v$ を「$a_{ij} - u_i - v_j \ge 0$」が保たれるように持ち、被約費用 $a_{ij} - u_i - v_j$ で Dijkstra 風に最短の増加路を見つけて割当を 1 つ増やす。

## 使い方

```cpp
vector<vector<long long>> a(n, vector<long long>(m));
auto [cost, p] = hungarian(a);   // p[i] = 行 i に割り当てた列
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `pair<T, vector<int>> hungarian(const vector<vector<T>> &a)` | 最小値と割当 | $O(n^2 m)$ |

## 注意

- 最大化したいときは符号を反転して渡す。
- 負の値があってもよい。
- $n > m$ のときは転置してから渡す。
