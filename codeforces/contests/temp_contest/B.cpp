#include <bits/stdc++.h>
using namespace std;

int main () {
	int _; cin >> _;
	while (_--) {
		int n; cin >> n;
		string s; cin >> s;

		int sqRoot = -1;
		for (int i = 2; i*i <= n; i++) {
			if (i*i == n) {
				sqRoot = i;
			}
		}
		if (sqRoot == -1) {cout << "No\n"; continue;}
		
		bool isValid = true;
		for (int i = 0; i < sqRoot; i++) {
			if (i == 0 || i == sqRoot-1) {
				for (int k = 0; k < sqRoot; k++) {
					if (s[i*sqRoot + k] == '0') {
						isValid = false;
						break;
					}
				}
				if (! isValid) {
					break;
				}
				continue;
			}
			if (s[i*sqRoot] == '0' || s[i*sqRoot + sqRoot - 1] == '0') {
				isValid = false;
				break;
			}
			if(! isValid) break;
			for (int j = 1; j < sqRoot-1; j++) {
				if (s[i*sqRoot + j] == '1') {
					isValid = false;
					break;
				}
			}
			if (! isValid) break;
		}
		if (isValid) {
			cout << "Yes\n";
		}
		else cout << "No\n";
	}
}