/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start

//典型的遍历与回溯
class Solution {

private:
    vector<vector<int>> res;
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return {};
        
        vector<int> list;
        dfs(nums, list,  0);

        return res;


        
    }

    void dfs(vector<int> &nums, vector<int>& list,  int pos){
        res.push_back( list );

        for (int i = pos; i < nums.size(); ++i)
        {
            
            list.push_back(nums[i]);
            dfs(nums, list,  i+1);
            list.pop_back();
        }
    }

};
// @lc code=end

