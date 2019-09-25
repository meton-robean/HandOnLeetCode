#
# @lc app=leetcode id=82 lang=python
#
###### [82] Remove Duplicates from Sorted List II ###
#
# Category	Difficulty	Likes	Dislikes
# algorithms	Medium (34.06%)	1031	86
# Tags
# Companies
# Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

# Example 1:

# Input: 1->2->3->3->4->4->5
# Output: 1->2->5
# Example 2:

# Input: 1->1->1->2->3
# Output: 2->3

######################################################

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


##solution 1:
# ✔ Accepted
#   ✔ 168/168 cases passed (20 ms)
#   ✔ Your runtime beats 97.1 % of python submissions
#   ✔ Your memory usage beats 93.75 % of python submissions (11.8 MB)

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        ## 1-> 2->2->2->3->4->NULL  
        dummy = ListNode(-1)
        is_duplicate = False
        tmp = dummy
        while head:
            fast = head.next
            #fast指针遇到了重复的节点，跳过所有重复的节点，并更新head的指向
            while fast and head.val == fast.val:
                fast = fast.next
                is_duplicate =True
            if is_duplicate:
                head = fast
                is_duplicate= False
            #将没有重复的节点拼接到dummy链表上
            else:
                tmp.next = head
                tmp = tmp.next
                head = head.next
        tmp.next = None
        return dummy.next


#时间复杂度 O(n), 空间复杂度 O（1）

