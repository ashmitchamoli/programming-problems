#include <bits/stdc++.h>
using namespace std;

long long modInverse(long long a, long long m) {
  return a <= 1 ? a : (m - (m/a) * modInverse(m % a, m) % m)%m;
}

long long MOD = 1e9 + 7;

int main () {
	int _; cin >> _;
	while (_--) {
		long long n; cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		long long totalSum = accumulate(a.begin(), a.end(), 0);
		long long P = 0;
		for (int i = 0; i < n; i++) {
			P += ((long long)(a[i]%MOD) * ((totalSum - a[i]) % MOD)) % MOD;
			P %= MOD;
		}

		cout << (((P)%MOD)*(modInverse((long long)n*(n-1), MOD)%MOD)) % MOD << "\n";
	}
}