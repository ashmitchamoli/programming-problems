#include <bits/stdc++.h>
using namespace std;

long long expr(long long x, long long b, long long c) {
	return x * x + x * b - c;
}

int main() {
	int _; cin >> _;
	while (_--) {
		long long n, k; cin >> n >> k;
		long long c = ((n) * (n + 2 * k - 1)) / 2, b = 2 * k - 1;

		long long x = (long long) (((double) -b + sqrt(b*b + 4 * c)) / 2.0);

		cout << min(abs(expr(x, b, c)), abs(expr(x+1, b, c))) << endl;
	}
}