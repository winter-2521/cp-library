---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ordered_set.test.cpp
    title: test/ordered_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/ordered_set.test.cpp
    title: test/unittest/ordered_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    \ 3 \"data_structure/ordered_set.hpp\"\n\n// \u9806\u5E8F\u4ED8\u304D\u96C6\u5408\
    \ (\u30AA\u30F3\u30E9\u30A4\u30F3\u30FB\u5024\u306E\u5148\u8AAD\u307F\u4E0D\u8981\
    )\n// \u5404\u30CE\u30FC\u30C9\u304C\u6700\u5927 B \u500B\u306E\u5024\u3092\u30BD\
    \u30FC\u30C8\u6E08\u307F\u914D\u5217\u3067\u6301\u3064 AVL \u6728\uFF0E\n// 1\
    \ \u30CE\u30FC\u30C9\u3092 128 \u30D0\u30A4\u30C8\u7A0B\u5EA6\u306B\u3057\u3066\
    \u30AD\u30E3\u30C3\u30B7\u30E5\u52B9\u7387\u3092\u4E0A\u3052\uFF0C\u30CE\u30FC\
    \u30C9\u5185\u306F\u7DDA\u5F62\u63A2\u7D22\u3059\u308B\uFF0E\u5404\u64CD\u4F5C\
    \ O(log n)\n//\n// \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306E\u623B\u308A\
    \u5024\u306F def (\u7701\u7565\u6642 -1)\ntemplate <class T, int B = std::max(4,\
    \ int(112 / sizeof(T)))>\nstruct OrderedSet {\n    struct Node {\n        T data[B];\n\
    \        int left, right, total;  // total: \u90E8\u5206\u6728\u306E\u8981\u7D20\
    \u6570\n        short height, size;\n    };\n\n    vector<Node> t;\n    vector<int>\
    \ free_list;\n    int root = 0;\n\n    OrderedSet() { t.push_back(Node{}); } \
    \ // t[0] \u306F\u756A\u5175 (height = total = 0)\n\n    // \u521D\u671F\u8981\
    \u7D20 a (\u9806\u4E0D\u540C\u30FB\u91CD\u8907\u53EF) \u3067 O(n log n) \u69CB\
    \u7BC9 (\u30BD\u30FC\u30C8\u6E08\u307F\u306A\u3089 O(n))\n    OrderedSet(vector<T>\
    \ a) : OrderedSet() {\n        if (!is_sorted(a.begin(), a.end())) sort(a.begin(),\
    \ a.end());\n        a.erase(unique(a.begin(), a.end()), a.end());\n        int\
    \ n = a.size();\n        if (n == 0) return;\n        // \u5F8C\u304B\u3089\u633F\
    \u5165\u3067\u304D\u308B\u3088\u3046\u5C11\u3057\u4F59\u88D5\u3092\u6B8B\u3057\
    \u3066\u8A70\u3081\u308B\n        int bs = std::max(1, B * 6 / 7);\n        int\
    \ m = (n + bs - 1) / bs;\n        t.reserve(m + 1);\n        vector<int> ids(m);\n\
    \        for (int i = 0; i < m; i++) {\n            int v = ids[i] = new_node();\n\
    \            int l = i * bs, r = std::min(n, l + bs);\n            for (int j\
    \ = l; j < r; j++) t[v].data[j - l] = a[j];\n            t[v].size = r - l;\n\
    \        }\n        root = build(ids, 0, m);\n    }\n\n    int size() const {\
    \ return t[root].total; }\n    bool empty() const { return root == 0; }\n\n  \
    \  // x \u3092\u633F\u5165\u3059\u308B\uFF0E\u633F\u5165\u3057\u305F\u3089 true\uFF0C\
    \u65E2\u306B\u3042\u308C\u3070 false\n    bool insert(const T &x) {\n        done\
    \ = false;\n        root = insert(root, x);\n        return done;\n    }\n\n \
    \   // x \u3092\u524A\u9664\u3059\u308B\uFF0E\u524A\u9664\u3057\u305F\u3089 true\uFF0C\
    \u306A\u3051\u308C\u3070 false\n    bool erase(const T &x) {\n        done = false;\n\
    \        root = erase(root, x);\n        return done;\n    }\n\n    bool contains(const\
    \ T &x) const {\n        for (int v = root; v;) {\n            const Node &nd\
    \ = t[v];\n            if (x < nd.data[0]) v = nd.left;\n            else if (nd.data[nd.size\
    \ - 1] < x) v = nd.right;\n            else {\n                for (int i = 0;\
    \ i < nd.size; i++) if (!(nd.data[i] < x)) return !(x < nd.data[i]);\n       \
    \         return false;\n            }\n        }\n        return false;\n   \
    \ }\n    size_t count(const T &x) const { return contains(x); }\n\n    // \u5C0F\
    \u3055\u3044\u65B9\u304B\u3089 k \u756A\u76EE (0-indexed) \u306E\u8981\u7D20\uFF0E\
    k >= size() \u306A\u3089 def\n    T kth(int k, T def = T(-1)) const {\n      \
    \  if (k < 0 || k >= size()) return def;\n        for (int v = root;;) {\n   \
    \         const Node &nd = t[v];\n            int ls = t[nd.left].total;\n   \
    \         if (k < ls) v = nd.left;\n            else if (k < ls + nd.size) return\
    \ nd.data[k - ls];\n            else k -= ls + nd.size, v = nd.right;\n      \
    \  }\n    }\n\n    // x \u672A\u6E80\u306E\u8981\u7D20\u306E\u500B\u6570\n   \
    \ int count_lt(const T &x) const {\n        int res = 0;\n        for (int v =\
    \ root; v;) {\n            const Node &nd = t[v];\n            if (!(nd.data[0]\
    \ < x)) v = nd.left;\n            else if (nd.data[nd.size - 1] < x) res += nd.total\
    \ - t[nd.right].total, v = nd.right;\n            else {\n                int\
    \ i = 0;\n                while (nd.data[i] < x) i++;\n                return\
    \ res + t[nd.left].total + i;\n            }\n        }\n        return res;\n\
    \    }\n\n    // x \u4EE5\u4E0B\u306E\u8981\u7D20\u306E\u500B\u6570\n    int count_le(const\
    \ T &x) const {\n        int res = 0;\n        for (int v = root; v;) {\n    \
    \        const Node &nd = t[v];\n            if (x < nd.data[0]) v = nd.left;\n\
    \            else if (!(x < nd.data[nd.size - 1])) res += nd.total - t[nd.right].total,\
    \ v = nd.right;\n            else {\n                int i = 0;\n            \
    \    while (!(x < nd.data[i])) i++;\n                return res + t[nd.left].total\
    \ + i;\n            }\n        }\n        return res;\n    }\n\n    // [lo, hi)\
    \ \u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u306E\u500B\u6570\n    int count_range(const\
    \ T &lo, const T &hi) const { return lo < hi ? count_lt(hi) - count_lt(lo) : 0;\
    \ }\n\n    // x \u672A\u6E80\u306E\u6700\u5927\u306E\u8981\u7D20 (\u306A\u3051\
    \u308C\u3070 def)\n    T max_lt(const T &x, T def = T(-1)) const {\n        for\
    \ (int v = root; v;) {\n            const Node &nd = t[v];\n            if (!(nd.data[0]\
    \ < x)) v = nd.left;\n            else if (nd.data[nd.size - 1] < x) def = nd.data[nd.size\
    \ - 1], v = nd.right;\n            else {\n                int i = 1;\n      \
    \          while (nd.data[i] < x) i++;\n                return nd.data[i - 1];\n\
    \            }\n        }\n        return def;\n    }\n\n    // x \u4EE5\u4E0B\
    \u306E\u6700\u5927\u306E\u8981\u7D20 (\u306A\u3051\u308C\u3070 def)\n    T max_le(const\
    \ T &x, T def = T(-1)) const {\n        for (int v = root; v;) {\n           \
    \ const Node &nd = t[v];\n            if (x < nd.data[0]) v = nd.left;\n     \
    \       else if (!(x < nd.data[nd.size - 1])) def = nd.data[nd.size - 1], v =\
    \ nd.right;\n            else {\n                int i = 1;\n                while\
    \ (!(x < nd.data[i])) i++;\n                return nd.data[i - 1];\n         \
    \   }\n        }\n        return def;\n    }\n\n    // x \u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u306E\u8981\u7D20 (\u306A\u3051\u308C\u3070 def)\n    T min_ge(const T\
    \ &x, T def = T(-1)) const {\n        for (int v = root; v;) {\n            const\
    \ Node &nd = t[v];\n            if (!(nd.data[0] < x)) def = nd.data[0], v = nd.left;\n\
    \            else if (nd.data[nd.size - 1] < x) v = nd.right;\n            else\
    \ {\n                int i = 1;\n                while (nd.data[i] < x) i++;\n\
    \                return nd.data[i];\n            }\n        }\n        return\
    \ def;\n    }\n\n    // x \u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u8981\
    \u7D20 (\u306A\u3051\u308C\u3070 def)\n    T min_gt(const T &x, T def = T(-1))\
    \ const {\n        for (int v = root; v;) {\n            const Node &nd = t[v];\n\
    \            if (x < nd.data[0]) def = nd.data[0], v = nd.left;\n            else\
    \ if (!(x < nd.data[nd.size - 1])) v = nd.right;\n            else {\n       \
    \         int i = 1;\n                while (!(x < nd.data[i])) i++;\n       \
    \         return nd.data[i];\n            }\n        }\n        return def;\n\
    \    }\n\n    // \u6700\u5C0F\u306E\u8981\u7D20 / \u6700\u5927\u306E\u8981\u7D20\
    \ (\u7A7A\u306A\u3089 def)\n    T min(T def = T(-1)) const {\n        if (!root)\
    \ return def;\n        int v = root;\n        while (t[v].left) v = t[v].left;\n\
    \        return t[v].data[0];\n    }\n    T max(T def = T(-1)) const {\n     \
    \   if (!root) return def;\n        int v = root;\n        while (t[v].right)\
    \ v = t[v].right;\n        return t[v].data[t[v].size - 1];\n    }\n\n    // \u8981\
    \u7D20\u3092\u6607\u9806\u306B\u5217\u6319\n    vector<T> to_vector() const {\n\
    \        vector<T> res;\n        res.reserve(size());\n        auto dfs = [&](auto\
    \ self, int v) -> void {\n            if (!v) return;\n            self(self,\
    \ t[v].left);\n            res.insert(res.end(), t[v].data, t[v].data + t[v].size);\n\
    \            self(self, t[v].right);\n        };\n        dfs(dfs, root);\n  \
    \      return res;\n    }\n\n  private:\n    bool done = false;\n\n    int new_node()\
    \ {\n        int v;\n        if (!free_list.empty()) v = free_list.back(), free_list.pop_back();\n\
    \        else v = t.size(), t.emplace_back();\n        Node &nd = t[v];\n    \
    \    nd.left = nd.right = 0, nd.size = 0, nd.height = 1, nd.total = 0;\n     \
    \   return v;\n    }\n\n    int build(const vector<int> &ids, int l, int r) {\n\
    \        int m = (l + r) / 2, v = ids[m];\n        t[v].left = l < m ? build(ids,\
    \ l, m) : 0;\n        t[v].right = m + 1 < r ? build(ids, m + 1, r) : 0;\n   \
    \     update(v);\n        return v;\n    }\n\n    void update(int v) {\n     \
    \   Node &nd = t[v];\n        nd.height = std::max(t[nd.left].height, t[nd.right].height)\
    \ + 1;\n        nd.total = nd.size + t[nd.left].total + t[nd.right].total;\n \
    \   }\n    int balance_factor(int v) const { return t[t[v].left].height - t[t[v].right].height;\
    \ }\n\n    int rotate_right(int v) {\n        int l = t[v].left;\n        t[v].left\
    \ = t[l].right, t[l].right = v;\n        update(v), update(l);\n        return\
    \ l;\n    }\n    int rotate_left(int v) {\n        int r = t[v].right;\n     \
    \   t[v].right = t[r].left, t[r].left = v;\n        update(v), update(r);\n  \
    \      return r;\n    }\n    // update(v) \u6E08\u307F\u3067\u3042\u308B\u3053\
    \u3068\n    int balance(int v) {\n        int bf = balance_factor(v);\n      \
    \  if (bf == 2) {\n            if (balance_factor(t[v].left) < 0) t[v].left =\
    \ rotate_left(t[v].left);\n            return rotate_right(v);\n        }\n  \
    \      if (bf == -2) {\n            if (balance_factor(t[v].right) > 0) t[v].right\
    \ = rotate_right(t[v].right);\n            return rotate_left(v);\n        }\n\
    \        return v;\n    }\n\n    // \u30CE\u30FC\u30C9\u5185\u306B\u633F\u5165\
    \ (size < B \u3067\u3042\u308B\u3053\u3068)\uFF0E\u65E2\u306B\u3042\u308C\u3070\
    \ false\n    bool node_insert(Node &nd, const T &x) {\n        int i = 0;\n  \
    \      while (i < nd.size && nd.data[i] < x) i++;\n        if (i < nd.size &&\
    \ !(x < nd.data[i])) return false;\n        for (int j = nd.size; j > i; j--)\
    \ nd.data[j] = nd.data[j - 1];\n        nd.data[i] = x, nd.size++;\n        return\
    \ true;\n    }\n    bool node_erase(Node &nd, const T &x) {\n        int i = 0;\n\
    \        while (i < nd.size && nd.data[i] < x) i++;\n        if (i == nd.size\
    \ || x < nd.data[i]) return false;\n        for (int j = i + 1; j < nd.size; j++)\
    \ nd.data[j - 1] = nd.data[j];\n        nd.size--;\n        return true;\n   \
    \ }\n    // \u6E80\u676F\u306E\u30CE\u30FC\u30C9 v \u306E\u5F8C\u534A\u3092\u65B0\
    \u3057\u3044\u30CE\u30FC\u30C9\u306B\u79FB\u3057\u3066\uFF0C\u305D\u306E\u756A\
    \u53F7\u3092\u8FD4\u3059\n    int split(int v) {\n        int u = new_node();\n\
    \        constexpr int h = B / 2;\n        for (int i = 0; i < B - h; i++) t[u].data[i]\
    \ = t[v].data[h + i];\n        t[u].size = B - h, t[v].size = h;\n        return\
    \ u;\n    }\n\n    // \u90E8\u5206\u6728 v \u306E\u5168\u8981\u7D20\u3088\u308A\
    \u5C0F\u3055\u3044 x \u3092\u633F\u5165\u3059\u308B\n    int insert_leftmost(int\
    \ v, const T &x) {\n        if (t[v].left) {\n            int l = insert_leftmost(t[v].left,\
    \ x);\n            t[v].left = l;\n            update(v);\n            return\
    \ balance(v);\n        }\n        node_insert(t[v], x);\n        if (t[v].size\
    \ < B) {\n            update(v);\n            return v;\n        }\n        int\
    \ u = split(v);\n        t[u].left = v, t[u].right = t[v].right, t[v].right =\
    \ 0;\n        update(v), update(u);\n        return balance(u);\n    }\n\n   \
    \ int insert(int v, const T &x) {\n        if (!v) {\n            v = new_node();\n\
    \            t[v].data[0] = x, t[v].size = 1;\n            update(v);\n      \
    \      done = true;\n            return v;\n        }\n        if (t[v].left &&\
    \ x < t[v].data[0]) {\n            int l = insert(t[v].left, x);\n           \
    \ t[v].left = l;\n        } else if (t[v].right && t[v].data[t[v].size - 1] <\
    \ x) {\n            int r = insert(t[v].right, x);\n            t[v].right = r;\n\
    \        } else {\n            done = node_insert(t[v], x);\n            if (t[v].size\
    \ == B) {\n                if (t[v].right) {\n                    // \u6700\u5927\
    \u306E\u8981\u7D20\u3092\u53F3\u90E8\u5206\u6728\u306E\u5148\u982D\u306B\u56DE\
    \u3059\n                    T y = t[v].data[--t[v].size];\n                  \
    \  int r = insert_leftmost(t[v].right, y);\n                    t[v].right = r;\n\
    \                } else {\n                    int u = split(v);\n           \
    \         update(u);\n                    t[v].right = u;\n                }\n\
    \            }\n        }\n        update(v);\n        return balance(v);\n  \
    \  }\n\n    // \u90E8\u5206\u6728 v \u306E\u6700\u3082\u5DE6\u306E\u30CE\u30FC\
    \u30C9\u3092\u5207\u308A\u96E2\u3059 (u \u306B\u5165\u308C\u308B)\uFF0E\u6B8B\u3063\
    \u305F\u90E8\u5206\u6728\u306E\u6839\u3092\u8FD4\u3059\n    int cut_leftmost(int\
    \ v, int &u) {\n        if (!t[v].left) {\n            u = v;\n            return\
    \ t[v].right;\n        }\n        int l = cut_leftmost(t[v].left, u);\n      \
    \  t[v].left = l;\n        update(v);\n        return balance(v);\n    }\n\n \
    \   int erase(int v, const T &x) {\n        if (!v) return 0;\n        if (x <\
    \ t[v].data[0]) {\n            int l = erase(t[v].left, x);\n            t[v].left\
    \ = l;\n        } else if (t[v].data[t[v].size - 1] < x) {\n            int r\
    \ = erase(t[v].right, x);\n            t[v].right = r;\n        } else {\n   \
    \         done = node_erase(t[v], x);\n            if (t[v].size == 0) {\n   \
    \             // \u7A7A\u306B\u306A\u3063\u305F\u30CE\u30FC\u30C9\u3092\u6728\u304B\
    \u3089\u5916\u3059\n                free_list.push_back(v);\n                if\
    \ (!t[v].left || !t[v].right) return t[v].left ? t[v].left : t[v].right;\n   \
    \             int u = 0;\n                int r = cut_leftmost(t[v].right, u);\n\
    \                t[u].left = t[v].left, t[u].right = r;\n                update(u);\n\
    \                return balance(u);\n            }\n        }\n        update(v);\n\
    \        return balance(v);\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n// \u9806\u5E8F\u4ED8\u304D\
    \u96C6\u5408 (\u30AA\u30F3\u30E9\u30A4\u30F3\u30FB\u5024\u306E\u5148\u8AAD\u307F\
    \u4E0D\u8981)\n// \u5404\u30CE\u30FC\u30C9\u304C\u6700\u5927 B \u500B\u306E\u5024\
    \u3092\u30BD\u30FC\u30C8\u6E08\u307F\u914D\u5217\u3067\u6301\u3064 AVL \u6728\uFF0E\
    \n// 1 \u30CE\u30FC\u30C9\u3092 128 \u30D0\u30A4\u30C8\u7A0B\u5EA6\u306B\u3057\
    \u3066\u30AD\u30E3\u30C3\u30B7\u30E5\u52B9\u7387\u3092\u4E0A\u3052\uFF0C\u30CE\
    \u30FC\u30C9\u5185\u306F\u7DDA\u5F62\u63A2\u7D22\u3059\u308B\uFF0E\u5404\u64CD\
    \u4F5C O(log n)\n//\n// \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306E\u623B\
    \u308A\u5024\u306F def (\u7701\u7565\u6642 -1)\ntemplate <class T, int B = std::max(4,\
    \ int(112 / sizeof(T)))>\nstruct OrderedSet {\n    struct Node {\n        T data[B];\n\
    \        int left, right, total;  // total: \u90E8\u5206\u6728\u306E\u8981\u7D20\
    \u6570\n        short height, size;\n    };\n\n    vector<Node> t;\n    vector<int>\
    \ free_list;\n    int root = 0;\n\n    OrderedSet() { t.push_back(Node{}); } \
    \ // t[0] \u306F\u756A\u5175 (height = total = 0)\n\n    // \u521D\u671F\u8981\
    \u7D20 a (\u9806\u4E0D\u540C\u30FB\u91CD\u8907\u53EF) \u3067 O(n log n) \u69CB\
    \u7BC9 (\u30BD\u30FC\u30C8\u6E08\u307F\u306A\u3089 O(n))\n    OrderedSet(vector<T>\
    \ a) : OrderedSet() {\n        if (!is_sorted(a.begin(), a.end())) sort(a.begin(),\
    \ a.end());\n        a.erase(unique(a.begin(), a.end()), a.end());\n        int\
    \ n = a.size();\n        if (n == 0) return;\n        // \u5F8C\u304B\u3089\u633F\
    \u5165\u3067\u304D\u308B\u3088\u3046\u5C11\u3057\u4F59\u88D5\u3092\u6B8B\u3057\
    \u3066\u8A70\u3081\u308B\n        int bs = std::max(1, B * 6 / 7);\n        int\
    \ m = (n + bs - 1) / bs;\n        t.reserve(m + 1);\n        vector<int> ids(m);\n\
    \        for (int i = 0; i < m; i++) {\n            int v = ids[i] = new_node();\n\
    \            int l = i * bs, r = std::min(n, l + bs);\n            for (int j\
    \ = l; j < r; j++) t[v].data[j - l] = a[j];\n            t[v].size = r - l;\n\
    \        }\n        root = build(ids, 0, m);\n    }\n\n    int size() const {\
    \ return t[root].total; }\n    bool empty() const { return root == 0; }\n\n  \
    \  // x \u3092\u633F\u5165\u3059\u308B\uFF0E\u633F\u5165\u3057\u305F\u3089 true\uFF0C\
    \u65E2\u306B\u3042\u308C\u3070 false\n    bool insert(const T &x) {\n        done\
    \ = false;\n        root = insert(root, x);\n        return done;\n    }\n\n \
    \   // x \u3092\u524A\u9664\u3059\u308B\uFF0E\u524A\u9664\u3057\u305F\u3089 true\uFF0C\
    \u306A\u3051\u308C\u3070 false\n    bool erase(const T &x) {\n        done = false;\n\
    \        root = erase(root, x);\n        return done;\n    }\n\n    bool contains(const\
    \ T &x) const {\n        for (int v = root; v;) {\n            const Node &nd\
    \ = t[v];\n            if (x < nd.data[0]) v = nd.left;\n            else if (nd.data[nd.size\
    \ - 1] < x) v = nd.right;\n            else {\n                for (int i = 0;\
    \ i < nd.size; i++) if (!(nd.data[i] < x)) return !(x < nd.data[i]);\n       \
    \         return false;\n            }\n        }\n        return false;\n   \
    \ }\n    size_t count(const T &x) const { return contains(x); }\n\n    // \u5C0F\
    \u3055\u3044\u65B9\u304B\u3089 k \u756A\u76EE (0-indexed) \u306E\u8981\u7D20\uFF0E\
    k >= size() \u306A\u3089 def\n    T kth(int k, T def = T(-1)) const {\n      \
    \  if (k < 0 || k >= size()) return def;\n        for (int v = root;;) {\n   \
    \         const Node &nd = t[v];\n            int ls = t[nd.left].total;\n   \
    \         if (k < ls) v = nd.left;\n            else if (k < ls + nd.size) return\
    \ nd.data[k - ls];\n            else k -= ls + nd.size, v = nd.right;\n      \
    \  }\n    }\n\n    // x \u672A\u6E80\u306E\u8981\u7D20\u306E\u500B\u6570\n   \
    \ int count_lt(const T &x) const {\n        int res = 0;\n        for (int v =\
    \ root; v;) {\n            const Node &nd = t[v];\n            if (!(nd.data[0]\
    \ < x)) v = nd.left;\n            else if (nd.data[nd.size - 1] < x) res += nd.total\
    \ - t[nd.right].total, v = nd.right;\n            else {\n                int\
    \ i = 0;\n                while (nd.data[i] < x) i++;\n                return\
    \ res + t[nd.left].total + i;\n            }\n        }\n        return res;\n\
    \    }\n\n    // x \u4EE5\u4E0B\u306E\u8981\u7D20\u306E\u500B\u6570\n    int count_le(const\
    \ T &x) const {\n        int res = 0;\n        for (int v = root; v;) {\n    \
    \        const Node &nd = t[v];\n            if (x < nd.data[0]) v = nd.left;\n\
    \            else if (!(x < nd.data[nd.size - 1])) res += nd.total - t[nd.right].total,\
    \ v = nd.right;\n            else {\n                int i = 0;\n            \
    \    while (!(x < nd.data[i])) i++;\n                return res + t[nd.left].total\
    \ + i;\n            }\n        }\n        return res;\n    }\n\n    // [lo, hi)\
    \ \u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u306E\u500B\u6570\n    int count_range(const\
    \ T &lo, const T &hi) const { return lo < hi ? count_lt(hi) - count_lt(lo) : 0;\
    \ }\n\n    // x \u672A\u6E80\u306E\u6700\u5927\u306E\u8981\u7D20 (\u306A\u3051\
    \u308C\u3070 def)\n    T max_lt(const T &x, T def = T(-1)) const {\n        for\
    \ (int v = root; v;) {\n            const Node &nd = t[v];\n            if (!(nd.data[0]\
    \ < x)) v = nd.left;\n            else if (nd.data[nd.size - 1] < x) def = nd.data[nd.size\
    \ - 1], v = nd.right;\n            else {\n                int i = 1;\n      \
    \          while (nd.data[i] < x) i++;\n                return nd.data[i - 1];\n\
    \            }\n        }\n        return def;\n    }\n\n    // x \u4EE5\u4E0B\
    \u306E\u6700\u5927\u306E\u8981\u7D20 (\u306A\u3051\u308C\u3070 def)\n    T max_le(const\
    \ T &x, T def = T(-1)) const {\n        for (int v = root; v;) {\n           \
    \ const Node &nd = t[v];\n            if (x < nd.data[0]) v = nd.left;\n     \
    \       else if (!(x < nd.data[nd.size - 1])) def = nd.data[nd.size - 1], v =\
    \ nd.right;\n            else {\n                int i = 1;\n                while\
    \ (!(x < nd.data[i])) i++;\n                return nd.data[i - 1];\n         \
    \   }\n        }\n        return def;\n    }\n\n    // x \u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u306E\u8981\u7D20 (\u306A\u3051\u308C\u3070 def)\n    T min_ge(const T\
    \ &x, T def = T(-1)) const {\n        for (int v = root; v;) {\n            const\
    \ Node &nd = t[v];\n            if (!(nd.data[0] < x)) def = nd.data[0], v = nd.left;\n\
    \            else if (nd.data[nd.size - 1] < x) v = nd.right;\n            else\
    \ {\n                int i = 1;\n                while (nd.data[i] < x) i++;\n\
    \                return nd.data[i];\n            }\n        }\n        return\
    \ def;\n    }\n\n    // x \u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u8981\
    \u7D20 (\u306A\u3051\u308C\u3070 def)\n    T min_gt(const T &x, T def = T(-1))\
    \ const {\n        for (int v = root; v;) {\n            const Node &nd = t[v];\n\
    \            if (x < nd.data[0]) def = nd.data[0], v = nd.left;\n            else\
    \ if (!(x < nd.data[nd.size - 1])) v = nd.right;\n            else {\n       \
    \         int i = 1;\n                while (!(x < nd.data[i])) i++;\n       \
    \         return nd.data[i];\n            }\n        }\n        return def;\n\
    \    }\n\n    // \u6700\u5C0F\u306E\u8981\u7D20 / \u6700\u5927\u306E\u8981\u7D20\
    \ (\u7A7A\u306A\u3089 def)\n    T min(T def = T(-1)) const {\n        if (!root)\
    \ return def;\n        int v = root;\n        while (t[v].left) v = t[v].left;\n\
    \        return t[v].data[0];\n    }\n    T max(T def = T(-1)) const {\n     \
    \   if (!root) return def;\n        int v = root;\n        while (t[v].right)\
    \ v = t[v].right;\n        return t[v].data[t[v].size - 1];\n    }\n\n    // \u8981\
    \u7D20\u3092\u6607\u9806\u306B\u5217\u6319\n    vector<T> to_vector() const {\n\
    \        vector<T> res;\n        res.reserve(size());\n        auto dfs = [&](auto\
    \ self, int v) -> void {\n            if (!v) return;\n            self(self,\
    \ t[v].left);\n            res.insert(res.end(), t[v].data, t[v].data + t[v].size);\n\
    \            self(self, t[v].right);\n        };\n        dfs(dfs, root);\n  \
    \      return res;\n    }\n\n  private:\n    bool done = false;\n\n    int new_node()\
    \ {\n        int v;\n        if (!free_list.empty()) v = free_list.back(), free_list.pop_back();\n\
    \        else v = t.size(), t.emplace_back();\n        Node &nd = t[v];\n    \
    \    nd.left = nd.right = 0, nd.size = 0, nd.height = 1, nd.total = 0;\n     \
    \   return v;\n    }\n\n    int build(const vector<int> &ids, int l, int r) {\n\
    \        int m = (l + r) / 2, v = ids[m];\n        t[v].left = l < m ? build(ids,\
    \ l, m) : 0;\n        t[v].right = m + 1 < r ? build(ids, m + 1, r) : 0;\n   \
    \     update(v);\n        return v;\n    }\n\n    void update(int v) {\n     \
    \   Node &nd = t[v];\n        nd.height = std::max(t[nd.left].height, t[nd.right].height)\
    \ + 1;\n        nd.total = nd.size + t[nd.left].total + t[nd.right].total;\n \
    \   }\n    int balance_factor(int v) const { return t[t[v].left].height - t[t[v].right].height;\
    \ }\n\n    int rotate_right(int v) {\n        int l = t[v].left;\n        t[v].left\
    \ = t[l].right, t[l].right = v;\n        update(v), update(l);\n        return\
    \ l;\n    }\n    int rotate_left(int v) {\n        int r = t[v].right;\n     \
    \   t[v].right = t[r].left, t[r].left = v;\n        update(v), update(r);\n  \
    \      return r;\n    }\n    // update(v) \u6E08\u307F\u3067\u3042\u308B\u3053\
    \u3068\n    int balance(int v) {\n        int bf = balance_factor(v);\n      \
    \  if (bf == 2) {\n            if (balance_factor(t[v].left) < 0) t[v].left =\
    \ rotate_left(t[v].left);\n            return rotate_right(v);\n        }\n  \
    \      if (bf == -2) {\n            if (balance_factor(t[v].right) > 0) t[v].right\
    \ = rotate_right(t[v].right);\n            return rotate_left(v);\n        }\n\
    \        return v;\n    }\n\n    // \u30CE\u30FC\u30C9\u5185\u306B\u633F\u5165\
    \ (size < B \u3067\u3042\u308B\u3053\u3068)\uFF0E\u65E2\u306B\u3042\u308C\u3070\
    \ false\n    bool node_insert(Node &nd, const T &x) {\n        int i = 0;\n  \
    \      while (i < nd.size && nd.data[i] < x) i++;\n        if (i < nd.size &&\
    \ !(x < nd.data[i])) return false;\n        for (int j = nd.size; j > i; j--)\
    \ nd.data[j] = nd.data[j - 1];\n        nd.data[i] = x, nd.size++;\n        return\
    \ true;\n    }\n    bool node_erase(Node &nd, const T &x) {\n        int i = 0;\n\
    \        while (i < nd.size && nd.data[i] < x) i++;\n        if (i == nd.size\
    \ || x < nd.data[i]) return false;\n        for (int j = i + 1; j < nd.size; j++)\
    \ nd.data[j - 1] = nd.data[j];\n        nd.size--;\n        return true;\n   \
    \ }\n    // \u6E80\u676F\u306E\u30CE\u30FC\u30C9 v \u306E\u5F8C\u534A\u3092\u65B0\
    \u3057\u3044\u30CE\u30FC\u30C9\u306B\u79FB\u3057\u3066\uFF0C\u305D\u306E\u756A\
    \u53F7\u3092\u8FD4\u3059\n    int split(int v) {\n        int u = new_node();\n\
    \        constexpr int h = B / 2;\n        for (int i = 0; i < B - h; i++) t[u].data[i]\
    \ = t[v].data[h + i];\n        t[u].size = B - h, t[v].size = h;\n        return\
    \ u;\n    }\n\n    // \u90E8\u5206\u6728 v \u306E\u5168\u8981\u7D20\u3088\u308A\
    \u5C0F\u3055\u3044 x \u3092\u633F\u5165\u3059\u308B\n    int insert_leftmost(int\
    \ v, const T &x) {\n        if (t[v].left) {\n            int l = insert_leftmost(t[v].left,\
    \ x);\n            t[v].left = l;\n            update(v);\n            return\
    \ balance(v);\n        }\n        node_insert(t[v], x);\n        if (t[v].size\
    \ < B) {\n            update(v);\n            return v;\n        }\n        int\
    \ u = split(v);\n        t[u].left = v, t[u].right = t[v].right, t[v].right =\
    \ 0;\n        update(v), update(u);\n        return balance(u);\n    }\n\n   \
    \ int insert(int v, const T &x) {\n        if (!v) {\n            v = new_node();\n\
    \            t[v].data[0] = x, t[v].size = 1;\n            update(v);\n      \
    \      done = true;\n            return v;\n        }\n        if (t[v].left &&\
    \ x < t[v].data[0]) {\n            int l = insert(t[v].left, x);\n           \
    \ t[v].left = l;\n        } else if (t[v].right && t[v].data[t[v].size - 1] <\
    \ x) {\n            int r = insert(t[v].right, x);\n            t[v].right = r;\n\
    \        } else {\n            done = node_insert(t[v], x);\n            if (t[v].size\
    \ == B) {\n                if (t[v].right) {\n                    // \u6700\u5927\
    \u306E\u8981\u7D20\u3092\u53F3\u90E8\u5206\u6728\u306E\u5148\u982D\u306B\u56DE\
    \u3059\n                    T y = t[v].data[--t[v].size];\n                  \
    \  int r = insert_leftmost(t[v].right, y);\n                    t[v].right = r;\n\
    \                } else {\n                    int u = split(v);\n           \
    \         update(u);\n                    t[v].right = u;\n                }\n\
    \            }\n        }\n        update(v);\n        return balance(v);\n  \
    \  }\n\n    // \u90E8\u5206\u6728 v \u306E\u6700\u3082\u5DE6\u306E\u30CE\u30FC\
    \u30C9\u3092\u5207\u308A\u96E2\u3059 (u \u306B\u5165\u308C\u308B)\uFF0E\u6B8B\u3063\
    \u305F\u90E8\u5206\u6728\u306E\u6839\u3092\u8FD4\u3059\n    int cut_leftmost(int\
    \ v, int &u) {\n        if (!t[v].left) {\n            u = v;\n            return\
    \ t[v].right;\n        }\n        int l = cut_leftmost(t[v].left, u);\n      \
    \  t[v].left = l;\n        update(v);\n        return balance(v);\n    }\n\n \
    \   int erase(int v, const T &x) {\n        if (!v) return 0;\n        if (x <\
    \ t[v].data[0]) {\n            int l = erase(t[v].left, x);\n            t[v].left\
    \ = l;\n        } else if (t[v].data[t[v].size - 1] < x) {\n            int r\
    \ = erase(t[v].right, x);\n            t[v].right = r;\n        } else {\n   \
    \         done = node_erase(t[v], x);\n            if (t[v].size == 0) {\n   \
    \             // \u7A7A\u306B\u306A\u3063\u305F\u30CE\u30FC\u30C9\u3092\u6728\u304B\
    \u3089\u5916\u3059\n                free_list.push_back(v);\n                if\
    \ (!t[v].left || !t[v].right) return t[v].left ? t[v].left : t[v].right;\n   \
    \             int u = 0;\n                int r = cut_leftmost(t[v].right, u);\n\
    \                t[u].left = t[v].left, t[u].right = r;\n                update(u);\n\
    \                return balance(u);\n            }\n        }\n        update(v);\n\
    \        return balance(v);\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/ordered_set.hpp
  requiredBy: []
  timestamp: '2026-10-12 10:34:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/ordered_set.test.cpp
  - test/ordered_set.test.cpp
