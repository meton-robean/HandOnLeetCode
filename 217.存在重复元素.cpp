/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
//set去重，比较size是否一样
// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        bool found = unordered_set<int>(nums.begin(), nums.end()).size() == nums.size()? false: true;
        return found ;
    }
};
// @lc code=end

