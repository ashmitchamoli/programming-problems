#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	int MOD = 1e9 + 7;
	while(t--) {
		int l, r; cin >> l >> r;
		int x1 = 1, c1 = 0, x2 = 1, c2 = 0;
		int temp = l-1;
		while (temp > 0) {
			c1++;
			temp /= 3;
		}
		c1--;
		temp = r;
		while (temp > 0) {
			c2++;
			temp /= 3;
		}
		c2--;

		for (int i = 0; i < c1; i++) x1 *= 3;
		for (int i = 0; i < c2; i++) x2 *= 3;


		// cout << c1 << " " << x1 << " " << c2 << " " << x2 << "\n";

		int q = ((c2 + 1) * r - 3 * (x2 - 1) / 2) + c2;
		if (l > 1) {
			q -= ((c1+1) * (l-1) - 3 * (x1 - 1) / 2) + c1;
		}

		int x = 0;
		temp = l;
		while (temp > 0) {
			x++;
			temp /= 3;
		}

		cout << q + x << "\n";
	}
}