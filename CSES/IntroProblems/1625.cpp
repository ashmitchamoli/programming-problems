#include <bits/stdc++.h>

using namespace std;

string s;

int dp[7][7];
bool isVisited[7][7];



int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    bool isVisited[7][7];
    for(int i = 0; i < 7; i++)
        for(int j = 0; j < 7; j++)
        {
            dp[i][j] = -1;
            isVisited[i][j] = false;    
        }
    
    dp[6][0] = 1;
    int ans = count(0, 0, 0);
    cout << ans;
}