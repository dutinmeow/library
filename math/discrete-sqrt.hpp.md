---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/inverse.hpp
    title: Modulo Inverse
  - icon: ':heavy_check_mark:'
    path: utility/mint.hpp
    title: Modular Int
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/discrete-sqrt.yosupo-sqrt-mod.test.cpp
    title: verify/discrete-sqrt.yosupo-sqrt-mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/inverse.hpp\"\n#pragma region modulo inverse\n\nnamespace\
    \ math {\n\ttemplate <typename T>\n\tT inverse(T a, T p) {\n\t\tT b = p, x = 1,\
    \ y = 0;\n\t\twhile (a) {\n\t\t\tT q = b / a;\n\t\t\tswap(a, b %= a);\n\t\t\t\
    swap(x, y -= q * x);\n\t\t}\n\t\tassert(b == 1);\n\t\treturn y < 0 ? y + p : y;\n\
    \t}\n}\n\n#pragma endregion modulo inverse\n#line 2 \"utility/mint.hpp\"\n\n#pragma\
    \ region mint\n\ntemplate<typename T>\nclass Modular {\npublic:\n\tusing Type\
    \ = typename decay<decltype(T::value)>::type;\n\t\n\tconstexpr Modular() : value()\
    \ {}\n\n\ttemplate<typename U>\n\tModular(const U &x) { value = normalize(x);\
    \ }\n\n\ttemplate<typename U>\n\tstatic Type normalize(const U &x) {\n\t\tType\
    \ v;\n\t\tif (-mod() <= x && x < mod()) \n\t\t\tv = static_cast<Type>(x);\n\t\t\
    else \n\t\t\tv = static_cast<Type>(x % mod());\n\t\tif (v < 0) \n\t\t\tv += mod();\n\
    \t\treturn v;\n\t}\n\n\tconst Type &operator()() const { return value; }\n\n\t\
    template<typename U>\n\texplicit operator U() const { return static_cast<U>(value);\
    \ }\n\n\tconstexpr static Type mod() { return T::value; }\n\n\tModular &operator+=(const\
    \ Modular &a) { \n\t\tif ((value += a.value) >= mod()) \n\t\t\tvalue -= mod();\
    \ \n\t\treturn *this; \n\t}\n\n\tModular &operator-=(const Modular &a) { \n\t\t\
    if ((value -= a.value) < 0) \n\t\t\tvalue += mod(); \n\t\treturn *this; \n\t}\n\
    \n\ttemplate<typename U> \n\tModular &operator+=(const U &other) { return *this\
    \ += Modular(other); }\n\n\ttemplate<typename U> \n\tModular &operator-=(const\
    \ U &other) { return *this -= Modular(other); }\n\n\tModular &operator++() { return\
    \ *this += 1; }\n\n\tModular &operator--() { return *this -= 1; }\n\n\tModular\
    \ operator++(int) { \n\t\tModular result(*this); \n\t\t*this += 1; \n\t\treturn\
    \ result; \n\t}\n\n\tModular operator--(int) { \n\t\tModular result(*this);\n\t\
    \t*this -= 1; \n\t\treturn result; \n\t}\n\n\tModular operator-() const { return\
    \ Modular(-value); }\n\n\ttemplate<typename U = T>\n\ttypename enable_if<is_same<typename\
    \ Modular<U>::Type, int>::value, Modular>::type\n\t&operator*=(const Modular &a)\
    \ {\n#ifdef _WIN32\n\t\tuint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(a.value);\n\
    \t\tuint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x),\
    \ d, m;\n\t\tasm(\n\t\t\t\"divl %4; \\n\\t\"\n\t\t\t: \"=a\" (d), \"=d\" (m)\n\
    \t\t\t: \"d\" (xh), \"a\" (xl), \"r\" (mod())\n\t\t);\n\t\tvalue = m;\n#else\n\
    \t\tvalue = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(a.value));\n\
    #endif\n\t\treturn *this;\n\t}\n\t\n\ttemplate <typename U = T>\n\ttypename enable_if<is_same<typename\
    \ Modular<U>::Type, int64_t>::value, Modular>::type\n\t&operator*=(const Modular\
    \ &a) {\n\t\tint64_t q = static_cast<int64_t>(static_cast<long double>(value)\
    \ * a.value / mod());\n\t\tvalue = normalize(value * a.value - q * mod());\n\t\
    \treturn *this;\n\t}\n\n\ttemplate <typename U = T>\n\ttypename enable_if<!is_integral<typename\
    \ Modular<U>::Type>::value, Modular>::type \n\t&operator*=(const Modular &a) {\n\
    \t\tvalue = normalize(value * a.value);\n\t\treturn *this;\n\t}\n\n\tModular &operator/=(const\
    \ Modular &other) { return *this *= Modular(math::inverse(other.value, mod()));\
    \ }\n\n\ttemplate<typename U>\n\tfriend bool operator==(const Modular<U>& a, const\
    \ Modular<U>& b);\n\n\ttemplate<typename U>\n\tfriend bool operator<(const Modular<U>&\
    \ a, const Modular<U>& b);\n\n\ttemplate<typename U>\n\tfriend istream &operator>>(istream\
    \ &is, Modular<U> &a);\n\nprivate:\n\tType value;\n};\n\ntemplate<typename T>\
    \ \nbool operator==(const Modular<T> &a, const Modular<T> &b) { return a.value\
    \ == b.value; }\n\ntemplate<typename T, typename U> \nbool operator==(const Modular<T>\
    \ &a, U b) { return a == Modular<T>(b); }\n\ntemplate<typename T, typename U>\
    \ \nbool operator==(U a, const Modular<T> &b) { return Modular<T>(a) == b; }\n\
    \ntemplate<typename T> \nbool operator!=(const Modular<T> &a, const Modular<T>\
    \ &b) { return !(a == b); }\n\ntemplate<typename T, typename U> \nbool operator!=(const\
    \ Modular<T> &a, U b) { return !(a == b); }\n\ntemplate<typename T, typename U>\
    \ \nbool operator!=(U a, const Modular<T> &b) { return !(a == b); }\n\ntemplate<typename\
    \ T> \nbool operator<(const Modular<T> &a, const Modular<T> &b) { return a.value\
    \ < b.value; }\n\ntemplate<typename T> \nModular<T> operator+(const Modular<T>\
    \ &a, const Modular<T> &b) { return Modular<T>(a) += b; }\n\ntemplate<typename\
    \ T, typename U> \nModular<T> operator+(const Modular<T> &a, U b) { return Modular<T>(a)\
    \ += b; }\n\ntemplate<typename T, typename U> \nModular<T> operator+(U a, const\
    \ Modular<T> &b) { return Modular<T>(a) += b; }\n\ntemplate<typename T> \nModular<T>\
    \ operator-(const Modular<T> &a, const Modular<T> &b) { return Modular<T>(a) -=\
    \ b; }\n\ntemplate<typename T, typename U> \nModular<T> operator-(const Modular<T>\
    \ &a, U b) { return Modular<T>(a) -= b; }\n\ntemplate<typename T, typename U>\
    \ \nModular<T> operator-(U a, const Modular<T> &b) { return Modular<T>(a) -= b;\
    \ }\n\ntemplate<typename T> Modular<T> \noperator*(const Modular<T> &a, const\
    \ Modular<T> &b) { return Modular<T>(a) *= b; }\n\ntemplate<typename T, typename\
    \ U> \nModular<T> operator*(const Modular<T> &a, U b) { return Modular<T>(a) *=\
    \ b; }\n\ntemplate<typename T, typename U> \nModular<T> operator*(U a, const Modular<T>\
    \ &b) { return Modular<T>(a) *= b; }\n\ntemplate<typename T> Modular<T> \noperator/(const\
    \ Modular<T> &a, const Modular<T> &b) { return Modular<T>(a) /= b; }\n\ntemplate<typename\
    \ T, typename U> \nModular<T> operator/(const Modular<T> &a, U b) { return Modular<T>(a)\
    \ /= b; }\n\ntemplate<typename T, typename U> \nModular<T> operator/(U a, const\
    \ Modular<T> &b) { return Modular<T>(a) /= b; }\n\ntemplate<typename T, typename\
    \ U>\nModular<T> fast_pow(const Modular<T> &a, const U &b) {\n\tassert(b >= 0);\n\
    \tModular<T> x = a, res = 1;\n\tU p = b;\n\twhile (p > 0) {\n\t\tif (p & 1) \n\
    \t\t\tres *= x;\n\t\tx *= x;\n\t\tp /= 2;\n\t}\n\treturn res;\n}\n\ntemplate<typename\
    \ T>\nstring to_string(const Modular<T> &a) { return to_string(a()); }\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const Modular<T> &a) { return os << a();\
    \ }\n\ntemplate<typename T>\nistream &operator>>(istream &is, Modular<T> &a) {\n\
    \ttypename common_type<typename Modular<T>::Type, long long>::type x;\n\tis >>\
    \ x;\n\ta.value = Modular<T>::normalize(x);\n\treturn is;\n}\n\n// /*\nusing ModType\
    \ = int;\n\nstruct VarMod { static ModType value; };\n\nModType VarMod::value;\n\
    \nModType &MOD = VarMod::value;\n\nusing mint = Modular<VarMod>;\n// */\n\n/*\n\
    constexpr int MOD = @@HERE@@;\n\nusing mint = Modular<integral_constant<decay<decltype(MOD)>::type,\
    \ MOD>>;\n*/\n\n#pragma endregion mint\n#line 2 \"math/discrete-sqrt.hpp\"\n\n\
    #pragma region discrete sqrt\n\nnamespace math {\n\ttemplate<typename T = long\
    \ long>\n\tT discrete_sqrt(const T &a, const T &mod) {\n\t\tassert(0 <= a && a\
    \ < mod);\n\t\tif (a < 2) \n\t\t\treturn a;\n\t\tMOD = mod;\n\t\tif (fast_pow(mint(a),\
    \ (mod - 1) >> 1) != 1) \n\t\t\treturn -1;\n\t\tmint b = 1;\n\t\tfor (; fast_pow(b,\
    \ (mod - 1) >> 1) == 1; b++);\n\t\tT m = mod - 1, e = 0;\n\t\tfor (; m % 2 ==\
    \ 0; m >>= 1, e++);\n\t\tmint x = fast_pow(mint(a), (m - 1) >> 1), y = mint(a)\
    \ * x * x, z = fast_pow(mint(b), m);\n\t\tx *= a;\n\t\twhile (y != 1) {\n\t\t\t\
    T j = 0;\n\t\t\tmint t = y;\n\t\t\twhile (t != 1) {\n\t\t\t\tj += 1;\n\t\t\t\t\
    t *= t;\n\t\t\t}\n\t\t\tz = fast_pow(z, T(1) << (e - j - 1));\n\t\t\tx *= z;\n\
    \t\t\tz *= z;\n\t\t\ty *= z;\n\t\t\te = j;\n\t\t}\n\t\treturn x();\n\t}\n}\n\n\
    #pragma endregion discrete sqrt\n"
  code: "#include \"utility/mint.hpp\"\n\n#pragma region discrete sqrt\n\nnamespace\
    \ math {\n\ttemplate<typename T = long long>\n\tT discrete_sqrt(const T &a, const\
    \ T &mod) {\n\t\tassert(0 <= a && a < mod);\n\t\tif (a < 2) \n\t\t\treturn a;\n\
    \t\tMOD = mod;\n\t\tif (fast_pow(mint(a), (mod - 1) >> 1) != 1) \n\t\t\treturn\
    \ -1;\n\t\tmint b = 1;\n\t\tfor (; fast_pow(b, (mod - 1) >> 1) == 1; b++);\n\t\
    \tT m = mod - 1, e = 0;\n\t\tfor (; m % 2 == 0; m >>= 1, e++);\n\t\tmint x = fast_pow(mint(a),\
    \ (m - 1) >> 1), y = mint(a) * x * x, z = fast_pow(mint(b), m);\n\t\tx *= a;\n\
    \t\twhile (y != 1) {\n\t\t\tT j = 0;\n\t\t\tmint t = y;\n\t\t\twhile (t != 1)\
    \ {\n\t\t\t\tj += 1;\n\t\t\t\tt *= t;\n\t\t\t}\n\t\t\tz = fast_pow(z, T(1) <<\
    \ (e - j - 1));\n\t\t\tx *= z;\n\t\t\tz *= z;\n\t\t\ty *= z;\n\t\t\te = j;\n\t\
    \t}\n\t\treturn x();\n\t}\n}\n\n#pragma endregion discrete sqrt"
  dependsOn:
  - utility/mint.hpp
  - math/inverse.hpp
  isVerificationFile: false
  path: math/discrete-sqrt.hpp
  requiredBy: []
  timestamp: '2022-04-21 20:14:03-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/discrete-sqrt.yosupo-sqrt-mod.test.cpp
documentation_of: math/discrete-sqrt.hpp
layout: document
title: Discrete Square Root
---

## Discrete Square Root