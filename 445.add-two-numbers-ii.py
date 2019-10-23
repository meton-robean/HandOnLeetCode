#
# @lc app=leetcode id=445 lang=python
#
# [445] Add Two Numbers II

# Category	Difficulty	Likes	Dislikes
# algorithms	Medium (51.24%)	903	120
# Tags
# Companies
# You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

# You may assume the two numbers do not contain any leading zero, except the number 0 itself.

# Follow up:
# What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

# Example:

# Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 8 -> 0 -> 7



#################################################################################
# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


##solution1
#和 add two numbers I 不一样，这次链表表示的是数字的正序，所以我们可以遍历链表把其元素值放入栈中，
#这样从栈顶取出的就是低位了，从栈顶取数进行相加边构造dummy节点来保存结果

# Accepted
# 1563/1563 cases passed (60 ms)
# Your runtime beats 62.27 % of python submissions
# Your memory usage beats 46.67 % of python submissions (11.9 MB)
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        stack1 = []
        stack2 = []
        carry = 0
        #链表元素值入栈
        while l1:
            stack1.append(l1.val)
            l1 = l1.next

        while l2:
            stack2.append(l2.val)
            l2 = l2.next

        dummy = ListNode(-1)

        #从栈顶弹出数字低位进行运算，结果链接到dummy链表节点中
        while stack1 or stack2:
            result = 0
            if stack1:
                val1 = stack1.pop()
                result+=val1
            if stack2:
                val2 = stack2.pop()
                result+=val2
            result += carry
            carry, result = divmod(result, 10)

            dummy_next_copy = dummy.next
            dummy.next = ListNode(result)
            dummy.next.next = dummy_next_copy
        
        #如果最后carry不是0的话，直接修改dummy头结点值，并返回dummy节点，而不用返回dummy.next
        if carry==0:
            return dummy.next
        else:
            dummy.val = carry
            return dummy





# @lc code=end

