#include <bits/stdc++.h>
using namespace std;

int main() {
	int _; cin >> _;
	while(_--) {
		int n, q; cin >> n >> q;
		map<string, set<int>> mp;
		vector<string> colors(n);

		for (int i = 0; i < n; i++) {
			string color; cin >> color;

			colors[i] = color;
			mp[color].insert(i);
		}

		for (int i = 0; i < q; i++) {
			int x, y; cin >> x >> y;

			if (x == y) {
				cout << "0\n";
				continue;
			}

			x--; y--;
			if (x > y) swap(x, y);

			if (colors[x][0] == colors[y][0] || 
				colors[x][1] == colors[y][0] || 
				colors[x][0] == colors[y][1] ||
				colors[x][1] == colors[y][1]) {
					
				cout << y - x << endl;
				continue;
			}

			int ans = INT_MAX;
			for (auto kv: mp) {
				if (kv.first == colors[x] || kv.first == colors[y]) continue;

				auto l = kv.second.lower_bound(x);
				if (l != kv.second.end()) {
					ans = min(ans, abs((*l) - x) + abs((*l) - y));
				}

				if (l != kv.second.begin()) {
					--l;
					ans = min(ans, x+y - 2 * (*l));
				}
			}

			if (ans == INT_MAX) {
				cout << "-1\n";
			}
			else {
				cout << ans << "\n";
			}
		}
	}
	
	return 0;
}