---
title: 列の挿入・削除・反転・区間作用 (Dynamic Sequence, Splay 木)
documentation_of: //data_structure/dynamic_sequence.hpp
---

## 概要

列に対して、任意位置への挿入・削除・**区間反転**・区間作用・区間積を、ならし $O(\log n)$ で処理する（Splay 木）。値と作用は遅延セグメント木と同じ作用付きモノイド `AM`（[acted_monoid.hpp](../../algebra/acted_monoid.hpp)）。

- 両端に番兵を置き、区間 $[l, r)$ は「$l-1$ 番目を根に splay → $r$ 番目を根の右の子に splay」したときの、その左の子の部分木として取り出す。取り出した部分木の根に、反転フラグや作用を遅延で載せる。
- 反転は部分木の左右の子を入れ替える。非可換なモノイドで反転するときは逆順の積も持つ必要があるので、`COMMUTATIVE = false` を指定する。

## 使い方

```cpp
using AM = ActedAffineSum<mint>;
vector<AM::S> a(n);                   // a[i] = AM::make(x)
DynamicSequence<AM> seq(a);
seq.reserve(n + q);                   // 挿入の回数分の容量 (任意)
seq.insert(i, AM::make(x));           // i 番目の直前に挿入 (i = size() なら末尾)
seq.erase(i);
seq.reverse(l, r);
seq.apply(l, r, {b, c});
seq.prod(l, r).sum;
seq.get(i); seq.set(i, x);
seq.push_back(x); seq.push_front(x);
seq.size(); seq.all_prod(); seq.to_vector();

// 作用なしで反転と区間和だけ
DynamicSequence<ActedNone<MonoidSum<long long>>> s2(v);   // vector<long long> v
// 非可換なモノイドで反転する
DynamicSequence<ActedNone<MonoidAffine<mint>>, false> s3(fs);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `DynamicSequence<AM, COMMUTATIVE = true>(const vector<S> &a)` | 構築 | $O(n)$ |
| `void insert(int i, S x)` / `push_back` / `push_front` | 挿入 | ならし $O(\log n)$ |
| `void erase(int i)` | 削除 | ならし $O(\log n)$ |
| `void reverse(int l, int r)` | $[l, r)$ を反転 | ならし $O(\log n)$ |
| `void apply(int l, int r, F f)` | $[l, r)$ に作用 | ならし $O(\log n)$ |
| `S prod(int l, int r)` | 区間積（空なら `e()`） | ならし $O(\log n)$ |
| `S get(int i)` / `void set(int i, S x)` | 一点取得 / 更新 | ならし $O(\log n)$ |
| `int size()` | 要素数 | $O(1)$ |
| `vector<S> to_vector()` | 列全体（デバッグ用） | $O(n)$ |

## 注意

- 区間を反転するとき、モノイドが非可換なら `COMMUTATIVE = false` にすること（デフォルトの `true` だと逆順の積を持たないので、反転後の積がおかしくなる）。和・最小値などは可換なのでそのままでよい。
- 削除したノードは再利用しない（ノード数は 初期の長さ + 挿入回数）。
- 作用付きモノイドの書き方は [acted_monoid.hpp](../../algebra/acted_monoid.hpp)。作用が要らないときは `ActedNone<M>` でモノイド `M` を包む。
