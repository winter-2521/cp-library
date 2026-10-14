---
title: 全体の積が取れる両端キュー (Foldable Deque)
documentation_of: //data_structure/foldable_deque.hpp
---

## 概要

モノイド `M` の列を両端キューとして持ち、両端への追加・両端の削除・**全体の積** をならし $O(1)$ で処理する。非可換なモノイドでもよい。積は「先頭から末尾の順」。

先頭側・末尾側の 2 本のスタックにそれぞれ累積積を積む。片方が空のときにそちら側から削除が来たら、もう片方の要素を **半分ずつ** に分けて両方作り直す。半分に分けるので、作り直しにかかる時間は直前の作り直し以降の操作回数でならせて、ならし $O(1)$ になる（全部移すと、両端から交互に削除されたとき毎回 $O(n)$ かかってしまう）。

## 使い方

```cpp
FoldableDeque<MonoidAffine<mint>> deq;
deq.reserve(q);
deq.push_front(f); deq.push_back(f);
deq.pop_front(); deq.pop_back();
deq.front(); deq.back();
deq.all_prod()(x);    // f_{back}(...f_{front}(x))
deq.size(); deq.empty(); deq.clear();
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `void push_front(S x)` / `void push_back(S x)` | 追加 | $O(1)$ |
| `void pop_front()` / `void pop_back()` | 削除 | ならし $O(1)$ |
| `S front()` / `S back()` | 先頭 / 末尾 | $O(1)$ |
| `S all_prod()` | 先頭から末尾の順の積（空なら `e()`） | $O(1)$ |
| `int size()` / `bool empty()` / `void clear()` / `void reserve(int n)` | | $O(1)$ |

## 注意

- 削除・`front` / `back` は空でないときに呼ぶこと。
- 片側からしか削除しないなら [FoldableQueue](foldable_queue.hpp) の方が少し速い。
