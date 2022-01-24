---
title: General Segment Tree
documentation_of: //data-structure/general-segment-tree.hpp
---

## General Segment Tree

### Summary

See summary of [Segment Tree](https://dutinmeow.github.io/library/data-structure/segment-tree.hpp). Note that in this case, the operations **do not** have to be commutative. 


### Preconditions

- `B` is a class with the following defined:
  - `T`: A type.
  - `const T dval`: The identity element.
  - `void apply(T &a, T b)`: Applies an update of value `b` to a node with value `a`. 
  - `T merge(T a, T b)`: Merges two nodes with values `a` and `b`. 

### Methods

- `SegTree()`: Constructs an empty `Segtree` object.
- `SegTree(size_t _n)`: Constructs a `Segtree` object with initial capacity `_n` filled with the default value.
- `void init(int _n)`: Initializes a `Segtree` object with capacity `_n` filled with the default value. 
- `void update(int i, T v)`: Updates node `i` with value `v`.
- `T query(int l, int r)`: Queries the range from `l` to `r` inclusive. 
- `T operator[](int i)`: Returns the value of the element at index `i`. 