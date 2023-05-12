#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<long long> a(n), index_sum(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        index_sum[i] = a[i];
    }
    sort(a.begin(), a.end());
    sort(index_sum.begin(), index_sum.end());
    
    for(int i = 1; i < n; i++) {
        index_sum[i] += index_sum[i-1]; 
    }

    long long ans = LONG_MAX;
    for(int i = 0; i < n; i++) {
        long long c = a[i] * (2*(i+1) - n) + -2*index_sum[i] + index_sum[n-1];
        if(c < ans) ans = c;
    }
    cout << ans;
}