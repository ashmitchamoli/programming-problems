#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;

    vector<int> dp(n+1, -1);
    dp[0] = 0;

    for (int i = 0; i <= n; i++) {
        int temp = i;
        while(temp > 0) {
            int digit = temp%10;
            if (digit == 0 || dp[i - digit] == -1) {temp /= 10; continue;}
            if(dp[i] == -1) dp[i] = dp[i - digit] + 1;
            else dp[i] = min(dp[i], dp[i - digit] + 1);
            temp /= 10;
        }
    }

    cout << dp[n] << "\n";
}