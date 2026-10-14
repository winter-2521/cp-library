---
title: 辺の追加と強連結成分 (Incremental SCC)
documentation_of: //graph/incremental_scc.hpp
---

## 概要

有向グラフに辺 $0, 1, \ldots, m-1$ を順に追加していくとき、各辺 $i$ について「辺 $0, \ldots, t-1$ を追加した時点で、辺 $i$ の両端が同じ強連結成分になる最小の $t$」（ならなければ $m + 1$）を求める。辺を $t$ の小さい順に Union-Find でつなげば、各時点の強連結成分が分かる。

時刻について分割統治する。答えが $(l, r]$ にある辺の集合について、時刻 $\mathrm{mid}$ までに追加された辺で強連結成分分解し、

- 両端が同じ成分になった辺は答えが $\mathrm{mid}$ 以下 → $(l, \mathrm{mid}]$ へ
- それ以外の辺は端点を成分に縮約して $(\mathrm{mid}, r]$ へ

と振り分ける。各段で辺は 1 回ずつ見るので $O(m \log m)$。

## 使い方

```cpp
vector<pair<int, int>> edges;              // 追加する順
vector<int> t = incremental_scc(n, edges); // t[i]: 辺 i の両端が強連結になる時刻 (追加した辺の本数)．ならなければ m + 1
// 例: 時刻 k の強連結成分は「t[i] <= k の辺 i の両端を Union-Find でつないだもの」
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<int> incremental_scc(int n, edges)` | 各辺が成分の内側になる時刻 | $O(n + m \log m)$ |

## 注意

- **オフライン**（全ての辺を先読みできるときのみ）。
- $t[i] > i$（辺 $i$ は自分が追加されるまで使えない）。自己ループは $t[i] = i + 1$。
