#include <bits/stdc++.h>
using namespace std;

int main() {
	int MOD = 1e9 + 7;
	int n; cin >> n;
	vector<string> grid(n, "");
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	if (grid[n-1][n-1] == '*') {
		cout << 0;
		return 0;
	}

	vector<vector<int>> dp(n, vector<int>(n, 0));
	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > 0 && grid[i-1][j] != '*') {
				dp[i][j] += dp[i-1][j];
			}
			if (j > 0 && grid[i][j-1] != '*') {
				dp[i][j] += dp[i][j-1];
			}

			dp[i][j] = dp[i][j] % MOD;
		}
	}

	cout << dp[n-1][n-1];
	
	// for (auto v: dp) {
	// 	for (auto x: v) {
	// 		cout << x << " ";
	// 	}
	// 	cout << "\n";
	// }
	return 0;
}