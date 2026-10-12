---
title: 重み付き Union-Find (Weighted Union-Find)
documentation_of: //data_structure/weighted_dsu.hpp
---

## 概要

各要素にポテンシャル（重み）$p(x)$ を持たせた Union-Find。
「$p(y) - p(x) = w$」という差分制約を追加していき、同じ集合に属する 2 要素の差分を求められる。
union by rank と経路圧縮を併用している。頂点は 0-indexed。

## 使い方

```cpp
WeightedUnionFind<long long> uf(n);   // 型 T は重みの型 (デフォルト int)
uf.unite(x, y, w);    // p(y) - p(x) = w という関係を追加
uf.same(x, y);        // 同じ集合なら true
uf.diff(x, y);        // p(y) - p(x) を返す (same(x, y) のときのみ意味がある)
uf.weight(x);         // 代表元を基準とした p(x)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `WeightedUnionFind(int n, T SUM_UNITY = 0)` | 要素数 `n` で初期化。`SUM_UNITY` は重みの単位元 | $O(n)$ |
| `int find(int x)` | 代表元を返す | ならし $O(\alpha(n))$ |
| `T weight(int x)` | 代表元の重みを `SUM_UNITY` としたときの $p(x)$ | ならし $O(\alpha(n))$ |
| `bool same(int x, int y)` | 同じ集合か判定 | ならし $O(\alpha(n))$ |
| `bool unite(int x, int y, T w)` | $p(y) - p(x) = w$ となるよう併合。既に同じ集合なら何もせず `false` | ならし $O(\alpha(n))$ |
| `T diff(int x, int y)` | $p(y) - p(x)$ | ならし $O(\alpha(n))$ |

## 注意

- **向きに注意**：`unite(x, y, w)` は $p(y) - p(x) = w$ を意味する。`diff(x, y)` も同じ向きで $p(y) - p(x)$ を返す。
- 既に同じ集合に属する `x, y` に対して `unite` を呼んでも、制約の矛盾チェックはしない。矛盾判定が必要なら、先に `same(x, y)` を確認して `diff(x, y) == w` かを比較すること。
- 重みは加法群（`+=`, `-=`, 単項 `-` が使える型）であればよい。
