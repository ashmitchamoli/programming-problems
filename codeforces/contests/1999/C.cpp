#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		string n; cin >> n;

		int ans = 0;
		
		for (char c : n) {
			ans += c - '0';
		}

		cout << ans << "\n";
	}
}