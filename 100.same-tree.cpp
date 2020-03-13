/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
//用递归DFS遍历树
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if ((!p && q) || (p && !q) || (p->val != q->val))
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
*/



//迭代方式，只用一个stack即可
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        stack<TreeNode *> st;
        st.push(p);
        st.push(q);

        while (!st.empty())
        {
            q = st.top();
            st.pop();
            p = st.top();
            st.pop();
            if (!q && !p)
                continue;
            if ((q && !p) || (!q && p) || q->val != p->val)
                return false;
            st.push(p->right);
            st.push(q->right);
            st.push(p->left);
            st.push(q->left);
        }

        return true;
    }
};


// @lc code=end

