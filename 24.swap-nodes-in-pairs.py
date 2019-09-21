#
# @lc app=leetcode id=24 lang=python
#
# [24] Swap Nodes in Pairs
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


#思考： 递归， 维持三个指针， 子串翻转
#      进阶难度参考 25 Reverse Nodes in k-Group
# ✔ Accepted
#   ✔ 55/55 cases passed (16 ms)
#   ✔ Your runtime beats 77.92 % of python submissions
#   ✔ Your memory usage beats 27.27 % of python submissions (11.8 MB)


class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        first, second, third = head, head.next, head.next.next
        first, second = self.swap(first, second)
        if third:
            second.next = self.swapPairs(third)
            return first
        else:
            return first


    def swap(self, first, second):
        dummy = ListNode(-1)
        while first!=second:
            first_next_copy = first.next
            dummy_next_copy = dummy.next

            dummy.next = first
            first.next = dummy_next_copy
            first = first_next_copy
        if first == second:
            first_next_copy = first.next
            dummy_next_copy = dummy.next

            dummy.next = first
            first.next = dummy_next_copy
            first = first_next_copy  
        first = dummy.next
        while dummy.next:
            dummy = dummy.next
        second = dummy

        return first, second
         

