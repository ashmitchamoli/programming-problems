#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	int MOD = 1e9 + 7;
	while(t--) {
		int n, k; cin >> n >> k;
		vector<int> arr(n);
		for (auto& x: arr) cin >> x;
		int n1 = accumulate(arr.begin(), arr.end(), 0);

		int ans = 0;
		for(int i = (k+1)/2; i <= min(k, n1); i++) {

		}
	}
}