#
# @lc app=leetcode id=142 lang=python
#
# [142] Linked List Cycle II

# Category	Difficulty	Likes	Dislikes	Discuss
# algorithms	Easy (38.11%)	1821	235	–
# Tags
# Companies
# Given a linked list, determine if it has a cycle in it.



### @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

###思考
# 先由快慢指针检测链表上是否存在环
# 如果环存在，根据相遇点到环入口点的距离 = 链表起始点到环入口点的距离，我们可以同时从D点（链表起始点）和B点（相遇点）循环两个指针
# 两个会最终指向A点，即，环的起始点


###
# Accepted
# 16/16 cases passed (44 ms)
# Your runtime beats 44.81 % of python submissions
# Your memory usage beats 47.17 % of python submissions (18.2 MB)

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or head.next==None:
            return None     #no cycle
        
        slow, fast = head, head
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                tmp = head
                while tmp!=slow:
                    tmp = tmp.next
                    slow = slow.next
                return tmp
        
        return None




# @lc code=end

