---
title: 順序付き集合 (Ordered Set)
documentation_of: //data_structure/ordered_set.hpp
---

## 概要

集合に対して、挿入・削除・$k$ 番目の要素・$x$ 以下の要素の個数・$x$ 以下の最大の要素・$x$ 以上の最小の要素を $O(\log n)$ で処理する。
**オンライン** で動く（挿入する値を先読みする必要はない）。

各ノードが最大 $B$ 個の値をソート済み配列で持つ AVL 木。1 ノードを約 128 バイトにしてキャッシュ効率を上げ、ノード内は線形探索している。木の高さが $\log_2 (n / B)$ 程度になるので、`std::set` よりはるかに速い（`ordered_set` の最大ケースで手元 0.13 秒。座標圧縮 + FastSet + Fenwick Tree のオフライン解法 0.17 秒より速い）。

## 使い方

```cpp
OrderedSet<int> st;          // 空集合
OrderedSet<int> st2(a);      // vector から構築 (順不同・重複可)

st.insert(x);        // 挿入 (既にあれば何もしない)
st.erase(x);         // 削除 (なければ何もしない)
st.contains(x);
st.kth(k);           // 小さい方から k 番目 (0-indexed)．なければ -1
st.count_le(x);      // x 以下の個数   (count_lt: x 未満, count_range(lo, hi): [lo, hi))
st.max_le(x);        // x 以下の最大   (max_lt: x 未満)．なければ -1
st.min_ge(x);        // x 以上の最小   (min_gt: x より大)．なければ -1
st.min(); st.max(); st.size(); st.to_vector();
st.max_le(x, LLONG_MIN);  // 値が負にもなりうるなら「なし」を表す値を渡す
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `OrderedSet<T>()` | 空集合 | $O(1)$ |
| `OrderedSet<T>(vector<T> a)` | `a` の要素で初期化 | $O(n \log n)$（ソート済みなら $O(n)$） |
| `bool insert(T x)` | `x` を挿入。挿入したら `true`、既にあれば `false` | $O(\log n + B)$ |
| `bool erase(T x)` | `x` を削除。削除したら `true`、なければ `false` | $O(\log n + B)$ |
| `bool contains(T x)` / `size_t count(T x)` | `x` が含まれるか | $O(\log n + B)$ |
| `T kth(int k, T def = -1)` | 小さい方から $k$ 番目（0-indexed）。なければ `def` | $O(\log n)$ |
| `int count_le(T x)` / `int count_lt(T x)` | $x$ 以下 / 未満の要素数 | $O(\log n + B)$ |
| `int count_range(T lo, T hi)` | $[lo, hi)$ の要素数 | $O(\log n + B)$ |
| `T max_le(T x, T def = -1)` / `T max_lt(T x, T def = -1)` | $x$ 以下 / 未満の最大の要素。なければ `def` | $O(\log n + B)$ |
| `T min_ge(T x, T def = -1)` / `T min_gt(T x, T def = -1)` | $x$ 以上 / より大きい最小の要素。なければ `def` | $O(\log n + B)$ |
| `T min(T def = -1)` / `T max(T def = -1)` | 最小 / 最大の要素。空なら `def` | $O(\log n)$ |
| `int size()` / `bool empty()` | 要素数 / 空か | $O(1)$ |
| `vector<T> to_vector()` | 要素を昇順に列挙 | $O(n)$ |

$B$ はノードあたりの要素数（第 2 テンプレート引数。デフォルトは `int` で 28、`long long` で 14）。

## 注意

- 多重集合ではない（同じ値は 1 個まで）。
- `T` は `<` で比較できればよい（`pair` なども可）。
- `kth` は 0-indexed（「$x$ 番目」が 1-indexed の問題では `kth(x - 1)`）。
- 「なし」を表す値のデフォルトは `-1`。値が負になりうるときは `def` を明示する。
- 削除で要素数が少ないノードが残っても併合はしないので、挿入・削除を繰り返すと木が少し深くなることがある（高さはこれまでの挿入回数の対数で抑えられる）。
