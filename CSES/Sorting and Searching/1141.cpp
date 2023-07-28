#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int i = 0, j = 0;
    int max_window = 1;
    set<int> s{a[0]}; 
    while(j < n-1) {
        j++;
        while(s.find(a[j]) != s.end()) {
            s.erase(a[i]);
            i++;
        }
        s.insert(a[j]);
        max_window = max(max_window, j - i + 1);
    }
    cout << max_window << "\n";
}