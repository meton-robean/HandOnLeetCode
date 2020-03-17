/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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

//普通的dfs， 注意符合条件的路径的最后一个节点必须是叶子节点
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {

        if (!root)
            return false;

        //注意符合条件的路径的最后一个节点必须是叶子节点
        if (root->val == sum && ( (root->left == nullptr) && (root->right == nullptr ) ))
            return true;

        return hasPathSum(root->left, sum - (root->val)) || hasPathSum(root->right, sum - (root->val));
    }
};
// @lc code=end
