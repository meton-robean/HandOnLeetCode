/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 * 
 * 相较于 Unique Binary Search Trees II， 这里只要求出所有二叉搜索数的总个数即可。
 * 注意到一某个index的数为树root,那么此时所有的二叉搜索树个数为 root左边树的组合 × root右边树的组合
 * 可以用动态规划思想： dp[n]表示 n的时候所有的二叉搜索数总数
 * 详细可以参考 https://blog.csdn.net/shulixu/article/details/86376621
 */

// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {

        vector<int> dp(n + 1, 0);
        //init
        dp[0] = 1;
        dp[1] = 1;
        if (n <= 1)
            return 1;

        //iter and memorization
        for (int i = 2; i <= n; i++)
        {

            for (int j = 1; j <= i; j++)
            {

                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};
// @lc code=end

