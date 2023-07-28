#include <bits/stdc++.h>

using namespace std;

int main() {
    int __; cin >> __;
    while(__--) {
        vector<vector<char>> b(3, vector<char>(3, '-'));
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cin >> b[i][j];
            }
        }
        char won = '.';
        for(int i = 0; i < 3; i++) {
            if(b[i][0] == b[i][1] && b[i][1] == b[i][2]) {
                won = b[i][0];
                break;
            }
            if(b[0][i] == b[1][i] && b[1][i] == b[2][i]) {
                won = b[0][i];
                break;
            }
        }
        if(won != '.') {
            cout << won << "\n";
            continue; 
        }
        if(b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[0][0] != '.') 
        {cout << b[0][0] << "\n";
        continue;}
        
        if(b[0][2] == b[1][1] && b[1][1] == b[2][0] && b[0][2] != '.') 
        {cout << b[0][2] << "\n";
        continue;}

        cout << "DRAW\n";
    }
}