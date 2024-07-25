#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--)
	{
		long long n; cin >> n;
		if (n == 1) {
			cout << "1\n1\n";
			continue;
		}
		if ((n & (n-1)) == 0) {
			cout << "1\n" << n << "\n";
			continue;
		}

		cout << __builtin_popcountll(n)+1 << endl;
		vector<long long> ans;
		ans.push_back(n);
		for (int i = 0; i < 64; i++) {
			if (n & ((long long)1 << i)) {
				// cout << n - (1 << i) << " ";
				ans.push_back(n - ((long long)1 << i));
			}
		}
		
		for (int i = 1; i < ans.size()+1; i++) {
			cout << ans[ans.size()-i] << ' ';
		}
		cout << "\n";
	}
}