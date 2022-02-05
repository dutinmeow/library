---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data-structure/tnemges-tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/tnemges-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tTnettree<long long> tib(N +\
    \ 1);\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint l,\
    \ r; long long v;\n\t\t\tcin >> l >> r >> v;\n\t\t\ttib.update(l, r, v);\n\t\t\
    } else {\n\t\t\tint i; cin >> i;\n\t\t\tcout << tib.query(i) << '\\n';\n\t\t}\n\
    \t}\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/tnemges-tree.aizu-point-add-query.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/tnemges-tree.aizu-point-add-query.test.cpp
layout: document
redirect_from:
- /verify/verify/tnemges-tree.aizu-point-add-query.test.cpp
- /verify/verify/tnemges-tree.aizu-point-add-query.test.cpp.html
title: verify/tnemges-tree.aizu-point-add-query.test.cpp
---