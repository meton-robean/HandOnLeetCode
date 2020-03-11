/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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



//递归思想+暴力遍历
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> v;
        if(n == 0) return v;
        return generateTreesUtil(1, n);
        
    }

private:
    vector<TreeNode *> generateTreesUtil(int start, int end)
    {
        vector<TreeNode *> v;
        if (start > end)
        {
            //we want to make sure there is at least one node even it's null
            //so the double loop below gets executed for all right and left
            TreeNode *n = NULL;
            v.push_back(n);
            return v;
        }
        for (int root = start; root <= end; root++)
        {
            vector<TreeNode *> left;
            vector<TreeNode *> right;
            left = generateTreesUtil(start, root - 1); // allow smaller nodes than root i
            right = generateTreesUtil(root + 1, end);  //allow only bigger than i nodes
            for (auto tn : left)
                for (auto tr : right)
                {
                    TreeNode *r = new TreeNode(root);
                    r->left = tn;
                    r->right = tr;
                    v.push_back(r);
                }
        }
        return v;
    }
};
// @lc code=end

