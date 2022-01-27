#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/binary-index-tree.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	Fentree<long long> bit(N);
	while (Q--) {
		int t; cin >> t;
		if (t == 0) {
			int i; long long v;
			cin >> i >> v;
			bit.update(i, v);
		} else if (t == 1) {
			int l, r;
			cin >> l >> r;
			cout << bit.query(l, r) << '\n';
		}
	}
}