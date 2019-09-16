####
# Category	Difficulty	Likes	Dislikes
# algorithms	Medium (34.58%)	2128	160
# Tags
# linked-list | two-pointers

# Companies
# Given a linked list, remove the n-th node from the end of list and return its head.

# Example:

# Given linked list: 1->2->3->4->5, and n = 2.

# After removing the second node from the end, the linked list becomes 1->2->3->5.


####
# [19] Remove Nth Node From End of List
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


#origin solution 
#先遍历一遍链表，获得链表长度，在从前往后找到位置，进行替换
# Runtime: 12 ms, faster than 96.19% of Python online submissions
# class Solution(object):
#     def removeNthFromEnd(self, head, n):
#         """
#         :type head: ListNode
#         :type n: int
#         :rtype: ListNode
#         """
#         cur = head
#         list_len = 0
#         while cur:                  #get listnode lenght
#             list_len+=1
#             cur = cur.next

#         if n>list_len:              #1 unvalid n
#             return

#         if list_len ==1 and n==1:   #2 special case 注意空链表的表示方式 cur->None
#             cur =head 
#             cur = cur.next
#             return cur

#         cur = head
#         if list_len-n ==0:          #3 special case 只需去掉第一个元素
#             cur = cur.next
#             return cur

#         for i in range(list_len-n-1):
#             cur = cur.next
#         cur.next = cur.next.next
#         return head
        


##solution 1 快指针和慢指针法
#  So the faster pointer starts and the slower pointer waits,、
#  after the faster pointer has passed n nodes, the slower 、
#  pointer starts till the faster pointer reaches the end of、
#  the linked list. The dummyNode helps handle the edge case of a single node.

# 下面的通不过 [1] n=1 ;  [1->2->3] n=3 的边界case, 可以考虑引入dummy_node
# class Solution(object):
#     def removeNthFromEnd(self, head, n):
#         """
#         :type head: ListNode
#         :type n: int
#         :rtype: ListNode
#         """
#         fast = slow = head
#         while fast.next and n:
#             fast = fast.next
#             n = n-1
#         while fast.next:
#             fast = fast.next
#             slow = slow.next
#         slow.next = slow.next.next
#         return head


##引入dummy node

# ✔ 208/208 cases passed (16 ms)
#   ✔ Your runtime beats 85.3 % of python submissions
#   ✔ Your memory usage beats 65.31 % of python submissions (11.7 MB)
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        fast = slow = dummy

        while fast.next:
            fast = fast.next
            n = n-1
            if n <0:
                slow = slow.next
        slow.next = slow.next.next
        return dummy.next


