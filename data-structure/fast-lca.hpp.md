---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse-table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fast-lca.yosupo-lowest-common-ancestor.test.cpp
    title: verify/fast-lca.yosupo-lowest-common-ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/sparse-table.hpp\"\ntemplate<typename T>\n\
    class SparseTable {\n\tsize_t n, logn;\n\tvector<vector<T>> table;\n\npublic:\n\
    \tSparseTable() = default;\n\n\ttemplate<typename I>\n\tSparseTable(I l, I r)\
    \ { init(l, r); }\n\n\ttemplate<typename I>\n\tvoid init(I l, I r) {\n\t\tn =\
    \ distance(l, r), logn = 32 - __builtin_clz(n);\n\t\ttable.assign(logn, vector<T>(n));\n\
    \t\tcopy(l, r, table[0].begin());\n\t\tfor (int k = 1; k < logn; k++)\n\t\t\t\
    for (int i = 0; i + (1 << k) <= n; i++)\n\t\t\t\ttable[k][i] = min(table[k - 1][i],\
    \ table[k - 1][i + (1 << (k - 1))]);\n\t}\n\n\tT query(int l, int r) {\n\t\tint\
    \ k = 31 - __builtin_clz(r - l + 1);\n\t\treturn min(table[k][l], table[k][r -\
    \ (1 << k) + 1]);\n\t}\n};\n#line 2 \"data-structure/fast-lca.hpp\"\n\nclass LowestCommonAncestor\
    \ {\n\tSparseTable<pair<int, int>> st;\n\tvector<int> pos;\n\npublic:\n\tLowestCommonAncestor()\
    \ = default;\n\n\tLowestCommonAncestor(const vector<vector<int>> &tree) { init(tree);\
    \ }\n\n\ttemplate<typename T>\n\tLowestCommonAncestor(const vector<vector<pair<int,\
    \ T>>> &tree) { init(tree); }\n\n\tvoid init(const vector<vector<int>> &tree)\
    \ {\n\t\tint n = tree.size();\n\t\tpos.resize(n);\n\t\tvector<pair<int, int>>\
    \ A;\n\t\tA.reserve(2 * n);\n\n\t\tconst auto dfs = [&](const auto &self, int\
    \ u, int d = 0, int p = -1) -> void {\n\t\t\tpos[u] = A.size();\n\t\t\tA.emplace_back(d,\
    \ u);\n\t\t\tfor (int v : tree[u]) {\n\t\t\t\tif (v == p)\n\t\t\t\t\tcontinue;\n\
    \t\t\t\tself(self, v, d + 1, u);\n\t\t\t\tA.emplace_back(d, u);\n\t\t\t}\n\t\t\
    };\n\n\t\tdfs(dfs, 0);\n\n\t\tst.init(A.begin(), A.end());\n\t}\n\n\ttemplate<typename\
    \ T>\n\tvoid init(const vector<vector<pair<int, T>>> &tree) {\n\t\tint n = tree.size();\n\
    \t\tpos.resize(n);\n\t\tvector<pair<int, int>> A;\n\t\tA.reserve(2 * n);\n\n\t\
    \tconst auto dfs = [&](const auto &self, int u, int d = 0, int p = -1) -> void\
    \ {\n\t\t\tpos[u] = A.size();\n\t\t\tA.emplace_back(d, u);\n\t\t\tfor (auto [v,\
    \ w] : tree[u]) {\n\t\t\t\tif (v == p)\n\t\t\t\t\tcontinue;\n\t\t\t\tself(self,\
    \ v, d + 1, u);\n\t\t\t\tA.emplace_back(d, u);\n\t\t\t}\n\t\t};\n\n\t\tdfs(dfs,\
    \ 0);\n\n\t\tst.init(A.begin(), A.end());\n\t}\n\n\tint query(int u, int v) {\n\
    \t\tif (pos[u] > pos[v])\n\t\t\tswap(u, v);\n\t\tauto [d, a] = st.query(pos[u],\
    \ pos[v]);\n\t\treturn a;\n\t}\n\n\tint operator()(int u, int v) { return query(u,\
    \ v); }\n};\n"
  code: "#include \"data-structure/sparse-table.hpp\"\n\nclass LowestCommonAncestor\
    \ {\n\tSparseTable<pair<int, int>> st;\n\tvector<int> pos;\n\npublic:\n\tLowestCommonAncestor()\
    \ = default;\n\n\tLowestCommonAncestor(const vector<vector<int>> &tree) { init(tree);\
    \ }\n\n\ttemplate<typename T>\n\tLowestCommonAncestor(const vector<vector<pair<int,\
    \ T>>> &tree) { init(tree); }\n\n\tvoid init(const vector<vector<int>> &tree)\
    \ {\n\t\tint n = tree.size();\n\t\tpos.resize(n);\n\t\tvector<pair<int, int>>\
    \ A;\n\t\tA.reserve(2 * n);\n\n\t\tconst auto dfs = [&](const auto &self, int\
    \ u, int d = 0, int p = -1) -> void {\n\t\t\tpos[u] = A.size();\n\t\t\tA.emplace_back(d,\
    \ u);\n\t\t\tfor (int v : tree[u]) {\n\t\t\t\tif (v == p)\n\t\t\t\t\tcontinue;\n\
    \t\t\t\tself(self, v, d + 1, u);\n\t\t\t\tA.emplace_back(d, u);\n\t\t\t}\n\t\t\
    };\n\n\t\tdfs(dfs, 0);\n\n\t\tst.init(A.begin(), A.end());\n\t}\n\n\ttemplate<typename\
    \ T>\n\tvoid init(const vector<vector<pair<int, T>>> &tree) {\n\t\tint n = tree.size();\n\
    \t\tpos.resize(n);\n\t\tvector<pair<int, int>> A;\n\t\tA.reserve(2 * n);\n\n\t\
    \tconst auto dfs = [&](const auto &self, int u, int d = 0, int p = -1) -> void\
    \ {\n\t\t\tpos[u] = A.size();\n\t\t\tA.emplace_back(d, u);\n\t\t\tfor (auto [v,\
    \ w] : tree[u]) {\n\t\t\t\tif (v == p)\n\t\t\t\t\tcontinue;\n\t\t\t\tself(self,\
    \ v, d + 1, u);\n\t\t\t\tA.emplace_back(d, u);\n\t\t\t}\n\t\t};\n\n\t\tdfs(dfs,\
    \ 0);\n\n\t\tst.init(A.begin(), A.end());\n\t}\n\n\tint query(int u, int v) {\n\
    \t\tif (pos[u] > pos[v])\n\t\t\tswap(u, v);\n\t\tauto [d, a] = st.query(pos[u],\
    \ pos[v]);\n\t\treturn a;\n\t}\n\n\tint operator()(int u, int v) { return query(u,\
    \ v); }\n};"
  dependsOn:
  - data-structure/sparse-table.hpp
  isVerificationFile: false
  path: data-structure/fast-lca.hpp
  requiredBy: []
  timestamp: '2022-04-08 11:25:52-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fast-lca.yosupo-lowest-common-ancestor.test.cpp
documentation_of: data-structure/fast-lca.hpp
layout: document
title: Fast Lowest Common Ancestor
---

## Fast Lowest Common Ancestor