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

    for(int i = 1; i < n; i++) {
        index_sum[i] += index_sum[i-1]; 
    }

    long long ans = 1e12;
    for(int i = 0; i < n; i++) {
        long long c = a[i] * (2*i - n) + -2*index_sum[i] + index_sum[n-1];
        if(c < ans) ans = c;
    }
    cout << ans;
}