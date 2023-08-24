#include <bits/stdc++.h>

using namespace std;

int findLongestPath(int curr, vector<bool>& isVisited, vector<int>& dp, vector<vector<int>>& graph) {

    if(isVisited[curr]) {
        cout << "Cycle hai " << curr << "\n";
    }
    
    isVisited[curr] = true;

    if(dp[curr] != -1) {
        return dp[curr];
    }

    int ans = -1;
    for(int node: graph[curr]) {
        ans = max(ans, findLongestPath(node, isVisited, dp, graph));
    }

    isVisited[curr] = false;

    return (dp[curr] = ans+1);
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        graph[x-1].push_back(y-1);
    }

    vector<int> dp(n, -1);
    vector<bool> isVisited(n, false);

    int ans = -1;
    for(int i = 0; i < n; i++) {
        if(dp[i] == -1) {
            findLongestPath(i, isVisited, dp, graph);
        }
        ans = max(dp[i], ans);
    }   
    cout << ans;
}