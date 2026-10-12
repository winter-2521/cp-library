---
title: 区間並列 Union-Find (Range Parallel Union-Find)
documentation_of: //data_structure/range_parallel_unionfind.hpp
---

## 概要

「$i = 0, \ldots, k-1$ について $a+i$ と $b+i$ を併合する」という操作を高速に処理する Union-Find。

段 $j$ の Union-Find は長さ $2^j$ の区間 $[i, i+2^j)$ を要素 $i$ として持つ。長さ $k$ の併合は、$2^j \le k$ となる最大の $j$ について長さ $2^j$ の区間 2 つ（先頭と末尾）の併合に分解する。段 $j$ で実際に併合が起きたら段 $j-1$ で前半同士・後半同士を併合する。各段で実際に併合が起きるのは高々 $n-1$ 回なので、全体で $O((n \log n + q)\,\alpha(n))$。

段 0 で実際に併合が起きるたびにコールバック `f(残った根, 吸収された根)` が呼ばれるので、成分ごとの値（和など）を管理できる。

クエリをまとめて先読みできるなら、`merge_offline` の方が速い（段を 1 つずつ処理するのでキャッシュに乗りやすい。$n = q = 5 \times 10^5$ で手元 0.47 秒 → 0.27 秒）。

## 使い方

```cpp
RangeParallelUnionFind uf(n);
uf.merge(a, b, k);                     // i = 0..k-1 について a+i と b+i を併合
uf.merge(a, b, k, [&](int r, int c) {  // 段 0 で併合が起きるたびに呼ばれる
    val[r] += val[c];                  // r が残った根, c が吸収された根
});
uf.leader(x); uf.same(x, y); uf.size(x);

// オフライン版：qs[t] = {a, b, k}．f(t, r, c) が t の昇順に呼ばれる
vector<array<int, 3>> qs = ...;
RangeParallelUnionFind::merge_offline(n, qs, [&](int t, int r, int c) { ... });
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `RangeParallelUnionFind(int n)` | 要素数 `n` で初期化 | $O(n \log n)$ |
| `void merge(int a, int b, int k, F f)` | $a+i$ と $b+i$ ($0 \le i < k$) を併合。段 0 の併合ごとに `f(r, c)` | 全体でならし $O((n \log n + q)\,\alpha(n))$ |
| `int leader(int x)` | 代表元 | ならし $O(\alpha(n))$ |
| `bool same(int x, int y)` | 同じ集合か | ならし $O(\alpha(n))$ |
| `int size(int x)` | `x` を含む集合のサイズ | ならし $O(\alpha(n))$ |
| `static void merge_offline(int n, const vector<array<int, 3>> &qs, F f)` | クエリ列 `qs[t] = {a, b, k}` を順に処理し、段 0 の併合ごとに `f(t, r, c)` を $t$ の昇順に呼ぶ | $O((n \log n + q)\,\alpha(n))$ |

## 注意

- $0 \le a, b$ かつ $a + k, b + k \le n$ であること。$k = 0$ や $a = b$ のときは何もしない。
- メモリは $O(n \log n)$（`merge_offline` は $O(n + q)$）。
- `merge_offline` の後の連結性は、コールバックで受け取った `(r, c)` を通常の Union-Find で併合すれば再現できる（`r`, `c` は段 0 の Union-Find の根）。
- コールバックの中で `uf` 自体を操作してはいけない（`leader` などの参照は可）。
