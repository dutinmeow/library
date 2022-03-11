---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/chmax.hpp\"\ntemplate<typename T>\nbool chmax(T\
    \ &a, T b) {\n\tif (a < b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n\
    }\n"
  code: "template<typename T>\nbool chmax(T &a, T b) {\n\tif (a < b) {\n\t\ta = b;\n\
    \t\treturn true;\n\t}\n\treturn false;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/chmax.hpp
  requiredBy: []
  timestamp: '2022-02-04 21:19:28-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/chmax.hpp
layout: document
title: Chmax
---

## Chmax

### Summary
For some $a$ and $b$, assigns $a = \max(a, b)$. Returns `true` if the assignment is successful, and `false` otherwise. 

### Parameters
- `T &a`: A reference.
- `T b`: A value.

### Return
- `true` if $a < b$'; `false` otherwise. 