/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
//树层次遍历是典型的BFS应用，这里多一个要求：分层次输出而已
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        if (!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> tmp_vector;
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *t = q.front();
                q.pop();
                tmp_vector.push_back(t->val);
                if(t->left)  q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res.push_back(tmp_vector);
        }

        return res;
    }
};
*/

//递归的写法，核心就在于需要一个二维数组，和一个变量 level
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode *root, int level, vector<vector<int>> &res)
    {
        if (!root)
            return;
        if (res.size() == level)
            res.push_back({}); //first reach this level, if not, meaning that we trace back;
        res[level].push_back(root->val);

        if (root->left)
            dfs(root->left, level + 1, res);
        if (root->right)
            dfs(root->right, level + 1, res);
    }
};

// @lc code=end