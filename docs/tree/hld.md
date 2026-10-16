---
title: 重軽分解 (Heavy-Light Decomposition)
documentation_of: //tree/hld.hpp
---

## 概要

根付き木を「重い道」（各頂点から部分木が最大の子へ進む道）に分ける。頂点を「重い子を先に訪れる DFS の行きがけ順」に並べると、

- 部分木は区間 `[in[v], out[v])`
- 任意の 2 頂点を結ぶ道は $O(\log n)$ 個の区間

になる。軽い辺を通るたびに部分木の大きさが半分以下になるので、道が通る重い道は $O(\log n)$ 本。

LCA、距離、$k$ 個上の祖先、道の $k$ 番目の頂点を $O(\log n)$ で答えられる。セグメント木などと組み合わせると道・部分木への更新や集約ができる。構築は非再帰で $O(n)$。

## 使い方

```cpp
HLD hld(n, edges, root);        // 木の辺 (n-1 本) と根から
HLD hld2(par);                  // 親の配列から (根は par = -1)
hld.lca(u, v);  hld.dist(u, v);
hld.la(v, k);                   // v から k 個上の祖先 (なければ -1)
hld.jump(s, t, i);              // s から t への道の i 番目の頂点 (道より長ければ -1)
hld.in[v];  hld.ord[i];         // 頂点 → 番号，番号 → 頂点
auto [l, r] = hld.subtree(v);   // 部分木の番号の区間 [l, r)
hld.path(u, v, [&](int l, int r) { /* 道の一部の番号の区間 [l, r) */ });
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `HLD(int n, edges, int root = 0)` / `HLD(par)` | 構築 | $O(n)$ |
| `int lca(int u, int v)` | 最小共通祖先 | $O(\log n)$ |
| `int dist(int u, int v)` | 距離 (辺の本数) | $O(\log n)$ |
| `int la(int v, int k)` | $k$ 個上の祖先 | $O(\log n)$ |
| `int jump(int s, int t, int i)` | 道の $i$ 番目 | $O(\log n)$ |
| `void path(int u, int v, F f)` | 道を番号の区間に分ける (順不同) | $O(\log n)$ 個 |
| `pair<int,int> subtree(int v)` | 部分木の区間 | $O(1)$ |

## 注意

- `path` の区間は道の向きの順にはなっていない。非可換な演算を道に沿って畳み込むときは向きを考える必要がある。
