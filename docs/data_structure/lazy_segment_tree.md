---
title: 遅延セグメント木 (Lazy Segment Tree)
documentation_of: //data_structure/lazy_segment_tree.hpp
---

## 概要

作用付きモノイド `AM` に対して、区間作用と区間積を $O(\log n)$ で処理する。非再帰の実装で、操作と規約は ACL の `lazy_segtree` と同じ。
よく使う作用付きモノイドは [acted_monoid.hpp](../../algebra/acted_monoid.hpp) にある。

## 使い方

```cpp
using AM = ActedAffineSum<mint>;    // 区間 1 次関数・区間和
vector<AM::S> a(n);
for (int i = 0; i < n; i++) a[i] = AM::make(x[i]);
LazySegmentTree<AM> seg(a);
seg.apply(l, r, {b, c});   // [l, r) の各要素を b x + c に
seg.prod(l, r).sum;        // [l, r) の和
seg.apply(p, f); seg.set(p, x); seg.get(p); seg.all_prod();
seg.max_right(l, g); seg.min_left(r, g);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `LazySegmentTree<AM>(int n)` / `(const vector<S> &a)` | 構築 | $O(n)$ |
| `void apply(int l, int r, F f)` | $i \in [l, r)$ について $a_i = f(a_i)$ | $O(\log n)$ |
| `void apply(int p, F f)` | $a_p = f(a_p)$ | $O(\log n)$ |
| `S prod(int l, int r)` | $a_l \cdots a_{r-1}$ | $O(\log n)$ |
| `S all_prod()` | 全体の積 | $O(1)$ |
| `void set(int p, S x)` / `S get(int p)` | 一点代入・取得 | $O(\log n)$ |
| `int max_right(int l, G g)` / `int min_left(int r, G g)` | 二分探索 | $O(\log n)$ |

## 注意

- `prod` / `get` も内部で作用を下ろすので `const` ではない。
- `max_right` / `min_left` の条件は単調で、`g(e())` が真であること。
