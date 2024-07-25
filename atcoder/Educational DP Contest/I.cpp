#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<double> p(n);
    for(auto& x: p) {
        cin >> x;
    }

    vector<vector<double>> dp(n, vector<double>((n-1)/2 + 1, 1));

    for(int T = 0; T <= (n-1)/2; T++) {
        dp[0][T] = (T==0 ? p[0] : 1);
        for(int i = 1; i < n; i++) {
            if(T==0) {
                dp[i][0] = p[i] * dp[i-1][0];
                continue;
            }
            dp[i][T] = p[i] * dp[i-1][T] + (1-p[i]) * dp[i-1][T-1];
        }
    }
    cout << setprecision(10) << dp[n-1][(n-1)/2];
}