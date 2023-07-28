#include <bits/stdc++.h>

using namespace std;

int main() {
    int _;cin>>_;
    while(_--) {
        int n; cin >> n;
        vector<int> a(n);
        int minpow = (1<<30) - 1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            minpow = minpow & a[i];
        }
        if(minpow != 0) {
            cout << "1\n";
            continue;
        }
        int ans = 1;
        int currpow = (1<<30) - 1;
        for(int i = 0; i < n; i++) {
            currpow = currpow & a[i];
            if(currpow == 0) {
                currpow = (1<<30) - 1;
                ans++;
            }
        }
        cout << ans - 1 << "\n";
    }
}