#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
 
class Solution {
public:
    int getMaxPath(TreeNode* node, int& maxVal) { // max value path ending at node from right and left subtree
        if (node == nullptr) {
            return 0;
        }

        int rightPathLength = getMaxPath(node->right, maxVal);
        int leftPathLength = getMaxPath(node->left, maxVal);
        
        int myVal = max(0, rightPathLength) + node->val + max(0, leftPathLength);

        maxVal = max(myVal, maxVal);

        return max(node->val, max(node->val + leftPathLength, node->val + rightPathLength));
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;

        getMaxPath(root, ans);

        return ans;
    }
};
// @lc code=end

