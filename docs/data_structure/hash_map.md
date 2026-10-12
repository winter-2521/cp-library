---
title: ハッシュマップ (Hash Map)
documentation_of: //data_structure/hash_map.hpp
---

## 概要

整数キー専用のハッシュマップ。オープンアドレス法（線形探査）で、`std::unordered_map` よりかなり速い。

- ハッシュは multiply-shift（乗数は実行ごとにランダムな奇数）なので、狙い撃ちの入力で衝突させられにくい。
- 負荷率が $1/2$ を超えたら容量を 2 倍にする。
- 削除は墓標を使わず、後ろに続く要素を詰め直す（backward shift deletion）ので、削除を繰り返しても遅くならない。

## 使い方

```cpp
HashMap<long long, int> mp;          // キーは 64 bit 以下の整数型
HashMap<long long, int> mp2(1 << 20);  // 要素数の見込みを渡すと再ハッシュを避けられる
mp[k] = v;                           // なければ Val() を挿入して参照を返す
mp[k] += 1;
mp.get(k, -1);                       // 値 (なければ -1．挿入はしない)
mp.contains(k); mp.count(k);
if (auto p = mp.find(k)) *p += 1;    // 値へのポインタ (なければ nullptr)
mp.erase(k);
mp.size(); mp.empty(); mp.clear(); mp.reserve(n);
mp.for_each([&](long long k, int &v) { ... });  // 全要素 (順不同)
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `HashMap<Key, Val>(size_t reserve_size = 0)` | 空のマップ。`reserve_size` 要素まで再ハッシュしない | $O(\text{容量})$ |
| `Val &operator[](Key k)` | `k` の値への参照（なければ `Val()` を挿入） | 期待 $O(1)$ |
| `Val get(Key k, Val def = Val())` | `k` の値（なければ `def`、挿入はしない） | 期待 $O(1)$ |
| `bool contains(Key k)` / `size_t count(Key k)` | `k` があるか | 期待 $O(1)$ |
| `Val *find(Key k)` | 値へのポインタ（なければ `nullptr`） | 期待 $O(1)$ |
| `bool erase(Key k)` | `k` を削除。削除したら `true` | 期待 $O(1)$ |
| `size_t size()` / `bool empty()` | 要素数 / 空か | $O(1)$ |
| `void reserve(size_t n)` | `n` 要素まで再ハッシュしないよう拡張 | $O(n)$ |
| `void clear()` | 全削除（容量はそのまま） | $O(\text{容量})$ |
| `void for_each(F f)` | 全要素について `f(key, val)`（順不同） | $O(\text{容量})$ |

## 注意

- キーは整数型のみ（`pair` などは 64 bit に詰めてから使う）。
- `operator[]` で挿入が起きると拡張により **参照・ポインタが無効になる** ことがある。
- 容量は縮まないので、`clear()` はそれまでの最大容量に比例した時間がかかる。
