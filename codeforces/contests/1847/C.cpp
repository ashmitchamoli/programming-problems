#include<bits/stdc++.h>

using namespace std;

int main ()  {
    int __; cin >> __;
    while(__--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int maxnum = a[n-1];
        for(int i = n-2; i >= 0; i--) {
            a[i] = a[i] ^ a[i+1];
            maxnum = max(maxnum, a[i]);
        }
        int ans = maxnum;
        for(int i = 0; i < n; i++)  {
            ans = max(ans, maxnum ^ a[i]);
        }
        cout << ans << "\n";

    }
}