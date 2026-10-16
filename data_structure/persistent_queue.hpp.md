---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/persistent_queue.test.cpp
    title: test/persistent_queue.test.cpp
  - icon: ':x:'
    path: test/unittest/persistent.test.cpp
    title: test/unittest/persistent.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ 3 \"data_structure/persistent_queue.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u6C38\u7D9A\u30AD\u30E5\u30FC (Persistent Queue)\uFF0E\u3069\u306E\u7248\
    \u306B\u3082 push / pop \u3067\u304D\uFF0C\u65B0\u3057\u3044\u7248\u306E\u756A\
    \u53F7\u3092\u8FD4\u3059\n// \u8FFD\u52A0\u3057\u305F\u8981\u7D20\u3092\u300C\u89AA\
    \ = 1 \u3064\u524D\u306E\u672B\u5C3E\u300D\u3068\u3059\u308B\u6728\u3067\u6301\
    \u3061\uFF0C\u7248\u306F (\u672B\u5C3E\u306E\u30CE\u30FC\u30C9, \u5148\u982D\u306E\
    \u6DF1\u3055) \u306E\u7D44\uFF0E\n// \u5148\u982D\u306E\u8981\u7D20 = \u672B\u5C3E\
    \u306E\u30CE\u30FC\u30C9\u306E\u7956\u5148\u306E\u3046\u3061\u6DF1\u3055\u304C\
    \ \u5148\u982D\u306E\u6DF1\u3055 + 1 \u306E\u3082\u306E\uFF0E\u7956\u5148\u306F\
    \ skew-binary \u306E\u8DF3\u3073\u5148\u3067 O(log n) \u3067\u6C42\u3081\u308B\
    \n// push O(1)\uFF0Cpop\u30FBfront O(log n)\ntemplate <class T>\nstruct PersistentQueue\
    \ {\n    struct Node {\n        T val;\n        int par, jump, depth;\n    };\n\
    \    vector<Node> nodes;                 // nodes[0] \u306F\u6839 (\u6DF1\u3055\
    \ 0\uFF0C\u8981\u7D20\u306A\u3057)\n    vector<pair<int, int>> versions;    //\
    \ (\u672B\u5C3E\u306E\u30CE\u30FC\u30C9, \u5148\u982D\u306E\u6DF1\u3055)\uFF0E\
    versions[0] \u306F\u7A7A\u306E\u30AD\u30E5\u30FC\n\n    PersistentQueue() {\n\
    \        nodes.push_back({T(), 0, 0, 0});\n        versions.push_back({0, 0});\n\
    \    }\n\n    void reserve(int n) { nodes.reserve(n + 1), versions.reserve(n +\
    \ 1); }\n\n    // \u7A7A\u306E\u30AD\u30E5\u30FC\u306E\u7248\u306E\u756A\u53F7\
    \n    static constexpr int empty_version() { return 0; }\n\n    int size(int v)\
    \ const { return nodes[versions[v].first].depth - versions[v].second; }\n    bool\
    \ empty(int v) const { return size(v) == 0; }\n\n    // \u7248 v \u306E\u672B\u5C3E\
    \u306B x \u3092\u8FFD\u52A0\u3057\u305F\u7248\u3092\u4F5C\u308A\uFF0C\u305D\u306E\
    \u756A\u53F7\u3092\u8FD4\u3059\n    int push(int v, const T &x) {\n        auto\
    \ [tail, head] = versions[v];\n        int p = tail;\n        // skew-binary \u306E\
    \u8DF3\u3073\u5148: \u89AA\u306E\u8DF3\u3073\u5148\u306E\u8DF3\u3073\u5148\u3068\
    \u6DF1\u3055\u306E\u5DEE\u304C\u305D\u308D\u3063\u3066\u3044\u308C\u3070\u305D\
    \u3053\u3078\uFF0C\u3067\u306A\u3051\u308C\u3070\u89AA\n        int j = p, pj\
    \ = nodes[p].jump, dep = nodes[p].depth;\n        if (dep - nodes[pj].depth ==\
    \ nodes[pj].depth - nodes[nodes[pj].jump].depth) j = nodes[pj].jump;\n       \
    \ nodes.push_back({x, p, j, dep + 1});\n        versions.push_back({(int)nodes.size()\
    \ - 1, head});\n        return versions.size() - 1;\n    }\n\n    // \u7248 v\
    \ \u306E\u5148\u982D\u306E\u8981\u7D20 (\u7A7A\u3067\u306A\u3044\u3053\u3068)\n\
    \    T front(int v) const {\n        auto [tail, head] = versions[v];\n      \
    \  return nodes[ancestor(tail, head + 1)].val;\n    }\n\n    // \u7248 v \u306E\
    \u5148\u982D\u3092\u524A\u9664\u3057\u305F\u7248\u3092\u4F5C\u308A\uFF0C\u305D\
    \u306E\u756A\u53F7\u3092\u8FD4\u3059 (\u7A7A\u3067\u306A\u3044\u3053\u3068)\n\
    \    int pop(int v) {\n        auto [tail, head] = versions[v];\n        versions.push_back({tail,\
    \ head + 1});\n        return versions.size() - 1;\n    }\n\n  private:\n    //\
    \ \u30CE\u30FC\u30C9 x \u306E\u7956\u5148\u3067\u6DF1\u3055\u304C dep \u306E\u3082\
    \u306E\n    int ancestor(int x, int dep) const {\n        while (nodes[x].depth\
    \ > dep) {\n            int j = nodes[x].jump;\n            x = nodes[j].depth\
    \ >= dep ? j : nodes[x].par;\n        }\n        return x;\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// https://github.com/winter-2521/cp-library\n\
    \n// \u6C38\u7D9A\u30AD\u30E5\u30FC (Persistent Queue)\uFF0E\u3069\u306E\u7248\
    \u306B\u3082 push / pop \u3067\u304D\uFF0C\u65B0\u3057\u3044\u7248\u306E\u756A\
    \u53F7\u3092\u8FD4\u3059\n// \u8FFD\u52A0\u3057\u305F\u8981\u7D20\u3092\u300C\u89AA\
    \ = 1 \u3064\u524D\u306E\u672B\u5C3E\u300D\u3068\u3059\u308B\u6728\u3067\u6301\
    \u3061\uFF0C\u7248\u306F (\u672B\u5C3E\u306E\u30CE\u30FC\u30C9, \u5148\u982D\u306E\
    \u6DF1\u3055) \u306E\u7D44\uFF0E\n// \u5148\u982D\u306E\u8981\u7D20 = \u672B\u5C3E\
    \u306E\u30CE\u30FC\u30C9\u306E\u7956\u5148\u306E\u3046\u3061\u6DF1\u3055\u304C\
    \ \u5148\u982D\u306E\u6DF1\u3055 + 1 \u306E\u3082\u306E\uFF0E\u7956\u5148\u306F\
    \ skew-binary \u306E\u8DF3\u3073\u5148\u3067 O(log n) \u3067\u6C42\u3081\u308B\
    \n// push O(1)\uFF0Cpop\u30FBfront O(log n)\ntemplate <class T>\nstruct PersistentQueue\
    \ {\n    struct Node {\n        T val;\n        int par, jump, depth;\n    };\n\
    \    vector<Node> nodes;                 // nodes[0] \u306F\u6839 (\u6DF1\u3055\
    \ 0\uFF0C\u8981\u7D20\u306A\u3057)\n    vector<pair<int, int>> versions;    //\
    \ (\u672B\u5C3E\u306E\u30CE\u30FC\u30C9, \u5148\u982D\u306E\u6DF1\u3055)\uFF0E\
    versions[0] \u306F\u7A7A\u306E\u30AD\u30E5\u30FC\n\n    PersistentQueue() {\n\
    \        nodes.push_back({T(), 0, 0, 0});\n        versions.push_back({0, 0});\n\
    \    }\n\n    void reserve(int n) { nodes.reserve(n + 1), versions.reserve(n +\
    \ 1); }\n\n    // \u7A7A\u306E\u30AD\u30E5\u30FC\u306E\u7248\u306E\u756A\u53F7\
    \n    static constexpr int empty_version() { return 0; }\n\n    int size(int v)\
    \ const { return nodes[versions[v].first].depth - versions[v].second; }\n    bool\
    \ empty(int v) const { return size(v) == 0; }\n\n    // \u7248 v \u306E\u672B\u5C3E\
    \u306B x \u3092\u8FFD\u52A0\u3057\u305F\u7248\u3092\u4F5C\u308A\uFF0C\u305D\u306E\
    \u756A\u53F7\u3092\u8FD4\u3059\n    int push(int v, const T &x) {\n        auto\
    \ [tail, head] = versions[v];\n        int p = tail;\n        // skew-binary \u306E\
    \u8DF3\u3073\u5148: \u89AA\u306E\u8DF3\u3073\u5148\u306E\u8DF3\u3073\u5148\u3068\
    \u6DF1\u3055\u306E\u5DEE\u304C\u305D\u308D\u3063\u3066\u3044\u308C\u3070\u305D\
    \u3053\u3078\uFF0C\u3067\u306A\u3051\u308C\u3070\u89AA\n        int j = p, pj\
    \ = nodes[p].jump, dep = nodes[p].depth;\n        if (dep - nodes[pj].depth ==\
    \ nodes[pj].depth - nodes[nodes[pj].jump].depth) j = nodes[pj].jump;\n       \
    \ nodes.push_back({x, p, j, dep + 1});\n        versions.push_back({(int)nodes.size()\
    \ - 1, head});\n        return versions.size() - 1;\n    }\n\n    // \u7248 v\
    \ \u306E\u5148\u982D\u306E\u8981\u7D20 (\u7A7A\u3067\u306A\u3044\u3053\u3068)\n\
    \    T front(int v) const {\n        auto [tail, head] = versions[v];\n      \
    \  return nodes[ancestor(tail, head + 1)].val;\n    }\n\n    // \u7248 v \u306E\
    \u5148\u982D\u3092\u524A\u9664\u3057\u305F\u7248\u3092\u4F5C\u308A\uFF0C\u305D\
    \u306E\u756A\u53F7\u3092\u8FD4\u3059 (\u7A7A\u3067\u306A\u3044\u3053\u3068)\n\
    \    int pop(int v) {\n        auto [tail, head] = versions[v];\n        versions.push_back({tail,\
    \ head + 1});\n        return versions.size() - 1;\n    }\n\n  private:\n    //\
    \ \u30CE\u30FC\u30C9 x \u306E\u7956\u5148\u3067\u6DF1\u3055\u304C dep \u306E\u3082\
    \u306E\n    int ancestor(int x, int dep) const {\n        while (nodes[x].depth\
    \ > dep) {\n            int j = nodes[x].jump;\n            x = nodes[j].depth\
    \ >= dep ? j : nodes[x].par;\n        }\n        return x;\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/persistent_queue.hpp
  requiredBy: []
  timestamp: '2026-10-17 01:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unittest/persistent.test.cpp
  - test/persistent_queue.test.cpp
documentation_of: data_structure/persistent_queue.hpp
layout: document
title: "\u6C38\u7D9A\u30AD\u30E5\u30FC (Persistent Queue)"
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
