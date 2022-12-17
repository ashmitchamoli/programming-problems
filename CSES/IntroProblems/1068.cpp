#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n; cin >> n;
    cout << n << " ";
    while(n!=1)
        cout << (n = (n%2 ? (3*n + 1) : n/2)) << " ";
    
}