documentation_of: data_structure/ordered_set.hpp
layout: document
title: "\u9806\u5E8F\u4ED8\u304D\u96C6\u5408 (Ordered Set)"
---

## 概要

集合に対して、挿入・削除・$k$ 番目の要素・$x$ 以下の要素の個数・$x$ 以下の最大の要素・$x$ 以上の最小の要素を $O(\log n)$ で処理する。
**オンライン** で動く（挿入する値を先読みする必要はない）。

各ノードが最大 $B$ 個の値をソート済み配列で持つ AVL 木。1 ノードを約 128 バイトにしてキャッシュ効率を上げ、ノード内は線形探索している。木の高さが $\log_2 (n / B)$ 程度になるので、`std::set` よりはるかに速い（`ordered_set` の最大ケースで手元 0.13 秒。座標圧縮 + FastSet + Fenwick Tree のオフライン解法 0.17 秒より速い）。

## 使い方

```cpp
OrderedSet<int> st;          // 空集合
OrderedSet<int> st2(a);      // vector から構築 (順不同・重複可)

st.insert(x);        // 挿入 (既にあれば何もしない)
st.erase(x);         // 削除 (なければ何もしない)
st.contains(x);
st.kth(k);           // 小さい方から k 番目 (0-indexed)．なければ -1
st.count_le(x);      // x 以下の個数   (count_lt: x 未満, count_range(lo, hi): [lo, hi))
st.max_le(x);        // x 以下の最大   (max_lt: x 未満)．なければ -1
st.min_ge(x);        // x 以上の最小   (min_gt: x より大)．なければ -1
st.min(); st.max(); st.size(); st.to_vector();
st.max_le(x, LLONG_MIN);  // 値が負にもなりうるなら「なし」を表す値を渡す
```

