/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        int preindex = 0; //global var
        int left = 0;
        int right = inorder.size()-1 ;

        return buildSubTree(preorder, inorder, preindex, left, right);
    }

    TreeNode *buildSubTree(vector<int> &preorder, vector<int> &inorder, int &pidx, int left, int right)
    {

        if (right < left)
            return NULL;

        int index;
        int root_val = preorder[pidx];
        pidx++;

        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == root_val)
            {
                index = i;
                break;
            }
        }

        TreeNode *t = new TreeNode(root_val);
        t->left  = buildSubTree(preorder, inorder, pidx, left, index - 1);
        t->right = buildSubTree(preorder, inorder, pidx, index + 1, right);
        return t;
    }
};
// @lc code=end
