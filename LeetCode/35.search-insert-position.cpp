/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n-1;
        while(i < j) {
            int mid = (i + j) / 2;
            
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target) {
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }
        if(i == j) {
            return i;
        }
        if(i > j) {
            return j+1;
        }
        return -1;
    }
};
// @lc code=end

