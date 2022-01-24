#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/recursive-segment-tree.hpp"

const int MAX = 5e5 + 5;

int N, Q;

struct stinfo {
	using T = long long;

	const T dval = 0;

	void apply(T &a, T b) { a += b; }

	T merge(T a, T b) { return a + b; }
};

Segtree<stinfo> sgt;

int main() {
	cin >> N >> Q;
	sgt.init(N);
	for (int i = 0; i < N; i++) {
		long long a; cin >> a;
		sgt.update(i, a);
	}
	while (Q--) {
		int t; cin >> t;
		if (t == 0) {
			int p; long long x;
			cin >> p >> x;
			sgt.update(p, x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << sgt.query(l, r - 1) << '\n';
		}
	}
}