---
title: 最小有向全域木 (Directed MST)
documentation_of: //graph/directed_mst.hpp
---

## 概要

有向グラフと根 $r$ について、$r$ から全頂点へ到達できる有向木（全域アーボレセンス）のうち辺の重みの和が最小のものを求める。$O(m \log n)$。

Chu-Liu/Edmonds 法：各頂点に入る最小の辺を選び、閉路ができたら縮約して「その閉路に入る辺の重みから、閉路内で選んだ辺の重みを引く」。素朴には $O(nm)$ だが、各頂点に入る辺を**遅延加算つき skew heap** に入れ、縮約をヒープの併合と Union-Find で表すと $O(m \log n)$ になる。最後に縮約を新しい順にほどいて親を復元する。

## 使い方

```cpp
vector<tuple<int, int, long long>> edges;   // (from, to, 重み)
auto [w, par] = directed_mst(n, edges, r);  // par[v] = v の親, par[r] = r
if (par.empty()) { /* 到達できない頂点がある */ }
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `pair<T, vector<int>> directed_mst(int n, edges, int r)` | 重みの和と親の配列 | $O(m \log n)$ |

## 注意

- 根から到達できない頂点があると `{-1, {}}` を返す（`par` が空かどうかで判定する）。
- 負の重みがあってもよい。
