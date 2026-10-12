---
title: 区間ソートができるセグメント木 (Sortable Segment Tree)
documentation_of: //data_structure/sortable_segment_tree.hpp
---

## 概要

各位置 $i$ に（キー $k_i$, 値 $a_i$）を持ち、一点更新・区間積・**区間をキーの昇順 / 降順にソート** を処理する。値はモノイド（非可換でもよい）。**オンライン** で動く（キーの先読み不要）。

ソート済みの連続部分（ラン）ごとに、キーの 2 分トライを持つ。トライの各ノードは要素数と「キーの昇順に並べた積」「降順に並べた積」を持つ。

- 区間ソート：両端でランを切り、内側のランのトライを全てマージする。
- ランを途中で切る：トライを要素数で分割する（作るノードは $O(\mathrm{LOG})$ 個）。
- 区間積：両端でランを切り、ランの先頭位置にランの積を置いたセグメント木で求める。

トライのマージは「重なったノードの個数」だけ時間がかかり、重なったノードは 1 つ消える。ノードを作るのは初期化・一点更新・分割だけなので、マージの総コストは作ったノード数で抑えられ、全体でならし $O((n + q) \mathrm{LOG})$。

## 使い方

```cpp
SortableSegmentTree<MonoidAffine<mint>> seg(keys, vals);  // vector<long long> keys, vector<Affine<mint>> vals
seg.set(i, key, x);     // 位置 i を (key, x) に
seg.prod(l, r)(x);      // op(a[l], ..., a[r-1])
seg.sort_asc(l, r);     // [l, r) をキーの昇順にソート
seg.sort_desc(l, r);    // 降順
auto [key, x] = seg.get(i);
seg.all_prod();
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `SortableSegmentTree<M, LOG = 30>(keys, vals)` | 構築 | $O(n \cdot \mathrm{LOG})$ |
| `void set(int i, long long key, S x)` | 位置 $i$ を (key, x) に | $O(\mathrm{LOG} + \log n)$ |
| `S prod(int l, int r)` | 区間積 | $O(\mathrm{LOG} + \log n)$ |
| `void sort_asc(int l, int r)` / `sort_desc` | 区間をソート | ならし $O(\mathrm{LOG} + \log n)$ |
| `pair<long long, S> get(int i)` | 位置 $i$ の (キー, 値) | $O(\mathrm{LOG} + \log_{64} n)$ |
| `S all_prod()` | 全体の積 | $O(1)$ |

## 注意

- キーは $[0, 2^{\mathrm{LOG}})$ の整数で、**常に全て相異なる** こと。
- メモリは $O(n \cdot \mathrm{LOG})$ 個のトライのノード（消えたノードは再利用する）。$n = q = 10^5$ で手元 100 MB。
