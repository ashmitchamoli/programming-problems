#include <bits/stdc++.h>
using namespace std;

int main() {
	int _; cin >> _;
	while(_--) {
		int n, k; cin >> n >> k;
		vector<int> arr(n);
		for (auto& x : arr) cin >> x;
		sort(arr.begin(), arr.end(), greater<int>());

		for (int i = 1; i < n; i+=2) {
			if (k > 0) {
				int change =  min(arr[i-1] - arr[i], k);
				arr[i] += change;
				k -= change;
			}
			else {
				break;
			}
		}

		// if (k > 0) {
		// 	arr[0] += (k - k/2);
		// 	arr[1] += k/2;
		// }

		int ans = 0;
		for (int i = 1; i < n; i+=2) {
			ans += arr[i-1] - arr[i];
		}

		if (n%2){
			ans += arr[n-1];
		}

		cout << ans << "\n";
	}
	
	return 0;
}