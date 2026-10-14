---
title: 静的な区間の値の個数 (Static Range Frequency)
documentation_of: //data_structure/static_range_frequency.hpp
---

## 概要

静的な数列 $a$ について「$a_l, \ldots, a_{r-1}$ の中に $x$ が何個あるか」を $O(\log n)$ で答える（オンライン）。
値ごとに出現位置を昇順に並べた列を作っておき、$x$ の位置の列の中で $[l, r)$ に入るものを二分探索で数える。

## 使い方

```cpp
StaticRangeFrequency<int> f(a);   // vector<int> a (値の型は < で比べられれば何でもよい)
f.count(l, r, x);                 // a[l..r) の中の x の個数
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `StaticRangeFrequency<T>(const vector<T> &a)` | 構築 | $O(n \log n)$ |
| `int count(int l, int r, T x)` | $a_l, \ldots, a_{r-1}$ の中の $x$ の個数 | $O(\log n)$ |

## 注意

- 値が変わるなら [DynamicRangeFrequency](dynamic_range_frequency.hpp)。
