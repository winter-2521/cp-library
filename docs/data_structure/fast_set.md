---
title: 64 分木による整数集合 (Fast Set)
documentation_of: //data_structure/fast_set.hpp
---

## 概要

$[0, n)$ の整数の集合を 64 分木（各段がビット列）で持ち、挿入・削除・存在判定・「$i$ 以上の最小の要素」・「$i$ 以下の最大の要素」を $O(\log_{64} n)$ で処理する。
$n = 10^6$ でも 4 段なので、`std::set` よりはるかに速く、メモリも約 $n/8$ バイトしか使わない。

## 使い方

```cpp
FastSet fs(n);                                   // 空集合
FastSet fs2(n, [&](int i) { return s[i] == '1'; });  // f(i) が true の i を入れて O(n) で構築
fs.insert(i); fs.erase(i);
fs.contains(i);   // fs[i] でも可
fs.next(i);       // i 以上の最小の要素 (なければ -1)
fs.prev(i);       // i 以下の最大の要素 (なければ -1)
fs.min(); fs.max(); fs.empty();
fs.enumerate(l, r, [&](int x) { ... });  // [l, r) の要素を昇順に列挙
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `FastSet(int n)` | 空集合で初期化 | $O(n / 64)$ |
| `FastSet(int n, F f)` | `f(i)` が `true` の `i` を入れて初期化 | $O(n)$ |
| `void insert(int i)` | `i` を追加（既にあれば何もしない） | $O(\log_{64} n)$ |
| `void erase(int i)` | `i` を削除（なければ何もしない） | $O(\log_{64} n)$ |
| `bool contains(int i)` | `i` が含まれるか | $O(1)$ |
| `int next(int i)` | `i` 以上の最小の要素。なければ `-1`（`i < 0` なら 0 とみなす） | $O(\log_{64} n)$ |
| `int prev(int i)` | `i` 以下の最大の要素。なければ `-1`（`i >= n` なら `n - 1` とみなす） | $O(\log_{64} n)$ |
| `int min()` / `int max()` | 最小 / 最大の要素（空なら `-1`） | $O(\log_{64} n)$ |
| `bool empty()` | 空か | $O(1)$ |
| `void enumerate(int l, int r, F f)` | $[l, r)$ の要素を昇順に `f(x)` | $O((\text{個数} + 1) \log_{64} n)$ |

## 注意

- 要素数を数える機能はない（順位や $k$ 番目が必要なら [OrderedSet](ordered_set.hpp) を使う）。
- 値の範囲が大きい場合は座標圧縮してから使う。
