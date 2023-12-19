#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    sort(coins.begin(), coins.end());

    vector<int> dp(x+1, 0);
    dp[0] = 1;

    int mod = 1e9 + 7;
    for(int i = 0; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if ( i < coins[j] ) continue;
            dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
            dp[i] %= mod;
        }
    }

    cout << dp[x] << "\n";
}