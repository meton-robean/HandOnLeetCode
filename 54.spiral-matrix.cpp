/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start

//递归的用法
//每次对 matrix最外围遍历完成，可以将内层剩下的当成一个新的maxtirx继续递归以上操作
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> res;
        helper(matrix, res);
        return res;
    }

    void helper(vector<vector<int>> &matrix, vector<int> &res){
        int row = matrix.size();
        if (row == 0)
            return; 
        int col = matrix[0].size();
        //vector<int> res = matrix[0];

        //第一行
        for(int i = 0; i < col; ++i){
            res.push_back(matrix[0][i]);
        }

        if (row > 1)
        {

            for (int i = 1; i < row; ++i)
            {
                res.push_back(matrix[i][col - 1]); //最右边一列
            }


            for (int j = col - 2; j >= 0; --j)
            {
                res.push_back(matrix[row - 1][j]);//最低下一行
            }

            if (col > 1)
            {
                for (int k = row - 2; k >= 1; --k)
                {
                    res.push_back(matrix[k][0]); //最左边的一列（逆序）
                }
            }

        } //END matrix最外围遍历完成，可以将内层剩下的当成一个新的maxtirx继续递归以上操作..

        vector<vector<int>> mat;

        for (int r = 1; r <= row - 2; ++r)
        {
            if(col>2){
                vector<int> tmp_row;
                for (int c = 1; c <= col - 2; ++c)
                {
                    tmp_row.push_back(matrix[r][c]);
                }
                mat.push_back(tmp_row);
            }
        }
        return helper(mat, res);
    }

};
// @lc code=end

