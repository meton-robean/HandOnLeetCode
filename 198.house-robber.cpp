/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
//动态规划
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1] );
        int max_money = dp[1];

        for(int i = 2; i < n; ++i){
            for(int j = i-2; j >=0; --j){
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
            max_money = max(max_money, dp[i]);
        }

        return max_money;

    }
};
// @lc code=end

