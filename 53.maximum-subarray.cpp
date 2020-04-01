/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start

/*
一维动态规划
                 [-2,1,-3,4,-1,2,1,-5,4]
状态转移方程 f[i] = f[i-1] > 0 ? f[i-1] + nums[i] : nums[i]
推演一遍得到 f[] = [-2,1,-2,4,3,5,6,1,5 ]
再从f[]中找最大的那个 就是 6
*/

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         vector<int> dp(nums.size());
//         dp[0] = nums[0];
//         for(int i = 1; i < nums.size(); ++i){
//             dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i] : nums[i];
//         }
//         return *std::max_element(dp.begin(), dp.end());
//     }
// };


//空间优化版本:
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int local_max = nums[0];
        int global_max = nums[0];
        for(int i = 1; i<nums.size(); ++i){
            local_max = local_max > 0 ? local_max + nums[i] : nums[i];
            if( local_max > global_max) global_max = local_max ;
        }
        return global_max;
    }
};
// @lc code=end

