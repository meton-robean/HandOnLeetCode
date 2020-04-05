/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start

//动态规划
//dp[i][j] 表示从出口(0,0)到终点( i-1, j-1)有多少种走法.
//状态转移方程 dp[i][j] = dp[i][j-1] + dp[i-1][j]; //左 + 上
class Solution {
public:
    int uniquePaths(int m, int n) {

        int dp[m][n];
        for(int i = 0; i< m; ++i){
            dp[i][0] = 1;
        }

        for(int j = 0; j < n; ++j){
            dp[0][j] = 1;
        }

        for(int i = 1; i < m; ++i){

            for(int j = 1; j < n; ++j){
                dp[i][j] = dp[i][j-1] + dp[i-1][j]; //左 + 上
            }
        }

        return dp[m-1][n-1];
        
    }
};
// @lc code=end

