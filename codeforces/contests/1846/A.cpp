#include <bits/stdc++.h>

using namespace std;

int main() {
    int __; cin >> __;
    while(__--) {
        int n; cin >> n;
        int x, y;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            if(x-y > 0) {
                ans++;
            }
        }
        cout << ans << "\n";

    }
}