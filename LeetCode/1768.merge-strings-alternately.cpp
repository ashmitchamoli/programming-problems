/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        for (int i = 0; i < 2 * min(word1.size(), word2.size()); i++) {
            if (i%2 == 0) {
                ans.push_back(word1[i/2]);
            }
            else {
                ans.push_back(word2[(i-1)/2]);
            }
        }

        if (2 * word1.size() > ans.size()) {
            for (int i = ans.size() / 2; i < word1.size(); i++) {
                ans.push_back(word1[i]);
            } 
        } 
        else {
            for (int i = ans.size() / 2; i < word2.size(); i++) {
                ans.push_back(word2[i]);
            }
        }

        return ans;
    }
};
// @lc code=end

