#include <bits/stdc++.h>
using namespace std;

int main() {
	int _; cin >> _;
	while(_--) {
		int n; cin >> n;
		vector<int> x(n);
		for (auto& i: x) cin >> i;

		if (n > 2) {
			cout << "NO\n";
		}
		if (n == 1) {
			cout << "YES\n";
		}
		if (n == 2) {
			if (x[0] == x[1] - 1) {
				cout << "NO\n";
			}
			else {
				cout << "YES\n";
			}
		}
	}

	return 0;
}