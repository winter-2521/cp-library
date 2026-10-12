---
title: Union-Find (Disjoint Set Union)
documentation_of: //graph/dsu.hpp
---

## 概要

素集合を管理するデータ構造。「2 つの集合の併合」と「2 要素が同じ集合か判定」を高速に行う。
union by size と経路圧縮を併用している。頂点は 0-indexed。

## 使い方

```cpp
UnionFind uf(n);          // 要素 0, 1, ..., n-1 がそれぞれ単独の集合
uf.unite(x, y);           // x を含む集合と y を含む集合を併合
uf.same(x, y);            // x と y が同じ集合なら true
uf.find(x);               // x の属する集合の代表元
uf.size(x);               // x の属する集合の要素数
uf.groups();              // 集合ごとの要素の列挙 (vector<vector<int>>)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `UnionFind(int n)` | 要素数 `n` で初期化 | $O(n)$ |
| `int find(int x)` | 代表元を返す | ならし $O(\alpha(n))$ |
| `bool unite(int x, int y)` | 併合する。**新たに併合したら `true`、既に同じ集合なら `false`** | ならし $O(\alpha(n))$ |
| `bool same(int x, int y)` | 同じ集合か判定 | ならし $O(\alpha(n))$ |
| `int size(int x)` | `x` の属する集合のサイズ | ならし $O(\alpha(n))$ |
| `vector<vector<int>> groups()` | 各集合の要素を列挙（空集合は除く） | $O(n \alpha(n))$ |

$\alpha$ はアッカーマン関数の逆関数で、実用上は定数とみなせる。

## 注意

- ソース中のコメントでは `unite` の戻り値が「既に同じ集合に属すなら true」と書かれているが、実装は逆（新たに併合したとき `true`）。
- `find` は再帰で実装されているが、union by size を併用しているので木の高さは $O(\log n)$ に収まり、スタックオーバーフローの心配はない。
