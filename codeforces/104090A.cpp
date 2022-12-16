#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    /*
    sum(a) + ns + dn(n+1)/2
    */
    ll n, m; cin >> n >> m;
    ll a[n];
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        sum = sum%m;
    }
    ll t = (n*(n+1))/2;
    t = t%m;
}