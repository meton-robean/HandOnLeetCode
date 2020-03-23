/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
class Solution {
public:
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        
        dfs(root);
        return res;
        
    }

    void dfs(TreeNode* root){
        if(root == nullptr) return ;
        dfs(root->left);
        dfs(root->right);
        res.push_back(root->val);

    }

};
// @lc code=end

