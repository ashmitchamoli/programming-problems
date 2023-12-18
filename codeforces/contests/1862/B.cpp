#include <bits/stdc++.h>

using namespace std;

int main() {
    int _; cin >> _;
    while(_--) {
        int n; cin >> n;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(i == 0) {
                ans.push_back(x);
                continue;
            }
            int l = ans.size();
            if(ans[l-1] > x) {
                ans.push_back(1);
            }
            ans.push_back(x);
        }
        cout << ans.size() << "\n";
        for(int x: ans) cout << x << " ";
        cout << "\n";
    }
}