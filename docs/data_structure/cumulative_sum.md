---
title: 累積和 (Cumulative Sum)
documentation_of: //data_structure/cumulative_sum.hpp
---

## 概要

静的な配列の区間和を $O(1)$ で求める。1 次元版 `CumulativeSum` と 2 次元版 `CumulativeSum2D` がある。
2 次元版は 1 本の配列にまとめて持つ（`vector<vector<T>>` より速い）。

## 使い方

```cpp
vector<int> a = {3, 1, 4, 1, 5};
CumulativeSum<long long> cs(a);  // 和の型 T を指定する (要素の型 U は T に変換できればよい)
cs.sum(1, 4);                    // a[1] + a[2] + a[3] = 6
cs.prefix(3);                    // a[0] + a[1] + a[2] = 8
cs.push_back(9);                 // 末尾に追加

vector<vector<int>> g(h, vector<int>(w));
CumulativeSum2D<long long> cs2(g);
cs2.sum(x1, y1, x2, y2);         // 行 [x1, x2) × 列 [y1, y2) の和
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `CumulativeSum<T>(const vector<U> &a)` | 配列 `a` から構築 | $O(n)$ |
| `T sum(int l, int r)` | $a_l + \cdots + a_{r-1}$ | $O(1)$ |
| `T prefix(int r)` | $a_0 + \cdots + a_{r-1}$ | $O(1)$ |
| `void push_back(T x)` | 末尾に `x` を追加 | ならし $O(1)$ |
| `int size()` | 要素数 | $O(1)$ |
| `CumulativeSum2D<T>(const vector<vector<U>> &a)` | $h \times w$ の配列から構築 | $O(hw)$ |
| `T sum(int x1, int y1, int x2, int y2)` | $[x_1, x_2) \times [y_1, y_2)$ の和 | $O(1)$ |

## 注意

- 区間は半開区間。`l == r` なら 0 を返す。
- `T` は `+`, `-` が使える型（加法群）であればよい。modint でも使える。
- 和がオーバーフローしないよう `T` は十分大きな型にすること（`int` の配列でも和は `long long` にするなど）。
