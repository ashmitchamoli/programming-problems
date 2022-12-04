#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    // lets say 'x' b tickets - mx le liye n-mx bacha
    // bx + (n-mx)a = x(b-ma) + an -> minimimse this brute force lol
    int p = b - m*a;
    int q = a*n;
    int x = 0;
    int ans = INT_MAX;
    while(m*x <= n)
    {
        ans = min(ans, x*p + q);
        x++;
    }
    cout << min(ans, b*x) << '\n';
}

/* AC */