#include <bits/stdc++.h>

using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string s; cin >> s;
        vector<int> a(n+1, 0);

        set<int> ind;
        for(int i = 1; i < n; i++) {
            if(s[i] < s[i-1]) {
                ind.insert(i);
            }
        }

        int ans = 0;
        bool sisthere = false;
        vector<vector<bool>> done(n, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            int l, r; cin >> l >> r;
            l--; r--;
            if(done[l][r]) continue;
            done[l][r] = true;
            if(s[r] == '0') ans++;
        }
        cout << ans << "\n";

    }
}