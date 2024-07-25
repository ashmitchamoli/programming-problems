#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;

		int c0 = s[0] == '0', c1 = s[0] == '1';
		for (int i = 1; i < n; i++) {
			if (s[i] == '0' && s[i-1] != '0') c0++;
			else if (s[i] == '1') c1++;
		}

		if (c1 > c0) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
}