---
title: 部分集合畳み込み (Subset Convolution)
documentation_of: //math/subset_convolution.hpp
---

## 概要

長さ $2^n$ の列 $f, g$ について $h(S) = \sum_{T \subseteq S} f(T)\, g(S \setminus T)$ を $O(n^2 2^n)$ で求める。

ランク付きゼータ変換 $\hat f(S)[d] = \sum_{T \subseteq S, |T| = d} f(T)$ を取ると、各 $S$ で $\hat h(S) = \hat f(S) \cdot \hat g(S)$（$d$ についての多項式の積）になる。メビウス変換で戻し、$\hat h(S)[|S|]$ を取り出す。

$\hat f(S)[d]$ が 0 でないのは $d \le |S|$ だけ、最後に使うのは $d \ge |S|$ の段だけ、という範囲の絞り込みと、積和を 64 bit のまま足す遅延剰余で定数倍を軽くしている。

## 使い方

```cpp
vector<mint> h = subset_convolution(f, g);   // f, g の長さは同じ 2 冪
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<mint> subset_convolution(f, g)` | 部分集合畳み込み | $O(n^2 2^n)$ |

内部の `ranked_zeta`, `ranked_multiply`, `ranked_mobius` も `subset_convolution_internal` 名前空間から使える（同じ $g$ と何度も畳み込むときに $g$ の変換を使い回せる）。

## 注意

- `mint::mod()` が $2^{30}$ 未満であることを仮定している。
