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
        if(y == x+1 || x == y+1) {
            temp+=(y-x);
            cout << temp << "\n";
            continue;
        }
        for(int i: vector<int>{-1, 1}) {
            if(x+i > 0 && x+i <= n && ind[x+i] > ind[x] && ind[x+i] < ind[y]) temp += i;
            if(y+i > 0 && y+i <= n && ind[y+i] > ind[x] && ind[y+i] < ind[y]) temp -= i;
        }
        cout << temp << "\n";
    }

}