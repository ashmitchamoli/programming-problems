#include <bits/stdc++.h>
using namespace std;

int main() {
	int _; cin >> _;
	while (_--) {
		int n; cin >> n;
		set<int> x0, x1;
		int ans0 = 0, ans1 = 0;
		for (int i = 0; i < n; i++) {
			int x, y; cin >> x >> y;
			if (y == 0) {
				if (x1.find(x) != x1.end()) {
					ans0++;
					ans1++;
				}
				x0.insert(x);
			}
			else {
				if (x0.find(x) != x0.end()) {
					ans0++;
					ans1++;
				}
				x1.insert(x);
			}
		}

		int ans = 0;
		for (auto x : x1) {
			if (x0.find(x - 1) != x0.end() && x0.find(x + 1) != x0.end()) {
				ans++;
			}
		}
		for (auto x : x0) {
			if (x1.find(x - 1) != x1.end() && x1.find(x + 1) != x1.end()) {
				ans++;
			}
		}

		cout << ans0 * (x0.size() - 1) + ans1 * (x1.size() - 1) + ans << endl;
	}
}