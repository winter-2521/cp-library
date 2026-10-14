---
title: 長方形加算の後の長方形和 (Static Rectangle Add Rectangle Sum)
documentation_of: //data_structure/static_rectangle_add_rectangle_sum.hpp
---

## 概要

先に長方形加算（$[l, r) \times [d, u)$ の全マスに $w$）をまとめて行い、その後で長方形和を答える。加算の後のクエリはオンライン。

長方形加算を 4 隅の点 $(p, q, c)$（$c = \pm w$）に直すと、左下の累積和は

$$S(X, Y) = \sum_{x < X,\ y < Y} A_{xy} = \sum_{p < X,\ q < Y} c\,(X - p)(Y - q) = XY \sum c - X \sum cq - Y \sum cp + \sum cpq$$

なので、重み $(c, cp, cq, cpq)$ の組についての長方形和（[StaticRectangleSum](static_rectangle_sum.hpp)）1 回で $S(X, Y)$ が求まる。長方形和は $S$ の 4 回の包除。

## 使い方

```cpp
StaticRectangleAddRectangleSum<int, mint> rs;
rs.add(l, d, r, u, w);    // 先に全部の加算
rs.build();               // (省略すると最初の sum で build する)
rs.sum(l, d, r, u);       // [l, r) × [d, u) の和
rs.prefix(x, y);          // x' < x, y' < y の和
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `void add(X l, X d, X r, X u, T w)` | 長方形加算（`build` 前） | $O(1)$ |
| `void build()` | 構築 | $O(n \log n)$ |
| `T sum(X l, X d, X r, X u)` | 長方形和 | $O(\log n)$ |

## 注意

- `T` は座標の積を計算する型（modint など）。座標を `T` に変換して掛けるので、`long long` だと座標 $10^9$ で $XY \sum c$ があふれる。
- メモリは 4 隅の点 $4n$ 個 × $\log$ 段 × 重み 4 つ分（$n = 2 \times 10^5$ で約 300 MB）。
- 加算と和が交互に来るなら、オフラインで分割統治するか、遅延セグ木を使う別の方法が要る。
