---
title: ウェーブレット行列 (Wavelet Matrix)
documentation_of: //data_structure/wavelet_matrix.hpp
---

## 概要

静的な数列に対して、区間 $k$ 番目の値・区間内の $x$ 未満の個数・区間内の $x$ 未満の最大値などを $O(\log \sigma)$ で求める（$\sigma$ は値の種類数）。値は内部で座標圧縮する。

値を 2 進数で見て、上のビットから順に「そのビットが 0 のものを前、1 のものを後ろ」に安定ソートした列を各段で持つ。各段のビット列の rank（$[0, i)$ の 1 の個数）が $O(1)$ で求まれば、区間 $[l, r)$ が次の段のどこに移るかが $O(1)$ で分かる。
ビット列は 64 bit ごとに「ビット列と、それより前の 1 の個数」を隣り合わせて持ち、rank を 1 回のメモリアクセス + popcount で求める。

## 使い方

```cpp
WaveletMatrix<int> wm(a);
wm.kth_smallest(l, r, k);    // a[l..r) で小さい方から k 番目 (0-indexed)
wm.kth_largest(l, r, k);
wm.count_lt(l, r, x);        // a[l..r) の x 未満の個数 (count_le, count(l, r, x), count_range(l, r, lo, hi))
wm.max_lt(l, r, x);          // a[l..r) の x 未満の最大値．なければ -1 (max_le, min_ge, min_gt)
wm.access(i);                // a[i]
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `WaveletMatrix<T>(const vector<T> &a)` | 構築 | $O(n \log \sigma)$ |
| `T access(int i)` / `operator[]` | $a_i$ | $O(\log \sigma)$ |
| `T kth_smallest(int l, int r, int k)` / `kth_largest` | 区間 $k$ 番目（0-indexed） | $O(\log \sigma)$ |
| `int count_lt / count_le(int l, int r, T x)` | 区間内の $x$ 未満 / 以下の個数 | $O(\log \sigma)$ |
| `int count(int l, int r, T x)` / `count_range(l, r, lo, hi)` | $x$ の個数 / $[lo, hi)$ の個数 | $O(\log \sigma)$ |
| `T max_lt / max_le / min_ge / min_gt(int l, int r, T x, T def = -1)` | 区間内の前後の値（なければ `def`） | $O(\log \sigma)$ |

## 注意

- 静的（構築後に値を変えられない）。
- `kth_smallest` は $0 \le k < r - l$ であること。
