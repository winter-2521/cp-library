---
title: オフライン動的連結性
documentation_of: //graph/offline_dynamic_connectivity.hpp
---

## 概要

辺の追加・削除、頂点の値への加算、連結成分の値の和の質問を処理する。**クエリを全部先読みできるときのみ** 使える。

各辺が存在する時刻の区間 $[l, r)$ を、時刻のセグメント木の $O(\log Q)$ 個のノードに載せる。セグメント木を DFS し、ノードに入るときにその辺を Union-Find で併合、出るときに戻す（経路圧縮なし・大きさで併合）。葉（時刻 $t$）でその時刻の操作を行う。頂点 $v$ への加算は「$v$ から根までの各頂点の部分木の和」に足すので、併合を戻しても正しく残る。$O(Q \log Q \log n)$。

## 使い方

```cpp
OfflineDynamicConnectivity dc(n, a);   // a: 頂点の初期値 (省略すると 0)
dc.link(u, v);                         // 辺を追加 (その時点でない辺)
dc.cut(u, v);                          // 辺を削除 (その時点である辺)
dc.add(v, x);                          // a_v += x
dc.query(v);                           // v の連結成分の値の和を尋ねる
vector<long long> ans = dc.solve();    // query の答え (登録順)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `link`, `cut`, `add`, `query` | 操作の登録 | $O(1)$ |
| `vector<long long> solve()` | 全部の操作を処理 | $O(Q \log Q \log n)$ |

## 注意

- 同じ辺を同時に 2 本持つことはできない（多重辺は不可）。
- 値は `long long` の範囲で足し合わせる。
