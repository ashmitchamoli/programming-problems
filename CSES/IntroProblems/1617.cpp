#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007ULL;

typedef unsigned long long ull;

ull binexp(int n)
{
    if(n == 1)
    {
        return 2;
    }
    if(n == 0)
    {
        return 1;
    }
    ull x = binexp(n/2) % mod;
    if(n%2)
    {
        ull y = (x*x) % mod;
        return (2*y) % mod;
    }
    else
    {
        return (x*x)%mod;
    }
}

int main()
{
    int n; cin >> n;

    cout << binexp(n);
}