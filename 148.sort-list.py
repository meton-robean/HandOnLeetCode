#
# @lc app=leetcode id=148 lang=python
#
# [148] Sort List
#
#
# Category	Difficulty	Likes	Dislikes
# algorithms	Medium (37.21%)	1779	93
# Tags
# Companies
# Sort a linked list in O(n log n) time using constant space complexity.

# Example 1:

# Input: 4->2->1->3
# Output: 1->2->3->4


# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None



#solution 1 使用归并排序
# Accepted
# 16/16 cases passed (240 ms)
# Your runtime beats 45.68 % of python submissions
# Your memory usage beats 92.31 % of python submissions (26.2 MB)
class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        if not head or not head.next:
            return head
        
        #切成两段
        fast, slow = head, head
        pre = None
        while fast and fast.next: #链表找中点方法
            fast = fast.next.next
            pre = slow
            slow = slow.next
        pre.next = None #断开两段

        #如果可以，继续切分...
        left =  self.sortList(head)
        right = self.sortList(slow)

        #无法切分了，开始比较大小，需要用一个新的dummy list来存放 合并排序的结果
        dummy = ListNode(-1)
        cur = dummy
        while left!=None and right!=None:
            if left.val > right.val:
                cur.next = right
                right = right.next
            else:
                cur.next = left
                left = left.next
            cur = cur.next

        if left!=None:
            cur.next = left
        if right!=None:
            cur.next = right
        
        return dummy.next


# @lc code=end

