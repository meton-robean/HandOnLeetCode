/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
//用一个map来计数
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> dict;
        for(int i = 0; i <nums.size(); ++i){
            dict[nums[i]] ++;
        }
        int shrehold = nums.size() / 2;
        for(auto it : dict){
            if( it.second > shrehold ){
                return it.first;
            }
        }
        return INT_MIN;

    }
};
// @lc code=end

