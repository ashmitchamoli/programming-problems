#include <bits/stdc++.h>
using namespace std;

int main() {
	int _; cin >> _;
	while (_--) {
		int x, y, k; cin >> x >> y >> k;

		int xSteps = (x+k-1)/k, ySteps = (y+k-1)/k;
		if (ySteps >= xSteps) {
			cout << 2 * ySteps;
		}
		else {
			cout << 2 * xSteps - 1;
		}
		cout << endl;
	}
}