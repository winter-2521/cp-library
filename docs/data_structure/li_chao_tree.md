---
title: Li Chao Tree
documentation_of: //data_structure/li_chao_tree.hpp
---

## 概要

直線 $y = ax + b$・線分 $y = ax + b \ (x \in [l, r))$ の追加と、ある $x$ での最小値（最大値）を求める。

セグメント木の各ノードに直線を高々 1 本置く。ノードに新しい直線が来たら、ノードの中央の $x$ で比べて勝った方をノードに残し、負けた方は「負けた方が勝ちうる側」の子へ降ろす（2 直線は 1 回しか交わらないので、勝ちうるのは片側だけ）。$x$ での値は、根から $x$ の葉まで降りながら各ノードの直線の値の最小値を取る。

2 種類ある。

| | `DynamicLiChaoTree<T>(xlo, xhi)` | `LiChaoTree<T>(xs)` |
| --- | --- | --- |
| 対象の $x$ | $[x_{lo}, x_{hi})$ の全整数 | 先に与えた座標 `xs` のどれか |
| ノード | 必要な分だけ作る | 配列（完全二分木） |
| オンライン | ○ | 問い合わせる $x$ を先読みする必要がある |
| 速さ | 遅め（特に線分はノードが多い） | 速い |

## 使い方

```cpp
DynamicLiChaoTree<long long> lct(-1000000000, 1000000001);   // x ∈ [-1e9, 1e9]
DynamicLiChaoTree<long long, true> lct_max(lo, hi);          // 最大値
lct.add_line(a, b);            // y = a x + b
lct.add_segment(l, r, a, b);   // y = a x + b (x ∈ [l, r))
lct.get(x);                    // 最小値．何もなければ numeric_limits<T>::max() (最大値版は lowest())

LiChaoTree<long long> st(xs);  // 問い合わせる x を全部渡す (ソート・重複はあってよい)
st.add_line(a, b); st.add_segment(l, r, a, b);
st.get(x);                     // x は xs に含まれること
st.get_index(i);               // ソート済み座標の i 番目での値
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `DynamicLiChaoTree<T, MAX = false>(T xlo, T xhi)` | $x \in [x_{lo}, x_{hi})$ で初期化 | $O(1)$ |
| `LiChaoTree<T, MAX = false>(vector<T> xs)` | 座標 `xs` で初期化 | $O(n \log n)$ |
| `void add_line(T a, T b)` | 直線を追加 | $O(\log C)$ / $O(\log n)$ |
| `void add_segment(T l, T r, T a, T b)` | 線分を追加 | $O(\log^2 C)$ / $O(\log^2 n)$ |
| `T get(T x)` | $x$ での最小値（最大値） | $O(\log C)$ / $O(\log n)$ |

$C = x_{hi} - x_{lo}$、$n$ は座標の個数。

## 注意

- $ax + b$ が `T` に収まること（Library Checker の制約 $|a|, |x| \le 10^9, |b| \le 10^{18}$ なら `long long` で収まる）。
- 動的版で直線を追加すると新しいノードは高々 1 個。線分は $O(\log C)$ 個のノードを作るので、線分 $4 \times 10^5$ 本・$C = 2 \times 10^9$ で手元 400 MB 程度使う。座標を先読みできるなら `LiChaoTree` を使うこと（手元で約 6 倍速い）。
