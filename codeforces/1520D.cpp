#include<bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<long long> counts(2*n+1, 0);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] -= i-n;
            counts[a[i]]++;
        }
        // for(auto x : counts) cout << x << " ";
        // cout << "\n";
        long long ans = 0;
        for(int i = 0; i < 2*n+1; i++) {
            ans += ((counts[i] * (counts[i] - 1))/2);
        }
        cout << ans << "\n";
    }
}