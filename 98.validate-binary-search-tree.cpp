/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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

//binary search tree's inorder intraval 就是有序序列了
//先中序遍历，在检查序列是否有序即可
class Solution
{
public:
    vector<int> v;

    bool isValidBST(TreeNode *root)
    {
        inorder(root);
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] <= v[i - 1])
                return false;
        }
        return true;
    }

private:
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
};

// @lc code=end

