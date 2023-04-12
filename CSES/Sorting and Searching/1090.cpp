#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, x; cin >> n >> x;
    vector<ll> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    sort(p.begin(), p.end());
    int i = 0, j = n-1;
    int count = 0;
    while(i < j) {
        if(p[i] + p[j] <= x) {
            i++; j--;
        } 
        else{
            j--;
        }
        count++;
    }
    if(i == j) count++; 
    cout << count;
}