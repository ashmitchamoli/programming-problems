#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll binexp(int n)
{
    if(n == 1)
    {
        return 10;
    }
    if(n == 0)
    {
        return 1;
    }
    ll x = binexp(n/2);
    if(n%2)
    {
        ll y = (x*x);
        return (10*y);
    }
    else
    {
        return (x*x);
    }
}

int main()
{
    int q; cin >> q;
    while(q--)
    {
        ll k; cin >> k;
        ll i = 1, x = 9;
        while(k - i*x > 0)
        {
            k -= i*x;
            i++; x=x*10;
        }
        ll t = binexp(i-1) + k/i;
        if(k%i == 0) t--;
        ll n = (i - k%i)%i;
        cout << (t/binexp(n))%10 << "\n";
    }
}