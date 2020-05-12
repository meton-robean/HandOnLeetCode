/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
// s[i] = '0' 且  s[i-1] == '1' 或者'2' 时候 ， dp[i] = dp[i-2]
// s[i] != '0' 且 s[i-1] 在 '1' ~ '2' dp[i] = dp[i-1] + dp[i-2]
class Solution {
public:
int numDecodings(string s) {
        int l = s.size();
        if(0 == l) return 0;
        vector<int> dp(l + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < l; i++) {
            if(s[i] >= '1' && s[i] <= '9') dp[i + 1] += dp[i]; //分两步走 第一步
            if(i) {
                int tmp = (s[i - 1] - '0') * 10 + (s[i] - '0');
                if(tmp >= 10 && tmp <= 26) dp[i + 1] += dp[i - 1]; //第二步 
            }
        }
        return dp[l];
    }
};

// @lc code=end

