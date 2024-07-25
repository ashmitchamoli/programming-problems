#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;

		vector<long long> a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}

		vector<vector<int>> graph(n);
		int x, y; 
		for(int i = 0; i < n-1; i++) {
			cin >> x >> y;

			graph[x-1].push_back(y-1);
			graph[y-1].push_back(x-1);
		}

		
	}
}