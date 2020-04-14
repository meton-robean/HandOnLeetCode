/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
/* 
动态规划
dp[i]表示有i块钱时候，需要最少的找零数。 其实画个表就知道:
eg. amout = 6的时候
   coin面额 \dp[i]  0     1      2      3       4        5       6
    1              0     1      2      3       4        5       6  (在只有1面额情况下)
    2              0     1      1      2       2        3       3  (增加了2面额情况下, dp[i]数组进一步更新)
    5              0     1      1      2       2        1       2
所以一维dp[i]需要几轮更新，轮数取决于有多少种面额
转移方程 dp[i] = min( dp[i], dp[i-coin] + 1)

*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);  //最大找零数不会超过amout+1
        dp[0] = 0;
        for (int coin : coins){
            for(int i = coin; i <= amount; ++i){
                dp[i] = min(dp[i], dp[i - coin]+1);
            }
        } 

        return dp[amount] >= amount+1 ? -1: dp[amount];       
    }
};
// @lc code=end

