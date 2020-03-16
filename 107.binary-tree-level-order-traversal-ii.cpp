/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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



//最简单思路就是正常的从上到下层次遍历，之后在将结果翻转即可
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> res;
        int level = 0;
        dfs(root, res, level);
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(TreeNode *root, vector<vector<int>> &res, int level)
    {
        if (!root)
            return;
        if (level == res.size())
        {
            res.push_back({});
        }
        res[level].push_back(root->val);
        if (root->left)
            dfs(root->left, res, level + 1);
        if (root->right)
            dfs(root->right, res, level + 1);
        return;
    }
};
// @lc code=end
