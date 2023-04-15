#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    vector<pair<ll, int>> arr;
    multiset<int> tickets;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        tickets.insert(a[i]);
    }
    for(int i = 0; i < m; i++) cin >> b[i];
    
    for(int i = 0; i < m; i++) {
        auto it = tickets.upper_bound(b[i]);
        if(it == tickets.begin()) {
            cout << -1 << "\n";
        }
        else {
            cout << *(--it) << "\n";
            tickets.erase(it);
        }
    }
}
/*
input
10 10
9 3 9 6 6 8 6 2 6 3
9 5 4 6 3 9 3 3 5 2

9 3 3 6 2 9 -1 -1 -1 -1
b[i] = {9, 9, 6, 3, 3, 2, -, -, -, -}
*/