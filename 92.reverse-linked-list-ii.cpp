/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*

由于可能m=1,表示从第一个节点开始，凡是修改第一个节点的，需要在前面加一个dummy节点

x------------3--------1-------2--------3----4---6---null
dummy       pre      cur     future


通过以下操作:
ListNode* future = cur->next;
cur->next = future->next;
future->next = pre->next;
pre->next = future;

变成:
x------------3--------2-------1--------3----4---6---null
dummy       pre              cur     future

再进行一次上面操作，变成:

x------------3--------3-------2--------1----4---6---null
dummy       pre                       cur


*/
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (head == nullptr)
            return head;
        ListNode *dummy = new ListNode(0, nullptr);
        dummy->next = head;
        head = dummy;
        ListNode *pre = nullptr;
        int idx = 0;
        while (idx < m)
        {
            pre = head;
            head = head->next;
            idx++;
        }
        ListNode *cur = head;

        for (int i = m; i < n; ++i)
        {
            ListNode *future = cur->next;
            cur->next = future->next;
            future->next = pre->next;
            pre->next = future;
        }

        return dummy->next;
    }
};
// @lc code=end

