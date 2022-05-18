---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/binomial-coefficients.hpp
    title: Binomial Coefficients
  - icon: ':heavy_check_mark:'
    path: math/discrete-log.hpp
    title: Discrete Logarithm
  - icon: ':heavy_check_mark:'
    path: math/discrete-sqrt.hpp
    title: Discrete Square Root
  - icon: ':heavy_check_mark:'
    path: utility/mint.hpp
    title: Modular Int
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/discrete-log.yosupo-discrete-logarithm.test.cpp
    title: verify/discrete-log.yosupo-discrete-logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/discrete-sqrt.yosupo-sqrt-mod.test.cpp
    title: verify/discrete-sqrt.yosupo-sqrt-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
    title: verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
    title: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/mint.power.test.cpp
    title: verify/mint.power.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/mint.yosupo-A+B.test.cpp
    title: verify/mint.yosupo-A+B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
    title: verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/sliding-window-aggregate.yosupo-queue-operate-all-composite.test.cpp
    title: verify/sliding-window-aggregate.yosupo-queue-operate-all-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/sparse-segment-tree.yosupo-point-set-range-composite.test.cpp
    title: verify/sparse-segment-tree.yosupo-point-set-range-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
    title: verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/inverse.hpp\"\n#pragma region modular_inverse\n\nnamespace\
    \ math {\n\ttemplate <typename T>\n\tT inverse(T a, T p) {\n\t\tT b = p, x = 1,\
    \ y = 0;\n\t\twhile (a) {\n\t\t\tT q = b / a;\n\t\t\tswap(a, b %= a);\n\t\t\t\
    swap(x, y -= q * x);\n\t\t}\n\t\tassert(b == 1);\n\t\treturn y < 0 ? y + p : y;\n\
    \t}\n}\n\n#pragma endregion modular_inverse\n"
  code: "#pragma region modular_inverse\n\nnamespace math {\n\ttemplate <typename\
    \ T>\n\tT inverse(T a, T p) {\n\t\tT b = p, x = 1, y = 0;\n\t\twhile (a) {\n\t\
    \t\tT q = b / a;\n\t\t\tswap(a, b %= a);\n\t\t\tswap(x, y -= q * x);\n\t\t}\n\t\
    \tassert(b == 1);\n\t\treturn y < 0 ? y + p : y;\n\t}\n}\n\n#pragma endregion\
    \ modular_inverse"
  dependsOn: []
  isVerificationFile: false
  path: math/inverse.hpp
  requiredBy:
  - utility/mint.hpp
  - math/binomial-coefficients.hpp
  - math/discrete-sqrt.hpp
  - math/discrete-log.hpp
  timestamp: '2022-04-30 10:59:16-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/mint.yosupo-A+B.test.cpp
  - verify/discrete-log.yosupo-discrete-logarithm.test.cpp
  - verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
  - verify/sparse-segment-tree.yosupo-point-set-range-composite.test.cpp
  - verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
  - verify/discrete-sqrt.yosupo-sqrt-mod.test.cpp
  - verify/mint.power.test.cpp
  - verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
  - verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
  - verify/sliding-window-aggregate.yosupo-queue-operate-all-composite.test.cpp
documentation_of: math/inverse.hpp
layout: document
title: Modulo Inverse
---

## Modulo Inverse