#include <bits/stdc++.h>
using namespace std;

int main() {
	int _; cin >> _;
	while(_--) {
		int n, m; cin >> n >> m;

		vector<vector<int>> graph(n);
		for (int i = 0; i < m; i++) {
			int x, y; cin >> x >> y;
			graph[min(x, y) - 1].push_back(max(x, y) - 1);
		}
		
		for (int i = 0; i < n-1; i++) {
			graph[i].push_back(i+1);
		}

		queue<int> q({0, -1});
		int dist = 1;
		vector<int> arr(n, -1);
		arr[0] = 0;
		vector<bool> isVisited(n, false);

		while(!q.empty()) {
			int currNode = q.front();
			q.pop();

			for (auto neigh: graph[currNode]) {
				if (isVisited[neigh]) continue;
				q.push(neigh);
				isVisited[neigh] = true;
				arr[neigh] = dist;
			}

			if (q.front() == -1) {
				q.pop();
				if (q.empty()) break;
				q.push(-1);
				dist++;
			}
		}
		
		// for (auto d: arr) cout << d << " ";
		// cout << "\n";

		
	}

	return 0;
}