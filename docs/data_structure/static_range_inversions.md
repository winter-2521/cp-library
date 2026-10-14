---
title: 静的な区間転倒数 (Static Range Inversions Query)
documentation_of: //data_structure/static_range_inversions.hpp
---

## 概要

静的な数列 $a$ について、区間 $[l, r)$ の転倒数（$l \le i < j < r$ かつ $a_i > a_j$ の組の数）を $O(\sqrt n)$ で答える（**オンライン**、平方分割）。

大きさ $B$ のブロックに分け、次を前計算する。

| 表 | 意味 |
| --- | --- |
| `lt[R][i]` | $i$ のブロックより右、ブロック $R$ の手前までの要素で $a_i$ より小さいものの個数 |
| `gt[L][j]` | ブロック $L$ から $j$ のブロックの手前までの要素で $a_j$ より大きいものの個数 |
| `big[L][R]` | ブロック $L, \ldots, R-1$ の中の転倒数 |
| `pre[i]`, `suf[i]` | $i$ のブロックの中で、先頭から $i$ まで / $i$ から末尾までの転倒数 |
| ブロックごとの (値, 位置) の昇順リスト | 端どうしの組を数えるのに使う |

クエリは「左の端数・間の完全なブロック・右の端数」に分け、(端数の中) + (ブロックの中) + (端数 × ブロック: `lt`, `gt` を順に足す) + (左の端数 × 右の端数: 昇順リストのマージ) で数える。`lt` / `gt` は位置の順に並べてあるので、端数を順に見るとき連続アクセスになって速い。

## 使い方

```cpp
StaticRangeInversions<int> inv(a);       // vector<int> a
StaticRangeInversions<int> inv2(a, 256); // ブロックの大きさを指定
inv.query(l, r);                         // a[l..r) の転倒数 (long long)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `StaticRangeInversions<T>(const vector<T> &a, int block = -1)` | 構築（`block` 省略で $1.25\sqrt n$） | $O(n \sqrt n)$ |
| `long long query(int l, int r)` | 区間転倒数 | $O(\sqrt n)$ |

## 注意

- メモリは $2 n \cdot n / B$ 個の int（$n = 10^5$ で約 200 MB）。メモリが厳しいときは `block` を大きくする（クエリは遅くなる）。
- クエリを先読みできるなら Mo's algorithm + BIT（$O(n \sqrt q \log n)$）でも解ける。こちらは $\log$ が付かない。
