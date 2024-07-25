#include <bits/stdc++.h>

using namespace std;

int main () {
    long long n; cin >> n;
    long long ans = 0;
    ans = (n * ((n-1)/2));
    if(n%3 == 0) {
        ans -= 2*n/3;
    }
    cout << ans << "\n";
}