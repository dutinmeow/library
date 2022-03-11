---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-util.hpp
    title: Graph Utility
  - icon: ':heavy_check_mark:'
    path: utility/chmin.hpp
    title: Chmin
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
    title: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/chmin.hpp\"\ntemplate<typename T>\nbool chmin(T\
    \ &a, T b) {\n\tif (a > b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n\
    }\n#line 1 \"graph/graph-util.hpp\"\nusing u_graph = vector<vector<int>>;\n\n\
    using u_edgelist = vector<pair<int, int>>;\n\nusing u_matgraph = vector<vector<bool>>;\n\
    \nu_graph to_graph(size_t n, const u_edgelist &E) {\n\tu_graph G(n);\n\tfor (auto\
    \ [u, v] : E)\n\t\tG[u].push_back(v);\n\treturn G;\n}\n\nu_graph to_graph(const\
    \ u_matgraph &M) {\n\tsize_t n = M.size();\n\tu_graph G(n);\n\tfor (int u = 0;\
    \ u < n; u++)\n\t\tfor (int v = 0; v < n; v++)\n\t\t\tif (M[u][v])\n\t\t\t\tG[u].push_back(v);\n\
    \treturn G;\n}\n\nu_edgelist to_edgelist(const u_graph &G) {\n\tsize_t n = G.size();\n\
    \tu_edgelist E;\n\tfor (int u = 0; u < n; u++) \n\t\tfor (int v : G[u])\n\t\t\t\
    E.emplace_back(u, v);\n\treturn E;\n}\n\nu_edgelist to_edgelist(const u_matgraph\
    \ &M) {\n\tsize_t n = M.size();\n\tu_edgelist E;\n\tfor (int u = 0; u < n; u++)\n\
    \t\tfor (int v = 0; v < n; v++)\n\t\t\tif (M[u][v])\n\t\t\t\tE.emplace_back(u,\
    \ v);\n\treturn E;\n}\n\nu_matgraph to_matgraph(const u_graph &G) {\n\tint n =\
    \ G.size();\n\tu_matgraph M(n, vector<bool>(n, false));\n\tfor (int u = 0; u <\
    \ n; u++)\n\t\tfor (int v : G[u])\n\t\t\tM[u][v] = true;\n\treturn M;\n}\n\nu_matgraph\
    \ to_matgraph(size_t n, const u_edgelist &E) {\n\tu_matgraph M(n, vector<bool>(n,\
    \ false));\n\tfor (auto [u, v] : E)\n\t\tM[u][v] = true;\n\treturn M;\n}\n\ntemplate<typename\
    \ T>\nusing graph = vector<vector<pair<int, T>>>;\n\ntemplate<typename T>\nusing\
    \ edgelist = vector<tuple<int, int, T>>;\n\ntemplate<typename T>\nusing matgraph\
    \ = vector<vector<T>>;\n\ntemplate<typename T>\ngraph<T> to_graph(size_t n, const\
    \ edgelist<T> &E) {\n\tgraph<T> G(n);\n\tfor (auto [u, v, w] : E)\n\t\tG[u].emplace_back(v,\
    \ w);\n\treturn G;\n}\n\ntemplate<typename T>\ngraph<T> to_graph(const matgraph<T>\
    \ &M, const T dval) {\n\tsize_t n = M.size();\n\tgraph<T> G(n);\n\tfor (int u\
    \ = 0; u < n; u++)\n\t\tfor (int v = 0; v < n; v++)\n\t\t\tif (M[u][v] != dval)\n\
    \t\t\t\tG[u].emplace_back(v, M[u][v]);\n\treturn G;\n}\n\ntemplate<typename T>\n\
    edgelist<T> to_edgelist(const graph<T> &G) {\n\tsize_t n = G.size();\n\tedgelist<T>\
    \ E;\n\tfor (int u = 0; u < n; u++)\n\t\tfor (auto [v, w] : G[u])\n\t\t\tE.emplace_back(u,\
    \ v, w);\n\treturn E;\n}\n\ntemplate<typename T>\nedgelist<T> to_edgelist(const\
    \ matgraph<T> &M, const T dval) {\n\tsize_t n = M.size();\n\tedgelist<T> E;\n\t\
    for (int u = 0; u < n; u++)\n\t\tfor (int v = 0; v < n; v++)\n\t\t\tif (M[u][v]\
    \ != dval)\n\t\t\t\tE.emplace_back(u, v, M[u][v]);\n\treturn E;\n}\n\ntemplate<typename\
    \ T>\nmatgraph<T> to_matgraph(const graph<T> &G, const T dval) {\n\tsize_t n =\
    \ G.size();\n\tmatgraph<T> M(n, vector<T>(n, dval));\n\tfor (int u = 0; u < n;\
    \ u++)\t\n\t\tfor (auto [v, w] : G[u])\n\t\t\tM[u][v] = w;\n\treturn M;\n}\n\n\
    template<typename T>\nmatgraph<T> to_matgraph(size_t n, const edgelist<T> &E,\
    \ const T dval) {\n\tmatgraph<T> M(n, vector<T>(n, dval));\n\tfor (auto [u, v,\
    \ w] : E)\n\t\tM[u][v] = w;\n\treturn M;\n}\n#line 3 \"graph/floyd-warshall.hpp\"\
    \n\ntemplate<typename T>\nvoid floyd_warshall(matgraph<T> &G, const T dval) {\n\
    \tsize_t n = G.size();\n\tfor (int i = 0; i < n; i++)\n\t\tG[i][i] = 0;\n\tfor\
    \ (int k = 0; k < n; k++)\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (int j =\
    \ 0; j < n; j++)\n\t\t\t\tif (G[i][k] != dval && G[k][j] != dval) {\n\t\t\t\t\t\
    if (G[i][j] == dval)\n\t\t\t\t\t\tG[i][j] = G[i][k] + G[k][j];\n\t\t\t\t\telse\
    \ \n\t\t\t\t\t\tchmin(G[i][j], G[i][k] + G[k][j]);\n\t\t\t\t}\n}\n"
  code: "#include \"utility/chmin.hpp\"\n#include \"graph/graph-util.hpp\"\n\ntemplate<typename\
    \ T>\nvoid floyd_warshall(matgraph<T> &G, const T dval) {\n\tsize_t n = G.size();\n\
    \tfor (int i = 0; i < n; i++)\n\t\tG[i][i] = 0;\n\tfor (int k = 0; k < n; k++)\n\
    \t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (int j = 0; j < n; j++)\n\t\t\t\tif\
    \ (G[i][k] != dval && G[k][j] != dval) {\n\t\t\t\t\tif (G[i][j] == dval)\n\t\t\
    \t\t\t\tG[i][j] = G[i][k] + G[k][j];\n\t\t\t\t\telse \n\t\t\t\t\t\tchmin(G[i][j],\
    \ G[i][k] + G[k][j]);\n\t\t\t\t}\n}"
  dependsOn:
  - utility/chmin.hpp
  - graph/graph-util.hpp
  isVerificationFile: false
  path: graph/floyd-warshall.hpp
  requiredBy: []
  timestamp: '2022-02-04 21:19:28-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/floyd-warshall.all-pairs-shortest-path.test.cpp
documentation_of: graph/floyd-warshall.hpp
layout: document
title: Floyd-Warshall Algorithm
---

## Floyd-Warshall Algorithm

### Summary

Finds the shortest path between all nodes in $\mathcal{O}(n^3)$ time, where $n$ is the number of nodes. Works for both undirected and directed graphs. For nodes that have a potentially infinitly low distance (e.g. there exists some negative cycle), returns $-\infty$.

### Parameters
- `G &graph`: An adjacency matrix 
- `long long INF`: Some value of infinity used to denote that an edge does not exist between two nodes.  