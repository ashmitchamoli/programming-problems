#include <bits/stdc++.h>
using namespace std;

int main() {
	int _; cin >> _;
	while(_--) {
		int n; cin >> n;
		vector<int> p(n);
		for(auto& x: p) cin >> x;

		for (int i = p.size() - 1; i < 2*p.size() - 1; i++) {
			cout << p[i%p.size()] << " ";
		}
		cout << "\n";
	}

	return 0;
}