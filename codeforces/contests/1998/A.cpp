#include <bits/stdc++.h>
using namespace std;

int main() {
	int _; cin >> _;
	while(_--) {
		int x0, y0, k; cin >> x0 >> y0 >> k;

		for (int i = 1; i <= k/2; i++) {
			cout << x0 - i << " " << y0 - i << "\n";
			cout << x0 + i << " " << y0 + i << "\n";
		}

		if (k%2) {
			cout << x0 << " " << y0 << "\n";
		}
	}

	return 0;
}