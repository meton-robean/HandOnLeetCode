/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start

//动态规划
//leetcode 62 unique path 的翻版
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        int dp[m][n];
        //init
        dp[0][0] = grid[0][0];
        for(int i=1; i<m; ++i){
            dp[i][0] = dp[i-1][0] + grid[i][0]; 
        }
        for(int j =1; j< n; ++j){
            dp[0][j] =  dp[0][j-1] + grid[0][j];
        }

        for( int i = 1; i< m; ++i){

            for(int j=1; j<n; ++j){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m-1][n-1];

    }
};
// @lc code=end

