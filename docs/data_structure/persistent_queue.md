---
title: 永続キュー (Persistent Queue)
documentation_of: //data_structure/persistent_queue.hpp
---

## 概要

キューの **どの過去の版からでも** push / pop でき、新しい版を作る。

追加した要素を「親 = 追加する直前の末尾の要素」とする木で持つ。版は「末尾のノード」と「先頭の深さ」の組で表せ、先頭の要素は「末尾のノードの祖先のうち、深さが（先頭の深さ + 1）のもの」。

- push：末尾のノードの子として新しいノードを作る。$O(1)$。
- pop：先頭の深さを 1 増やすだけ。$O(1)$。
- front：祖先を求める。各ノードに **skew-binary の跳び先**（親の跳び先の跳び先、または親）を持たせると、祖先を $O(\log n)$ で求められる（ダブリングと違い、1 ノードあたり $O(1)$ のメモリ）。

## 使い方

```cpp
PersistentQueue<int> pq;
pq.reserve(q);
int v0 = pq.empty_version();     // 空のキュー
int v1 = pq.push(v0, 3);         // 新しい版の番号を返す
int v2 = pq.push(v1, 5);
pq.front(v2);                    // 3
int v3 = pq.pop(v2);             // [5]
pq.front(v2);                    // 3 (古い版はそのまま)
pq.size(v3); pq.empty(v3);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `int push(int v, T x)` | 版 $v$ の末尾に追加した版 | $O(1)$ |
| `int pop(int v)` | 版 $v$ の先頭を削除した版（空でないこと） | $O(1)$ |
| `T front(int v)` | 版 $v$ の先頭（空でないこと） | $O(\log n)$ |
| `int size(int v)` / `bool empty(int v)` | | $O(1)$ |
