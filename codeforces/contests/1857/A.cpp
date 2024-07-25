#include <bits/stdc++.h>

using namespace std;

int main () {
    int _; cin >> _;
    while(_--) {
        int n; cin >> n;
        int num_odd = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            num_odd += (x%2);
        }
        int num_even = n - num_odd;
        if(num_odd%2 == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}