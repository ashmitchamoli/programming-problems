	#include <bits/stdc++.h>
	using namespace std;

	int main () {
		int t; cin >> t;
		while(t--) {
			int n; cin >> n;
			vector<long long> arr(n);
			for (auto& x: arr) {
				cin >> x;
			}

			bool allOdds = true, allEvens = true;
			for (auto x: arr) {
				if(x%2 == 0) {
					allOdds = false;
					break;
				}
			}
			if (allOdds) {
				cout << "0\n";
				continue;
			}

			for (auto x: arr) {
				if(x%2 == 1) {
					allEvens = false;
					break;
				}
			}
			if (allEvens) {
				cout << "0\n";
				continue;
			}

			sort(arr.begin(), arr.end());
			long long ans = 0, greatestOdd = -1, greatestEven = -1;
			for (int i = n-1; i >= 0; i--) {
				if (arr[i]%2) {
					greatestOdd = arr[i];
					break;
				}
			}
			for (int i = n-1; i >= 0; i--) {
				if (arr[i]%2 == 0) {
					greatestEven = arr[i];
					break;
				}
			}
			
			// cout << greatestEven << " | ";

			for (int i = 0; i < n; i++) {
				// cout << greatestOdd << " " << arr[i] << " | ";	
				if (arr[i]%2 == 0) {
					if (greatestOdd < arr[i]) {
						ans += 2;
						greatestOdd = greatestOdd + arr[i] + greatestEven;
					}
					else {
						ans++;
						greatestOdd += arr[i];
					}
				}
				else {
					greatestOdd = max(greatestOdd, arr[i]);
				}
			}

			cout << ans << "\n";
		}
	}