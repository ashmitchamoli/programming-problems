#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x; cin >> n >> x;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {cin >> a[i].first; a[i].second = i + 1;}
    sort(a.begin(), a.end());

    int i = 0, j = n-1;
    while(i < j) {
        if(a[i].first + a[j].first > x) {
            j--;
        }
        else if(a[i].first + a[j].first < x) {
            i++;
        }
        else {
            cout << a[i].second << " " << a[j].second;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}