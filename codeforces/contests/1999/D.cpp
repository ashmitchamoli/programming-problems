#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		string s1, s2; cin >> s1 >> s2;

		int i1 = 0, i2 = 0;
		string ans = "";

		while(i1 < s1.size() && i2 < s2.size()) {
			if (s1[i1] == '?') {
				// ans += s2[i2];
				s1[i1] = s2[i2];
			}
			else if (s1[i1] == s2[i2]) {
				i1++;
				i2++;
			}
			else {
				i1++;
			}
		}

		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] == '?') s1[i] = 'x';
		}

		if (i2 == s2.size()) {
			cout << "YES\n" << s1 << "\n";
		}
		else {
			cout << "NO\n";
		}
	}
}