/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
//动态规划 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int min2cur = nums[0];
        int max2cur = nums[0];

        for(int i = 1; i < nums.size(); ++i){
            int max_tmp = max2cur;
            max2cur = max(nums[i], max(max2cur*nums[i], min2cur*nums[i]) );
            min2cur = min(nums[i], min(max_tmp * nums[i], min2cur * nums[i]));
            ans = max(ans, max2cur);
        }

        return ans;
        
    }
};
// @lc code=end

