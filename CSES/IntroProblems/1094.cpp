#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n; cin >> n;
    ll x[n]; ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
        if(i > 0 && x[i] < x[i-1])
        {
            ans += (x[i-1] - x[i]);
            x[i] = x[i-1];
        }
    }
    cout << ans;
}