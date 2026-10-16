---
title: 最小費用 b-flow (Min Cost b-Flow)
documentation_of: //graph/min_cost_b_flow.hpp
---

## 概要

各頂点 $v$ の供給 $b_v$（負なら需要）、各辺 $e$ の流量の下限 $l_e$・上限 $u_e$・費用 $c_e$ が与えられたとき、

- 流量保存：$(\text{$v$ から出る流量}) - (\text{$v$ に入る流量}) = b_v$
- 容量制約：$l_e \le f_e \le u_e$

を満たす流し方 $f$ のうち $\sum c_e f_e$ が最小のものを求める。双対（ポテンシャル）も返す。**容量スケーリング法**で $O(m \log U \cdot (n + m) \log n)$（$U$ は容量・供給の最大値）、最後の双対の計算（Bellman-Ford）に $O(nm)$。

1. 下限 $l_e$ 分を先に流したことにして、供給を調整する。
2. $\Delta = 2^k, \dots, 1$ の順に、残余容量が $\Delta$ 以上の辺だけを見る。その段の始めに被約費用が負の辺は飽和させ、超過が $\Delta$ 以上の頂点から不足が $\Delta$ 以上の頂点へ、ポテンシャル付き Dijkstra の最短路で $\Delta$ ずつ流す。
3. 最後に残余グラフで Bellman-Ford をしてポテンシャル $p$（全ての残余辺で $c_e + p_{\mathrm{from}} - p_{\mathrm{to}} \ge 0$）を求める。

## 使い方

```cpp
MinCostBFlow<long long, long long> g(n);   // <容量の型, 費用の型>
g.add_supply(v, x);                        // 供給 (add_demand で需要)
int e = g.add_edge(s, t, lo, hi, cost);    // 辺番号
if (!g.solve()) { /* 実行不可能 */ }
__int128 c = g.cost();
g.flow(e);                                 // 辺 e の流量
g.potential(v);                            // 双対変数
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `MinCostBFlow(int n)` | 頂点数 $n$ | $O(n)$ |
| `void add_supply(int v, Cap x)` / `add_demand` | 供給・需要を足す | $O(1)$ |
| `int add_edge(int u, int v, Cap lo, Cap hi, Cost c)` | 辺を追加して番号を返す | $O(1)$ |
| `bool solve()` | 解く．実行不可能なら `false` | $O(m \log U (n + m) \log n + nm)$ |
| `__int128 cost()` | 最小費用 | $O(m)$ |
| `Cap flow(int e)` | 辺 $e$ の流量 | $O(1)$ |
| `Cost potential(int v)` | ポテンシャル | $O(1)$ |

## 注意

- 費用が負の辺・負閉路があってもよい（容量が有限なので最小値は存在する）。
- 費用の合計は `long long` を超えうるので `__int128` で返す。
- 普通の「$s$ から $t$ へ $F$ 流す最小費用流」は `add_supply(s, F)`, `add_demand(t, F)` とすればよい。
