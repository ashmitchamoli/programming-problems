#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ull n; cin >> n;
    ull x = 5;
    ull ans = 0;
    while(n/x > 0)
    {
        ans += n/x;
        x *= 5;
    }
    cout << ans;
}