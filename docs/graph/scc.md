---
title: 強連結成分分解 (SCC)
documentation_of: //graph/scc.hpp
---

## 概要

有向グラフを強連結成分に分解し、成分をトポロジカル順（辺 $u \to v$ があれば $u$ の成分が先）に並べる。Tarjan のアルゴリズムを非再帰で実装し、隣接は [CSR](csr.hpp) で持つ。$O(n + m)$。

## 使い方

```cpp
StronglyConnectedComponents scc(n);
scc.reserve(m);
scc.add_edge(u, v);
int k = scc.build();      // 成分の個数
scc.groups;               // vector<vector<int>>: トポロジカル順の成分
scc.comp[v];              // 頂点 v の成分番号 (groups の添字)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `void add_edge(int u, int v)` | 辺 $u \to v$ を追加 | $O(1)$ |
| `int build()` | 分解して成分数を返す | $O(n + m)$ |
