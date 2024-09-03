#include <bits/stdc++.h>
using namespace std;

int main () {
	int _; cin >> _;
	while (_--) {
		int l, r; cin >> l >> r;
		cout << (int)((sqrt((double) 8 * (double)(r-l) + 1.0) - 1.0)/2.0) + 1 << "\n";
	}
}