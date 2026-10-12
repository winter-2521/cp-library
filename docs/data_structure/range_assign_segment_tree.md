---
title: 区間代入セグメント木 (Range Assign Segment Tree)
documentation_of: //data_structure/range_assign_segment_tree.hpp
---

## 概要

**任意のモノイド**（非可換でもよい）に対して、区間代入・一点代入・区間積を処理する。遅延セグメント木と違い、作用付きモノイドを作る必要がない。

値が等しい連続部分（ラン）ごとにまとめて持つ（いわゆる「区間をsetで管理する」テク / ODT）。

- ランの先頭位置を [FastSet](fast_set.hpp) で管理する。
- セグメント木の「ランの先頭の位置」にそのランの積 $x^{\text{長さ}}$ を、それ以外の位置に `e()` を置く。
- 区間代入は境界でランを切り、内側のランを全て消して 1 つのランにする。1 回の代入で作るランは高々 3 個なので、消えるランの総数も $O(n + q)$。
- 区間積は両端の端数のランを $x^k$ で計算し、間はセグメント木で求める。

## 使い方

```cpp
RangeAssignSegmentTree<MonoidAffine<mint>> seg(f);   // vector<Affine<mint>> f
RangeAssignSegmentTree<MonoidSum<long long>> seg2(n, 0);  // 長さ n，全て 0
seg.assign(l, r, {c, d});   // [l, r) を全て x に
seg.prod(l, r)(x);          // op(a[l], ..., a[r-1])
seg.set(i, x); seg.get(i); seg.all_prod();
seg.enumerate_runs([](int l, int r, S x) { ... });   // ランを左から列挙
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `RangeAssignSegmentTree<M>(const vector<S> &a)` | 配列から構築 | $O(n)$ |
| `RangeAssignSegmentTree<M>(int n, S x)` | 長さ `n`、全て `x` | $O(n)$ |
| `void assign(int l, int r, S x)` | $[l, r)$ を全て $x$ に | ならし $O(\log n)$ + $O(\log n)$ 回の `op` |
| `void set(int i, S x)` / `S get(int i)` | 一点代入・取得 | 同上 / $O(\log_{64} n)$ |
| `S prod(int l, int r)` | 区間積 | $O(\log n)$ 回の `op` |
| `S all_prod()` | 全体の積 | $O(1)$ |
| `void enumerate_runs(Fn f)` | ランを左から列挙 | $O(\text{ラン数} \cdot \log_{64} n)$ |

## 注意

- $x^k$ を繰り返し二乗法で計算するので、`op` を $O(\log n)$ 回呼ぶ。
