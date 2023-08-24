#include <bits/stdc++.h>

using namespace std;

int mod = 1e9+7;

int numPaths(int i, int j, vector<string>& grid, vector<vector<int>>& dp) {
    int h = grid.size(), w = grid[0].length();
    
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    if(i == h-1 && j == w-1) {
        return 1;
    }

    int ans = 0;
    if(i+1 < h && grid[i+1][j] != '#') {
        ans += (numPaths(i+1, j, grid, dp));
        ans = ans%mod;
    }
    if(j+1 < w && grid[i][j+1] != '#') {
        ans += (numPaths(i, j+1, grid, dp));
        ans = ans%mod;
    }

    return (dp[i][j] = ans);
}

int main() {
    int h, w; cin >> h >> w;
    vector<string> grid(h);

    for(int i = 0; i < h; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> dp(h, vector<int>(w, -1));
    cout << numPaths(0, 0, grid, dp);
}