/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
//这里需要定义i和j两个指针分别指向数组的左右两端，
//然后两个指针向中间搜索，每移动一次算一个值和结果比较取较大的
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0 , j = height.size() -1, res = 0;
        
        while( i < j){
            res = max(res, min(height[i], height[j]) * (j - i));
            height[i] < height[j] ? i++ : j--;
        } 
        return res;
        
    }
};


// @lc code=end

