#include <bits/stdc++.h>

using namespace std;

int main () {
    int _; cin >> _;
    while(_--) {
        long long n; cin >> n;
        vector<pair<long long, long long>> a(n);
        for(long long i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        
        vector<long long> prefix(n+1, 0);
        
        for(long long i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + a[i].first;
        }
        vector<long long> ans(n);
        for(long long i = 0; i < n; i++) {
            ans[a[i].second] = (a[i].first+1)*i + prefix[n] - 2*prefix[i] - (a[i].first - 1)*(n-i);
        }
        for(auto x: ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
}