---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/pi.hpp
    title: Pi
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/complex-convolution.hpp
    title: Complex Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/convolution-mod.hpp
    title: Convolution under Modulo
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: Convolution
  - icon: ':warning:'
    path: convolution/cyclic-product.hpp
    title: Cyclic Product
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/complex-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
    title: verify/complex-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
    title: verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/convolution-mod.yosupo-convolution.test.cpp
    title: verify/convolution-mod.yosupo-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
    title: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/pi.hpp\"\nconst double PI = acos(-1);\n#line 2 \"\
    convolution/fast-fourier-transform.hpp\"\n\nnamespace conv {\n\ttemplate<typename\
    \ T>\n\ttypename enable_if<is_floating_point<T>::value, void>::type\n\tfast_fourier_transform(vector<complex<T>>\
    \ &a) {\n\t\tint n = a.size(), logn = 31 - __builtin_clz(n);\n\n\t\tvector<int>\
    \ rev(n);\n\t\trev[0] = 0;\n\t\tfor (int i = 1; i < n; i++) {\n\t\t\trev[i] =\
    \ (rev[i >> 1] >> 1) + ((i & 1) << (logn - 1));\n\t\t\tif (i < rev[i])\n\t\t\t\
    \tswap(a[i], a[rev[i]]);\n\t\t}\n\n\t\tvector<complex<T>> root(n);\n\t\troot[1]\
    \ = {1, 0};\n\t\tfor (int k = 1; k < logn; k++) {\n\t\t\tT the = 2 * PI / (1 <<\
    \ (k + 1));\n\t\t\tcomplex<T> z = {cos(the), sin(the)};\n\t\t\tfor (int i = (1\
    \ << (k - 1)); i < (1 << k); i++) {\n\t\t\t\troot[i << 1] = root[i];\n\t\t\t\t\
    root[i << 1 | 1] = root[i] * z;\n\t\t\t}\n\t\t}\n\n\t\tfor (int l = 1; l < n;\
    \ l <<= 1) {\n\t\t\tfor (int i = 0; i < n; i += (l << 1)) {\n\t\t\t\tfor (int\
    \ j = 0; j < l; j++) {\n\t\t\t\t\tauto z = root[j + l] * a[i + j + l];\n\t\t\t\
    \t\ta[i + j + l] = a[i + j] - z;\n\t\t\t\t\ta[i + j] += z;\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t}\n}\n"
  code: "#include \"utility/pi.hpp\"\n\nnamespace conv {\n\ttemplate<typename T>\n\
    \ttypename enable_if<is_floating_point<T>::value, void>::type\n\tfast_fourier_transform(vector<complex<T>>\
    \ &a) {\n\t\tint n = a.size(), logn = 31 - __builtin_clz(n);\n\n\t\tvector<int>\
    \ rev(n);\n\t\trev[0] = 0;\n\t\tfor (int i = 1; i < n; i++) {\n\t\t\trev[i] =\
    \ (rev[i >> 1] >> 1) + ((i & 1) << (logn - 1));\n\t\t\tif (i < rev[i])\n\t\t\t\
    \tswap(a[i], a[rev[i]]);\n\t\t}\n\n\t\tvector<complex<T>> root(n);\n\t\troot[1]\
    \ = {1, 0};\n\t\tfor (int k = 1; k < logn; k++) {\n\t\t\tT the = 2 * PI / (1 <<\
    \ (k + 1));\n\t\t\tcomplex<T> z = {cos(the), sin(the)};\n\t\t\tfor (int i = (1\
    \ << (k - 1)); i < (1 << k); i++) {\n\t\t\t\troot[i << 1] = root[i];\n\t\t\t\t\
    root[i << 1 | 1] = root[i] * z;\n\t\t\t}\n\t\t}\n\n\t\tfor (int l = 1; l < n;\
    \ l <<= 1) {\n\t\t\tfor (int i = 0; i < n; i += (l << 1)) {\n\t\t\t\tfor (int\
    \ j = 0; j < l; j++) {\n\t\t\t\t\tauto z = root[j + l] * a[i + j + l];\n\t\t\t\
    \t\ta[i + j + l] = a[i + j] - z;\n\t\t\t\t\ta[i + j] += z;\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t}\n}"
  dependsOn:
  - utility/pi.hpp
  isVerificationFile: false
  path: convolution/fast-fourier-transform.hpp
  requiredBy:
  - convolution/convolution-mod.hpp
  - convolution/complex-convolution.hpp
  - convolution/convolution.hpp
  - convolution/cyclic-product.hpp
  timestamp: '2022-04-14 22:02:35-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  - verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
  - verify/complex-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  - verify/convolution-mod.yosupo-convolution.test.cpp
documentation_of: convolution/fast-fourier-transform.hpp
layout: document
title: Fast Fourier Transform
---

## Fast Fourier Transform