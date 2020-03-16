/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode *root)
    {
        if(!root) return 0;
        return dfs(root, 1);
    }

    int dfs(TreeNode *root, int height)
    {
        if (!root)
            return height-1;

        return min(dfs(root->left, height + 1), dfs(root->right, height + 1));
    }
};
// @lc code=end
