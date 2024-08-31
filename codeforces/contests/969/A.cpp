#include <bits/stdc++.h>
using namespace std;

int main() {
	int _; cin >> _;
	while (_--) {
		int l, r; cin >> l >> r;

		if (r - l + 1 < 3) {
			cout << "0\n";
			continue;
		}

		if (r - l + 1 == 3) {
			if (l%2) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
			continue;
		}

		if (l%2) {
			cout << (r-l+2)/4 << endl;
		}
		else {
			cout << (r-l+1)/4 << endl;
		}

		// cout << (r-l+1)/4 << endl;
	}

	return 0;
}