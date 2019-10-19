#
# @lc app=leetcode id=203 lang=python
#
# [203] Remove Linked List Elements
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None



##solution 1
#正常遍历链表，遍历过程去掉所要求的val，注意链表第一个就是val 以及 链表中间多个相同val节点
# Accepted
# 65/65 cases passed (56 ms)
# Your runtime beats 78.27 % of python submissions
# Your memory usage beats 10.34 % of python submissions (18.9 MB

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if not head :
            return None

        #处理链表第一个节点的值就是val的情况
        cur = head
        while cur and cur.val == val:
            head = cur.next
            cur = head

        #处理链表中间节点有多个相同val情况
        while cur and cur.next :
            if cur.next.val == val:
                cur.next = cur.next.next
                continue
            cur = cur.next

        return head

# @lc code=end

