---
title: 二部グラフの最大マッチング (Bipartite Matching)
documentation_of: //graph/bipartite_matching.hpp
---

## 概要

左 $L$ 頂点・右 $R$ 頂点の二部グラフで、端点を共有しない辺をできるだけ多く選ぶ（最大マッチング）。$O(m\sqrt{n})$。

1. **Karp-Sipser の貪欲**で初期マッチングを作る。残りの次数が 1 の頂点はその唯一の相手と組ませても最適性を損なわないので先に組み、なければ適当に組む。
2. 左の未マッチ頂点全部から同時に BFS し、各頂点に「どの始点から来たか (root)」を付ける。未マッチの右頂点に着いたらその場で増加路を反転し、同じ root からの探索は打ち切る。1 回 $O(m)$ で互いに素な増加路がまとめて取れる。
3. 2 を $\sqrt{n}$ 回やっても終わらなければ **Hopcroft-Karp**（最短増加路の層に沿った DFS）に切り替え、計算量 $O(m\sqrt{n})$ を保証する。

Library Checker の最悪ケース（augmented_cycle）で Hopcroft-Karp 単体の約 3 倍速い。

## 使い方

```cpp
BipartiteMatching bm(L, R);
bm.reserve(m);                // 任意
bm.add_edge(a, b);            // 左 a (0..L-1) と右 b (0..R-1)
int k = bm.solve();           // 最大マッチングの大きさ
for (auto [a, b] : bm.matching()) { ... }
bm.match_l[a], bm.match_r[b]; // 相手 (いなければ -1)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `BipartiteMatching(int L, int R)` | 空のグラフ | $O(1)$ |
| `void add_edge(int a, int b)` | 辺を追加 | 償却 $O(1)$ |
| `int solve()` | 最大マッチングを求めて大きさを返す | $O(m\sqrt{n})$ |
| `vector<pair<int,int>> matching()` | マッチングの辺 (左, 右) | $O(L)$ |

## 注意

- `solve()` は 1 回だけ呼ぶ（呼ぶたびに作り直す）。
- 多重辺があってもよい。
