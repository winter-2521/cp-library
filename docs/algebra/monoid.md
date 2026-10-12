---
title: モノイド (Monoid)
documentation_of: //algebra/monoid.hpp
---

## 概要

セグメント木などに渡すモノイドの定義と、よく使うモノイド。1 次関数 `Affine<T>` もここにある。

モノイドは次の形の構造体で表す（ACL の `segtree` のテンプレート引数を 1 つの構造体にまとめた形）。

```cpp
struct M {
    using S = 値の型;
    static S op(const S &a, const S &b);  // 結合的．a が左 (先)，b が右 (後)
    static S e();                         // 単位元
};
```

## 用意しているもの

| 名前 | `S` | `op(a, b)` | `e()` |
| --- | --- | --- | --- |
| `MonoidSum<T>` | `T` | $a + b$ | $0$ |
| `MonoidMin<T>` | `T` | $\min(a, b)$ | `numeric_limits<T>::max()` |
| `MonoidMax<T>` | `T` | $\max(a, b)$ | `numeric_limits<T>::lowest()` |
| `MonoidXor<T>` | `T` | $a \oplus b$ | $0$ |
| `MonoidAffine<T>` | `Affine<T>` | 「先に $a$、次に $b$」 $= b(a(x))$ | $x \mapsto x$ |

```cpp
Affine<mint> f(a, b);   // f(x) = a x + b
f(x); f.eval(x);        // 値
f.then(g);              // 先に f，次に g: g(f(x))
f == g;

monoid_pow<M>(x, k);    // op(x, x, ..., x) (k 個)．O(log k) 回の op
```

`MonoidAffine` を `SegmentTree` に乗せると、`prod(l, r)` は $f_{r-1}(\cdots f_l(x))$ を表す関数になる（Library Checker の Point Set Range Composite と同じ向き）。

## 注意

- `MonoidMin` / `MonoidMax` は `numeric_limits` を使うので算術型のみ。
- 自作するときは `op` が結合的で `e()` が単位元であることを確かめること。
