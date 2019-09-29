#
# @lc app=leetcode id=92 lang=python
#
# [92] Reverse Linked List II
#

# Category	Difficulty	Likes	Dislikes	Discuss
# algorithms	Medium (36.00%)	1483	104	–
# Tags
# Companies
# Reverse a linked list from position m to n. Do it in one-pass.

# Note: 1 ≤ m ≤ n ≤ length of list.

# Example:

# Input: 1->2->3->4->5->NULL, m = 2, n = 4
# Output: 1->4->3->2->5->NULL




# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


# 44/44 cases passed (12 ms)
# Your runtime beats 95.22 % of python submissions
# Your memory usage beats 100 % of python submissions (11.9 MB)

class Solution(object):
    def reverseBetween(self, head, m, n):
        index = 1
        list_head = head        # saving the original head (in case m>1)
        head_prev_node = None   # used for saving the last node before m (in case m>1)

        # this section traverses the nodes before m
        while index < m:
            head_prev_node = head
            head = head.next
            index = index+1

        # this section reverses the links between m and n
        # 重点！！！！ 就地翻转 不需要 dummy node 的辅助  -1-2-3-4-5-
        current = head
        while (index>=m) and (index<n) and current.next:
            old_head = head
            head = current.next
            current.next  = current.next.next
            head.next = old_head
            index = index+1


        # this section connects the nodes after n with the reversed node between m and n
        if head_prev_node:
            head_prev_node.next = head

        # this section makes sure the correct head is returned
        if m == 1:
            list_head = head
        return list_head






