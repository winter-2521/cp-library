---
title: Sparse Table
documentation_of: //data_structure/sparse_table.hpp
---

## 概要

**冪等** な結合的演算（$\min$, $\max$, $\gcd$, bitwise and / or など、$x \cdot x = x$ となるもの）の区間クエリを、構築 $O(n \log n)$・クエリ $O(1)$ で処理する。
テーブルは `vector<vector<T>>` ではなく 1 本の配列にまとめて持っている。

区間最小値・最大値だけなら、メモリが $O(n)$ で済む [`StaticRMQ`](static_rmq.hpp) の方が速い。

## 使い方

```cpp
SparseTable st(a, [](int x, int y) { return min(x, y); });      // 演算をラムダで渡す
SparseTable g(a, [](long long x, long long y) { return gcd(x, y); });
st.prod(l, r);   // op(a[l], ..., a[r-1])
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `SparseTable(const vector<T> &a, Op op)` | 配列 `a` と演算 `op` で構築 | $O(n \log n)$ |
| `T prod(int l, int r)` | $\mathrm{op}(a_l, \ldots, a_{r-1})$ | $O(1)$ |

## 注意

- `l < r` であること（空区間には対応していない）。
- 冪等でない演算（和など）には使えない（重なった 2 区間を合成するため）。
- C++17 のクラステンプレート引数推論で `T`, `Op` を推論する。明示するなら `SparseTable<int, decltype(f)> st(a, f);`。
