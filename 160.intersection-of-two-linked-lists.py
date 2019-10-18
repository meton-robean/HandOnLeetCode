#
# @lc app=leetcode id=160 lang=python
#
# [160] Intersection of Two Linked Lists

# Category	Difficulty	Likes	Dislikes
# algorithms	Easy (35.56%)	2509	252
# Tags
# Companies
# Write a program to find the node at which the intersection of two singly linked lists begins.



######################################################################
# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


##solution1 
#哈希思想
# Accepted
# 45/45 cases passed (200 ms)
# Your runtime beats 42.35 % of python submissions
# Your memory usage beats 5.33 % of python submissions (42.5 MB)

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        hashmap = {}
        while headA:
            hashmap[headA] = 1
            headA = headA.next
        while headB:
            if headB in hashmap:
                return headB
            headB = headB.next
        return None




# @lc code=end

