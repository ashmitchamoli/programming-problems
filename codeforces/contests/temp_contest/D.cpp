#include <bits/stdc++.h>
using namespace std;

int main () {
	int _; cin >> _;
	while (_--) {
		int n; cin >> n;
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			p[i]--;
		}
		string s; cin >> s;

		vector<bool> isVisited(n, false);
		vector<int> ans(n, 0);
		for (int i = 0; i < n; i++) {
			if (isVisited[i]) continue;

			int blackCount = s[i] == '0';
			int currNode = i;
			while (p[currNode] != i) {
				currNode = p[currNode];
				blackCount += s[currNode] == '0';
			}

			currNode = i;
			while(p[currNode] != i) {
				currNode = p[currNode];
				isVisited[currNode] = true;
				ans[currNode] = blackCount;
			}

			// cout << "hello" << endl;
			
			isVisited[i] = true;
			ans[i] = blackCount;
		}

		for (int x : ans) cout << x << " ";
		cout << "\n";
	}
}