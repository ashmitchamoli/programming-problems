#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;

		int ans = 0;
		if (a1 > b1) {
			if (a2 >= b2) {
				ans++;
			}
		}
		else if (a1 == b1) {
			if (a2 > b2) ans++;
		}

		if (a1 > b2) {
			if (a2 >= b1) {
				ans++;
			}
		}
		else if (a1 == b2) {
			if (a2 > b1) ans++;
		}

		if (a2 > b1) {
			if (a1 >= b2) {
				ans++;
			}
		}
		else if (a2 == b1) {
			if (a1 > b2) {
				ans++;
			}
		}
		
		if (a2 > b2) {
			if (a1 >= b1) {
				ans++;
			}
		}
		else if (a2 == b2) {
			if (a1 > b1) {
				ans ++;
			}
		}
		
		cout << ans << "\n";
 	}
}