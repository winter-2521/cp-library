---
title: Fenwick Tree (Binary Indexed Tree)
documentation_of: //data_structure/fenwick_tree.hpp
---

## 概要

一点加算と区間和を $O(\log n)$ で処理する。外部からは 0-indexed で扱う。

- 配列からの構築は $O(n)$。
- `sum(l, r)` は `sum(r) - sum(l)` を 2 回計算するのではなく、$l, r$ から lowbit を消していって一致したところで打ち切るので、短い区間ほど速い。
- 全要素が非負なら、累積和に対する二分探索 (`lower_bound` / `upper_bound`) が $O(\log n)$ でできる。座標圧縮した値の個数を持てば「$k$ 番目に小さい値」が求まる。

## 使い方

```cpp
FenwickTree<long long> bit(n);   // 全て 0 で初期化
FenwickTree<long long> bit2(a);  // vector<long long> a で初期化
bit.add(i, x);                   // a[i] += x
bit.sum(l, r);                   // a[l] + ... + a[r-1]
bit.sum(r);                      // a[0] + ... + a[r-1]
bit.get(i);                      // a[i]
bit.set(i, x);                   // a[i] = x
bit.lower_bound(w);              // a[0] + ... + a[i] >= w となる最小の i
bit.upper_bound(w);              // a[0] + ... + a[i] >  w となる最小の i
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `FenwickTree(int n)` | 長さ `n`、全て 0 で初期化 | $O(n)$ |
| `FenwickTree(const vector<T> &a)` | 配列 `a` で初期化 | $O(n)$ |
| `void add(int i, T x)` | $a_i \mathrel{+}= x$ | $O(\log n)$ |
| `T sum(int r)` | $a_0 + \cdots + a_{r-1}$ | $O(\log n)$ |
| `T sum(int l, int r)` | $a_l + \cdots + a_{r-1}$ | $O(\log n)$ |
| `T get(int i)` | $a_i$ | $O(\log n)$ |
| `void set(int i, T x)` | $a_i = x$ | $O(\log n)$ |
| `int lower_bound(T w)` | $a_0 + \cdots + a_i \ge w$ となる最小の $i$（なければ $n$）。$w \le 0$ なら 0 | $O(\log n)$ |
| `int upper_bound(T w)` | $a_0 + \cdots + a_i > w$ となる最小の $i$（なければ $n$） | $O(\log n)$ |
| `int size()` | 要素数 | $O(1)$ |

## 注意

- `T` は `+=`, `-=` が使える型（可換群）であればよい。modint でも使える。
- `lower_bound` / `upper_bound` は **全要素が非負** のときのみ正しい。
