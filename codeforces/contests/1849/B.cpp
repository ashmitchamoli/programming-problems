#include <bits/stdc++.h>

using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {    
        int n, k; cin >>n >> k;
        vector<pair<int, int>> a(n);
        for(int i  = 0 ; i < n; i++) {
            cin >> a[i].first;
            a[i].first = a[i].first % k;
            a[i].second = i;
            a[i].first = -a[i].first;
            if(a[i].first == 0) {
                a[i].first = -k;
            }
        }
        sort(a.begin(), a.end());
        for(auto x: a) {
            cout << x.second +1 << " ";
        }
        cout << "\n";

    }
}