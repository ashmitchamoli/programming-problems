#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<pair<long long, int>> a(2*n);
    for(int i = 0; i < 2*n; i+=2) {
        cin >> a[i].first >> a[i+1].first;
        a[i].second = 1;
        a[i+1].second = -1;
    }
    sort(a.begin(), a.end());
    int ans = 1;
    int temp = 0;
    for(int i = 0; i < 2*n; i++) {
        temp += a[i].second;
        if(temp > ans) ans = temp;
    }
    cout << ans;
}