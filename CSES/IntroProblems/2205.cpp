#include <bits/stdc++.h>

using namespace std;

/*
recursive
vector<string> solve(int n)
{
    if(n == 1)
    {
        vector<string> ans(2);
        ans[0] = "0"; ans[1] = "1";
        return ans;
    }
    vector<string> prev = solve(n-1);
    vector<string> ans;
    for(string s : prev)
    {
        ans.push_back("0" + s);
    }
    for(int i = (1<<(n-1)) - 1; i > -1; i--)
    {
        ans.push_back("1" + prev[i]);
    }
    return ans;
}
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    
    for(int i = 0; i < (1<<n); i++)
    {
        cout << (i>>(n-1));
        for(int j = n-2; j > -1; j--)
        {
            cout << (((i>>(j+1)) ^ (i>>j)) & 1);
        }
        cout << "\n";
    }
}