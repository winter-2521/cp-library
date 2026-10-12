---
title: ポテンシャル付き Union-Find (非可換群対応)
documentation_of: //data_structure/potentialized_unionfind.hpp
---

## 概要

各要素 $x$ に群 $G$ の元 $a_x$ を持たせ、「$a_x^{-1} a_y = w$」という関係の追加・矛盾判定と、同じ集合に属する 2 要素の $a_x^{-1} a_y$ の取得を行う。
$G$ は **非可換群でもよい**。加法群なら「$a_y - a_x = w$」、xor なら「$a_x \oplus a_y = w$」という意味になる。

union by size と経路圧縮を併用している。頂点は 0-indexed。
[`weighted_dsu.hpp`](weighted_dsu.hpp) と違い、矛盾判定を `merge` の戻り値で返し、群を自由に差し替えられる。

## 使い方

```cpp
PotentializedUnionFind<AdditiveGroup<long long>> uf(n);  // a_y - a_x = w
uf.merge(x, y, w);   // a_x^{-1} a_y = w を追加．矛盾したら false (状態は変わらない)
uf.same(x, y);
uf.diff(x, y);       // a_x^{-1} a_y (同じ集合のときのみ)
uf.potential(x);     // a_r^{-1} a_x (r は x の集合の根)
uf.size(x); uf.leader(x); uf.groups();

// 群を自作する場合 (例: 2x2 行列の積)
struct G {
    using T = array<mint, 4>;
    static T op(const T &a, const T &b);  // a * b
    static T inv(const T &a);             // 逆元
    static T e();                         // 単位元
};
PotentializedUnionFind<G> uf2(n);
```

用意してある群: `AdditiveGroup<X>`（加法、modint も可）、`XorGroup<X>`（xor）。

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `PotentializedUnionFind<G>(int n)` | 要素数 `n` で初期化 | $O(n)$ |
| `bool merge(int x, int y, T w)` | $a_x^{-1} a_y = w$ を追加。矛盾すれば何もせず `false`、そうでなければ `true`（既知の関係でも `true`） | ならし $O(\alpha(n))$ |
| `T diff(int x, int y)` | $a_x^{-1} a_y$。`same(x, y)` であること | ならし $O(\alpha(n))$ |
| `T potential(int x)` | $a_r^{-1} a_x$（$r$ は根） | ならし $O(\alpha(n))$ |
| `int leader(int x)` | 代表元 | ならし $O(\alpha(n))$ |
| `bool same(int x, int y)` | 同じ集合か | ならし $O(\alpha(n))$ |
| `int size(int x)` | 集合のサイズ | ならし $O(\alpha(n))$ |
| `vector<vector<int>> groups()` | 集合ごとの要素のリスト | $O(n\,\alpha(n))$ |

（計算量は群演算を $O(1)$ としたもの）

## 注意

- **向きに注意**：`merge(x, y, w)` は $a_x^{-1} a_y = w$（加法なら $a_y - a_x = w$）。「$a_u = a_v \cdot x$」なら `merge(v, u, x)`。
- `T` は `==` で比較できること（矛盾判定に使う）。
- `leader` は再帰で実装しているが、union by size なので深さは $O(\log n)$。
