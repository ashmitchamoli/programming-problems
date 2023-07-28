#include <bits/stdc++.h>

using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {    
        int b,c,h; cin >> b >> c >> h;

        if(c+h >= b) cout << 2*b-1;
        else cout << 2*(c+h) +1;
        cout << "\n";
    }
}