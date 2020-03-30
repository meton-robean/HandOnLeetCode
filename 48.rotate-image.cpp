/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start

//方法多样
//1 先mat上下行翻转，再转置
//2 先转置， 再左右列翻转
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        reverse( matrix.begin(), matrix.end() );

        for(int i = 0; i< matrix.size(); i++)
            for(int j = i; j < matrix.size(); j++){
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        
    }
};
;
// @lc code=end

