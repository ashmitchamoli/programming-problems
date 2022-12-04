#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    int x[n], h[n];
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> h[i];
    }

    int ans = min(2, n);
    int tree_info[n]; // -1 = left, 0 = stay, 1 = right
    tree_info[0] = -1; tree_info[n-1] = 1;
    for(int i = 1; i < n - 1; i++)
    {
        int lim = x[i-1] + (tree_info[i-1] == 1 ? h[i-1] : 0);
        if(lim < x[i] - h[i])
        {
            tree_info[i] = -1;
            ans++;
        }
        else if(x[i] + h[i] < x[i+1])
        {
            tree_info[i] = 1;
            ans++;
        }
        else
        {
            tree_info[i] = 0;
        }
    }
    cout << ans;
}
/* 
AC but tutorial dekha
Was on the right track with greedy but left in between
*/
