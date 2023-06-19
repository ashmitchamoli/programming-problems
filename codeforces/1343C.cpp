#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        int k = 1;
        for(int i = n-1; i > 0; i--) {
            if(a[i] * a[i-1] < 0) k++;
        }
        long long max_yet = a[0];
        long long ans = 0;
        for(int i = 1; i < n; i++) {
            if(a[i] * a[i-1] > 0) {
                if(a[i] > max_yet) max_yet = a[i];
                // cout << max_yet << "\n";
            }
            else {
                ans += max_yet;
                max_yet = a[i];
            }
        }
        ans += max_yet;
        cout << ans << "\n";
    }
    
}