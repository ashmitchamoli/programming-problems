#include <bits/stdc++.h>
using namespace std;

int main() {
	int _; cin >> _;
	while(_--) {
		int l, r, L, R; cin >> l >> r >> L >> R;

		if (R < l) {
			cout << "1\n";
		}
		else if (L > r) {
			cout << "1\n";
		}
		else {
			int x = max(l, L), y = min(r, R);
			int ans = y - x + (l != L && x != 1) + (r != R && y != 100);
			cout << ans << "\n";
		}
	}
	
	return 0;
}