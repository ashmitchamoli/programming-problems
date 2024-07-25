/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string rotate(string s, int i, int direction) {
        if (s[i] == '0' and direction == -1) {
            s[i] = '9';
            return s;
        }
        if (s[i] == '9' and direction == 1) {
            s[i] = '0';
            return s;
        }
        s[i] += direction;
        return s;
    }

    int openLock(vector<string>& deadends, string target) {
        string startNode = "0000";

        set<string> deadEnds(deadends.begin(), deadends.end());
        set<string> visited;

        queue<string> q({startNode, "|"});
        int ans = 0;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                for (int dir = -1; dir <= 1; dir+=2) {
                    string combination = rotate(curr, i, dir);
                    if (deadEnds.find(combination) == deadEnds.end() and visited.find(combination) == visited.end()) {
                        q.push(combination);
                    }
                    if (combination == target) {
                        return ans;                        
                    }
                }
            }

            if (q.front() == "|") {
                q.pop();
                ans++;
                q.push("|");
            }
        }

        return -1;
    }
};
// @lc code=end

