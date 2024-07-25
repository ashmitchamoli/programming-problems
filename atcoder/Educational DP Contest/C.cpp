#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<vector<int>> dp(n, vector<int>(3, -1));
    dp[0][0] = max(b[0], c[0]);
    dp[0][1] = max(a[0], c[0]);
    dp[0][2] = max(b[0], a[0]);
    for(int i = 1; i < n; i++) {
        dp[i][0] = max(b[i] + dp[i-1][1], c[i] + dp[i-1][2]);
        dp[i][1] = max(a[i] + dp[i-1][0], c[i] + dp[i-1][2]);
        dp[i][2] = max(b[i] + dp[i-1][1], a[i] + dp[i-1][0]);
    }
    cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]); 
}