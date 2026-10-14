---
title: オイラー路 (Eulerian Trail)
documentation_of: //graph/eulerian_trail.hpp
---

## 概要

全ての辺をちょうど 1 回ずつ通る路（オイラー路）を求める。Hierholzer の方法を非再帰で実装。$O(n + m)$。

- 存在条件（有向）：全ての頂点で 出次数 = 入次数、または 出 − 入 = 1 の頂点と 入 − 出 = 1 の頂点がちょうど 1 つずつ（始点・終点）で、辺を持つ頂点が全部つながっている。
- 存在条件（無向）：次数が奇数の頂点が 0 個か 2 個で、辺を持つ頂点が全部つながっている。

始点から「まだ使っていない辺があれば進む、なければ路に出力して戻る」を繰り返し、出力を逆順にする。全ての辺を使えなかったら非連結なので存在しない。

## 使い方

```cpp
vector<pair<int, int>> edges;
auto [vs, es] = eulerian_trail<true>(n, edges);    // 有向．vs: 頂点の列 (m+1 個)，es: 辺番号の列 (m 個)
auto [vs2, es2] = eulerian_trail<false>(n, edges); // 無向
if (vs.empty()) { /* 存在しない */ }
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `pair<vector<int>, vector<int>> eulerian_trail<DIRECTED>(int n, edges)` | オイラー路．なければ空 | $O(n + m)$ |

## 注意

- 辺が 1 本もないときは `{{0}, {}}`（頂点 0 だけの長さ 0 の路）を返す。
- 閉路（始点 = 終点）が欲しいときは、全頂点の次数条件が「出 = 入」（無向なら全て偶数）であることを先に確かめる。
