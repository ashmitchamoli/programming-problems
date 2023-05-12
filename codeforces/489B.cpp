#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int m; cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0, ans = 0;
    while( i<n && j<m ){
        if(abs(a[i] - b[j]) <= 1) {
            i++; j++; ans++;
        }
        else if(a[i] > b[j]) {
            j++;
        }
        else {
            i++;
        }
    }
    cout << ans;
}