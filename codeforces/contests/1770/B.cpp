#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        for(int i = n; i > 0; i-=2)
        {
            cout << i  << " ";
        }
        for(int i = (1<<(n%2)); i <= n; i+=2)
        {
            cout << i << " ";
        }
        cout  << "\n";
    }
}