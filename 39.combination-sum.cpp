/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start

//回溯法 这个题目和二叉树的sum path类型题很像
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return {};

        vector<vector<int>> res;
        vector<int> item;
        dfs(candidates, 0, target, item, res);
        
        return res;
    }

    void dfs(vector<int>& candidates, int idx,  int target,
             vector<int>& item, vector<vector<int>>& res){

            if (target < 0 ) return;
            if (target == 0){
                res.push_back( item );
                return;
            }

            for(int i = idx; i < candidates.size(); i++){
                item.push_back( candidates[i]);
                dfs(candidates, i, target - candidates[i], item, res );
                item.pop_back();
            }

    }
};
// @lc code=end

