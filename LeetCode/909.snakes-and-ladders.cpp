#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start
class Solution {
public:
    pair<int, int> decipherCoord(int num, int N) {
        int x = N - 1 - (num - 1) / N;
        
        int yDir = 2 * (x%2) - 1; // 1 for odd x, -1 for even x.
        yDir *= -2 * (N%2) + 1; // yDir should be 1 for even x if N is odd and -1 if N is even.
        
        int y = (-N+1)*((yDir-1)/2) + yDir * ((num-1) % N);
    
        return {x, y};
    }

    vector<int> getNeighbours(vector<vector<int>>& board, int curr) {
        vector<int> neighbours; 
        int N = board.size();

        curr++;
        while(neighbours.size() < 6 && curr <= N*N) {
            auto coord = decipherCoord(curr, N);
            if (board[coord.first][coord.second] != -1) {
                neighbours.push_back(board[coord.first][coord.second]);
            }
            else {
                neighbours.push_back(curr);
            }
            curr++;
        }

        return neighbours;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        vector<bool> isVisited(N*N+1, false);
        isVisited[1] = true;

        queue<int> Q({1, -1});
        int ans = 1;

        while (! Q.empty()) {
            int curr = Q.front();
            Q.pop();

            cout << curr << " ";
            auto neighbours = getNeighbours(board, curr);
            // cout << neighbours.size();

            for (int x : neighbours) {
                if (isVisited[x]) continue;

                if (x == N*N) {
                    return ans;
                }

                isVisited[x] = true;
                Q.push(x);
            }

            if (Q.front() == -1) {
                Q.pop();
                if (Q.empty()) {
                    break;
                }
                cout << " |\n";
                ans++;
                Q.push(-1);
            }
        }
        return -1;
    }
};
// @lc code=end

