#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {        
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < equations.size(); i++) {
            auto equation = equations[i];
            string var1 = equation[0], var2 = equation[1];

            graph[var1].push_back({var2, values[i]});
            graph[var2].push_back({var1, 1/values[i]});
        }

        vector<double> ans;

        for (auto query : queries) {
            string var1 = query[0], var2 = query[1];

            if (graph.find(var1) == graph.end() || graph.find(var2) == graph.end()) {
                ans.push_back(-1);
                continue;
            }

            if (var1 == var2) {
                ans.push_back(1);
                continue;
            }

            queue<pair<string, double>> Q({{var1, 1}});
            
            unordered_map<string, bool> isVisited;
            for (auto var : graph) {
                isVisited[var.first] = false;
            }
            isVisited[var1] = true;

            bool found = false;
            while(!Q.empty()) {
                auto currNode = Q.front();
                Q.pop();

                for (auto neighbour : graph[currNode.first]) {
                    if (isVisited[neighbour.first]) continue;

                    Q.push({neighbour.first, neighbour.second * currNode.second});
                    
                    if (neighbour.first == var2) {
                        ans.push_back(Q.back().second);
                        found = true;
                        break;
                    }

                    isVisited[neighbour.first] = true;

                }
                if (found) break;
            }
            if (found) continue;
            ans.push_back(-1);
        }
        return ans;
    }
};
// @lc code=end
