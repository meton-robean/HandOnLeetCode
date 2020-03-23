/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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


//解法一
//最简单的方式，维护一个vector, 使用中序遍历放数。
//之后的next取数都在vector操作. 但是时间复杂独O（n）不符合要求

// class BSTIterator
// {
// private:
//     TreeNode *root;
//     vector<TreeNode *> inOrderList;
//     int current;

// public:
//     BSTIterator(TreeNode *root)
//     {
//         this->root = root;
//         inOrderTrav(root);
//         this->current = -1;
//     }

//     void inOrderTrav(TreeNode *root)
//     {
//         if (!root)
//             return;
//         if (root->left)
//             inOrderTrav(root->left);
//         this->inOrderList.push_back(root);
//         if (root->right)
//             inOrderTrav(root->right);
//         return;
//     }

//     /** @return the next smallest number */
//     int next()
//     {
//         current++;
//         return inOrderList[current]->val;
//     }

//     /** @return whether we have a next smallest number */
//     bool hasNext()
//     {
//         if (current + 1 < this->inOrderList.size())
//         {
//             return true;
//         }
//         return false;
//     }
// };

//解法二：
//  iterative in-order-traversal with stack in BST.
// 其实就是利用中序遍历的迭代方式实现，这需要用到stack。
class BSTIterator
{
private:
    stack<TreeNode*> st;


public:
    BSTIterator(TreeNode *root) {
        while( root ){
            st.push( root);
            root = root -> left;
        }

    }

    /** @return the next smallest number */
    int next(){
        TreeNode* t = st.top(); st.pop();
        int val = t->val;
        TreeNode* head = t->right;
        while(head){
            st.push(head);
            head = head->left;
        }

        return val;

    }

    /** @return whether we have a next smallest number */
    bool hasNext(){
        return st.empty()? false: true;
    }


};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

