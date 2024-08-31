#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x; cin >> n >> x;

	vector<int> h(n), s(n);

	for (int i = 0; i < n; i++) cin >> h[i];
	for (int i = 0; i < n; i++) cin >> s[i];

	vector<vector<int>> dp(x+1, vector<int>(n, 0)); 
	
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= x; j++) {
			if (h[i] <= j) {
				dp[j][i] = max(dp[j][i-1], s[i] + dp[j-h[i]][i-1]);
			}
			else {
				dp[j][i] = dp[j][i-1];
			}
		}
	}

	cout << dp[x][n-1];

	return 0;
}