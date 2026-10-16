---
title: スター付きグラフの最小カット (動的)
documentation_of: //graph/star_augmented_min_cut.hpp
---

## 概要

重み付き無向グラフ $G$（$n$ 頂点）に新しい頂点 $N$ と辺 $\{i, N\}$（重み $a_i$）を足したグラフ $H$ の最小カットを、$a_i$ を書き換えながら求める。

$H$ のカットは「$N$ を含まない側 $X \subseteq V$（空でない）」で表せ、重さは $d_G(X) + a(X)$。

1. 最小にする $X$ は **極端集合**（真部分集合 $Y$ が全て $d(Y) > d(X)$ を満たす $X$）から選んでよい。極端集合は層状（交わるなら包含関係）なので、それらを全て含む層状の族を木（$2n - 1$ ノード）で持つ。
2. 木は **最小次数順序**（未訪問の頂点のうち「未訪問への辺の重みの和」が最小のものを順に選ぶ）の最後の 2 頂点を縮約することを繰り返して作る（Nagamochi）。縮約で順序の先頭部分は変わらないので、崩れた位置からだけ計算し直す。
3. 各ノード $X$ に $d_G(X) + a(X)$ を持たせる。$a_i$ の変更は「葉 $i$ から根までの道に加算」、答えは全体の最小値。重軽分解 + 区間加算・全体最小のセグメント木。

## 使い方

```cpp
vector<tuple<int, int, long long>> edges;   // G の辺 (u, v, 重み)
vector<long long> a(n);                     // 辺 {i, N} の重み
StarAugmentedMinCut mc(n, edges, a);
mc.set(x, y);                               // a_x = y
long long c = mc.min_cut();                 // H の最小カット
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `StarAugmentedMinCut(int n, edges, a)` | 構築 | $O(n(n + m)\log n)$ |
| `void set(int x, ll y)` | $a_x$ を $y$ にする | $O(\log^2 n)$ |
| `ll min_cut()` | 今の最小カット | $O(1)$ |

## 注意

- 重みは非負。
- 「$N$ だけを切り離す」カット（$X = V$、値 $\sum a_i$）も候補に入っている。
