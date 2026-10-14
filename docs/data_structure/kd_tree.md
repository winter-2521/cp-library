---
title: k-d 木 (長方形作用・長方形積)
documentation_of: //data_structure/kd_tree.hpp
---

## 概要

2 次元平面上の値付きの点に対して、**長方形の中の点への作用**・**長方形の中の点の積**・一点更新を $O(\sqrt n)$ で処理する。値と作用は遅延セグメント木と同じ作用付きモノイド（[acted_monoid.hpp](../../algebra/acted_monoid.hpp)）。

- `KDTree<X, AM>`：点が固定。点を「x の中央値で 2 分割 → 各半分を y の中央値で 2 分割 → …」と **軸を交互に** 分けた木で、各ノードが点の外接長方形・積・遅延作用を持つ。クエリでは、外接長方形がクエリの長方形に含まれるノードはそのまま使い、交わらないノードは無視し、それ以外は子に降りる。
- `DynamicKDTree<X, AM>`：点の **追加** もできる（オンライン）。大きさが 2 冪の `KDTree` を高々 $\log n$ 個持ち、追加のたびに同じ大きさのものを併合して作り直す（二進カウンタ）。

## 使い方

```cpp
using AM = ActedAffineSum<mint>;
vector<int> x(n), y(n);
vector<AM::S> w(n);                       // w[i] = AM::make(重み)
KDTree<int, AM> kd(x, y, w);
kd.prod(l, d, r, u).sum;                  // l <= x < r, d <= y < u の点の積
kd.apply(l, d, r, u, {a, b});             // 同じ範囲の点に作用
kd.get(i); kd.set(i, AM::make(v));        // 点 i (構築時の番号)
kd.all_prod(); kd.values();

DynamicKDTree<int, AM> dk(x, y, w);       // 空でもよい: DynamicKDTree<int, AM> dk;
int id = dk.add_point(px, py, AM::make(v));  // 追加した点の番号 (0, 1, 2, ... の順)
dk.prod(l, d, r, u); dk.apply(l, d, r, u, f); dk.get(id); dk.set(id, s);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `KDTree<X, AM>(xs, ys, vals)` | 構築 | $O(n \log n)$ |
| `S prod(X l, X d, X r, X u)` | 長方形 $[l, r) \times [d, u)$ の点の積 | $O(\sqrt n)$ |
| `void apply(X l, X d, X r, X u, F f)` | 長方形の点に作用 | $O(\sqrt n)$ |
| `S get(int i)` / `void set(int i, S x)` | 一点取得 / 更新 | $O(\log n)$ |
| `vector<S> values()` | 全点の値 | $O(n)$ |
| `int add_point(X x, X y, S v)`（動的版） | 点の追加 | ならし $O(\log^2 n)$ |
| `prod` / `apply`（動的版） | | $O(\sqrt n)$ |

## 注意

- 積は **可換** であること（点の並び順は決まっていない）。
- 分割の軸は深さで交互にする。「広がりの大きい軸で分ける」と、$y$ が数種類しかない入力で $y$ の細い帯のクエリが $O(n)$ になる（Library Checker の hack ケースで 100 秒以上かかった）。
