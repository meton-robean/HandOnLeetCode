/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start

/*
dp[i]表示str(0 ~ i)区间是否符合条件，可切分与匹配到.

str:  0---------------k------i

dp[i] = ( dp[k] && if str(k, i) in wordDict )

*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         vector<bool> dp( s.length()+1, false); //init
         dp[0] = true;

         for( int i = 1; i <= s.length(); i++){

             for( int k = i-1; k>=0; --k){
                 if ( dp[k] && std::count( wordDict.begin(), wordDict.end(), s.substr(k, i-k)) ){
                     dp[i] = true;
                     break;
                 }
             }
             
         }

         return dp[s.length()]; 

    }
};
// @lc code=end

