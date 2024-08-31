#include <bits/stdc++.h>
using namespace std;

int main() {
	int _; cin >> _;
	while (_--) {
		int n, m; cin >> n >> m;
		vector<int> arr(n);
		for (auto& x: arr) cin >> x;

		sort(arr.begin(), arr.end());

		vector<pair<int, int>> q1, q2;
		for (int i = 0; i < m; i++) {
			char c; cin >> c;
			int x, y; cin >> x >> y;
 			if (c == '-') {
				q2.push_back({x, y});
			}
			else {
				q1.push_back({x, y});
			}
		}
		sort(q1.begin(), q1.end());
		sort(q2.begin(), q2.end());

		
	}

	return 0;
}