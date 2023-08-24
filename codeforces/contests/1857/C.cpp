#include <bits/stdc++.h>

using namespace std;

int main () {
    int _; cin >> _;
    while(_--) {
        int n; cin >> n;
        map<int, int> freq;
        for(int i = 0; i < (n*(n-1))/2; i++) {
            int x; cin >> x;
            freq[x]++;
        }
        long long sum = 0;
        vector<int> ans;
        for(auto it = freq.rbegin(); it != freq.rend(); it++) {
            // cout << (*it).first << " " << (*it).second << "\n";
            int y = sqrt(4*sum*(sum-1) + 1 + 8*((*it).second));
            y += (1-2*sum);
            y /= 2;
            sum += y;
            for(int i = 0; i < y; i++) {
                ans.push_back(((*it).first));
            }
        }
        for(int x: ans) cout << x << " ";
        cout << "\n";
    }
}