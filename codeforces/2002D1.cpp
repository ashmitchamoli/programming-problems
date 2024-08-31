#include <bits/stdc++.h>
using namespace std;

int main() {
	int _; cin >> _;
	while(_--) {
		int n, q; cin >> n >> q;
		vector<int> a(n-1);
		for (auto& i : a) cin >> i;
		
		vector<int> p(n+1), indices(n+1, -1);
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
			indices[p[i]] = i+1;
		}

		set<int> wrong;
		for (int i = 2; i <= n; i+=2) {
			int level = log2(i);

			int numNodes = n - (1 << (level + 1)) + 1;

			if (abs(indices[i] - indices[i+1]) != numNodes) {
				wrong.insert(i);
			}
		}

		for (int i = 0; i < q; i++) {
			int x, y; cin >> x >> y;

			swap(p[x], p[y]);
			int c1 = p[x], c2 = p[y];
			int s1 = c1 - (c1%2), s2 = c2 - (c2%2);
			int l1 = log2(c1), l2 = log2(c2);

			if (min(c1, c2) == max(c1, c2) + 1) {
				if (wrong.empty()) cout << "YES\n";
				else cout << "NO\n";
				continue;
			}

			if (abs(indices[s1] - y) == (n - (1 << (l1 + 1)) + 1)) {
				if (wrong.find(min(s1, c1)) != wrong.end()) {
					wrong.erase(min(s1, c1));
				}
			}
			else {
				if (wrong.find(min(s1, c1)) == wrong.end()) {
					wrong.insert(min(s1, c1));
				}
			}

			if (abs(indices[s2] - x) == (n - (1 << (l2 + 1)) + 1)) {
				if (wrong.find(min(s2, c2)) != wrong.end()) {
					wrong.erase(min(s2, c2));
				}
			}
			else {
				if (wrong.find(min(s2, c2)) == wrong.end()) {
					wrong.insert(min(s2, c2));
				}
			}

			if (wrong.empty() && (p[x] == (x < n-1 ? p[x+1] / 2 : p[x]))) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}

		cout << "\n";
	}
}