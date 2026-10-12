---
title: 動的遅延セグメント木 (Dynamic Lazy Segment Tree)
documentation_of: //data_structure/dynamic_lazy_segment_tree.hpp
---

## 概要

添字の範囲が大きい（$n \le 10^{18}$ 程度）場合の区間作用・区間積。**オンライン** で動く。はじめ全ての要素が `x0`。
触った部分だけノードを作り、1 回の操作で作るノードは $O(\log n)$ 個。

大きさを 2 冪 $2^K$ に切り上げ、まだノードを作っていない長さ $2^k$ の区間の積として $x_0^{2^k}$ を事前に計算して使う。区間積はノードを作らない（上から作用を持ち越して計算する）。

## 使い方

```cpp
using AM = ActedAffineSum<mint>;
DynamicLazySegmentTree<AM> seg(1000000000, AM::make(0));   // 全て 0
seg.apply(l, r, {b, c});
seg.prod(l, r).sum;
seg.set(p, AM::make(x)); seg.get(p); seg.all_prod();
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `DynamicLazySegmentTree<AM>(long long n, S x0 = e())` | 長さ `n`、全て `x0` | $O(\log n)$ |
| `void apply(long long l, long long r, F f)` | $i \in [l, r)$ について $a_i = f(a_i)$ | $O(\log n)$ |
| `S prod(long long l, long long r)` | 区間積 | $O(\log n)$ |
| `void set(long long p, S x)` / `S get(long long p)` | 一点代入・取得 | $O(\log n)$ |
| `S all_prod()` | 全体の積 | $O(1)$ |

## 注意

- メモリは 1 回の操作あたり最大 $4 \log_2 n$ ノード程度（$n = 10^9$、$q = 10^5$ で手元 100 MB）。
- `x0` は「和を持つ」型なら `make(x)`（長さ 1）で渡すこと。
