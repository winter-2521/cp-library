---
title: 木の距離の度数表
documentation_of: //tree/frequency_table_of_tree_distance.hpp
---

## 概要

木の全ての頂点の組 $\{u, v\}$ について距離（辺の本数）を数え、`res[d]` = 距離 $d$ の組の個数を求める。

重心分解をし、重心 $c$ を通る組を数えてから $c$ を取り除いて再帰する。$c$ を通る組は「別々の子の部分木（または $c$ 自身）から 1 つずつ」選んだもので、子を深さの浅い順に見て「それまでの深さの度数」と「今の子の深さの度数」を畳み込む。各段の畳み込みの長さの合計は $O(n)$ なので $O(n \log^2 n)$。

組の数は $10^{10}$ を超えうるので、2 つの素数の NTT と中国剰余定理で正確に求める（`convolve_small`）。

## 使い方

```cpp
vector<pair<int, int>> edges;                                  // n-1 本
vector<long long> res = frequency_table_of_tree_distance(n, edges);   // res[0..n-1]
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<long long> frequency_table_of_tree_distance(int n, edges)` | 距離ごとの組の個数 | $O(n \log^2 n)$ |
