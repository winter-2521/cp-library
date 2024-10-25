---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/4/ITP1_4_A\"\
    \n#include \"../template.hpp\"\n#include \"../graph/dsu.hpp\"\n\n//verify for\
    \ UnionFind\n\nint main(){\n    int n,q; cin >> n >> q;\n    UnionFind dsu(n);\n\
    \    for(int query = 0; query < q; query++){\n        int t,u,v; cin >> t >> u\
    \ >> v;\n        if(t == 0){//test for unite\n            dsu.unite(u,v);\n  \
    \      }\n        if(t == 1){//test for same?\n            cout << dsu.same(u,v)\
    \ << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/unionfind.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/unionfind.test.cpp
- /verify/test/unionfind.test.cpp.html
title: test/unionfind.test.cpp
---
