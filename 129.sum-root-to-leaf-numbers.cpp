/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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

//dfs 路径搜索
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);

    }
    int dfs(TreeNode* root, int sum){
        if(!root) return 0;
        sum = sum*10 + root->val;
        if(!root->left && !root->right) return sum;
        return dfs(root->left, sum) + dfs(root->right, sum);
    }


};
// @lc code=end

