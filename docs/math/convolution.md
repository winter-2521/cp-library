---
title: 畳み込み (NTT)
documentation_of: //math/convolution.hpp
---

## 概要

$c_k = \sum_{i + j = k} a_i b_j$ を数論変換 (NTT) で $O((n + m) \log (n + m))$ で求める。

- `convolve<mint>(a, b)`：mod が NTT 向きの素数（$998244353$ など、$\mathrm{mod} - 1$ が大きな 2 冪で割り切れる）のとき。原始根はコンパイル時に求める。
- `convolve_ll(a, b)`：整数のまま（結果が `long long` に収まること）。3 つの素数で NTT して中国剰余定理で復元。
- `convolve_small(a, b)`：非負整数で結果が $7.5 \times 10^{17}$ 未満と分かっているとき。2 つの素数で済むので速い。

短い列では素朴な $O(nm)$ の方が速いので自動で切り替える。自分自身との畳み込み（2 乗）は変換を 1 回省く。

## 使い方

```cpp
vector<mint> c = convolve(a, b);                 // mint = ModInt998244353 など
vector<long long> d = convolve_ll(x, y);
vector<long long> e = convolve_small(x, y);      // 非負，結果 < 7.5e17
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `vector<mint> convolve(a, b)` | mod 上の畳み込み | $O(N \log N)$ |
| `vector<long long> convolve_ll(a, b)` | 整数の畳み込み | $O(N \log N)$ |
| `vector<long long> convolve_small(a, b)` | 非負・小さい結果の整数の畳み込み | $O(N \log N)$ |

## 注意

- 名前は ACL の `convolution` と衝突しないように `convolve` にしてある。
- NTT は基本的な基数 2 の実装。
