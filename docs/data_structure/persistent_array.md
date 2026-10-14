---
title: 永続配列 (Persistent Array)
documentation_of: //data_structure/persistent_array.hpp
---

## 概要

配列の **どの過去の版からでも** 一点更新でき、新しい版を作る。$2^{\mathrm{LOG}}$ 分木（デフォルト 8 分木）で持ち、更新では根から葉までの道のノードだけを複製する（path copying）。

## 使い方

```cpp
PersistentArray<int> pa(a);          // vector<int> a．版 0
PersistentArray<int> pb(n, -1);      // 長さ n，全て -1
pa.reserve(q);
int v1 = pa.set(0, i, x);            // 版 0 の a[i] を x にした版
pa.get(v1, i);                       // 版 v1 の a[i]
pa.get(0, i);                        // 版 0 はそのまま
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `PersistentArray<T, LOG = 3>(const vector<T> &a)` | 構築（版 0） | $O(n)$ |
| `T get(int v, int i)` | 版 $v$ の $a_i$ | $O(\log_{2^{\mathrm{LOG}}} n)$ |
| `int set(int v, int i, T x)` | 版 $v$ の $a_i$ を $x$ にした版 | $O(2^{\mathrm{LOG}} \log_{2^{\mathrm{LOG}}} n)$ |

## 注意

- `set` 1 回で $2^{\mathrm{LOG}} \times$ 高さ 個の int を使う。`LOG` を大きくすると `get` は速くなるが `set` のメモリが増える。
