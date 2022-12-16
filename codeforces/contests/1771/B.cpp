#include <bits/stdc++.h>

using namespace std;


int min(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}

typedef long long ll;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        int suf[n];
        for(int i = 0; i < n; i++)
        {
            suf[i] = n;
        }
        for(int i = 0; i < m; i++)
        {
            int x, y; cin >> x >> y;
            x--; y--;
            if(x > y)
            {
                int intaskdj = x; x = y; y = intaskdj;
            }
            suf[x] = min(suf[x], y);
        }
        for(int i = n - 2; i > -1; i--)
        {
            suf[i] = min(suf[i], suf[i+1]);
        }

        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += (ll)suf[i] - (ll)i;
        }
        cout << ans << "\n";
    } 
}