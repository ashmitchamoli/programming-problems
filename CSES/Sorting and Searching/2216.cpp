#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int x;
    bool done[n+1] = {false};
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> x;
        ans += (!done[x-1]);
        done[x] = true;
    }
    cout << ans;
}