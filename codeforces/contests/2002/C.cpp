#include <bits/stdc++.h>
using namespace std;

int main () {
	int _; cin >> _;
	while (_--) {
		int n; cin >> n;
		vector<pair<int, int>> points(n);
		for (int i = 0; i < n; i++) {
			cin >> points[i].first >> points[i].second;
		}

		long long xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
		long long sqD = (xt - xs) * (xt - xs) + (yt - ys) * (yt - ys);
		
		bool isPossible = true;
		for (auto pt: points) {
			if (sqD >= (xt - pt.first) * (xt - pt.first) + (yt - pt.second) * (yt - pt.second)) {
				isPossible = false;
				break;
			}
		}

		if (isPossible) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}