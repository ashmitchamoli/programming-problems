#include <bits/stdc++.h>
using namespace std;

int main() {
	int _; cin >> _;
	while (_--) {
		int n; cin >> n;
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;

			for (int j = 1; j <= 4; j++) {
				if (s[j-1] == '#') {
					ans.push_back(j);
					break;
				}
			}
		}

		for (int i = n-1; i >= 0; i--) {
			cout << ans[i] << " ";
		} 
		cout << endl;
	}
}