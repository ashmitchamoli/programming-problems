#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll min(ll a, ll b)
{
    if(a > b) return b;
    return a;
}

ll abs_(ll a)
{
    if(a > 0) return a;
    else a = (-1LL) * a;
    return a;
}

int main()
{
    int n; cin >> n;
    ll w[n];
    for(int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    int bitmask = 1;
    ll ans = 1e11;
    while(bitmask < (1<<n))
    {
        ll s1 = 0, s2 = 0;
        for(int i = 0; i < n; i++)
        {
            if((bitmask>>i) & 1)
            {
                s1 += w[i];
            }
            else
            {
                s2 += w[i];
            }
        }
        // cout << s2 << " " << s1 << "\n";
        ans = min(ans, abs_(s2 - s1));
        bitmask++;
    }
    cout << ans;
}