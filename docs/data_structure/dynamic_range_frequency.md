---
title: 一点更新ありの区間の値の個数 (Point Set Range Frequency)
documentation_of: //data_structure/dynamic_range_frequency.hpp
---

## 概要

数列 $a$ について、一点更新 $a_i \gets x$ と「$a_l, \ldots, a_{r-1}$ の中の $x$ の個数」を $O(\log n)$ で処理する（**オンライン**）。
(値, 位置) の組を [順序付き集合](ordered_set.hpp) に入れておき、$(x, l)$ 以上 $(x, r)$ 未満の組の個数を数える。

## 使い方

```cpp
DynamicRangeFrequency<int> f(a);   // vector<int> a
f.set(i, x);                       // a[i] = x
f.count(l, r, x);                  // a[l..r) の中の x の個数
f.get(i);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `DynamicRangeFrequency<T>(const vector<T> &a)` | 構築 | $O(n \log n)$ |
| `void set(int i, T x)` | $a_i = x$ | $O(\log n)$ |
| `int count(int l, int r, T x)` | 区間の $x$ の個数 | $O(\log n)$ |
| `T get(int i)` | $a_i$ | $O(1)$ |

## 注意

- 更新がないなら [StaticRangeFrequency](static_range_frequency.hpp) の方が速い。
