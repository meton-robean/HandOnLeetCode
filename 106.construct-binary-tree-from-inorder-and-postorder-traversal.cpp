/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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

/*
由于后序的顺序的最后一个肯定是根，所以原二叉树的根节点可以知道，
题目中给了一个很关键的条件就是树中没有相同元素，有了这个条件我们
就可以在中序遍历中也定位出根节点的位置，并以根节点的位置将中序
遍历拆分为左右两个部分，分别对其递归调用原函数
*/
class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int postindex = postorder.size() - 1;
        int left = 0;
        int right = inorder.size() - 1;

        return buildSubTree(inorder, postorder, postindex, left, right);
    }

    TreeNode *buildSubTree(vector<int> &inorder, vector<int> &postorder, int &posidex, int left, int right)
    {

        if (right < left)
        {
            return NULL;
        }
        int index;
        int root_val = postorder[posidex];
        posidex--;

        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == root_val)
            {
                index = i;
            }
        }

        TreeNode *t = new TreeNode(root_val);

        t->right = buildSubTree(inorder, postorder, posidex, index + 1, right);
        t->left = buildSubTree(inorder, postorder, posidex, left, index-1);

        return t;
    }
};
// @lc code=end
