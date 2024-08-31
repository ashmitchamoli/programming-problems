#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		long long n, s, m; cin >> n >> s >> m;
		vector<pair<long long, long long>> tasks(n);
		for (int i = 0; i < n; i++) {
			cin >> tasks[i].first >> tasks[i].second; 
		}

		// sort(tasks.begin(), tasks.end());

		if (n == 1) {
			int interval = tasks[0].first;
			if (interval >= s) {
				cout << "YES\n"; 
				continue;
			}
			if (m - tasks[0].second >= s) {
				cout << "YES\n";
				continue;
			}
			cout << "NO\n";
			continue;
		}

		bool ans = false;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				long long interval = tasks[i].first;
				// cout << interval << "\n";
				if (interval >= s) {
					ans = true;
					break;
				}
			}
			else if (i == n-1) {
				long long interval = tasks[i].first - tasks[i-1].second;
				if (interval >= s) {
					ans = true;
					break;
				}
				interval = m - tasks[i].second;
				if (interval >= s) {
					ans = true;
					break;
				}
			}
			else {
				long long interval = tasks[i].first - tasks[i-1].second;
				if (interval >= s) {
					ans = true;
					break;
				}
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}