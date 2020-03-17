/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, sum, res, path);
        return res;
    }

    void dfs(TreeNode *root, int sum, vector<vector<int>> &res, vector<int>& path)
    {

        if (!root)
            return;

        path.push_back(root->val);

        if ((root->val == sum) && (root->left == nullptr) && (root->right == nullptr))
        {

            res.push_back(path);
        }

        dfs(root->left, sum - (root->val), res, path);
        dfs(root->right, sum - (root->val), res, path);

        path.pop_back(); //before trace back, we need to pop the last element of path
    }
};
// @lc code=end
