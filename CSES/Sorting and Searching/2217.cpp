#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n+1);
    vector<int> ind(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ind[a[i]] = i;
    }
    bool done[n+1] = {false};
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int x = a[i];
        ans += (!done[x-1]);
        done[x] = true;
    }
    while(m--) {
        int x, y; cin >> x >> y;
        int temp = ans;
        x = a[x];
        y = a[y];
        
        cout << temp << "\n";
    }

}