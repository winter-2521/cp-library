---
title: 作用付きモノイド (Acted Monoid)
documentation_of: //algebra/acted_monoid.hpp
---

## 概要

遅延セグメント木などに渡す「作用付きモノイド」の定義と、よく使うもの。規約は ACL の `lazy_segtree` と同じ。

```cpp
struct AM {
    using S = 値の型;  static S op(S a, S b);  static S e();
    using F = 作用の型;
    static S mapping(F f, S x);          // f を x に作用させる
    static F composition(F f, F g);      // 先に g，次に f (f ∘ g)
    static F id();                       // 恒等写像
};
```

`mapping(f, op(a, b)) = op(mapping(f, a), mapping(f, b))`（作用が積と可換）であること。

## 用意しているもの

| 名前 | 値 `S` | 作用 `F` | 用途 |
| --- | --- | --- | --- |
| `ActedAffineSum<T>` | `{sum, len}` | `Affine<T>` | 区間 1 次関数・区間和 |
| `ActedAddSum<T>` | `{sum, len}` | `T` | 区間加算・区間和 |
| `ActedAddMin<T>` | `T` | `T` | 区間加算・区間最小値 |
| `ActedAddMax<T>` | `T` | `T` | 区間加算・区間最大値 |
| `ActedAssignSum<T>` | `{sum, len}` | `AssignAction<T>` | 区間代入・区間和 |
| `ActedAssignMin<T>` | `T` | `AssignAction<T>` | 区間代入・区間最小値 |
| `ActedAssignMax<T>` | `T` | `AssignAction<T>` | 区間代入・区間最大値 |

```cpp
using AM = ActedAffineSum<mint>;
vector<AM::S> a(n);
for (int i = 0; i < n; i++) a[i] = AM::make(x[i]);   // 和を持つものは make(x) = {x, 1} で作る
LazySegmentTree<AM> seg(a);
seg.apply(l, r, {b, c});          // Affine<mint>(b, c)
seg.prod(l, r).sum;

LazySegmentTree<ActedAssignMin<int>> seg2(v);
seg2.apply(l, r, 5);              // AssignAction<int>(5): 区間を 5 にする
```

## 注意

- 和を持つものは要素数 `len` を一緒に持つ（作用に長さが必要なため）。初期値は `make(x)` で作ること（`{x, 0}` にすると加算が反映されない）。
- `ActedAddMin` / `ActedAddMax` は単位元（空区間）には作用させない。
