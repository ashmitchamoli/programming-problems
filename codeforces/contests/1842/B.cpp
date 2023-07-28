#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        vector<vector<int>> vec(3);
        for(int i = 0; i < 3; i++)
            for(int k = 0; k < n; k++) {
                int y; cin >> y;
                vec[i].push_back(y);
            }
        for(int i = 0; i < 3; i++) reverse(vec[i].begin(), vec[i].end());
        int k = 0;
        while(k != x) {
            bool die = true;
            for(int i = 0; i < 3; i++) {
                int m = vec[i].size();
                if(m == 0) continue;
                if((x | vec[i][m-1]) == x) {
                    k = (k | vec[i][m-1]);
                    die = false;
                    vec[i].pop_back();
                }
            }
            if(die) {break;}
        }
        if(k == x) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
    return 0;
}