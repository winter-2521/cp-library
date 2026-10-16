---
title: 行列式
documentation_of: //math/determinant.hpp
---

## 概要

素数 mod 上の $n \times n$ 行列の行列式を、ガウスの消去法で上三角にして対角成分の積として求める。行を入れ替えたら符号を反転する。$O(n^3)$。

## 使い方

```cpp
vector<vector<mint>> a(n, vector<mint>(n));
mint d = determinant(a);
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `mint determinant(vector<vector<mint>> a)` | 行列式 | $O(n^3)$ |

## 注意

- mod は素数であること（ピボットの逆元を使う）。
