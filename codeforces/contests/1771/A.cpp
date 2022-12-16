#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        long long n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a+n);
        int a1 = a[0], an = a[n-1];
        long long cj = 0, ci = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(a[i] == a1) ci++;
            if(a[i] == an) cj++;
        }
        long long t_ = ci*cj*2LL;
        if(ci == n)
        {
            t_ = n*(n-1);
        }
        cout << t_ << "\n";
    }
}