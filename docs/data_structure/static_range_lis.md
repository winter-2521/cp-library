---
title: 区間 LIS (Static Range LIS Query, Seaweed 法)
documentation_of: //data_structure/static_range_lis.hpp
---

## 概要

静的な数列 $a$ について、区間 $[l, r)$ の **最長狭義増加部分列（LIS）の長さ** を、前計算 $O(n \log^2 n)$・クエリ $O(\log n)$ で答える（**オンライン**）。Tiskin の Seaweed 法。

- 列を位置、行を値とする $n \times n$ の格子で、$a_j$ = 行 のマスだけ「一致」とする LCS を考える。各マスで 2 本のひも（seaweed）が「一致なら交差しない、不一致なら **まだ交差していなければ** 交差する」というルールで流れる。
- 上辺の列 $j$ から入ったひもが下辺の列 $\mathrm{end}_j$ に出るとき、$\mathrm{LIS}(a[l..r)) = (r - l) - \#\{j \in [l, r) : \mathrm{end}_j < r\}$。これはウェーブレット行列で $O(\log n)$。
- ひもの行き先（置換）は、値で上下半分に分けて再帰的に求め、2 つを **unit-Monge 積（steady ant 法、$O(n \log n)$）** で合成する。全体 $O(n \log^2 n)$。

## 使い方

```cpp
StaticRangeLIS lis(a);   // vector<T> a (順列でなくてもよい．狭義増加で数える)
lis.query(l, r);         // a[l..r) の LIS の長さ
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `StaticRangeLIS(const vector<T> &a)` | 構築 | $O(n \log^2 n)$ |
| `int query(int l, int r)` | 区間 LIS の長さ（$l \ge r$ なら 0） | $O(\log n)$ |

内部の `seaweed_internal::sticky_product(a, b)` は、置換（始点 → 終点）$a$ を先に、$b$ を後に適用した 0-Hecke 積（ひもが 2 回交差しない合成）を返す。

## 注意

- 同じ値は「位置が後ろのものほど小さい」とみなして順列にしてから計算する（狭義増加になる）。広義増加で数えたいときは、同じ値を位置の昇順に小さくした順列を自分で作って渡す。
- 前計算の作業領域として約 $100n$ 個の int を一時的に使う。
