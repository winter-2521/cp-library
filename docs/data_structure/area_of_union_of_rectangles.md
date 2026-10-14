---
title: 長方形の和集合の面積 (Area of Union of Rectangles)
documentation_of: //data_structure/area_of_union_of_rectangles.hpp
---

## 概要

$n$ 個の長方形の和集合の面積を $O(n \log n)$ で求める。

$x$ の小さい順に長方形の左端（追加）・右端（削除）を処理し、$y$ 方向を「覆っている長方形の数」で管理するセグメント木で、隣り合うイベントの間の幅 × 覆われている $y$ の長さ を足していく。

セグメント木の各ノードは

- `cnt`：ノードの区間 **全体** をちょうど覆っている長方形の数（子には伝えない）
- `cov`：ノードの区間のうち覆われている長さ ＝ `cnt > 0` ならノードの区間の長さ、そうでなければ子の `cov` の和

を持つ。追加と削除は必ず対になって同じノードの集合に来るので、遅延伝播がいらない。

## 使い方

```cpp
vector<long long> l(n), d(n), r(n), u(n);   // 長方形 i は [l[i], r[i]] × [d[i], u[i]]
long long area = area_of_union_of_rectangles(l, d, r, u);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `T area_of_union_of_rectangles(l, d, r, u)` | 和集合の面積 | $O(n \log n)$ |

## 注意

- 面積が `T` に収まること（座標 $10^9$ なら面積は $10^{18}$ 以下で `long long` に収まる）。
