#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(auto& x: a) cin >> x;
    vector<int> dp(n, 0);
    for(int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        for(int j = max(0, i-k); j < i; j++) {
            dp[i] = min(dp[j] + abs(a[j] - a[i]), dp[i]);
        }
    }
    cout << dp[n-1];
}