---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/dsu.hpp
    title: graph/dsu.hpp
  - icon: ':x:'
    path: template.hpp
    title: template.hpp
  - icon: ':x:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/4/ITP1_4_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/4/ITP1_4_A
  bundledCode: "#line 1 \"test/unionfind.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/4/ITP1_4_A\"\
    \n#line 1 \"template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n#if\
    \ __has_include(<atcoder/all>)\n#include <atcoder/all>\nusing namespace atcoder;\n\
    #endif\n//*/\n#pragma GCC optimize(\"Ofast,unroll-loops,no-stack-protector,fast-math\"\
    )\n#pragma GCC target(\"avx2,bmi,bmi2,lzcnt,popcnt\")\n#pragma GCC target(\"avx,avx2,fma\"\
    )\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma\"\
    )\n//*/\n#define rep(i,n) for(int i=0;i<n;i++)\n#define Rep(i,a,b) for(int i=a;i<b;i++)\n\
    #define ALL(x) (x).begin(),(x).end()\n#define dbgv(x); for(auto now : x) cout\
    \ << now << \" \"; cout << endl;\n//using P = pair<int,int>;\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\ntypedef pair<int, int> pii;\ntypedef\
    \ pair<ll, ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line\
    \ 2 \"template.hpp\"\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
    #include <atcoder/all>\nusing namespace atcoder;\n#endif\n//*/\n#pragma GCC optimize(\"\
    Ofast,unroll-loops,no-stack-protector,fast-math\")\n#pragma GCC target(\"avx2,bmi,bmi2,lzcnt,popcnt\"\
    )\n#pragma GCC target(\"avx,avx2,fma\")\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma\"\
    )\n//*/\n#define rep(i,n) for(int i=0;i<n;i++)\n#define Rep(i,a,b) for(int i=a;i<b;i++)\n\
    #define ALL(x) (x).begin(),(x).end()\n#define dbgv(x); for(auto now : x) cout\
    \ << now << \" \"; cout << endl;\n//using P = pair<int,int>;\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\ntypedef pair<int, int> pii;\ntypedef\
    \ pair<ll, ll> pll;\ntypedef vector<ll> vll;\ntypedef vector<int> vint;\n#line\
    \ 3 \"graph/dsu.hpp\"\n\nstruct UnionFind {\n    //\u89AA\u3092\u4FDD\u5B58\u3059\
    \u308B\u914D\u5217\n    vector<int> par;\n\n    UnionFind(int n=0): par(n,-1)\
    \ {}\n\n    //\u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\n    int\
    \ find(int x) {\n        if(par[x] < 0) return x;\n        return par[x] = find(par[x]);\n\
    \    }\n\n    //x \u3092\u542B\u3080\u96C6\u5408\u3068 y \u3092\u542B\u3080\u96C6\
    \u5408\u3092\u30DE\u30FC\u30B8\n    //\u65E2\u306B\u540C\u3058\u96C6\u5408\u306B\
    \u5C5E\u3059\u306A\u3089true , \u305D\u308C\u4EE5\u5916\u3067false\u3092\u8FD4\
    \u3059\uFF0E\n    bool unite(int x, int y){\n        x = find(x); y = find(y);\n\
    \        if(x==y) return false;\n        if(par[x] > par[y]) swap(x,y);\n    \
    \    par[x] += par[y];\n        par[y] = x;\n        return true;\n    }\n\n \
    \   //x \u3068 y \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u306A\u3089\
    true , \u305D\u308C\u4EE5\u5916\u3067false\u3092\u8FD4\u3059\uFF0E\n    bool same(int\
    \ x, int y) {return find(x) == find(y);}\n\n    //x \u306E\u5C5E\u3059\u308B\u96C6\
    \u5408\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\uFF0E\n    int size(int x) {return\
    \ -par[find(x)];}\n\n    //\u73FE\u5728\u5B58\u5728\u3059\u308B\u96C6\u5408\u306E\
    \u5217\u6319\n    vector<vector<int>> groups(){\n        vector<vector<int>> res(par.size());\n\
    \        for(int i = 0; i < (int)par.size(); i++){\n            res[find(i)].push_back(i);\n\
    \        }\n        res.erase(remove_if(res.begin(), res.end(),\n            \
    \    [&](const vector<int> &v) { return v.empty(); }),\n                res.end());\n\
    \        return res;\n    }\n};\n#line 4 \"test/unionfind.test.cpp\"\n\n//verify\
    \ for UnionFind\n\nint main(){\n    int n,q; cin >> n >> q;\n    UnionFind dsu(n);\n\
    \    for(int query = 0; query < q; query++){\n        int t,u,v; cin >> t >> u\
    \ >> v;\n        if(t == 0){//test for unite\n            dsu.unite(u,v);\n  \
    \      }\n        if(t == 1){//test for same?\n            cout << dsu.same(u,v)\
    \ << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/4/ITP1_4_A\"\
    \n#include \"../template.hpp\"\n#include \"../graph/dsu.hpp\"\n\n//verify for\
    \ UnionFind\n\nint main(){\n    int n,q; cin >> n >> q;\n    UnionFind dsu(n);\n\
    \    for(int query = 0; query < q; query++){\n        int t,u,v; cin >> t >> u\
    \ >> v;\n        if(t == 0){//test for unite\n            dsu.unite(u,v);\n  \
    \      }\n        if(t == 1){//test for same?\n            cout << dsu.same(u,v)\
    \ << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - template.hpp
  - graph/dsu.hpp
  - template.hpp
  isVerificationFile: true
  path: test/unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-10-25 23:23:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/unionfind.test.cpp
- /verify/test/unionfind.test.cpp.html
title: test/unionfind.test.cpp
---
