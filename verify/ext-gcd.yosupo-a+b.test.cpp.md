---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ext-gcd.hpp
    title: Extended GCD
  - icon: ':heavy_check_mark:'
    path: random/mersenne_twister.hpp
    title: Mersenne Twister
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/ext-gcd.yosupo-a+b.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 1 \"math/ext-gcd.hpp\"\n#pragma region extended gcd\n\nnamespace\
    \ math {\n\ttemplate<typename T>\n\tT ext_gcd(T a, T b, T &x, T &y) {\n\t\tx =\
    \ 1, y = 0;\n\t\tT x1 = 0, y1 = 1, a1 = a, b1 = b;\n\t\twhile (b1) {\n\t\t\tT\
    \ q = a1 / b1;\n\t\t\ttie(x, x1) = make_tuple(x1, x - q * x1);\n\t\t\ttie(y, y1)\
    \ = make_tuple(y1, y - q * y1);\n\t\t\ttie(a1, b1) = make_tuple(b1, a1 - q * b1);\n\
    \t\t}\n\t\treturn a1;\n\t}\n}\n\n#pragma endregion extended gcd\n#line 1 \"random/mersenne_twister.hpp\"\
    \nmt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());\n\ntemplate<typename\
    \ T = int>\nT rng(T l, T r) { return uniform_int_distribution<T>(l, r)(_rng);\
    \ }\n#line 8 \"verify/ext-gcd.yosupo-a+b.test.cpp\"\n\nint main() {\n\tint T =\
    \ 2e5;\n\twhile (T--) {\n\t\tlong long A = rng<long long>(1, 1e6);\n\t\tlong long\
    \ B = rng<long long>(1, 1e6);\n\t\tlong long X, Y;\n\t\tauto G = math::ext_gcd(A,\
    \ B, X, Y);\n\t\tassert(G == __gcd(A, B));\n\t\tassert(A * X + B * Y == G);\n\t\
    }\n\n\tlong long A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"math/ext-gcd.hpp\"\n#include \"random/mersenne_twister.hpp\"\
    \n\nint main() {\n\tint T = 2e5;\n\twhile (T--) {\n\t\tlong long A = rng<long\
    \ long>(1, 1e6);\n\t\tlong long B = rng<long long>(1, 1e6);\n\t\tlong long X,\
    \ Y;\n\t\tauto G = math::ext_gcd(A, B, X, Y);\n\t\tassert(G == __gcd(A, B));\n\
    \t\tassert(A * X + B * Y == G);\n\t}\n\n\tlong long A, B;\n\tcin >> A >> B;\n\t\
    cout << A + B << '\\n';\n}"
  dependsOn:
  - math/ext-gcd.hpp
  - random/mersenne_twister.hpp
  isVerificationFile: true
  path: verify/ext-gcd.yosupo-a+b.test.cpp
  requiredBy: []
  timestamp: '2022-04-20 11:24:42-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ext-gcd.yosupo-a+b.test.cpp
layout: document
redirect_from:
- /verify/verify/ext-gcd.yosupo-a+b.test.cpp
- /verify/verify/ext-gcd.yosupo-a+b.test.cpp.html
title: verify/ext-gcd.yosupo-a+b.test.cpp
---