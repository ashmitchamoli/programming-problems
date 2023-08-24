#include <bits/stdc++.h>

using namespace std;

int main () {
    int _; cin >> _;
    while(_--) {
        int n; cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());



        int q; cin >> q;
        while(q--) {
            long long x, y; cin >> x >> y;
            long long num = x*x-4*y;
            long long a = (x + sqrt(num))/2, b = (x - sqrt(num))/2;
            
        }
    }
}