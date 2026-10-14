---
title: 長方形加算・一点取得 (Rectangle Add Point Get)
documentation_of: //data_structure/rectangle_add_point_get.hpp
---

## 概要

平面に「長方形 $[l, r) \times [d, u)$ の全ての点に $w$ を足す」と「点 $(x, y)$ の値」を処理する（**オンライン**）。

長方形への加算を **4 隅に $\pm w$ の点を置く**（2 次元の差分：$(l, d)$ に $+w$、$(l, u)$ と $(r, d)$ に $-w$、$(r, u)$ に $+w$）ことに直すと、点 $(x, y)$ の値は「$x' \le x$ かつ $y' \le y$ の点の重みの和」になる。これを点の追加ができる長方形和 [DynamicRectangleSum](static_rectangle_sum.hpp) で求める。

## 使い方

```cpp
RectangleAddPointGet<int, long long> rp(l, d, r, u, w);   // 初期の長方形 (vector)．空でもよい
rp.add(l, d, r, u, w);    // [l, r) × [d, u) に w を足す
rp.get(x, y);             // 点 (x, y) の値
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `RectangleAddPointGet<X, W>(l, d, r, u, w)` | 構築 | $O(n \log n)$ |
| `void add(X l, X d, X r, X u, W w)` | 長方形加算 | ならし $O(\log^2 n)$ |
| `W get(X x, X y)` | 一点取得 | $O(\log^2 n)$ |

## 注意

- `W` は足し算・引き算ができる型。`get` では `numeric_limits<X>::lowest()` を左下の端として使い、`x + 1`, `y + 1` を計算するので、座標は `X` の最大値未満であること。
