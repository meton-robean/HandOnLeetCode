

# Category	Difficulty	Likes	Dislikes
# algorithms	Easy (56.69%)	2761	69
# Tags
# Companies
# Reverse a singly linked list.

# Example:

# Input: 1->2->3->4->5->NULL
# Output: 5->4->3->2->1->NULL
# Follow up:

# A linked list can be reversed either iteratively or recursively. Could you implement both? both?


# [206] Reverse Linked List
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# head->1->2->3->NULL
# dummy->inf->NULL

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(float('inf'))
        while head:
            #keep ptr backup
            head_next_copy = head.next
            dummy_next_copy = dummy.next
            
            #re-connect linked-list
            dummy.next = head     # dummy->inf->1
            head.next = dummy_next_copy #dummy->inf->1->NULL
            head = head_next_copy  #head->2->3->NULL

        return dummy.next



