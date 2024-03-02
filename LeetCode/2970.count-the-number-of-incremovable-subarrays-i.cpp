/*
 * @lc app=leetcode id=2970 lang=cpp
 *
 * [2970] Count the Number of Incremovable Subarrays I
 */

// @lc code=start
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        while(i+1 < n && nums[i+1] > nums[i]) i++;
        if(i == n-1) {
            return (n*(n+1))/2;
        }
        while(j-1 > -1 && nums[j-1] < nums[j]) j--;
        // cout << i << " " << j;
        int ans = 1; // 1 is for removing the entire array
        ans += i+1;
        ans += (n-j);

        if(nums[i] < nums[j]) ans += (n-j) * (i+1) + j-i - 2;

        return ans;
    }
};
// @lc code=end

