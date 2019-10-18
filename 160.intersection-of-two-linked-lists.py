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


##solution2 
# 事实上，可以不用计算两个链表的长度，因为本质上我们关心的是让两个链表的指针同时到达交叉点。
# 我们可以定义两个指针，让它们都将两个链表都遍历一遍，那么它们走的总长度是一样的，
# 倘若两个链表相交，那么这两个指针一定会在某个地方相等。
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if not headA or not headB:
            return None
        p, q = headA, headB
        while p and q and p != q:
            p = p.next
            q = q.next
            if p == q:
                return p
            if not p:
                p = headB
            if not q:
                q = headA
        return p


# @lc code=end

