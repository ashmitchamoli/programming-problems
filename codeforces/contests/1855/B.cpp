#include <bits/stdc++.h>

using namespace std;

int main() {
    int _; cin >> _;
    while(_--) {
        long long n; cin >> n;
        if(n<3) {cout << n << "\n";continue;}
        long long ans = 1;
        while (true)
        {
            if(n%ans != 0) break;
            ans++;
        }
        cout << ans-1 << "\n";
        
    }
}