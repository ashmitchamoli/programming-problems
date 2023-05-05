#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    long long max_yet = a[0], sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(sum > max_yet) {
            max_yet = sum;
        }
        if(sum < 0)
            sum = 0;
    }
    cout << max_yet;
}