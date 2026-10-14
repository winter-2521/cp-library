---
title: 永続 Union-Find (Persistent Union-Find)
documentation_of: //data_structure/persistent_unionfind.hpp
---

## 概要

Union-Find の **どの過去の版にも** 辺を足して新しい版を作れる（オンライン）。

親の配列を [永続配列](persistent_array.hpp) で持つ。経路圧縮は（過去の版を書き換えてしまうので）使わず、union by size だけで木の高さを $O(\log n)$ に抑える。

## 使い方

```cpp
PersistentUnionFind uf(n);
uf.reserve(q);
int v0 = uf.initial_version();   // 辺なし
int v1 = uf.merge(v0, a, b);     // 版 v0 に辺 (a, b) を足した版
uf.same(v1, a, b);               // true
uf.same(v0, a, b);               // false (古い版はそのまま)
uf.leader(v1, a); uf.size(v1, a);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `int merge(int v, int x, int y)` | 版 $v$ に辺を足した版 | $O(\log n \cdot \log_8 n)$ |
| `bool same(int v, int x, int y)` | 版 $v$ で連結か | $O(\log n \cdot \log_8 n)$ |
| `int leader(int v, int x)` / `int size(int v, int x)` | 根 / 連結成分の大きさ | $O(\log n \cdot \log_8 n)$ |

## 注意

- `merge` は内部で永続配列を 2 回更新するので、版の番号は連番にならない。返り値の番号をそのまま使うこと。
- クエリを先読みできるなら、版の木を DFS しながら undo 付き Union-Find で処理するオフライン解法の方がメモリが少ない。
