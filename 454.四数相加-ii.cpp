/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> hash;
        int res_count = 0;
        for( int a: A){
            for( int b: B) {
                hash[ a+b] += 1; //可能会有重复，也是算入的
            }
        }

        for( int c: C){
            for(int d: D){
                res_count += hash[-(c+d)]; 
            }
        }

        return res_count;
    }
};
// @lc code=end

