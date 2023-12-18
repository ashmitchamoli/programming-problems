#include <bits/stdc++.h>

using namespace std;

int main() {
    int _; cin >> _;
    while(_--) {
        long long n; cin >> n;

        double ans = (1.0 + sqrt(1 + 8*n))/2.0;
        long long diff = ((long long)floor(ans));
        diff = n - (diff*(diff-1))/2;
        cout << ((long long) floor(ans)) + diff << "\n";    
    }
}