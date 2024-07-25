#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = (s[0] == t[0]);
    for(int i = 1; i < n; i++) dp[i][0] = max(dp[i-1][0], int(s[i] == t[0]));
    for(int i = 1; i < m; i++) dp[0][i] = max(dp[0][i-1], int(t[i] == s[0]));

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(s[i] == t[j]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i][j-1], max(dp[i-1][j-1], dp[i-1][j]));
            }
        }
    }
    int i = n-1, j = m-1;
    string ans;
    while(i >= 0 && j >= 0) {
        if(s[i] == t[j]) {
            ans.push_back(s[i]);
            i--; j--;
            continue;
        }
        if(i > 0 && dp[i][j] == dp[i-1][j]) {
            i--;
        }
        else if(j > 0 && dp[i][j] == dp[i][j-1]) {
            j--;
        }
        else{
            i--;
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}