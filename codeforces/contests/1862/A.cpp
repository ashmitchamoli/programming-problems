#include <bits/stdc++.h>

using namespace std;

int main() {
    int _; cin >> _;
    while(_--) {
        int n, m; cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, ' '));
        for(auto& row: grid) for(char& c: row) cin >> c; 

        string tar = "vika";
        int k = 0;
        bool poss = false;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[j][i] == tar[k]) {
                    k++;
                    if(k == 4) {
                        poss = true;
                    }
                    break;
                }
            }
            if(poss) break;
        }
        if(poss) cout << "YES\n";
        else cout << "NO\n";
    }
}