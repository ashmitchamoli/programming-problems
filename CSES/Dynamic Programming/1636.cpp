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

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= x; j++) {
            dp[j] += dp[j - coins[i]];
            dp[j] = dp[j] % 1000000007;
        }
    }

    cout << dp[x] << "\n";
}