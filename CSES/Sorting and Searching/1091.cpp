#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    vector<pair<ll, int>> arr;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        arr.push_back({b[i], i});
    }

    sort(a.begin(), a.end());
    sort(arr.begin(), arr.end());

    for(int i = 0; i < m; i++) b[i] = -1;

    int i = n-1, j = m-1;
    while(i >= 0 && j >= 0) {
        if(a[i] <= arr[j].first) {
            b[arr[j].second] = a[i];
            i--; j--;
        }
        else {
            i--;
        }
    }
    for(int i = 0; i < m; i++) cout << b[i] << "\n";
}
/*
10 10
9 9 8 6 6 6 6 3 3 2
9 9 6 5 5 4 3 3 3 2 

b[i] = {9, 9, 6, 3, 3, 2, -, -, -, -}
*/