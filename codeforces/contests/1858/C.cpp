#include <bits/stdc++.h>

using namespace std;

int main() {
    int _; cin >> _;
    while(_--) {
        int n; cin >> n;
        vector<bool> done(n+1, false);
        done[1] = true;
        vector<int> ans{1};
        for(int i = 2; i <= n; i++) {
            if(done[i]) continue;
            done[i] = true;
            ans.push_back(i);
            int curr = i;
            while(curr*2 <= n) {
                curr *= 2;
                done[curr] = true;
                ans.push_back(curr);
            }
        }
        for(int x: ans) cout << x << " ";
        cout << "\n";
    }
}