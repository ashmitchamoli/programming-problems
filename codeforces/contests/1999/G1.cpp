#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int l = 2, r = 999;
		int mid = (l+r)/2;
		cout << "? " << mid << " " << mid << "\n";
		cout.flush();

		while (true) {
			int area; cin >> area;
			if (area == -1) {
				break;
			}

			if (area == mid * mid) {
				l = mid + 1;
			}
			if (area == (mid + 1) * (mid + 1)) {
				r = mid;
			}

			mid = (l+r)/2;
			if (l >= r) {
				cout << "! " << r << endl;
				cout.flush();
				break;
			}
			else {
				cout << "? " << mid << " " << mid << "\n";
				cout.flush();
			}
		}
	}	
}