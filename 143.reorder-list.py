#
# @lc app=leetcode id=143 lang=python
#
# [143] Reorder List
# Given a singly linked list L: L0→L1→…→Ln-1→Ln,
# reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
# You must do this in-place without altering the nodes' values.
# For example,
# Given {1,2,3,4}, reorder it to {1,4,2,3}.

# @lc code=start

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

###思考：
    # 1，先将链表截断为两个相等长度的链表，如果链表长度为奇数，则第一条链表长度多1。如原链表为L={1,2,3,4,5}，那么拆分结果为L1={1,2,3}；L2={4,5}。拆分的技巧还是快慢指针的技巧。

    # 2，将第二条链表L2翻转，如将L2={4,5}翻转为L2={5,4}。

    # 3，按照题意归并链表。

###结果：
# Accepted
# 13/13 cases passed (88 ms)
# Your runtime beats 49.88 % of python submissions
# Your memory usage beats 44.44 % of python submissions (29.7 MB)
class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        #
        if not head or not head.next or not head.next.next:
            return head

        #快慢指针找出中点
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        #分裂成两个链表 head1 head2
        head1 = head; 
        head2 = slow.next
        slow.next = None

        #翻转 head2
        head2 = self.swap_list(head2)

        #将head2元素间隔插入head1中
        while head2:
            head1_next_copy = head1.next
            head1.next = head2
            head2 = head2.next
            head1.next.next = head1_next_copy
            head1 = head1_next_copy

        return head

    def swap_list(self, head):
        cur = head
        while cur.next:
            old_head = head
            head = cur.next
            cur.next = cur.next.next
            head.next = old_head
        return head



# @lc code=end

