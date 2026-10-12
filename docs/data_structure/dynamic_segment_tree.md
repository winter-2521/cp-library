---
title: 動的セグメント木 (Dynamic Segment Tree)
documentation_of: //data_structure/dynamic_segment_tree.hpp
---

## 概要

添字の範囲が大きい（$n \le 10^{18}$ 程度）場合の一点更新・区間積。はじめ全て `e()`。**オンライン** で動く（座標圧縮のための先読みが不要）。

各ノードが「担当区間の中の 1 要素（位置と値）」と部分木の積を持ち、左の子の部分木の位置 $<$ ノードの位置 $<$ 右の子の部分木の位置 という順序を保つ。
こうするとノード数は値を設定した位置の個数と同じになり、メモリは $O(\text{更新回数})$ で済む（素朴な動的セグメント木は 1 回の更新で $\log n$ 個のノードを作る）。

## 使い方

```cpp
DynamicSegmentTree<MonoidAffine<mint>> seg(1000000000);
seg.reserve(q);          // 任意．更新回数の見込み
seg.set(p, {c, d});      // a[p] = x
seg.prod(l, r)(x);       // op(a[l], ..., a[r-1])
seg.get(p); seg.all_prod();
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `DynamicSegmentTree<M>(long long n)` | 長さ `n`、全て `e()` | $O(1)$ |
| `void set(long long p, S x)` | $a_p = x$ | $O(\log n)$ |
| `S get(long long p)` | $a_p$ | $O(\log n)$ |
| `S prod(long long l, long long r)` | $a_l \cdots a_{r-1}$ | $O(\log n)$ |
| `S all_prod()` | 全体の積 | $O(1)$ |

## 注意

- 非可換なモノイドでもよい。
- 区間作用が必要なら [DynamicLazySegmentTree](dynamic_lazy_segment_tree.hpp) を使う。
