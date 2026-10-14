---
title: 全体の積が取れるキュー (Foldable Queue / SWAG)
documentation_of: //data_structure/foldable_queue.hpp
---

## 概要

モノイド `M` の列をキューとして持ち、末尾への追加・先頭の削除・**全体の積** をならし $O(1)$ で処理する（Sliding Window Aggregation）。非可換なモノイドでもよい。積は「先頭から末尾の順」$a_{\text{front}} \cdots a_{\text{back}}$。

スタックを 2 本使う。

- 末尾側のスタックには追加された順に積み、その全体の積を 1 つだけ持つ。
- 先頭側のスタックには「その要素から先頭側スタックの底までの積」を積む。先頭側が空のときに削除が来たら、末尾側を全部移し替えて累積積を作り直す。

各要素は 1 回しか移し替えられないので、ならし $O(1)$。

## 使い方

```cpp
FoldableQueue<MonoidAffine<mint>> que;
que.reserve(q);
que.push(f);          // 末尾に追加
que.pop();            // 先頭を削除
que.front();          // 先頭
que.all_prod()(x);    // f_{back}(...f_{front}(x))
que.size(); que.empty(); que.clear();
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `void push(S x)` | 末尾に追加 | $O(1)$ |
| `void pop()` | 先頭を削除 | ならし $O(1)$ |
| `S front()` | 先頭 | ならし $O(1)$ |
| `S all_prod()` | 先頭から末尾の順の積（空なら `e()`） | $O(1)$ |
| `int size()` / `bool empty()` / `void clear()` / `void reserve(int n)` | | $O(1)$ |

## 注意

- `pop` / `front` は空でないときに呼ぶこと。
- 両端から出し入れしたいときは [FoldableDeque](foldable_deque.hpp)。
