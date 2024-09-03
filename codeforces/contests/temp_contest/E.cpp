#include <bits/stdc++.h>
using namespace std;

int main () {
	int _; cin >> _;
	while (_--) {
		int n; cin >> n;
		string s; cin >> s;

			int ans = 0;
		if (n%2 == 0){
			vector<int> freq(27, 0);
			for (int i = 0; i < n; i+=2) {
				freq[s[i] - 'a']++;
			}
			int maxFreq = *max_element(freq.begin(), freq.end());
			ans += (n+1)/2 - maxFreq;
			
			bool deleteNotDone = true;
			if (n%2) {
				if (maxFreq == (n+1)/2) {

				}
				else {
					deleteNotDone = false;
				}
			}

			vector<int> freq2(27, 0);
			for (int i = 1; i < n; i+=2) {
				freq2[s[i] - 'a']++;
			}
			maxFreq = *max_element(freq2.begin(), freq2.end());
			ans += n/2 - maxFreq;
			if (n%2 && deleteNotDone) {
				if (maxFreq == n/2) {
					ans++;
				}
			}
		}
		else {
			ans = INT_MAX;
			vector<int> f0(27, 0), f1(27, 0), f2(27, 0), f3(27, 0);

			for (int i = 0; i < n; i+=2) {
				f2[s[i] - 'a']++;
			}

			for (int i = 1; i < n; i+=2) {
				f3[s[i] - 'a']++;
			}

			for (int i = 0; i < n; i++) {
				if (i%2 == 0) {
					f2[s[i] - 'a']--;
				}
				else {
					f3[s[i] - 'a']--;
				}

				vector<int> newF0(f0.begin(), f0.end()), newF1(f1.begin(), f1.end());
				for (int i = 0; i < 27; i++) {
					newF0[i] += f3[i];
					newF1[i] += f2[i];
				}

				int x = *max_element(newF0.begin(), newF0.end());
				int y = *max_element(newF1.begin(), newF1.end());
				ans = min(ans, (n-1)/2 - y + (n/2) - x);

				if (i%2 == 0) {
					f0[s[i] - 'a']++;
				}
				else {
					f1[s[i] - 'a']++;
				}
			}
			ans++;
		}

		cout << ans << "\n";
	}
}