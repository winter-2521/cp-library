---
title: クリークの列挙
documentation_of: //graph/enumerate_cliques.hpp
---

## 概要

単純無向グラフの全ての（空でない）クリークを列挙する。

辺を (次数, 番号) の小さい方から大きい方へ向けると、各頂点から出る辺は $\sqrt{2m}$ 本以下になる。クリークの中で（向きで）最小の頂点 $v$ を決めると残りは $v$ から出る先の中のクリークなので、その中の隣接を bit で持って全てたどる。各クリークはちょうど 1 回見つかり、全体 $O(2^{\sqrt{2m}} n)$ 程度。

## 使い方

```cpp
vector<pair<int, int>> edges;
enumerate_cliques(n, edges, [&](const vector<int> &c) { ... });   // c: クリークの頂点
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `void enumerate_cliques(int n, edges, F f)` | 全てのクリークで `f(c)` を呼ぶ | $O(2^{\sqrt{2m}} n)$ |

## 注意

- 単純グラフであること。各頂点から出る辺は 63 本以下を仮定（$m \le 1900$ 程度なら必ず満たす）。
