#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    sort(coins.begin(), coins.end());

    vector<vector<int>> dp(x+1, vector<int>(n, 0));
    for(int i = 0; i < n; i++) dp[0][i] = 1;
    for(int i = 0; i <= x; i++) dp[i][0] = (i%coins[0] == 0);

    for(int i = 1; i <= x; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] += dp[i][j-1];
            int k = 1;
            while(k*coins[j] <= i) {
                dp[i][j] += dp[i-k*coins[j]][j-1];
                k++;
            }
        }
    }

    cout << dp[x][n-1] << "\n";
}