/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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

//利用中序遍历获得树的序列，对该序列排序后更新回原来的树，这是比较直观的方法
class Solution
{
public:
    vector<int> v;
    vector<TreeNode *> tree_list;
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            tree_list[i]->val = v[i];
        }
    }

    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        v.push_back(root->val);
        tree_list.push_back(root);
        inorder(root->right);
    }
};

// @lc code=end

