#
# @lc app=leetcode id=234 lang=python
#
# [234] Palindrome Linked List
#

# Category	Difficulty	Likes	Dislikes
# algorithms	Easy (37.00%)	2028	289
# Tags
# Companies
# Given a singly linked list, determine if it is a palindrome.

# Example 1:

# Input: 1->2
# Output: false
# Example 2:

# Input: 1->2->2->1
# Output: true


############################
# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


#solution 1 
#回文的特征是如果将链表分成两边， 后半部分压入栈中， 则链表前半部分 和 栈中的数是一样的
# （注意奇数情况栈中的元素数目比前半部分链表的元素数目多一个，不过不影响判断）

# Accepted
# 26/26 cases passed (60 ms)
# Your runtime beats 94.47 % of python submissions
# Your memory usage beats 75.86 % of python submissions (30.8 MB)

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        #平分链表
        slow, fast  = head, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        
        #链表后半部分放入栈中
        stack = []
        while slow:
            stack.append(slow.val)
            slow = slow.next
        
        #对比链表前半部分和栈的元素
        while head and stack:
            check_val = stack.pop()
            if head.val != check_val:
                return False
            head = head.next
        return True



# @lc code=end

