####
# Category	Difficulty	Likes	Dislikes
# algorithms	Medium (38.40%)	809	216
# Tags
# Companies
# Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

# You should preserve the original relative order of the nodes in each of the two partitions.

# Example:

# Input: head = 1->4->3->2->5->2, x = 3
# Output: 1->2->2->4->3->5

####
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

#
# Runtime: 20 ms, faster than 74.43% of Python online submissions for Partition List.
# Memory Usage: 11.8 MB, less than 25.00% of Python online submissions for Partition List.


##思考 使用两个dummy链表，将小于x放到leftdummy中， 大于的放到rightdummy， 最后拼接两个dummy即可，没有难度
class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        leftdummy = ListNode(-1)
        rightdummy  = ListNode(-1)
        left_cur = leftdummy; right_cur = rightdummy
        while head:
            if head.val < x:
                left_cur.next = head
                left_cur = left_cur.next
            else:
                right_cur.next = head
                right_cur = right_cur.next
            head = head.next

        left_cur.next = rightdummy.next
        right_cur.next = None
        return leftdummy.next


