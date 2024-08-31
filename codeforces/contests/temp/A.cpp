#include <bits/stdc++.h>
using namespace std;

int main () {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string s; cin >> s;

		vector<int> counts(4, 0);
		for(char c: s) {
			if (c == '?') continue;
			counts[c-'A']++;
		}

		int ans = 0;
		for (int x: counts) {
			ans += min(n, x);
		}

		cout << ans << "\n";
	}
}