---
title: テンプレート
documentation_of: //template.hpp
---

## 概要

各ライブラリが `#include` する共通ヘッダ。`<bits/stdc++.h>` と `using namespace std;`、よく使うマクロ・型エイリアスを定義する。
AC Library (`<atcoder/all>`) がインクルードパスにあれば自動で読み込む（`__has_include` で判定）。

## 定義されているもの

| 名前 | 内容 |
| --- | --- |
| `rep(i, n)` | `for (int i = 0; i < n; i++)` |
| `Rep(i, a, b)` | `for (int i = a; i < b; i++)` |
| `ALL(x)` | `(x).begin(), (x).end()` |
| `dbgv(x)` | コンテナの中身を空白区切りで出力 |
| `ll`, `ull` | `long long`, `unsigned long long` |
| `pii`, `pll` | `pair<int,int>`, `pair<ll,ll>` |
| `vint`, `vll` | `vector<int>`, `vector<ll>` |

## 注意

- `#pragma GCC optimize("Ofast,...,fast-math")` / `#pragma GCC target("avx2", ...)` はコメントアウトされている（QCfium 法を使うときだけ `/*/` を `//*/` に変えて有効化する）。有効化すると `fast-math` により浮動小数点の厳密な比較・`NaN` 判定が壊れることがあるので注意。
- `#pragma once` が無いが、各ライブラリは `#pragma once` 付きでこのファイルを 1 回だけ読み込む想定。
