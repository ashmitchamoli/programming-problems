#include <bits/stdc++.h>
using namespace std;

int main () {
	int _; cin >> _;
	while (_--) {
		int n, m, k; cin >> n >> m >> k;

		long long ans = min(m, k);
		ans = ans * min(k, n);

		cout << ans << "\n";
	}
	return 0;
}