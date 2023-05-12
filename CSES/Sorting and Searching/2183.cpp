#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        if(sum + 1 < a[i]) {
            cout << sum + 1;
            return 0;
        }
        sum += a[i];
    }
    cout << sum + 1;
}