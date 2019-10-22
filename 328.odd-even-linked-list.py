#
# @lc app=leetcode id=328 lang=python
#
# [328] Odd Even Linked List
# Category	Difficulty	Likes	Dislikes
# algorithms	Medium (50.36%)	962	243
# Tags
# Companies
# Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

# You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

# Example 1:

# Input: 1->2->3->4->5->NULL
# Output: 1->3->5->2->4->NULL
# Example 2:

# Input: 2->1->3->5->6->4->7->NULL
# Output: 2->3->6->7->1->5->4->NULL

# Note:

# The relative order inside both the even and odd groups should remain as it was in the input.
# The first node is considered odd, the second node even and so on ...


###########################################
# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


##solution 1
# 奇偶指针交替法：奇数指针和偶数指针交替移动，根据 偶数指针的旁边是奇数节点 这个特点来重新组织

# Accepted
# 71/71 cases passed (28 ms)
# Your runtime beats 80.1 % of python submissions
# Your memory usage beats 65 % of python submissions (15.2 MB)
class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #保证链表至少有两个节点
        if not head or not head.next:
            return head
        
        #初始化：奇数指针指向第一个，偶数指针指向第二个节点
        odd = head
        even = head.next
        even_head = even

        #奇数指针和偶数指针交替移动，根据 偶数指针的旁边是奇数节点 这个特点来重新组织
        while even and even.next:
            odd.next = even.next
            odd = odd.next
            even.next = odd.next
            even = even.next

        odd.next = even_head
        return head



# @lc code=end

