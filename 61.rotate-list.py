#
# @lc app=leetcode id=61 lang=python
#
# [61] Rotate List
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# ✔ Accepted
#   ✔ 231/231 cases passed (24 ms)
#   ✔ Your runtime beats 60.45 % of python submissions
#   ✔ Your memory usage beats 38.1 % of python submissions (11.8 MB)

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head: 
            return head
        node = head
        l=1
        while node.next:
            node = node.next
            l+=1
        last_node = node
        k = k%l
        if k ==0:
            return head
        hops = l-k-1
        node_before = head
        while hops > 0:
            node_before = node_before.next
            hops-=1
        node = node_before.next
        last_node.next = head
        head = node
        node_before.next = None
        return head

