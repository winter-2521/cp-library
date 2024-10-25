---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/dsu.hpp
    title: graph/dsu.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unionfind.test.cpp
    title: test/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unionfind.test.cpp
    title: test/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 1 "template.hpp"

    #include <bits/stdc++.h>

    using namespace std;

    #if __has_include(<atcoder/all>)

    #include <atcoder/all>

    using namespace atcoder;

    #endif

    //*/

    #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

    #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

    #pragma GCC target("avx,avx2,fma")

    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

    //*/

    #define rep(i,n) for(int i=0;i<n;i++)

    #define Rep(i,a,b) for(int i=a;i<b;i++)

    #define ALL(x) (x).begin(),(x).end()

    #define dbgv(x); for(auto now : x) cout << now << " "; cout << endl;

    //using P = pair<int,int>;

    using ll = long long;

    using ull = unsigned long long;

    typedef pair<int, int> pii;

    typedef pair<ll, ll> pll;

    typedef vector<ll> vll;

    typedef vector<int> vint;

    '
  code: '#include <bits/stdc++.h>

    using namespace std;

    #if __has_include(<atcoder/all>)

    #include <atcoder/all>

    using namespace atcoder;

    #endif

    //*/

    #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

    #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

    #pragma GCC target("avx,avx2,fma")

    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

    //*/

    #define rep(i,n) for(int i=0;i<n;i++)

    #define Rep(i,a,b) for(int i=a;i<b;i++)

    #define ALL(x) (x).begin(),(x).end()

    #define dbgv(x); for(auto now : x) cout << now << " "; cout << endl;

    //using P = pair<int,int>;

    using ll = long long;

    using ull = unsigned long long;

    typedef pair<int, int> pii;

    typedef pair<ll, ll> pll;

    typedef vector<ll> vll;

    typedef vector<int> vint;'
  dependsOn: []
  isVerificationFile: false
  path: template.hpp
  requiredBy:
  - graph/dsu.hpp
  timestamp: '2024-10-25 23:23:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unionfind.test.cpp
  - test/unionfind.test.cpp
documentation_of: template.hpp
layout: document
redirect_from:
- /library/template.hpp
- /library/template.hpp.html
title: template.hpp
---
