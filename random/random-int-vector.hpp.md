---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: random/mersenne-twister.hpp
    title: Mersenne Twister
  - icon: ':heavy_check_mark:'
    path: random/random-int.hpp
    title: Random Integer
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/cyclic-product.yosupo-a+b.test.cpp
    title: verify/cyclic-product.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
    title: verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
    title: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/wavelet-tree.yosupo-a+b.test.cpp
    title: verify/wavelet-tree.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/zip.yosupo-a+b.test.cpp
    title: verify/zip.yosupo-a+b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/mersenne-twister.hpp\"\n#pragma region mersenne_twister\n\
    \n#ifndef MERSENNE_TWISTER_HPP\n#define MERSENNE_TWISTER_HPP\n\nnamespace rng\
    \ {\n\tmt19937 mst(chrono::steady_clock::now().time_since_epoch().count());\n\
    }\n\n#endif\n\n#pragma endregion mersenne_twister\n#line 2 \"random/random-int.hpp\"\
    \n\n#pragma region rng_int\n\n#ifndef RANDOM_INT_HPP\n#define RANDOM_INT_HPP\n\
    \nnamespace rng {\n\ttemplate<typename T = int>\n\ttypename enable_if<is_integral<T>::value,\
    \ T>::type \n\trint(T l, T r) { return uniform_int_distribution<T>(l, r)(mst);\
    \ }\n}\n\n#endif\n\n#pragma endregion rng_int\n#line 2 \"random/random-int-vector.hpp\"\
    \n\n#pragma region rng_int_vector\n\n#ifndef RNG_VECTOR_HPP\n#define RNG_VECTOR_HPP\n\
    \nnamespace rng {\n\ttemplate<typename T>\n\ttypename enable_if<is_integral<T>::value,\
    \ vector<T>>::type \n\trivec(int n, T l, T r) {\n\t\tvector<T> v(n);\n\t\tfor\
    \ (auto &a : v)\n\t\t\ta = rint(l, r);\n\t\treturn v;\n\t}\n}\n\n#endif\n\n#pragma\
    \ endregion rng_int_vector\n"
  code: "#include \"random-int.hpp\"\n\n#pragma region rng_int_vector\n\n#ifndef RNG_VECTOR_HPP\n\
    #define RNG_VECTOR_HPP\n\nnamespace rng {\n\ttemplate<typename T>\n\ttypename\
    \ enable_if<is_integral<T>::value, vector<T>>::type \n\trivec(int n, T l, T r)\
    \ {\n\t\tvector<T> v(n);\n\t\tfor (auto &a : v)\n\t\t\ta = rint(l, r);\n\t\treturn\
    \ v;\n\t}\n}\n\n#endif\n\n#pragma endregion rng_int_vector"
  dependsOn:
  - random/random-int.hpp
  - random/mersenne-twister.hpp
  isVerificationFile: false
  path: random/random-int-vector.hpp
  requiredBy: []
  timestamp: '2022-05-18 09:09:46-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/zip.yosupo-a+b.test.cpp
  - verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
  - verify/wavelet-tree.yosupo-a+b.test.cpp
  - verify/cyclic-product.yosupo-a+b.test.cpp
  - verify/monotonic-dp-hull.yosupo-a+b.test.cpp
documentation_of: random/random-int-vector.hpp
layout: document
title: Random Integer Vector
---

## Random Int Vector