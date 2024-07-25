#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    sort(coins.begin(), coins.end());

    vector<int> dp(x+1, -1);
    dp[0] = 0;

    for(int i = 1; i < x+1; i++) {
        int j = 0;
        while( coins[j] <= i && j < n ) {
            if (dp[i - coins[j]] == -1) {j++; continue;}
            if(dp[i] == -1) dp[i] = dp[i - coins[j]] + 1;
            else dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            j++;
        }
    }

    cout << dp[x] << "\n";
}