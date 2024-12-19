#include <bits/stdc++.h>
using namespace std;

int main() {
	int _; cin >> _;
	while (_--) {
		int n, q; cin >> n >> q;
		vector<int> arr(n);
		long long totalSum = 0;
		for (auto& x : arr) {
			cin >> x;
			totalSum += x;
		}
		vector<int> prefixSum(n, 0);
		prefixSum[0] = arr[0];
		for (int i = 1; i < n; i++) {
			prefixSum[i] += prefixSum[i-1] + arr[i];
		}

		for (int i = 0; i < q; i++) {
			long long l, r; cin >> l >> r;

			long long ans = 0;
			int x = l / n, y = l%n;
			if (y > n-x) {
				ans += prefixSum[x];
				
			}


		}
	}
}