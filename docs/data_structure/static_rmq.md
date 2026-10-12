---
title: 静的 RMQ (Static Range Minimum Query)
documentation_of: //data_structure/static_rmq.hpp
---

## 概要

静的な配列の区間最小値（とその位置）を、構築 $O(n)$・クエリ $O(1)$ で求める。

64 要素ずつのブロックに分け、

- ブロック内：各位置 $i$ について「ブロック先頭から $i$ までの単調スタック」を 64 bit のビットマスクで持つ。区間 $[l, i]$ の最小値の位置は、マスクを $l$ でシフトした最下位ビット。
- ブロック間：ブロックごとの最小値の位置に対する Sparse Table（$O(\frac{n}{64} \log n)$ 要素）。

とする。Sparse Table を直接作るよりメモリが少なくキャッシュに乗りやすいので速い。

## 使い方

```cpp
StaticRMQ<int> mn(a);                     // 最小値
StaticRMQ<int, greater<int>> mx(a);       // 比較関数を変えると最大値
mn.prod(l, r);     // min(a[l], ..., a[r-1])
mn.argmin(l, r);   // その位置 (最小値が複数あれば一番左)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `StaticRMQ<T, Compare = less<T>>(const vector<T> &a, Compare comp = Compare())` | 構築 | $O(n)$ |
| `T prod(int l, int r)` | $[l, r)$ の最小値 | $O(1)$ |
| `int argmin(int l, int r)` | $[l, r)$ の最小値の位置（複数あれば一番左） | $O(1)$ |

## 注意

- `l < r` であること（空区間には対応していない）。
- `Compare` は狭義弱順序（`less` / `greater` など）。`greater<T>` にすると最大値と、最大値のうち一番左の位置を返す。
- 配列のコピーを内部に持つ。
