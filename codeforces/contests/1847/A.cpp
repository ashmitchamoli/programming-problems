#include <bits/stdc++.h>

using namespace std;

int main() {
    int _; cin >> _;
    while(_--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin >> a[i];

        vector<pair<int, int>> ind(n-1);
        for(int i = 0; i < n-1; i++) {
            a[i] = abs(a[i+1] - a[i]);
            ind[i].first = a[i];
            ind[i].second = i;
        }
        sort(ind.begin(), ind.end());

        bool isIncluded[n] = {false};
        int ans = 0, i = 0;
        while(n-k > 0) {
            ans += ind[i].first;
            i++;
            k++;
        }
        cout << ans << "\n";
    }
}