#include <bits/stdc++.h>

using namespace std;

int main() {
    int _; cin >> _;
    while(_--) {
        int n; cin >> n;
        if(n%2 == 0) {
            for(int i = 0; i < n-1; i++) {
                cout << n+1 << " ";
            }
            cout << "1";
        }
        else {
            for(int i = 0; i < n; i++) {
                cout << "1 ";
            }
        }
        cout << "\n";
    }
}