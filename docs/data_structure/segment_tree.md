---
title: セグメント木 (Segment Tree)
documentation_of: //data_structure/segment_tree.hpp
---

## 概要

モノイド `M` の列に対して、一点更新と区間積を $O(\log n)$ で処理する。非可換なモノイドでもよい。
大きさを 2 冪に切り上げた完全二分木を 1 本の配列で持つ、非再帰の実装。ACL の `segtree` と同じ操作に加えて `multiply` がある。

## 使い方

```cpp
SegmentTree<MonoidSum<long long>> seg(n);   // 全て e()
SegmentTree<MonoidAffine<mint>> seg2(f);   // vector<Affine<mint>> f から構築
seg.set(p, x);        // a[p] = x
seg.multiply(p, x);   // a[p] = op(a[p], x)
seg.get(p);           // a[p] (seg[p] でも可)
seg.prod(l, r);       // op(a[l], ..., a[r-1])
seg.all_prod();
seg.max_right(l, [](S x) { return 条件; });  // 条件を満たす最大の r
seg.min_left(r, [](S x) { return 条件; });   // 条件を満たす最小の l
seg2.prod(l, r)(x);   // f_{r-1}(...f_l(x))
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `SegmentTree<M>(int n)` / `SegmentTree<M>(const vector<S> &a)` | 構築 | $O(n)$ |
| `void set(int p, S x)` | $a_p = x$ | $O(\log n)$ |
| `void multiply(int p, S x)` | $a_p = a_p \cdot x$ | $O(\log n)$ |
| `S get(int p)` / `operator[]` | $a_p$ | $O(1)$ |
| `S prod(int l, int r)` | $a_l \cdots a_{r-1}$（空なら `e()`） | $O(\log n)$ |
| `S all_prod()` | 全体の積 | $O(1)$ |
| `int max_right(int l, G g)` | `g(prod(l, r))` が真となる最大の $r$ | $O(\log n)$ |
| `int min_left(int r, G g)` | `g(prod(l, r))` が真となる最小の $l$ | $O(\log n)$ |

## 注意

- `max_right` / `min_left` の `g` は単調（短い区間で真なら長い区間で偽になりうるが、その逆はない）で、`g(e())` が真であること。
- モノイドの書き方は [monoid.hpp](../../algebra/monoid.hpp) を参照。
