#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // for(ll i = 0; i < n; i++) cout << a[i] << " ";
    // cout << "\n";
    // for(ll i = 0; i < m; i++) cout << b[i] << " ";
    // cout << "\n";

    ll i = n-1, j = m-1;
    ll count = 0;

    while(i >= 0 && j >= 0) {
        ll diff = a[i] - b[j];
        if(diff >= 0) {
            if(diff <= k) {
                i--; j--; count++;
            }
            else {
                i--;
            }
        }
        else if(diff < 0) {
            if(diff >= -k) {
                i--; j--; count++;
            }
            else {
                j--;
            }
        }
        // cout << i << " " << j << "\n";
    }

    cout << count;
}