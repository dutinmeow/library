---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: random/random-vector.hpp
    title: Randomized Vector
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/cyclic-product.yosupo-a+b.test.cpp
    title: verify/cyclic-product.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ext-gcd.yosupo-a+b.test.cpp
    title: verify/ext-gcd.yosupo-a+b.test.cpp
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
    path: verify/wavelet-tree.yosupo-a+b.test.cpp
    title: verify/wavelet-tree.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/zip.yosupo-a+b.test.cpp
    title: verify/zip.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/zip.yosupo-a+b.test.cpp
    title: verify/zip.yosupo-a+b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 1 "random/mersenne-twister.hpp"

    #pragma region rng


    #ifndef MERSENNE_TWISTER_HPP

    #define MERSENNE_TWISTER_HPP


    mt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());


    template<typename T = int>

    typename enable_if<is_integral<T>::value, T>::type rng(T l, T r) { return uniform_int_distribution<T>(l,
    r)(_rng); }


    #endif


    #pragma endregion rng

    '
  code: '#pragma region rng


    #ifndef MERSENNE_TWISTER_HPP

    #define MERSENNE_TWISTER_HPP


    mt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());


    template<typename T = int>

    typename enable_if<is_integral<T>::value, T>::type rng(T l, T r) { return uniform_int_distribution<T>(l,
    r)(_rng); }


    #endif


    #pragma endregion rng'
  dependsOn: []
  isVerificationFile: false
  path: random/mersenne-twister.hpp
  requiredBy:
  - random/random-vector.hpp
  timestamp: '2022-05-03 13:32:14-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/zip.yosupo-a+b.test.cpp
  - verify/zip.yosupo-a+b.test.cpp
  - verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
  - verify/ext-gcd.yosupo-a+b.test.cpp
  - verify/wavelet-tree.yosupo-a+b.test.cpp
  - verify/wavelet-tree.yosupo-a+b.test.cpp
  - verify/cyclic-product.yosupo-a+b.test.cpp
  - verify/monotonic-dp-hull.yosupo-a+b.test.cpp
documentation_of: random/mersenne-twister.hpp
layout: document
title: Mersenne Twister
---

## Mersenne Twister