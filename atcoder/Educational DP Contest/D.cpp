#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, W; cin >> n >> W;
    vector<long long> w(n), v(n);
    for(long long i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(W+1, 0));
    for(long long weight = 1; weight<=W; weight++) {
        if(w[0] <= weight) {
            dp[0][weight] = v[0];
        }
        for(long long i = 1; i < n; i++) {
            if(w[i] <= weight) {
                dp[i][weight] = max(v[i] + dp[i-1][weight-w[i]], dp[i-1][weight]); 
            }
            else {
                dp[i][weight] = dp[i-1][weight];
            }
        }
    }
    cout << dp[n-1][W];
}