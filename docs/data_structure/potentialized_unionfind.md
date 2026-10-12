---
title: ポテンシャル付き Union-Find (非可換群対応)
documentation_of: //data_structure/potentialized_unionfind.hpp
---

## 概要

各要素 $u$ に群 $G$ の元 $a_u$ を持たせ、「$a_u = a_v w$」という関係の追加・矛盾判定と、同じ集合に属する 2 要素の $a_v^{-1} a_u$ の取得を行う。
$G$ は **非可換群でもよい**。加法群なら「$a_u - a_v = w$」、xor なら「$a_u \oplus a_v = w$」という意味になる。向きは Library Checker と同じ。

union by size と経路圧縮を併用している。頂点は 0-indexed。
[`weighted_dsu.hpp`](weighted_dsu.hpp) と違い、矛盾判定を `merge` の戻り値で返し、群を自由に差し替えられる。

## 使い方

```cpp
PotentializedUnionFind<AdditiveGroup<long long>> uf(n);
uf.merge(u, v, w);   // a_u = a_v w (加法なら a_u - a_v = w) を追加．矛盾したら false (状態は変わらない)
uf.same(u, v);
uf.diff(u, v);       // a_v^{-1} a_u (加法なら a_u - a_v)．同じ集合のときのみ
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
| `bool merge(int u, int v, T w)` | $a_u = a_v w$ を追加。矛盾すれば何もせず `false`、そうでなければ `true`（既知の関係でも `true`） | ならし $O(\alpha(n))$ |
| `T diff(int u, int v)` | $a_v^{-1} a_u$（加法なら $a_u - a_v$）。`same(u, v)` であること | ならし $O(\alpha(n))$ |
| `T potential(int x)` | $a_r^{-1} a_x$（$r$ は根） | ならし $O(\alpha(n))$ |
| `int leader(int x)` | 代表元 | ならし $O(\alpha(n))$ |
| `bool same(int x, int y)` | 同じ集合か | ならし $O(\alpha(n))$ |
| `int size(int x)` | 集合のサイズ | ならし $O(\alpha(n))$ |
| `vector<vector<int>> groups()` | 集合ごとの要素のリスト | $O(n\,\alpha(n))$ |

（計算量は群演算を $O(1)$ としたもの）

## 注意

- **向きに注意**：`merge(u, v, w)` は $a_u = a_v w$（加法なら $a_u - a_v = w$）、`diff(u, v)` は $a_v^{-1} a_u$。[`weighted_dsu.hpp`](weighted_dsu.hpp) とは向きが逆。
- `T` は `==` で比較できること（矛盾判定に使う）。
- `leader` は再帰で実装しているが、union by size なので深さは $O(\log n)$。
