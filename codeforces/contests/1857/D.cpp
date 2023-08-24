#include <bits/stdc++.h>

using namespace std;

int main () {
    int _; cin >> _;
    while(_--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            a[i] -= x;
        }
        int maxel = *max_element(a.begin(), a.end());
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == maxel) {
                count++;
            }
        }
        cout << count << "\n";
        for(int i = 0; i < n; i++) {
            if(a[i] == maxel) {
                cout << i+1 << " ";
            }
        }
        cout << "\n";
    }
}