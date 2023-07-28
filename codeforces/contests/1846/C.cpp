#include <bits/stdc++.h>

using namespace std;

int main () {
    int __; cin >> __;
    while (__--){
        int n, m, h; cin >> n >> m >> h;
        vector<vector<int>> t(n, vector<int>(m, 0));

        vector<vector<int>> points(n, vector<int>(3, 0)); // pts, penalty, index
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> t[i][j];
            }
            sort(t[i].begin(), t[i].end());
            int tim = 0;
            for(int j = 0; j < m; j++) {
                tim += t[i][j];
                if(tim > h) {
                    break;
                }
                points[i][0]++;
                points[i][1] += tim;
            }
            points[i][1] *= -1;
            points[i][2] = n-i;
        }
        int ans;
        sort(points.begin(), points.end());
        for(int i = 0; i < n; i++)  {
            if(points[i][2] == n) {
                ans = n-i;
                break;
            }
        }
        cout << ans << "\n";

    }
    
}