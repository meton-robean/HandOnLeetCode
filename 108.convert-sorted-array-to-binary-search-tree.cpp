/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() -1;
        return helper(nums, left, right);
    }

    TreeNode *helper(vector<int> &nums, int left, int right)
    {
        if (right < left)
            return NULL;

        int mid = (left + right + 1) / 2 ;
        TreeNode *t = new TreeNode(nums[mid]);
        t->left = helper(nums, left, mid - 1 );
        t->right = helper(nums, mid + 1, right);
        return t;
    }
};
// @lc code=end
