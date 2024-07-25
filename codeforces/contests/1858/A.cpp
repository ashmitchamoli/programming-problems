#include <bits/stdc++.h>

using namespace std;

int main() {
    int _; cin >> _;
    while(_--) {
        int a, b, c; cin >> a >> b >> c;

        int a_1 = (c+1)/2, b_1 = (c - a_1);
        if(a + a_1 > b + b_1) {
            cout << "First\n";
        } 
        else {
            cout << "Second\n";
        }
    }
}