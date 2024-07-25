#include <bits/stdc++.h>

using namespace std;

int main() {
    int _; cin >> _;
    while(_--) {
        int n; cin >> n;
        vector<int> a(n);
        for(auto& x: a) cin >> x;

        int i = 0, j = n-1;
        bool symm = true;
        for(i = 0; i < n; i++) {
            if(a[i] != (j+1)) {
                symm = false;
                break;
            }
            while(j >= 0 && a[j] == i+1) {
                j--;
            }
        }
        if(symm) cout << "YES\n";
        else cout << "NO\n";
    }
}