#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, m; cin >> n >> m;
	vector<int> arr(n);
	for (auto& x: arr) cin >> x;

	vector<vector<int>> dp(n, vector<int>(m, 0));

	for(int i = 0; i < n; i++) {
		if (arr[i] != 0) continue;

		for (int j = arr[i] - 1; j <= arr[i]+1; j++) {
			if (i+1 < n && abs(j-arr[i+1]) <= 1) {
				
			}
		}
	}
}