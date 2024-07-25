#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, W; cin >> n >> W;
    vector<long long> w(n), v(n);
    long long maxVal = 0;
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
        maxVal += v[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(maxVal+1, 1e9));
    for(int i = 0; i < n; i++) dp[i][0] = 0;
    for(int val = 0; val <= maxVal; val++) {
        if(v[0] == val) {
            dp[0][val] = w[0];
        }
        for(int i = 1; i < n; i++) {
            if(v[i] <= val) {
                dp[i][val] = min(w[i] + dp[i-1][val-v[i]], dp[i-1][val]);
            }
            else {
                dp[i][val] = dp[i-1][val];
            }
        }
    }
    for(int val = maxVal; val >= 0; val--) {
        if(dp[n-1][val] <= W) {
            cout << val;
            break;
        } 
    }
}