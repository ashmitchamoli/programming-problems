#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<pair<int, int>> movies(n);
    for(int i = 0; i < n; i++)
        cin >> movies[i].second >> movies[i].first;
    
    sort(movies.begin(), movies.end());
    int ans = 1; int index = 0;
    for(int i = 1; i < n; i++) {
        if(movies[index].first > movies[i].second) continue;
        ans++;
        index = i;
    }
    cout << ans;
}