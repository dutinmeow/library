### Segment Tree

### Summary

Segment Trees are a general class of online data structures, represented by a complete binary tree with the leaves built on an array such that all nodes in the tree (excluding leaves) are a function of its children. This specific implementation requires said function to be commutative (such as sum, min, max, gcd, etc.). More specifically, it supports:
- Given two indices $l, r$, it finds $\sum_{k = l}^r a_k$, or the sum of values in the range $[l, r]$.
- Given an index $i$ and a value $v$, assigns $a_i$ to $v$. 

Both these operations are performed in $\mathcal{O}(\log n)$, where $n$ is the number of elements represented by the segment tree. The total space complexity is linear (more specifically, it allocates $2n$ memory). Note that all indices are zero-based. For a similar data structure, see the [binary index tree](https://dutinmeow.github.io/library/data-structure/binary-index-tree.hpp). 

### Documentation

- `SegmentTree()`: Constructs an empty segment tree.
- `SegmentTree(int n, T v)`: Constructs a segment tree of size $n$ initialized with default value $v$. This takes $\mathcal{O}(n)$ time.
- `SegmentTree(Iterator begin, Iterator end, T v)`: Constructs a segment tree initialized with values specified by $\texttt{begin}$ and $\texttt{end}$. The default value is set to $v$. This runs in $\mathcal{O}(n)$ time.
- `T query(int l, int r)`: Returns $\sum_{k = l}^r a_k$. This runs in $\mathcal{O}(\log n)$ time.
- `T operator[](int i)`: Returns $a_i$. This runs in $\mathcal{O}(1)$ time.
- `void update(int i, T v)`: Assigns $a_i$ to value $v$. This runs in $\mathcal{O}(\log n)$. 

Note that the following methods and variables are meant to be modified or overriden. 
- `T dval`: This variable is the default value, which depends on the type of $T$ and $\texttt{merge}$ function. For any $v \neq \texttt{dval}$, $\texttt{dval}$ should satisfy $v = \texttt{merge}(v, \texttt{dval})$. For instance, a sum operator would mean that $\texttt{dval} = 0$, and a min operator would mean that $\texttt{dval} = \infty$. 
- `T merge(T a, T b)`: Specifies how values are to be combined. It takes in two values and merges them into a single value. In this specific use case, this function must be commutative (ie $\texttt{merge}(a, b) = \texttt{merge}(b, a)$). For non-commutative merge functions, see the recursive implementation of segment tree. 
- `T apply(T &a, T b)`: Applies an update with value $b$ to a node with value $a$. This will most likely always be the `=` or `+=` operator. 
