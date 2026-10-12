---
title: Segment Tree Beats
documentation_of: //data_structure/segment_tree_beats.hpp
---

## 概要

区間 chmin・区間 chmax・区間加算・区間代入と、区間和・区間最小値・区間最大値を処理する。

各ノードに最大値・2 番目の最大値・最大値の個数（最小値側も同様）と和を持つ。区間 chmin($x$) で、ノードの「2 番目の最大値 $< x <$ 最大値」なら最大値の要素だけが変わるので、そのノードで止められる。そうでなければ子に降りる。
降りる回数はポテンシャル（各ノードの部分木内の値の種類数の和）で評価でき、ならし $O((n + q) \log^2 n)$（加算がなければ $O((n + q) \log n)$）。

## 使い方

```cpp
SegmentTreeBeats<long long> seg(a);   // vector<long long> a
seg.chmin(l, r, x);   // a[i] = min(a[i], x)
seg.chmax(l, r, x);   // a[i] = max(a[i], x)
seg.add(l, r, x);     // a[i] += x
seg.assign(l, r, x);  // a[i] = x
seg.sum(l, r); seg.min(l, r); seg.max(l, r); seg.get(i);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `SegmentTreeBeats<T>(const vector<T> &a)` / `(int n)` | 構築 | $O(n)$ |
| `void chmin(int l, int r, T x)` / `void chmax(int l, int r, T x)` | 区間 chmin / chmax | ならし $O(\log^2 n)$ |
| `void add(int l, int r, T x)` | 区間加算 | $O(\log n)$（ならし評価に影響） |
| `void assign(int l, int r, T x)` | 区間代入（chmin と chmax の組み合わせ） | ならし $O(\log^2 n)$ |
| `T sum(int l, int r)` / `T min(int l, int r)` / `T max(int l, int r)` | 区間和 / 最小 / 最大 | $O(\log n)$ |
| `T get(int i)` | $a_i$ | $O(\log n)$ |

## 注意

- 和がオーバーフローしないよう `T` を選ぶこと（$|a_i| \le 10^{12}$、$n = 2 \times 10^5$ なら `long long` で足りる）。
