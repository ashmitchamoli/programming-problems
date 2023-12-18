#include <bits/stdc++.h>

using namespace std;


long long mod = 998244353;

vector<long long> traverse(long long curr, vector<long long>& S, vector<vector<long long>>& W, vector<vector<long long>>& L, vector<vector<long long>>& dp) {
    if(dp[curr][0] != -1) {
        return dp[curr];
    }
    if(S[curr] == 0) {
        return {0, 0, 0};
    }
    vector<long long> ans = {0, 0, 0};
    for(long long j = 0; j < S[curr]; j++) {
        vector<long long> temp = traverse(L[curr][j], S, W, L, dp);
        if(W[curr][j] == 1) {
            ans[0]++;
        }
        else {
            ans[2] += ans[0];
            ans[1]++;
        }
        ans[2] = ans[2]%mod;
        ans[2] += (ans[0]*temp[1])%mod + temp[2];
        ans[1] += temp[1];
        ans[0] += temp[0];
        ans[2] = ans[2]%mod;
        ans[1] = ans[1]%mod;
        ans[0] = ans[0]%mod;
    }
    return (dp[curr] = ans);
}

int main() {
    long long n; cin >> n;
    vector<long long> S(n);
    vector<vector<long long>> W(n);
    vector<vector<long long>> L(n);

    for(long long i = 0; i < n; i++) {
        cin >> S[i];
        for(long long j = 0; j < S[i]; j++) {
            long long x, y; cin >> x >> y;
            x--;
            W[i].push_back(y);
            L[i].push_back(x);
        }
    }

    vector<vector<long long>> dp(n, vector<long long>{-1, -1, -1});

    traverse(0, S, W, L, dp);
    cout << dp[0][2];
}