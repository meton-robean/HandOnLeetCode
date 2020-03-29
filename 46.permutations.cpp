/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
//回溯法 参考：https://www.cnblogs.com/grandyang/p/4358848.html
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        if (nums.size() == 0) return {};

        vector<vector<int>> res;
        vector<int> item;
        vector<int> visited( nums.size(), 0);
        dfs(nums, 0, visited, item, res);
        return res;
    }

    void dfs(vector<int> &nums, 
             int level,
             vector<int> & visited,
             vector<int> &item,
             vector<vector<int>>& res){
                 
                 if (level == nums.size() ) {
                     res.push_back(item);
                     return;
                 }

                 for(int i = 0; i < nums.size(); i++){
                     if (visited[i] == 1) continue;
                     visited[i] = 1;
                     item.push_back( nums[i] );
                     dfs( nums, level+1, visited, item, res );
                     item.pop_back();
                     visited[i] = 0; 
                 }

    }
};
// @lc code=end

