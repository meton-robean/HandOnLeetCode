/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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

//BFS, 每次根据level的奇偶翻转vector
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            vector<int> tmp_list;
            int len = q.size();

            for (int i = 0; i < len; i++)
            {
                TreeNode *t = q.front();
                q.pop();
                tmp_list.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
                
            }
            if(level % 2 == 1){
                reverse(tmp_list.begin(), tmp_list.end());
            }
            res.push_back(tmp_list);
            level++;
            
            
        }
        return res;
    }
};
// @lc code=end
