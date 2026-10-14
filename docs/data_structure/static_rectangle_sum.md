---
title: 長方形の中の点の重みの和 (Rectangle Sum)
documentation_of: //data_structure/static_rectangle_sum.hpp
---

## 概要

平面上の重み付きの点について、「$l \le x < r$ かつ $d \le y < u$ の点の重みの和」を答える（**オンライン**）。

- `StaticRectangleSum<X, W>`：点が固定。点を $x$ でソートし、$y$（座標圧縮）の列を **重み付きウェーブレット行列**（各段で振り分けた後の列の重みの累積和を持つ）で持つ。クエリ $O(\log n)$。
- `DynamicRectangleSum<X, W>`：点の **追加** ができる。大きさが 2 冪の `StaticRectangleSum` を高々 $\log n$ 個持ち、追加のたびに同じ大きさのものを併合して作り直す（二進カウンタ。各点が作り直しに巻き込まれるのは $O(\log n)$ 回）。

## 使い方

```cpp
StaticRectangleSum<int, long long> rs(x, y, w);   // vector<int> x, y, vector<long long> w
rs.sum_rect(l, d, r, u);                          // l <= x < r, d <= y < u の重みの和 (rs(l, d, r, u) でも可)

DynamicRectangleSum<int, long long> ds(x, y, w);  // 初期の点 (空でもよい: DynamicRectangleSum<int, long long> ds;)
ds.add(px, py, pw);                               // 点を追加 (同じ座標に複数あってよい)
ds.sum_rect(l, d, r, u);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `StaticRectangleSum<X, W>(x, y, w)` | 構築 | $O(n \log n)$ |
| `W sum_rect(X l, X d, X r, X u)` | 長方形の重みの和 | $O(\log n)$ |
| `DynamicRectangleSum<X, W>(x, y, w)` | 構築 | $O(n \log n)$ |
| `void add(X x, X y, W w)` | 点を追加 | ならし $O(\log^2 n)$ |
| `W sum_rect(X l, X d, X r, X u)`（動的版） | 長方形の重みの和 | $O(\log^2 n)$ |

## 注意

- 重みは足し算と引き算ができる型（`long long`、modint など）。点の重みを後から変える（一点加算）には、同じ座標に差分の重みの点を `add` すればよい。
- メモリは $n \log n$ 個の `W`（累積和）。
