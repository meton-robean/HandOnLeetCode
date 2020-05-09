/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */
//厄拉多塞筛法 （按倍数筛选法）
// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrimes(n, true);
        int count = 0;
        for( int i = 2; i < n; i++ ){
            if( isPrimes[i] == true ) {
                count++;
                for( int j = i + i; j < n; j += i) { // 从i 的倍数开始，按倍数排除
                    isPrimes[j] = false;
                }
            }
        }
        return count;
    }

};
// @lc code=end

