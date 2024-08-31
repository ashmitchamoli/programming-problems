#include <bits/stdc++.h>
using namespace std;

int main () {
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		vector<long long> arr(n);
		for (auto& x: arr) cin >> x;
		sort(arr.begin(), arr.end());

		long long maxEl = -1;
		for (int i = 0; i < n-1; i++) {
			arr[i] -= arr[n-1]%k;
			arr[i] = arr[i]%k;
			maxEl = max(maxEl, arr[i]);
		}

		if (maxEl > k) {
			cout << "-1\n";
		}
		else {
			cout << arr[n-1] + k << "\n";
		}

	}

	return 0;
}