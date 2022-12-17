#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        ll y, x; cin >> y >> x;
        ll start, displacement, sign, bit;
        if(y < x)
            bit = (x%2 == 0 ? 1 : 0);

        if(y >= x)
            bit = y%2;
        
        ll A = max(x, y); ll B = min(x, y);

        start = A*A - 2*bit*(A - 1);
        displacement = B; 
        sign = -1 + 2*bit;
        cout << start + sign*(displacement - 1) << "\n"; 
    }
}