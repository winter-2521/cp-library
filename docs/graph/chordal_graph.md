---
title: 弦グラフ判定 (Chordal Graph Recognition)
documentation_of: //graph/chordal_graph.hpp
---

## 概要

単純無向グラフが弦グラフ（長さ 4 以上の誘導閉路がない）か判定する。弦グラフなら完全消去順序（PEO）を、そうでなければ長さ 4 以上の誘導閉路を返す。$O(n + m)$。

1. **最大基数探索 (MCS)**：「訪問済みの隣の数」が最大の未訪問頂点を順に訪れる（重みごとのバケット）。弦グラフなら訪問順の逆が PEO。
2. **検査 (Tarjan-Yannakakis)**：訪問順で $x$ の先に訪れた隣のうち最後のものを親 $z$ とし、$x$ の他の先に訪れた隣が全て $z$ と隣接するかを、$z$ ごとにまとめて調べる。
3. **誘導閉路**：検査に失敗した $y - x - z$（$y, z$ は隣接しない）について、$x$ と $x$ の隣（$z$ 以外）を通らない $y$ から $z$ への最短路を BFS で求め、$x$ を足す。

## 使い方

```cpp
auto res = chordal_graph(n, edges);
if (res.chordal) res.peo;     // 完全消去順序
else res.cycle;               // 誘導閉路 (長さ 4 以上)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `ChordalResult chordal_graph(int n, edges)` | 判定と証拠 | $O(n + m)$ |

## 注意

- 単純グラフであること。
