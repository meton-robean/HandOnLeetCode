#
# @lc app=leetcode id=21 lang=python
#
# [21] Merge Two Sorted Lists
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


#solution 1
#思考： 不需要从 l1, l2 拆卸节点拼接，而是直接遍历然后复制新的节点到新的dummy节点，不过这样比较耗内存和时间
# ✔ Accepted
#   ✔ 208/208 cases passed (28 ms)
#   ✔ Your runtime beats 30.91 % of python submissions
#   ✔ Your memory usage beats 31.03 % of python submissions (11.9 MB)


class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        cur = dummy
        while l1 and l2:
            if l1.val <= l2.val:
                cur.next  = ListNode( l1.val)
                cur = cur.next
                l1 = l1.next
            else:
                cur.next = ListNode(l2.val)
                cur = cur.next
                l2 = l2.next

        while l1:
            cur.next  = ListNode( l1.val)
            cur = cur.next
            l1 = l1.next

        while l2:
            cur.next = ListNode(l2.val)
            cur = cur.next
            l2 = l2.next            
        
        return dummy.next


#solution 2
#
#思考：直接拆卸l1 l2的节点，而不是复制。 因为两个链表都是排好序的，所以只需移动两个链表指针，匹配大小，一次放入新的链表节点。
#     这个过程有点像归并排序里面的合并过程

#result:
# ✔ Accepted
#   ✔ 208/208 cases passed (20 ms)
#   ✔ Your runtime beats 86.16 % of python submissions
#   ✔ Your memory usage beats 74.71 % of python submissions (11.8 MB)

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        cur = dummy
        p1=l1
        p2=l2
        while l1 and l2:
            if l1.val <= l2.val:
                p1 = l1     #p1 is tmp pointer to keep the current l1 node 
                l1=l1.next  #l1 points to next element
                
                #linking l1 node to current dummy linked-list
                cur_next_copy = cur.next
                cur.next = p1
                p1.next = cur_next_copy
                cur = cur.next
                
            else:
                p2 = l2
                l2 = l2.next #l2 points to next element
                cur_next_copy = cur.next
                cur.next = p2
                p2.next = cur_next_copy
                cur = cur.next                

        while l1:
                p1 = l1
                l1=l1.next
                cur_next_copy = cur.next
                cur.next = p1
                p1.next = cur_next_copy
                cur = cur.next

        while l2:
                p2 = l2
                l2 = l2.next  
                cur_next_copy = cur.next
                cur.next = p2
                p2.next = cur_next_copy
                cur = cur.next    

        return dummy.next





