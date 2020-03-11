/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */
/* 题目描述
Category Difficulty Likes Dislikes
    algorithms Medium(55.96 %) 2524 106 Tags
    Companies
    Given a binary tree,
    return the inorder traversal of its nodes' values.

    Example :

    Input : [ 1, null, 2, 3 ] 

    Output : [ 1, 3, 2 ] Follow up : Recursive solution is trivial,
    could you do it iteratively ?
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
//递归方法： 中序遍历套路： 按照 inorder(left) -- res.push_back(root) -- inorder(right)组织，
//刚好是中序遍历的顺序
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder( root);
        return result;
    }

private:
    vector<int> result;
    void inorder(TreeNode* root ){
        if(!root) return; //哨兵语句
        inorder(root-> left);
        result.push_back( root-> val );
        inorder( root->right );

    }
};
*/

    //迭代方法需要用到堆栈

    class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        vector<int> res;
        TreeNode *p = root;
        while (!s.empty() || p)
        {
            if (p)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                TreeNode *t = s.top();
                s.pop();
                res.push_back(t->val);
                p = t->right;
            }
        }
        return res;
    }
};



    // @lc code=end
