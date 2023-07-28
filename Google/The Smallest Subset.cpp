#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int _; cin >> _;
    while(_--) {
        int n; cin >> n;
        vector<int> a(n);
        for(auto& x: a) cin >> x;
        int ans = 0;
        int bor = 0;
        int max_bor = 0;
        
        sort(a.rbegin(), a.rend());
        
        for(int i = 0; i < n; i++)  {
            int temp = a[i] | bor;
            if(temp > bor) {
                ans++;
                bor |= a[i];
            }
            if(bor == a[i]) {
                ans = 1;
            }
        }
        
        cout << ans << ' ' << bor << "\n";
    }    
}
/*
7 
91 29 58 45 51 74 70
1
47
5
1 2 3 4 5
6
34 48 8 72 67 90
*/