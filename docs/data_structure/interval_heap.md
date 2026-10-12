---
title: Interval Heap (両端優先度付きキュー)
documentation_of: //data_structure/interval_heap.hpp
---

## 概要

最小値と最大値の両方を取り出せる優先度付きキュー。1 本の配列で持ち、節点 $k$ が区間 $[d_{2k}, d_{2k+1}]$ を持つ。左端だけ見ると min-heap、右端だけ見ると max-heap になっている。
`std::multiset` よりはるかに速く、`priority_queue` 2 本 + 遅延削除よりもメモリが少なく速い。

## 使い方

```cpp
IntervalHeap<int> hp;               // 比較関数を渡すことも可 (IntervalHeap<T, Compare>)
IntervalHeap<int> hp2(a);           // vector から構築
hp.reserve(n);
hp.push(x);
hp.min(); hp.max();                 // 参照 (空でないこと)
hp.pop_min(); hp.pop_max();         // 取り出して値を返す (空でないこと)
hp.size(); hp.empty(); hp.clear();
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `IntervalHeap<T, Compare = less<T>>()` | 空で初期化 | $O(1)$ |
| `IntervalHeap(const vector<T> &a)` | `a` の要素を入れて初期化 | $O(n \log n)$ |
| `void push(T x)` | `x` を追加 | $O(\log n)$ |
| `const T &min()` / `const T &max()` | 最小値 / 最大値 | $O(1)$ |
| `T pop_min()` / `T pop_max()` | 最小値 / 最大値を取り出す | $O(\log n)$ |
| `int size()` / `bool empty()` | 要素数 / 空か | $O(1)$ |
| `void reserve(int n)` / `void clear()` | 容量確保 / 全削除 | - |

## 注意

- `min` / `max` / `pop_min` / `pop_max` は空でないときに呼ぶこと。
- 要素数 1 のときは最小値と最大値は同じ要素。
