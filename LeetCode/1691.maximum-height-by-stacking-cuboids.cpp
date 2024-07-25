#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1691 lang=cpp
 *
 * [1691] Maximum Height by Stacking Cuboids 
 */

// @lc code=start
class Solution {
public:
    bool cmp(const vector<int>& a, const vector<int>& b) {
        
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        sort(cuboids.begin(), cuboids.end(), cmp);
    }
};
// @lc code=end

