#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;

    if((n%4)%3 != 0)
    {
        cout << "NO";
        return 0;
    }
    cout  << "YES\n";
    int t_n = n - (n%4)%2;
    cout << (n+1)/2 << "\n";
    for(int i = 1; i <= t_n/2; i+=2)
    {
        cout << i << " " << t_n + 1 - i << " ";
    }
    cout << "\n" << t_n/2 << "\n";
    for(int i = 2; i <=t_n/2; i+=2)
    {
        cout << i << " " << t_n + 1 - i << " ";
    }
    if(t_n == n-1) cout << n;
}