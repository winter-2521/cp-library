---
title: 静的な区間の種類数 (Static Range Count Distinct)
documentation_of: //data_structure/static_range_count_distinct.hpp
---

## 概要

静的な数列 $a$ について「$a_l, \ldots, a_{r-1}$ に何種類の値があるか」を $O(\log n)$ で答える（**オンライン**）。

$\mathrm{prev}_i$ を「$i$ より前で $a_i$ と同じ値が最後に出てくる位置（なければ $-1$）」とすると、区間 $[l, r)$ の中で各値を **一番左の出現** だけ数えればよく、それは $\mathrm{prev}_i < l$ となる $i$。よって答えは $\#\{i \in [l, r) : \mathrm{prev}_i < l\}$ で、これは $\mathrm{prev}$ の列に対する [ウェーブレット行列](wavelet_matrix.hpp) の `count_lt` 1 回で求まる。

## 使い方

```cpp
StaticRangeCountDistinct<int> cd(a);   // vector<int> a
cd.count(l, r);                        // a[l..r) の種類数
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `StaticRangeCountDistinct<T>(const vector<T> &a)` | 構築 | $O(n \log n)$ |
| `int count(int l, int r)` | $a_l, \ldots, a_{r-1}$ の種類数 | $O(\log n)$ |

## 注意

- クエリを先読みできるなら、右端でソートして BIT で数えるオフライン解法もある（定数倍はそちらの方が軽い）。
