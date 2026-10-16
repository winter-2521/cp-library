---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/associative_array.test.cpp
    title: test/associative_array.test.cpp
  - icon: ':x:'
    path: test/unittest/hash_map.test.cpp
    title: test/unittest/hash_map.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/winter-2521/cp-library
  bundledCode: "#line 1 \"template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#if __has_include(<atcoder/all>)\n#include <atcoder/all>\nusing namespace\
    \ atcoder;\n#endif\n// QCfium\u6CD5\u3092\u4F7F\u3046\u6642\u306F\u30B3\u30E1\u30F3\
    \u30C8\u30A2\u30A6\u30C8\u3092\u5916\u3059\n/*/\n#pragma GCC optimize(\"Ofast,unroll-loops,no-stack-protector,fast-math\"\
    )\n#pragma GCC target(\"avx2,bmi,bmi2,lzcnt,popcnt\")\n#pragma GCC target(\"avx,avx2,fma\"\
    )\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma\"\
    )\n//*/\n#define rep(i,n) for(int i=0;i<n;i++)\n#define Rep(i,a,b) for(int i=a;i<b;i++)\n\
    #define ALL(x) (x).begin(),(x).end()\n#define dbgv(x); for(auto now : x) cout\
    \ << now << \" \"; cout << endl;\n//using P = pair<int,int>;\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\ntypedef pair<int, int> pii;\ntypedef\
    \ pair<ll, ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line\
    \ 3 \"data_structure/hash_map.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u6574\u6570\u30AD\u30FC\u306E\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7\
    \ (\u30AA\u30FC\u30D7\u30F3\u30A2\u30C9\u30EC\u30B9\u6CD5\u30FB\u7DDA\u5F62\u63A2\
    \u67FB)\n// unordered_map \u3088\u308A\u5927\u5E45\u306B\u901F\u3044\uFF0E\u30AD\
    \u30FC\u306F 64 bit \u4EE5\u4E0B\u306E\u6574\u6570\u578B\ntemplate <class Key,\
    \ class Val>\nstruct HashMap {\n    static_assert(is_integral_v<Key>, \"HashMap:\
    \ Key must be an integral type\");\n\n    struct Slot {\n        Key key;\n  \
    \      Val val;\n    };\n\n    vector<Slot> slots;\n    vector<uint8_t> used;\n\
    \    uint32_t mask;\n    int shift;\n    size_t cnt = 0;\n    // \u30CF\u30C3\u30B7\
    \u30E5\u7528\u306E\u4E71\u6570 (\u5947\u6570)\uFF0E\u5B9F\u884C\u3054\u3068\u306B\
    \u5909\u308F\u308B\u306E\u3067\uFF0C\u72D9\u3044\u6483\u3061\u306E\u5165\u529B\
    \u3067\u885D\u7A81\u3055\u305B\u3089\u308C\u306B\u304F\u3044\n    uint64_t mul;\n\
    \n    HashMap(size_t reserve_size = 0) {\n        mul = uint64_t(chrono::steady_clock::now().time_since_epoch().count())\
    \ * 0x9E3779B97F4A7C15ULL | 1;\n        mul ^= uint64_t(reinterpret_cast<uintptr_t>(this))\
    \ << 1;\n        mul |= 1;\n        size_t cap = 16;\n        while (cap < reserve_size\
    \ * 2) cap <<= 1;\n        init(cap);\n    }\n\n    void init(size_t cap) {\n\
    \        slots.assign(cap, Slot{});\n        used.assign(cap, 0);\n        mask\
    \ = cap - 1;\n        shift = 64 - __builtin_ctzll(cap);\n    }\n\n    // multiply-shift\
    \ \u30CF\u30C3\u30B7\u30E5 (\u4E0A\u4F4D\u30D3\u30C3\u30C8\u3092\u4F7F\u3046)\n\
    \    uint32_t home(Key k) const { return uint32_t((uint64_t(k) * mul) >> shift);\
    \ }\n\n    // k \u304C\u3042\u308C\u3070\u305D\u306E\u4F4D\u7F6E\uFF0C\u306A\u3051\
    \u308C\u3070 k \u3092\u5165\u308C\u308B\u3079\u304D\u7A7A\u304D\u4F4D\u7F6E\u3092\
    \u8FD4\u3059\n    uint32_t locate(Key k) const {\n        uint32_t i = home(k);\n\
    \        while (used[i] && slots[i].key != k) i = (i + 1) & mask;\n        return\
    \ i;\n    }\n\n    void grow() {\n        vector<Slot> old_slots = std::move(slots);\n\
    \        vector<uint8_t> old_used = std::move(used);\n        init(old_slots.size()\
    \ * 2);\n        for (size_t i = 0; i < old_slots.size(); i++) {\n           \
    \ if (!old_used[i]) continue;\n            uint32_t j = home(old_slots[i].key);\n\
    \            while (used[j]) j = (j + 1) & mask;\n            used[j] = 1;\n \
    \           slots[j] = std::move(old_slots[i]);\n        }\n    }\n\n    size_t\
    \ size() const { return cnt; }\n    bool empty() const { return cnt == 0; }\n\n\
    \    // \u8981\u7D20\u6570 n \u307E\u3067\u518D\u30CF\u30C3\u30B7\u30E5\u306A\u3057\
    \u3067\u5165\u308B\u3088\u3046\u306B\u3059\u308B\n    void reserve(size_t n) {\n\
    \        while (slots.size() < n * 2) grow();\n    }\n\n    // k \u306B\u5BFE\u5FDC\
    \u3059\u308B\u5024\u3078\u306E\u53C2\u7167 (\u306A\u3051\u308C\u3070 Val() \u3092\
    \u633F\u5165\u3059\u308B)\n    Val &operator[](Key k) {\n        uint32_t i =\
    \ locate(k);\n        if (!used[i]) {\n            // \u8CA0\u8377\u7387 1/2 \u3092\
    \u8D85\u3048\u305F\u3089\u62E1\u5F35\n            if ((cnt + 1) * 2 > slots.size())\
    \ {\n                grow();\n                i = locate(k);\n            }\n\
    \            used[i] = 1;\n            slots[i].key = k;\n            slots[i].val\
    \ = Val();\n            cnt++;\n        }\n        return slots[i].val;\n    }\n\
    \n    bool contains(Key k) const { return used[locate(k)]; }\n    size_t count(Key\
    \ k) const { return contains(k); }\n\n    // k \u306B\u5BFE\u5FDC\u3059\u308B\u5024\
    \uFF0E\u306A\u3051\u308C\u3070 def\n    Val get(Key k, const Val &def = Val())\
    \ const {\n        uint32_t i = locate(k);\n        return used[i] ? slots[i].val\
    \ : def;\n    }\n\n    // k \u306B\u5BFE\u5FDC\u3059\u308B\u5024\u3078\u306E\u30DD\
    \u30A4\u30F3\u30BF\uFF0E\u306A\u3051\u308C\u3070 nullptr\n    Val *find(Key k)\
    \ {\n        uint32_t i = locate(k);\n        return used[i] ? &slots[i].val :\
    \ nullptr;\n    }\n\n    // k \u3092\u524A\u9664\u3059\u308B\uFF0E\u524A\u9664\
    \u3057\u305F\u3089 true\n    // \u7DDA\u5F62\u63A2\u67FB\u306A\u306E\u3067\uFF0C\
    \u5F8C\u308D\u306B\u7D9A\u304F\u8981\u7D20\u3092\u8A70\u3081\u76F4\u3059 (backward\
    \ shift deletion) \u3053\u3068\u3067\u5893\u6A19\u3092\u4F7F\u308F\u306A\u3044\
    \n    bool erase(Key k) {\n        uint32_t i = locate(k);\n        if (!used[i])\
    \ return false;\n        used[i] = 0;\n        cnt--;\n        uint32_t j = i;\n\
    \        while (true) {\n            j = (j + 1) & mask;\n            if (!used[j])\
    \ break;\n            uint32_t h = home(slots[j].key);\n            // j \u306E\
    \u8981\u7D20\u306E\u672C\u6765\u306E\u4F4D\u7F6E h \u304C (i, j] \u306E\u5916\u306B\
    \u3042\u308C\u3070 i \u306B\u79FB\u305B\u308B\n            if (((j - h) & mask)\
    \ >= ((j - i) & mask)) {\n                slots[i] = std::move(slots[j]);\n  \
    \              used[i] = 1;\n                used[j] = 0;\n                i =\
    \ j;\n            }\n        }\n        return true;\n    }\n\n    void clear()\
    \ {\n        fill(used.begin(), used.end(), 0);\n        cnt = 0;\n    }\n\n \
    \   // \u5168\u3066\u306E (key, val) \u3092 f(key, val) \u306B\u6E21\u3059 (\u9806\
    \u5E8F\u306F\u4E0D\u5B9A)\n    template <class F>\n    void for_each(F f) {\n\
    \        for (size_t i = 0; i < slots.size(); i++) if (used[i]) f(slots[i].key,\
    \ slots[i].val);\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u6574\u6570\u30AD\u30FC\u306E\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7\
    \ (\u30AA\u30FC\u30D7\u30F3\u30A2\u30C9\u30EC\u30B9\u6CD5\u30FB\u7DDA\u5F62\u63A2\
    \u67FB)\n// unordered_map \u3088\u308A\u5927\u5E45\u306B\u901F\u3044\uFF0E\u30AD\
    \u30FC\u306F 64 bit \u4EE5\u4E0B\u306E\u6574\u6570\u578B\ntemplate <class Key,\
    \ class Val>\nstruct HashMap {\n    static_assert(is_integral_v<Key>, \"HashMap:\
    \ Key must be an integral type\");\n\n    struct Slot {\n        Key key;\n  \
    \      Val val;\n    };\n\n    vector<Slot> slots;\n    vector<uint8_t> used;\n\
    \    uint32_t mask;\n    int shift;\n    size_t cnt = 0;\n    // \u30CF\u30C3\u30B7\
    \u30E5\u7528\u306E\u4E71\u6570 (\u5947\u6570)\uFF0E\u5B9F\u884C\u3054\u3068\u306B\
    \u5909\u308F\u308B\u306E\u3067\uFF0C\u72D9\u3044\u6483\u3061\u306E\u5165\u529B\
    \u3067\u885D\u7A81\u3055\u305B\u3089\u308C\u306B\u304F\u3044\n    uint64_t mul;\n\
    \n    HashMap(size_t reserve_size = 0) {\n        mul = uint64_t(chrono::steady_clock::now().time_since_epoch().count())\
    \ * 0x9E3779B97F4A7C15ULL | 1;\n        mul ^= uint64_t(reinterpret_cast<uintptr_t>(this))\
    \ << 1;\n        mul |= 1;\n        size_t cap = 16;\n        while (cap < reserve_size\
    \ * 2) cap <<= 1;\n        init(cap);\n    }\n\n    void init(size_t cap) {\n\
    \        slots.assign(cap, Slot{});\n        used.assign(cap, 0);\n        mask\
    \ = cap - 1;\n        shift = 64 - __builtin_ctzll(cap);\n    }\n\n    // multiply-shift\
    \ \u30CF\u30C3\u30B7\u30E5 (\u4E0A\u4F4D\u30D3\u30C3\u30C8\u3092\u4F7F\u3046)\n\
    \    uint32_t home(Key k) const { return uint32_t((uint64_t(k) * mul) >> shift);\
    \ }\n\n    // k \u304C\u3042\u308C\u3070\u305D\u306E\u4F4D\u7F6E\uFF0C\u306A\u3051\
    \u308C\u3070 k \u3092\u5165\u308C\u308B\u3079\u304D\u7A7A\u304D\u4F4D\u7F6E\u3092\
    \u8FD4\u3059\n    uint32_t locate(Key k) const {\n        uint32_t i = home(k);\n\
    \        while (used[i] && slots[i].key != k) i = (i + 1) & mask;\n        return\
    \ i;\n    }\n\n    void grow() {\n        vector<Slot> old_slots = std::move(slots);\n\
    \        vector<uint8_t> old_used = std::move(used);\n        init(old_slots.size()\
    \ * 2);\n        for (size_t i = 0; i < old_slots.size(); i++) {\n           \
    \ if (!old_used[i]) continue;\n            uint32_t j = home(old_slots[i].key);\n\
    \            while (used[j]) j = (j + 1) & mask;\n            used[j] = 1;\n \
    \           slots[j] = std::move(old_slots[i]);\n        }\n    }\n\n    size_t\
    \ size() const { return cnt; }\n    bool empty() const { return cnt == 0; }\n\n\
    \    // \u8981\u7D20\u6570 n \u307E\u3067\u518D\u30CF\u30C3\u30B7\u30E5\u306A\u3057\
    \u3067\u5165\u308B\u3088\u3046\u306B\u3059\u308B\n    void reserve(size_t n) {\n\
    \        while (slots.size() < n * 2) grow();\n    }\n\n    // k \u306B\u5BFE\u5FDC\
    \u3059\u308B\u5024\u3078\u306E\u53C2\u7167 (\u306A\u3051\u308C\u3070 Val() \u3092\
    \u633F\u5165\u3059\u308B)\n    Val &operator[](Key k) {\n        uint32_t i =\
    \ locate(k);\n        if (!used[i]) {\n            // \u8CA0\u8377\u7387 1/2 \u3092\
    \u8D85\u3048\u305F\u3089\u62E1\u5F35\n            if ((cnt + 1) * 2 > slots.size())\
    \ {\n                grow();\n                i = locate(k);\n            }\n\
    \            used[i] = 1;\n            slots[i].key = k;\n            slots[i].val\
    \ = Val();\n            cnt++;\n        }\n        return slots[i].val;\n    }\n\
    \n    bool contains(Key k) const { return used[locate(k)]; }\n    size_t count(Key\
    \ k) const { return contains(k); }\n\n    // k \u306B\u5BFE\u5FDC\u3059\u308B\u5024\
    \uFF0E\u306A\u3051\u308C\u3070 def\n    Val get(Key k, const Val &def = Val())\
    \ const {\n        uint32_t i = locate(k);\n        return used[i] ? slots[i].val\
    \ : def;\n    }\n\n    // k \u306B\u5BFE\u5FDC\u3059\u308B\u5024\u3078\u306E\u30DD\
    \u30A4\u30F3\u30BF\uFF0E\u306A\u3051\u308C\u3070 nullptr\n    Val *find(Key k)\
    \ {\n        uint32_t i = locate(k);\n        return used[i] ? &slots[i].val :\
    \ nullptr;\n    }\n\n    // k \u3092\u524A\u9664\u3059\u308B\uFF0E\u524A\u9664\
    \u3057\u305F\u3089 true\n    // \u7DDA\u5F62\u63A2\u67FB\u306A\u306E\u3067\uFF0C\
    \u5F8C\u308D\u306B\u7D9A\u304F\u8981\u7D20\u3092\u8A70\u3081\u76F4\u3059 (backward\
    \ shift deletion) \u3053\u3068\u3067\u5893\u6A19\u3092\u4F7F\u308F\u306A\u3044\
    \n    bool erase(Key k) {\n        uint32_t i = locate(k);\n        if (!used[i])\
    \ return false;\n        used[i] = 0;\n        cnt--;\n        uint32_t j = i;\n\
    \        while (true) {\n            j = (j + 1) & mask;\n            if (!used[j])\
    \ break;\n            uint32_t h = home(slots[j].key);\n            // j \u306E\
    \u8981\u7D20\u306E\u672C\u6765\u306E\u4F4D\u7F6E h \u304C (i, j] \u306E\u5916\u306B\
    \u3042\u308C\u3070 i \u306B\u79FB\u305B\u308B\n            if (((j - h) & mask)\
    \ >= ((j - i) & mask)) {\n                slots[i] = std::move(slots[j]);\n  \
    \              used[i] = 1;\n                used[j] = 0;\n                i =\
    \ j;\n            }\n        }\n        return true;\n    }\n\n    void clear()\
    \ {\n        fill(used.begin(), used.end(), 0);\n        cnt = 0;\n    }\n\n \
    \   // \u5168\u3066\u306E (key, val) \u3092 f(key, val) \u306B\u6E21\u3059 (\u9806\
    \u5E8F\u306F\u4E0D\u5B9A)\n    template <class F>\n    void for_each(F f) {\n\
    \        for (size_t i = 0; i < slots.size(); i++) if (used[i]) f(slots[i].key,\
    \ slots[i].val);\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/hash_map.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/unittest/hash_map.test.cpp
  - test/associative_array.test.cpp
documentation_of: data_structure/hash_map.hpp
layout: document
title: "\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7 (Hash Map)"
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
