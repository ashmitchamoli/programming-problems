#include <bits/stdc++.h>
using namespace std;

vector<long long> getOptimalTicketRates(int railway_nodes, 
								   vector<int>& railway_from,
								   vector<int>& railway_to,
								   vector<int>& railway_weight,
								   vector<vector<int>>& queries) {
    vector<vector<pair<int, int>>> graph;
	for (int i = 0; i < railway_from.size(); i++) {
		graph[railway_from[i]].push_back({railway_to[i], railway_weight[i]});
	}

	for (auto query : queries) {
		int start = query[0], end = query[1];
		int maxStops = query[2];

		queue<int> q({start});

		// for () {}
	}
}

int main() {
}