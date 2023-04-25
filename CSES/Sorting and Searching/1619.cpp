#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<pair<int, int>> cust(n);
    for(int i = 0; i < n; i++)
        cin >> cust[i].first >> cust[i].second;
    sort(cust.begin(), cust.end());

    int ans = 1;
    int curr_cust = 1;
    for(int i = 1; i < n; i++) {
        
    }
}