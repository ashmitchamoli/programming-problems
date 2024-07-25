#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> nums(n+1);
    vector<int> ind(n+1, 1e6);
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
        ind[nums[i]] = i;
    }

    int ans = 0;
    for(int i = 1; i < n; i++) ans += (ind[i-1] > ind[i]);

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        
    }
}