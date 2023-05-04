#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        ll a[n], b[m];
        for(int i = 0; i < n; i++)
        {
           cin >> a[i]; 
        }
        for(int i = 0; i < m; i++)
        {
           cin >> b[i];
        }

        sort(a, a+n);
        // sort(b, b+m);
        ll ans = 0;
        int k = 0;
        for(int i = 0; i < m; i++)
        {
            int mini = 0;
            for(int j = 0; j < n; j++)
            {
                if(a[j] < a[mini]) mini = j;
            }
            a[mini] = b[i];
        }
        for(int i = 0; i < n; i++) ans+=a[i];
        cout << ans << "\n";
    }
}