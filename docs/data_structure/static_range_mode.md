---
title: 静的な区間最頻値 (Static Range Mode Query)
documentation_of: //data_structure/static_range_mode.hpp
---

## 概要

静的な数列 $a$ について、区間 $[l, r)$ の最頻値とその個数を $O(\sqrt n)$ で答える（**オンライン**、平方分割）。

- 長さ $B \approx \sqrt n$ のブロックに分け、ブロックの区間 $[b_i, b_j]$ ごとに最頻値と個数を前計算する（$O(n \sqrt n)$）。
- クエリでは、間の完全なブロックの最頻値から始め、両端の端数の要素それぞれについて「その値が個数 + 1 回出てくるか」を、値ごとの出現位置の列で $O(1)$ ずつ確かめて伸ばしていく。個数が増えるのは端数の要素数回まで。

## 使い方

```cpp
StaticRangeMode<int> md(a);       // vector<int> a
auto [x, c] = md.query(l, r);    // a[l..r) の最頻値 x とその個数 c (l < r)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `StaticRangeMode<T>(const vector<T> &a)` | 構築 | $O(n \sqrt n)$ |
| `pair<T, int> query(int l, int r)` | 最頻値と個数 | $O(\sqrt n)$ |

## 注意

- 最頻値が複数あるときはどれか 1 つを返す。
- $l < r$ で呼ぶこと。
- メモリはブロック数の 2 乗（$n = 10^5$ で約 $10^5$ 個の int）+ $O(n)$。