| 関数 | 説明 | 計算量 |
| --- | --- | --- |
| `OrderedSet<T>()` | 空集合 | $O(1)$ |
| `OrderedSet<T>(vector<T> a)` | `a` の要素で初期化 | $O(n \log n)$（ソート済みなら $O(n)$） |
| `bool insert(T x)` | `x` を挿入。挿入したら `true`、既にあれば `false` | $O(\log n + B)$ |
| `bool erase(T x)` | `x` を削除。削除したら `true`、なければ `false` | $O(\log n + B)$ |
| `bool contains(T x)` / `size_t count(T x)` | `x` が含まれるか | $O(\log n + B)$ |
| `T kth(int k, T def = -1)` | 小さい方から $k$ 番目（0-indexed）。なければ `def` | $O(\log n)$ |
| `int count_le(T x)` / `int count_lt(T x)` | $x$ 以下 / 未満の要素数 | $O(\log n + B)$ |
| `int count_range(T lo, T hi)` | $[lo, hi)$ の要素数 | $O(\log n + B)$ |
| `T max_le(T x, T def = -1)` / `T max_lt(T x, T def = -1)` | $x$ 以下 / 未満の最大の要素。なければ `def` | $O(\log n + B)$ |
| `T min_ge(T x, T def = -1)` / `T min_gt(T x, T def = -1)` | $x$ 以上 / より大きい最小の要素。なければ `def` | $O(\log n + B)$ |
| `T min(T def = -1)` / `T max(T def = -1)` | 最小 / 最大の要素。空なら `def` | $O(\log n)$ |
| `int size()` / `bool empty()` | 要素数 / 空か | $O(1)$ |
| `vector<T> to_vector()` | 要素を昇順に列挙 | $O(n)$ |

$B$ はノードあたりの要素数（第 2 テンプレート引数。デフォルトは `int` で 28、`long long` で 14）。

## 注意

- 多重集合ではない（同じ値は 1 個まで）。
- `T` は `<` で比較できればよい（`pair` なども可）。
- `kth` は 0-indexed（「$x$ 番目」が 1-indexed の問題では `kth(x - 1)`）。
- 「なし」を表す値のデフォルトは `-1`。値が負になりうるときは `def` を明示する。
- 削除で要素数が少ないノードが残っても併合はしないので、挿入・削除を繰り返すと木が少し深くなることがある（高さはこれまでの挿入回数の対数で抑えられる）。
