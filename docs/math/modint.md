---
title: ModInt (法がコンパイル時定数の modint)
documentation_of: //math/modint.hpp
---

## 概要

法 `MOD` がコンパイル時定数の剰余類。`MOD` が定数なので `%` は乗算とシフトに最適化される。
インターフェースは ACL の `atcoder::static_modint` と揃えてある（`val()`, `mod()`, `raw()`, `pow()`, `inv()`）。名前の衝突を避けるため CamelCase にしている。

このライブラリで mod を使うもの（fastio など）は `val()` と `mod()` だけに依存するので、**自作 `ModInt` と ACL の modint のどちらでも動く**。

## 使い方

```cpp
using mint = ModInt998244353;      // ModInt<998244353>．ModInt1000000007 もある
mint a = 3, b = -1;                // 負の数も正しく変換される
a + b; a - b; a * b; a / b;        // 四則演算 (割り算は逆元をかける)
a += b; -a; ++a;
a.val();                           // 値 (0 <= val < MOD)
a.pow(n);                          // a^n (n < 0 なら逆元の -n 乗)
a.inv();                           // 逆元
mint::mod();                       // 法
mint::raw(x);                      // 0 <= x < MOD が分かっているとき剰余を取らずに作る
fin >> a; fout << a;               // fastio で読み書きできる (cin / cout も可)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `ModInt<MOD>(T x)` | 整数 `x` を剰余類に変換（負の数も可） | $O(1)$ |
| `+`, `-`, `*`, 単項 `-`, `++`, `--`, `==`, `!=` | 演算 | $O(1)$ |
| `/` | `r.inv()` をかける | $O(\log \mathrm{MOD})$ |
| `unsigned val()` | 値 | $O(1)$ |
| `mint pow(long long n)` | $a^n$（$n < 0$ なら $(a^{-1})^{-n}$） | $O(\log \lvert n \rvert)$ |
| `mint inv()` | 逆元（拡張ユークリッドの互除法） | $O(\log \mathrm{MOD})$ |
| `static int mod()` | 法 | $O(1)$ |
| `static mint raw(int x)` | 剰余を取らずに作る | $O(1)$ |

## 注意

- $1 \le \mathrm{MOD} < 2^{31}$。素数でなくてもよいが、`inv()` / `/` は $\gcd(v, \mathrm{MOD}) = 1$ のときのみ正しい（そうでなければ assert で落ちる）。
- 法を実行時に決める modint はまだない。
