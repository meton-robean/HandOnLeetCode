#
# @lc app=leetcode id=237 lang=python
#
# [237] Delete Node in a Linked List

# Category	Difficulty	Likes	Dislikes
# algorithms	Easy (55.48%)	918	4491
# Tags
# Companies
# Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.#


########################################
# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


#solution 1
#该题目是给定当前要删除的节点，这一点容易理解错误
# Accepted
# 41/41 cases passed (24 ms)
# Your runtime beats 77.42 % of python submissions
# Your memory usage beats 96.77 % of python submissions (12.1 MB)

class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        
        node.val = node.next.val
        node.next = node.next.next

                
                 
# @lc code=end

