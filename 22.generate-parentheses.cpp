/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start

//递归回溯 讲解参考：https://www.youtube.com/watch?v=XF0wh8M2A6E
//一个重要的判断条件：
////在任何一时刻， 如果左括号剩下多于右括号， 说明右括号比左括号多， 不符合条件，剪枝
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if( n == 0) return {};
        vector<string> res;
        helper(res, "", n, n);
        return res;
        
    }
    //left 代表左括号剩下的数目， 当left == 0代表左括号用完了.
    void helper(vector<string> &res, string item, int left, int right)
    {
        if(left > right){ //在任何一时刻， 如果左括号剩下多于右括号， 说明右括号比左括号多， 不符合条件，剪枝
            return ;
        }
        if( left == 0 && right == 0){
            res.push_back(item);
        }
        if(left > 0){
            helper(res, item + '(', left - 1, right);
        }

        if(right >0){
            helper(res, item + ')', left, right-1);

        }
    }
};

// @lc code=end

