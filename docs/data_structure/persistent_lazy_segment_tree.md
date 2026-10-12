---
title: 永続遅延セグメント木 (Persistent Lazy Segment Tree)
documentation_of: //data_structure/persistent_lazy_segment_tree.hpp
---

## 概要

遅延セグメント木の全てのバージョンを残す。各バージョンを根のノード番号 (`int`) で表し、更新操作は新しいバージョンの根を返す（元のバージョンは変わらない）。
「あるバージョンの区間を別のバージョンの同じ区間で置き換える」(`copy_range`) もできる。

- 更新は書き換えるノードだけを複製する（経路複製）。作用を下ろすときは子も複製する。
- 作用が残っていないノードでは、降りる側の子だけを複製する（ノード数と時間が約 2 割減る）。
- 区間積はノードを作らない（上から作用を持ち越して計算する）。
- ノードは $2^{16}$ 個ずつのブロックに確保する（`vector` の再確保によるコピーとメモリの一時的な倍増を避ける）。

## 使い方

```cpp
using AM = ActedAffineSum<mint>;
PersistentLazySegmentTree<AM> seg(n);
int v0 = seg.build(a);                    // vector<AM::S> a から最初のバージョン
int v1 = seg.apply(v0, l, r, {b, c});     // v0 に作用させたバージョン
int v2 = seg.copy_range(v1, v0, l, r);    // v1 の [l, r) を v0 の [l, r) にしたバージョン
int v3 = seg.set(v2, p, AM::make(x));
seg.prod(v1, l, r).sum;                   // v1 の区間和 (v0 は変わっていない)
seg.get(v0, p); seg.all_prod(v0); seg.to_vector(v0);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `PersistentLazySegmentTree<AM>(int n)` | 長さ `n` の木の入れ物 | $O(1)$ |
| `int build(const vector<S> &a)` / `int build(S x)` | 最初のバージョンを作る | $O(n)$ |
| `int apply(int v, int l, int r, F f)` | 区間作用したバージョン | $O(\log n)$ |
| `int copy_range(int dst, int src, int l, int r)` | `dst` の $[l, r)$ を `src` のもので置き換えたバージョン | $O(\log n)$ |
| `int set(int v, int p, S x)` | 一点代入したバージョン | $O(\log n)$ |
| `S prod(int v, int l, int r)` / `S get(int v, int p)` | 区間積 / 一点取得 | $O(\log n)$ |
| `S all_prod(int v)` | 全体の積 | $O(1)$ |
| `vector<S> to_vector(int v)` | 配列全体 | $O(n)$ |
| `int node_count()` | これまでに作ったノード数 | $O(1)$ |

## 注意

- ノードは解放しない。メモリは $O(n + q \log n)$（$n = q = 10^5$ の区間 1 次関数・区間和で手元最大 240 MB）。
