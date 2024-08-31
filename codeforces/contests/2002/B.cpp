#include <bits/stdc++.h>
using namespace std;

int main () {
	int _; cin >> _;
	while (_--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;
		
		int i1 = 0, i2 = 0, j1 = n-1, j2 = n-1;

		bool aliceWins = false;
		while (i1 != j1 && i2 != j2) {
			if (set<int>({a[i1], a[j1]}) != set<int>({b[i2], b[j2]})) {
				aliceWins = true;
				break;
			}
			if (a[i1] == b[i2]) {
				i1++;
				i2++;
			}
			else if (a[i1] == b[j2]) {
				i1++;
				j2--;
			}
			else if (a[j1] == b[i2]) {
				j1--;
				i2++;
			}
			else if (a[j1] == b[j2]) {
				j1--;
				j2--;
			}
		}
		if (aliceWins) {
			cout << "Alice\n";
		}
		else cout << "Bob\n";
	}
	return 0;
}