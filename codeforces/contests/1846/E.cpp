#include <bits/stdc++.h>
 
using namespace std;

int main () {
    int _; cin >> _;
    while(_--) {
        long long x; cin >> x;
        bool is = false;
        for(long long k = 2; k*k + k + 1 <= x; k++){
            long long temp = (k-1) * x + 1;
            while(temp % k == 0) {
                temp /= k;
            }
            if(temp == 1) {
                is = true;
                break;
            }
        }
        if(is) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}