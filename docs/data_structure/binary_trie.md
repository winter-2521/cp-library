---
title: 2 分トライ (Binary Trie)
documentation_of: //data_structure/binary_trie.hpp
---

## 概要

$[0, 2^{\mathrm{LOG}})$ の非負整数の **多重集合** を、上位ビットから見た 2 分木で持つ。各ノードは部分木の要素数を持つ。
「全要素に $x$ を xor した集合」に対する最小値・最大値・$k$ 番目・$a$ 未満の個数を、どれも根から 1 本降りるだけで $O(\mathrm{LOG})$ で求められる（xor の各ビットが 1 なら左右の子を入れ替えて見ればよい）。

## 使い方

```cpp
BinaryTrie<30> trie;                 // [0, 2^30)．値の型は unsigned int
BinaryTrie<64, unsigned long long> t64;
trie.reserve(q * 30 + 1);            // ノード数の上限 (任意)
trie.insert(x);       trie.insert(x, k);   // k 個追加
trie.erase(x);        trie.erase(x, k);    // k 個削除 (入っていること)
trie.insert_unique(x);   // 入っていなければ追加 (追加したら true)
trie.erase_one(x);       // 入っていれば 1 個削除 (削除したら true)
trie.count(x);
trie.xor_min(x);  trie.xor_max(x);    // min / max (x xor y)
trie.kth(k, x);                       // (y xor x) の k 番目に小さい値 (0-indexed)
trie.count_less(a, x);                // (y xor x) < a となる y の個数
trie.min(); trie.max();               // 最小値 / 最大値
trie.size(); trie.empty();
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `void insert(T x, int k = 1)` / `void erase(T x, int k = 1)` | 追加 / 削除 | $O(\mathrm{LOG})$ |
| `bool insert_unique(T x)` / `bool erase_one(T x)` | 集合として追加 / 削除 | $O(\mathrm{LOG})$ |
| `int count(T x)` | $x$ の個数 | $O(\mathrm{LOG})$ |
| `T xor_min(T x)` / `T xor_max(T x)` | $\min / \max_{y} (x \oplus y)$ | $O(\mathrm{LOG})$ |
| `T kth(int k, T x = 0)` | $\{y \oplus x\}$ の $k$ 番目（0-indexed） | $O(\mathrm{LOG})$ |
| `int count_less(T a, T x = 0)` | $\#\{y : (y \oplus x) < a\}$ | $O(\mathrm{LOG})$ |
| `T min(T x = 0)` / `T max(T x = 0)` | $\{y \oplus x\}$ の最小 / 最大 | $O(\mathrm{LOG})$ |

## 注意

- `xor_min` / `xor_max` / `kth` / `min` / `max` は空でないときに呼ぶこと。
- 削除してもノードは消さない（個数 0 のまま残る）。ノード数は追加した値の種類数 × LOG で抑えられる。
