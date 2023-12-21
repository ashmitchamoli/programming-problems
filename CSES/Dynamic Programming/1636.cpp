#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    sort(coins.begin(), coins.end());

    // dp(x, i) = number of ways to make x using coins[i...n-1]
    vector<vector<int>> dp(x+1, vector<int>(n, -1));
    for(int i = 0; i < n; i++) dp[0][i] = 1;
    for(int i = 0; i <= x; i++) dp[i][n-1] = (i % coins[n-1] == 0);
    
    int mod = 1e9 + 7;
    
}