---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/cyclic-product.hpp
    title: Cyclic Product
  - icon: ':heavy_check_mark:'
    path: convolution/fast-fourier-transform.hpp
    title: Fast Fourier Transform
  - icon: ':heavy_check_mark:'
    path: random/mersenne-twister.hpp
    title: Mersenne Twister
  - icon: ':heavy_check_mark:'
    path: random/random-int-vector.hpp
    title: Random Integer Vector
  - icon: ':heavy_check_mark:'
    path: random/random-int.hpp
    title: Random Integer
  - icon: ':heavy_check_mark:'
    path: utility/pi.hpp
    title: Pi
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
  bundledCode: "#line 1 \"verify/cyclic-product.yosupo-a+b.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 1 \"utility/pi.hpp\"\n#pragma region Pi\n\n#ifndef PI_HPP\n\
    #define PI_HPP\n\nconst double PI = acos(-1);\n\n#endif\n\n#pragma endregion Pi\n\
    #line 2 \"convolution/fast-fourier-transform.hpp\"\n\n#pragma region fast_fourier_transform\n\
    \nnamespace conv {\n\ttemplate<typename T>\n\ttypename enable_if<is_floating_point<T>::value,\
    \ void>::type\n\tfast_fourier_transform(vector<complex<T>> &a) {\n\t\tint n =\
    \ a.size(), logn = 31 - __builtin_clz(n);\n\t\t\n\t\tvector<int> rev(n);\n\t\t\
    rev[0] = 0;\n\t\tfor (int i = 1; i < n; i++) {\n\t\t\trev[i] = (rev[i >> 1] >>\
    \ 1) + ((i & 1) << (logn - 1));\n\t\t\tif (i < rev[i])\n\t\t\t\tswap(a[i], a[rev[i]]);\n\
    \t\t}\n\n\t\tvector<complex<T>> root(n);\n\t\troot[1] = {1, 0};\n\t\tfor (int\
    \ k = 1; k < logn; k++) {\n\t\t\tT the = 2 * PI / (1 << (k + 1));\n\t\t\tcomplex<T>\
    \ z = {cos(the), sin(the)};\n\t\t\tfor (int i = (1 << (k - 1)); i < (1 << k);\
    \ i++) {\n\t\t\t\troot[i << 1] = root[i];\n\t\t\t\troot[i << 1 | 1] = root[i]\
    \ * z;\n\t\t\t}\n\t\t}\n\n\t\tfor (int l = 1; l < n; l <<= 1) {\n\t\t\tfor (int\
    \ i = 0; i < n; i += (l << 1)) {\n\t\t\t\tfor (int j = 0; j < l; j++) {\n\t\t\t\
    \t\tauto z = root[j + l] * a[i + j + l];\n\t\t\t\t\ta[i + j + l] = a[i + j] -\
    \ z;\n\t\t\t\t\ta[i + j] += z;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}\n\n#pragma endregion\
    \ fast_fourier_transform\n#line 2 \"convolution/convolution.hpp\"\n\n#pragma region\
    \ convolution\n\nnamespace conv {\n\ttemplate<typename T, typename U = double>\n\
    \tvector<T> convolution(const vector<T> &a, const vector<T> &b) {\n\t\tint n =\
    \ 1;\n\t\twhile (n < a.size() + b.size()) \n\t\t\tn <<= 1;\n\t\tvector<complex<U>>\
    \ c(n);\n\t\tfor (int i = 0; i < a.size(); i++)\n\t\t\tc[i] = static_cast<U>(a[i]);\n\
    \t\tfor (int i = 0; i < b.size(); i++)\n\t\t\tc[i] = {c[i].real(), static_cast<U>(b[i])};\n\
    \t\tfast_fourier_transform(c);\n\n\t\tvector<complex<U>> d(n);\n\t\tfor (int i\
    \ = 0, j; i < n; i++) {\n\t\t\tj = (n - i) & (n - 1);\n\t\t\td[i] = (c[j] * c[j]\
    \ - conj(c[i] * c[i])) * complex<U>{0, -0.25 / n};\n\t\t}\n\t\tfast_fourier_transform(d);\n\
    \n\t\tn = a.size() + b.size() - 1;\n\t\tvector<T> ret(n);\n\t\tfor (int i = 0;\
    \ i < n; i++)\n\t\t\tret[i] = static_cast<T>(d[i].real() + 0.5);\n\t\treturn ret;\n\
    \t}\n}\n\n#pragma endregion convolution\n#line 2 \"convolution/cyclic-product.hpp\"\
    \n\n#pragma region cyclic_product\n\nnamespace conv {\n\ttemplate<typename T,\
    \ typename U = double>\n\tvector<T> cyclic_product(vector<T> a, vector<T> b) {\n\
    \t\tassert(a.size() == b.size());\n\t\tint n = a.size();\n\t\treverse(a.begin(),\
    \ a.end());\n\t\ta.resize(2 * n);\n\t\tb.insert(b.end(), b.begin(), b.end());\n\
    \t\tauto c = convolution<T, U>(a, b);\n\t\tvector<T> ret(n);\n\t\tfor (int i =\
    \ 0; i < n; i++)\n\t\t\tret[i] = c[i + n - 1];\n\t\treturn ret;\n\t}\n}\n\n#pragma\
    \ endregion cyclic_product\n#line 1 \"random/mersenne-twister.hpp\"\n#pragma region\
    \ mersenne_twister\n\n#ifndef MERSENNE_TWISTER_HPP\n#define MERSENNE_TWISTER_HPP\n\
    \nnamespace rng {\n\tmt19937 mst(chrono::steady_clock::now().time_since_epoch().count());\n\
    }\n\n#endif\n\n#pragma endregion mersenne_twister\n#line 2 \"random/random-int.hpp\"\
    \n\n#pragma region rng_int\n\n#ifndef RANDOM_INT_HPP\n#define RANDOM_INT_HPP\n\
    \nnamespace rng {\n\ttemplate<typename T = int>\n\ttypename enable_if<is_integral<T>::value,\
    \ T>::type \n\trint(T l, T r) { return uniform_int_distribution<T>(l, r)(mst);\
    \ }\n}\n\n#endif\n\n#pragma endregion rng_int\n#line 2 \"random/random-int-vector.hpp\"\
    \n\n#pragma region rng_int_vector\n\n#ifndef RNG_VECTOR_HPP\n#define RNG_VECTOR_HPP\n\
    \nnamespace rng {\n\ttemplate<typename T>\n\ttypename enable_if<is_integral<T>::value,\
    \ vector<T>>::type \n\trivec(int n, T l, T r) {\n\t\tvector<T> v(n);\n\t\tfor\
    \ (auto &a : v)\n\t\t\ta = rint(l, r);\n\t\treturn v;\n\t}\n}\n\n#endif\n\n#pragma\
    \ endregion rng_int_vector\n#line 8 \"verify/cyclic-product.yosupo-a+b.test.cpp\"\
    \n\nconst int N = 5e4;\n\nint main() { \n\t{\n\t\tvector<long long> A = rng::rivec<long\
    \ long>(N, 1, 1e5);\n\t\tvector<long long> B = rng::rivec<long long>(N, 1, 1e5);\n\
    \t\tauto C = conv::cyclic_product(A, B);\n\t\tB.insert(B.end(), B.begin(), B.end());\n\
    \t\tfor (int i = 0; i < N; i++) {\n\t\t\tlong long cur = 0;\n\t\t\tfor (int j\
    \ = 0; j < N; j++)\n\t\t\t\tcur += A[j] * B[i + j];\n\t\t\tassert(cur == C[i]);\n\
    \t\t}\n\t}\n\n\tint A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"convolution/cyclic-product.hpp\"\n#include\
    \ \"random/random-int-vector.hpp\"\n\nconst int N = 5e4;\n\nint main() { \n\t\
    {\n\t\tvector<long long> A = rng::rivec<long long>(N, 1, 1e5);\n\t\tvector<long\
    \ long> B = rng::rivec<long long>(N, 1, 1e5);\n\t\tauto C = conv::cyclic_product(A,\
    \ B);\n\t\tB.insert(B.end(), B.begin(), B.end());\n\t\tfor (int i = 0; i < N;\
    \ i++) {\n\t\t\tlong long cur = 0;\n\t\t\tfor (int j = 0; j < N; j++)\n\t\t\t\t\
    cur += A[j] * B[i + j];\n\t\t\tassert(cur == C[i]);\n\t\t}\n\t}\n\n\tint A, B;\n\
    \tcin >> A >> B;\n\tcout << A + B << '\\n';\n}"
  dependsOn:
  - convolution/cyclic-product.hpp
  - convolution/convolution.hpp
  - convolution/fast-fourier-transform.hpp
  - utility/pi.hpp
  - random/random-int-vector.hpp
  - random/random-int.hpp
  - random/mersenne-twister.hpp
  isVerificationFile: true
  path: verify/cyclic-product.yosupo-a+b.test.cpp
  requiredBy: []
  timestamp: '2022-05-18 09:09:46-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/cyclic-product.yosupo-a+b.test.cpp
layout: document
redirect_from:
- /verify/verify/cyclic-product.yosupo-a+b.test.cpp
- /verify/verify/cyclic-product.yosupo-a+b.test.cpp.html
title: verify/cyclic-product.yosupo-a+b.test.cpp
---