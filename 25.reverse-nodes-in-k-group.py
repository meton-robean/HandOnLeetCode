#
##
# Category	Difficulty	Likes	Dislikes
# algorithms	Hard (37.84%)	1387	281
# Tags
# Companies
# Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

# k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

# Example:

# Given this linked list: 1->2->3->4->5

# For k = 2, you should return: 2->1->4->3->5

# For k = 3, you should return: 3->2->1->4->5

# Note:

# Only constant extra memory is allowed.
# You may not alter the values in the list's nodes, only nodes itself may be changed.


##
# [25] Reverse Nodes in k-Group
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


##solution 1
#思考: 按顺序遍历head, 每次把k个逆序拼接到dummy中，再拼接回去head. 不足k个的从dummy中再逆序拼接回head

# ✘ Time Limit Exceeded
#   ✘ 1/81 cases passed (N/A)
#   ✘ testcase: '[1,2,3,4,5]\n3'
#   ✘ answer: 
#   ✘ stdout: ''
# class Solution(object):
#     def reverseKGroup(self, head, k):
#         """
#         :type head: ListNode
#         :type k: int
#         :rtype: ListNode
#         """
#         counter = 0
#         dummy = ListNode(0)
#         keep_head= keep_sub_list_head = cur = head
#         n=0
#         while head:
#             dummy_next_copy = dummy.next
#             dummy.next = cur
#             head = cur.next #head point to next node
#             cur.next = dummy_next_copy
#             counter+=1   #count
#             cur = head   #cur point to head (point to next node,too)
#             if counter == k:
#                 n+=1
#                 sub_list_head = sub_list_tail = dummy.next
#                 dummy.next =None #reset dummy 
#                 while sub_list_tail.next:
#                     sub_list_tail =sub_list_tail.next
                
#                 if n==1:
#                     keep_head = sub_list_head
#                     #sublist首尾拼接
#                     sub_list_tail.next = head
#                     keep_sub_list_head= sub_list_head
#                     keep_sub_list_head = sub_list_tail
#                 else:
#                     sub_list_tail.next = head
#                     keep_sub_list_head.next = sub_list_head##
#                     keep_sub_list_head = sub_list_tail                    
#                 counter = 0 #reset counter

#             #处理剩余不足k的那几个
#             if head == None and counter!=0 and counter!=k:
#                 #print(keep_head)
#                 tmp = ListNode(0)
#                 dummy = dummy.next
#                 dummy_head = dummy
#                 while dummy_head:
#                     tmp_next_copy = tmp.next
#                     tmp.next = dummy
#                     dummy_head = dummy.next
#                     dummy.next = tmp_next_copy

#                 sub_list_head = sub_list_tail = tmp.next
#                 tmp.next = None
#                 while sub_list_tail.next:
#                     sub_list_tail = sub_list_tail.next
#                 #拼接
#                 sub_list_tail.next = head
#                 keep_sub_list_head.next = sub_list_head##
#                 keep_sub_list_head = sub_list_tail                  

#         return keep_head


### solution2 
#思考：

##
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """

