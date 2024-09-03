#include <bits/stdc++.h>
using namespace std;

int main () {
	int _; cin >> _;
	while (_--) {
		int a, b; cin >> a >> b;

		if (a%2) {
			cout << "No\n";
		}
		else {
			if (b%2) {
				if (a > 1) {
					cout << "Yes\n";
				} 
				else {
					cout << "No\n";
				}
			}
			else {
				cout << "Yes\n";
			}
		}
	}
}