#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = (a[i] == 0 ? 1 : -1);
    }
    int max_ending_here = 0;
    int max_so_far = INT_MIN;
    int start = 0, end = 0, s = 0;
    for(int i = 0; i < n; i++) {
        max_ending_here += a[i];
        if(max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
        if(max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) 
        ans += ((i >= start && i <= end) ? ((1+a[i])/2) : (1-a[i])/2);
    cout << ans;
}