#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--)
	{
		int n, k; cin >> n >> k;
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		if (k == 2) {
			cout << n-1 << endl;
			continue;
		}
		int ans = 0;
		cout << n/(k-1) + (n%(k-1) > 1) << endl;
	}
}