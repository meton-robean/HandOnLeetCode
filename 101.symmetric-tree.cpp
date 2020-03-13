/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
//迭代的方式 BFS
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty())
        {
            TreeNode *t1 = q.front();
            q.pop();
            TreeNode *t2 = q.front();
            q.pop();
            if ((t1 && !t2) || (!t1 && t2))
                return false;
            if (!t1 && !t2) 
                continue;
            if (t1->val != t2->val)
                return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }

        return true;
    }
};
*/


//DFS 递归
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return isSymDFS(root->left, root->right);
    }

    bool isSymDFS(TreeNode *t1, TreeNode *t2)
    {

        if (!t1 && !t2)
            return true;

        if ((!t1 && t2) || (t1 && !t2) || (t1->val != t2->val))
            return false;

        return isSymDFS(t1->left, t2->right) && isSymDFS(t1->right, t2->left);
    }
};

// @lc code=end

