/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
/*
递归解法：于是完全二叉树，所以若节点的左子结点存在的话，其右子节点必定存在，
所以左子结点的 next 指针可以直接指向其右子节点，对于其右子节点的处理方法是，
判断其父节点的 next 是否为空，若不为空，则指向其 next 指针指向的节点的左子结点
，若为空则指向 NULL
*/
/*
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        if(root->left) root->left->next = root->right;
        if(root->right) root->right->next = root->next? root->next->left : nullptr;
        connect(root->left);
        connect(root->right);
        return root; 
        
    }
};
*/


//迭代解法1：
class Solution
{
public:
    Node *connect(Node *root)
    {
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* r = q.front(); q.pop();
            if(r->left) {
                r->left->next = r->right;
                q.push(r->left);
            }
            if(r->right) {
                r->right->next = r->next? r->next->left : nullptr;
                q.push(r->right);
            }

        }
        return root;

    }
};


// @lc code=end

