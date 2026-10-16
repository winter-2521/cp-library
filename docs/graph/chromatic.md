---
title: 彩色数・彩色多項式
documentation_of: //graph/chromatic.hpp
---

## 概要

$n \le 20$ 程度の無向グラフの **彩色数**（隣接頂点が違う色になる塗り分けの最小色数）と **彩色多項式** $P(x)$（$x$ 色での塗り分けの数）を求める。

- **彩色数**：$I(S)$ = 「$S$ に含まれる独立集合（空集合も含む）の個数」とすると、$c(k) = \sum_{S} (-1)^{n-|S|} I(S)^k$ は「和集合が全体になる $k$ 個の独立集合の組」の数（包除原理）で、$c(k) > 0$ ⇔ $k$ 色で塗れる。$k = 1, 2, \dots$ と調べる。$O(2^n \chi)$。
- **彩色多項式**：$a_m$ = 「頂点全体を $m$ 個の独立集合に分ける方法の数」とすると $P(x) = \sum_m a_m\, x(x-1)\cdots(x-m+1)$。$a_m = (s^m/m!)(V)$（$s$ は空でない独立集合の指示関数、積は部分集合畳み込み）を、「最大の要素を含むブロックを 1 つずつ外す」転置した部分集合畳み込み（power projection）で $m$ についてまとめて求める。$O(n^2 2^n)$。

## 使い方

```cpp
vector<pair<int, int>> edges;
int chi = chromatic_number(n, edges);                          // 自己ループがあれば -1
vector<mint> p = chromatic_polynomial<mint>(n, edges);         // p[0..n]
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `int chromatic_number(int n, edges)` | 彩色数 | $O(2^n \chi)$ |
| `vector<mint> chromatic_polynomial<mint>(int n, edges)` | 彩色多項式の係数 | $O(n^2 2^n)$ |

## 注意

- 彩色数は $2^{61} - 1$ を法として 0 かどうかを判定している（偶然 0 になる確率は無視できる）。
- 多重辺はあってもよい。自己ループがあると塗れない（彩色多項式は 0）。
