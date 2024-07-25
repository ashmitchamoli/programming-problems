#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;

        while(i < j) {
            int mid = (i+j)/2;

            // if mid is peak
            if (mid-1 >= 0 && nums[mid] > nums[mid-1] && mid+1 < nums.size() && nums[mid] > nums[mid+1]) {
                return  mid;
            }
            else if (mid+1 < nums.size() && nums[mid+1] > nums[mid]) {
                i = mid+1;
            }
            else {
                j = mid - 1;
            }
        }

        return i;
    }    
};
// @lc code=end

