---
title: 区間 1 次関数加算・区間最小値 (Range Linear Add Range Min)
documentation_of: //data_structure/linear_add_min_segment_tree.hpp
---

## 概要

整数列 $a$ に対して、

- 区間 $[l, r)$ の各 $i$ に $b i + c$ を足す（**位置によって足す量が違う**）
- 区間 $[l, r)$ の最小値（最大値）

を処理する。普通の遅延セグメント木では、「区間の最小値」に $b i + c$ を足した結果が分からない（どの位置が最小になるかが変わる）ので扱えない。

点 $(i, a_i)$ を平面上に置くと、区間の最小値を取りうるのは点の **下側凸包** の頂点だけ。しかも 1 次関数 $b i + c$ を全点に足しても凸包の形は変わらない（どの点が頂点かは同じ）。そこで各ノードに「左の子の凸包と右の子の凸包をつなぐ橋（共通接線の 2 端点）」だけを持つ。

- 最小値：ノードの橋の傾きが負なら最小値は右の子側、そうでなければ左の子側にあるので、根から 1 本降りれば $O(\log n)$。
- 1 次関数の加算：橋の端点の値と遅延に足すだけ。
- 橋の再計算：左右の子の凸包を同時に降りる（Overmars–van Leeuwen）。左の凸包の辺と右の凸包の辺を延長した 2 直線を、左右の境界 $x = m - 1/2$ で比べると、どちらかの半分を捨てられるので $O(\log n)$。

## 使い方

```cpp
LinearAddMinSegmentTree<long long> seg(a);         // vector<long long> a
LinearAddMinSegmentTree<long long, true> segmax(a); // 区間最大値
seg.add(l, r, b, c);     // i in [l, r) について a[i] += b * i + c
seg.min(l, r);           // min(a[l], ..., a[r-1])  (最大値版は seg.max(l, r) でも可)
seg.all_min();
seg.get(i); seg.set(i, x);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `LinearAddMinSegmentTree<T = long long, MAX = false>(const vector<T> &a)` | 構築 | $O(n \log n)$ |
| `void add(int l, int r, T b, T c)` | $a_i \mathrel{+}= b i + c$ | $O(\log^2 n)$ |
| `T min(int l, int r)` / `T max(int l, int r)` | 区間最小値（最大値版では最大値） | $O(\log^2 n)$ |
| `T all_min()` | 全体の最小値 | $O(\log n)$ |
| `T get(int i)` / `void set(int i, T x)` | 一点取得 / 更新 | $O(\log n)$ / $O(\log^2 n)$ |

## 注意

- 足す量の $i$ は **0-indexed の位置そのもの**（区間の左端からの距離ではない）。左端からの距離で足したいときは $c$ を $c - b l$ にする。
- `min(l, r)` は $l < r$ で呼ぶこと。
- 値は `T`（符号付き整数）に収まること。橋の比較は `__int128` で行う（値 $\times$ 長さ$^2$ 程度まで使う）。
