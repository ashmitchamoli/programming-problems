#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    if(!(n%2))
    {
        cout << -1;
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        cout << n-i-1 << ' ';
    }
    cout << '\n';
    for(int i = 0; i < n; i++)
    {
        cout << (2*i + 1)%n << ' ';
    }
    cout << '\n';
    for(int i = 0; i < n; i++)
    {
        cout << i << ' ';
    }
    cout << '\n';
}