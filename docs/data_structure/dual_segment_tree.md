---
title: 双対セグメント木 (Dual Segment Tree)
documentation_of: //data_structure/dual_segment_tree.hpp
---

## 概要

区間への作用と一点取得を $O(\log n)$ で処理する。各位置 $i$ に作用 $F_i$（はじめ単位元）を持ち、`apply(l, r, f)` で $[l, r)$ の各 $F_i$ を $\mathrm{op}(F_i, f)$ に更新する。
`op(x, y)` は **時系列順**（先に $x$、次に $y$）の合成。非可換でもよい（範囲作用の前に境界の祖先の作用を下ろしている）。

遅延セグメント木と違って区間積は求められないが、そのぶん速くて軽い。

## 使い方

```cpp
// 区間 1 次関数作用・一点取得 (range_affine_point_get)
DualSegmentTree<MonoidAffine<mint>> seg(n);
seg.apply(l, r, {b, c});    // [l, r) に x -> b x + c を作用
seg.get(i)(a[i]);           // 位置 i の作用の合成を初期値 a[i] に適用 = 現在の値

// 区間加算・一点取得
DualSegmentTree<MonoidSum<long long>> add(n);
add.apply(l, r, x);
a[i] + add.get(i);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `DualSegmentTree<M>(int n)` | 全て `e()` で構築 | $O(n)$ |
| `void apply(int l, int r, S f)` | $i \in [l, r)$ について $F_i = \mathrm{op}(F_i, f)$ | $O(\log n)$ |
| `void apply(int p, S f)` | $F_p = \mathrm{op}(F_p, f)$ | $O(\log n)$ |
| `S get(int p)` / `operator[]` | $F_p$ | $O(\log n)$ |
| `void set(int p, S f)` | $F_p = f$ | $O(\log n)$ |

## 注意

- 値そのものではなく「これまでの作用の合成」を返す。初期値への適用は呼び出し側で行う（`get(i)(a[i])` など）。
