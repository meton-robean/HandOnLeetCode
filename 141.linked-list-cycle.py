#
# @lc app=leetcode id=141 lang=python
#
# [141] Linked List Cycle
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


#思考： 使用快指针慢指针法，有环的话两个指针在某一时刻会相遇指向同一个对象地址
##
# Accepted
# 17/17 cases passed (28 ms)
# Your runtime beats 98.25 % of python submissions
# Your memory usage beats 60.99 % of python submissions (18.1 MB)

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head:
            return None

        slow, fast = head, head
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
            if slow == fast:
                return True
        return False




# @lc code=end

