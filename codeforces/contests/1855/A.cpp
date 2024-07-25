#include <bits/stdc++.h>

using namespace std;

int main() {
    int _; cin >> _;
    while(_--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(auto& x: arr) cin >> x;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(i+1==arr[i]) ans++;
        }
        cout << (ans+1)/2  << "\n";
    }
}