#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<bool>> bfsGrid(pair<int, int>& start, vector<string>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push(start);

    auto isValidCoord = [n, m, &grid, &isVisited](int i, int j) -> bool {
        return (i > 0 && j > 0 && i < n && j < m) &&
               (grid[i][j] != '#') &&
               (!isVisited[i][j]);
    };

    while(! q.empty()) {
        pair<int, int> v = q.front();
        int i = v.first, j = v.second;
        q.pop();
        isVisited[i][j] = true;
        if(isValidCoord(i-1, j)) q.push({i-1, j});
        if(isValidCoord(i+1, j)) q.push({i+1, j});
        if(isValidCoord(i, j-1)) q.push({i, j-1});
        if(isValidCoord(i, j+1)) q.push({i, j+1});
    }

    return isVisited;
}

int main() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    pair<int, int> start, end;
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') {
                start = {i, j};
            }
            if(grid[i][j] == 'B') {
                end = {i, j};
            }
        }
    }
    auto isVisited = bfsGrid(start, grid);
    if (isVisited[end.first][end.second]) cout << "YES\n";
    else cout << "NO\n";d
}