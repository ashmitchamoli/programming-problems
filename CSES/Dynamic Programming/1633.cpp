#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n; cin >> n;
    int mod = 1e9 + 7;
    vector<long long> a(n+1, 0);

    a[0] = 1;
    a[1] = 1;
    for(long long i = 2; i <= n; i++) {
        long long temp = 0;
        for(long long j = 1; j <= 6; j++) {
            if (i - j < 0) continue;
            temp += a[i-j];
            temp = temp % mod;
        }
        a[i] = temp % mod;
    }
    cout << a[n];
}